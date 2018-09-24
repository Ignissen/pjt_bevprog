#include "std_lib_facilities.h"
#include <unistd.h>

void draw(vector<string> v, int x, int y, char c);

int main()
{
	vector<string> v; ///a pálya, amin pattog a labda
	v.push_back("##########################################################");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #"); 
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("#                                                        #");
	v.push_back("##########################################################");
	
	int xlen=v[0].length()-1;  ///a "pálya" szélessége-1
	int ylen=v.size()-1;		 ///a "pálya" magassága-1
	
	int i=1; ///számláló
	
	
	
	int x=1,y=1; ///koordináták és kezdőérték adás
	while(1)
	{
		x=abs(xlen-i%(2*xlen)); ///x koordináták számítása
		y=abs(ylen-i%(2*ylen)); ///y koordináták számítása
		draw(v,x,y,'@');
		i++;
		usleep(50000);
	}
	return 0;
}

void draw(vector<string> v, int x, int y, char c) ///Rajzolásért felelős függvény
{
	system("clear");
	v[y][x]=c;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	
	
}



























