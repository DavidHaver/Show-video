#include "FileFrameGetter.hpp"

namespace show_video
{
	FileFrameGetter::FileFrameGetter(const std::string &filePath): m_reader(filePath)
	{
		//empty
	}

	cv::Mat FileFrameGetter::GetNextFrame()
	{
		MFormatFrame frame = m_reader.GetNextFrame();
		return cv::Mat(frame.GetHeight(), frame.GetWidth(), CV_8UC4, frame.GetData());
	}
}
