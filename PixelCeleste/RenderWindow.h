#pragma once
#include "ErrorLogger.h"

class WindowContainer;

class RenderWindow
{
public:
    bool Initialize(WindowContainer* pWhjndowContainera, HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height);
    bool ProcessMessages();
    HWND GetHWND();

    RenderWindow() 
    {
        std::cout << "RenderWindow 생성자 호출" << std::endl;
    }
    ~RenderWindow();
private:
    void RegisterWindowClass();
    HWND handle = NULL; //Handle to this window
    HINSTANCE hInstance = NULL; //Handle to applicationb instance
    
    std::string window_title = "";
    std::wstring window_title_wide = L"";   //Wide string representation of window title

    std::string window_class = "";
    std::wstring window_class_wide = L"";   //Wide string representation of window class name

    int width = 0;
    int height = 0;
};

