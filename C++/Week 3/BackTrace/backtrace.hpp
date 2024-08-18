#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <iostream>
#include <stack>
#include <string>

class Backtrace {
private:
    std::stack<std::string> callStack;

public:
    void enterFunction(const std::string& functionName) {
        callStack.push(functionName);
        std::cout << "Enter to [" << functionName << "]\n";
    }

    void leaveFunction() {
        if (!callStack.empty()) {
            std::cout << "Exit From [" << callStack.top() << "]\n";
            callStack.pop();
        }
    }

    void printBacktrace() const {
        std::stack<std::string> tempStack = callStack;
        std::cout << "Backtrace as follows:\n";
        int i = 0;
        while (!tempStack.empty()) {
            std::cout << i++ << "- " << tempStack.top() << "\n";
            tempStack.pop();
        }
        std::cout << "Back Trace is Finished\n";
    }
};

Backtrace globalBacktrace;

#define EnterFn  globalBacktrace.enterFunction(__FUNCTION__)
#define ExitFn   globalBacktrace.leaveFunction()
#define PRINT_BT globalBacktrace.printBacktrace()

#endif
