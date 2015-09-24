// Main project file
//using graphics.h
//have separte class for ur part :)


//I had coded without using a cass, so if u want to test it out on your PC just take the contents of the class
//and dont take the class as a whole.
//IT IS STILL INCOMPLTE. JUST A SAMPLE.
#include<iostream>
#include<graphics.h>
using namespace std;

class LS
{
    #include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

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
        setcolor(WHITE);
        line(x/2,y/2,oposx,(y/2)+50);//Reflected ray2
        setcolor(DARKGRAY);
        p1=(double)((x-50)-x/2)*h/v;
        line(x/2,y/2,(x-50),y/2+p1);//Ray2 inside mirror
        p1=(double)((y/2-50+(R/2))*100)/p;
        setcolor(WHITE);
        line(x/2-50,(y/2)-p1,(x/2)+R-p,(y/2)-50);//Reflected ray 1
        setcolor(DARKGRAY);
        line(x/2+R-p,y/2-50,x/2+(R/2),y/2);//Ray 1 inside mirror
    }
    if(oposx>x/2&&f>0)
    {
        if(oposx>x/2+(R/2))
        {
        setcolor(WHITE);
        p1=(double)((x-50)-x/2)*h/v;
        line(x/2,y/2,(x-50),y/2+p1);  //Reflected ray2
        p1=(double)((1200-p)*50)/p;
        setcolor(WHITE);
        line(x/2-100,y/2+p1,x/2+R-p,y/2-50);//Reflected ray 1 
        }
        else
        {
        setcolor(DARKGRAY);
        p1=(double)((x/2-50+(R/2))*100)/p;
        setcolor(DARKGRAY);
        line(x/2-50,y/2-p1,x/2+R-p,y/2-50);
        setcolor(WHITE);
        line(x/2+R-p,y/2-50,x/2+(R/2),y/2);//Reflected ray 1
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
    initwindow(1360,750);
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
        outtextxy(200,100,"Focal Length :");
        outtextxy(200,800,"Press q to quit.");
        outtextxy(200,750,"Press f to change focal length.");
        itoa(f,ptr,10);
        outtextxy(375,100,ptr);
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
                delay(100);
                goto label;
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

}


class LSim
{
public:
int v,oposx=0,f=10,u,R,h;
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
    arc((800+(f*2)*10),450,100,260,(f*2)*10);
    setcolor(07);
    line(50,450,1550,450);
    setcolor(LIGHTGRAY);
    line(800-R/2,448,800-R/2,452);
    line(800+R/2,448,800+R/2,452);
    line(800-R,448,800-R,452);
    line(800+R,448,800+R,452);
}

void Rays()
{
    p=sqrt(R*R-2500);
    setcolor(WHITE);
    line(oposx,400,800+R-p,400);//Parrallel ray to mirror
    line(oposx,400,800,450);//Ray to pole
    if(oposx<800&&f>0)
    {
        setcolor(WHITE);
        line(800,450,oposx,500);//Reflected ray2
        setcolor(DARKGRAY);
        p1=(double)(1550-800)*h/v;
        line(800,450,1550,450+p1);//Ray2 inside mirror
        p1=(double)((400+(R/2))*100)/p;//HOW THE FK IS IT *100!!!! I FKING DID THIS FORMULA A MILLION TIMES AND THIS RANDOM VALUE FITS IN?!? 
        setcolor(WHITE);
        line(400,450-p1,800+R-p,400);//Reflected ray 1
        setcolor(DARKGRAY);
        line(800+R-p,400,800+(R/2),450);//Ray 1 inside mirror
    }
    if(oposx>800&&f>0)
    {
        if(oposx>800+(R/2))
        {
        setcolor(WHITE);
        p1=(double)(1550-800)*h/v;
        line(800,450,1550,450+p1);  //Reflected ray2
        p1=(double)((1200-p)*50)/p;
        setcolor(WHITE);
        line(1400,450+p1,800+R-p,400);//Reflected ray 1 
        }
        else
        {
        setcolor(DARKGRAY);
        p1=(double)((400+(R/2))*100)/p;
        setcolor(DARKGRAY);
        line(400,450-p1,800+R-p,400);
        setcolor(WHITE);
        line(800+R-p,400,800+(R/2),450);//Reflected ray 1
        setcolor(WHITE);
        p1=(double)(1550-800)*h/v;
        line(800,450,1550,450+p1);  //Reflected ray2
        setcolor(DARKGRAY);
        line(800,450,50,450-p1);  //Ray 2 inside mirror
        }
    }
        
}

int main()
{
    cout<<"Initial focal length is 10 units.\n";
    system("pause");
    initwindow(1600,900);
    while(ch!='q')
    {
        labelX:
        initwindow(1600,900);
        label:  
        cleardevice();
        labelY:   
        settextstyle(4,0,12);
        setcolor(8);      
        outtextxy(200,100,"Focal Length :");
        outtextxy(200,800,"Press q to quit.");
        outtextxy(200,750,"Press f to change focal length.");
        itoa(f,ptr,10);
        outtextxy(375,100,ptr);
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
            u=oposx-800;
            if(u>R/2-5&&u<R/2+5)
            {    
                outtextxy(200,150,"Image at infinity.");
                setcolor(GREEN);
                line(oposx,450,oposx,400);
                delay(100);
                goto label;
            }
            setcolor(GREEN);
            line(oposx,450,oposx,400);
            v=(u*(R/2))/(u-(R/2));
            isize=(double)v/u;
            h=isize*50;
            setcolor(LIGHTGREEN);
            line(800+v,450,800+v,450+h);
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

