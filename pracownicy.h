
void RejestrPrac();
void PoprawPrac();
void UsunPrac();
void Wyswietlpracownik();
void DodajPrac();
bool SprawdzPrac(char imie[15]);
void WysZawPrac(int &nr, strpracownik pracownik);
void WysNagPrac(int linia);
void BrakPrac(int i);

void RejestrPrac()
{
  int x,y, wybor;
do
{
clrscr();

  y= wherey();
  textcolor(7);
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"***    Rejestr Pracowników   ***"<<endl;
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"Wybierz Opcję : ";
  y++;
  gotoxy(10,y++); cout<<"   1 -  Dodaj ";
  gotoxy(10,y++); cout<<"   2 -  Popraw ";
  gotoxy(10,y++); cout<<"   3 -  Usun ";
  gotoxy(10,y++); cout<<"   9 -  Wyswietl wszystkich pracowników";
  y++;
  gotoxy(10,y++); cout<<"   0 -  Wroc do poprzedniego menu";
  gotoxy(8,y);
  cin>>wybor;
  switch (wybor)
  {
   case 1: DodajPrac();
        break;
   case 2: PoprawPrac();
        break;
   case 3: UsunPrac();
        break;
   case 9: Wyswietlpracownik();
        break;
   case 0: break;
  }
}
while (wybor!=0);
}
void DodajPrac()
{
     strpracownik pracownik;
   ofstream plik1("pracownicy.dat",ios::binary | ios::app | ios::out);
     cout<<" Imię :";
     cin>>pracownik.imie;
     cout<<" Nazwisko :";
     cin>>pracownik.nazwisko;
     cout<<" Identyfikator :";
     cin>>pracownik.identyfikator;
     cout<<" Nr.tel :";
     cin>>pracownik.numertel;
     pracownik.aktywny=1;  //warunek sprawdzany przy wypisywaniu
    plik1.write(reinterpret_cast<char*>(&pracownik),sizeof(pracownik));
	plik1.close();
}

void Wyswietlpracownik()
{
 int i=1;
 int x,y;
 int dl;
 strpracownik pracownik2;
     ifstream plik2("pracownicy.dat",ios::binary| ios::in);
 y= wherey();
 y++;
	while (1)
        {
                plik2.read(reinterpret_cast<char*>(&pracownik2),sizeof(pracownik2));
                if(plik2.eof()) break;
		   if (pracownik2.aktywny==1)
		   {
             if (i==1)WysNagPrac(y);
             WysZawPrac(i, pracownik2);
             if (i%5==0)getch();
          }
        }
	plik2.close();
   getch();
}

void PoprawPrac()
{
 int i=1;
 int x,y;
 int dl;
 char identyfikator[5];
 strpracownik pracownik3;
 char popraw;
     fstream plik3("pracownicy.dat",ios::binary| ios::in| ios::out);
 y= wherey();
 y++;
     cout<<"Podaj identyfikator pracownika : ";
     cin>>identyfikator;
	while (1)
        {
           plik3.read(reinterpret_cast<char*>(&pracownik3),sizeof(pracownik3));
           if(plik3.eof()){BrakPrac(i); break;}

                   if (strcmp(pracownik3.identyfikator,identyfikator)==0)
                     {
                      if (i==1)WysNagPrac(y);
                      dl= plik3.tellg();

                         WysZawPrac(i, pracownik3);

                          plik3.seekp(dl-72);

                               cout<<"Czy poprawiamy imię ? t/n ";
                               do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                  { cout<<"imie : "; cin>>pracownik3.imie;}

                               cout<<"Czy poprawiamy nazwisko ? t/n ";
                               do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                   { cout<<"Nazwisko : "; cin>>pracownik3.nazwisko;}

                               cout<<"Czy porawiamy numer telefonu ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                  {cout<<"Numer telefonu : "; cin>>pracownik3.numertel;}
                               pracownik3.aktywny=1;

    plik3.write(reinterpret_cast<char*>(&pracownik3),sizeof(pracownik3));
                      i++;
                     }
	}
	plik3.close();
}

void UsunPrac()
{
 int i=1;
 int x,y;
 int dl;
 char identyfikator[5];
 strpracownik pracownik3;
 char popraw;
     fstream plik3("pracownicy.dat",ios::binary| ios::in| ios::out);
     cout<<"Podaj numer karty pracownika : ";
     cin>>identyfikator;
 y= wherey();
 y++;
	while (1)
        {
           plik3.read(reinterpret_cast<char*>(&pracownik3),sizeof(pracownik3));
           if(plik3.eof()){BrakPrac(i); break;}

                   if ((strcmp(pracownik3.identyfikator,identyfikator)==0) && (pracownik3.aktywny==1))
                     {
                         if (i==1)WysNagPrac(y);
                          dl= plik3.tellg();
                          WysZawPrac(i, pracownik3);
                          plik3.seekp(dl-72);
                       cout<<"Czy usunac pracownika ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)//T
                                 { pracownik3.aktywny=0; cout<<"pracownikelnik "<<pracownik3.identyfikator<<" usuniety "; }

    plik3.write(reinterpret_cast<char*>(&pracownik3),sizeof(pracownik3));

                      getch();
                     }
	}
	plik3.close();
}

void WysZawPrac(int &nr, strpracownik pracownik)
{
     int y;
            y= wherey();
            textcolor(9);
           cout<<nr<<")  "<<pracownik.identyfikator;
           gotoxy (10,y);
           cout<<pracownik.imie;
           gotoxy (25,y);
           cout<<pracownik.nazwisko;
           gotoxy (45,y);
           cout<<pracownik.numertel;
           cout<<endl;
              nr++;
}

void WysNagPrac(int linia)
{
    textcolor(2);
        gotoxy (1,linia);
        cout<<"Lp. Id";
        gotoxy (10,linia);
        cout<<"Imie";
        gotoxy (25,linia);
        cout<<"Nazwisko";
        gotoxy (45,linia);
        cout<<"Numer telefonu";
        cout<<endl;
}
void BrakPrac(int i)
{
if (i==1)
 {
     textcolor(4);
   cout<<"Nie ma pracownika o takim id !";
   getch();
 }
};

