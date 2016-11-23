#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

#include "MenuItem.h"

class GameInterfaceControl
{
	public:
		GameInterfaceControl();
		~GameInterfaceControl();

		void inicializar();
		void clear();
		void addItem(string item);
		void setItem(int item, string texto);

		void setPointer(int pointer);

		int run(int autoPlay);

	private:
		void drawBackground();
		Sprite background;
		
		int itens;
		int pointer;
		MenuItem item[3];
		//Texto item[3];
		Texto pointerText;

		int mouseLastX;
		int mouseLastY;
};


