#include <windows.h>
#include <iostream>


/*********************************** Macros Section *****************************************/
// Color constants
#define RED    FOREGROUND_RED | FOREGROUND_INTENSITY     
#define GREEN  FOREGROUND_GREEN | FOREGROUND_INTENSITY  
#define RESET  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE


/*********************************** Class Section *****************************************/

class Handler
{
    public:
    static int youtube_handler(std::string name);
    static int whatsapp_handler(std::string name);
    static void terminal_handler(std::string name);
    static void system_handler(std::string name);
};


class System : public Handler
{
    public:
    static void clearScreen();
    static void setColor(WORD color);
    static void open(std::string name);
};


