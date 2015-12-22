#include <iostream>
#include <graphics.h>
#include <math.h>
#include<stdlib.h>
using namespace std;

extern int mainGC();
extern int mainLS();
extern int mainON();

int bpX=240; int tpX=190;
int countX=1;
void setsX(int ch,int bpX,int tpX,int pos_b,int pos_t)
{
     if(ch!=1)
     {
        setcolor(BLACK);
        rectangle(520,tpX,900,bpX);
        setcolor(RED);
        bpX+=50;
        rectangle(520,tpX+50,900,bpX);
        setcolor(11);
     }
     else
     {
        setcolor(BLACK);
        rectangle(520,pos_t,900,pos_b);
        setcolor(RED);
        rectangle(520,190,900,240);
        setcolor(11);
    }
}
void mmX()
{
    outtextxy(530,200,"1.Compound Namer");
    outtextxy(530,250,"2.Light simulator");
    outtextxy(530,300,"3.Linear Graphing");
    outtextxy(530,350,"4.Exit");
    settextstyle(1,0,2);
    setcolor(RED);
    outtextxy(520,400,"Press g to select everywhere");
    setcolor(11);
    settextstyle(3,0,4);
}
void setuX(int ch,int bpX,int tpX,int last_op,int pos_b,int pos_t)
{
     if(ch!=last_op)
     {
         setcolor(BLACK);
         rectangle(520,tpX,900,bpX);
         setcolor(RED);
         rectangle(520,tpX-50,900,bpX-50);
         setcolor(11);
     }
     else
     {
         setcolor(BLACK);
         rectangle(520,190,900,240);
         setcolor(RED);
         rectangle(520,pos_t,900,pos_b);
         setcolor(11);
     }
}
int boxX(char ch,int last_op,int pos_b,int pos_t)
{
     if(ch=='s')
            {
                       
                       if(::countX==last_op)
                        {
                            ::countX=1;bpX=240;tpX=190;setsX(::countX,bpX,tpX,pos_b,pos_t);
                        }
                       else
                        {
                            ::countX++;
                            setsX(::countX,bpX,tpX,pos_b,pos_t);
                            bpX+=50;
                            tpX+=50;
                        }
            }
            if(ch=='w')
            {
                       if(::countX==1)
                        {
                            ::countX=last_op;bpX=pos_b;tpX=pos_t;setuX(::countX,bpX,tpX,last_op,pos_b,pos_t);
                        }
                       else
                        {
                            ::countX--;
                        setuX(::countX,bpX,tpX,last_op,pos_b,pos_t);
                        bpX-=50;
                        tpX-=50;}
            }
            if(ch=='g')
            {
                cleardevice();
                return 1;           
            }
}
int main()
{
    initwindow(1360,700);
    ex_mm:
    settextstyle(3,0,4);
    setcolor(WHITE);
    mmX();
    int i=0;
    char ch;
    while(i==0)
    {
        if(kbhit())
        {
            ch=getch();
            if(boxX(ch,4,390,340)==1)
           break;
        }
    }
    if(::countX==1)
    {
        system("CLS");
        closegraph();
        mainON();
    }
    else if(::countX==2)
    {
         system("CLS");
        closegraph(); 
        mainLS();
    }
    else if(::countX==3)
    {
         //system("CLS");
        closegraph();
        mainGC();
    }
    else
        exit(1);
    system("pause");
}
