void RejestrKsiazek();
void PoprawKsiazke();
void UsunKsiazke();
void WyswietlKsiazke();
void DodajKsiazke();
void WysZawKsiazki(int &nr, strksiazka ksiazka);
void WysNagKsiazki(int linia);
void WysNagKsiazkiWyp(int linia);
void WysZawKsiazkiWyp(int &nr,strpracownik prac ,strksiazka ksiazka,strczytelnik czyt,strwypozycz wyp);
void BrakKsiazki(int i);
void wyswietlWyp();
void stanKs(strksiazka &ks,int ilosc);
strpracownik pobierzpracownika(char ident[5]);
strczytelnik pobierzczytelnika(char ident[5]);
strksiazka pobierzksiazke(char ident[5]);

void stanKs(char indeks[5],int ilosc) //funkcja zmieniająca stan książki
{
 int i=1;
 int x,y;
 int dl;
 strksiazka ksiazka3;
    fstream plik3("ksiazki.dat",ios::binary| ios::in| ios::out);
    while (1)
        {
            plik3.read(reinterpret_cast<char*>(&ksiazka3),sizeof(ksiazka3));
               if(plik3.eof()){break;}
                    if (strcmp(ksiazka3.indeks,indeks)==0)
                    {
                        dl= plik3.tellg();
                        plik3.seekp(dl-112);
                        ksiazka3.stan = ksiazka3.stan+ilosc;
                        ksiazka3.aktywny=1;
                        plik3.write(reinterpret_cast<char*>(&ksiazka3),sizeof(ksiazka3));
                    }
	     }
plik3.close();
}

strpracownik pobierzpracownika(char ident[5])
{
strpracownik prac;
fstream plik5("pracownicy.dat",ios::binary| ios::in| ios::out);
    while (1)
    {
      plik5.read(reinterpret_cast<char*>(&prac),sizeof(prac));
      if (plik5.eof()) {break;};
          if (strcmp(prac.identyfikator,ident)==0)
            {
                return prac;
                break;
            }
    }
plik5.close();
return prac;
}
strczytelnik pobierzczytelnika(char ident[5])
{
strczytelnik czyt;
fstream plik5("czytelnicy.dat",ios::binary| ios::in| ios::out);
	while (1)
    {
        plik5.read(reinterpret_cast<char*>(&czyt),sizeof(czyt));
        if (plik5.eof()) break;
            if (strcmp(czyt.nrkarty,ident)==0)
            {
                return czyt;
                break;
            }
    }
plik5.close();
return czyt;
}
strksiazka pobierzksiazke(char ident[5])
{
strksiazka ksiazka;
fstream plik5("ksiazki.dat",ios::binary| ios::in| ios::out);
    while (1)
    {
        plik5.read(reinterpret_cast<char*>(&ksiazka),sizeof(ksiazka));
        if (plik5.eof()) break;
            if (strcmp(ksiazka.indeks,ident)==0)
            {
                return ksiazka;
                break;
            }
    }
        plik5.close();
        return ksiazka;
}
void RejestrKsiazek()
{
int x,y, wybor;
do
{
  clrscr();
  textcolor(7);
  y= wherey();
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"***      Rejestr Książek     ***"<<endl;
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"Wybierz Opcję : ";
  y++;
  gotoxy(10,y++); cout<<"   1 -  Dodaj ";
  gotoxy(10,y++); cout<<"   2 -  Popraw ";
  gotoxy(10,y++); cout<<"   3 -  Usun ";
  gotoxy(10,y++); cout<<"   8 -  Wyswietl wypożyczone książki";
  gotoxy(10,y++); cout<<"   9 -  Wyswietl wszystkich";
  y++;
  gotoxy(10,y++); cout<<"   0 -  Wroc do poprzedniego menu";
  gotoxy(8,y);
  cin>>wybor;
  switch (wybor)
  {
   case 1: DodajKsiazke();
        break;
   case 2: PoprawKsiazke();
        break;
   case 3: UsunKsiazke();
        break;
   case 8: wyswietlWyp();
        break;
   case 9: WyswietlKsiazke();
        break;
   case 0: break;
  }
}
while (wybor!=0);
}

