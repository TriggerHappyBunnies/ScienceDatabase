#include <iostream>
#include <graphics.h>
#include <math.h>
#include<ctype.h>
using namespace std;

extern int main();

float m,c;
static float x=0,y; 
static char ptr[5],ch=' ';

void text()
{
    settextstyle(4,0,12);
    itoa(m,ptr,10);
    int len=0;
    while(!(ptr[len]=='\0'))
    {
        len++;
    }   
    setcolor(WHITE);
    outtextxy(50,50,"Equation of the line : y=");
    outtextxy(317,50,ptr); 
    outtextxy(317+(len*15),50,"x+");  
    c=c/30;
    itoa(c,ptr,10);
    outtextxy(317+(len*15)+30,50,ptr);
    setcolor(8);
    outtextxy(50,680,"Press q to quit to main menu.");
    outtextxy(50,710,"Press r to re-enter values.");
}

int mainGC()
{
    system("CLS");
    cout<<"\nSTRAIGHT LINE GRAPHING CALCULATOR\n\n";  
    cout<<"A simple graphing calculator which lets you input the slope(m) and constant(c)\n";   
    cout<<"and plots the graph against the X and Y coordinates as per the equation :\n";
    cout<<"y=mx+c\n\n";
    label:        
    x=0;                                                     
    cout<<"\nEnter slope : ";                                                                                                 
    cin>>m;                
    cout<<"Enter constant : ";                
    cin>>c;
    c*=30;
    initwindow(1360,750);                
    line(680,0,680,750);
    line(0,375,1360,375);
    for(int i=735;i>=0;i-=30)
    {
        line(678,i,682,i);
    }
    for(int i=1340;i>=0;i-=30)
    {
        line(i,373,i,377);
    }
    while(x<1360)
    {        
        y=(-m*(x-680)-c+375);
        setcolor(9);
        lineto(x,y);
        x++;                                        
    }  
    text();
    labelX:
    if(kbhit())
     {    
         ch=getch();
         if(ch=='r')
         {
             closegraph();
             goto label;
         }
         if(ch=='q')
         {
             closegraph();
             main();
         }
     }
     else
         goto labelX;
    system("pause");
}   
