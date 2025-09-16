#include <stdexcept>//std::runtime_error
#include "FrameGetterException.hpp"//FailedToGetFrame
#include "Init.hpp"//InitMFormat
#include "MFormatReader.hpp"

namespace show_video
{

	MFormatReader::MFormatReader(const std::string& filePath): m_rewind(false)
	{
        InitMFormat();
        HRESULT result = m_reader.CoCreateInstance(__uuidof(MFReader));
        if (FAILED(result))
        {
            throw std::runtime_error("ERROR: Can't create MFReader instance");
        }
        
        CComBSTR cbsProps{ _T("") };
        CComBSTR cFilePath = filePath.c_str();
        result = m_reader->ReaderOpen(cFilePath, cbsProps);
        if (FAILED(result))
        {
            throw std::runtime_error("ERROR: Can't open this media file");
        }
	}

    MFormatReader::~MFormatReader()
    {
        m_reader->ReaderClose();
    }

    MFormatFrame MFormatReader::GetNextFrame()
    {
        M_AV_PROPS readerProperties = {};
        readerProperties.vidProps.dblRate = 60;
        readerProperties.vidProps.fccType = eMFCC_RGB32;
        readerProperties.vidProps.nAspectX = 16;
        readerProperties.vidProps.nAspectY = 9;
        readerProperties.vidProps.nWidth = 1920;
        readerProperties.vidProps.nHeight = 1080;
        readerProperties.vidProps.eInterlace = eMI_Progressive;

        CComPtr<IMFFrame> frame = NULL;
        if (m_rewind)
        {
            HRESULT result = m_reader->SourceFrameConvertedGetByTime(&readerProperties, 0, -1, &frame, CComBSTR(L""));
            if (FAILED(result) || !frame)
            {
               throw FailedToGetFrame();
            }
            m_rewind = false;
        }
        else
        {
            HRESULT result = m_reader->SourceFrameConvertedGetByTime(&readerProperties, -1, -1, &frame, CComBSTR(L""));
            if (FAILED(result) || !frame)
            {
                throw FailedToGetFrame();
            }
        }

        //Check for the last frame
        M_TIME time;
        HRESULT result = frame->MFTimeGet(&time);
        if (SUCCEEDED(result))
        {
            if ((time.eFFlags & eMFF_Last) != 0)
            {
                m_rewind = true;
            }
        }
        
        return MFormatFrame(frame);
    }

}
