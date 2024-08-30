### Project Description: PC Remote Controller via Mobile Application

#### Overview:
The project consists of a PC remote controller system that enables users to control various aspects of a Windows-based PC through a mobile application. The system is built with a server-side application written in C++ and a client-side application built using Kivy (Python) for the mobile interface. The communication between the client and server is established over TCP/IP.

#### Components:

1. **Server-side (C++ Application):**
   - The server application is responsible for listening for incoming connections and executing commands received from the client. It includes a `TCP_Server` class for handling network communication and a `System` class for executing commands on the PC.
   - The server can:
     - Open specified applications (like Chrome, Edge, VirtualBox, etc.).
     - Open specific websites (like YouTube, GitHub, Facebook, etc.).
     - Execute terminal commands.
     - Control system actions such as shutdown, reboot, and sleep.

2. **Client-side (Python Kivy Application):**
   - The mobile application provides a user interface to connect to the server and send commands.
   - Users can connect to the server by providing the IP address and port number.
   - The interface includes buttons for launching applications, opening websites, executing terminal commands, and performing system actions.

#### Functionality:

- **Server Initialization and Client Communication:**
  - The server initializes a TCP socket and listens for client connections.
  - Once a client connects, the server waits for commands and executes them accordingly.
  - The communication loop continues until a "close" command is received, or an error occurs.

- **Command Handling on Server:**
  - The server handles commands using various handlers:
    - **Application Commands:** Opens applications using `ShellExecuteA` for Windows.
    - **Web Link Commands:** Opens websites in the default browser using system commands.
    - **Terminal Commands:** Executes shell commands provided by the client.
    - **System Commands:** Performs actions like shutdown, reboot, or sleep.

- **Client User Interface:**
  - Provides a simple UI with text input fields for IP and Port, and buttons for sending specific commands.
  - After connecting to the server, the interface displays buttons grouped by functionality:
    - **App Control:** Opens applications like Edge, Chrome, VSCode, etc.
    - **Link Control:** Opens websites like YouTube, GitHub, Facebook, etc.
    - **Terminal Control:** Allows users to send terminal commands.
    - **System Control:** Performs actions like shutdown, reboot, and sleep.

#### Features:

1. **Dynamic Application and Web Control:**
   - Users can remotely open applications or web links defined on the server.

2. **System Management:**
   - Control over system functions like shutdown, reboot, and sleep directly from the mobile app.

3. **Terminal Access:**
   - Allows the execution of terminal commands on the server from the mobile client.

4. **Real-time Communication:**
   - The client and server communicate in real-time using TCP/IP, providing a seamless user experience.

#### Usage:

1. **Start the Server:**
   - Run the server application on the PC to start listening for incoming connections.
   - The server initializes and displays its IP address for client connection.

2. **Connect the Client:**
   - Open the mobile application.
   - Enter the IP address and port of the server, and click "Connect."

3. **Send Commands:**
   - Use the mobile app to send commands like opening applications, visiting websites, or performing system actions.
   - The server executes the commands and provides feedback.

4. **Close the Connection:**
   - The connection can be closed from the mobile app, which will terminate the server’s command execution loop.

#### Future Enhancements:

- **Cross-Platform Support:** Extend support to Linux and MacOS systems.
- **Authentication:** Add user authentication for secure connections.
- **Encryption:** Implement encryption for command transmission.
- **Extended Control:** Add more functionalities like file management, media control, etc.

This project demonstrates a practical application of network programming, socket communication, and system command execution, providing a versatile tool for remote PC management through a mobile device.
