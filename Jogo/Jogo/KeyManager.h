#pragma once
#include "game.h"

class KeyManager {
public:
	
	void checkMovement();	

private:
	bool cima, baixo, esquerda, direita;
};