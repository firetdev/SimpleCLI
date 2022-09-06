#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "terminal", sf::Style::Titlebar);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}