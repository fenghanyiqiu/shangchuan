#include<iostream>
#include<fstream>
#include<iomanip>
#define N 20
using namespace std;
int main()
{
    int rank[N];                                                                           //用于排名；
    int number[N];                                                                         //辅助输出数据
    double average[N];                                                                     //求取平均值；
    int i,j,k;                                                                             //用于循环
    int m,n;                                                                               //用于处理数据；
    string y,z;                                                                            //用于处理数据；
    double sum,x;                                                                          //用于处理数据；
    int score[N*7];                                                                        //用于储存数据；
    string name[7];                                                                        //储存裁判姓名；
    string competitor[N*2];                                                                //存放选手信息；
    int handle1[7],handle2[5],handle3[N];                                                  //用于处理数据；
    ifstream judgmentin("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/裁判.txt");
    ifstream competitorin("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/选手.txt");
    ofstream out("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/输出.txt");
    for(i=0;i<N;i++)                                                                       //将用于排名的数放入数组
    {
        rank[i]=i+1;
    }
    for(i=0;i<N;i++)
    {
        number[i]=i;
    }
    for(i=0;i<N*7+7;i++)                                                                   //将裁判姓名放入对应数组；
    {
       if((i+1)%(N+1)==0)
       {
           j=(i+1)/(N+1)-1;
           judgmentin>>name[j];
       }
       else                                                                                //将裁判打分放入对应数组；
       {
           j=(i+1)/(N+1);
           judgmentin>>score[i-j];
       }
    }
    for(k=0;k<N;k++)                                                                       //对数据进行处理；
    {
        sum=0;
        for(i=0;i<7;i++)                                                                   //将一个学生的打分放入处理数组；
        {
            handle1[i]=score[i*(N)+k];
        }
        for(i=0;i<7;i++)                                                                   //进行冒泡排序；
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
        for(i=0;i<5;i++)                                                                    //去掉最高分与最低分；
        {
            handle2[i]=handle1[i+1];
        }
        for(i=0;i<5;i++)                                                                    //求取最终成绩；
        {
            sum=sum+handle2[i];
        }
        average[k]=sum*1.0/5.0;                 
    }
    for(i=0;i<2*N;i++)                                                                      //放入选手信息；
    {
        competitorin>>competitor[i];
    }
    for(i=0;i<N;i++)                                                                        //将选手信息与得分绑定并排名；
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
    out<<std::left<<setw(12)<<"排名";                                                         //输出排名；
    for(i=0;i<N;i++)
    {
        out<<std::left<<setw(8)<<rank[i];
    }
    out<<endl;
    out<<std::left<<setw(12)<<"学号";                                                         //输出学号；
    for(i=0;i<N;i++)
    {
        out<<std::left<<setw(8)<<competitor[i*2];
    }
    out<<endl<<std::left<<setw(12)<<"姓名";                                                   //输出姓名；
    for(i=0;i<N;i++)
    {
        out<<std::left<<setw(8)<<competitor[i*2+1];
    }
    out<<endl<<std::left<<setw(15)<<"最终成绩";                                                //输出最终成绩；
    for(i=0;i<N;i++)
    {
        out<<std::left<<setw(8)<<average[i];
    }
    out<<endl;
    for(i=0;i<7;i++)
    {
        out<<std::left<<setw(9)<<name[i];                                                      //输出裁判姓名与对应打分；
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