void wyswietlWyp()
{
 int i=1;
 int x,y;
 int dl;
 strksiazka ks;
 strpracownik prac;
 strczytelnik czyt;
 strwypozycz wyp;
 ifstream plik2("wypozyczenia.dat",ios::binary| ios::in);
if( plik2.good() == true )
{
 y= wherey();
 y++;
	while (1)
        {
            plik2.read(reinterpret_cast<char*>(&wyp),sizeof(wyp));
            if(plik2.eof()) break;
            //tu jestesmy, gdy czytanie powiod³o siê, wiêc to co przeczytalismy wypisujemy.
            if (i==1)WysNagKsiazkiWyp(y);
            prac = pobierzpracownika(wyp.identyfikator);
            ks = pobierzksiazke(wyp.indeks);
            czyt = pobierzczytelnika(wyp.nrkarty);
            WysZawKsiazkiWyp(i, prac,ks, czyt, wyp);
            if (i%5==0)getch();
        }
plik2.close();
getch();
}
else
cout<<"Brak wypożyczeń";
getch();
}
void WysZawKsiazkiWyp(int &nr,strpracownik prac,strksiazka ksiazka,strczytelnik czyt,strwypozycz wyp)
{
        int y;
        y= wherey();
        textcolor(9);
        cout<<nr<<") "<<ksiazka.indeks;
        gotoxy (13,y);
        cout<<ksiazka.tytul;
        gotoxy (33,y);
        cout<<prac.imie;
        gotoxy (34,y);
        cout<<".";
        gotoxy (36,y);
        cout<<prac.nazwisko;
        gotoxy (48,y);
        cout<<czyt.imie;
        gotoxy (49,y);
        cout<<".";
        gotoxy (50,y);   //pierwsza litera imienia(jeden odstep)
        cout<<czyt.nazwisko;
        gotoxy (61,y);
        if(wyp.aktywny==0)
        {
            textcolor(14);
            cout<<"zwrocono";
            textcolor(9);
        }
           else
              cout<<wyp.datazwrotu;
           gotoxy (75,y);
           if(ksiazka.stan<=0)
           {
               textcolor(4);
           }
           cout<<ksiazka.stan<<endl;
           textcolor(7);
           nr++;
}

void WysNagKsiazkiWyp(int linia)
{
        textcolor(2);
        gotoxy (1,linia);
        cout<<"Lp. ksiazka i";
        gotoxy (13,linia);
        cout<<"Tytul";
        gotoxy (33,linia);
        cout<<"Pracownik";
        gotoxy (48,linia);
        cout<<"Czytelnik";
        gotoxy (61,linia);
        cout<<"Data zwrotu";
        gotoxy (75,linia);
        cout<<"Stan"<<endl;
        textcolor(7);

}

void DodajKsiazke()
{
     strksiazka ksiazka;
     ofstream plik1("ksiazki.dat",ios::binary | ios::app | ios::out);
     cout<<" Tytul :";
     cin>>ksiazka.tytul;
     cout<<" Autor :";
     cin>>ksiazka.autor;
     cout<<" Rok wydania :";
     cin>>ksiazka.rok_wydania;
     cout<<" Kod ISBN :";
     cin>>ksiazka.isbn;
     cout<<" Numer EAN :";
     cin>>ksiazka.ean;
     cout<<" Indeks :";
     cin>>ksiazka.indeks;
     cout<<" Ilość książek :";
     cin>>ksiazka.stan;
     ksiazka.aktywny=1;
     plik1.write(reinterpret_cast<char*>(&ksiazka),sizeof(ksiazka));
	 plik1.close();
}

