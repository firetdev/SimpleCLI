#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Output
{
public:
	std::string txtlog;
	sf::Font font;
	sf::Text text;
	int appended;
	void addText(std::string);
	void appendText(std::string);
	bool removeFromText();
	void render(sf::RenderWindow &window);
	Output(std::string);
};

void Output::addText(std::string txt)
{
	txtlog += "\n" + txt;
	text.setString(txtlog);
	text.move(0, -15);
}

void Output::appendText(std::string txt)
{
	txtlog += txt;
	text.setString(txtlog);
	appended += txt.size();
}

bool Output::removeFromText()
{
	//Delete character--don't delete prompt
	if(appended > 0)
	{
		txtlog.pop_back();
		text.setString(txtlog);
		appended--;
		return true;
	}
	return false;
}

void Output::render(sf::RenderWindow &window)
{
	window.draw(text);
}

Output::Output(std::string fontPath)
{
	txtlog = "Welcome to SimpleCLI!\nEnter command: ";
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(15);
	text.setPosition(10, 360);
	text.setString(txtlog);
	appended = 0;
}
