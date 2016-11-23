#include "Pote.h"



Pote::Pote(){
	for(int i=0; i<13; i++){
		if(i<6){
			dado[i].start("VERDE"); }
		else if(i<10){
			dado[i].start("AMARELO"); }
		else{
			dado[i].start("VERMELHO"); }
	}
}


Pote::~Pote(){}


void Pote::start(){
	for(int i=0; i<13; i++){
		dado[i].reset(); }
	dadosDisponiveis=13;
}

int Pote::getDadoRandom()
{
	//ERROR
	if(dadosDisponiveis<1){ return -1; }
	

	//SORTEIA DADO UTILIZANDO SOMENTE OS DADOS VALIDOS
	int dadoNumberCount=0;
	int dadoNumber = rand()%dadosDisponiveis;
	dadosDisponiveis--;

	for(int i=0; i<13; i++){
		if(dado[i].getLocal()=="POTE"){
			if(dadoNumberCount==dadoNumber){
				dado[i].setLocal("HAND");
				//dado[i].roll();//Esta linha se tornou desnecessaria apos a ultima modificação para o audio. Avaliar logica de funcionamento sem ela.
				return i; }
			dadoNumberCount++;
		}
	}


	//ERROR
	return -2;
}

int Pote::getDadosDisponiveis(){
	return this->dadosDisponiveis;
}

void Pote::refill(){
	for(int i=0; i<13; i++){
		if(dado[i].getFace()!="FUGA" && dado[i].getLocal()!="HAND"){
			dado[i].setLocal("POTE");
			dadosDisponiveis++; }
	}
}


string Pote::getDadoTipo(int dado){
	return this->dado[dado].getTipo();
}

string Pote::getDadoFace(int dado){
	return this->dado[dado].getFace();
}

string Pote::getDadoLocal(int dado){
	return this->dado[dado].getLocal();
}

void Pote::setDadoLocal(int dado, string local){
	this->dado[dado].setLocal(local);
}

void Pote::dadoRoll(int dado, int handPos){
	this->dado[dado].roll(handPos);
}


