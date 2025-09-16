#ifndef MFORMAT_WEBCAM_HPP
#define MFORMAT_WEBCAM_HPP

//This is a partial implemntion - the minimum needed for this task

#include <string>//std::string
#include "MFormatFrame.hpp"//MFormatFrame , CComPtr, IMFDevice

namespace show_video
{

	class __declspec(dllexport) MFormatWebCam
	{
	public:
		MFormatWebCam();
		MFormatWebCam(const MFormatWebCam& other) = delete;
		MFormatWebCam(MFormatWebCam&& other) = delete;
		~MFormatWebCam() noexcept;
		MFormatWebCam& operator=(const MFormatWebCam& rhs) = delete;
		MFormatWebCam& operator=(MFormatWebCam&& rhs) = delete;

		//throw FailedToGetFrame when could not get frame 
		MFormatFrame GetNextFrame();

	private:
		CComPtr<IMFDevice> m_webcam;
	};

}// show_video
#endif // !MFORMAT_WEBCAM_HPP