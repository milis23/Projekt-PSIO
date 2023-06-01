#pragma once
#include "AnimowaneAssety.h"
class Shield :
    public AnimowaneAssety
{
    virtual void animuj(sf::Window window);
    virtual void collide(AnimowaneAssety& col);
    virtual void notify(sf::Event ev);
};
