#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
    int rank[6]={1,2,3,4,5,6};                       //用于排名
    int average[6];                                  //存储平均成绩；
    int a,b,c,i,j;                                   //用于循环;
    int x,sum;  string y,z;                        //用于处理数据；
    int score[42];                                   //存放裁判打分；
    string name[7];                                  //存放裁判姓名；
    string competitor[12];                           //选手信息；
    int handle1[7],handle2[5];                       //用于处理数据；
    ifstream judgmentin("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/裁判.txt");
    ifstream competitorin("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/选手.txt");
    ofstream out("/Users/s20181106277/Desktop/shangchuan/ 作业/作业/输出.txt");
    for(i=0;i<49;i++)                                //将数据放入数组；
    {
       if((i+1)%7==0)                                //将裁判名放入对应数组；
       {
           j=(i+1)/7-1;
           judgmentin>>name[j];
       } else                                        //将打分放入对应数组；
       {
           j=(i+1)/7;
           judgmentin>>score[i-j];
       }
    }
    for(b=0;b<6;b++)                                 //对数据进行处理；
    {
        sum=0;
        c=0;
        for(i=0;i<7;i++)                             //将数据放入处理数组
        {
            handle1[c]=score[i*6+b];
            c++;
        }
        for(a=0;a<7;a++)                             //进行冒泡排序；
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
        handle2[0]=handle1[1];                        //去掉最高分与最低分；
        handle2[1]=handle1[2];
        handle2[2]=handle1[3];
        handle2[3]=handle1[4];
        handle2[4]=handle1[5];
        for(i=0;i<5;i++)                              //计算最终成绩；
        {
            sum=sum+handle2[i];
        }
        average[b]=sum/5;
    }
    for(i=0;i<12;i++)                                 //将选手数据存入数组；
    {
        competitorin>>competitor[i];
    }
    for(a=0;a<6;a++)                                  //进行冒泡排序并且选手信息与分数绑定；
    {
        for(j=0;j<6;j++)
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
            }
        }
    }
    out<<std::left<<setw(12)<<"排名";
    for(i=0;i<6;i++)
    {
        out<<std::left<<setw(8)<<rank[i];
    }
    out<<endl;
    out<<std::left<<setw(15)<<"学院编号";
    for(i=0;i<6;i++)
    {
        out<<std::left<<setw(8)<<competitor[i*2];
    }
    out<<endl<<std::left<<setw(12)<<"姓名";
    for(i=0;i<6;i++)
    {
        out<<std::left<<setw(8)<<competitor[i*2+1];
    }
    out<<endl<<std::left<<setw(15)<<"最终成绩";
    for(i=0;i<6;i++)
    {
        out<<std::left<<setw(8)<<average[i];
    }
    for(i=0;i<7;i++)
    {
        out<<std::left<<setw(8)<<name[i];
    }
    return 0;
}
