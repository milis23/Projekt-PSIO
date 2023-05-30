#pragma once
#include "AnimowaneAssety.h"
class Champion : public AnimowaneAssety {
public:
    Champion(float x, float y, sf::Texture& tex) : AnimowaneAssety(x, y) {
        type = ObjectType::CHAMPION;
    }
    virtual void notify(sf::Event& ev) {
        
    }

    virtual void collide(AnimowaneAssety& col) {
        if (getGlobalBounds().intersects(col.getGlobalBounds())) {
            if (col.type == ObjectType::COIN) {
                points += 1;
            }
            if (col.type == ObjectType::BOMB) {
                lives -= 1;
                col.alive = false;
            }
            if (col.type == ObjectType::SHIELD) {
                if (immortality) {
                    immortality = true;
                }
                else {
                    immortality = false;
                }
            }
            if (col.type == ObjectType::AID&&lives<3) {
                lives++;
            }
        }
    }

    virtual void Animuj(sf::RenderWindow& window) {
        if (getPosition().x < 0.0) {
            setPosition(window.getSize().x, getPosition().y);
        }
        if (getPosition().x > window.getSize().x) {
            setPosition(0.0, getPosition().y);
        }
        
        window.draw(sprite);
    }

    int getPoints() {
        return points;
    }

    int getLives() {
        return lives;
    }

private:
    int points = 0;
    int lives = 3;
    bool immortality = false;
};

