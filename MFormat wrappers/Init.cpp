#include <Windows.h>//Com
#include <memory>//std::shared_ptr
#include <stdexcept>//std::runtime_error
#include "Init.hpp"

namespace show_video
{ 
    class Init
    {
    public:
        Init();
        ~Init();

    private:

    };

    Init::Init()
    {
        //Initialize COM
        HRESULT result = CoInitializeEx(NULL, COINIT_MULTITHREADED);
        if(FAILED(result))
        {
          throw std::runtime_error("Failed to Initialize MFormat");
        }
    }

    Init::~Init()
    {
        CoUninitialize();
    }

    void InitMFormat()
    {
        static std::shared_ptr<Init> init = nullptr;
        if(!init)
        {
            init = std::shared_ptr<Init>(new Init());
        }
    }
}