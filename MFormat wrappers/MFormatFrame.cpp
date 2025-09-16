#include "MFormatFrame.hpp"

namespace show_video
{
	MFormatFrame::MFormatFrame(CComPtr<IMFFrame> frame): m_frame(frame)
	{
		//empty
	}

	int MFormatFrame::GetHeight()
	{
		M_AV_PROPS properties;
		long audioSample;
		m_frame->MFAVPropsGet(&properties, &audioSample);
		return properties.vidProps.nHeight;
	}

	int MFormatFrame::GetWidth()
	{
		M_AV_PROPS properties;
		long audioSample;
		m_frame->MFAVPropsGet(&properties, &audioSample);
		return properties.vidProps.nWidth;
	}

	void* MFormatFrame::GetData()
	{
		LONG size;
		LONGLONG video;
		m_frame->MFVideoGetBytes(&size, &video);
		return reinterpret_cast<void *>(video);
	}
}
