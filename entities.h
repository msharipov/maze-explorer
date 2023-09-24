#ifndef ENTITIES_H
#define ENTITIES_H
#include "items.h"

// The size of all entities' inventories
#define INV_SIZE 5

class Entity {
public:
    virtual short getHP() const = 0;
    virtual short getMaxHP() const = 0;
    virtual Item & operator[](short pos) const = 0;
    virtual void move(short dir) = 0;
    virtual short getX() const = 0;
    virtual short getY() const = 0;
    virtual short getDepth() const = 0;
    virtual const std::string getName() const = 0;
    virtual const std::string getSymbol() const = 0;
    virtual ~Entity() {};
};


class Player : virtual public Entity {
    short max_health, health;
    size_t x, y, z;
    const std::string SYMBOL;
    Item *inventory;
    Item *hand, *offhand, *head, *chest;

public:
    // Creates a player at the default starting position
    Player();
    Player(short Z, short Y, short X, short HP, Weapon * wep, 
           Shield * shld, Helmet * helm, Cuirass * crs, Item * inv);
    Player & operator=(const Player &other);
    Player(const Player &other);

    void teleport(short X, short Y, short Z)
    {
        x = X;
        y = Y;
        z = Z;
    }

    short getWepValue() const
    {
        short p_wep = -1;
        if (typeid(*hand) == typeid(Spear))
        {
            p_wep = hand->getQuality();
        }
        if (typeid(*hand) == typeid(Sword))
        {
            p_wep = 6 + hand->getQuality();
        }
        return p_wep;
    }

    std::string getWepName() const
    {
        return hand->describe();
    }

    short getOffValue() const
    {
        return offhand->getQuality();
    }

    std::string getOffName() const
    {
        return offhand->describe();
    }

    short getChestValue() const
    {
        return chest->getQuality();
    }

    std::string getChestName() const
    {
        return chest->describe();
    }

    short getHelmValue() const
    {
        return head->getQuality();
    }

    std::string getHelmName() const
    {
        return head->describe();
    }

    void operator+(short healing)
    {
        health = (health + healing) > max_health ? max_health
                                                 : health + healing;
    }

    void operator-(short damage)
    {
        health -= damage;
    }

    short getHP() const
    {
        return health;
    }

    double getArmor() const
    {
        double output = 0.0;
        if (offhand != NULL)
        {
            output += offhand->getArmor();
        }
        if (head != NULL)
        {
            output += head->getArmor();
        }
        if (chest != NULL)
        {
            output += chest->getArmor();
        }
        return output;
    }

