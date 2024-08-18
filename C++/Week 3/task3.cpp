/****************************************************************************************************/
/*                                             Task                                                 */
/****************************************************************************************************/
/*                             handle interrupt signal like (ctrl+c)                                */
/****************************************************************************************************/

#include <iostream>
#include <csignal>
#include <cstdlib>

// Signal handler function
void handleSignal(int signal) {
    if (signal == SIGINT) {
        std::cout << "\nInterrupt signal (Ctrl+C) received.\n";
        // Perform cleanup if necessary
        std::cout << "Exiting program...\n";
        std::exit(0); // Exit the program
    }
}

int main() {
    // Register signal handler
    std::signal(SIGINT, handleSignal);

    

    std::cout << "Press Ctrl+C to trigger the signal handler...\n";

    // Infinite loop to keep the program running
    while (true) {
        // Your code can go here
    }

    return 0;
}
