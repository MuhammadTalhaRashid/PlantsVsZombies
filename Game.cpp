#include "Game.h"
#include<iostream>
#include"Level.h"
#include"BeginnersGarden.h"
#include"ZombieOutskirts.h"
#include"FoggyForest.h"
#include"SunflowerFields.h"
using namespace std;

Game::Game() {
	level = NULL;
}
int Game::play(int playerinfo, int clevel, RenderWindow& window, int (*gameGrid)[11]) {
	playerInfoIndex = playerinfo;

	if (clevel == -1) {
	//file level loading
		//currentLevel = 
		level = new Level(currentLevel, playerInfoIndex);
		level->setLevel(playerInfoIndex);
	}
	else if (clevel == 1) {
		currentLevel = clevel;
		level = new BeginnersGarden(1, playerInfoIndex, window);
	}
	else if (clevel == 2) {
		currentLevel = clevel;
		level = new ZombieOutskirts(2, playerInfoIndex);
	}
	else if (clevel == 3) {
		currentLevel = clevel;
		level = new SunflowerFields(3, playerInfoIndex);
	}
	else if (clevel == 4) {
		currentLevel = clevel;
		level = new FoggyForest(4, playerInfoIndex);
	}
	//else if (clevel == 5) {
		//currentLevel = clevel;
		//level = new Level(5, playerInfoIndex);
	//}
	
	int situation = 0;
	while (!situation) {
		
		level->draw(window, gameGrid);
		window.display();
		window.clear();

		situation = level->play(gameGrid);
		if (situation == -1)
			return -1;
	}
	delete level;
	return situation;
}
Game::~Game() {
	delete level;
}