#include <iostream>
#include <vector>

using namespace std;


template<class T>
void csere(T &a,T &b)
{
	T tmp=a;
	a=b;
	b=tmp;
}

template<class T>
void buborek(vector<T> &v)
{
	int n=v.size();
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(v[j]<v[j-1])
			{
				csere(v[j],v[j-1]);
			}
		}
	}
}

int main()
{

	double x,min=999999999999999,max=0,sum=0;
	string s;
	vector<double> v;
	
	
	while(!cin.fail())
	{
		cin>>x>>s;
		
		if(s=="cm")
		{
			x=x/100;
			sum+=x;
			v.push_back(x);
		}
		else if(s=="ft")
		{
			x=2.54*12*x/100;
			sum+=x;
			v.push_back(x);
		}
		else if(s=="in")
		{
			x=2.54*x/100;
			sum+=x;
			v.push_back(x);
		}
		else if(s=="m")
		{
			sum+=x;
			v.push_back(x);
		}
		else 
		{
			cout<<"This is an illegal unit."<<endl;
			break;
		}
		
		if(x>max)
		{
			cout<<"This is largest number so far.\n";
			max=x;
		}
		else if(x<min)
		{
			cout<<"This is smallest number so far.\n";
			min=x;
		}
		
	}
	
	buborek(v);
	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\n";
	}
	
	
	return 0;
}








