    short getMaxHP() const
    {
        return max_health;
    }
    short getX() const
    {
        return x;
    }
    short getY() const
    {
        return y;
    }
    short getDepth() const
    {
        return z;
    }
    const std::string getName() const
    {
        return "Player";
    }
    Item &operator[](short pos) const
    {
        return *inventory[pos];
    }
    void claim(Item *stuff)
    {
        for (size_t pos = 0; pos < INV_SIZE; pos++)
        {
            if (typeid(*inventory[pos]) == typeid(EmptyItem))
            {
                inventory[pos] = stuff;
                pos = INV_SIZE;
            }
        }
    }
    void equip(short spot)
    {
        Item *temp;
        if (typeid(*inventory[spot]) == typeid(Sword))
        {
            temp = new Sword(dynamic_cast<Sword &>(*inventory[spot]));
            *inventory[spot] = *hand;
            hand = new Sword(dynamic_cast<Sword &>(*temp));
        }
        if (typeid(*inventory[spot]) == typeid(Spear))
        {
            temp = inventory[spot];
            inventory[spot] = hand;
            hand = dynamic_cast<Spear *>(temp);
        }
        if (typeid(*inventory[spot]) == typeid(Shield))
        {
            temp = inventory[spot];
            inventory[spot] = offhand;
            offhand = dynamic_cast<Shield *>(temp);
        }
        if (typeid(*inventory[spot]) == typeid(Cuirass))
        {
            temp = inventory[spot];
            inventory[spot] = chest;
            chest = dynamic_cast<Cuirass *>(temp);
        }
        if (typeid(*inventory[spot]) == typeid(Helmet))
        {
            temp = inventory[spot];
            inventory[spot] = head;
            head = dynamic_cast<Helmet *>(temp);
        }
    }
    void discard(short spot)
    {
        for (size_t pos = spot; pos < INV_SIZE; pos++)
        {
            if (pos + 1 < INV_SIZE)
            {
                inventory[pos] = inventory[pos + 1];
            }
            else
            {
                inventory[pos] = new EmptyItem();
            }
        }
    }
    const std::string getSymbol() const
    {
        return SYMBOL;
    }
    short attack(double armor)
    {
        double base = hand->strike() + rand() % 8;
        return static_cast<short>(floor(base * 10 / armor));
    }
    void move(short dir)
    {
        x += (dir % 2) * (2 - dir);
        y += ((dir + 1) % 2) * (1 - dir);
    }
    void climb(short dir)
    {
        z += dir;
    }
    ~Player(void)
    {
        for (size_t pos = 0; pos < INV_SIZE; pos++)
        {
            delete inventory[pos];
            inventory[pos] = NULL;
        }
        delete[] inventory;
        inventory = NULL;
    }
};

class Treasure : virtual public Entity
{
    short x, y, z;
    Item *placeholder;

public:
    Treasure(short Z, short Y, short X) : x(X), y(Y), z(Z), placeholder(NULL)
    {
        placeholder = new EmptyItem();
    }
    Treasure(Treasure &other) : Entity(), x(other.getX()), y(other.getY()),
                                z(other.getDepth()), placeholder(NULL)
    {
        placeholder = new EmptyItem();
    }
    Treasure &operator=(Treasure &other)
    {
        if (this != &other)
        {
            x = other.getX();
            y = other.getY();
            z = other.getDepth();
            *placeholder = other[0];
        }
        return *this;
    }
    short getX() const
    {
        return x;
    }
    short getY() const
    {
        return y;
    }
    short getDepth() const
    {
        return z;
    }
    const std::string getName() const
    {
        return "Treasure";
    }
    const std::string getSymbol() const
    {
        return "\033[48;5;236m\033[38;5;226mâ\230¼\033[0m";
    }
    Item &operator[](short nope) const
    {
        nope++;
        return *placeholder;
    }
    short getHP() const
    {
        return 0;
    }
    short getMaxHP() const
    {
        return 0;
    }
    void move(short nope)
    {
        nope++;
    }
    ~Treasure(void)
    {
        delete placeholder;
        placeholder = NULL;
    }
};

