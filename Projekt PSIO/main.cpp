#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Game.h"
#include"AnimowaneAssety.h"
#include"Coin.h"
#include"Champion.h"
#include"Bomb.h"
#include"Aid.h"
#include"Shield.h"
#include"Bullet.h"
#include"Net.h"
#include<time.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Gierka",sf::Style::Fullscreen);
    std::vector<AnimowaneAssety*> objects;
    window.setFramerateLimit(144);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed||(event.type == sf::Event::KeyPressed&& event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        window.clear();

        window.display();
    }

	return 0;
};