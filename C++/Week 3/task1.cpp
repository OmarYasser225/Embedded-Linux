/****************************************************************************************************/
/*                                            Tasks                                                 */
/****************************************************************************************************/
/*                               Check if the character is digit?                                   */
/*                               Check if all the array is even?                                    */
/*                         Check if there is any value of array is even ?                           */
/****************************************************************************************************/

#include<iostream>

class check
{
    private:
        char symbol;
        char* ptr_char = nullptr;
        int size_ptr_char = 0;

    public:
    check(){} // default constructor
    check(char s):symbol(s){} // parameterized constructor
    check(char* s,int size):ptr_char(s),size_ptr_char(size){} // parameterized constructor
    void IsCharDigit()
    {
        if(symbol >= '0' && symbol <= '9')
        {
            std::cout<<"It is a digit"<<std::endl;
            return;
        }
        std::cout<<"It is not a digit"<<std::endl;
    }

    void IsAllArrayDigits()
    {
        if(ptr_char != nullptr)
        {
            for(int i=0; i< size_ptr_char; i++)
            {
                if(ptr_char[i] >= '0' && ptr_char[i] <= '9'){}
                else
                {
                    std::cout<< "the array is not all digit"<<std::endl;
                    return;
                }
            }
        }
        else
        {
            std::cout<<"there is no exist array"<<std::endl;
        }
        
        std::cout<< "the array is all digit"<<std::endl;
    }

    void FindArrayEven()
    {
        if(ptr_char != nullptr)
        {
            for(int i=0; i< size_ptr_char; i++)
            {
                if(ptr_char[i] % 2 == 0)
                {
                    std::cout<< ptr_char[i] << " , it is even number"<<std::endl;
                }
                
            }
        }
        else
        {
            std::cout<<"there is no exist array"<<std::endl;
        }
        
    }



};

int main()
{
    char c = 0;
    char arr[10] = {'1','2','3','4','5','6','7','8','A','0'};

    check obj(arr,sizeof(arr)/sizeof(arr[0]));
    obj.FindArrayEven();
}