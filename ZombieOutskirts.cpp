#include "ZombieOutskirts.h"
#include"Level.h"

ZombieOutskirts::ZombieOutskirts(int cLevel, int playerInfo) {
	currentLevel = cLevel;
	playerInfoIndex = playerInfo;
	suncurrency = 1000;
	lives = 3;
	zombieKilled = 0;
	playerScore = 0;

	plants = new PlantsFactory(currentLevel);
	zombie = new ZombieFactory(currentLevel);
	lawnmover = new LawnMover * [5];
	for (int i = 0; i < 5; i++) {
		lawnmover[i] = new LawnMover(320, i * 125 + 100);
	}
}