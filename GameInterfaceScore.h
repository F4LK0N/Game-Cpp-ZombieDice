#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

#include "Jogador.h"

class GameInterfaceScore
{
	public:
		GameInterfaceScore();
		~GameInterfaceScore();

		void inicializar();

		void setGame(string game);
		
		void run(Jogador jogador);

	private:
		Sprite scoreBackground;
		Texto score;
		Texto jogador;

		Sprite gameBackground;
		Texto game;
};

