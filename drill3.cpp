#include "std_lib_facilities.h"





int main()
{
	
	string first_name;
	
	cout<<"Enter the name of the person you want to write to: ";
	cin>>first_name;
	
	cout<<"Dear "<<first_name<<","<<endl;
	
	cout<<"How are you? I am fine. I miss you."	<<endl;
	
	string friend_name;
	cout<<"Please enter a friend's name: ";
	cin>>friend_name;
	
	cout<<"Have you seen "<<friend_name<<" lately?"<<endl;
	
	
	char friend_sex=0;
	cout<<"Is "<<friend_name<<" male(m) or female(f)?";
	cin>>friend_sex;
	
	if(friend_sex=='m')
	{
		cout<<"If you see "<< friend_name<<" please ask him to call me."<<endl;
	}
	else
	{
		cout<<"If you see "<< friend_name<<" please ask her to call me."<<endl;
	}
	
	int age;
	cout<<"Please enter "<<first_name<<"'s age: ";
	cin>>age;
	if(age<1 || age>110)
	{
		simple_error("You're kidding.");
	}
	cout<<"I hear you just had a birthday and you are "<<age<<" years old."<<endl;
	if(age<12)
	{
		cout<<"Next year you will be "<<age+1<<"."<<endl;
	}
	else if(age==17)
	{
		cout<<"Next year you will be able to vote."<<endl;
	}
	else if(age>70)
	{
		cout<<"I hope you are enjoying retirement."<<endl;
	}
	
	cout<<"Yours sincerely,\n\nJózsi"<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
