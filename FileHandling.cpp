#include "FileHandling.h"

int FileHandling::getLevelOfPlayer(int lineNum) {
	std::ifstream file("D:\\Oop Project\\levelFile.txt");
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << "levelFile" << std::endl;
	}

	char c;
	int currentLine = 0;
	int value = 0;

	// Read characters until the desired line
	while (currentLine < lineNum && file.get(c)) {
		if (c == '\n') {
			currentLine++;
		}
	}

	// Read the integer value from the line
	while (file.get(c)) {
		if (c >= '0' && c <= '9') {
			value = (c - '0');
		}
	}

	return value; // Return the integer value from the line
}


void FileHandling::createWallnutCard(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\wallnutCard.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(500, 0);
	s_map.setScale(0.75f, 0.75f);

	window.draw(s_map);
}
void FileHandling::createPeaShooterCard(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\peashooterCard.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(80, 0);
	s_map.setScale(0.75f, 0.75f);

	window.draw(s_map);

}
void FileHandling::createSunFlowerCard(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\sunflowerCardnew.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(220, 0);
	s_map.setScale(0.75f, 0.75f);

	window.draw(s_map);
}
void FileHandling::createRepeaterCard(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\repeaterCard.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(360, 0);
	s_map.setScale(0.75f, 0.75f);

	window.draw(s_map);
}
void FileHandling::createCherryBombCard(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\cherrybombCard.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(640, 0);
	s_map.setScale(0.75f, 0.75f);

	window.draw(s_map);
}
void FileHandling::createShovelCard(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\Shovel.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(920, 0);
	s_map.setScale(0.75f, 0.6f);

	window.draw(s_map);
}
void FileHandling::createSunCard(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\sunnew.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	//s_map.setScale(0.75f, 0.75f);

	window.draw(s_map);
}
void FileHandling::createSnowPeaCard(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\spcard.jpeg");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(780, 0);
	s_map.setScale(0.7f, 0.5f);

	window.draw(s_map);
}
void FileHandling::menuScreen(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\menu button.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(1230, 0);

	// Set the scale of the sprite
	s_map.setScale(0.5f, 0.5f);

	window.draw(s_map);
}

void FileHandling::createScreens(RenderWindow& window, int level)
{
	createMap(window);
	createShovelCard(window);
	createSunCard(window);
	createPeaShooterCard(window);
	createSunFlowerCard(window);
	createSnowPeaCard(window);
	createRepeaterCard(window);
	menuScreen(window);
	if (level > 1) {
		createWallnutCard(window);
		if (level > 2) {
			createCherryBombCard(window);
		}
		if (level > 3)
			createRepeaterCard(window);
	}
}



void FileHandling::DrawLawnmower(RenderWindow& window, int x, int y) {
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\LawnMower.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(x, y);
	s_map.setScale(0.65f, 0.65f);

	window.draw(s_map);
}


//Drawing the Screen 1
void FileHandling::createScreen1(RenderWindow& window) {
	//Drawing a screen 1
	Image map_image;//?????? ??????????? ??? ?????
	map_image.loadFromFile("D:\\Oop Project\\images\\Starting_Screen.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);

	// Set the scale of the sprite
	s_map.setScale(1.20f, 1.09f);

	window.draw(s_map);
}
void FileHandling::createScreen2(RenderWindow& window) {
	//Drawing a screen 2
	Image map_image;//?????? ??????????? ??? ?????
	map_image.loadFromFile("D:\\Oop Project\\images\\Page1.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);

	// Set the scale of the sprite
	s_map.setScale(2.10f, 2.1f);

	window.draw(s_map);
}
void FileHandling::createScreen3(RenderWindow& window) {
	//Drawing a screen 2
	Image map_image;//?????? ??????????? ??? ?????
	map_image.loadFromFile("D:\\Oop Project\\images\\MainMenu.jpg");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);

	// Set the scale of the sprite
	s_map.setScale(1.075f, 0.8f);

	window.draw(s_map);
}
void FileHandling::createScreen31(RenderWindow& window) {
	//Drawing a screen 31
	Image map_image;//?????? ??????????? ??? ?????
	map_image.loadFromFile("D:\\Oop Project\\images\\ChooseLevel.jpg");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);

	// Set the scale of the sprite
	s_map.setScale(0.95f, 0.63f);

	window.draw(s_map);
}
void FileHandling::resumeScreen(RenderWindow& window)
{
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\pauseMenu.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(330, 80);

	// Set the scale of the sprite
	//s_map.setScale(0.95f, 0.63f);

	window.draw(s_map);
}

