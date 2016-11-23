#include "MenuItem.h"



MenuItem::MenuItem()
{
}


MenuItem::~MenuItem()
{
}

void MenuItem::inicializar(string texto, int x, int y)
{
	//TEXTO
	this->texto.setString(texto);
	this->texto.setFonte("fonteBlackAsylum");
	this->texto.setAlinhamento(TEXTO_ALINHADO_A_ESQUERDA);
	this->texto.setAncora(0, 0);
	this->texto.setLarguraMaxima(0);

	//PADDINGS
	this->paddingLeft  =12;
	this->paddingRight =15;
	this->paddingTop   =7;
	this->paddingBottom=5;

	//POS
	this->x=x;
	this->y=y;
	
	//SIZE
	this->largura = paddingLeft + this->texto.getLargura() + paddingRight;
	this->altura  = paddingTop  + this->texto.getAltura()  + paddingBottom;
}

void MenuItem::setString(string texto)
{
	//TEXTO
	this->texto.setString(texto);

	//SIZE
	this->largura = paddingLeft + this->texto.getLargura() + paddingRight;
	this->altura  = paddingTop  + this->texto.getAltura()  + paddingBottom;
}

int MenuItem::getX()
{
	return this->x;
}

int MenuItem::getLargura()
{
	return this->largura;
}

void MenuItem::draw()
{
	if(texto.getLargura()<1){ return; }
	
	Retangulo retangulo;
	retangulo.x=this->x;   retangulo.y=this->y;   retangulo.largura=this->largura;   retangulo.altura=this->altura;

	//BORDA
	Cor corBorda(50, 50, 50);
	gGraficos.desenharRetangulo(retangulo, corBorda.r, corBorda.g, corBorda.b);

	//PREENCHIMENTO
	retangulo.x++;   retangulo.y++;   retangulo.largura-=2;   retangulo.altura-=2;
	Cor corPreenchimento(100, 100, 100);
	while(retangulo.altura>0){
		gGraficos.desenharRetangulo(retangulo, corPreenchimento.r-retangulo.altura, corPreenchimento.g-retangulo.altura, corPreenchimento.b-retangulo.altura);
		retangulo.altura--;
	}

	//TEXTO
	texto.desenhar(this->x+paddingLeft, this->y+paddingTop);
}

bool MenuItem::mouseOver()
{
	if( (texto.getLargura()>0)
	 && (gMouse.x >= this->x) && (gMouse.x <= this->x+this->largura) 
	 && (gMouse.y >= this->y) && (gMouse.y <= this->y+this->altura) ){
		return true; }
	else{
		return false; }
}
