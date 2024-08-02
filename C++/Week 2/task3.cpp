/***********************************************************************************************/
/********************************* Delete number in array **************************************/
/***********************************************************************************************/

#include<iostream>

void delete_element(int* arr , int num , int count)
{
    int i  = 0;
    for ( i = 0; i < count; i++)
    {
        /* code */
        if(arr[i]== num)
        {
            break;
        }
    }
    

    for (int j = i ; j < count; j++)
    {
        /* code */
        arr[j] = arr[j+1];
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int num = 0;
    int count = (sizeof(arr)/sizeof(arr[0]));

    std::cout << "Enter the number: ";
    std::cin >> num;

    delete_element(arr,num,count);

    for(int i = 0 ; i < count-1 ; i++)
    {
        std::cout <<arr[i] <<"\n";
    }

}