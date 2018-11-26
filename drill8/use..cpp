#include <iostream>
#include "my.h"
using namespace std;

int foo;

void swap_v(int a, int b)
{
    int temp; temp = a, a=b; b=temp;
}

void swap_r(int &a, int &b)
{
    int temp; temp = a, a=b; b=temp;
}

/*void swap_v(const int &a,const int &b)
{
    int temp; temp = a, a=b; b=temp;
}*/

int main()
{

    int x = 7;
    int y =9;
    swap_r(x,y);                      // replace ? by v, r, or cr
    //swap_r(7,9);
    const int cx = 7;
    const int cy = 9;
    swap_r(cx,cy);
    swap_r(7.7,9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_r(dx,dy);
    //swap_r(7.7,9.9);
    return 0;
}
