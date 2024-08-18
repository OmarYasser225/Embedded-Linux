/****************************************************************************************************/
/*                                             Task                                                 */
/****************************************************************************************************/
/*                     Write string class which has Members { length - string}                      */
/****************************************************************************************************/

#include<iostream>

class String
{
    private:
        std::string str;
        int len = 0;
    public:
        String(){} // default constructor
        String(std::string s):str(s),len(s.length()){} // parameterized constructor
        int length(){return len;}
};S



int main()
{
    String obj("hello");
    std::cout<<obj.length();
}