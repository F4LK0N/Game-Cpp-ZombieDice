#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

#include "Jogador.h"

class GameInterfaceTable
{
	public:
		GameInterfaceTable();
		~GameInterfaceTable();
		void inicializar();
		void reset();
		void run(Jogador jogador);

	private:
		void handDraw(Jogador jogador);
		Texto  handText[3];
		Sprite handSprite[3][3];
		
		void tableDraw(Jogador jogador);
		Texto  tableText[10];
		Sprite tableSprite[3][3];

		void deadDraw(Jogador jogador);
		Texto  deadText[2];
		Sprite deadSprite;
		Sprite deadBackground;
		Som deadSound;
		bool deadSoundPlayed;
};

