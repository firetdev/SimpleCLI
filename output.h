#include <SFML/Graphics.hpp>
#include <string>

class Output
{
public:
	std::string txtlog;
	sf::Font font;
	sf::Text text;
	void addText(std::string);
	void render(sf::RenderWindow &window);
	Output(std::string);
};

void Output::addText(std::string txt)
{
	txtlog += "\n" + txt;
	text.setString(txtlog);
	text.move(0, -15);
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
}
