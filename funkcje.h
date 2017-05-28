struct TablicaHasz
{
char od_kogo[16];
char do_kogo[16];
int wartosc;
int dl_od;
int dl_do;
TablicaHasz *next;
TablicaHasz(){od_kogo[0]='\0'; do_kogo[0]='\0'; wartosc = 0; next=NULL;dl_od=0;dl_do=0;}
};
void program();
int FunkcjaHasz(TablicaHasz *element,int Lslowa1,int Lslowa2,int wielkoscTH);
void WprowadzDane(TablicaHasz *TabHasz,int m);
void DlNazwy(char nazwa[],int &licznik);
int Poteg(int liczba,int iteracja);
void WstawTH(TablicaHasz *TabHasz,int index,TablicaHasz *&element);
void SzukajPrzelewu(TablicaHasz *TabHasz,int m);
void SzukajTH(TablicaHasz *TabHasz,int index,TablicaHasz *element);
bool SprawdzZgodNazw(TablicaHasz *Dane,TablicaHasz *element);
void SzukRek(TablicaHasz *&Dane,TablicaHasz *element,int &wartosc);
