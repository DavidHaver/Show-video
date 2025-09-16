#ifndef DRAW_VIDEO_HPP
#define DRAW_VIDEO_HPP

#include <memory>//std::shared_ptr
#include <windows.h>//HWND
#include "FrameGetter.hpp"

namespace show_video
{
	class DrawVideo
	{
	public:
		explicit DrawVideo(HWND windowHandle);
		DrawVideo(HWND windowHandle, const std::string &filePath);
		~DrawVideo() noexcept;

		void Draw();
	private:	
		void IntalizeCvWindow();

		const std::string WINDOW_TITLE = "Video";

		std::shared_ptr<FrameGetter> m_video;
		HWND m_windowHandle;
		bool m_running;
	};
}// show_video

#endif // !DRAW_VIDEO_HPP

