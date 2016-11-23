#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

class Dado
{
	public:
		Dado();
		~Dado();

		void start(string tipo); //INICIALIZA A COR DO DADO
		void reset(); //RETORNA O DADO PARA O POTE
		void roll(int handPos); //MUDA O STATUS DO DADO
		void setLocal(string local);

		string getLocal();
		string getTipo();
		string getFace();

	private:
		string local; //ONDE O DADO SE ENCONTRA NO MOMENTO: POTE | HAND | TABLE
		string tipo; //VERDE, AMARELO, VERMELHO
		string face; //CEREBRO, TIRO, FUGA
};

