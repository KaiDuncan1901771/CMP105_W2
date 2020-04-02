#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	bool dragging;
	int x1;
	int x2;
	int y1;
	int y2;
	int diffX;
	int diffY;

	// Add your object here
	sf::Font font;
	sf::Text text;
};