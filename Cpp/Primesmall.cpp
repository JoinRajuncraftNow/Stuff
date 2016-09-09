#include <iostream>
using namespace std;int main(){int x, y, z=1;cin>>x;y=x;while(y>0){if(x%y==0&&y!=x&&y!=1){z=0;cout<<endl<<y;}y--;}if(z==1){cout<<"\nPrime\n";}main();}
