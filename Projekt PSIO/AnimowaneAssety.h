#pragma once
#include"Game.h"
#include<SFML/Graphics.hpp>
enum class ObjectType {
    CHAMPION = 0,
    COIN,
    AID,
    NET,
    BULLET,
    SHIELD,
    BOMB
};
class AnimowaneAssety:public sf::Sprite{
public:
    AnimowaneAssety(float x, float y) {
        sprite.setPosition(x, y);
    }
    virtual void notify(sf::Event& ev) = 0;
    virtual void collide(AnimowaneAssety& col) = 0;
    virtual void Animuj(sf::RenderWindow& window) = 0;

    sf::Sprite sprite;
    ObjectType type = ObjectType::CHAMPION;
    bool alive = true;
    void setVelocity_x(float x) {
        velocity_x = x;
    }
    void setVelocity_y(float y) {
        velocity_x = y;
    }
    float getVelocity_x() {
        return velocity_x;
    }
    float getVelocity_y() {
        return velocity_y;
    }
private:
    float velocity_x=0;
    float velocity_y=0;
};

