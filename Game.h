#pragma once
#include<iostream>
#include"Level.h"
using namespace std;
class Game
{
protected:
	int playerInfoIndex;
	int currentLevel;
	Level* level;
	FileHandling fileHandling;
public:
	Game();
	int play(int, int, RenderWindow& window, int(*gameGrid)[11]);

	~Game();
};

