#include "GameInterfaceScore.h"



GameInterfaceScore::GameInterfaceScore(){}

GameInterfaceScore::~GameInterfaceScore(){}

void GameInterfaceScore::inicializar()
{
	game.setFonte("fonteTheDeadAreComingMini");
	game.setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
	game.setLarguraMaxima(0);
	game.setString("");
	game.setAncora(0, 0);
	game.setCorAzul(0, true);
	game.setCorVerde(0, true);
	game.setCorVermelho(100, true);

	jogador.setFonte("fonteExquisiteCorpseBig");
	jogador.setAlinhamento(TEXTO_CENTRALIZADO);
	jogador.setLarguraMaxima(0);
	jogador.setString("");
	jogador.setCorAzul(25, true);
	jogador.setCorVerde(25, true);
	jogador.setCorVermelho(180, true);

	score.setFonte("fonteExquisiteCorpse");
	score.setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
	score.setAncora(0, 0);
	score.setLarguraMaxima(0);
	score.setString("");
	score.setCorAzul(25, true);
	score.setCorVerde(25, true);
	score.setCorVermelho(180, true);

	gameBackground.setSpriteSheet("mask");
	gameBackground.setAncora(0, 0);

	scoreBackground.setSpriteSheet("maskTopBottom");
	scoreBackground.setAncora(0, 0);
}

void GameInterfaceScore::setGame(string game)
{
	this->game.setString(game);
}

void GameInterfaceScore::run(Jogador jogador)
{
	//SCORE BACKGROUND
	scoreBackground.desenhar(0, (gJanela.getAltura()/12*2)-scoreBackground.getAltura());
	
	//GAME
	gameBackground.desenhar(0, (gJanela.getAltura()/12*0.7)-gameBackground.getAltura());
	game.desenhar(gJanela.getLargura()/12*0.3, gJanela.getAltura()/12*0.2);


	//JOGADOR
	this->jogador.setString(jogador.getNome());
	this->jogador.desenhar(gJanela.getLargura()/2, gJanela.getAltura()/12*1.35);


	//SCORE
	string temp="";
	temp="Cerebros: "+to_string(jogador.cerebrosTotal);
	if(jogador.cerebrosParcial>0){ temp+="("+to_string(jogador.cerebrosParcial)+")"; }
	temp+="     ";
	temp+="Tiros: "+to_string(jogador.tiros);

	score.setString(temp);
	score.desenhar(gJanela.getLargura()/12*0.22, gJanela.getAltura()/12*1.5);


	//ACESSORIOS
	//...(Capacete, Energético, Etc...)...

}
