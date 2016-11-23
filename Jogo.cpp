//############################################################################################################################################
#include "Jogo.h"
//############################################################################################################################################



//############################################################################################################################################
Jogo::Jogo(){}
Jogo::~Jogo(){}
//############################################################################################################################################



//############################################################################################################################################
void Jogo::inicializar(){
	//TELA
	//uniInicializar(800, 600, false);
	//uniInicializar(1024, 768, true);
	uniInicializar(1920, 1080, true);
	
	//RANDOM NUMBERS
	srand(time(0));
	

	//FONTES
	//Default
	gRecursos.carregarFonte("fonteArial", "assets/fonts/arial.ttf", gJanela.getAltura()/20);
	//In Game: Game Name
	gRecursos.carregarFonte("fonteTheDeadAreComing",     "assets/fonts/the-dead-are-coming.ttf", gJanela.getAltura()/15);
	gRecursos.carregarFonte("fonteTheDeadAreComingMini", "assets/fonts/the-dead-are-coming.ttf", gJanela.getAltura()/35);
	//In Game: Score && Player Name
	gRecursos.carregarFonte("fonteExquisiteCorpseExtraBig", "assets/fonts/exquisite-corpse.ttf", gJanela.getAltura()/6);
	gRecursos.carregarFonte("fonteExquisiteCorpseBig",      "assets/fonts/exquisite-corpse.ttf", gJanela.getAltura()/11);
	gRecursos.carregarFonte("fonteExquisiteCorpse",         "assets/fonts/exquisite-corpse.ttf", gJanela.getAltura()/27);
	//In Game: Dead Message
	gRecursos.carregarFonte("fonteYouMurderedBig", "assets/fonts/you-murderer.otf", gJanela.getAltura()/7);
	gRecursos.carregarFonte("fonteYouMurdered",    "assets/fonts/you-murderer.otf", gJanela.getAltura()/12);
	//Menus
	gRecursos.carregarFonte("fonteBlackAsylum",    "assets/fonts/black-asylum-zombie-queen-mix.ttf", gJanela.getAltura()/20);

		
	
	//MASKS
	gRecursos.carregarSpriteSheet("mask", "assets/imgs/mask.png");
	gRecursos.carregarSpriteSheet("maskTopBottom", "assets/imgs/mask-top-bottom.png");
	

	//BACKGROUNDS
	gRecursos.carregarSpriteSheet("menuBackground1", "assets/imgs/menu-background1.jpg");
	gRecursos.carregarSpriteSheet("menuBackground2", "assets/imgs/menu-background2.jpg");
	gRecursos.carregarSpriteSheet("menuBackground3", "assets/imgs/menu-background3.jpg");
	
	gRecursos.carregarSpriteSheet("gameBackground1", "assets/imgs/game-background1.jpg");
	gRecursos.carregarSpriteSheet("gameBackground2", "assets/imgs/game-background2.jpg");
	gRecursos.carregarSpriteSheet("gameBackground3", "assets/imgs/game-background3.jpg");
	gRecursos.carregarSpriteSheet("gameBackground4", "assets/imgs/game-background4.jpg");

	gRecursos.carregarSpriteSheet("backgroundWallBlack", "assets/imgs/background-wall-black.jpg");


	//SPRITES
	gRecursos.carregarSpriteSheet("spriteDead", "assets/imgs/sprite-dead.png");


	//DADOS
	gRecursos.carregarSpriteSheet("dadoVERDE-CEREBRO",    "assets/imgs/dado-verde-cerebro.png");
	gRecursos.carregarSpriteSheet("dadoVERDE-TIRO",       "assets/imgs/dado-verde-tiro.png");
	gRecursos.carregarSpriteSheet("dadoVERDE-FUGA",       "assets/imgs/dado-verde-fuga.png");
	gRecursos.carregarSpriteSheet("dadoAMARELO-CEREBRO",  "assets/imgs/dado-amarelo-cerebro.png");
	gRecursos.carregarSpriteSheet("dadoAMARELO-TIRO",     "assets/imgs/dado-amarelo-tiro.png");
	gRecursos.carregarSpriteSheet("dadoAMARELO-FUGA",     "assets/imgs/dado-amarelo-fuga.png");
	gRecursos.carregarSpriteSheet("dadoVERMELHO-CEREBRO", "assets/imgs/dado-vermelho-cerebro.png");
	gRecursos.carregarSpriteSheet("dadoVERMELHO-TIRO",    "assets/imgs/dado-vermelho-tiro.png");
	gRecursos.carregarSpriteSheet("dadoVERMELHO-FUGA",    "assets/imgs/dado-vermelho-fuga.png");


	//SOUND - MUSIC
	gRecursos.carregarMusica("musicMenu", "assets/musics/menu.mp3");
	gRecursos.carregarMusica("musicGame", "assets/musics/game.mp3");
	gMusica.tocar("musicMenu", true);
	
	
	//SOUND - FX
	soundFXInterval = 30;
	soundFXTimeLine = soundFXInterval*4; //Qualquer numero maior que soundFXInterval*3 serve.
	gRecursos.carregarAudio("somCerebro",         "assets/sounds/cerebro.wav");
	gRecursos.carregarAudio("somFuga",            "assets/sounds/fuga.mp3");
	gRecursos.carregarAudio("somTiroVerde",       "assets/sounds/tiro-verde.mp3");
	gRecursos.carregarAudio("somTiroAmarelo",     "assets/sounds/tiro-amarelo.mp3");
	gRecursos.carregarAudio("somTiroVermelho",    "assets/sounds/tiro-vermelho.mp3");
	gRecursos.carregarAudio("somDead",            "assets/sounds/dead.mp3");
	gRecursos.carregarAudio("somClick",           "assets/sounds/click.mp3");


	//MENU - MAIN
	menuMain.setBackground("menuBackground1");
	menuMain.addItem("Zombie Dice - Tradicional");
	menuMain.addItem("Zombie Dice - Dose Dupla");
	menuMain.addItem("Zombie Dice - Ônibus Escolar");
	menuMain.addItem("Opções");
	menuMain.addItem("Creditos");
	menuMain.addItem("Sair");

	//MENU - OPÇÕES
	menuOpcoes.setBackground("menuBackground1");
	menuOpcoes.addItem("Audio: Ligado");
	menuOpcoes.addItem("Voltar");

	//MENU - JOGADORES
	menuJogadores.setBackground("menuBackground1");
	menuJogadores.addItem("Jogador vs Computador");
	menuJogadores.addItem("2 Jogadores");
	menuJogadores.addItem("3 Jogadores");
	menuJogadores.addItem("4 Jogadores");
	menuJogadores.addItem("Regras");
	menuJogadores.addItem("Voltar");

	//MENU - NOMES
	menuNomes.setBackground("menuBackground1");
	menuNomes.addItem("Jogar");
	menuNomes.addItem("");
	menuNomes.addItem("");
	menuNomes.addItem("");
	menuNomes.addItem("");
	menuNomes.addItem("Voltar");
	cursorBlink=0;

	//MENU - PAUSE
	menuPause.setBackground("menuBackground1");
	menuPause.addItem("Voltar para o Windows");
	menuPause.addItem("Sair do Jogo");
	menuPause.addItem("Continuar Jogo");
	menuPause.setPointer(2);

	//MENU - GANHADOR
	menuGanhador.setBackground("menuBackground2");
	menuGanhador.addItem("");
	menuGanhador.addItem("");
	menuGanhador.addItem("");
	menuGanhador.addItem("");
	menuGanhador.addItem("");
	menuGanhador.addItem("");
	menuGanhador.addItem("");
	menuGanhador.addItem("Voltar para o Menu");
	menuGanhador.setPointer(10);

	//MENU - EMPATE
	menuEmpate.setBackground("menuBackground2");
	menuEmpate.addItem("   EMPATE!   ");
	menuEmpate.addItem("");
	menuEmpate.addItem("");
	menuEmpate.addItem("");
	menuEmpate.addItem("");
	menuEmpate.addItem("");
	menuEmpate.addItem("");
	menuEmpate.addItem("Rodada de desempate");
	menuEmpate.setPointer(10);

	//MENU - SCORE
	menuScore.setBackground("menuBackground2");
	menuScore.addItem("");
	menuScore.addItem("");
	menuScore.addItem("");
	menuScore.addItem("");
	menuScore.addItem("");
	menuScore.addItem("");
	menuScore.addItem("");
	menuScore.setPointer(10);

	//MENU - REGRAS
	menuRegras.addItem("");
	menuRegras.addItem("");
	menuRegras.addItem("");
	menuRegras.addItem("");
	menuRegras.addItem("");
	menuRegras.addItem("");
	menuRegras.addItem("");
	menuRegras.addItem("");
	menuRegras.addItem("");
	menuRegras.addItem("Voltar");
	menuRegras.setPointer(10);
	for(int i=0; i<3; i++){
		menuRegrasTexto[i].setFonte("fonteArial");
		menuRegrasTexto[i].setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
		menuRegrasTexto[i].setAncora(0, 0);
		menuRegrasTexto[i].setEscala(0.75, 0.75);
	}
	//MENU - REGRAS - ZD1
	menuRegrasTexto[0].setString(
		"Zombie Dice - Tradicional\n"
		"\n"
		" Você é um zumbi e seu objetivo é comer cerebros!\n"
		" A cada rodada cada jogador escolhe jogar o quanto quiser, ate parar ou morrer.\n"
		" O jogador que comer 13 cerebros ou mais ao final da rodada ganha.\n"
		" Você sempre persegue 3 vitimas de cada vez.\n"
		" Cada vitima pode ter um cerebro, um tiro ou uma pegada.\n"
		" Se você tomar 3 tiros você morre e perde os cerebros que conquistou nesta rodada.\n"
		" Se cair pegada aquela vitima segue fugindo de você.\n"
		" Cada vitima tem chances de cair 6 opções diferentes.\n"
		" As vitimas verdes tem 4 cerebros, 1 pegada e 1 tiro\n"
		" As vitimas amarelas tem 2 cerebros, 2 pegadas e 2 tiros.\n"
		" As vitimas vermelhas tem 4 tiros, 1 pegada e 1 cerebro."
	);
	//MENU - REGRAS - ZD2
	menuRegrasTexto[1].setString("");
	//MENU - REGRAS - ZD3
	menuRegrasTexto[2].setString("");

	//MENU - CREDITS
	menuCredits.addItem("");
	menuCredits.addItem("");
	menuCredits.addItem("");
	menuCredits.addItem("");
	menuCredits.addItem("");
	menuCredits.addItem("");
	menuCredits.addItem("");
	menuCredits.addItem("");
	menuCredits.addItem("Voltar");
	menuCredits.addItem("Proxima Pagina");
	menuCredits.setPointer(10);
	for(int i=0; i<20; i++){
		menuCreditsTexto[i][0].setFonte("fonteTheDeadAreComing");
		menuCreditsTexto[i][0].setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
		menuCreditsTexto[i][0].setAncora(0, 0);
		menuCreditsTexto[i][0].setEscala(0.55, 0.55);
		menuCreditsTexto[i][0].setCor(75, 75, 75, true);

		menuCreditsTexto[i][1].setFonte("fonteExquisiteCorpseExtraBig");
		menuCreditsTexto[i][1].setAlinhamento(TEXTO_CENTRALIZADO);
		menuCreditsTexto[i][1].setAncora(0.5, 0.5);
		menuCreditsTexto[i][1].setEscala(1, 1);
		menuCreditsTexto[i][1].setCor(128, 25, 25, true);

		menuCreditsTexto[i][2].setFonte("fonteTheDeadAreComing");
		menuCreditsTexto[i][2].setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
		menuCreditsTexto[i][2].setAncora(0, 0);
		menuCreditsTexto[i][2].setEscala(0.55, 0.55);
		menuCreditsTexto[i][2].setCor(75, 75, 75, true);

		menuCreditsTexto[i][3].setFonte("fonteBlackAsylum");
		menuCreditsTexto[i][3].setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
		menuCreditsTexto[i][3].setAncora(0, 0);
		menuCreditsTexto[i][3].setEscala(0.5, 0.5);
		menuCreditsTexto[i][3].setCor(110, 110, 110, true);
	}

	menuCreditsPage=0;

	//CREDITS - STEVE JACKSON
	menuCreditsTexto[0][0].setString("Jogo Criado Originalmente por:");
	menuCreditsTexto[0][1].setString("Steve Jackson");
	menuCreditsTexto[0][2].setString("Links:");
	menuCreditsTexto[0][3].setString("www.sjgames.com\n"
									 "www.galapagosjogos.com.br\n"
									 "www.edgeent.com\n");

	//CREDITS - FERNANDO MARSON
	menuCreditsTexto[1][0].setString("Querido Professor de Algoritimos e Coordenador do Projeto:");
	menuCreditsTexto[1][1].setString("Fernando P. Marson");
	menuCreditsTexto[1][2].setString("Facebook:");
	menuCreditsTexto[1][3].setString("www.facebook.com/profile.php?id=100009665747330");

	//CREDITS - OTAVIO
	menuCreditsTexto[2][0].setString("Planejamento e Execucao do Projeto:");
	menuCreditsTexto[2][1].setString("Otavio B. Soria");
	menuCreditsTexto[2][2].setString("Facebook:");
	menuCreditsTexto[2][3].setString("www.facebook.com/profile.php?id=100003995779430");

	//CREDITS - LIBUNICORNIO
	menuCreditsTexto[3][0].setString("Powered by:");
	menuCreditsTexto[3][1].setString("LibUnicornio");
	menuCreditsTexto[3][2].setString("GitHub:");
	menuCreditsTexto[3][3].setString("github.com/GuilhermeAlanJohann/libUnicornio");

	//CREDITS - SOUND FX
	menuCreditsTexto[4][0].setString("Efeitos Sonoros por:");
	menuCreditsTexto[4][1].setString("Free Sound");
	menuCreditsTexto[4][2].setString("Link:");
	menuCreditsTexto[4][3].setString("www.freesound.org");

	//CREDITS - SOUND FX
	menuCreditsTexto[5][0].setString("Efeitos Sonoros por:");
	menuCreditsTexto[5][1].setString("Flash Kit");
	menuCreditsTexto[5][2].setString("Link:");
	menuCreditsTexto[5][3].setString("www.flashkit.com");

	//CREDITS - SOUND FX
	menuCreditsTexto[6][0].setString("Efeitos Sonoros por:");
	menuCreditsTexto[6][1].setString("Sound Bible");
	menuCreditsTexto[6][2].setString("Link:");
	menuCreditsTexto[6][3].setString("www.soundbible.com");

	//CREDITS - IMAGES
	menuCreditsTexto[7][0].setString("Imagens por:");
	menuCreditsTexto[7][1].setString("The Noun Project");
	menuCreditsTexto[7][2].setString("Link:");
	menuCreditsTexto[7][3].setString("www.thenounproject.com");

	//CREDITS - IMAGES
	menuCreditsTexto[8][0].setString("Imagens por:");
	menuCreditsTexto[8][1].setString("Alpha Coders");
	menuCreditsTexto[8][2].setString("Link:");
	menuCreditsTexto[8][3].setString("wall.alphacoders.com");

	//CREDITS - IMAGES
	menuCreditsTexto[9][0].setString("Imagens por:");
	menuCreditsTexto[9][1].setString("Maxwel Parker");
	menuCreditsTexto[9][2].setString("Link:");
	menuCreditsTexto[9][3].setString("maxwelparker.files.wordpress.com/2012/10/stampinwall.jpg");

	//CREDITS - FONTS
	menuCreditsTexto[10][0].setString("Fontes por:");
	menuCreditsTexto[10][1].setString("My Fonts");
	menuCreditsTexto[10][2].setString("Link:");
	menuCreditsTexto[10][3].setString("www.myfonts.com");

	//CREDITS - FONTS
	menuCreditsTexto[11][0].setString("Fontes por:");
	menuCreditsTexto[11][1].setString("1001 Fonts");
	menuCreditsTexto[11][2].setString("Link:");
	menuCreditsTexto[11][3].setString("http://www.1001fonts.com/");

	//CREDITS - FONTS
	menuCreditsTexto[12][0].setString("Fontes por:");
	menuCreditsTexto[12][1].setString("Font Space");
	menuCreditsTexto[12][2].setString("Link:");
	menuCreditsTexto[12][3].setString("http://www.fontspace.com/");

	//CREDITS - MUSICS
	menuCreditsTexto[13][0].setString("Musicas por:");
	menuCreditsTexto[13][1].setString("Bensound");
	menuCreditsTexto[13][2].setString("Link:");
	menuCreditsTexto[13][3].setString("www.bensound.com");

	
	//RUNNING INSTANCES
	runningMain=true;
	runningMenu="main";
	runningGame="0";
	
	//OPTIONS
	extern bool optionAudio;
	optionAudio=true;

	//GAME INTERFACE
	gameInterfaceBackground.inicializar();
	gameInterfaceScore.inicializar();
	gameInterfaceTable.inicializar();
	gameInterfaceControl.inicializar();
}
//############################################################################################################################################



