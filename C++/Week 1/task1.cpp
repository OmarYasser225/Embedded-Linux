                                /*          ASCII Table            */

#include <iostream>
#include <iomanip>


int main()
{
   
    std::cout << "--------------------------------" << std::endl;
    std::cout << "|     char     |     value     |" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    
    for(int i = 0 ; i < 128 ; i++)
    {
        std::cout << "|       ";
        
        if (i >= 32 && i <= 126) {
            std::cout << (char)i << "      ";
        } else {
            std::cout << "       "; // non-printable characters
        }
        
        std::cout << "|     " << std::setw(4) << i << "      |" << std::endl;
    }
    
    std::cout << "--------------------------------" << std::endl;
    
    return 0;
}

