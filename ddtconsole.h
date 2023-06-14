#ifndef CONSOLE_H
#define CONSOLE_H
/******************************************************************************/
/*         Biblioteka stworzona na potrzeby kursu programowania C++           */
/******************************************************************************/
/*         Autor: Piotr Szawdyński            Ÿród³o: http://ddt.pl           */
/*         Wersja: 1.1        Ostatnia aktualizacja: 7 czerwca 2009           */
/*         Przeznaczone œrodowisko: Dev-C++                                   */
/*         Obs³ugiwane systemy operacyjne: Windows                            */
/*         Plik zawieraj¹cy dokumentacjê biblioteki: ddt-console.pdf          */
/******************************************************************************/
/*   Biblioteka nie mo¿e byæ rozpowszechniana bez kompletnej dokumentacji.    */
/*   Za bibliotekê nie mog¹ byæ pobierane jakiekolwiek op³aty.                */
/*   Niniejsza biblioteka jest darmowa.                                       */
/*   Bibliotekê mo¿e pobraæ ka¿dy ze strony http://ddt.pl                     */
/*   Bibliotekê mo¿na u¿ywaæ do celów edukacyjnych jak i komercyjnych.        */
/*   Plik nie mo¿e byæ rozpowszechniany, jeœli zostanie cokolwiek w nim       */
/*   zmienione. Dotyczy to równie¿ komentarzy!                                */
/******************************************************************************/
/*   Biblioteka nie powinna sprawiaæ ¿adnych problemów, pod warunkiem i¿      */
/*   nie bêd¹ wprowadzane do niej jakiekolwiek zmiany.                        */
/******************************************************************************/
/*   Autor nie ponosi odpowiedzialnoœci za b³êdne funkcjonowanie biblioteki.  */
/*   Niniejsz¹ bibliotekê uruchamiasz na w³asne ryzyko.                       */
/******************************************************************************/
/*   Change Log:                                                              */
/*   ----------------------------------------------------------------------   */
/*   * Wersja 1.0:                                                            */
/*       Opis: Utworzenie pierwszej wersji biblioteki                         */
/*		 Wykona³: Piotr Szawdyñski                                            */
/*		 Data: 8 maja 2007                                                    */
/*   ----------------------------------------------------------------------   */
/*   * Wersja 1.1:                                                            */
/*		 Opis: Rozwi¹zanie problemu multiple definitions                      */
/*       Wykona³: u¿ytkownik portalu http://ddt.pl: manfred                   */
/*		 Data: 7 czerwca 2009                                                 */
/*   ----------------------------------------------------------------------   */
/******************************************************************************/

#include <windows.h>
#include <conio.h>

namespace ddt
{
	namespace console
	{
		namespace
		{
			HANDLE DDTxDefaultConsoleHandle = 0;
			WORD DDTxCurrentColor;

			void textattr(WORD kolor);

			void init()
			{
				DDTxDefaultConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SMALL_RECT tRozmiar = {0, 0, 79, 24};
				COORD tWymiary = {80, 25};
				SetConsoleWindowInfo(DDTxDefaultConsoleHandle, true, &tRozmiar);
				//SetConsoleTitleA("Dokumentacja na stronie: http://ddt.pl");
				SetConsoleScreenBufferSize(DDTxDefaultConsoleHandle, tWymiary);
				textattr(7);
			}

			void gotoxy(int x, int y)
			{
				if(!DDTxDefaultConsoleHandle) init();

				COORD tPosition = {SHORT(x - 1), SHORT(y - 1)};
				SetConsoleCursorPosition(DDTxDefaultConsoleHandle, tPosition);
			}

			void textattr(WORD kolor)
			{
				if(!DDTxDefaultConsoleHandle) init();

				DDTxCurrentColor = kolor;
				SetConsoleTextAttribute(DDTxDefaultConsoleHandle, DDTxCurrentColor);
			}

			void textcolor(int kolor)
			{
				textattr((DDTxCurrentColor & 0xf0) + (kolor % 16));
			}

			void textbackground(int kolor)
			{
				textattr((DDTxCurrentColor & 0x0f) + ((kolor % 16)*16));
			}

			void SetCursor(bool fVisible = true)
			{
				if(!DDTxDefaultConsoleHandle)  init();

				CONSOLE_CURSOR_INFO ConCurInf;
				ConCurInf.dwSize = 10;
				ConCurInf.bVisible = fVisible;
				SetConsoleCursorInfo(DDTxDefaultConsoleHandle, &ConCurInf);
			}

			void clrscr()
			{
				if(!DDTxDefaultConsoleHandle) init();

				DWORD written;
				COORD coord = {0, 0};
				FillConsoleOutputAttribute (DDTxDefaultConsoleHandle, DDTxCurrentColor, 2000, coord, &written);
				FillConsoleOutputCharacter (DDTxDefaultConsoleHandle, ' ', 2000, coord, &written);
				gotoxy(1, 1);
			}

			int wherex()
			{
				CONSOLE_SCREEN_BUFFER_INFO tConsoleInfo;
				GetConsoleScreenBufferInfo(DDTxDefaultConsoleHandle, &tConsoleInfo);
				return tConsoleInfo.dwCursorPosition.X + 1;
			}

			int wherey()
			{
				if(!DDTxDefaultConsoleHandle) init();

				CONSOLE_SCREEN_BUFFER_INFO tConsoleInfo;
				GetConsoleScreenBufferInfo(DDTxDefaultConsoleHandle,&tConsoleInfo);
				return tConsoleInfo.dwCursorPosition.Y + 1;
			}

			void title(const char* tytul)
			{
				if(!DDTxDefaultConsoleHandle) init();

				SetConsoleTitleA(tytul);
			}
		}
	}
}
#endif CONSOLE_H


