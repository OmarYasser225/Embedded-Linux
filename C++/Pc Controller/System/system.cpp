
/************************************ Include Section *****************************************/
#include"system.hpp"
#include<map>
#include <cstdlib>
#include<windows.h> 
#include <algorithm>
#include <iomanip>
#include <sstream>
   
/*********************************** Variable Section *****************************************/
std::map<std::string, std::string> path = 
{
        {"edge", "C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe"},
        {"chrome", "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe"},
        {"vsCode", "C:\\Users\\omarn\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"},
        {"microchip", "C:\\Program Files (x86)\\Atmel\\Studio\\7.0\\AtmelStudio.exe"},
        {"stmcube", "C:\\ST\\STM32CubeIDE_1.14.1\\STM32CubeIDE\\stm32cubeide.exe"},
        {"stmutility", "C:\\Program Files (x86)\\STMicroelectronics\\STM32 ST-LINK Utility\\ST-LINK Utility\\STM32 ST-LINK Utility.exe"},
        {"virtualbox", "C:\\Program Files\\Oracle\\VirtualBox\\VirtualBox.exe"}
};


std::map<std::string, std::string> webLink = 
{
    {"youtube", "https://www.youtube.com"},
    {"github", "https://github.com"},
    {"facebook", "https://www.facebook.com"},
    {"twitter", "https://twitter.com"},
    {"instagram", "https://www.instagram.com"},
    {"linkedin", "https://www.linkedin.com"},
    {"pinterest", "https://www.pinterest.com"},
    {"tiktok", "https://www.tiktok.com"},
    {"reddit", "https://www.reddit.com"},
    {"whatsapp" , "https://api.whatsapp.com"}
};

/********************************************* Function Handler ********************************/
int Handler::youtube_handler(std::string name)
{
    std::string search_str = "youtube ";
    std::size_t pos = name.find(search_str);
    if (pos != std::string::npos) 
    {
        name = name.substr(pos + search_str.length());

        std::replace(name.begin(), name.end(), ' ', '-');

        // Combine the two parts of the URL
        std::string url = std::string("start https://www.youtube.com/results?search_query=") 
                          + name;

        system(url.c_str());
        return 1;
    }
    return 0;
}

int Handler::whatsapp_handler(std::string name)
{
    std::string search_str = "Whatsapp ";
    std::size_t pos = name.find(search_str);
    if (pos != std::string::npos) 
    {
        name = name.substr(pos + search_str.length());

        // Combine the two parts of the URL
        std::string url = std::string("start https://wa.me/+2") + name;
        system(url.c_str());
        return 1;
    }
    return 0;
}

void Handler::terminal_handler(std::string name)
{
    if (!name.empty())
      system(name.c_str());  
}

void Handler::system_handler(std::string name)
{
    if(name.find("shutdown"))
    {
        system("shutdown /r /t 1");
    }
    else if(name.find("reboot"))
    {
        system("shutdown /s /t 1");
    }
    else
    {
        system("rundll32.exe powrprof.dll,SetSuspendState 0,1,0");
    }
}

/*********************************** Function Class *****************************************/
void System::clearScreen() 
{
    system("cls"); // Windows command to clear the console
}


void System::setColor(WORD color) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void System::open( std::string name) 
{
     if (path.find(name) != path.end())
    {
        HINSTANCE result = ShellExecuteA(NULL, "open", path[name].c_str(), NULL, NULL, SW_SHOWNORMAL);
        
        // Check for errors
        if (reinterpret_cast<intptr_t>(result) <= 32) {
            // Handle error (e.g., logging, error message)
            MessageBox(NULL, "Failed to open the application.", "Error", MB_OK | MB_ICONERROR);
        }
    }
    else if (webLink.find(name) != webLink.end())
    {
        std::string url = "start " + webLink[name];
        system(url.c_str());   
    }
    else if(name.find("terminal") != std::string::npos)
    {
        std::string ter = "terminal ";
        ter = name.substr(name.find(ter) + ter.length());
        terminal_handler(ter);
    }
    else if(name.find("system") != std::string::npos)
    {
        std::string sys = "system ";
        sys = name.substr(name.find(sys) + sys.length());
        system_handler(sys);
    }
    else 
    {
        if(youtube_handler(name))
            return;
        else if (whatsapp_handler(name))
            return;

        // Handle the case where the application name is not found in the map
        MessageBox(NULL, "Application not found in the path map.", "Error", MB_OK | MB_ICONERROR);
    }
}


