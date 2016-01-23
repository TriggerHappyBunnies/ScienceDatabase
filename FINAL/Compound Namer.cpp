#include "Classes.h"
#include <graphics.h>
using namespace std;

int bp=240; int tp=190;
int count=1;
void CN::sets(int ch,int bp,int tp,int pos_b,int pos_t)
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
void CN::mm()
{
     setcolor(RED);
     settextstyle(10,0,8);
    outtextxy(350,180,"COMPOUND NAMER");
    settextstyle(3,0,4);
    outtextxy(410,300,"Instructions:");
    settextstyle(4,0,3);
    setcolor(WHITE);
    outtextxy(450,340,"Press i for information on compound namer");
    outtextxy(450,370,"Press g to select");
    outtextxy(450,400,"Press q to quit");
    outtextxy(450,430,"Press w and s for up and down buttons");
    settextstyle(3,0,4);
    setcolor(11);
}
void CN::info()
{
    settextstyle(10,0,6);
    setcolor(RED);
    outtextxy(500,100,"INFORMATION");
    setcolor(WHITE);
    settextstyle(3,0,2);
    outtextxy(360,200,"Organic compounds are made up of carbon atoms.These compounds can be made up");
    outtextxy(360,230,"zero or no substituents.For being able to recognize these compounds without ");
    outtextxy(360,260,"drawing IUPAC made a set of rules for naming compounds.There is some level of");
    outtextxy(360,290,"difficulty in nameing these compounds. This program is designed to make it easy");
    outtextxy(360,320,"to name these compounds. Given the structure of the compound the program can");
    outtextxy(360,350,"help name the compound, hence the structure is needed as input.");
    setcolor(RED);
    outtextxy(570,390,"Press any key to continue");
    int g=0;
    while(g==0)
    {
        if(kbhit())
        {
            setcolor(GREEN);
            outtextxy(570,390,"Press any key to continue");
            delay(150);
            settextstyle(3,0,4);
            setcolor(11);
            break;
        }
    }
}
void CN::m2()
{
     outtextxy(500,300,"Enter no of c-atoms -/+");
     settextstyle(1,0,2);
     outtextxy(540,340,"Press x for main menu");
     settextstyle(3,0,4);
     rectangle(920,290,975,330);
}
void CN::m21()
{
    outtextxy(530,200,"1.Carboxylic Acid");
    outtextxy(530,250,"2.Aldehyde");
    outtextxy(530,300,"3.Ketone");
    outtextxy(530,350,"4.Alcohol");
    settextstyle(1,0,2);
    outtextxy(530,400,"Press x for main menu");
    outtextxy(530,430,"Press n to name");
    settextstyle(3,0,4); 
}
void CN::m211()
{                       
     outtextxy(500,300,"Pos of substituent  -/+");
     settextstyle(1,0,2);
     outtextxy(540,340,"Press x to return");
     settextstyle(3,0,4);
     rectangle(920,290,975,330);
}
void CN::benzene()
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
void CN::setu(int ch,int bp,int tp,int last_op,int pos_b,int pos_t)
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
int CN::box(char ch,int last_op,int pos_b,int pos_t)
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
void CN::draw_c(int flag1,int x)
{
    setcolor(BLACK);
    int xv=450;
    if(flag1==0)
    { 
         xv=450;
         for(int k=0;k<12;k++)
         {
            outtextxy(xv,600,"C-");
            xv+=90;
         }
    }
    xv=450;
    setcolor(11);
    for(int j=0;j<x;j++)
    {
         outtextxy(xv,600,"C-");
         xv+=90;
    }
}
void CN::draw_subst(int subst[11],int x)
{
     for(int i=0;i<11;i++)
     {
             if(subst[i]==1)
             {
                line(465+(i*90),595,465+(i*90),560);
                outtextxy(450+(i*90),550,"OH");
                line(463+(i*90),628,463+(i*90),644);
                line(467+(i*90),628,467+(i*90),644);
                outtextxy(450+(i*90),645,"O"); 
             }
             if(subst[i]==2)
             {
                line(465+(i*90),595,465+(i*90),560);
                outtextxy(450+(i*90),550,"CHO");
             }
             if(subst[i]==3)
             {
                line(463+(i*90),595,463+(i*90),560);
                line(467+(i*90),595,467+(i*90),560);
                outtextxy(450+(i*90),550,"O");
             }
             if(subst[i]==4)
             {
                line(465+(i*90),595,465+(i*90),560);
                outtextxy(450+(i*90),550,"OH"); 
             }
     }
}
void CN::reset(int subst[11])
{    
    for(int i=0;i<11;i++)
    {
        subst[i]=0;
    }
}
void CN::alkane(int n,int flag)
{
     if(flag!=0)
     {
        if(n==1)
            outtextxy(520,250,"methan");
        if(n==2)
            outtextxy(520,250,"ethan");
        if(n==3)
            outtextxy(520,250,"propan");
        if(n==4)
            outtextxy(520,250,"butan");
        if(n==5)
            outtextxy(520,250,"pentan");
        if(n==6)
            outtextxy(520,250,"hexan");
        if(n==7)
            outtextxy(520,250,"heptan");
        if(n==8)
            outtextxy(520,250,"octan");
        if(n==9)
            outtextxy(520,250,"nonan");
        if(n==10)
            outtextxy(520,250,"decan");
     }
     if(flag==0)
     {
         if(n==1)
            outtextxy(520,250,"methane");
         if(n==2)
             outtextxy(520,250,"ethane");
         if(n==3)
             outtextxy(520,250,"propane");
         if(n==4)
            outtextxy(520,250,"butane");
         if(n==5)
             outtextxy(520,250,"pentane");
         if(n==6)
             outtextxy(520,250,"hexane");
         if(n==7)
             outtextxy(520,250,"heptane");
         if(n==8)
             outtextxy(520,250,"octane");
            if(n==9)
             outtextxy(520,250,"nonane");
         if(n==10)
             outtextxy(520,250,"decane");
     }
}
int CN::check(int n,int s,int s2[11],int s1[11])
{
    int sum1=0,sum2=0;int x=0;
    for(int i=0;i<n;i++)
    {
        if(s2[i]==s)
            {
                s1[x]=i;
                sum1=sum1+i;
                sum2=sum2+(n+1-i);
                x++;
            }
    }
}
void CN::name_comp(int s[11],int n)
{
     int x=0,k,s1[11],k1,s2[11],p,g=0;
     int flag=0;int count_s[5];int flag1=0;
     count_s[4]=0;
     count_s[1]=0;
     count_s[2]=0;
     count_s[3]=0;
     for(int i=0;i<n;i++)
     {
        if(s[i]!=0)
            flag=1;
     }
     if(flag==0)
        alkane(n,flag);
     for(int i=0;i<n;i++)
     {
             if(s[i]==1)
             {
                count_s[1]++;
             }
             if(s[i]==2)
             {
                count_s[2]++;
             }
             if(s[i]==3)
             {
                count_s[3]++;
             }
             if(s[i]==4)
             {
                count_s[4]++;
             }
     }
     if(flag==1)
     {
        if(count_s[1]!=0)
        {
            alkane(n,flag);
            k=check(n,1,s,s1);
            outtextxy(660,250,"-");
            int i=0;
            for(;i<count_s[1];i++)
            {
               char no[0];
                memset(no,0,2);
                sprintf(no,"%d",s1[i]+1);
                outtextxy(700+(35*i),250,no);
                if(i+1!=count_s[1])
                outtextxy(700+(35*i)+25,250,",");
                }
            setcolor(11);
            outtextxy(700+35*(i+1),250,"oic acid");
            flag1=1;
        }
        if(count_s[2]!=0)
        {
            if(flag1==0)
            {
                alkane(n,flag);
                k=check(n,2,s,s1);
                outtextxy(660,250,"-");
                int i=0;
                for(;i<count_s[2];i++)
                {
                    char no[0];
                    memset(no,0,2);
                    sprintf(no,"%d",s1[i]+1);
                    outtextxy(700+(35*i),250,no);
                    if(i+1!=count_s[2])
                        outtextxy(700+(35*i)+25,250,",");
                }
                setcolor(11);
                outtextxy(700+35*(i+1),250,"al");
                flag1=1;g=1;
            }
            else
            {
                help:
                check(n,2,s,s1);
                if(g==0)
                {
                    
                    check(n,2,s,s1);
                    check(n,3,s,s2);
                    int i=0;
                    if(count_s[4]==0)
                        p=250;
                    else
                        p=210;
                    int l=0,s3[11],s4[11];
                    int c=0,v=0;
                    if(count_s[3]!=0)
                    {
                        for(int j=0;j<count_s[2]+count_s[3];j++)
                        {
                            if(s1[c]<s2[v])
                            {
                                s4[j]=s1[c];
                                c++;
                            }
                            else
                            {
                                s4[j]=s2[v];
                                v++;
                            }
                        }
                        for(int i=0;i<count_s[2]+count_s[3];i++)
                        {
                            s3[i]=s4[count_s[2]+count_s[3]-1-i];
                        }
                    }
                    else
                    {
                        for(int i=0;i<count_s[2];i++)
                            s3[i]=s1[count_s[2]-1-i];
                    }
                    for(;i<count_s[2]+count_s[3];i++)
                    {
                        char no[0];
                        memset(no,0,2);
                        sprintf(no,"%d",s3[i]+1) ;  
                        outtextxy(400-(35*l),p,no);
                        if(i+1!=count_s[2]+count_s[3])
                            outtextxy(400-(35*l)-10,p,",");
                        l++;
                    }
                    setcolor(11);
                    outtextxy(440,p,"oxo");
                    goto skip;
                }
            
            if(g==1)
            {
                check(n,3,s,s1);
                int i=0,l=0;
                if(count_s[4]==0)
                    p=250;
                else
                    p=210;
                int rev[11];
                int q=count_s[3]-1;
                for(int h=0;h<=count_s[3];h++)
                {
                    rev[h]=s1[q];
                    q--;
                }
                for(;i<count_s[3];i++)
                {
                    char no[0];
                    memset(no,0,2);
                    sprintf(no,"%d",rev[i]+1);
                    outtextxy(400-(35*l),p,no);
                    if(i+1!=count_s[3])
                        outtextxy(400-(35*l)-10,p,",");
                    l++;
                }
                setcolor(11);
                outtextxy(440,p," oxo");
            }
                goto skip;
            }
        }
        if(count_s[3]!=0)
        {
            if(flag1==0)
            {
                alkane(n,flag);
                check(n,3,s,s1);
                outtextxy(660,250,"-");
                int i=0;
                for(;i<count_s[3];i++)
                {
                    char no[0];
                    memset(no,0,2);
                    sprintf(no,"%d",s1[i]+1);
                    outtextxy(700+(35*i),250,no);
                    if(i+1!=count_s[3])
                        outtextxy(700+(35*i)+25,250,",");
                }
                setcolor(11);
                outtextxy(700+35*(i+1),250,"one");
                 flag1=1;
            }
            else
            goto help;
        }skip:
        if(count_s[4]!=0)
        {
            if(flag1==0)
            {    
                alkane(n,flag);
                check(n,4,s,s1);
                outtextxy(660,250,"-");
                 int i=0;
                 for(;i<count_s[4];i++)
                 {
                     char no[0];
                     memset(no,0,2);
                     sprintf(no,"%d",s1[i]+1);
                     outtextxy(700+(35*i),250,no);
                     if(i+1!=count_s[4])
                         outtextxy(700+(35*i)+25,250,",");
                 }
                 setcolor(11);
                 outtextxy(700+35*(i+1),250,"ol");
            }
            else
            {
                k1=check(n,4,s,s1);
                int i=0,l=0;
                int s5[11];
                for(int i=0;i<count_s[4];i++)
                    s5[i]=s1[count_s[4]-1-i];
                for(;i<count_s[4];i++)
                {
                char no[0];
                memset(no,0,2);
                sprintf(no,"%d",s5[i]+1);
                outtextxy(320-(35*l),250,no);
                if(i+1!=count_s[4])
                outtextxy(320-(35*l)-10,250,",");
                l++;
                }
                setcolor(11);
                outtextxy(360,250,"Hydroxy");
            }
        }
     }
        settextstyle(4,0,2); 
        setcolor(RED);
        outtextxy(10,50,"Press x for main menu");
        setcolor(11);
        settextstyle(3,0,4); 
        int o=0;
        char ch;
        while(o==0)
        {
            if(kbhit())
            {
                ch=getch();
                if(ch=='x')
                    {
                        setcolor(2);
                         settextstyle(4,0,2); 
                        outtextxy(10,50,"Press x for main menu");
                        delay(200);
                         settextstyle(3,0,4); 
                        setcolor(11);
                        cleardevice();
                        break; 
                    }
            }
        }

}
void CN::mainON()
{
    int i1=0;int i2=0;
    int subst[11];
    reset(subst);
    int flag1=1;
    int i=0;char ch;
    int sel;
    int f1=0;
    int x=0;
    int y=48;
    int h=0;
    int xv=550;
    int x1=1;
    int f=0;
    int no_c_atoms;int flag_subst=0;
    char no[0];
    memset(no,0,2);
    sprintf(no,"%d",x);
    initwindow(1360,700);
    m1:
    settextstyle(3,0,4);
    mm();
    while(i==0)
    {
        if(kbhit())
        {
                   ch=getch();
                   if(ch=='q')
                   {
                        closegraph();
                        //main();
                        return;
                   }
                   if(ch=='i')
                   {
                    cleardevice();
                    info();
                   }
            break;
        }
    }
    cleardevice();
    ::count=1;
    m2:
    if(::count==1)
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
                            if(x==11)
                            {x=0;flag1=0;}
                            memset(no,0,2);
                            sprintf(no,"%d",x);
                            outtextxy(930,296,no);
                            delay(125);
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
                            {x=10;}
                            memset(no,0,2);
                            sprintf(no,"%d",x);
                            outtextxy(930,296,no);
                            delay(125);
                            setcolor(11);
                            outtextxy(851,300,"-");
                            flag1=0;
                        }
                        if(ch=='x')
                       {
                       cleardevice();x=0;
                       memset(no,0,2);sprintf(no,"%d",x);goto m1;
                       }
                       draw_c(flag1,x);
                       
                       if(ch=='g')
                      {
                                 if(x==0)
                                 {
                                         for(int i=0;i<10;i++)
                                         {
                                         setcolor(11);
                                         if(i%2==0)        
                                         setcolor(RED);
                                         delay(100);
                                         outtextxy(400,150,"NO OF C-ATOMS CANNOT BE ZERO!!!");
                                         }
                                         setcolor(BLACK);
                                         outtextxy(400,150,"NO OF C-ATOMS CANNOT BE ZERO!!!");
                                         setcolor(11);
                                 }
                                 else
                                 {
                                     reset(subst);
                                 no_c_atoms=x;cleardevice();x=0;m21:memset(no,0,2);sprintf(no,"%d",x);
                                 sets(::count,bp,tp,390,340);
                                 m21();
                                 draw_c(1,no_c_atoms);
                                 draw_subst(subst,no_c_atoms);
                                 x=0;
                                  while(i==0)
                                  {
                                             
                                             if(kbhit())
                                             {
                                                        ch=getch();
                                                        if(ch=='x')
                                                        {no_c_atoms=0;x=0;::count=1;cleardevice();reset(subst);goto m1;}
                                                        if(ch=='n')
                                                        {
                                                        goto name;
                                                        }
                                                       if(box(ch,4,390,340)==1)
                                                       {
                                                       flag_subst=1;sel=::count;::count=1;
                                                       }
                                             }
                                             if(flag_subst==1)  
                                             {
                                               flag_subst=0;
                                               i1=0;x=0;
                                               cleardevice();
                                                memset(no,0,2);
                                                sprintf(no,"%d",x);
                                                outtextxy(930,296,no);
                                                m211();
                                               while(i1==0)
                                               {
                                                   if(kbhit())
                                                   {
                                                    ch=getch();
                                                    if(ch=='w')
                                                     {
                                                     setcolor(GREEN);
                                                     outtextxy(854,300,"+");//951
                                                     setcolor(BLACK);
                                                     outtextxy(930,296,no);
                                                     setcolor(11);
                                                     x++;
                                                     flag1=1;
                                                     if(x>no_c_atoms)
                                                     {x=0;flag1=0;}
                                                     memset(no,0,2);
                                                     sprintf(no,"%d",x);
                                                     outtextxy(930,296,no);
                                                     delay(125);
                                                     setcolor(11);
                                                     outtextxy(854,300,"+");
                                                     }  
                                                     if(ch=='s')
                                                     {
                                                     setcolor(RED);
                                                     outtextxy(830,300,"-");
                                                     setcolor(BLACK);
                                                     outtextxy(930,296,no);
                                                     setcolor(11);
                                                     x--;
                                                     if(x==-1)
                                                     {x=no_c_atoms;}
                                                     memset(no,0,2);
                                                     sprintf(no,"%d",x);
                                                     outtextxy(930,296,no);
                                                     delay(125);
                                                     setcolor(11);
                                                     outtextxy(830,300,"-");
                                                     flag1=0;
                                                     }           
                                                     if(ch=='x')
                                                     {
                                                                cancel:
                                                     cleardevice();x=0;
                                                     memset(no,0,2);sprintf(no,"%d",x);goto m21;
                                                     }  
                                                     if(ch=='g')
                                                     {
                                                                if(x==0)
                                                                {outtextxy(400,150,"pos cant be zero");
                                                                delay(100);
                                                                setcolor(BLACK);
                                                                outtextxy(400,150,"pos cant be zero");
                                                                setcolor(11);
                                                                continue;
                                                                }
                                                                delay(500);
                                                                cleardevice();subst[x-1]=sel;
                                                                draw_subst(subst,no_c_atoms);x=0;
                                                                memset(no,0,2);sprintf(no,"%d",x);::count=1;bp=240;tp=190;goto m21;
                                                     }      
                                               }
                                               }
                                             } //if subst_flag
                                  }//inner while
                                  
                                 }//else inside select g
                      }//if ch==g
               }//if kbhit
         }//while
         name:
         cleardevice();
         draw_c(1,no_c_atoms);
         draw_subst(subst,no_c_atoms);
         name_comp(subst,no_c_atoms);
         goto m1;                        
    } //if count
    system("pause");
}
