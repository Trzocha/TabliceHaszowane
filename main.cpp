#include <iostream>
#include "funkcje.h"
 
using namespace std;
 
int main()
{
        program();
        return 0;
}
 
void program()
{
char znak;
int m = 701;
TablicaHasz *TH = new TablicaHasz[m];
 
        while(cin>>znak)
        {
                switch(znak)
                {
                case '+':
                        WprowadzDane(TH,m);
                        break;
                case '?':
                        SzukajPrzelewu(TH,m);
                        break;
                }
        }
delete TH;
}
