#pragma once
#include "AnimowaneAssety.h"
class Aid :
    public AnimowaneAssety

{
    virtual void collide(AnimowaneAssety& col);
    virtual void animuj(sf::Window window);
    virtual void notify(sf::Event ev);
};

