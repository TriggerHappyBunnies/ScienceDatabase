// Main project file
//using graphics.h
//have separte class for ur part :)


//I had coded without using a cass, so if u want to test it out on your PC just take the contents of the class
//and dont take the class as a whole.

//LIGHT SIMULATOR COMPLETE! 
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class LS
{
int v,oposx=0,f=10,u,R,h;
int x,y;
double p1,p;
double isize;
char ch='a',ptr[5];

int getf()
{
    cout<<"\nEnter new focal length : ";
    cin>>f;
    return f;
}

void DrawMir()
{
    setcolor(BROWN);
    arc((x/2+(f*2)*10),y/2,100,260,(f*2)*10);
    setcolor(07);
    line(50,y/2,x-50,y/2);
    setcolor(LIGHTGRAY);
    line(x/2-R/2,y/2-2,x/2-R/2,y/2+2);
    line(x/2+R/2,y/2-2,x/2+R/2,y/2+2);
    line(x/2-R,y/2-2,x/2-R,y/2+2);
    line(x/2+R,y/2-2,x/2+R,y/2+2);
}

void Rays()
{
    p=sqrt(R*R-2500);
    setcolor(WHITE);
    line(oposx,(y/2)-50,(x/2)+R-p,(y/2)-50);//Parrallel ray to mirror
    line(oposx,y/2-50,x/2,y/2);//Ray to pole
    
    if(oposx<x/2&&f>0)
    {
        setcolor(8);      
        outtextxy(100,610,"Nature of mirror : Convex");
        setcolor(WHITE);
        line(x/2,y/2,oposx,(y/2)+50);//Reflected ray2
        setcolor(DARKGRAY);
        p1=(double)((x-50)-x/2)*h/v;
        line(x/2,y/2,(x-50),y/2+p1);//Ray2 inside mirror
        setcolor(WHITE);
        p1=(double)((x/2+(R/2))*100)/p;
        line(0,y/2-p1,x/2+R-p,y/2-50);//Reflected ray 1
        setcolor(DARKGRAY);
        p1=(double)((1200-p)*50)/p;
        line(x-80,y/2+p1,x/2+R-p,y/2-50);//Ray 1 inside mirror
    }
    
    if(oposx>x/2&&f>0)
    {
        setcolor(8);      
        outtextxy(100,610,"Nature of mirror : Concave");
        if(oposx>x/2+(R/2))
        {
        setcolor(WHITE);
        p1=(double)((x-50)-x/2)*h/v;
        line(x/2,y/2,(x-50),y/2+p1);  //Reflected ray2
        p1=(double)((1200-p)*50)/p;
        setcolor(WHITE);
        line(x-80,y/2+p1,x/2+R-p,y/2-50);//Reflected ray 1 
        }
        else
        {
        setcolor(DARKGRAY);
        p1=(double)((x/2+(R/2))*100)/p;
        setcolor(DARKGRAY);
        line(0,y/2-p1,x/2+R-p,y/2-50);//Ray 1 inside mirror
        setcolor(WHITE);
        p1=(double)((1200-p)*50)/p;
        line(x-80,y/2+p1,x/2+R-p,y/2-50);;//Reflected ray 1
        setcolor(WHITE);
        p1=(double)((x-50)/2)*h/v;
        line(x/2,y/2,x-50,y/2+p1);  //Reflected ray2
        setcolor(DARKGRAY);
        line(x/2,y/2,50,y/2-p1);  //Ray 2 inside mirror
        }
    }        
}

int main()
{
    cout<<"Initial focal length is 10 units.\n";
    system("pause");
    initwindow(1360,700);
    x=getmaxx();
    y=getmaxy();
    while(ch!='q')
    {
        labelX:
        initwindow(1360,750);
        label:  
        cleardevice();
        labelY:   
        settextstyle(4,0,12);
        setcolor(8);      
        outtextxy(100,550,"Focal Length :");
        outtextxy(100,680,"Press q to quit.");
        outtextxy(100,700,"Press f to change focal length.");
        itoa(f*10,ptr,10);
        outtextxy(330,550,"pixels (Entered f*10)");
        outtextxy(275,550,ptr);
        itoa(u,ptr,10);
        outtextxy(100,570,"Object Distance : ");
        outtextxy(300,570,ptr);
        itoa(v,ptr,10);
        outtextxy(100,590,"Image Distance : ");
        outtextxy(300,590,ptr);
        if(kbhit())
        {    
            ch=getch();
            if(ch=='q')
            {
                closegraph();
                break;
            }
            else if(ch=='f')
            {
                closegraph();
                f=getf();
                goto labelX;
            }
            else
                goto label;
        }
         
        else
        {

            R=(f*2)*10;
            DrawMir();  
            oposx=mousex();
            u=oposx-x/2;
            if(u>R/2-5&&u<R/2+5)
            {    
                outtextxy(200,150,"Image at infinity.");
                setcolor(GREEN);
                line(oposx,(y/2),oposx,(y/2)-50);
                p=sqrt(R*R-2500);
                setcolor(WHITE);
                line(oposx,(y/2)-50,(x/2)+R-p,(y/2)-50);//Parrallel ray to mirror
                line(oposx,y/2-50,x/2,y/2);//Ray to pole
                setcolor(DARKGRAY);
                p1=(double)((x/2+(R/2))*100)/p;;
                line(0,y/2-p1,x/2+R-p,y/2-50);//Ray 1 inside mirror
                setcolor(WHITE);
                p1=(double)((1200-p)*50)/p;
                line(x-80,y/2+p1,x/2+R-p,y/2-50);;//Reflected ray 1
                setcolor(WHITE);
                p1=(double)((x-50)/2)*h/v;
                line(x/2,y/2,x-50,y/2+p1);  //Reflected ray2
                setcolor(DARKGRAY);
                line(x/2,y/2,50,y/2-p1);  //Ray 2 inside mirror
                no_flik:
                if(mousex()!=oposx)
                    goto label;
                else
                    goto no_flik;
            }
            setcolor(GREEN);
            line(oposx,y/2,oposx,(y/2)-50);
            v=(u*(R/2))/(u-(R/2));
            isize=(double)v/u;
            h=isize*50;
            setcolor(LIGHTGREEN);
            line(x/2+v,y/2,x/2+v,y/2+h);
            Rays();  
            delay(100);            
            if(mousex()==oposx)
                goto labelY;
            goto label;
        }
    }
    system("pause");
}


class compound_namer
{
#include<iostream>
#include <graphics.h>
using namespace std;
void sets(int ch,int bp,int tp)
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
     rectangle(520,340,900,390);
     setcolor(RED);
     rectangle(520,190,900,240);
     setcolor(11);
     }
}
void mm()
{
    outtextxy(530,200,"1.Straight Chain");
    outtextxy(530,250,"2.Cyclic");
    outtextxy(530,300,"3.Benzene");
    outtextxy(530,350,"4.Exit"); 
}
void m2()
{
    
     outtextxy(500,300,"Enter no of c-atoms -/+");
     settextstyle(1,0,2);
     outtextxy(540,340,"Press x for main menu");
     settextstyle(3,0,4);
     rectangle(920,290,975,330);
}
void benzene()
{
     setcolor(11);
     line(600,500,650,470);     
     
     line(650,470,700,500);
     line(700,500,700,550);
     line(600,500,600,550);
     circle(650,525,20);
     line(700,550,650,580);
     line(600,550,650,580);
     
}
void setu(int ch,int bp,int tp)
{
     if(ch!=4)
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
     rectangle(520,340,900,390);
     setcolor(11);
     }
}
int main()
{
    int flag1=1;
    int i=0;char ch;int count=1;
    int bp=240; int tp=190;
    int x=0;
    int y=48;
    int xv=550;
    char no[0];
    memset(no,0,2);
    sprintf(no,"%d",x);
    initwindow(1360,700);
    m1:
    settextstyle(3,0,4);
    sets(count,bp,tp);
    mm();
    while(i==0)
    {
        if(kbhit())
        {
            ch=getch();
            if(ch=='s')
            {
                       
                       if(count==4)
                       {count=1;bp=240;tp=190;sets(count,bp,tp);continue;}
                       else{count++;}
                       sets(count,bp,tp);
                       bp+=50;
                       tp+=50;
            }
            if(ch=='w')
            {
                       if(count==1)
                       {count=4;bp=390;tp=340;setu(count,bp,tp);continue;}
                       else{count--;}
                       setu(count,bp,tp);
                       bp-=50;
                       tp-=50;
                       
            }
            if(ch=='g')
            {
            cleardevice();
            break;           
            }
        }
    }
    m2:
    if(count==2)
    {
         m2();
        outtextxy(930,296,no);
        while(i==0)
         {
               if(kbhit())
               {
                        ch=getch();
                        if(ch=='w')
                        {
                             setcolor(GREEN);
                             outtextxy(875,300,"+");//951
                            setcolor(BLACK);
                            outtextxy(930,296,no);
                            setcolor(11);
                            x++;
                            flag1=1;
                            if(x==13)
                            {x=0;flag1=0;}
                            memset(no,0,2);
                            sprintf(no,"%d",x);
                            outtextxy(930,296,no);
                            delay(100);
                            setcolor(11);
                            outtextxy(875,300,"+");
                        }  
                        if(ch=='s')
                        {
                            setcolor(RED);
                            outtextxy(851,300,"-");
                            setcolor(BLACK);
                            outtextxy(930,296,no);
                            setcolor(11);
                            x--;
                            if(x==-1)
                            {x=12;}
                            memset(no,0,2);
                            sprintf(no,"%d",x);
                            outtextxy(930,296,no);
                            delay(100);
                            setcolor(11);
                            outtextxy(851,300,"-");
                            flag1=0;
                        }
                        if(ch=='x')
                       {
                       cleardevice();x=0;
                       memset(no,0,2);
                       sprintf(no,"%d",x);goto m1;
                       }
                       setcolor(BLACK);
                       if(flag1==0)
                       { 
                          xv=450;
                          for(int k=0;k<12;k++)
                          {
                               outtextxy(xv,500,"C-");
                               if(k==10)
                               outtextxy(xv,500,"C");
                               xv+=50;
                          }
                       }
                       xv=450;
                       setcolor(11);
                       for(int j=0;j<x;j++)
                       {
                               outtextxy(xv,500,"C-");
                               if(j==10)
                               outtextxy(xv,500,"C");
                               xv+=50;
                       }
               }
         }
    } 
    if(count==3)
    {
                benzene();         
    }   
    //while(i==0)
    //{}
    system("pause");
}
}
}

//STRAIGHT LINE GRAPHING CALCULATOR
//COMPLETE

#include<iostream>
#include<graphics.h>
using namespace std;

float m,c,x=0,y; 
char ptr[5],ch=' ';

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
    outtextxy(50,680,"Press q to quit.");
    outtextxy(50,710,"Press r to re-enter values.");
}

int main()
{
 
    cout<<"\nSTRAIGHT LINE GRAPHING CALCULATOR\n";     
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
             exit(0);
         }
     }
     else
         goto labelX;
    system("pause");
}   


