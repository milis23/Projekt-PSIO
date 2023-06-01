#pragma once
#include "AnimowaneAssety.h"
class Coin : public AnimowaneAssety {
public:
    Coin(float x, float y) : AnimowaneAssety(x, y) {};

    virtual void notify(sf::Event& ev);

    virtual void collide(AnimowaneAssety& col);

    virtual void Animuj(sf::RenderWindow& window);
};

