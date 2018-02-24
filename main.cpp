#include <iostream>
#include <string>
#include "Serpiente.h"
#include <ncurses.h>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;
//Crear tablero
void Create(string**&);
//Crear pixel
void addPixel(string**&);
//Imprimir 
void printTab(string**,WINDOW*);
//Llenar
void Llenar(string**&);

int main(){
	cout<<"Ingrese su nombre: "<<endl;
	string nombre;
	cin>>nombre;
	Serpiente* snake = new Serpiente(nombre);
	initscr();
	noecho();
	WINDOW* win = newwin(50,50,1,1);
	//getch();
	string** tablero;
	Create(tablero);
	Llenar(tablero);
	addPixel(tablero);
	keypad(stdscr,TRUE);
	cbreak();
	int pos_x,pos_y;
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			if(tablero[i][j] == "C "){
				pos_x = j;
				pos_y = i;		
			}
		}
	}
	int delta_y = 1;
	int delta_x = 0;
	while(!snake->Muerte(tablero)){
		nodelay(stdscr,TRUE);
		clear();
		halfdelay(5);
		refresh();
		printTab(tablero,win);
		printw("%s","\n");
		printw("%i",snake->getScore());
		switch(getch()){
		case KEY_UP:
			delta_y = -1;
			delta_x = 0;
			nodelay(stdscr, FALSE);
			break;
		case KEY_DOWN:
			delta_y = 1;
			delta_x = 0;
			nodelay(stdscr, FALSE);
			break;
			
		case KEY_LEFT:
			delta_x = -1;
			delta_y = 0;
			nodelay(stdscr, FALSE);
			break;

		case KEY_RIGHT:
			delta_x = 1;
			delta_y = 0;
			nodelay(stdscr, FALSE);
			break;
		}
		//tablero[pos_y][pos_x] = "- ";
		pos_x+=delta_x;
		pos_y+=delta_y;
		if(pos_x < 12 && pos_x >= 0 && pos_y < 12 && pos_y >=0){
			if(tablero[pos_y][pos_x] == "p "){
				addPixel(tablero);
			}
		}
		if(!snake->Muerte(tablero)){
			snake->Movimiento(pos_x,pos_y,tablero[pos_y][pos_x], tablero);
		}else{
			cout<<"Perdio"<<endl;
		}
		//tablero[pos_y][pos_x] = "C ";
		usleep(5000);	
	}
	//printTab(tablero,win);
	//getch();
	//endwin();
	return 0;
}
void Create(string**& tablero){
	tablero = new string*[12];
	for(int i = 0; i < 12; i++){
		tablero[i] = new string[12];
	}
}

void Llenar(string**& tablero){
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			if(i==0 || i==11){
				tablero[i][j] = "* ";
			}else if(j==0 || j == 11){
				tablero[i][j] = "* ";
			}else{
				tablero[i][j] = "- ";
			}
		}
	}
	tablero[1][1] = "C ";
	tablero[1][2] = "c ";
	tablero[1][3] = "c ";
	tablero[1][4]  = "c ";
	tablero[1][5] = "c ";
}
void addPixel(string**& tablero){
	srand(time(NULL));
	int randomX,randomY;
	bool val = false;
	while(!val){
		randomX = rand() % 10 + 1;
		randomY = rand() % 10 + 1;
		if(tablero[randomY][randomX] == "- "){
			tablero[randomY][randomX] = "p ";
			val = true;
		}
	}

}

void printTab(string** tablero,WINDOW* win){
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			string mat;
			mat = tablero[i][j];
			//cout<<tablero[i][j]<<"    ";
			printw("%s",tablero[i][j].c_str());
			//addch(tablero[i][j]);
		}
		printw("%s","\n");
		//cout<<endl;
	}
}
