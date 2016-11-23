#include "GameInterfaceBackground.h"



GameInterfaceBackground::GameInterfaceBackground()
{
}


GameInterfaceBackground::~GameInterfaceBackground()
{
}

void GameInterfaceBackground::inicializar()
{
	for(int i=0; i<4; i++){
		background[i].setSpriteSheet("gameBackground"+to_string(i+1));
	}
}

void GameInterfaceBackground::setBackground(int background, string sprite)
{
	this->background[background].setSpriteSheet(sprite);
}

void GameInterfaceBackground::run(int background)
{
	this->background[background].desenhar(gJanela.getLargura()/2, gJanela.getAltura()/2);
}
