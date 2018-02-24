#include "Serpiente.h"
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;
Serpiente::Serpiente(string nombre){
	this->nombre = nombre;
	cuerpo.push_back("5-1");
	cuerpo.push_back("4-1");
	cuerpo.push_back("3-1");
	cuerpo.push_back("2-1");
	cuerpo.push_back("1-1");
	//cuerpo[0] = "1-1";
	//cuerpo[1] = "1-2";
	//cuerpo[2] = "1-3";
	//cuerpo[3] = "1-4";
	//cuerpo[4] = "1-5";
}
string Serpiente::getNombre(){
	return nombre;
}
vector<string> Serpiente::getCuerpo(){
	return cuerpo;
}
void Serpiente::agregarPixel(string coordenadas){
	cuerpo.push_back(coordenadas);
}
int Serpiente::getCantMov(){
	return cantmov;
}
void Serpiente::setCantMov(){
	cantmov++;
}
void Serpiente::Comer(string**& tablero){
	
}
int Serpiente::getScore(){
	return score;
}
void Serpiente::Movimiento(int x, int y,string c, string**& tablero){
	stringstream cord;
	cord<<y<<"-"<<x;
	cuerpo.push_back(cord.str());
	setCantMov();
	if (c == "p "){
	//	setCantMov();
		pixelescomidos++;
		score+= 100-cantmov;	
		cantmov = 0;
	}else{
		cuerpo.erase(cuerpo.begin());
		/*string corden = cuerpo[cuerpo.size()-1];
		string delimiter = "-";
		string y, x;
		y = corden.substr(0,corden.find(delimiter));
		x = corden.substr(corden.find(delimiter) + 1);
		int cord_x,cord_y;
		cord_x = atoi(x.c_str());
		cord_y = atoi(y.c_str());*/

	}
	for(int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			if(tablero[i][j] == "c " || tablero[i][j] == "C "){
				tablero[i][j] = "- ";
				//cout<<"entro";
			}
		}
	}
	for(int i = 0; i < cuerpo.size(); i++){
		string corden = cuerpo[i];
		string delimiter = "-";
		string y,x;
		y = corden.substr(0,corden.find(delimiter));
		x = corden.substr(corden.find(delimiter)+1,corden.length()-1);
		int cord_x,cord_y;
		cord_x = atoi(x.c_str());
		cord_y = atoi(y.c_str());
		if(i != cuerpo.size()-1){
			tablero[cord_y][cord_x] = "c ";
		}else{
			tablero[cord_y][cord_x] = "C ";
		}
	}
}
bool Serpiente::Muerte(string**& tablero){
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			if(tablero[i][j] == "C "){
				if(i == 12 || i == 0){
					return true;
				}else if(j == 12 || j == 0){
					return true;
				}else{
					for(int i = 0; i < cuerpo.size(); i++){
						string corden = cuerpo[i];
						string delimiter = "-";
						string y,x;
						y = corden.substr(0,corden.find(delimiter));
						x = corden.substr(corden.find(delimiter)+1,corden.length()-1);
						int cord_x,cord_y;
						cord_x = atoi(x.c_str());
						cord_y = atoi(y.c_str());
						if(i != cuerpo.size()-1){
							tablero[cord_y][cord_x] = "c ";
						}else{
							tablero[cord_y][cord_x] = "C ";
						}
					}	
					return false;		
				}
			}
		}
	}
}
Serpiente::~Serpiente(){
	
}
