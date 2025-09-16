#ifndef WEBCAM_FRAME_GETTER_HPP
#define WEBCAM_FRAME_GETTER_HPP

#include "FrameGetter.hpp"//FrameGetter
#include "MFormatWebCam.hpp"//MFormatReader

namespace show_video
{
	class __declspec(dllexport) WebCamFrameGetter : public FrameGetter
	{
	public:
		WebCamFrameGetter() = default;
		~WebCamFrameGetter() = default;

		cv::Mat GetNextFrame();

	private:
		MFormatWebCam m_webCam;
	};


}// show_video
#endif // !WEBCAM_FRAME_GETTER_HPP
