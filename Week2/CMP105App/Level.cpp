#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}
	
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	input->setMouseLDown(false);
	dragging = false;
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	diffX = 0;
	diffY = 0;
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "J, K and L were Pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		std::cout << "ESC was Pressed\n";
		window->close();
	}

	if (input->isMouseLDown())
	{
		input->setMouseLDown(true);

		dragging = true;
		x2 = input->getMouseX();
		y2 = input->getMouseY();
	}
		else
		{
			input->setMouseLDown(false);
			if (dragging == true)
			{
				system("CLS");
				dragging = false;
				diffX = x2 - x1;
				diffY = y2 - y1;
				std::cout << "X movement: " << diffX << " " << "Y movement: " << diffY;
			}
			else
			{
				x1 = input->getMouseX();
				y1 = input->getMouseY();
			}
		}


	if (!input->isMouseLDown() && dragging == true)
	{

	}


}

// Update game objects
void Level::update()
{
	float x = input->getMouseX();
	float y = input->getMouseY();

	text.setString(std::to_string(x) + ", " + std::to_string(y));
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}