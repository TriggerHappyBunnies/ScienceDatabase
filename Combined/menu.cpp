#include <iostream>
#include <graphics.h>
using namespace std;
int bp=240; int tp=190;
int count=1;
void sets(int ch,int bp,int tp,int pos_b,int pos_t)
{
     if(ch!=1)
     {
        setcolor(BLACK);
        rectangle(520,tp,900,bp);
        setcolor(RED);
        bp+=50;
        rectangle(520,tp+50,900,bp);
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
void mm()
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
void setu(int ch,int bp,int tp,int last_op,int pos_b,int pos_t)
{
     if(ch!=last_op)
     {
         setcolor(BLACK);
         rectangle(520,tp,900,bp);
         setcolor(RED);
         rectangle(520,tp-50,900,bp-50);
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
int box(char ch,int last_op,int pos_b,int pos_t)
{
     if(ch=='s')
            {
                       
                       if(::count==last_op)
                        {
                            ::count=1;bp=240;tp=190;sets(::count,bp,tp,pos_b,pos_t);
                        }
                       else
                        {
                            ::count++;
                            sets(::count,bp,tp,pos_b,pos_t);
                            bp+=50;
                            tp+=50;
                        }
            }
            if(ch=='w')
            {
                       if(::count==1)
                        {
                            ::count=last_op;bp=pos_b;tp=pos_t;setu(::count,bp,tp,last_op,pos_b,pos_t);
                        }
                       else
                        {
                            ::count--;
                        setu(::count,bp,tp,last_op,pos_b,pos_t);
                        bp-=50;
                        tp-=50;}
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
    mm();
    int i=0;
    char ch;
    while(i==0)
    {
        if(kbhit())
        {
            ch=getch();
            if(box(ch,4,390,340)==1)
           break;
        }
    }
    system("pause");
}
