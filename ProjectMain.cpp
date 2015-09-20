// Main project file
//using graphics.h
//have separte class for ur part :)


//I had coded without using a cass, so if u want to test it out on your PC just take the contents of the class
//and dont take the class as a whole.
//IT IS STILL INCOMPLTE. JUST A SAMPLE.
#include<iostream>
#include<graphics.h>
using namespace std;


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
void sets(int ch,int bp,int tp)
{
     if(ch!=1)
     {
     setcolor(BLACK);
     rectangle(670,tp,1000,bp);
     setcolor(RED);
     bp+=50;
     rectangle(670,tp+50,1000,bp);
     setcolor(11);
     }
     else
     {
     setcolor(BLACK);
     rectangle(670,440,1000,490);
     setcolor(RED);
     rectangle(670,290,1000,340);
     setcolor(11);
     }
}
void mm()
{
    outtextxy(680,300,"1.Straight Chain");
    outtextxy(680,350,"2.Cyclic");
    outtextxy(680,400,"3.Benzene");
    outtextxy(680,450,"4.Exit"); 
}
void m2()
{
    
     outtextxy(600,300,"Enter no of c-atoms -/+");
     settextstyle(1,0,2);
     outtextxy(640,340,"Press x for main menu");
     settextstyle(3,0,4);
     rectangle(1020,290,1075,330);
     
     
}
void setu(int ch,int bp,int tp)
{
     if(ch!=4)
     {
     setcolor(BLACK);
     rectangle(670,tp,1000,bp);
     setcolor(RED);
     rectangle(670,tp-50,1000,bp-50);
     setcolor(11);
     }
     else
     {
     setcolor(BLACK);
     rectangle(670,290,1000,340);
     setcolor(RED);
     rectangle(670,440,1000,490);
     setcolor(11);
     }
}
int main()
{
    int flag1=1;
    int i=0;char ch;int count=1;
    int bp=340; int tp=290;
    int x=0;
    int y=48;
    int xv=550;
    char no[0];
    memset(no,0,2);
    sprintf(no,"%d",x);
    initwindow(1600,900);
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
                       {count=1;bp=340;tp=290;sets(count,bp,tp);continue;}
                       else{count++;}
                       sets(count,bp,tp);
                       bp+=50;
                       tp+=50;
            }
            if(ch=='w')
            {
                       if(count==1)
                       {count=4;bp=490;tp=440;setu(count,bp,tp);continue;}
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
    if(count!=3 && count!=4)
    {
         m2();
        outtextxy(1030,296,no);
        while(i==0)
         {
               if(kbhit())
               {
                        ch=getch();
                        if(ch=='w')
                        {
                             setcolor(GREEN);
                             outtextxy(975,300,"+");//951
                            setcolor(BLACK);
                            outtextxy(1030,296,no);
                            setcolor(11);
                            x++;
                            flag1=1;
                            if(x==13)
                            {x=0;flag1=0;}
                            memset(no,0,2);
                            sprintf(no,"%d",x);
                            outtextxy(1030,296,no);
                            delay(100);
                            setcolor(11);
                            outtextxy(975,300,"+");
                        }  
                        if(ch=='s')
                        {
                            setcolor(RED);
                            outtextxy(951,300,"-");
                            setcolor(BLACK);
                            outtextxy(1030,296,no);
                            setcolor(11);
                            x--;
                            if(x==-1)
                            {x=12;}
                            memset(no,0,2);
                            sprintf(no,"%d",x);
                            outtextxy(1030,296,no);
                            delay(100);
                            setcolor(11);
                            outtextxy(951,300,"-");
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
                          xv=550;
                          for(int k=0;k<12;k++)
                          {
                               outtextxy(xv,600,"C-");
                               xv+=50;
                          }
                       }
                       xv=550;
                       setcolor(11);
                       for(int j=0;j<x;j++)
                       {
                               outtextxy(xv,600,"C-");
                               xv+=50;
                       }
               }
                     
               
         }
    }    
    //while(i==0)
    //{}
    system("pause");
}
}
}

