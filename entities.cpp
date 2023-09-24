#include <typeinfo>
#include <cmath>
#include "entities.h"

#define DEFAULT_PLAYER_MAX_HP 100

// ============================================================================
// Entity -> Player

// Creates a player without equipment at the default starting location (4,4)
Player::Player() : max_health(DEFAULT_PLAYER_MAX_HP), health(100), x(4), y(4), 
                   z(0), SYMBOL("SYMBOL_PLAYER"), inventory(NULL),
                   hand(NULL), offhand(NULL), head(NULL), chest(NULL) {

    Item * inventory[INV_SIZE];
    for (size_t i = 0; i < INV_SIZE; i++) {
        inventory[i] = new EmptyItem();
    }
    hand = new EmptyItem();
    offhand = new EmptyItem();
    head = new EmptyItem();
    chest = new EmptyItem();

}

Player::Player(short Z, short Y, short X, short HP, Weapon * wep, 
               Shield * shld, Helmet * helm, Cuirass * crs, Item * inv) 
               : max_health(DEFAULT_PLAYER_MAX_HP), health(HP), x(X), y(Y), 
                 z(Z), SYMBOL("SYMBOL_PLAYER"), inventory(NULL), hand(NULL),
                 offhand(NULL), head(NULL), chest(NULL) {

    inventory = inv;
    hand = wep;
    offhand = shld;
    head = helm;
    chest = crs;
}

Player & Player::operator=(const Player &other){
    if (this == &other) return *this;

    for (size_t i = 0; i < INV_SIZE; i++) {
        delete inventory[i];
        *(inventory[i]) = new Item(other[i]);
    } 

    max_health = other.getMaxHP();
    health = other.getHP();
    return *this;
}

Player::Player(const Player &other) : Player() {
    *this=other;
}