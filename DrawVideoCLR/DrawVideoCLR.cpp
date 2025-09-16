#include "DrawVideoCLR.hpp"


namespace show_video
{
    std::string MarshalString(String ^s) 
    {
        using namespace Runtime::InteropServices;
        const char *chars =
            (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
        std::string os = chars;
        Marshal::FreeHGlobal(IntPtr((void *)chars));
        return os;
    }

    DrawVideoCLR::DrawVideoCLR(IntPtr windowHandle)
    {
        m_draw = new DrawVideo(static_cast<HWND>(windowHandle.ToPointer()));
    }

    DrawVideoCLR::DrawVideoCLR(IntPtr windowHandle, String ^filePath)
    {
        m_draw = new DrawVideo(static_cast<HWND>(windowHandle.ToPointer()), MarshalString(filePath));
    }

    DrawVideoCLR::~DrawVideoCLR()
    {
        Close();
    }

    void DrawVideoCLR::Draw()
    {
        m_draw->Draw();
    }

    void DrawVideoCLR::Close()
    {
        delete m_draw;
        m_draw = nullptr;
    }
}// show_video
