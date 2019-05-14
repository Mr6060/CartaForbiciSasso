
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <fstream>
#include <Windows.h>
#include "gioco.h"
using namespace std;

extern int sc1,p,p1;
ifstream leggiPuntG, leggiPuntP;
ofstream scriviPuntG, scriviPuntP;

int main()
{
	int sc;
	leggiPuntG.open("puntG.txt", ios::app);
	if (leggiPuntG.is_open()) {
		leggiPuntG >> p;
		leggiPuntG.close();
	}
	leggiPuntP.open("puntP.txt", ios::app);
	if (leggiPuntP.is_open()) {
		leggiPuntP >> p1;
		leggiPuntP.close();
	}
	do {
		system("CLS");
		cout << "MENU'" << endl;
		cout << "1-\tInizia a giocare\n";
		cout << "2-\tMostra i punti di giocatore e macchina\n";
		cout << "3-\tResetta i punti\n";
		cout << "4-\tFine\n";
		cin >> sc;
		switch (sc) {
			case 1:
				iniziaGioco();
				break;
			case 2:
				cout << "Punti Giocatore\t\tPunti Macchina\n";
				cout <<"\t"<< p << "\t\t\t" << p1 << endl;
				system("Pause");
				break;
			case 3:
				p = 0;
				p1 = 0;
				cout << "Fatto, i punti sono azzerati" << endl;
				break;
			case 4:
				system("CLS");
				cout << "\n\n\n\t\t\tGRAZIE PER AVER GIOCATO, ALLA PROSSIMA!!!\n\n\n" << endl;
				break;
		}
		if ((sc <= 0) || (sc > 4)) {
			cout << "\aErrore\n";
			this_thread::sleep_for(chrono::seconds(2));
			system("CLS");
		}
		scriviPuntG.open("puntG.txt", ios::in);
		if (scriviPuntG.is_open()) {
			scriviPuntG << p;
			scriviPuntG.close();
		}
		scriviPuntP.open("puntP.txt", ios::in);
		if (scriviPuntP.is_open()) {
			scriviPuntP << p1;
			scriviPuntP.close();
		}
		this_thread::sleep_for(chrono::seconds(2));
	} while (sc != 4);
}