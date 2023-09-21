#ifndef ITEMS_H
#define ITEMS_H

#include <stdlib.h>
#include <string>

class Item {
public:
    virtual std::string describe() const = 0;
    virtual short getQuality() const = 0;
    virtual ~Item() {}
};


class EmptyItem : virtual public Item {
private:
    short quality;

public:
    EmptyItem() : quality(-1) {}

    std::string describe() const {
        return "EMPTY_ITEM";
    }

    short getQuality() const {
        return -1;
    }

    ~EmptyItem() {}
};


class Weapon : virtual public Item {
public:
    virtual double strike() const = 0;
    ~Weapon() {}
};


class Spear : virtual public Weapon {
private:
    short quality;

public:
    Spear() : quality(rand() % 6) {}

    Spear(short q) : quality(q % 6) {}

    Spear &operator=(const Spear &other) {
        if (this != &other)
        {
            quality = other.getQuality();
        }
        return *this;
    }

    double strike() const {
        return 1.6 * quality;
    }

    short getQuality() const {
        return quality;
    }

    std::string describe() const {
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

    ~Spear() {}
};

class Sword : virtual public Weapon {
private:
    short quality;

public:
    Sword() : quality(rand() % 6) {}

    Sword(short q) : quality(q % 6) {}

    Sword &operator=(const Sword &other) {
        if (this != &other)
        {
            quality = other.getQuality();
        }
        return *this;
    }

    double strike() const {
        return 2.5 * quality;
    }

    short getQuality() const {
        return quality;
    }

    std::string describe() const {
        std::string modifier;
        switch (quality)
        {
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

    ~Sword() {}
};


class Armor : virtual public Item {
public:
    virtual double getArmor() const = 0;

    ~Armor() {}
};


class Shield: virtual public Armor {
private:
    short quality;

public:
    Shield() : quality(rand() % 6) {}

    Shield(short q) : quality(q % 6) {}

    double getArmor() const {
        return quality * 2.0 + 1;
    }

    short getQuality() const {
        return quality;
    }

    std::string describe() const {
        std::string modifier;
        switch (quality)
        {
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

    ~Shield() {}
};


class Cuirass: virtual public Armor
{
private:
    short quality;

public:
    Cuirass() : quality(rand() % 6) {}

    Cuirass(short q) : quality(q % 6) {}

    double getArmor() const {
        return quality * 3.0 + 1;
    }

    short getQuality() const {
        return quality;
    }

    std::string describe() const {
        std::string modifier;
        switch (quality)
        {
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

    ~Cuirass() {}
};


class Helmet: virtual public Armor
{
private:
    short quality;

public:
    Helmet() : quality(rand() % 6) {}

    Helmet(short q) : quality(q % 6) {}

    double getArmor() const {
        return quality * 1.2 + 1;
    }

    short getQuality() const {
        return quality;
    }

    std::string describe() {
        std::string modifier;
        switch (quality)
        {
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

    ~Helmet() {}
};
#endif
