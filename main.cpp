#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "output.h"
#include "input.h"

int main()
{
	//App window
    sf::RenderWindow window(sf::VideoMode(600, 400), "SimpleCLI", sf::Style::Titlebar);
	//Output box
	Output output("Anonymous_Pro.ttf");
	//Disable if process is running
	bool requestingInput = true;
	//Input by user
	std::string input = "";
	//App loop
	while(window.isOpen())
    {
		//Event checks
        sf::Event event;
        while(window.pollEvent(event))
        {
			//App closed
            if(event.type == sf::Event::Closed)
			{
                window.close();
			}
			//Key pressed
			if(event.type == sf::Event::KeyPressed)
			{
				//Command entered
				if(event.key.code == sf::Keyboard::Enter)
				{
					requestingInput = false;
					//Placeholder--only run on unrecognized command
					system(input.c_str());
					output.addText("Enter command: ");
					requestingInput = true;
				}
				//Backspace
				else if(event.key.code == sf::Keyboard::Backspace)
				{
					if(output.removeFromText())
					{
						input.pop_back();
					}
				}
				//Spacebar
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
		//Render
        window.clear();
		output.render(window);
        window.display();
    }
    return 0;
}