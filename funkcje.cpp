#include <iostream>
#include "funkcje.h"
 
using namespace std;
 
void WprowadzDane(TablicaHasz *TabHasz,int m)
{
TablicaHasz *nowy = new TablicaHasz;
int klucz = 0;
int Lnazwa1=0;
int Lnazwa2=0;
 
                cin>>nowy->do_kogo;
                cin>>nowy->od_kogo;
                cin>>nowy->wartosc;
 
                DlNazwy(nowy->od_kogo,Lnazwa1);
                DlNazwy(nowy->do_kogo,Lnazwa2);
                nowy->dl_od = Lnazwa1;
                nowy->dl_do = Lnazwa2;
                klucz = FunkcjaHasz(nowy,Lnazwa1,Lnazwa2,m);
                WstawTH(TabHasz,klucz,nowy);
}
 
int FunkcjaHasz(TablicaHasz *element,int Lslowa1,int Lslowa2,int rozmiarTH)
{
int suma1=0;
int pomoc1=0;
int pomoc2=0;
int tab[16]={13,55,3,5,8,13,55,3,5,8,13,55,3,5,8};
 
        if(Lslowa1 > Lslowa2)
                Lslowa1 = Lslowa2;
 
        for(int i=0;i<Lslowa1;i++)
        {
                pomoc1 = element->od_kogo[i] - 97;
                pomoc2 = element->do_kogo[i] - 97;
                suma1+=pomoc1*tab[i]+pomoc2*tab[i];
        }
 
return (suma1%rozmiarTH);
}
void DlNazwy(char nazwa[],int &licznik)
{
        while(nazwa[licznik]!='\0')
                licznik++;
}
 
int Poteg(int liczba,int iteracja)
{
 for(int i=0;i<iteracja%2;i++)
         liczba*=liczba;
return liczba;
}
void WstawTH(TablicaHasz *TabHasz,int index,TablicaHasz *&element)
{
TablicaHasz *pomoc = NULL;
 
        if(TabHasz[index].next==NULL) TabHasz[index].next = element;
        else {                                                                                                          //Kolizja
                        pomoc = TabHasz[index].next;
                        TabHasz[index].next = element;
                        element->next = pomoc;
                }
}
 
void SzukajPrzelewu(TablicaHasz *TabHasz,int m)
{
TablicaHasz *nowy = new TablicaHasz;
int Lnazwa1=0;
int Lnazwa2=0;
int klucz=0;
 
                cin>>nowy->do_kogo;
                cin>>nowy->od_kogo;
                DlNazwy(nowy->od_kogo,Lnazwa1);
                DlNazwy(nowy->do_kogo,Lnazwa2);
                nowy->dl_od = Lnazwa1;
                nowy->dl_do = Lnazwa2;
                klucz = FunkcjaHasz(nowy,Lnazwa1,Lnazwa2,m);
                SzukajTH(TabHasz,klucz,nowy);
}
void SzukajTH(TablicaHasz *TabHasz,int index,TablicaHasz *element)
{
TablicaHasz *pomoc = NULL;
int wartosc = 0;
        if(TabHasz[index].next == NULL)
                cout<<"0\n";
        else {
                pomoc = TabHasz[index].next;
                if(SprawdzZgodNazw(pomoc,element)) {
                                                                                        wartosc += pomoc->wartosc;
                                                                                        if(pomoc->next!= NULL)
                                                                                                SzukRek(pomoc,element,wartosc);
                                                                                        }
                else if(pomoc->next !=NULL) SzukRek(pomoc,element,wartosc);
                cout<<wartosc<<"\n";
                }
}
bool SprawdzZgodNazw(TablicaHasz *Dane,TablicaHasz *element)
{
bool slowo1=1;
bool slowo2=1;
        if(Dane->dl_od == element->dl_od)
        {
                for(int i=0;i<Dane->dl_od;i++)
                        {
                                if(Dane->od_kogo[i] != element->od_kogo[i])
                                        slowo1 =0;
                        }
                if(slowo1 == 1 && Dane->dl_do == element->dl_do)
                {
                        for(int i=0;i<Dane->dl_do;i++)
                                {
                                        if(Dane->do_kogo[i] != element->do_kogo[i])
                                                slowo2 =0;
                                }
                }
        }else return false;
 
        if((slowo1 && slowo2) == true)
                return true;
        else return false;
}
void SzukRek(TablicaHasz *&Dane,TablicaHasz *element,int &wartosc)
{
        Dane = Dane->next;
        if(SprawdzZgodNazw(Dane,element)) {
                                                                          wartosc += Dane->wartosc;
                                                                          if(Dane->next!= NULL)
                                                                                  SzukRek(Dane,element,wartosc);
                                                                          }
        else if(Dane->next !=NULL) SzukRek(Dane,element,wartosc);
}
