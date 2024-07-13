                   /*       change from decimal to binary and vice versa        */


#include <iostream>
#include <bitset>
#include <string>

void decimalToBinary(int decimal) {
    std::bitset<8> binary(decimal); // assuming 8 bits for simplicity
    std::cout << "Decimal: " << decimal << " -> Binary: " << binary << std::endl;
}

void binaryToDecimal(const std::string &binaryString) {
    std::bitset<8> binary(binaryString); // assuming 8 bits for simplicity
    unsigned long decimal = binary.to_ulong();
    std::cout << "Binary: " << binaryString << " -> Decimal: " << decimal << std::endl;
}

int main() 
{

    int choose = 0;
    std::cout<<"1-convert from decimal to binaray\n2-convert from binary to decimal\nEnter your choose: ";
    std::cin>> choose;

    if(choose == 1)
    {
        int num = 0;
        std::cout<<"Enter the decimal number: ";
        std::cin>> num;
        decimalToBinary(num);
    }
    else 
    {
        std::string bin_num = "0";
        std::cout<<"Enter the binary number: ";
        std::cin>> bin_num;
        binaryToDecimal(bin_num);
    
    }


    return 0;
}
