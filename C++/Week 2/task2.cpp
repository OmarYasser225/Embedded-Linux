/******************************************************************************************/
/* create a function to search to the number in the array which number is taken from user */
/******************************************************************************************/

#include<iostream>

void find_num(int arr[],int num , int count)
{
    for (int i = 0; i < count; i++)
    {
        /* code */
        if(num == arr[i])
        {
            std::cout << "Number founded at index " << i;
            return ;
        }
    }
     std:: cout << "Number not founded";
    
}

int main()
{
    int num = 0;
    int arr [] = {1,2,3,4,5,6,7,8,9};

    std::cout << "Please Enter the number: ";
    std::cin >> num;

    find_num(arr,num,(sizeof(arr)/sizeof(arr[0])));
}