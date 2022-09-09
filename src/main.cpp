#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "output.h"
#include "input.h"
#include "commands.h"
#include "parser.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "SimpleCLI", sf::Style::Titlebar);
	Output output("Anonymous_Pro.ttf");
	//Disable if process is running
	bool requestingInput = true;
	std::string input = "";
	while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
			{
                window.close();
			}
			if(event.type == sf::Event::KeyPressed)
			{
				//Command entered
				if(event.key.code == sf::Keyboard::Enter)
				{
					requestingInput = false;
					parse(input, output);
					output.addText("Enter command: ");
					requestingInput = true;
					input = "";
				}
				else if(event.key.code == sf::Keyboard::Backspace)
				{
					if(output.removeFromText())
					{
						input.pop_back();
					}
				}
				else if(event.key.code == sf::Keyboard::Space)
				{
					input += " ";
					output.appendText("  ");
				}
				//Adding input
				else if(requestingInput)
				{
					input += keyToString(event.key.code);
					output.appendText(keyToString(event.key.code));
				}
			}
		}
        window.clear();
		output.render(window);
        window.display();
    }
    return 0;
}