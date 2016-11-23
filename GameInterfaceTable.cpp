#include "GameInterfaceTable.h"



GameInterfaceTable::GameInterfaceTable(){}

GameInterfaceTable::~GameInterfaceTable(){}

void GameInterfaceTable::inicializar()
{
	//HAND TEXT
	for(int i=0; i<3; i++){
		handText[i].setFonte("fonteArial");
		handText[i].setAlinhamento(TEXTO_CENTRALIZADO);
		handText[i].setLarguraMaxima(0);
	}
	//HAND SPRITE
	string corName, faceName;
	for(int cor=0; cor<3; cor++){
		for(int face=0; face<3; face++){
			switch(cor){
				case 0:  corName="VERDE";     break;
				case 1:  corName="AMARELO";   break;
				case 2:  corName="VERMELHO";  break;
			}
			switch(face){
				case 0:  faceName="CEREBRO";  break;
				case 1:  faceName="FUGA";     break;
				case 2:  faceName="TIRO";     break;
			}
			handSprite[cor][face].setSpriteSheet("dado"+corName+"-"+faceName);
		}
	}
	

	//TABLE TEXT
	for(int i=0; i<10; i++){
		tableText[i].setFonte("fonteArial");
		tableText[i].setAlinhamento(TEXTO_CENTRALIZADO);
		tableText[i].setAncora(0, 0);
		tableText[i].setLarguraMaxima(0);
		tableText[i].setEscala(0.4, 0.4);
	}
	//TABLE SPRITE
	//string corName, faceName;
	for(int cor=0; cor<3; cor++){
		for(int face=0; face<3; face++){
			switch(cor){
				case 0:  corName="VERDE";     break;
				case 1:  corName="AMARELO";   break;
				case 2:  corName="VERMELHO";  break;
			}
			switch(face){
				case 0:  faceName="CEREBRO";  break;
				case 1:  faceName="FUGA";     break;
				case 2:  faceName="TIRO";     break;
			}
			tableSprite[cor][face].setSpriteSheet("dado"+corName+"-"+faceName);
			tableSprite[cor][face].setEscala(0.3, 0.3);
		}
	}


	//DEAD TEXT 0
	deadText[0].setFonte("fonteYouMurderedBig");
	deadText[0].setAlinhamento(TEXTO_CENTRALIZADO);
	deadText[0].setLarguraMaxima(0);
	deadText[0].setCorVermelho(200, true);
	deadText[0].setCorVerde(0, true);
	deadText[0].setCorAzul(0, true);
	deadText[0].setString("VOCE MORREU }");
	//DEAD TEXT 1
	deadText[1].setFonte("fonteYouMurdered");
	deadText[1].setAlinhamento(TEXTO_CENTRALIZADO);
	deadText[1].setLarguraMaxima(0);
	deadText[1].setCorVermelho(200, true);
	deadText[1].setCorVerde(0, true);
	deadText[1].setCorAzul(0, true);
	deadText[1].setString("{ Tente novamente na proxima rodada!");
	//DEAD SPRITE
	deadSprite.setSpriteSheet("spriteDead");
	deadBackground.setSpriteSheet("mask");
	deadBackground.setCorAlpha(200);
	//DEAD SOUND
	deadSound.setAudio("somDead");
	deadSound.setVolume(1.00);
	deadSoundPlayed=false;
}

void GameInterfaceTable::reset()
{
	deadSoundPlayed=false;
}


		


void GameInterfaceTable::run(Jogador jogador)
{
	//TABLE
	this->tableDraw(jogador);
	
	//HAND
	this->handDraw(jogador);

	//DEAD
	this->deadDraw(jogador);
}

void GameInterfaceTable::handDraw(Jogador jogador)
{
	int dado;
	int cor;    string corStr;
	int face;   string dadoFace;

	for(int pos=0; pos<3; pos++){
		
		dado = jogador.getHand(pos);

		if(dado!=-1){
	
			corStr=jogador.getDadoTipo(dado);
				 if(corStr=="VERDE"){    cor=0;  }
			else if(corStr=="AMARELO"){  cor=1;  }
			else if(corStr=="VERMELHO"){ cor=2;  }
			else{                        cor=-1; }

			dadoFace=jogador.getDadoFace(dado);
				 if(dadoFace=="CEREBRO"){ face=0;  }
			else if(dadoFace=="FUGA"){    face=1;  }
			else if(dadoFace=="TIRO"){    face=2;  }
			else{                         face=-1; }
	
			if(cor>=0 && face>=0){ handSprite[cor][face].desenhar(((gJanela.getLargura()/6)*(2+pos)), ((gJanela.getAltura()/12)*5)); }
		}
	}
}

void GameInterfaceTable::tableDraw(Jogador jogador)
{
	int dado;
	int cor;    string corStr;
	int face;   string dadoFace;

	for(int pos=0; pos<10; pos++){

		dado = jogador.getTable(pos);

		if(dado!=-1){

			corStr=jogador.getDadoTipo(dado);
			if(corStr=="VERDE"){    cor=0;  }
			else if(corStr=="AMARELO"){  cor=1;  }
			else if(corStr=="VERMELHO"){ cor=2;  }
			else{                        cor=-1; }

			dadoFace=jogador.getDadoFace(dado);
			if(dadoFace=="CEREBRO"){ face=0;  }
			else if(dadoFace=="FUGA"){    face=1;  }
			else if(dadoFace=="TIRO"){    face=2;  }
			else{                         face=-1; }

			if(cor>=0 && face>=0){ tableSprite[cor][face].desenhar(((gJanela.getLargura()/13)*(2+pos)), ((gJanela.getAltura()/12)*8)); }
		}
	}
}

void GameInterfaceTable::deadDraw(Jogador jogador)
{
	if(jogador.roundCheckEnd()){
		deadBackground.desenhar(gJanela.getLargura()/2, gJanela.getAltura()/2);
		deadSprite.desenhar(gJanela.getLargura()/2, (gJanela.getAltura()/12)*6.5);
		deadText[0].desenhar(gJanela.getLargura()/2, (gJanela.getAltura()/12)*4);
		deadText[1].desenhar(gJanela.getLargura()/2, (gJanela.getAltura()/12)*9);
		extern bool optionAudio;
		if(optionAudio && !deadSoundPlayed){
			deadSoundPlayed=true;
			extern Som soundDado[3];
			for(int i=0; i<3; i++){ soundDado[i].setVolume(0.0); }
			deadSound.tocar();
		}
	}
}




