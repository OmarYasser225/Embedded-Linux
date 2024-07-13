                              /*      Summation of digits        */

#include <iostream>

int main()
{
    int num = 0;
    int temp =0;
    int sum = 0;

    std::cout <<"Enter an integer: ";
    std::cin >> num;

    while (num) 
    {
        temp = num%10;
        sum += temp;
        num/= 10;
    }

    std::cout <<"Summation of digits is "<<sum << std::endl;


}