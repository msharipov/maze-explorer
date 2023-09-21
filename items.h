/* Item
*  |
*  |―― EmptyItem
*  |
*  |―― Weapon
*  |   |
*  |   |―― Spear
*  |   |―― Sword
*  |
*  |―― Armor
*  |   |
*  |   |―― Shield
*  |   |―― Cuirass
*  |   |―― Helmet
*/

#ifndef ITEMS_H
#define ITEMS_H

#include <stdlib.h>
#include <string>

// All item qualities must be lower than this.
#define MAX_ITEM_QUALITY 6

class Item {
public:
    virtual ~Item() {};

    // Returns key string that maps to the base name of the item.
    virtual std::string describe() const = 0;

    // Returns the quality of the item.
    virtual short getQuality() const = 0;

    // Indicates whether this is an empty item.
    // Use this before checking quality.
    virtual bool isEmpty() const = 0;
};


// Use this as a placeholder in inventory.
class EmptyItem : virtual public Item {
private:
    short quality;

public:
    EmptyItem();
    ~EmptyItem() {};

    bool isEmpty() const;

    // Returns a string that can be used to check identify empty items.
    std::string describe() const;
    
    // Fails an assert. Use isEmpty() to verify that item is not empty
    // before calling getQuality().
    short getQuality() const;
};


class Weapon : virtual public Item {
public:
    ~Weapon() {};  
    virtual double strike() const = 0;

    bool isEmpty() const;
};


class Spear : virtual public Weapon {
private:
    short quality;

public:
    
    // Creates a spear with random quality in [0, MAX_ITEM_QUALITY).
    Spear();

    // REQUIRES : MAX_ITEM_QUALITY > q >= 0
    // Creates a spear with specified quality q.
    Spear(short q);

    Spear &operator=(const Spear &other);
    ~Spear() {};

    // Returns the amount of damage dealt by the spear.
    double strike() const;

    // Returns the quality of the spear.
    short getQuality() const;

    // Returns a key string that maps to the name of the spear.
    std::string describe() const;
};


class Sword : virtual public Weapon {
private:
    short quality;

public:
    // Creates a sword with random quality in [0, MAX_ITEM_QUALITY).
    Sword();

    // REQUIRES : MAX_ITEM_QUALITY > q >= 0
    // Creates a spear with specified quality q.
    Sword(short q);

    Sword &operator=(const Sword &other);
    ~Sword() {};

    // Returns the amount of damage dealt by the sword.
    double strike() const;

    // Returns the quality of the sword.
    short getQuality() const;

    // Returns a key string that maps to the name of the sword.
    std::string describe() const;
};


class Armor : virtual public Item {
public:
    ~Armor() {}
    virtual double getArmor() const = 0;

    bool isEmpty() const;
};


class Shield: virtual public Armor {
private:
    short quality;

public:
    // Creates a shield with random quality in [0, MAX_ITEM_QUALITY).
    Shield();

    // REQUIRES : MAX_ITEM_QUALITY > q >= 0
    // Creates a shield with specified quality q.
    Shield(short q);

    Shield &operator=(const Shield &other);
    ~Shield() {};

    // Returns the shield's armor value.
    double getArmor() const;

    // Returns the shield's quality.
    short getQuality() const;

    // Returns a key string that maps to the name of the shield.
    std::string describe() const;
};


class Cuirass: virtual public Armor {
private:
    short quality;

public:
    // Creates a cuirass with random quality in [0, MAX_ITEM_QUALITY).
    Cuirass();

    // REQUIRES : MAX_ITEM_QUALITY > q >= 0
    // Creates a cuirass with specified quality q.
    Cuirass(short q);

    Cuirass &operator=(const Cuirass &other);
    ~Cuirass() {};

    // Returns the cuirass's armor value.
    double getArmor() const;
    
    // Returns the cuirass's quality.
    short getQuality() const;

    // Returns a key string that maps to the name of the cuirass.
    std::string describe() const;
};


class Helmet: virtual public Armor {
private:
    short quality;

public:
    // Creates a helmet with random quality in [0, MAX_ITEM_QUALITY).
    Helmet();

    // REQUIRES : MAX_ITEM_QUALITY > q >= 0
    // Creates a helmet with specified quality q.
    Helmet(short q);

    Helmet &operator=(const Helmet &other);
    ~Helmet() {};

    // Returns the helmet's armor value.
    double getArmor() const;
    
    // Returns the helmet's quality.
    short getQuality() const;

    // Returns a key string that maps to the name of the helmet.
    std::string describe() const;
};
#endif