void WyswietlKsiazke()
{
 int i=1;
 int x,y;
 int dl;
 strksiazka ksiazka2;
 ifstream plik2("ksiazki.dat",ios::binary| ios::in);
 y= wherey();
 y++;
	while (1)
    {
        plik2.read(reinterpret_cast<char*>(&ksiazka2),sizeof(ksiazka2));
        if(plik2.eof()) break;
		   if (ksiazka2.aktywny==1)
		   {
             if (i==1)WysNagKsiazki(y);
             WysZawKsiazki(i, ksiazka2);
             if (i%5==0)getch();
           }
	}
plik2.close();
getch();
}
void PoprawKsiazke()
{
 int i=1;
 int x,y;
 int dl;
 char indeks[5];
 strksiazka ksiazka3;
 char popraw;
 fstream plik3("ksiazki.dat",ios::binary| ios::in| ios::out);
 y= wherey();
 y++;
     cout<<"Podaj indeks ksiazki : ";
     cin>>indeks;
	 while (1)
        {
           plik3.read(reinterpret_cast<char*>(&ksiazka3),sizeof(ksiazka3));
           if(plik3.eof()){BrakKsiazki(i); break;}

                   if (strcmp(ksiazka3.indeks,indeks)==0)
                     {
                      if (i==1)WysNagKsiazki(y);
                      dl= plik3.tellg();

                         WysZawKsiazki(i, ksiazka3);

                          plik3.seekp(dl-112);

                               cout<<"Czy poprawiamy tytuł ? t/n ";
                               do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                  { cout<<"Tytul : "; cin>>ksiazka3.tytul;}

                               cout<<"Czy poprawiamy autora ? t/n ";
                               do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                   { cout<<"Autor : "; cin>>ksiazka3.autor;}

                               cout<<"Czy porawiamy rok wydania ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                  {cout<<"Rok wydania : "; cin>>ksiazka3.rok_wydania;}

                               cout<<"Czy poprawiamy kod ISBN ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                   { cout<<"Kod ISBN : "; cin>>ksiazka3.isbn;}

                               cout<<"Czy poprawiamy kod EAN ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                   { cout<<"Kod EAN : "; cin>>ksiazka3.ean;}

                               cout<<"Czy poprawiamy stan początkowy ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                   {cout<<"Stan początkowy : "; cin>>ksiazka3.stan;}

                               ksiazka3.aktywny=1;

                      plik3.write(reinterpret_cast<char*>(&ksiazka3),sizeof(ksiazka3));
                      i++;
                     }
	}
plik3.close();
}

void UsunKsiazke()
{
 int i=1;
 int x,y;
 int dl;
 char indeks[5];
 strksiazka ksiazka3;
 char popraw;
fstream plik3("ksiazki.dat",ios::binary| ios::in| ios::out);
cout<<"Podaj indeks ksiazki : ";
cin>>indeks;
 y= wherey();
 y++;
	while (1)
        {
           plik3.read(reinterpret_cast<char*>(&ksiazka3),sizeof(ksiazka3));
           if(plik3.eof()){BrakKsiazki(i); break;}
                   if ((strcmp(ksiazka3.indeks,indeks)==0) && (ksiazka3.aktywny==1))
                     {
                         if (i==1)WysNagKsiazki(y);
                          dl= plik3.tellg();

                          WysZawKsiazki(i, ksiazka3);

                          plik3.seekp(dl-112);

                       cout<<"Czy usunac ksiazke ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                 { ksiazka3.aktywny=0; cout<<"Ksiazka "<<ksiazka3.indeks <<", "<<ksiazka3.indeks<<" usunieta "; }

plik3.write(reinterpret_cast<char*>(&ksiazka3),sizeof(ksiazka3));
getch();
                     }
	}
	plik3.close();
}

void WysZawKsiazki(int &nr, strksiazka ksiazka)
{
           int y;
           textcolor(9);
            y= wherey();
           cout<<nr<<")  "<<ksiazka.indeks;
           gotoxy (13,y);
           cout<<ksiazka.tytul;
           gotoxy (31,y);
           cout<<ksiazka.autor;
           gotoxy (51,y);
           cout<<ksiazka.rok_wydania;
           gotoxy (64,y);
           cout<<ksiazka.isbn;
           gotoxy (71,y);
           cout<<ksiazka.ean;
           gotoxy (77,y);
           if(ksiazka.stan<=0)
           {
               textcolor(4);
           }
           cout<<ksiazka.stan<<endl;
            textcolor(7);
              nr++;
}

void WysNagKsiazki(int linia)
{
    textcolor(2);
        gotoxy (1,linia);
        cout<<"Lp. indeks";
        gotoxy (13,linia);
        cout<<"Tytul";
        gotoxy (31,linia);
        cout<<"Autor";
        gotoxy (51,linia);
        cout<<"Rok wydania";
        gotoxy (64,linia);
        cout<<"ISBN";
        gotoxy (71,linia);
        cout<<"EAN";
        gotoxy (77,linia);
        cout<<"Stan"<<endl;
         textcolor(7);

}

void BrakKsiazki(int i)
{
if (i==1)
 {
   cout<<"Nie ma ksiazki o takim tytule !";
   getch();
 }
};
bool TestKsiazki(char indeks[5],bool* t)
{
    strksiazka ksiazka9;
    fstream plik("ksiazki.dat",ios::binary| ios::in| ios::out);
	do
    {
        plik.read(reinterpret_cast<char*>(&ksiazka9),sizeof(ksiazka9));
        if (strcmp(ksiazka9.indeks,indeks)==0)
        {
            if(ksiazka9.stan<=0)
                *t=false;
            else
                *t=true;
        }
    }while(plik.eof());
plik.close();
return *t;
}



