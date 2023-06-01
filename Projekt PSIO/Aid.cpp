#include "Aid.h"

void Aid::collide(AnimowaneAssety& col) {
    if (getGlobalBounds().intersects(col.getGlobalBounds())) {
        if (col.type == ObjectType::BULLET || col.type == ObjectType::BOMB || col.type == ObjectType::NET) {
            alive = false;
        }
    }
}

void Aid::animuj(sf::Window window) {

}

void Aid::notify(sf::Event ev) {

}