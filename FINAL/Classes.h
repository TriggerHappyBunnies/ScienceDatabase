#ifndef Classes
#define Classes
#include<fstream>
using namespace std;

class LG
{
    struct hist
    {
        int sm,sc;
    };
    ifstream ifile;
    ofstream ofile;
    hist obj;
    float m,c;
    float x,y; 
    int rec,slno,flag;
    char ptr[5],ch;
    public:
    LG()
    {
        x=0;
        ch=' ';
    }
    void text();
    void mainGC();
    void history();
};
class LS
{
      int v,oposx,f,u,R,h;
      int x,y;
      double p1,p,isize;
      char ch,ptr[5];
      public :
      LS()
      {
          oposx=0;
          f=10;
          ch='a';
      }
      int getf();
      void DrawMir();
      void Rays();
      void mainLS();
};
class CN
{
      int bp,tp;
      int count;
      public :
      CN()
      {
          bp=240;
          tp=190;
          count=1;
      }
      void sets(int ch,int bp,int tp,int pos_b,int pos_t);
      void mm();
      void info();
      void m2();
      void m21();
      void m211();
      void benzene();
      void setu(int ch,int bp,int tp,int last_op,int pos_b,int pos_t);
      int box(char ch,int last_op,int pos_b,int pos_t);
      void draw_c(int flag1,int x);
      void draw_subst(int subst[11],int x);
      void reset(int subst[11]);
      void alkane(int n,int flag);
      int check(int n,int s,int s2[11],int s1[11]);
      void name_comp(int s[11],int n);
      void mainON();
};

#endif
