/***********************************************************************************************/
/********************************* Find Max Number in arr **************************************/
/***********************************************************************************************/

#include<iostream>

int get_max(int arr[], int num)
{
    int max = arr[0];
    for (int i = 0; i < num; i++)
    {
        /* code */
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}


int main()
{

    int arr[] = {1,2,3,4,5,6,7};
    
    std::cout<<"Max Number is " << get_max(arr, (sizeof(arr)/sizeof(arr[0])));
}