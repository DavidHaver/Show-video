#include <Windows.h>//SetParent, GetWindowLong, SetWindowLong
#include <opencv2/highgui/highgui_c.h>//cvGetWindowHandle
#include "FileFrameGetter.hpp"//FileFrameGetter
#include "WebCamFrameGetter.hpp"//WebCamFrameGetter
#include "DrawVideo.hpp"

namespace show_video
{

    DrawVideo::DrawVideo(HWND windowHandle): m_video(new WebCamFrameGetter), m_windowHandle(windowHandle), m_running(true)
    {
        IntalizeCvWindow();
    }

    DrawVideo::DrawVideo(HWND windowHandle, const std::string& filePath) : m_video(new FileFrameGetter(filePath)), m_windowHandle(windowHandle), m_running(true)
    {
        IntalizeCvWindow();
    }

    DrawVideo::~DrawVideo()
    {
        cv::destroyWindow(WINDOW_TITLE);
    }

    void DrawVideo::Draw()
    {
        cv::Mat frame;
        frame = m_video->GetNextFrame();

        try
        {
            RECT rect;
            GetClientRect(m_windowHandle, &rect);
            cv::resize(frame, frame, cv::Size(rect.right, rect.bottom));
            cv::imshow(WINDOW_TITLE, frame);
            const int MILLISECONDS_DELAY_BETWEEN_FRAMES = 12;
            cv::waitKey(MILLISECONDS_DELAY_BETWEEN_FRAMES); 
        }
        catch (const FailedToGetFrame&)
        {

        }
    }

    void DrawVideo::IntalizeCvWindow()
    {
        cv::namedWindow(WINDOW_TITLE);

        //Moving the window so the user will not see it
        cv::resizeWindow(WINDOW_TITLE, 1, 1);
        cv::moveWindow(WINDOW_TITLE, -10000, -10000);

        HWND cvWindowHandle = (HWND)cvGetWindowHandle(WINDOW_TITLE.c_str());
        SetParent(cvWindowHandle, m_windowHandle);
        LONG style = GetWindowLong(cvWindowHandle, GWL_STYLE);
        SetWindowLong(cvWindowHandle, GWL_STYLE, style | WS_CHILD);
    }

    

}// show_video