#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int x,y,z;
    ifstream in("/Users/s20181106277/Desktop/lianxiin.txt");
    in>>x>>y;
    z=x+y;
    ofstream out("/Users/s20181106277/Desktop/lianxiout.txt");
    out<<z;
    cout<<z;
}
