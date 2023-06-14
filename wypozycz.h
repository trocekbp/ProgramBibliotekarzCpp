
void wypozyczKsiazke();


void wypozyczKsiazke()
{
clrscr();
bool test;//sprawdzenie czy ksiazke mozna wypozyczyc
int x,y;
y= wherey();
gotoxy(10,y++); cout<<"********************************"<<endl;
gotoxy(10,y++); cout<<"***   Wypożyczenie książki   ***"<<endl;
gotoxy(10,y++); cout<<"********************************"<<endl;
strwypozycz wyp;
ofstream plik1("wypozyczenia.dat",ios::binary | ios::app | ios::out);
cout<<" Podaj identyfikator pracownika :";
cin>>wyp.identyfikator;
cout<<" Podaj indeks ksiazki :";
cin>>wyp.indeks;
cout<<" Numer karty czytelnika :";
cin>>wyp.nrkarty;
cout<<" Data zwrotu(rrrr-mm-dd) :";
cin>>wyp.datazwrotu;
wyp.ilosc = 1;   //domyslnie wypozycza siê tylko jedn¹ ksi¹¿kê
wyp.aktywny = 1;
TestKsiazki(wyp.indeks,&test);
if(test==true)
{
    stanKs(wyp.indeks,-wyp.ilosc);
    plik1.write(reinterpret_cast<char*>(&wyp),sizeof(wyp));
}
    else if(test==false)
    {
        cout<<"Brak książki na stanie"<<endl;
        getch();
    }
plik1.close();
}
