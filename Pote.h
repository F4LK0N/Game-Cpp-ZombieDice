#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

#include "Dado.h"

class Pote
{
	public:
		Pote();
		~Pote();

		void start();
		int getDadoRandom();
		int getDadosDisponiveis();
		void refill();
		
		string getDadoTipo(int dado);
		string getDadoFace(int dado);
		string getDadoLocal(int dado);

		void setDadoLocal(int dado, string local);
		void dadoRoll(int dado, int handPos);

	private:
		Dado dado[13];
		int dadosDisponiveis;
};