//############################################################################################################################################
void Jogo::finalizar(){
	
	//STOP SOUNDS
	extern Som soundDado[3];
	for(int i=0; i<3; i++){ soundDado[i].parar(); }

	//STOP MUSICS
	gMusica.parar();

	//WAIT FOR ANY OTHER SOUNDS
	_sleep(1000);
	
	//UNLOAD RESOURCES
	gRecursos.descarregarTodasFontes();
	gRecursos.descarregarTodasMusicas();
	gRecursos.descarregarTodosAudios();
	gRecursos.descarregarTodosSpriteSheets();
	gRecursos.descarregarTudo();
	
	//LIB END
	uniFinalizar();
}
//############################################################################################################################################



//############################################################################################################################################
void Jogo::executar(){   while(!gEventos.sair && runningMain){
		
	uniIniciarFrame();

	//### MENUS ###
	if(runningMenu!="0"){
			 if(runningMenu=="main"){      methodMenuMain(); }
		else if(runningMenu=="opcoes"){    methodMenuOpcoes(); }
		else if(runningMenu=="jogadores"){ methodMenuJogadores(); }
		else if(runningMenu=="nomes"){     methodMenuNomes(); }
		else if(runningMenu=="pause"){     methodMenuPause(); }
		else if(runningMenu=="ganhador"){  methodMenuGanhador(); }
		else if(runningMenu=="empate"){    methodMenuEmpate(); }
		else if(runningMenu=="regras"){    methodMenuRegras(); }
		else if(runningMenu=="creditos"){  methodMenuCredits(); }
	}

	//### GAMES ###
	else if(runningGame!="0"){

		//SCORE
		if(gTeclado.segurando[TECLA_TAB]){ methodMenuScore(); }

		//ZOMBIE DICE - TRADICIONAL
		else if(runningGame=="zd1"){ methodGameZD1(); }

		//ZOMBIE DICE - DOSE DUPLA
		else if(runningGame=="zd2"){ methodGameZD1(); }

		//ZOMBIE DICE - ÔNIBUS ESCOLAR
		else if(runningGame=="zd3"){ methodGameZD1(); }
	}

	uniTerminarFrame();
}}
//############################################################################################################################################



