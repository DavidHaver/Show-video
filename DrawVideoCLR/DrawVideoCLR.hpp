#ifndef DRAW_VIDEO_CLR_HPP
#define DRAW_VIDEO_CLR_HPP

#include "DrawVideo.hpp"

using namespace System;

namespace show_video
{
    public ref class DrawVideoCLR {
    public:
        explicit DrawVideoCLR(IntPtr windowHandle);
        DrawVideoCLR(IntPtr windowHandle, String ^filePath);
        ~DrawVideoCLR();

        void Draw();
        void Close();
    private:
        DrawVideo *m_draw;
    };
}// show_video
#endif // !DRAW_VIDEO_CLR_HPP