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
int v,oposx,f=10,u,R,h;
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
            //Rays();
            delay(100);
            goto label;
        }
    }
    system("pause");
}

