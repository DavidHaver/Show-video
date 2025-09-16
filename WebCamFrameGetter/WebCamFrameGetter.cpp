#include "WebCamFrameGetter.hpp"

namespace show_video
{
	cv::Mat WebCamFrameGetter::GetNextFrame()
	{
		MFormatFrame frame = m_webCam.GetNextFrame();
		cv::Mat result(frame.GetHeight(), frame.GetWidth(), CV_8UC4, frame.GetData());
		cv::flip(result, result, 0);
		return result;
	}
}
