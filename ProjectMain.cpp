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
int osize,msize,isize,ipos,oposx,oposy,f=10;
char ch='a',ptr[5];

int getf()
{
    cout<<"\nEnter new focal length : ";
    cin>>f;
    return f;
}

void DrawMir()
{
    arc((800+(f*2)*10),450,100,260,(f*2)*10);
    line(50,450,1550,450);
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
        outtextxy(200,100,"Focal Length :");
        outtextxy(200,800,"Press q to quit.");
        outtextxy(200,750,"Press f to change focal length.");
        itoa(f,ptr,10);
        outtextxy(300,100,ptr);
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
            DrawMir();
            oposx=mousex();
            line(oposx,450,oposx,400);
            delay(100);
            goto label;
        }
    }
    system("pause");
}

}
