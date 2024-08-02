/***********************************************************************************************/
/***************** lambda function to calculate the square of a given number *******************/
/***********************************************************************************************/

#include<iostream>

int main()
{
    int num =0 ;
    std :: cout << "Enter the number: ";
    std:: cin >> num ;

    [num]()
    {
        std::cout << "Square of number is "<< num*num;
    }();
}