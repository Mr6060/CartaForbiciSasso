#pragma once
#ifndef GIOCO_H
#define GIOCO_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>           //this_thread::sleep_for(chrono::seconds(3));
#include <chrono>
#include <fstream>   //libreria che userò per salvare i punteggi;
#include <Windows.h>
using namespace std;
extern int sc1,p,p1;
int sc1,p,p1;
void facile();
void medio();
void difficile();
void impossibile();
void cambioDiff();
void giocoFacile(){

	do {
		system("CLS");
		cout << "DIFFICOLTA' FACILE" << endl;
		cout << "Scegli cosa fare\n";
		cout << "1-\tScegli Carta (c), Forbice (f) o Sasso (s)\n";
		cout << "2-\tCambia difficolta'\n";
		cout << "3-\tFine gioco\n";
		cin >> sc1;
		switch (sc1) {
			case 1:
				facile();
				break;
			case 2:
				cambioDiff();
				break;
			case 3:
				system("CLS");
				cout << "\n\n\n\t\t\tSTAI USCENDO DAL GIOCO, VERRAI PORTATO NEL MENU' PRINCIPALE\n\n\n";
				this_thread::sleep_for(chrono::seconds(3));
				system("CLS");
				break;
		}
	}while(sc1!=3);
}
void giocoMedio() {

	do {
		system("CLS");
		cout << "DIFFICOLTA' MEDIA" << endl;
		cout << "Scegli cosa fare\n";
		cout << "1-\tScegli Carta (c), Forbice (f) o Sasso (s)\n";
		cout << "2-\tCambia  difficolta'\n";
		cout << "3-\tFine gioco\n";
		cin >> sc1;
		switch (sc1) {
			case 1:
				medio();
				break;
			case 2:
				cambioDiff();
				break;
			case 3:
				system("CLS");
				cout << "\n\n\n\t\t\tSTAI USCENDO DAL GIOCO, VERRAI PORTATO NEL MENU' PRINCIPALE\n\n\n";
				this_thread::sleep_for(chrono::seconds(3));
				system("CLS");
				break;
		}
	} while (sc1 != 3);
}
void giocoDiff() {

	do{
		system("CLS");
		cout << "DIFFICOLTA' DIFFICILE" << endl;
		cout << "Scegli cosa fare\n";
		cout << "1-\tScegli Carta (c), Forbice (f) o Sasso (s)\n";
		cout << "2-\tCambia  difficolta'\n";
		cout << "3-\tFine gioco\n";
		cin >> sc1;
		switch (sc1) {
			case 1:

				difficile();
				break;
			case 2:
				cambioDiff();
				break;
			case 3:
				system("CLS");
				cout << "\n\n\n\t\t\tSTAI USCENDO DAL GIOCO, VERRAI PORTATO NEL MENU' PRINCIPALE\n\n\n";
				this_thread::sleep_for(chrono::seconds(3));
				system("CLS");
				break;
		}
	}while(sc1!=3);
}
void giocoImp(){
	do{
		system("CLS");
		cout<<"DIFFICOLTA' IMPOSSIBILE"<<endl;
		cout<<"Scegli cosa fare\n";
		cout<<"1-\tScegli Carta (c), Forbice (f) o Sasso (s)\n";
		cout<<"2-\tCambia  difficolta'\n";
		cout<<"3-\tFine gioco\n";
		cin>>sc1;
		switch (sc1) {
			case 1:
				impossibile();
				break;
			case 2:
				cambioDiff();
				break;
			case 3:
				system("CLS");
				cout<<"\n\n\n\t\t\tSTAI USCENDO DAL GIOCO, VERRAI PORTATO NEL MENU' PRINCIPALE\n\n\n";
				this_thread::sleep_for(chrono::seconds(3));
				system("CLS");
				break;
		}
	}while(sc1!=3);
}
void cambioDiff(){
	int diff;
	system("CLS");
	cout<<"Scegli la difficolta':\n";
	cout<<"1-\t Facile (no, veramente troppo facile)\n";
	cout<<"2-\t Medio (non troppo facile, ma non troppo difficile)\n";
	cout<<"3-\t Difficile (difficile ma non impossibile)\n";
	cout<<"4-\t Impossibile (diffile e pressoche' impossibile)\n";
	cout<<"Fai la tua scelta\n";
	cin>>diff;
	switch(diff){
		case 1:
			giocoFacile();
			break;
		case 2:
			giocoMedio();
			break;
		case 3:
			giocoDiff();
			break;
		case 4:
			giocoImp();
			break;
	}
}
void facile(){
	srand(time(NULL));
	char a;
	int r;
	system("CLS");
	cout<<"Bene, scegli Carta (c), Forbice (f) o Sasso (s)\n ";
	cin>>a;
	r=rand()%10+1;

	if((a!='c')&&(a!='f')&&(a!='s')){
		cout<<"Oggetto inesistente\n";
	}
	else{

		if(r!=10){
			if(a=='c'){
				cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego SASSO!\n";
				cout<<"\t\tHai vinto! Un punto a te."<<endl;
				p++;

			}
			if(a=='f'){
				cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo CARTA!\n";
				cout<<"\t\tHai vinto! Un punto a te."<<endl;
				p++;
			}
			if(a=='s'){
				cout<<"\n\t\tHai scelto SASSO\n\t\tIo scelgo FORBICI\n";
				cout<<"\t\tHai vinto! Un punto a te."<<endl;
				p++;
			}
		}
		else{
			if(r==10){
				if(a=='c'){
					cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego FORBICI!\n";
					cout<<"\t\tHo vinto! Un punto a me."<<endl;
					p1++;
				}
				if(a=='f'){
					cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo SASSO!\n";
					cout<<"\t\tHo vinto! Un punto a me."<<endl;
					p1++;
				}
				if(a=='s'){
					cout<<"\n\t\tHai scelto SASSO\n\t\tIo scelgo CARTA\n";
					cout<<"\t\tHo vinto! Un punto a me."<<endl;
					p1++;
				}
			}
		}
		this_thread::sleep_for(chrono::seconds(3));
	}

}
void medio(){
	srand(time(NULL));
	char a;
	int r;
	system("CLS");
	cout<<"Bene, scegli Carta (c), Forbice (f) o Sasso (s)\n ";
	cin>>a;
	r=rand()%10+1;


	if((a!='c')&&(a!='f')&&(a!='s')){
		cout<<"Oggetto inesistente\n";
	}
	if(r<=7){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego SASSO!\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo CARTA!\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
		if(a=='s'){
			cout<<"\n\t\tHai schelto SASSO\n\t\tIo scelgo FORBICI\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
	}
	if((r>7)&&(r<=9)){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego FORBICI!\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scleto FORBICI\n\t\tIo scelgo SASSO!\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
		if(a=='s'){
			cout<<"\n\t\tHai scleto SASSO\n\t\tIo scelgo CARTA\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
	}
	if(r==10){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego CARTA!\n";
			cout<<"\t\tPareggio!"<<endl;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo FORBICI!\n";
			cout<<"\t\tPareggio"<<endl;
		}
		if(a=='s'){
			cout<<"\n\t\tHai scelto SASSO\n\t\tIo scelgo SASSO\n";
			cout<<"\t\tPareggio"<<endl;
		}
	}
	this_thread::sleep_for(chrono::seconds(3));
}
void difficile(){
	srand(time(NULL));
	char a;
	int r;
	system("CLS");
	cout<<"Bene, scegli Carta (c), Forbice (f) o Sasso (s)\n ";
	cin>>a;
	r=rand()%10+1;

	if((a!='c')&&(a!='f')&&(a!='s')){
		cout<<"Oggetto inesistente\n";
	}
	if(r<=3){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego SASSO!\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo CARTA!\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
		if(a=='s'){
			cout<<"\n\t\tHai schelto SASSO\n\t\tIo scelgo FORBICI\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
	}
	if((r>=4)&&(r<=8)){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego FORBICI!\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo SASSO!\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
		if(a=='s'){
			cout<<"\n\t\tHai scelto SASSO\n\t\tIo scelgo CARTA\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
	}
	if(r>=9){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego CARTA!\n";
			cout<<"\t\tPareggio"<<endl;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo FORBICI!\n";
			cout<<"\t\tPareggio"<<endl;
		}
		if(a=='s'){
			cout<<"\n\t\tHai scelto SASSO\n\t\tIo scelgo SASSO\n";
			cout<<"\t\tPareggio"<<endl;
		}
	}
	this_thread::sleep_for(chrono::seconds(3));

}
void impossibile(){
	srand(time(NULL));
	char a;
	int r;
	system("CLS");
	cout<<"Bene, scegli Carta (c), Forbice (f) o Sasso (s)\n ";
	cin>>a;
	r=rand()%10+1;

	if((a!='c')&&(a!='f')&&(a!='s')){
		cout<<"Oggetto inesistente\n";
	}
	if(r<=1){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego SASSO!\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo CARTA!\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
		if(a=='s'){
			cout<<"\n\t\tHai schelto SASSO\n\t\tIo scelgo FORBICI\n";
			cout<<"\t\tHai vinto! Un punto a te."<<endl;
			p++;
		}
	}
	if((r>=2)&&(r<=9)){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego FORBICI!\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo SASSO!\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
		if(a=='s'){
			cout<<"\n\t\tHai scelto SASSO\n\t\tIo scelgo CARTA\n";
			cout<<"\t\tHo vinto! Un punto a me."<<endl;
			p1++;
		}
	}
	if(r==10){
		if(a=='c'){
			cout<<"\n\t\tHai scelto CARTA\n\t\tIo sclego CARTA!\n";
			cout<<"\t\tPareggio"<<endl;
		}
		if(a=='f'){
			cout<<"\n\t\tHai scelto FORBICI\n\t\tIo scelgo FORBICI!\n";
			cout<<"\t\tPareggio"<<endl;
		}
		if(a=='s'){
			cout<<"\n\t\tHai scelto SASSO\n\t\tIo scelgo SASSO\n";
			cout<<"\t\tPareggio"<<endl;
		}
	}
	this_thread::sleep_for(chrono::seconds(3));
}

void iniziaGioco(){
	int diff;
	system("CLS");
	cout<<"Bene, iniziamo a giocare!\n";
	cout<<"Scegli la difficolta':\n";
	cout<<"1-\t Facile (no, veramente troppo facile)\n";
	cout<<"2-\t Medio (non troppo facile, ma non troppo difficile)\n";
	cout<<"3-\t Difficile (difficile ma non impossibile)\n";
	cout<<"4-\t Impossibile (diffile e pressoche' impossibile)\n";
	cout<<"Fai la tua scelta\n";
	cin>>diff;
	switch(diff){
		case 1:
			giocoFacile();
			break;
		case 2:
			giocoMedio();
			break;
		case 3:
			giocoDiff();
			break;
		case 4:
			giocoImp();
			break;

	}
}

#endif // GIOCO_H
