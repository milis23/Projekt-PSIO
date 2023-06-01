#pragma once
#include "AnimowaneAssety.h"
class Champion : public AnimowaneAssety {
public:
    Champion(float x, float y, sf::Texture& tex) : AnimowaneAssety(x, y) {};

    virtual void notify(sf::Event& ev);

    virtual void collide(AnimowaneAssety& col);

    virtual void Animuj(sf::RenderWindow& window);

    int getPoints();

    int getLives();

private:
    int points = 0;
    int lives = 3;
    bool immortality = false;
};

