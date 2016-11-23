#pragma once
#include <string>
using namespace std;

#include "libUnicornio.h"

class GameInterfaceBackground
{
	public:
		GameInterfaceBackground();
		~GameInterfaceBackground();

		void inicializar();
		void setBackground(int background, string sprite);
	
		void run(int background);
	
	private:
		Sprite background[4];
};

