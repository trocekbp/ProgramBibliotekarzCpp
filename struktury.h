struct strksiazka
{
     char* id;
     char tytul[30];
     char autor[20];
     char isbn[22];
     char ean[13];
     char rok_wydania[5];
     char indeks[5];
     int stan;
     unsigned int aktywny : 1;
};
typedef struct strpracownik
{
     char* id;
     char imie[15];
     char nazwisko[30];
     char numertel[10];
     char identyfikator[5];
     unsigned int aktywny : 1;
};
struct strwypozycz
{
     char* id;
     char indeks[5];
     char nrkarty[5];
     char identyfikator[5];
     int ilosc;
     char datazwrotu[10];
     unsigned int aktywny;
};
 typedef struct strczytelnik
{
     char* id;
     char imie[15];
     char nazwisko[30];
     char nrkarty[5];
     char numertel[10];
     char pesel[12];
     unsigned int aktywny : 1;
};