class Monster : virtual public Entity
{
public:
    virtual short attack(Player *p) = 0;
    virtual bool isDead(void) const = 0;
    virtual bool checkKill(void) = 0;
    virtual std::string getWepName() const = 0;
    virtual std::string getArmName() const = 0;
    virtual double getArmor() const = 0;
    virtual void operator-(short damage) = 0;
    virtual Weapon *getWLoot() = 0;
    virtual Armor *getALoot() = 0;
    ~Monster() {}
};
class LizardMan : virtual public Monster
{
    short x, y, z, health;
    bool dead;
    Weapon *w_loot;
    Armor *a_loot;
    const short max_health, STR;

public:
    LizardMan(short Z, short Y, short X, short HP = 20,
              short wep = rand() % 12, short arm = rand() % 18) : x(X),
                                                                  y(Y), z(Z),
                                                                  health(HP), dead(false),
                                                                  w_loot(NULL),
                                                                  a_loot(NULL),
                                                                  max_health(20), STR(5)
    {
        switch (wep / 6)
        {
        case 0:
            w_loot = new Spear(wep);
            break;
        case 1:
            w_loot = new Sword(wep);
            break;
        }
        switch (arm / 6)
        {
        case 0:
            a_loot = new Helmet(arm);
            break;
        case 1:
            a_loot = new Cuirass(arm);
            break;
        case 2:
            a_loot = new Shield(arm);
            break;
        }
    }
    LizardMan(const LizardMan &other) : Entity(), Monster(), x(other.getX()),
                                        y(other.getY()), z(other.getDepth()),
                                        health(other.getHP()),
                                        dead(other.isDead()),
                                        w_loot(NULL), a_loot(NULL),
                                        max_health(20), STR(5)
    {
        x = other.getX();
        y = other.getY();
        z = other.getDepth();
        if (typeid(other[0]) == typeid(Spear))
        {
            w_loot = new Spear(other[0].getQuality());
        }
        if (typeid(other[0]) == typeid(Sword))
        {
            w_loot = new Sword(other[0].getQuality());
        }
        if (typeid(other[1]) == typeid(Helmet))
        {
            a_loot = new Helmet(other[1].getQuality());
        }
        if (typeid(other[1]) == typeid(Cuirass))
        {
            a_loot = new Cuirass(other[1].getQuality());
        }
        if (typeid(other[1]) == typeid(Shield))
        {
            a_loot = new Shield(other[1].getQuality());
        }
    }
    LizardMan &operator=(const LizardMan &other)
    {
        if (this != &other)
        {
            x = other.getX();
            y = other.getY();
            z = other.getDepth();
            health = other.getHP();
            dead = other.isDead();
            if (typeid(other[0]) == typeid(Spear))
            {
                w_loot = new Spear(other[0].getQuality());
            }
            if (typeid(other[0]) == typeid(Sword))
            {
                w_loot = new Sword(other[0].getQuality());
            }
            if (typeid(other[1]) == typeid(Helmet))
            {
                a_loot = new Helmet(other[1].getQuality());
            }
            if (typeid(other[1]) == typeid(Cuirass))
            {
                a_loot = new Cuirass(other[1].getQuality());
            }
            if (typeid(other[1]) == typeid(Shield))
            {
                a_loot = new Shield(other[1].getQuality());
            }
        }
        return *this;
    }
    Item &operator[](short sel) const
    {
        Item *p;
        if (sel == 0)
        {
            p = w_loot;
        }
        else
        {
            p = a_loot;
        }
        return *p;
    }
    short getDepth() const
    {
        return z;
    }
    short getX() const
    {
        return x;
    }
    short getY() const
    {
        return y;
    }
    bool isDead() const
    {
        return dead;
    }
    short getHP() const
    {
        return health;
    }
    short getMaxHP() const
    {
        return max_health;
    }
    void move(short dir)
    {
        x += (dir % 2) * (2 - dir);
        y += ((dir + 1) % 2) * (1 - dir);
    }
    const std::string getName() const
    {
        return "Lizard Man";
    }
    bool checkKill()
    {
        if (health <= 0)
        {
            dead = true;
        }

        return dead;
    }
    Weapon *getWLoot()
    {
        return w_loot;
    }
    Armor *getALoot()
    {
        return a_loot;
    }
    void operator-(short damage)
    {
        health -= damage;
    }
    std::string getWepName() const
    {
        return w_loot->describe();
    }
    std::string getArmName() const
    {
        return a_loot->describe();
    }
    const std::string getSymbol() const
    {
        return "\033[48;5;234m\033[38;5;40mÏ \033[0m";
    }
    short attack(Player *p)
    {
        double base = w_loot->strike() + rand() % STR;
        *p - static_cast<short>(floor(8 * base / (p->getArmor())));
        return static_cast<short>(floor(8 * base / (p->getArmor())));
    }
    double getArmor() const
    {
        return a_loot->getArmor();
    }
    ~LizardMan() {}
};
#endif