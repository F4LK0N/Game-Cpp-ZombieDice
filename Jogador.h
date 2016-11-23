#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

#include "Pote.h"

class Jogador
{
	public:
		Jogador();
		~Jogador();

		void initialize(string nome, string control); //ADICIONA O JOGADOR AO GAME
		void restart();
		void clear(); //RETIRA O JOGADOR DO GAME
		void eliminar(); //JOGADOR PERDEU

		bool getStatus();
		bool getJogando();
		string getNome();
		void setNome(string nome);

		int getHand(int pos);
		int getTable(int pos);
		
		string getDadoTipo(int dado);
		string getDadoFace(int dado);
		string getDadoLocal(int dado);

		void roundStart();
		void roundStop();
		bool roundCheckEnd(); //TRUE = PLAYER DIED
		void roundContinue();

		int autoPlay();

		int getCerebrosTotal();
		int getCerebrosParcial();
		int getTiros();
		int getVida();

		void setCerebrosTotal(int valor);
		void setCerebrosParcial(int valor);
		void setTiros(int valor);
		void setVida(int valor);

		//FAZER GET E SET DESSAS VARIAVIES E MUDAR O CODIGO DA INTERFACE
		int cerebrosTotal; //TOTAL DE CEREBROS COMIDOS NO JOGO TODO.
		int cerebrosParcial; //TOTAL DE CEREBROS COMIDOS NA RODADA ATUAL.
		int tiros;
		int vida; //QUANTOS TIROS PODE LEVAR. DEFAULT 3, COM CAPACETE PASSA PARA 4.

	private:
		string nome;
		bool status; //ATIVO | INATIVO;
		bool jogando; //FALSE = ELIMINADO
		string control; //HUMANO | PC
		
		Pote pote;
		int hand[3];
		int table[10];

		int autoPlayDelay;
};
