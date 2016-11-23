#pragma once
#include <string>
#include <time.h>
using namespace std;

#include "libUnicornio.h"

#include "Menu.h"
#include "GameInterfaceBackground.h"
#include "GameInterfaceScore.h"
#include "GameInterfaceTable.h"
#include "GameInterfaceControl.h"

class Jogo
{
	public:
		Jogo();
		~Jogo();

		void inicializar();
		void finalizar();
		void executar();
	
	private:
		//MENUS
		Menu menuMain;
		Menu menuOpcoes;
		Menu menuJogadores;
		Menu menuNomes;
		Menu menuPause;
		Menu menuScore;
		Menu menuGanhador;
		Menu menuEmpate;
		Menu menuRegras;
		Menu menuCredits;
		
		//MENU METHODS
		void methodMenuMain();
		void methodMenuOpcoes();
		void methodMenuJogadores();
		void methodMenuNomes();
		void methodMenuPause();
		void methodMenuScore();
		void methodMenuGanhador();
		void methodMenuEmpate();
		void methodMenuRegras();
		void methodMenuCredits();

		//MENU - REGRAS
		Texto menuRegrasTexto[3];
		
		//MENU - NOME
		int cursorBlink;

		//MENU - CREDITS
		Texto menuCreditsTexto[20][4];
		int menuCreditsPage;



		//RUNNING INSTANCES
		bool   runningMain;
		string runningMenu;
		string runningGame;

		//OPTIONS
		//bool optionAudio;//Esta variavel agora é definida globalmente.

		//JOGADORES
		Jogador jogador[4];
		int     jogadorAtual;

		//GAME WINNER
		int gameWinners=0;
		int gameHigherPoints=0;
		void checkWinner();

		//GAME INTERFACE
		GameInterfaceBackground gameInterfaceBackground;
		GameInterfaceScore      gameInterfaceScore;
		GameInterfaceTable      gameInterfaceTable;
		GameInterfaceControl    gameInterfaceControl;

		//GAME METHODS
		void methodGameZD1();
		void methodGameZD2();
		void methodGameZD3();

		//SOUND FX
		int soundFXTimeLine;
		int soundFXInterval;
};

