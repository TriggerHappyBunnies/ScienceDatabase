#include "Classes.h"
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

int LS::getf()
{
    f:
    cout<<"\nEnter new focal length : ";
    cin>>f;
    if(!((f>=10)&&(f<=50)||(f>=-50)&&(f<=-10)))
    {
        cout<<"\nEnter a valid integer value between (-50 to -10) or (10 to 50).";
        goto f;
    } 
    if(f<0)
        f=f*(-1);
    return f;
}

void LS::DrawMir()
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

void LS::Rays()
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

void LS::mainLS()
{
    system("CLS");
    ch=' ';
    cout<<"\nREFLECTION SIMULATOR\n\n";
    cout<<"A simple and effective program that gives you the freedom of moving the object\n";
    cout<<"and simulating image formation due to a sperical mirror. You can also adjust the";
    cout<<"focal length of the mirror in the range of 10-50 units.\n\n";
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
        outtextxy(100,680,"Press q to quit to main menu.");
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
                //main();
                return;
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
