#include <iostream>
int main(){int x,y,z=1;std::cin>>x;for(y=x;y>1;y--)if(x%y==0&&y-x)z=0,std::cout<<'\n'<<y;if(z)std::cout<<"\nPrime\n";main();}
