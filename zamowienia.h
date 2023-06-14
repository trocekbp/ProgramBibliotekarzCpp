void WyswietlZleconeKs();
void rejsetrZlecen();
void WysZawKsiazki(int &nr, strksiazka ksiazka);
void WysNagKsiazki(int linia);
void ZapiszZleconeKs();
void DoTXT(char indeks, char tytul,char autor,char isbn,char ean,int ilosc);

void rejsetrZlecen()
{
int x,y, wybor;
do
{
  clrscr();
  y= wherey();
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"***      Rejestr zleceń     ***"<<endl;
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"Wybierz Opcję : ";
  y++;
  gotoxy(10,y++); cout<<"   1 -  Wyswietl zlecenia na zakup książek ";
  gotoxy(10,y++); cout<<"   2 -  Zapisz zlecenia do pliku ";
  y++;
  gotoxy(10,y++); cout<<"   0 -  Wróć do poprzedniego menu";
  gotoxy(8,y);int x,y, wybor;
  cin>>wybor;

      switch (wybor)
      {
       case 1: WyswietlZleconeKs();
            break;
       case 2: ZapiszZleconeKs();
            break;
      }
      break;
} while (wybor!=0);
}

void WyswietlZleconeKs()
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
          if(plik2.eof())break;
            if (ksiazka2.aktywny==1)
            {
                if (i==1)WysNagKsiazki(y);
                    if(ksiazka2.stan==0)
                    {
                        WysZawKsiazki(i, ksiazka2);
                        if (i%5==0)getch();
                    }
                i++;
            }
	   }
plik2.close();
getch();
}
void DoTXT(char* indeks, char* tytul,char* autor,char* isbn,char* ean,int ilosc)
{
fstream zapis;
zapis.open("ZleceniaKsiazek.txt",ios::out | ios::app);
zapis <<indeks<<", "<<tytul<<", "<<autor<<", ISBN: "<<isbn<<", EAN: "<<ean<<", ilosc do zamowienia: "<<ilosc<<endl;
zapis.close();
}
void ZapiszZleconeKs()
{
int x; //ile sztuk ksiazek
strksiazka ksiazka8;
ifstream plik("ksiazki.dat",ios::binary| ios::in);
while (1)
        {
        plik.read(reinterpret_cast<char*>(&ksiazka8),sizeof(ksiazka8));
        if(plik.eof()) break;
		   if (ksiazka8.aktywny==1)
		   {
		       if(ksiazka8.stan==0)
               {
                   cout<<"Ilosc egzemplarzy ksiazki '"<<ksiazka8.tytul<<"' do zamowienia - ";
                   cin>>x;
                   cout<<endl;
                   DoTXT(ksiazka8.indeks,ksiazka8.tytul,ksiazka8.autor,ksiazka8.isbn,ksiazka8.ean,x);
               }
          }
        }
plik.close();
textcolor(10);
cout<<"Raport zleceń został zapisany w pliku 'ZleceniaKsiazek.txt' "<<endl;
textcolor(7);
getch();
}



