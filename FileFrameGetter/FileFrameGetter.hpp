#ifndef FILE_FRAME_GETTER_HPP
#define FILE_FRAME_GETTER_HPP

#include "FrameGetter.hpp"//FrameGetter
#include "MFormatReader.hpp"//MFormatReader

namespace show_video
{
	class __declspec(dllexport) FileFrameGetter : public FrameGetter
	{
	public:
		explicit FileFrameGetter(const std::string &filePath);
		~FileFrameGetter() = default;

		cv::Mat GetNextFrame();

	private:
		MFormatReader m_reader;
	};


}// show_video
#endif // !FILE_FRAME_GETTER_HPP
