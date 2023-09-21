#ifndef ITEMS_H
#define ITEMS_H

#include <stdlib.h>
#include <string>

class Item {
public:
    virtual ~Item() {};
    virtual std::string describe() const = 0;
    virtual short getQuality() const = 0;
};


class EmptyItem : virtual public Item {
private:
    short quality;

public:
    EmptyItem();
    ~EmptyItem() {};

    std::string describe() const;
    short getQuality() const;
};


class Weapon : virtual public Item {
public:
    ~Weapon() {};  
    virtual double strike() const = 0;
};


class Spear : virtual public Weapon {
private:
    short quality;

public:
    Spear();
    Spear(short q);
    Spear &operator=(const Spear &other);
    ~Spear() {};

    double strike() const;
    short getQuality() const;
    std::string describe() const;
};


class Sword : virtual public Weapon {
private:
    short quality;

public:
    Sword();
    Sword(short q);
    Sword &operator=(const Sword &other);
    ~Sword() {};

    double strike() const;
    short getQuality() const;
    std::string describe() const;
};


class Armor : virtual public Item {
public:
    ~Armor() {}
    virtual double getArmor() const = 0; 
};


class Shield: virtual public Armor {
private:
    short quality;

public:
    Shield();
    Shield(short q);
    Shield &operator=(const Shield &other);
    ~Shield() {};

    double getArmor() const;
    short getQuality() const;
    std::string describe() const;
};


class Cuirass: virtual public Armor {
private:
    short quality;

public:
    Cuirass();
    Cuirass(short q);
    Cuirass &operator=(const Cuirass &other);
    ~Cuirass() {};

    double getArmor() const;
    short getQuality() const;
    std::string describe() const;
};


class Helmet: virtual public Armor {
private:
    short quality;

public:
    Helmet();
    Helmet(short q);
    Helmet &operator=(const Helmet &other);
    ~Helmet() {};

    double getArmor() const;
    short getQuality() const;
    std::string describe() const;
};
#endif
