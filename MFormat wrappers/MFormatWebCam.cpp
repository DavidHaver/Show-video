#include <stdexcept>//std::runtime_error
#include "FrameGetterException.hpp"//FailedToGetFrame
#include "Init.hpp"//InitMFormat
#include "MFormatWebCam.hpp"

namespace show_video
{
    MFormatWebCam::MFormatWebCam()
    {
        InitMFormat();
        HRESULT result = m_webcam.CoCreateInstance(__uuidof(MFLive));
        if (FAILED(result))
        {
            throw std::runtime_error("ERROR: Can't create MFLive instance");
        }

        int DevicCount = 0;
        result = m_webcam->DeviceGetCount(eMFDT_Video, &DevicCount);
        if (DevicCount == 0)
        {
            throw std::runtime_error("No available live video devices found");
        }

        CComBSTR DevicName;
        BOOL busy = false;
        for (int i = 0; i < DevicCount; i++)
        {
            m_webcam->DeviceGetByIndex(eMFDT_Video, i, &DevicName, &busy);
            if (CComBSTR("Integrated Camera") == DevicName)
            {
                m_webcam->DeviceSet(eMFDT_Video, i, CComBSTR(L""));
                break;
            }
        }
    }

    MFormatWebCam::~MFormatWebCam() noexcept
    {
        m_webcam->DeviceClose();
    }

    MFormatFrame MFormatWebCam::GetNextFrame()
    {
        M_AV_PROPS sourceProperties = {};
        sourceProperties.vidProps.dblRate = 60;
        sourceProperties.vidProps.fccType = eMFCC_RGB32;
        sourceProperties.vidProps.nAspectX = 16;
        sourceProperties.vidProps.nAspectY = 9;
        sourceProperties.vidProps.nWidth = 1920;
        sourceProperties.vidProps.nHeight = 1080;
        sourceProperties.vidProps.eInterlace = eMI_Progressive;

        CComPtr<IMFFrame> frame = NULL;
        CComQIPtr<IMFSource> source(m_webcam);
        HRESULT result = source->SourceFrameConvertedGet(&sourceProperties, -1, &frame, CComBSTR(L""));
        if (FAILED(result) || !frame)
        {
            throw FailedToGetFrame();
        }

        return MFormatFrame(frame);
    }

}
