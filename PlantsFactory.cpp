#include "PlantsFactory.h"

PlantsFactory::PlantsFactory(int clevel) {
	totalPlants = 20;
	currentLevel = clevel;
	sunCount = 10;
	sun = new Sun * [sunCount];
	plants = new Plants * [totalPlants];

	for (int i = 0; i < totalPlants; i++) {
		plants[i] = NULL;
	}
	for (int i = 0; i < sunCount; i++) {
		sun[i] = NULL;
	}
}
int PlantsFactory::play( int& sunCurrency) {
	Fire();
	callSun();
	for (int i = 0; i < sunCount; i++) {
		if (sun[i] != NULL)
			sun[i]->move();
	}
	return 0;
}
void PlantsFactory::drawPlant(RenderWindow& window, int& sunCurrency) {
	for (int i = 0; i < totalPlants; i++) {
		if (plants[i] != NULL)
			plants[i]->drawPlant(window, sunCurrency);
	}
	for (int i = 0; i < sunCount; i++) {
		if (sun[i] != NULL)
			sun[i]->draw(window);
	}
	collectSun(window, sunCurrency);
}
void PlantsFactory::harvestPlant(Plants* plants) {
	//cout << "reached" << endl;
	for (int i = 0; i < totalPlants; i++) {
		if (this->plants[i] == NULL) {
			this->plants[i] = plants;
			break;
		}
	}
	//cout << "completed" << endl;
}
bool PlantsFactory::destroyPlant(Plants* plant, int index) {
	if (index == 100) {
		for (int i = 0; i < totalPlants; i++) {
			if (plants[i] != NULL) {
				if (plants[i]->getX() == plant->getX() && plants[i]->getY() == plant->getY()) {
					delete plants[i];
					plants[i] = NULL;
				}
			}
		}
	}


	for (int i = 0; i < totalPlants; i++)
	{
		if (i == index)
		{
			delete plants[i];
			plants[i] = NULL;
			break;
		}
	}
	return 0;
}
void PlantsFactory::destroyPea(int index, int index1) {
	for (int i = 0; i < totalPlants; i++)
	{
		if (i == index && plants[i] != NULL)
		{
			plants[i]->destroyPea(index1);
		}
	}
}
void PlantsFactory::Fire() {
	for (int i = 0; i < totalPlants; i++) {
		if (plants[i] != NULL)
			plants[i]->Fire();
	}
}
void PlantsFactory::callSun() {
	if (sunClock.getElapsedTime().asSeconds() >= timeLimit) {
		// Reset the clock
		sunClock.restart();

		srand(time(NULL));
		int randNo = (rand() % 900) + 440;
		for (int i = 0; i < sunCount; i++) {
			if (sun[i] == NULL) {
				sun[i] = new Sun(randNo, 100, 1);
				break;
			}
		}
		
	}
}
int PlantsFactory::collectSun(RenderWindow& window, int& sunCurrency) {

	// Event loop to handle mouse clicks
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				int userInputX = event.mouseButton.x; // Get x-coordinate of mouse click
				int userInputY = event.mouseButton.y; // Get y-coordinate of mouse click

				// Iterate through each sun and check if the user click falls within its bounds
				for (int i = 0; i < sunCount; ++i) {
					if (sun[i] != NULL) {
						int sunX = sun[i]->getx(); // Get x-coordinate of the current sun
						int sunY = sun[i]->gety(); // Get y-coordinate of the current sun
						int sunWidth = 80; // Width of the sun
						int sunHeight = 80; // Height of the sun

						// Check if user click falls within the bounds of the current sun
						if (userInputX >= sunX && userInputX <= sunX + sunWidth &&
							userInputY >= sunY && userInputY <= sunY + sunHeight) {

							delete sun[i];
							sun[i] = NULL;
							sunCurrency += 25;
						}
					}
				}
			}
			break;
		}
		break;
	}
	return 0;
}

int PlantsFactory::getPlantsCount() {
	return totalPlants;
}
int PlantsFactory::getX(int index) {
	for (int i = 0; i < totalPlants; i++)
	{
		if (i == index && plants[i] != NULL)
		{
			//cout << "check" << endl;
			return plants[i]->getX();
		}
	}
}
int PlantsFactory::getY(int index) {
	for (int i = 0; i < totalPlants; i++)
	{
		if (i == index && plants[i] != NULL)
		{
			return plants[i]->getY();
		}
	}
}
int PlantsFactory::getXOfPea(int index, int index1) {
	for (int i = 0; i < totalPlants; i++)
	{
		if (i == index && plants[i] != NULL)
		{
			return plants[i]->getXOfPea(index1);
		}
	}
}
int PlantsFactory::getYOfPea(int index, int index1) {
	for (int i = 0; i < totalPlants; i++)
	{
		if (i == index && plants[i] != NULL)
		{
			return plants[i]->getYOfPea(index1);
		}
	}
}

PlantsFactory::~PlantsFactory() {
	for (int i = 0; i < totalPlants; i++) {
		if (plants[i] != NULL)
			delete plants[i];
	}
	delete[] plants;

	for (int i = 0; i < sunCount; i++) {
		if (sun[i] != NULL)
			delete sun[i];
	}
	delete[] sun;
}