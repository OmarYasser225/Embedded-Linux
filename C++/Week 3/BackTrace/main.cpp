/****************************************************************************************************/
/*                                             Task                                                 */
/****************************************************************************************************/
/*                              Back Trace using stack data structure                               */
/****************************************************************************************************/

#include "backtrace.hpp"

void fun2(int x);
void fun3(int x);
void fun1(int x)
{
    EnterFn;
    fun2(2);
    ExitFn;
}

void fun2(int x)
{
    EnterFn;
    fun3(3);
    ExitFn;
}

void fun3(int x)
{
    EnterFn;
    ExitFn;
}

int main()
{
    EnterFn;
    fun1(3);
    ExitFn;
    return 0;
}
