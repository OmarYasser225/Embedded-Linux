                           /*         Multiplication Table          */

#include <iostream>
#include <iomanip>

int set_dis(int i ,int num)
{
    int length = 0;

    if(i*num < 10)
           length = 13;
    else if (i*num >=10 && i*num <= 99 ) 
           length = 12;
    else
           length = 11;

    if (num >= 10)
        length--;

    if(i >= 10)
        length--;
    
    
    return length;
    
}

int main()
{
    int num = 0, length = 0;

    std::cout<<"Enter the numbuer of multiplication table : ";
    std::cin >> num;


    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"     Multiplication Table of "<< num << std::endl;
    std::cout<<"----------------------------------"<<std::endl;

    for (int i = 0; i < 13; i++) 
    {
        std::cout<< "|           ";
        std::cout<< i << " x " << num << " = " << i*num ;
        
        length = set_dis(i ,num);
            

        std::cout<< std::setw(length) <<"|"<< std::endl;
    }

}