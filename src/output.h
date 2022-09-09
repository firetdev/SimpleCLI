#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Output
{
public:
	std::string txtlog;
	sf::Font font;
	sf::Text text;
	int line;
	//Appended contains the number of characters on a line excluding prompt
	//Used when deleting characters so that prompt won't be deleted
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
	line = 0 + txt.size();
	std::cout << line << ":";
	text.setString(txtlog);
	text.move(0, -15);
}

void Output::appendText(std::string txt)
{
	//Add screen wrap
	txtlog += txt;
	appended += txt.size();
	if(line > 70)
	{
		txtlog += "\n";
		line = 0;
		text.move(0, -15);
	}
	line++;
	text.setString(txtlog);
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
	txtlog = "Welcome to SimpleCLI!";
	line = txtlog.size();
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(15);
	text.setPosition(10, 375);
	text.setString(txtlog);
	appended = 0;
	addText("Enter command: ");
}
