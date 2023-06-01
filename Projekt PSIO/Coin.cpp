#include "Coin.h"

Coin::Coin(float x, float y) : AnimowaneAssety(x, y) {
    type = ObjectType::COIN;
}

void Coin::collide(AnimowaneAssety& col) {
    if (getGlobalBounds().intersects(col.getGlobalBounds())) {
        if (col.type == ObjectType::CHAMPION || col.type == ObjectType::BOMB) {
            alive = false;
        }
    }
    if (col.type == ObjectType::BULLET) {
        alive = false;
    }
    if (col.type == ObjectType::NET) {

    }
    if (col.type == ObjectType::CHAMPION) {

    }
}
void Coin::Animuj(sf::RenderWindow& window){
        sprite.move(0.0, 0.1);
        if (getPosition().x < 0.0||getPosition().x > window.getSize().x) {
            setVelocity_x(getVelocity_x()*-1);
        }

        if (getPosition().y + getGlobalBounds().height > window.getSize().y) {
            setPosition(getPosition().x, window.getSize().y - getGlobalBounds().height);

        }
        window.draw(sprite);
}
void Coin::notify(sf::Event& ev) {

};