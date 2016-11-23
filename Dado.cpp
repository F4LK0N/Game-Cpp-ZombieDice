#include "Dado.h"

Dado::Dado(){}

Dado::~Dado(){}


void Dado::start(string tipo){
	this->tipo=tipo;
	this->local="POTE";
}

void Dado::reset(){
	this->local="POTE";
}

string Dado::getTipo(){
	return this->tipo; 
}

string Dado::getFace(){
	return this->face; 
}

string Dado::getLocal(){
	return this->local;
}

void Dado::setLocal(string local){
	this->local=local;
}


void Dado::roll(int handPos){
	
	extern Som soundDado[3];
	soundDado[handPos].parar();
	
	rand(); rand(); rand();
	int random=rand()%6;

	if(tipo=="VERDE"){
		/* 1 2 3 4 */if(random<4){ face="CEREBRO";  soundDado[handPos].setAudio("somCerebro");   }
		/* 5 */ else if(random<5){ face="FUGA";     soundDado[handPos].setAudio("somFuga");      }
		/* 6 */ else{              face="TIRO";     soundDado[handPos].setAudio("somTiroVerde"); }
	}

	else if(tipo=="AMARELO"){
		/* 1 2 */     if(random<2){ face="CEREBRO";  soundDado[handPos].setAudio("somCerebro");     }
		/* 3 4 */else if(random<4){ face="FUGA";     soundDado[handPos].setAudio("somFuga");        }
		/* 5 6 */else{              face="TIRO";     soundDado[handPos].setAudio("somTiroAmarelo"); }
	}

	else if(tipo=="VERMELHO"){
		/* 1 2 3 4 */if(random<4){ face="TIRO";     soundDado[handPos].setAudio("somTiroVermelho"); }
		/* 5 */ else if(random<5){ face="FUGA";     soundDado[handPos].setAudio("somFuga");         }
		/* 6 */ else{              face="CEREBRO";  soundDado[handPos].setAudio("somCerebro");      }
	}

}





