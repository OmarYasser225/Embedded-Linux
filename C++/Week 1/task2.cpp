                   /*           Get max value between three values          */

#include <iostream>

int get_max(int v1 , int v2 , int v3)
{
    int max = v1;

    if(v2 > max && v3 < v2)
        max = v2;
    else if (v3 > max)
        max = v3;

    return max;
}


int main()
{
    int value1 = 0 , value2 = 0 , value3 = 0;

    std:: cin >> value1 >> value2 >> value3;

    int max = get_max(value1,value2,value3);

    std:: cout << "the max value is " << max ;
}