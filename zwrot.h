void wzwrocKsiazke();

void zwrocKsiazke()
{
  clrscr();
  int x,y;
  y= wherey();
  gotoxy(10,y++); cout<<"********************************"<<endl;
  gotoxy(10,y++); cout<<"***     Zwrot  ksisiążki     ***"<<endl;
  gotoxy(10,y++); cout<<"********************************"<<endl;
  strwypozycz wyp;
  ofstream plik1("wypozyczenia.dat",ios::binary | ios::app | ios::out);
  cout<<" Podaj indeks ksiazki :";
  cin>>wyp.indeks;
  cout<<" Numer karty czytelnika :";
  cin>>wyp.nrkarty;
  wyp.ilosc = 1;   //domyslnie wypozycza siê tylko jedn¹ ksi¹¿kê
  wyp.aktywny = 0;
  stanKs(wyp.indeks,wyp.ilosc);
  plik1.write(reinterpret_cast<char*>(&wyp),sizeof(wyp));
  plik1.close();
}

