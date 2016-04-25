#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream> //We need to start feature planning from the start! - Saving
#include <vector>  //For infinite arrays
using namespace std;
bool exists (string name) //Tell if file exists
{
    ifstream f(name.c_str());
    if (f.good())
    {
        f.close();
        return true;
    }
    else
    {
        f.close();
        return false;
    }   
}
int main(){
  
}
//WIP
