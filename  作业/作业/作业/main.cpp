#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int average[6];//存储平均成绩；
    int a,b,c,i,j;//用于循环;
    int x,sum=0;//用于处理数据；
    int score[41]; //存放裁判打分；
    string name[6];//存放裁判姓名；
    int handle1[5],handle2[3];//用于处理数据；
    ifstream in("/Users/s20181106277/Desktop/ 作业/作业/裁判.txt");
    for(i=0;i<49;i++)//将数据放入数组；
    {
       if((i+1)%7==0)//将裁判名放入对应数组；
       {
           j=(i+1)/7-1;
           in>>name[j];
       } else      //将打分放入对应数组；
       {
           j=(i+1)/7;
           in>>score[i-j];
       }
    }
    for(b=0;b<7;b++)//对数据进行处理；
    {
        c=0;
        for(i=0;i<6;i++)//将数据放入处理数组
        {
            handle1[c]=score[i*6+b];
            c++;
        }
        for(a=0;a<6;a++)//进行冒泡排序；
        {
            for(j=0;j<6;j++)
            {
                if(handle1[j]>=handle1[j+1])
                {
                    x=handle1[j+1];
                    handle1[j+1]=handle1[j];
                    handle1[j]=x;
                }
            }
        }
        for(j=1;j<5;j++)//去掉最高分，去掉最低分，求取平均分；
        {
            for(a=0;a<4;a++)
            {
                handle2[a]=handle1[j];
            }
            for(a=0;a<4;a++)
            {
                sum=sum+handle2[a];
                average[b]=sum/4;
            }
        }
    }
}
