#include "std_lib_facilities.h"

int main()
{
	int a=20,b=40;
	
	a*=b;
	b=a/b;
	a=a/b;
	
	cout<<a<<" "<<b<<endl;
	
	return 0;
}
