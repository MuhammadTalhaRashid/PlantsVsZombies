#include "Level.h"

Level::Level()
{

}
Level::Level(int cLevel, int playerInfo = 0) {
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

int Level::play(int(*gameGrid)[11]) {
	plants->play(suncurrency);
	zombie->spawZombies(currentLevel);
	zombie->moveAllZombies();
	
	int reachedEnd = zombie->reachedEnd();
	if (reachedEnd == 1 || reachedEnd == 2 || reachedEnd == 3 || reachedEnd == 4 || reachedEnd == 0) {
		if (lawnmover[reachedEnd] != NULL)
			lawnmover[reachedEnd]->startMoving();
		else
			lives -= 1;
	}
	int check = 0;
	for (int i = 0; i < 5; i++) {
		check = 0;
		if (lawnmover[i] != NULL) {
			check = lawnmover[i]->move(gameGrid, newPlants, newzombie);
		}
		if (check == -1) {
			delete lawnmover[i];
			lawnmover[i] = NULL;
		}
			
	}
	checkCollision();

	if (lives == 0)
		return -1;
	else if (zombieKilled == 20)
		return 1;
	else 
		return 0;
}

void Level::draw(RenderWindow& window, int(*gameGrid)[11]) {
	//level screens draw
	
	filehandling.createScreens(window, currentLevel);
	zombie->renderAllZombies(window);
	plants->drawPlant(window, suncurrency);

	// Load font and create the text object
	sf::Font font;
	if (!font.loadFromFile("D:\\Oop Project\\ARIALN.ttf")) {
		// Handle font loading failure
		std::cerr << "Failed to load font!" << std::endl;
		return;
	}

	{
		sf::Text sunText;
		sunText.setFont(font);
		sunText.setCharacterSize(40);
		sunText.setFillColor(sf::Color::Black);
		sunText.setPosition(10, 84);
		sunText.setString(std::to_string(suncurrency));

		// Apply style and outline to the text
		sunText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		sunText.setOutlineColor(sf::Color::White);
		sunText.setOutlineThickness(2);

		// Create a background rectangle behind the text
		sf::RectangleShape backgroundRect;
		backgroundRect.setSize(sf::Vector2f(sunText.getGlobalBounds().width + 20, sunText.getGlobalBounds().height + 10));
		backgroundRect.setFillColor(sf::Color(255, 255, 255, 200));  // Semi-transparent white
		backgroundRect.setPosition(sunText.getPosition().x - 10, sunText.getPosition().y + 9);

		// Draw the background rectangle and the text
		window.draw(backgroundRect);
		window.draw(sunText);
	}
	{
		sf::Font font1;
		if (!font1.loadFromFile("D:\\Oop Project\\ARIALN.ttf")) {
			// Handle font loading failure
			std::cerr << "Failed to load font!" << std::endl;
			return;
		}

		sf::Text scoreText;
		scoreText.setFont(font1);
		scoreText.setCharacterSize(40);
		scoreText.setFillColor(sf::Color::Black);
		scoreText.setPosition(1150, 700);
		scoreText.setString("Score = " + std::to_string(playerScore));

		// Apply style and outline to the text
		scoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
		scoreText.setOutlineColor(sf::Color::White);
		scoreText.setOutlineThickness(2);

		// Create a background rectangle behind the text
		sf::RectangleShape backgroundRect1;
		backgroundRect1.setSize(sf::Vector2f(scoreText.getGlobalBounds().width + 20, scoreText.getGlobalBounds().height + 10));
		backgroundRect1.setFillColor(sf::Color(255, 255, 255, 200));  // Semi-transparent white
		backgroundRect1.setPosition(scoreText.getPosition().x - 10, scoreText.getPosition().y + 9);

		// Draw the background rectangle and the text
		window.draw(backgroundRect1);
		window.draw(scoreText);
	}


	for (int i = 0; i < 5; i++) {
		if (lawnmover[i] != NULL) {
			lawnmover[i]->draw(window);
		}
	}
	
	int inputSituation = filehandling.getInputGameScreen(window, suncurrency, currentLevel, gameGrid, newPlants);

	if (inputSituation != 19 && inputSituation != -1) {
		plants->harvestPlant(newPlants);
	}
	else if (inputSituation != -1)
		plants->destroyPlant(newPlants, 1);
}
void Level::setLevel(int) {

}

void Level::checkCollision()
{
	if (zombie != NULL && plants != NULL) {
		int sizeZombie = zombie->getZombieCount();
		int sizePlant = plants->getPlantsCount();
		int peaCordCheckX = 0;
		int peaCordCheckY = 0;
		int plantCordCheckX = 0;
		int plantCordCheckY = 0;
		int zombCordCheckX = 0;
		int zombCordCheckY = 0;

		for (int j = 0; j < sizePlant; j++)
		{
			plantCordCheckX = plants->getX(j);
			plantCordCheckY = plants->getY(j);

			for (int i = 0; i < sizeZombie; i++)
			{
				zombCordCheckX = zombie->getX(i);
				zombCordCheckY = zombie->getY(i);
				if (zombCordCheckY == plantCordCheckY)
				{
					if (plantCordCheckX >= zombCordCheckX)
					{
						if (1)
						{
							zombie->shouldStop(i);
							if (levelClock.getElapsedTime().asSeconds() >= timeLimit)
							{
								levelClock.restart();

								zombie->shouldStart(i);
								plants->destroyPlant(newPlants, j);
							}
						}
					}
				}

			}
		}

		for (int i = 0; i < sizeZombie; i++)
		{
			zombCordCheckX = zombie->getX(i);
			zombCordCheckY = zombie->getY(i);

			for (int j = 0; j < sizePlant; j++)
			{
				for (int k = 0; k < 2; k++) {
					peaCordCheckX = plants->getXOfPea(j, k);
					peaCordCheckY = plants->getYOfPea(j, k);
					if (peaCordCheckX < -1 && peaCordCheckY < -1) {
						peaCordCheckX *= -1;
						peaCordCheckY *= -1;
						if (zombCordCheckY == peaCordCheckY - 10)
						{
							if (peaCordCheckX >= zombCordCheckX)
							{
								zombie->decreaseHealth(i, zombieKilled);
								playerScore += 100;
								plants->destroyPea(j, k);
								zombie->shouldStop(i);
								if (levelClock.getElapsedTime().asSeconds() >= timeLimit)
								{
									levelClock.restart();

									zombie->shouldStart(i);
								}
							}
						}
					}
					else {
						if (zombCordCheckY == peaCordCheckY - 10)
						{
							if (peaCordCheckX >= zombCordCheckX)
							{
								zombie->decreaseHealth(i, zombieKilled);
								plants->destroyPea(j, k);
							}
						}
					}
				}
			}
		}

		for (int j = 0; j < 5; j++) {
			if (lawnmover[j] != NULL) {
				for (int i = 0; i < sizeZombie; i++)
				{
					zombCordCheckX = zombie->getX(i);
					zombCordCheckY = zombie->getY(i);

					if (zombCordCheckY == lawnmover[j]->gety())
					{

						if (zombCordCheckX <= lawnmover[j]->getx())
						{
							zombieKilled++;
							playerScore += 200;
							zombie->destroyZombie(i);
						}
					}
				}
			}
		}
	}
}

Level::~Level() {
	delete plants;
	delete newPlants;
	delete newzombie;
	delete zombie;
	for (int i = 0; i < 5; i++) {
		if (lawnmover[i] != NULL)
			delete lawnmover[i];
	}
	delete[] lawnmover;
}