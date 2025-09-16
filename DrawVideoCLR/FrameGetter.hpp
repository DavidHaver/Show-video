#ifndef FRAME_GETTER_HPP
#define FRAME_GETTER_HPP

#include <opencv2/opencv.hpp>//cv::Mat
#include "FrameGetterException.hpp"//FailedToGetFrame

namespace show_video
{

	class FrameGetter
	{
	public:
		FrameGetter() = default;

		virtual ~FrameGetter() = default;

		//throw FailedToGetFrame when could not get frame 
		virtual cv::Mat GetNextFrame() = 0;

	private:

	};

}// show_video
#endif // !FRAME_GETTER_HPP
