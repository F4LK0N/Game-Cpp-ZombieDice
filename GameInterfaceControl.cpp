#include "GameInterfaceControl.h"

GameInterfaceControl::GameInterfaceControl(){
	itens=0;
	pointer=0;
	pointerText.setString("->");
	pointerText.setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
	pointerText.setAncora(0, 0);
	pointerText.setLarguraMaxima(0);
	mouseLastX = -99999;
	mouseLastY = -99999;
}

GameInterfaceControl::~GameInterfaceControl(){}

void GameInterfaceControl::inicializar()
{
	//BACKGROUND
	background.setSpriteSheet("backgroundWallBlack");
	background.setAncora(0, 0);
}

void GameInterfaceControl::clear(){
	this->itens=0;
}

void GameInterfaceControl::addItem(string item){
	if(itens<3){
		this->pointerText.setFonte("fonteArial");

		int marginLeft=(gJanela.getLargura()/12);
		int posX = marginLeft+pointerText.getLargura();
		if(itens>0){ posX+=this->item[itens-1].getX()+this->item[itens-1].getLargura(); }
		this->item[itens].inicializar(item, posX, gJanela.getAltura()-((gJanela.getAltura()/12)*1.1));
		
		itens++;
	}
}

void GameInterfaceControl::setItem(int item, string texto){
	this->item[item].setString(texto);
}

void GameInterfaceControl::setPointer(int pointer)
{
	if(pointer<0){ pointer=0; }else if(pointer>itens-1){ pointer=itens-1; }

	this->pointer=pointer;
}

int GameInterfaceControl::run(int autoPlay){

	//###############################################
	// BACKGROUND
	//###############################################
	this->drawBackground();
	//###############################################


	//###############################################
	// DRAW
	//###############################################
	for(int i=0; i<itens; i++){
		if(pointer==i){ pointerText.desenhar(this->item[i].getX()-pointerText.getLargura()-(gJanela.getLargura()/100), gJanela.getAltura()-((gJanela.getAltura()/12)*1) ); }
		item[i].draw();
	}
	//###############################################
	
	
	//CONTROL - PC
	if(autoPlay!=-1){
		pointer=autoPlay;
	}

	//CONTROL - HUMANO
	else{
		//###############################################
		// CONTROL - KEYBOARD
		//###############################################
		//UP
		if(gTeclado.pressionou[TECLA_ESQ] && pointer>0){
			pointer--; }
		//DOWN
		else if(gTeclado.pressionou[TECLA_DIR] && pointer+1<itens){
			pointer++; }
		//###############################################



		//###############################################
		// CONTROL - MOUSE
		//###############################################
		for(int i=0; i<itens; i++){
			if(item[i].mouseOver()){
				/* POINTED  */if(gMouse.x!=mouseLastX || gMouse.y!=mouseLastY){ pointer=i; }
				/* SELECTED */if(gMouse.pressionou[BOTAO_MOUSE_ESQ]){ pointer=i;  return pointer; }
			}
		}
		mouseLastX = gMouse.x;
		mouseLastY = gMouse.y;
		//###############################################
	}
	
	
	//###############################################
	// SELECTED - KEYBOARD
	//###############################################
	if(gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2] || gTeclado.pressionou[TECLA_ESPACO]){
		return pointer; }
	else if(gTeclado.pressionou[TECLA_ESC]){
		return -2; }
	else{
		return -1; }
	//###############################################
}

void GameInterfaceControl::drawBackground()
{
	background.desenhar(0, (gJanela.getAltura()/12)*10.5);
}

