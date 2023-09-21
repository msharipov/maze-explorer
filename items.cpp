#include "items.h"
#include <string>
#include <cassert>

#define SPEAR_DAMAGE_MULTIPLIER 1.6
#define SWORD_DAMAGE_MULTIPLIER 2.5

#define SHIELD_ARMOR_MULTIPLIER 0.5
#define CUIRASS_ARMOR_MULTIPLIER 1.0
#define HELMET_ARMOR_MULTIPLIER 0.5

// ============================================================================
// Item -> EmptyItem
EmptyItem::EmptyItem() : quality(-1) {}

bool EmptyItem::isEmpty() const {
    return true;
}

std::string EmptyItem::describe() const {
    return "ITEM_NAME_EMPTY";
}

short EmptyItem::getQuality() const {
    assert(false && "ERROR: Attempting to get quality of an empty item!");
}

// ============================================================================
// Item -> Weapon

bool Weapon::isEmpty() const {
    return false;
}

// ============================================================================
// Item -> Weapon -> Spear

Spear::Spear() : quality(rand() % MAX_ITEM_QUALITY) {}

Spear::Spear(short q) : quality(q) {
    assert(q >= 0 && q < MAX_ITEM_QUALITY
           && "ERROR: Cannot create Spear: Invalid quality!");
}

Spear & Spear::operator=(const Spear &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Spear::strike() const {
    return SPEAR_DAMAGE_MULTIPLIER*(0.5*quality + 1);
}

short Spear::getQuality() const {
    return quality;
}

std::string Spear::describe() const {
    assert(quality >= 0
           && quality < MAX_ITEM_QUALITY
           && "ERROR: Cannot describe Spear: Invalid quality!");

    std::string base("ITEM_NAME_SPEAR_");
    base += (char)('0' + quality);
    return base;
}

// ============================================================================
// Item -> Weapon -> Sword

Sword::Sword() : quality(rand() % MAX_ITEM_QUALITY) {}

Sword::Sword(short q) : quality(q % MAX_ITEM_QUALITY) {
    assert(q >= 0 && q < MAX_ITEM_QUALITY
           && "ERROR: Cannot create Sword: Invalid quality!");
}

Sword & Sword::operator=(const Sword &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Sword::strike() const {
    return SWORD_DAMAGE_MULTIPLIER*(0.5*quality + 1);
}

short Sword::getQuality() const {
    return quality;
}

std::string Sword::describe() const {
    assert(quality >= 0
           && quality < MAX_ITEM_QUALITY
           && "ERROR: Cannot describe Sword: Invalid quality!");

    std::string base("ITEM_NAME_SWORD_");
    base += (char)('0' + quality);
    return base;
}

// ============================================================================
// Item -> Armor

bool Weapon::isEmpty() const {
    return false;
}

// ============================================================================
// Item -> Armor -> Shield

Shield::Shield() : quality(rand() % MAX_ITEM_QUALITY) {}

Shield::Shield(short q) : quality(q) {
    assert(q >= 0 && q < MAX_ITEM_QUALITY
           && "ERROR: Cannot create Shield: Invalid quality!");
}

Shield & Shield::operator=(const Shield &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Shield::getArmor() const {
    return SHIELD_ARMOR_MULTIPLIER*(0.5*quality + 1);
}

short Shield::getQuality() const {
    return quality;
}

std::string Shield::describe() const {
    assert(quality >= 0
           && quality < MAX_ITEM_QUALITY
           && "ERROR: Cannot describe Shield: Invalid quality!");

    std::string base("ITEM_NAME_SHIELD_");
    base += (char)('0' + quality);
    return base;
}

// Item -> Armor -> Cuirass

Cuirass::Cuirass() : quality(rand() % MAX_ITEM_QUALITY) {}

Cuirass::Cuirass(short q) : quality(q) {
    assert(q >= 0 && q < MAX_ITEM_QUALITY
           && "ERROR: Cannot create Cuirass: Invalid quality!");
}

Cuirass & Cuirass::operator=(const Cuirass &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Cuirass::getArmor() const {
    return CUIRASS_ARMOR_MULTIPLIER*(0.5*quality + 1);
}

short Cuirass::getQuality() const {
    return quality;
}

std::string Cuirass::describe() const {
    assert(quality >= 0
           && quality < MAX_ITEM_QUALITY
           && "ERROR: Cannot describe Cuirass: Invalid quality!");

    std::string base("ITEM_NAME_CUIRASS_");
    base += (char)('0' + quality);
    return base;
}

// Item -> Armor -> Helmet

Helmet::Helmet() : quality(rand() % 6) {}

Helmet::Helmet(short q) : quality(q % 6) {}

Helmet & Helmet::operator=(const Helmet &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Helmet::getArmor() const {
    return HELMET_ARMOR_MULTIPLIER*(0.5*quality + 1);
}

short Helmet::getQuality() const {
    return quality;
}

std::string Helmet::describe() const{
    assert(quality >= 0
           && quality < MAX_ITEM_QUALITY
           && "ERROR: Cannot describe Helmet: Invalid quality!");

    std::string base("ITEM_NAME_HELMET_");
    base += (char)('0' + quality);
    return base;
}
