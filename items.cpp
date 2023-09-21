#include "items.h"
#include <string>

// Item -> EmptyItem

EmptyItem::EmptyItem() : quality(-1) {}

std::string EmptyItem::describe() const {
    return "EMPTY_ITEM";
}

short EmptyItem::getQuality() const {
    return -1;
}

// Item -> Weapon -> Spear

Spear::Spear() : quality(rand() % 6) {}

Spear::Spear(short q) : quality(q % 6) {}

Spear & Spear::operator=(const Spear &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Spear::strike() const {
    return 1.6 * quality;
}

short Spear::getQuality() const {
    return quality;
}

std::string Spear::describe() const {
    std::string modifier;
    switch (quality) {
    case 0:
        modifier = "Worthless Spear";
        break;
    case 1:
        modifier = "Flimsy Spear";
        break;
    case 2:
        modifier = "Fair Spear";
        break;
    case 3:
        modifier = "Robust Spear";
        break;
    case 4:
        modifier = "Pointy Spear";
        break;
    case 5:
        modifier = "Legendary Spear";
        break;
    }
    return modifier;
}

// Item -> Weapon -> Sword

Sword::Sword() : quality(rand() % 6) {}

Sword::Sword(short q) : quality(q % 6) {}

Sword & Sword::operator=(const Sword &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Sword::strike() const {
    return 2.5 * quality;
}

short Sword::getQuality() const {
    return quality;
}

std::string Sword::describe() const {
    std::string modifier;
    switch (quality) {
    case 0:
        modifier = "Shattered Sword";
        break;
    case 1:
        modifier = "Chipped Sword";
        break;
    case 2:
        modifier = "Dull Sword";
        break;
    case 3:
        modifier = "Sharp Sword";
        break;
    case 4:
        modifier = "Razor-Sharp Sword";
        break;
    case 5:
        modifier = "Legendary Sword";
        break;
    }
    return modifier;
}

// Item -> Armor -> Shield

Shield::Shield() : quality(rand() % 6) {}

Shield::Shield(short q) : quality(q % 6) {}

Shield & Shield::operator=(const Shield &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Shield::getArmor() const {
    return quality * 2.0 + 1;
}

short Shield::getQuality() const {
    return quality;
}

std::string Shield::describe() const {
    std::string modifier;
    switch (quality) {
    case 0:
        modifier = "Wooden Shield";
        break;
    case 1:
        modifier = "Copper Shield";
        break;
    case 2:
        modifier = "Bronze Shield";
        break;
    case 3:
        modifier = "Iron Shield";
        break;
    case 4:
        modifier = "Steel Shield";
        break;
    case 5:
        modifier = "Adamantine Shield";
        break;
    }
    return modifier;
}

// Item -> Armor -> Cuirass

Cuirass::Cuirass() : quality(rand() % 6) {}

Cuirass::Cuirass(short q) : quality(q % 6) {}

Cuirass & Cuirass::operator=(const Cuirass &other) {
    if (this != &other) {
        quality = other.getQuality();
    }
    return *this;
}

double Cuirass::getArmor() const {
    return quality * 3.0 + 1;
}

short Cuirass::getQuality() const {
    return quality;
}

std::string Cuirass::describe() const {
    std::string modifier;
    switch (quality) {
    case 0:
        modifier = "Tattered Cuirass";
        break;
    case 1:
        modifier = "Rusty Cuirass";
        break;
    case 2:
        modifier = "Dented Cuirass";
        break;
    case 3:
        modifier = "Fine Cuirass";
        break;
    case 4:
        modifier = "Polished Cuirass";
        break;
    case 5:
        modifier = "Mithril Cuirass";
        break;
    }
    return modifier;
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
    return quality * 1.2 + 1;
}

short Helmet::getQuality() const {
    return quality;
}

std::string Helmet::describe() const{
    std::string modifier;
    switch (quality) {
    case 0:
        modifier = "Battered Helmet";
        break;
    case 1:
        modifier = "Punctured Helmet";
        break;
    case 2:
        modifier = "Clunky Helmet";
        break;
    case 3:
        modifier = "Elegant Helmet";
        break;
    case 4:
        modifier = "Magnificent Helmet";
        break;
    case 5:
        modifier = "Epic Helmet";
        break;
    }
    return modifier;
}