//############################################################################################################################################
void Jogo::checkWinner(){

	int i=0;
	
	for(i=0; i<4; i++){  if(jogador[i].getStatus() && jogador[i].getCerebrosTotal()>=13){
		//Empate
		if(gameHigherPoints>0 && jogador[i].getCerebrosTotal()==gameHigherPoints){
			gameWinners++;   }
		//Ganhador
		else if(jogador[i].getCerebrosTotal()>gameHigherPoints){
			gameWinners=1;
			gameHigherPoints=jogador[i].getCerebrosTotal();   }
	}}

	//Eliminados
	if(gameWinners>0){   for(i=0; i<4; i++){
		if(jogador[i].getStatus() && jogador[i].getCerebrosTotal()<gameHigherPoints){  jogador[i].eliminar();  }   }}

	//Ganhador
	if(gameWinners==1){
		runningMenu="ganhador"; }

	//Empate
	else if(gameWinners>1){
		runningMenu="empate"; }
}
//############################################################################################################################################



//############################################################################################################################################
void Jogo::methodMenuMain(){   switch(menuMain.run()){

	//ZOMBIE DICE - TRADICIONAL
	case 0:
		runningMenu="jogadores";
		runningGame="zd1";
		gameInterfaceScore.setGame("Zombie Dice - Tradicional");
		gameInterfaceControl.clear();
		gameInterfaceControl.addItem("Jogar");
		gameInterfaceControl.addItem("Parar");
		gameWinners=0;
		gameHigherPoints=0;
	break;

	//ZOMBIE DICE - DOSE DUPLA
	case 1:
		runningMenu="jogadores";
		runningGame="zd2";
		gameInterfaceScore.setGame("Zombie Dice - Dose Dupla");
		gameInterfaceControl.clear();
		gameInterfaceControl.addItem("Jogar");
		gameInterfaceControl.addItem("Parar");
		gameWinners=0;
		gameHigherPoints=0;
	break;

	//ZOMBIE DICE - ÔNIBUS ESCOLAR
	case 2:
		runningMenu="jogadores";
		runningGame="zd3";
		gameInterfaceScore.setGame("Zombie Dice - Ônibus Escolar");
		gameInterfaceControl.clear();
		gameInterfaceControl.addItem("Jogar");
		gameInterfaceControl.addItem("Parar");
		gameInterfaceControl.addItem("Entrar no Ônibus");
		gameWinners=0;
		gameHigherPoints=0;
	break;

	//OPÇÕES
	case 3:
		runningMenu="opcoes";
	break;

	//CREDITOS
	case 4:
		runningMenu="creditos";
	break;

	//SAIR
	case 5:
		runningMain=false;
	break;
}}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuOpcoes(){   switch(menuOpcoes.run()){

	//AUDIO
	case 0:
		extern bool optionAudio;
		if(optionAudio){
			menuOpcoes.setItem(0, "Audio: Desligado");
			gMusica.pausar();
			optionAudio=false; }
		else{
			menuOpcoes.setItem(0, "Audio: Ligado");
			gMusica.continuar();
			optionAudio=true; }
	break;

	//VOLTAR
	case 1:
		runningMenu="main";
	break;
}}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuJogadores(){   switch(menuJogadores.run()){

	//JOGADOR vs COMPUTADOR
	case 0:
		jogador[0].initialize("Jogador", "HUMANO");
		jogador[1].initialize("Computador", "PC");
		jogador[2].clear();
		jogador[3].clear();
		runningMenu="nomes";
	break;

	//2 JOGADORES
	case 1:
		jogador[0].initialize("Jogador 1", "HUMANO");
		jogador[1].initialize("Jogador 2", "HUMANO");
		jogador[2].clear();
		jogador[3].clear();
		runningMenu="nomes";
	break;

	//3 JOGADORES
	case 2:
		jogador[0].initialize("Jogador 1", "HUMANO");
		jogador[1].initialize("Jogador 2", "HUMANO");
		jogador[2].initialize("Jogador 3", "HUMANO");
		jogador[3].clear();
		runningMenu="nomes";
	break;

	//4 JOGADORES
	case 3:
		jogador[0].initialize("Jogador 1", "HUMANO");
		jogador[1].initialize("Jogador 2", "HUMANO");
		jogador[2].initialize("Jogador 3", "HUMANO");
		jogador[3].initialize("Jogador 4", "HUMANO");
		runningMenu="nomes";
	break;

	//REGRAS
	case 4:
		runningMenu="regras";
	break;

	//VOLTAR
	case 5:
		runningMenu="main";
	break;
}}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuNomes(){
	
	//NOMES -> MENU
	for(int i=0; i<4; i++){
		string temp="";   if(jogador[i].getStatus()){   temp="#"+to_string(i+1)+": "+jogador[i].getNome();   }
		menuNomes.setItem((i+1), temp);   }

	//INPUT TEXTO
	if(menuNomes.getPointer()>=1 && menuNomes.getPointer()<=4 && jogador[menuNomes.getPointer()-1].getJogando()){

		//GET NOME
		string jogadorNome = jogador[menuNomes.getPointer()-1].getNome();
		
		//DELETAR LETRA
		if(gTeclado.pressionou[TECLA_VOLTAR] || gTeclado.pressionou[TECLA_DELETE]){
			jogadorNome=jogadorNome.substr(0, jogadorNome.size()-1);
			gTeclado.pressionou[TECLA_VOLTAR]=false;   }

		//ADICIONA LETRA   // 4 - 29 (TECLA_A TECLA_Z)
		for(int tecla=4; tecla<=29; tecla++){ if(gTeclado.pressionou[tecla]){
			//65 - 90 (AZ)
			if(gTeclado.segurando[TECLA_SHIFT_ESQ] || gTeclado.segurando[TECLA_SHIFT_DIR]){
				jogadorNome+=tecla+61; }
			//97 - 122 (az)
			else{
				jogadorNome+=tecla+93; }
		}}

		//SALVA NOME
		jogador[menuNomes.getPointer()-1].setNome(jogadorNome);
		
		//BLINK CURSOR
		cursorBlink++;  if(cursorBlink>60){ cursorBlink=0; }
		if(cursorBlink<30){ jogadorNome+="|"; }else{ jogadorNome+=" "; }
		menuNomes.setItem(menuNomes.getPointer(), jogadorNome);
	}

	//MENU RUN
	switch(menuNomes.run()){

		//JOGAR
		case 0:
			runningMenu="0";
			jogadorAtual=0;
			jogador[jogadorAtual].roundStart();
			extern bool optionAudio;
			if(optionAudio){ gMusica.tocar("musicGame", true, 0.5); }
		break;

		//VOLTAR
		case 5:
			runningMenu="jogadores";
		break;
	}
}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuPause(){   switch(menuPause.run()){

	//VOLTAR PARA O WINDOWS
	case 0:
		runningMain=false;
	break;

	//SAIR DO JOGO
	case 1:
		runningMenu="main";
		runningGame="0";
		extern bool optionAudio;
		if(optionAudio){ gMusica.tocar("musicMenu", true, 0.5); }
	break;

	//CONTINAUR
	case 2:
		runningMenu="0";
	break;
}}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuScore(){
	
	string temp;

	menuScore.setItem(0, "     Score:     ");
	
	//NOMES -> MENU
	for (int i = 0; i<4; i++){
		temp = "";   if (jogador[i].getStatus()) { temp = "#" + to_string(i + 1) + ": " + jogador[i].getNome() + "     " + to_string(jogador[i].getCerebrosTotal()) + " cerebros"; }
		menuScore.setItem((i + 2), temp);
	}

	menuScore.run();
}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuGanhador(){
	
	string temp;
	
	//GANHADOR
	for(int i=0; i<4; i++){   if(jogador[i].getStatus() && jogador[i].getCerebrosTotal()==gameHigherPoints){  temp=jogador[i].getNome(); break;  }   }
	menuGanhador.setItem(0, "   "+temp+" comeu mais cerebros!   ");

	//NOMES -> MENU
	for(int i=0; i<4; i++){
		temp="";   if(jogador[i].getStatus()){   temp="#"+to_string(i+1)+": "+jogador[i].getNome()+"     "+to_string(jogador[i].getCerebrosTotal())+" cerebros";   }
		menuGanhador.setItem((i+2), temp);   }


	menuGanhador.setPointer(10);
	if(menuGanhador.run() != -1){
		runningMenu="main";
		extern bool optionAudio;
		if(optionAudio){ gMusica.tocar("musicMenu", true, 0.5); }
	}
}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuEmpate(){
	
	string temp;

	//NOMES -> MENU
	for(int i=0; i<4; i++){
		temp="";   if(jogador[i].getStatus()){   temp="#"+to_string(i+1)+": "+jogador[i].getNome()+"   "+to_string(jogador[i].getCerebrosTotal());   }
		menuEmpate.setItem((i+2), temp);   }

	menuEmpate.setPointer(10);
	if(menuEmpate.run() != -1){
		runningMenu="0"; }
}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodGameZD1(){
	
	//INTERFACE BACKGROUND
	gameInterfaceBackground.run(jogadorAtual);

	//INTERFACE TABLE
	gameInterfaceTable.run(jogador[jogadorAtual]);

	//INTERFACE SCORE
	gameInterfaceScore.run(jogador[jogadorAtual]);

	//INTERFACE CONTROL
	switch(gameInterfaceControl.run(jogador[jogadorAtual].autoPlay())){

		//CONTINUAR
		case 0:
			if(!jogador[jogadorAtual].roundCheckEnd()){
				soundFXTimeLine=0;
				jogador[jogadorAtual].roundContinue(); }
			else{
				gameInterfaceControl.setPointer(1); }
		break;

		//PARAR
		case 1:
			//Jogador Atual
			jogador[jogadorAtual].roundStop();

			//Proximo Jogador
			do{
				jogadorAtual=(jogadorAtual+1)%4;
				/*WINNER*/if(jogadorAtual==0){ this->checkWinner(); }
			}while(!jogador[jogadorAtual].getStatus() || !jogador[jogadorAtual].getJogando());
			jogador[jogadorAtual].roundStart();
			gameInterfaceControl.setPointer(0);
			gameInterfaceTable.reset();
		break;

		//PAUSE
		case -2:
			runningMenu="pause";
		break;
	}

	//SOUND FX
	extern bool optionAudio;
	if(optionAudio && soundFXTimeLine<=soundFXInterval*3 && !jogador[jogadorAtual].roundCheckEnd()){
		extern Som soundDado[3];
		for(int i=0; i<3; i++){
			if((soundFXTimeLine==soundFXInterval*i+20) && (jogador[jogadorAtual].getHand(i) != -1)){
				soundDado[i].tocar();
			}
		}
		soundFXTimeLine++;
	}
}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodGameZD2(){
}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodGameZD3(){
}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuRegras(){

	//FIX POINTER
	menuRegras.setPointer(10);
	
	//VOLTAR
	if(menuRegras.run()!=-1){
		runningMenu="jogadores"; }


	//GAME
	int index=0;
		 if(runningGame=="zd1"){ index=0; }
	else if(runningGame=="zd2"){ index=1; }
	else if(runningGame=="zd3"){ index=2; }

	//DRAW
	menuRegrasTexto[index].desenhar(100, 50);

}
//############################################################################################################################################

//############################################################################################################################################
void Jogo::methodMenuCredits(){

	//FIX POINTER
	/*if(menuCredits.getPointer()<7){
		menuCredits.setPointer(8); }*/

	//PROXIMA
	if(menuCredits.run()==9){
		menuCreditsPage=(menuCreditsPage+1)%14; }
	//VOLTAR
	else if(menuCredits.run()!=-1){
		runningMenu="main"; }

	//DRAW
	menuCreditsTexto[menuCreditsPage][0].desenhar(100,  50);
	menuCreditsTexto[menuCreditsPage][1].desenhar(gJanela.getLargura()/2, 225);
	menuCreditsTexto[menuCreditsPage][2].desenhar(100, 350);
	menuCreditsTexto[menuCreditsPage][3].desenhar(135, 400);

}
//############################################################################################################################################




