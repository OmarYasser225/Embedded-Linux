#ifndef SERVER_HPP
#define SERVER_HPP

/************************************* Include Section *********************************************/
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstdlib>
#include <iphlpapi.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")


/************************************* Define Section *********************************************/
#define BUFFER_SIZE 1024

/************************************** Enum Section **********************************************/
typedef enum 
{
    Success = 0,
    WSAStartup_failed = 1,
    Socket_failed = 2,
    Bind_failed = 3,
    Listen_failed = 4,
    Accept_failed = 5,
    Receive_failed = 6,
    Send_failed = 7,
    Closesocket_failed = 8,
    WSACleanup_failed = 9,
    Close_Server = 10
} socket_ret_t;

/************************************ Function Section *******************************************/


class Socket 
{
    public:
    SOCKET server_fd;
    SOCKET client_socket;

    public:
    Socket();
    socket_ret_t initialze();
    socket_ret_t Create_socket();
    socket_ret_t Bind_socket(int PORT);
    socket_ret_t Listen_socket(int PORT);
    socket_ret_t Accept_socket();
    socket_ret_t CLOSE_SERVER();
    std::string RECEIVE_DATA();
};

class server : public Socket
{
    private:  // Member
    int Num_client;
    int PORT;

    public: // Public Methods
    server(int Num_client , int PORT);
    socket_ret_t INIT_SERVER();
    
};

#endif
