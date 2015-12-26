#include <iostream>
#include <graphics.h>
#include <math.h>
#include<stdlib.h>
using namespace std;

extern int mainGC();
extern int mainLS();
extern int mainON();
int flag=0;
int bpX=240; int tpX=190;
int countX=1;
void mainmm()
{
     int i=0,x=0;
     settextstyle(10,0,4);
    setcolor(GREEN);
    outtextxy(700,400,"Developed By-");
    settextstyle(3,0,20);
    while(x<32)
    {
            if(i==16)
            {
             i=1;
            }
            if(x==31)
            setcolor(7);
            else
            setcolor(i);
    outtextxy(330,250,"Science Toolbox");
    if(x==5)
    {
    settextstyle(10,0,4);
    setcolor(WHITE);
    outtextxy(800,450,"Raj US");
    settextstyle(3,0,20);
    }
    if(x==10)
    {
    settextstyle(10,0,4);
    setcolor(WHITE);
    outtextxy(800,490,"Aakash Hegde");
    settextstyle(3,0,20);
    }
    if(x==15)
    {
    settextstyle(10,0,4);
    setcolor(WHITE);
    outtextxy(800,530,"Sushant S Rao");
    settextstyle(3,0,20);
    }
    x++;
    i++;
    delay(140);
    }
    
    setcolor(11);
    settextstyle(3,0,4);

}
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
    setcolor(RED);
    settextstyle(4,0,5);
    outtextxy(550,130,"Main Menu");
    setcolor(WHITE);
    settextstyle(3,0,4);
    outtextxy(530,200,"1.Compound Namer");
    outtextxy(530,250,"2.Light simulator");
    outtextxy(530,300,"3.Linear Graphing");
    outtextxy(530,350,"4.Exit");
    settextstyle(1,0,3);
    setcolor(RED);
    outtextxy(520,400,"Press g to select");
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
    if(flag==0)
    {
    mainmm();
    delay(100);
    cleardevice();
    ::flag=1;
    }
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
        closegraph();
        mainON();
    }
    else if(::countX==2)
    {
        closegraph(); 
        mainLS();
    }
    else if(::countX==3)
    {
        closegraph();
        mainGC();
    }
    else
        exit(1);
    system("pause");
}
