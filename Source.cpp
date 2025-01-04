#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <fstream>
#include "FileHandling.h"
#include "Game.h"

//#include"../SFML/Images/"
using namespace sf;
using namespace std;

int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1366, 768), "Plants Vs Zombies", Style::Titlebar | Style::Close | Style::Resize );
	//window.setSize(sf::Vector2u(1366, 728));
	window.setPosition(sf::Vector2i(0, 0));
	//Game icon
	Image icon;
	if (!icon.loadFromFile("D:\\Oop Project\\images\\icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
	window.display();

	FileHandling fileHandling;
	Game game;
	int gameGrid[5][11];
	int playerInfoIndex = -1;
	int currentLevel = -1;
	int situation = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			gameGrid[i][j] = -1;
		}
	}

	fileHandling.getInputScreen1(window);
	playerInfoIndex = fileHandling.getInputScreen2(window);
	currentLevel = fileHandling.getInputScreen3(window, playerInfoIndex);

	cout << currentLevel << endl;

	Clock timeMoney;



	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		clock.restart();
		time = time / 800;

		fileHandling.createMap(window);
		for (; currentLevel < 6;) {
			situation = game.play(playerInfoIndex, currentLevel, window, gameGrid);
			if (situation == 1) {
				currentLevel += 1;
			}
			else if (situation == -1)
				return 0;
		}
		



		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					window.close();
				}
			}
		}

		//Create a background
		//createBack(window);
		fileHandling.createMap(window);



		//window.setSize(sf::Vector2u(1366, 728));
		window.setPosition(sf::Vector2i(0, 0));
		window.display();
	}
	return 0;
}