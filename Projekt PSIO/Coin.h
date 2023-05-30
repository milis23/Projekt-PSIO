#pragma once
#include "AnimowaneAssety.h"
class Coin : public AnimowaneAssety {
public:
    Coin(float x, float y) : AnimowaneAssety(x, y) {
        type = ObjectType::COIN;
    }
    virtual void notify(sf::Event& ev) {
    }

    virtual void collide(AnimowaneAssety& col) {
        if (sprite.getGlobalBounds().intersects(col.sprite.getGlobalBounds())) {
            if (col.type == ObjectType::CHAMPION||col.type == ObjectType::BOMB) {
                alive = false;
            }
        }
    }

    virtual void Animuj(sf::RenderWindow& window) {
        sprite.move(0.0, 0.1);
        if (sprite.getPosition().x < 0.0) {
            sprite.setPosition(window.getSize().x, sprite.getPosition().y);
        }
        if (sprite.getPosition().x > window.getSize().x) {
            sprite.setPosition(0.0, sprite.getPosition().y);
        }
        if (sprite.getPosition().y < 0.0) {
            sprite.setPosition(sprite.getPosition().x, window.getSize().y);
        }
        window.draw(sprite);
    }
};

