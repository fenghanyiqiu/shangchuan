#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int average;   //
    int i,j//用于循环
    int score[41]; //存放裁判打分；
    string name[6];//存放裁判姓名；
    int handle[5];//用于处理数据；
    ifstream in("/Users/s20181106277/Desktop/ 作业/作业/裁判.txt");
    for(i=0;i<49;i++)//将数据放入数组；
    {
       if(i+1)%7==0)//将裁判名放入对应数组；
       {
           j=(i+1)/7-1;
           in>>name[j];
       } else      //将打分放入对应数组；
       {
           j=(i+1)/7;
           in>>score[i-j];
       }
    }
    for(i=0;i<42;i++)
    {
        for(j=0;j<6;j++)//
        {
            handle[j]=score[i];
        }
    }
}
