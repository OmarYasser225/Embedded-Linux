/************************************ Include Section *****************************************/
#include "TCP_Server.hpp"
#include"D:\projects\embedded_linux\C++\Pc Controller\System\system.hpp"


/*********************************** Function Section ****************************************/

/************** Methods of System Class ************/


Socket::Socket()
{
     // Get the size needed for the buffer
    DWORD bufferSize = 0;
    GetAdaptersInfo(nullptr, &bufferSize);

    // Allocate memory for the buffer
    IP_ADAPTER_INFO *adapterInfo = (IP_ADAPTER_INFO*)malloc(bufferSize);
    if (adapterInfo == nullptr)
    {
        std::cerr << "Memory allocation failed." << std::endl;
        return;
    }

    // Get adapter info
    if (GetAdaptersInfo(adapterInfo, &bufferSize) == ERROR_SUCCESS) {
        IP_ADAPTER_INFO *adapter = adapterInfo;
        while (adapter) 
        {
            if(strcmp(adapter->AdapterName,"{96462D11-5D8C-4B36-A13D-4F5358A55CD7}") == 0)
            {
                System::setColor(RED);
                std::cout << "Server IP: "; 
                System::setColor(RESET);
                std::cout << adapter->IpAddressList.IpAddress.String << std::endl;
                break;
            }
            adapter = adapter->Next;
        }
    } 
    else 
    {
        std::cerr << "Failed to get adapter information." << std::endl;
    }

    // Free allocated memory
    free(adapterInfo);
}


/************** Methods of Socket Class ************/
socket_ret_t Socket::initialze()
{
    WSADATA wsaData;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) 
    {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return WSAStartup_failed;
    }

    return Success;
}

socket_ret_t Socket::Create_socket()
{
    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_fd == INVALID_SOCKET) 
    {
        std::cerr << "Socket failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return Socket_failed;
    }
    
    return Success;
}

socket_ret_t Socket::Bind_socket(int PORT)
{
    // Bind the socket
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (SOCKADDR*)&address, sizeof(address)) == SOCKET_ERROR) 
    {
        std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return Bind_failed;
    }

    return Success;
}

socket_ret_t Socket::Listen_socket(int PORT)
{
    // Listen for incoming connections
    if (listen(server_fd, SOMAXCONN) == SOCKET_ERROR) 
    {
        std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return Listen_failed;
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    return Success;
}

socket_ret_t Socket::Accept_socket()
{
    // Accept a client socket
    client_socket = accept(server_fd, NULL, NULL);
    if (client_socket == INVALID_SOCKET) 
    {
        std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return Accept_failed;
    }

    System::clearScreen();
    System::setColor(GREEN);
    std::cout << "Client connected Successfully" << std::endl;
    System::setColor(RESET);
    std::cout << "-----------------------------------------------" << std::endl;

    return Success;
}

socket_ret_t Socket::CLOSE_SERVER()
{
    if (closesocket(client_socket) == SOCKET_ERROR) 
    {
        std::cerr << "closesocket failed: " << WSAGetLastError() << std::endl;
        return Closesocket_failed;
    }
    if (closesocket(server_fd) == SOCKET_ERROR) 
    {
        std::cerr << "closesocket failed: " << WSAGetLastError() << std::endl;
        return Closesocket_failed;
    }
    if (WSACleanup() != 0)
    {
        std::cerr << "WSACleanup failed: " << WSAGetLastError() << std::endl;
        return WSACleanup_failed;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    System::setColor(RED);
    std::cout << "Connection closing..." << std::endl;
    System::setColor(RESET);
    return Success;
}

std::string Socket::RECEIVE_DATA()
{
    // Receive data from client
    char buffer[BUFFER_SIZE] = {0};
    int bytesReceived = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytesReceived > 0) 
    {
        System::setColor(RED);
        std::cout << "Received from client: ";
        System::setColor(RESET); 
        std::cout << buffer << std::endl;

        std::string copy(buffer);
        return copy;
    } 
    return "NULL"; 
       
}



/************** Methods of Server Class ************/
server::server(int Num_client, int PORT) : Num_client(Num_client), PORT(PORT) 
{
    System::setColor(RED);
    std::cout<<"Server Port: ";
    System::setColor(RESET);
    std::cout<<PORT<<std::endl;

    System::setColor(GREEN);
    std::cout<<"Server Started..."<<std::endl;
    System::setColor(RESET);
}

socket_ret_t server::INIT_SERVER()
{
    socket_ret_t ret = Success;

    if ((ret=initialze()) != Success)
        return ret;
    if ((ret=Create_socket()) != Success)
        return ret;
    if ((ret=Bind_socket(this->PORT)) != Success)
        return ret;
    if ((ret=Listen_socket(this->PORT)) != Success)
        return ret;
    if ((ret=Accept_socket()) != Success)
        return ret;
    
    return ret;
}
