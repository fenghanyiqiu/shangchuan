#include<iostream>
#include<fstream>
#include<iomanip>
#define N 20
using namespace std;
int main()
{
    int rank[N];
    int number[N];
    double average[N];
    int a,b,i,j;
    int m,n;  string y,z;  double sum,x;
    int score[N*7];
    string name[7];
    string competitor[N*2];
    int handle1[7],handle2[5],handle3[N];
    ifstream judgmentin("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/裁判.txt");
    ifstream competitorin("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/选手.txt");
    ofstream out("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/输出.txt");
    for(i=0;i<N;i++)
    {
        rank[i]=i+1;
    }
    for(i=0;i<N;i++)
    {
        number[i]=i;
    }
    for(i=0;i<N*7+7;i++)
    {
       if((i+1)%(N+1)==0)
       {
           j=(i+1)/(N+1)-1;
           judgmentin>>name[j];
       } else
       {
           j=(i+1)/(N+1);
           judgmentin>>score[i-j];
       }
    }
    for(b=0;b<N;b++)
    {
        sum=0;
        for(i=0;i<7;i++)
        {
            handle1[i]=score[i*(N)+b];
        }
        for(a=0;a<7;a++)
        {
            for(j=0;j<7;j++)
            {
                if(handle1[j]<=handle1[j+1])
                {
                    x=handle1[j+1];
                    handle1[j+1]=handle1[j];
                    handle1[j]=x;
                }
            }
        }
        for(i=0;i<5;i++)
        {
            handle2[i]=handle1[i+1];
        }
        for(i=0;i<5;i++)
        {
            sum=sum+handle2[i];
        }
        average[b]=sum*1.0/5.0;
    }
    for(i=0;i<2*N;i++)
    {
        competitorin>>competitor[i];
    }
    for(a=0;a<N;a++)
    {
        for(j=0;j<N;j++)
        {
            if(average[j]<=average[j+1])
            {
                x=average[j+1];
                average[j+1]=average[j];
                average[j]=x;
                y=competitor[2*(j+1)];
                competitor[2*(j+1)]=competitor[2*j];
                competitor[2*j]=y;
                z=competitor[2*(j+1)+1];
                competitor[2*(j+1)+1]=competitor[2*j+1];
                competitor[2*j+1]=z;
                n=number[j+1];
                number[j+1]=number[j];
                number[j]=n;
            }
        }
    }
    out<<std::left<<setw(12)<<"排名";
    for(i=0;i<N;i++)
    {
        out<<std::left<<setw(8)<<rank[i];
    }
    out<<endl;
    out<<std::left<<setw(12)<<"学号";
    for(i=0;i<N;i++)
    {
        out<<std::left<<setw(8)<<competitor[i*2];
    }
    out<<endl<<std::left<<setw(12)<<"姓名";
    for(i=0;i<N;i++)
    {
        out<<std::left<<setw(8)<<competitor[i*2+1];
    }
    out<<endl<<std::left<<setw(15)<<"最终成绩";         
    for(i=0;i<N;i++)
    {
        out<<std::left<<setw(8)<<average[i];
    }
    out<<endl;
    for(i=0;i<7;i++)
    {
        out<<std::left<<setw(9)<<name[i];
        for(j=0;j<N;j++)
        {
            handle3[j]=score[j+N*i];
        }
        for(j=0;j<N;j++)
        {
            m=number[j];
            out<<std::left<<setw(8)<<handle3[m];
        }
        out<<endl;
    }
    return 0;
}
