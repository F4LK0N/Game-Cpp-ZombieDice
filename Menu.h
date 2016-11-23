#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

#include "MenuItem.h"
#include "Jogador.h"

class Menu
{
	public:
		Menu();
		~Menu();
		
		void setBackground(string sprite);
		
		void addItem(string item);
		void setItem(int item, string texto);
		
		void setPointer(int pos);
		int getPointer();
		
		int run();

		void stop();

	private:
		Sprite background;
	
		int itens; //NUMERO DE ITENS DO MENU
		MenuItem item[10];
		
		int pointer;
		Texto pointerText;

		Som soundClick;

		int mouseLastX;
		int mouseLastY;
};
