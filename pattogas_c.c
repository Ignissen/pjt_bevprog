#include <stdio.h>
#include <stdlib.h>

void draw(char v[20][46], int x, int y, char c);
int main()
{
	char v[20][46] ={"#############################################"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#                                           #"
					,"#############################################"};
		
	
	int xlen=45-1;  ///a "pálya" szélessége-1
	int ylen=20-1;		 ///a "pálya" magassága-1
	
	int i=1; ///számláló
	
	
	
	int x=1,y=1; ///koordináták és kezdőérték adás
	while(1)
	{
		x=abs(xlen-i%(2*xlen)); ///x koordináták számítása
		y=abs(ylen-i%(2*ylen)); ///y koordináták számítása
		char v2[20][46];
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<46;j++)
			{
				v2[i][j]=v[i][j];
			}
		}
		draw(v2,x,y,'@');
		i++;
		usleep(50000);
	}
	return 0;
}



void draw(char v[20][46], int x, int y, char c) ///Rajzolásért felelős függvény
{
	system("clear");
	v[y][x]=c;
	for(int i=0;i<20;i++)
	{
		printf("%s\n",v[i]);
	}
	
	
}



