//Drawing the map
void FileHandling::createMap(RenderWindow& window) {
	//Drawing a map
	Image map_image;
	map_image.loadFromFile("D:\\Oop Project\\images\\lawnnew.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);

	// Set the scale of the sprite
	//s_map.setScale(0.707f, 0.65f);

	window.draw(s_map);
}


void FileHandling::getInputScreen1(RenderWindow& window) {
	// getting input for first display
// Define the region of interest
	int regionX = 303; // Example: X coordinate of top-left corner of region
	int regionY = 584; // Example: Y coordinate of top-left corner of region
	int regionWidth = 715; // Example: Width of the region
	int regionHeight = 91; // Example: Height of the region
	bool clicked = 0;

	while (window.isOpen()) {
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				// Close window event
			case sf::Event::Closed:
				window.close();
				break;
				// Mouse button pressed event
			case sf::Event::MouseButtonPressed:
				// Check if left mouse button is pressed
				if (event.mouseButton.button == sf::Mouse::Left) {
					// Get mouse position
					int mouseX = sf::Mouse::getPosition(window).x;
					int mouseY = sf::Mouse::getPosition(window).y;
					// Check if mouse position is within the region
					if (mouseX >= regionX && mouseX <= regionX + regionWidth &&
						mouseY >= regionY && mouseY <= regionY + regionHeight) {
						// Mouse is clicked within the region, do something
						// For example, you can print a message
						clicked = 1;
					}
				}
				break;
			default:
				break;
			}
			if (clicked == 1) {
				break;
			}
		}

		// Clear the window
		window.clear();

		// Draw the background
		//window.draw(s_map);
		createScreen1(window);
		// Display the contents of the window
		window.display();

		if (clicked == 1) {
			break;
		}
	}

}
int FileHandling::getInputScreen2(RenderWindow& window) {
	// for second display's inputs
// Define the region of interest
	int region1X = 737; // Example: X coordinate of top-left corner of region
	int region1Y = 223; // Example: Y coordinate of top-left corner of region
	int region1Width = 445; // Example: Width of the region
	int region1Height = 70; // Example: Height of the region
	int region2X = 737; // Example: X coordinate of top-left corner of region
	int region2Y = 319; // Example: Y coordinate of top-left corner of region
	int region2Width = 434; // Example: Width of the region
	int region2Height = 91; // Example: Height of the region
	bool clicked = 0;
	int selectedIndex = -1;

	// Font for text rendering
	sf::Font font;
	if (!font.loadFromFile("D:\\Oop Project\\ARIALN.ttf")) {
		std::cerr << "Failed to load font file!" << std::endl;
	}

	// Text for displaying instructions and names
	sf::Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(20);
	instructions.setFillColor(sf::Color::White);
	//instructions.setString("Click on region 1 to input your name\nClick on region 2 to select a name from the list");

	sf::Text nameDisplay;
	nameDisplay.setFont(font);
	nameDisplay.setCharacterSize(20);
	nameDisplay.setFillColor(sf::Color::White);

	// Open the file for reading existing names
	std::ifstream inputFile("D:\\Oop Project\\namingFile.txt");
	std::string name;
	std::string names;
	int index = 1;

	// Read names from the file
	while (std::getline(inputFile, name)) {
		names += std::to_string(index) + ". " + name + "\n";
		index++;
	}

	// Close the file
	inputFile.close();

	while (window.isOpen()) {
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				// Close window event
			case sf::Event::Closed:
				window.close();
				break;
				// Mouse button pressed event
			case sf::Event::MouseButtonPressed:
				// Check if left mouse button is pressed
				if (event.mouseButton.button == sf::Mouse::Left) {
					// Get mouse position
					int mouseX = sf::Mouse::getPosition(window).x;
					int mouseY = sf::Mouse::getPosition(window).y;

					// Check if mouse position is within region 1
					if (mouseX >= region1X && mouseX <= region1X + region1Width &&
						mouseY >= region1Y && mouseY <= region1Y + region1Height) {

						// Input the user's complete name
						sf::String userName;
						sf::Text textInput;
						textInput.setFont(font);
						textInput.setCharacterSize(20);
						textInput.setFillColor(sf::Color::White);
						textInput.setPosition(10, 10);
						textInput.setString("Enter your complete name: ");

						// Create a separate window for input
						sf::RenderWindow inputWindow(sf::VideoMode(400, 80), " Enter your complete name", sf::Style::Titlebar | sf::Style::Close);
						inputWindow.setPosition(sf::Vector2i(200, 350));

						while (inputWindow.isOpen()) {
							// Process events
							sf::Event event;
							while (inputWindow.pollEvent(event)) {
								if (event.type == sf::Event::Closed) {
									inputWindow.close();
								}
								else if (event.type == sf::Event::TextEntered) {
									if (event.text.unicode == '\b' && userName.getSize() > 0) { // Backspace
										userName.erase(userName.getSize() - 1, 1);
									}
									else if (event.text.unicode < 128 && event.text.unicode != '\r') { // ASCII characters excluding carriage return
										userName += event.text.unicode;
									}
									textInput.setString("Enter your complete name: " + userName);
								}
								else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
									inputWindow.close();
								}
							}

							// Clear the input window
							inputWindow.clear();

							// Draw the text input
							inputWindow.draw(textInput);

							// Display the contents of the input window
							inputWindow.display();
						}

						// Save the name to the file
						std::ofstream outputFile("D:\\Oop Project\\namingFile.txt", std::ios::app);
						if (outputFile.is_open()) {
							outputFile << userName.toAnsiString() << std::endl;
							outputFile.close();
						}
						else {
							std::cerr << "Unable to open file for writing!" << std::endl;
						}
						selectedIndex = index;
						// Update names display
						inputFile.open("D:\\Oop Project\\namingFile.txt");
						names.clear();
						index = 1;
						while (std::getline(inputFile, name)) {
							names += std::to_string(index) + ". " + name + "\n";
							index++;
						}
						inputFile.close();
						clicked = 1;
					}


					// Check if mouse position is within region 2
					else if (mouseX >= region2X && mouseX <= region2X + region2Width &&
						mouseY >= region2Y && mouseY <= region2Y + region2Height) {
						// Display existing list of names
						nameDisplay.setString(names);
						nameDisplay.setPosition(20, 20);

						// Create a separate window for selecting a name
						sf::RenderWindow selectWindow(sf::VideoMode(400, 400), "Existing Players", sf::Style::Titlebar | sf::Style::Close);
						selectWindow.setPosition(sf::Vector2i(200, 330));

						// Get the index of the selected name
						bool selectingName = true;
						int selectedIndex = -1;

						sf::Text instructionText;
						instructionText.setFont(font);
						instructionText.setCharacterSize(20);
						instructionText.setFillColor(sf::Color::White);
						instructionText.setString("Click on the index of the name you want to select");

						while (selectingName) {
							// Process events
							sf::Event event;
							while (selectWindow.pollEvent(event)) {
								if (event.type == sf::Event::Closed) {
									selectWindow.close();
								}
								else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
									// Get mouse position
									int mouseY = sf::Mouse::getPosition(selectWindow).y;

									// Calculate index based on mouse position and font size
									int clickedIndex = (mouseY - 40) / 20; // Assuming each name occupies 20 pixels vertically
									if (clickedIndex >= 0 && clickedIndex < index) {
										selectedIndex = clickedIndex;
										selectingName = false;
										clicked = 1;
									}
								}
							}

							// Clear the select window
							selectWindow.clear();

							// Draw the instruction text and name display
							selectWindow.draw(instructionText);
							//nameDisplay.setPosition(20, 40); // Adjust position to accommodate instruction text
							selectWindow.draw(nameDisplay);

							// Display the contents of the select window
							selectWindow.display();
						}

						// Now 'selectedIndex' contains the index of the selected name
						// You can use it for further processing


						// Now 'selectedIndex' contains the index of the selected name
						// You can use it for further processing

							// Clear the window
						window.clear();

						// Draw the background
						createScreen2(window);
						//window.draw(instructionText);
						//window.draw(nameDisplay);

						// Display the contents of the window
						window.display();
					}
				}
				break;
			default:
				break;
			}
		}

		if (clicked == 1)
			break;
		// Clear the window
		window.clear();

		// Draw the background
		createScreen2(window);
		//window.draw(instructions);
		//window.draw(nameDisplay);

		// Display the contents of the window
		window.display();
	}
	return selectedIndex;
}
int FileHandling::getInputScreen3(RenderWindow& window, int playerIndex) {

	// Define the region of interest
	int region1X = 704;
	int region1Y = 114;
	int region1Width = 542;
	int region1Height = 114;
	int region2X = 715;
	int region2Y = 262;
	int region2Width = 520;
	int region2Height = 91;
	int region3X = 715;
	int region3Y = 375;
	int region3Width = 466;
	int region3Height = 91;
	int region4X = 715;
	int region4Y = 478;
	int region4Width = 434;
	int region4Height = 68;
	bool clicked = false;
	int selectedIndex = -1;
	int maxLevel = getLevelOfPlayer(playerIndex);

	while (window.isOpen()) {
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				// Get mouse position
				int mouseX = event.mouseButton.x;
				int mouseY = event.mouseButton.y;

				// Check if mouse position is within region 1
				if (mouseX >= region1X && mouseX <= region1X + region1Width &&
					mouseY >= region1Y && mouseY <= region1Y + region1Height) {
					// Create a new window for input with a new background
					sf::RenderWindow inputWindow(sf::VideoMode(1200, 600), "Input Window", sf::Style::Titlebar | sf::Style::Close);
					inputWindow.setPosition(sf::Vector2i(80, 80));
					//createScreen31(inputWindow);

					int region1X1 = 22; // Example: X coordinate of top-left corner of region
					int region1Y1 = 40; // Example: Y coordinate of top-left corner of region
					int region1Width1 = 258; // Example: Width of the region
					int region1Height1 = 171; // Example: Height of the region
					int region2X1 = 302; // Example: X coordinate of top-left corner of region
					int region2Y1 = 40; // Example: Y coordinate of top-left corner of region
					int region2Width1 = 258; // Example: Width of the region
					int region2Height1 = 171; // Example: Height of the region
					int region3X1 = 578; // Example: X coordinate of top-left corner of region
					int region3Y1 = 40; // Example: Y coordinate of top-left corner of region
					int region3Width1 = 258; // Example: Width of the region
					int region3Height1 = 171; // Example: Height of the region
					int region4X1 = 862; // Example: X coordinate of top-left corner of region
					int region4Y1 = 40; // Example: Y coordinate of top-left corner of region
					int region4Width1 = 258; // Example: Width of the region
					int region4Height1 = 171; // Example: Height of the region
					int region5X1 = 460; // Example: X coordinate of top-left corner of region
					int region5Y1 = 220; // Example: Y coordinate of top-left corner of region
					int region5Width1 = 258; // Example: Width of the region
					int region5Height1 = 171; // Example: Height of the region
					int region6X1 = 503; // Example: X coordinate of top-left corner of region
					int region6Y1 = 505; // Example: Y coordinate of top-left corner of region
					int region6Width1 = 241; // Example: Width of the region
					int region6Height1 = 44; // Example: Height of the region
					bool cclicked = 0;

					while (inputWindow.isOpen()) {
						// Process events
						sf::Event event;
						while (inputWindow.pollEvent(event)) {
							switch (event.type) {
								// Close window event
							case sf::Event::Closed:
								window.close();
								break;
								// Mouse button pressed event
							case sf::Event::MouseButtonPressed:
								// Check if left mouse button is pressed
								if (event.mouseButton.button == sf::Mouse::Left) {
									// Get mouse position
									int mouseX = sf::Mouse::getPosition(inputWindow).x;
									int mouseY = sf::Mouse::getPosition(inputWindow).y;

									// Check if mouse position is within region 1
									if (mouseX >= region1X1 && mouseX <= region1X1 + region1Width1 &&
										mouseY >= region1Y1 && mouseY <= region1Y1 + region1Height1) {
										return 1;
									}
									// Check if mouse position is within region 2
									else if (mouseX >= region2X1 && mouseX <= region2X1 + region2Width1 &&
										mouseY >= region2Y1 && mouseY <= region2Y1 + region2Height1) {
										if (maxLevel >= 2)
											return 2;
									}
									// Check if mouse position is within region 3
									else if (mouseX >= region3X1 && mouseX <= region3X1 + region3Width1 &&
										mouseY >= region3Y1 && mouseY <= region3Y1 + region3Height1) {
										if (maxLevel >= 3)
											return 3;
									}
									// Check if mouse position is within region 4
									else if (mouseX >= region4X1 && mouseX <= region4X1 + region4Width1 &&
										mouseY >= region4Y1 && mouseY <= region4Y1 + region4Height1) {
										if (maxLevel >= 4)
											return 4;
									}
									// Check if mouse position is within region 5
									else if (mouseX >= region5X1 && mouseX <= region5X1 + region5Width1 &&
										mouseY >= region5Y1 && mouseY <= region5Y1 + region5Height1) {
										if (maxLevel >= 5)
											return 5;
									}
									// Check if mouse position is within region 6
									else if (mouseX >= region6X1 && mouseX <= region6X1 + region6Width1 &&
										mouseY >= region6Y1 && mouseY <= region6Y1 + region6Height1) {
										inputWindow.close();
									}
								}
							}
						}
						// Clear the input window
						inputWindow.clear();
						createScreen31(inputWindow);
						// Draw the text input
						//inputWindow.draw();

						// Display the contents of the input window
						inputWindow.display();
					}
				}
				// Check if mouse position is within region 2
				else if (mouseX >= region2X && mouseX <= region2X + region2Width &&
					mouseY >= region2Y && mouseY <= region2Y + region2Height) {
					// Return 1 if region 2 is clicked
					return 1;
				}
				// Check if mouse position is within region 3
				else if (mouseX >= region3X && mouseX <= region3X + region3Width &&
					mouseY >= region3Y && mouseY <= region3Y + region3Height) {
					// Return -1 if region 3 is clicked
					return -1;
				}
				// Check if mouse position is within region 4
				else if (mouseX >= region4X && mouseX <= region4X + region4Width &&
					mouseY >= region4Y && mouseY <= region4Y + region4Height) {
					// Close the window if region 4 is clicked
					window.close();
				}
			}
		}

		// Clear the window
		window.clear();

		// Draw the background
		createScreen3(window);

		// Display the contents of the window
		window.display();


	}
}
int FileHandling::getInputGameScreen(RenderWindow& window, int& sunCurrency, int levelNo, int(*gameGrid)[11], Plants* (&newplants)) {
	// Define regions of interest
	int regionX[7] = { 80, 220, 360, 500, 640, 780, 1100 };
	int regionY[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int regionWidth[7] = { 132, 132, 132, 132, 132, 104, 250 };
	int regionHeight[7] = { 79, 79, 79, 79, 79, 84, 50 };

	// Check if the user clicked inside one of the regions
	bool clickedInsideRegion = false;
	int clickedRegion = -1;
	bool isPause = false;
	bool isResume = true;


	//while (!clickedInsideRegion) {
		// Process events
		Event event;
		while (!clickedInsideRegion && window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				//cout << "yeas" << endl;
				// Get mouse position
				int mouseX = event.mouseButton.x;
				int mouseY = event.mouseButton.y;

				// Check if mouse clicked inside one of the regions
				for (int i = 0; i < 7; ++i) {
					if ((mouseX >= regionX[i] && mouseX <= (regionX[i] + regionWidth[i])) &&
						(mouseY >= regionY[i] && mouseY <= (regionY[i] + regionHeight[i]))) {
						clickedInsideRegion = true;
						clickedRegion = i + 1;
						break;
					}
				}
				if (clickedRegion == 7)
				{
					isPause = true;
					isResume = false;

				}
			}
		}

		if (clickedRegion == 7)
		{
			while (!isResume && isPause)
			{
				//cout << "gone" << endl;
				Event eeeeevent;
				while (window.pollEvent(eeeeevent))
				{
					resumeScreen(window);
					if (clickedInsideRegion && (eeeeevent.type == Event::MouseButtonPressed) && (eeeeevent.mouseButton.button == Mouse::Left))
					{
						//cout << "okay" << endl;
						int mouseX = eeeeevent.mouseButton.x;
						int mouseY = eeeeevent.mouseButton.y;
						int regionX = 530;
						int regionWidth = 400;
						int regionY = 500;
						int regionHeight = 100;

						//cout << "mousex = " << mouseX << endl;
						//cout << "mousey = " << mouseY << endl;


						if ((mouseX >= regionX && mouseX <= (regionX + regionWidth)) &&
							(mouseY >= regionY && mouseY <= (regionY + regionHeight)))
						{
							//cout << "pressed" << endl;
							isResume = true;
							isPause = false;
							break;
						}
					}

					window.display();
					window.clear();
				}

				if (isResume && !isPause)
					break;
			}
			createScreens(window, levelNo);
			window.display();
			window.clear();

		}

	// Wait for the second click outside the region
	while (clickedInsideRegion && clickedRegion < 7) {
		// Process events
		Event eevent;
		while (window.pollEvent(eevent)) {
			if (eevent.type == Event::Closed) {
				window.close();
			}
			else if (clickedInsideRegion && (eevent.type == Event::MouseButtonPressed) && (eevent.mouseButton.button == Mouse::Left)) {
				// Get mouse position

				int mouseX = eevent.mouseButton.x;
				int mouseY = eevent.mouseButton.y;
				int gridX = (mouseY - 100) / 125;
				int gridY = (mouseX - 433) / 100;


				if (levelNo == 1 && (clickedRegion == 1 || clickedRegion == 2 || clickedRegion == 3 || clickedRegion == 6)) {
					if (gameGrid[gridX][gridY] == -1) {
						if (clickedRegion == 1 && sunCurrency > 99) {
							newplants = new Peashooter("Peashooter", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 100;
							return 11;
						}
						else if (clickedRegion == 2 && sunCurrency > 49) {
							cout << "sun" << endl;
							newplants = new Sunflower("Sunflower", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 50;
							return 12;
						}
						else if (clickedRegion == 3 && sunCurrency > 199) {
							newplants = new Repeater("Repeater", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 200;
							return 13;
						}

						else if (clickedRegion == 6 && sunCurrency > 199) {
							newplants = new Snowpea("Snowopea", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 100;
							return 17;
						}
					}
					//else if (clickedRegion == 6) {
					//	//cout << "hsohevel" << endl;
					//	newplants = new Peashooter("", (gridY * 100 + 433), (gridX * 125 + 100));
					//	return 19;
					//}
				}
				if (levelNo == 2 && (clickedRegion == 1 || clickedRegion == 2 || clickedRegion == 3 ||  clickedRegion == 4 || clickedRegion == 6)) {
					if (gameGrid[gridX][gridY] == -1) {
						if (clickedRegion == 1 && sunCurrency > 99) {
							newplants = new Peashooter("Peashooter", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 100;
							return 11;
						}
						else if (clickedRegion == 2 && sunCurrency > 49) {
							newplants = new Sunflower("Sunflower", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 50;
							return 12;
						}
						else if (clickedRegion == 4 && sunCurrency > 49) {
							newplants = new WallNut("WallNut", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 50;
							return 14;
						}
						else if (clickedRegion == 3 && sunCurrency > 199) {
							newplants = new Repeater("Repeater", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 200;
							return 13;
						}
						else if (clickedRegion == 6 && sunCurrency > 199) {
							newplants = new Snowpea("Snowopea", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 100;
							return 17;
						}
					}
					else if (clickedRegion == 6) {
						newplants = new Peashooter("", (gridY * 100 + 433), (gridX * 125 + 100));
						return 19;
					}
				}
				if (levelNo == 3 && (clickedRegion == 1 || clickedRegion == 2 || clickedRegion == 3 || clickedRegion == 4 || clickedRegion == 5 || clickedRegion == 6)) {
					if (gameGrid[gridX][gridY] == -1) {
						if (clickedRegion == 1 && sunCurrency > 99) {
							newplants = new Peashooter("Peashooter", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 100;
							return 11;
						}
						else if (clickedRegion == 2 && sunCurrency > 49) {
							newplants = new Sunflower("Sunflower", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 50;
							return 12;
						}
						else if (clickedRegion == 4 && sunCurrency > 49) {
							newplants = new WallNut("WallNut", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 50;
							return 14;
						}
						else if (clickedRegion == 5 && sunCurrency > 149) {
							newplants = new Cherrybomb("Cherrybomb", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 150;
							return 16;
						}
						else if (clickedRegion == 3 && sunCurrency > 199) {
							newplants = new Repeater("Repeater", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 200;
							return 13;
						}
						else if (clickedRegion == 6 && sunCurrency > 199) {
							newplants = new Snowpea("Snowopea", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 100;
							return 17;
						}

					}
					else if (clickedRegion == 6) {
						newplants = new Peashooter("", (gridY * 100 + 433), (gridX * 125 + 100));
						return 19;
					}
				}
				if (levelNo == 4 && (clickedRegion == 1 || clickedRegion == 2 || clickedRegion == 3 || clickedRegion == 4 || clickedRegion == 5 || clickedRegion == 6)) {
					if (gameGrid[gridX][gridY] == -1) {
						if (clickedRegion == 1 && sunCurrency > 99) {
							newplants = new Peashooter("Peashooter", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 100;
							return 11;
						}
						else if (clickedRegion == 2 && sunCurrency > 49) {
							newplants = new Sunflower("Sunflower", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 50;
							return 12;
						}
						else if (clickedRegion == 3 && sunCurrency > 199) {
							newplants = new Repeater("Repeater", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 200;
							return 13;
						}
						else if (clickedRegion == 4 && sunCurrency > 49) {
							newplants = new WallNut("WallNut", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 50;
							return 14;
						}
						else if (clickedRegion == 5 && sunCurrency > 149) {
							newplants = new Cherrybomb("Cherrybomb", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 150;
							return 16;
						}
						else if (clickedRegion == 6 && sunCurrency > 199) {
							newplants = new Snowpea("Snowopea", (gridY * 100 + 433), (gridX * 125 + 100));
							sunCurrency -= 100;
							return 17;
						}
					}
					else if (clickedRegion == 6) {
						newplants = new Peashooter("", (gridY * 100 + 433), (gridX * 125 + 100));
						return 19;
					}
				}
			}
		}
	}
	return -1;

}
