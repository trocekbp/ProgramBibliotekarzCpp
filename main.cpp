#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <string>
#include "ddtconsole.h" //funkcje do zarz¹dznia widokiem konsoli
using namespace std;
using namespace ddt::console;
#include "struktury.h"
#include "ksiazki.h"
#include "czytelnicy.h"
#include "pracownicy.h"
#include "wypozycz.h"
#include "zwrot.h"
#include "zamowienia.h"
void RejestrKsiazek();
void RejestrCzyt();
void RejestrPrac();
void wypozyczKsiazke();
void zwrocKsiazke();
void rejsetrZlecen();
int wypisz(int *w);

int main()
{
    system("chcp 65001>>NULL");
    int wybor;
    do
    {
        wypisz(&wybor);
        switch (wybor)
        {
               case 1:RejestrKsiazek();
                    break;
            case 2:RejestrCzyt();
            break;
              case 3:RejestrPrac();
                    break;
              case 4:wypozyczKsiazke();
                    break;
              case 5:zwrocKsiazke();
                    break;
              case 6:rejsetrZlecen();
                    break;
             default: break;
        }
}while(wybor!=0);
return EXIT_SUCCESS; //wyjscie z programu
}

int wypisz(int *w)
{
   clrscr();
   	textcolor(7);
 cout<<endl<<endl<<endl<<endl<<endl;
 cout<<"     ******************************************************** "<<endl;
 cout<<"     Bibliotekarz - program do zarządzania biblioteką v 1.0   "<<endl;
 cout<<"     ******************************************************** "<<endl<<endl;
 cout<<"     *******************************"<<endl;
 cout<<"      1 - Rejestr książek "<<endl;
 cout<<"      2 - Czytelnicy "<<endl;
 cout<<"      3 - Pracownicy "<<endl;
 cout<<"     *******************************"<<endl;
 cout<<"      4 - Wypożycz książkę"<<endl;
 cout<<"      5 - Zwróć książkę "<<endl;
 cout<<"     *******************************"<<endl;
 cout<<"      6 - Zlecenia na zakup książek "<<endl;
 cout<<"     *******************************"<<endl;
 cout<<"      0 - Zamknij Program "<<endl;
 cin>>*w;
}

