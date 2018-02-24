#ifndef SERPIENTE_H
#define SERPIENTE_H
#include <vector>
#include <string>
using namespace std;
class Serpiente{
	private:
		int size = 0;
		vector<string> cuerpo;
		int pixelescomidos = 0;
		int cantmov = 0;
		string nombre;
		int score=0;
	public:	
		int getCantMov();
		void setCantMov();
		void Moviviento();
		int getScore();
		Serpiente(string);
		string getNombre();
		vector<string> getCuerpo();
		void agregarPixel(string);
		void Comer(string**&);
		bool Muerte(string**&);
		void Movimiento(int,int,string,string**&);
		~Serpiente();
};
#endif
