#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

//OPTIONS
bool optionAudio;

//SOUND - FX
Som soundDado[3];

#include "Menu.h"
#include "Dado.h"
#include "Pote.h"
#include "Jogador.h"
#include "Jogo.h"

int main(int argc, char* argv[])
{
	Jogo jogo;
	jogo.inicializar();
	jogo.executar();
	jogo.finalizar();

	return 0;
}