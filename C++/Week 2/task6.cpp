/***********************************************************************************************/
/********* lambda functions to sort an array of integers in ascending and descending ***********/
/***********************************************************************************************/


#include <iostream>


int main()
{
    int num[] = {8,65,4,5,23,4,8,9,31,1} ;
    int count = sizeof(num)/sizeof(num[0]);

    auto sort_array = [&num,count](std::string type = "descending")mutable
    {
        int temp = 0;
        
        if(type == "descending")
        {
            for (int i = 0; i < count; i++)
            {
                for (int j = 0; j < count; j++)
                {
                    if(num[j] < num[i])
                    {
                        temp = num[j];
                        num[j] = num[i];
                        num[i] = temp;
                    }
                }
            
            }

        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                for (int j = 0; j < count; j++)
                {
                    if(num[j] > num[i])
                    {
                        temp = num[j];
                        num[j] = num[i];
                        num[i] = temp;
                    }
                }
            
            }


        }
    };


    sort_array("ascending");

    for(int i : num)
        std:: cout << i << " ";

    
}