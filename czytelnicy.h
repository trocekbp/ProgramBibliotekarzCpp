
void RejestrCzyt();
void PoprawCzyt();
void UsunCzyt();
void WyswietlCzyt();
void DodajCzyt();
bool SprawdzCzyt(char imie[15]);
void WysZawCzyt(int &nr, strczytelnik czyt);
void WysNagCzyt(int linia);
void BrakCzyt(int i);

void RejestrCzyt()
{
int x,y, wybor;
do
{
clrscr();
textcolor(7);
  y= wherey();
  textcolor(7);
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"***    Rejestr Czytelników   ***"<<endl;
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"Wybierz Opcję : ";
  y++;
  gotoxy(10,y++); cout<<"   1 -  Dodaj ";
  gotoxy(10,y++); cout<<"   2 -  Popraw ";
  gotoxy(10,y++); cout<<"   3 -  Usuń ";
  gotoxy(10,y++); cout<<"   9 -  Wyświetl wszystkich czytelników";
  y++;
  gotoxy(10,y++); cout<<"   0 -  Wróć do poprzedniego menu";
  gotoxy(8,y);
  cin>>wybor;
  switch (wybor)
  {
   case 1: DodajCzyt();
        break;
   case 2: PoprawCzyt();
        break;
   case 3: UsunCzyt();
        break;
   case 9: WyswietlCzyt();
        break;
   case 0: break;
  }
}
while (wybor!=0);
}
void DodajCzyt()
{
     strczytelnik czyt;
     ofstream plik1("czytelnicy.dat",ios::binary | ios::app | ios::out);
     cout<<" Imię :";
     cin>>czyt.imie;
     cout<<" Nazwisko :";
     cin>>czyt.nazwisko;
     cout<<" Numer karty :";
     cin>>czyt.nrkarty;
     cout<<" Nr.tel :";
     cin>>czyt.numertel;
     cout<<" Pesel :";
     cin>>czyt.pesel;
     czyt.aktywny=1;
     plik1.write(reinterpret_cast<char*>(&czyt),sizeof(czyt));
	 plik1.close();
}

void WyswietlCzyt()
{
int i=1;
int x,y;
int dl;
strczytelnik czyt2;
ifstream plik2("czytelnicy.dat",ios::binary| ios::in);
y= wherey();
y++;
	while (1)
        {
            plik2.read(reinterpret_cast<char*>(&czyt2),sizeof(czyt2));
            if(plik2.eof()) break;
                if (czyt2.aktywny==1)
                {
                     if (i==1)WysNagCzyt(y);
                     WysZawCzyt(i, czyt2);
                     if (i%5==0)getch();
                }
              i++;
        }
plik2.close();
getch();
}

void PoprawCzyt()
{
 int i=1;
 int x,y;
 int dl;
 char nrkarty[5];
 strczytelnik czyt3;
 char popraw;
 fstream plik3("czytelnicy.dat",ios::binary| ios::in| ios::out);
 y= wherey();
 y++;
 cout<<"Podaj numer karty czytelnika : ";
 cin>>nrkarty;
	while (1)
        {
           plik3.read(reinterpret_cast<char*>(&czyt3),sizeof(czyt3));
           if(plik3.eof()){BrakCzyt(i); break;}
                   if (strcmp(czyt3.nrkarty,nrkarty)==0)
                     {
                      if (i==1)WysNagCzyt(y);
                      dl= plik3.tellg();

                         WysZawCzyt(i, czyt3);

                          plik3.seekp(dl-88);

                               cout<<"Czy poprawiamy imiê ? t/n ";
                               do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                  { cout<<"imie : "; cin>>czyt3.imie;}

                               cout<<"Czy poprawiamy nazwisko ? t/n ";
                               do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                   { cout<<"Nazwisko : "; cin>>czyt3.nazwisko;}
                               cout<<"Czy porawiamy numer telefonu ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                  {cout<<"Numer telefonu : "; cin>>czyt3.numertel;}

                               cout<<"Czy poprawiamy pesel ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                   { cout<<"Pesel : "; cin>>czyt3.pesel;}
                                    cout<<"Czy wystawiamy now¹ kartê ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                   { cout<<"Nowy numer karty : "; cin>>czyt3.nrkarty;}

                               czyt3.aktywny=1;

    plik3.write(reinterpret_cast<char*>(&czyt3),sizeof(czyt3));
                      i++;
                     }
	}
plik3.close();
}

void UsunCzyt()
{
 int i=1;
 int x,y;
 int dl;
 char nrkarty[5];
 strczytelnik czyt3;
 char popraw;
 fstream plik3("czytelnicy.dat",ios::binary| ios::in| ios::out);
 cout<<"Podaj numer karty czytelnika : ";
 cin>>nrkarty;
 y= wherey();
 y++;
	while (1)
        {
           plik3.read(reinterpret_cast<char*>(&czyt3),sizeof(czyt3));
           if(plik3.eof()){BrakCzyt(i); break;}

                   if ((strcmp(czyt3.nrkarty,nrkarty)==0) && (czyt3.aktywny==1))
                     {
                         if (i==1)WysNagCzyt(y);
                          dl= plik3.tellg();
                          WysZawCzyt(i, czyt3);
                          plik3.seekp(dl-88);
                       cout<<"Czy usunac czytelnika ? t/n ";
                                do
                                 {
                                   popraw=getch();
                                   cout<<endl;
                                 }
                               while ((popraw!=116)&&(popraw!=110));
                                if (popraw==116)
                                 {
                                     czyt3.aktywny=0; cout<<"Czytelnik "<<czyt3.nrkarty<<" usuniety ";
                                 }

    plik3.write(reinterpret_cast<char*>(&czyt3),sizeof(czyt3));
    getch();
                     }
	}
	plik3.close();
}

void WysZawCzyt(int &nr, strczytelnik czyt)
{
           int y;
           y = wherey();
           textcolor(9);
           cout<<nr<<")  "<<czyt.imie;
           gotoxy (15,y);
           cout<<czyt.nazwisko;
           gotoxy (30,y);
           cout<<czyt.nrkarty;
           gotoxy (45,y);
           cout<<czyt.numertel;
           gotoxy (65,y);
           cout<<czyt.pesel<<endl;
           textcolor(7);
              nr++;
}

void WysNagCzyt(int linia)
{
        textcolor(2);
        gotoxy (1,linia);
        cout<<"Lp. Imie";
        gotoxy (15,linia);
        cout<<"Nazwisko";
        gotoxy (30,linia);
        cout<<"Nr karty";
        gotoxy (45,linia);
        cout<<"Numer telefonu";
        gotoxy (65,linia);
        cout<<"Pesel"<<endl;
        textcolor(7);
}
void BrakCzyt(int i)
{
if (i==1)
 {
   cout<<"Nie ma czytelnika o takiej nazwie !";
   getch();
 }
};
