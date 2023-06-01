#include "Champion.h"

Champion::Champion(float x, float y, sf::Texture& tex) : AnimowaneAssety(x, y) {
    type = ObjectType::CHAMPION;
}

void Champion::collide(AnimowaneAssety& col) {
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
        if (col.type == ObjectType::AID && lives < 3) {
            lives++;
        }
        if (col.type == ObjectType::NET) {

        }
        if (col.type == ObjectType::BULLET) {

        }
    }
}

void Champion::Animuj(sf::RenderWindow& window) {
    if (getPosition().x < 0.0) {
        setPosition(window.getSize().x, getPosition().y);
    }
    if (getPosition().x > window.getSize().x) {
        setPosition(0.0, getPosition().y);
    }

    window.draw(sprite);
}
void Champion::notify(sf::Event& ev) {

};

int Champion::getPoints() {
    return points;
}

int Champion::getLives() {
    return lives;
}