#include"Server\TCP_Server.hpp"
#include"System\system.hpp"

int main()
{
    std::string cmd;

    server myServer(1, 8080);

    myServer.INIT_SERVER();

    while (true)
    {
        cmd = myServer.RECEIVE_DATA();
        if(cmd == "close" || cmd == "NULL")
            break;
        System::open(cmd);
    }

    myServer.CLOSE_SERVER();
    
    return 0;
}
