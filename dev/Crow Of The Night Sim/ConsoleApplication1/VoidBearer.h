#pragma once
#include <string>
#include <iostream>
// Voidbearer template For the 4 Operatives
enum class ArtPalette {
    Stabilized,
    Reverbed
};

class VoidBearer {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int defense;
    ArtPalette currentPalette;

public:
    VoidBearer();
    VoidBearer( const std::string& charName, int hp, int atk, int def);
    virtual ~VoidBearer() = default; // Virtual destructor for inheritance

    std::string getName() const;
    int getHealth() const { return health; };
    int getMaxHealth() const;
    bool isAlive() const;
    ArtPalette getCurrentPalette() const;

    virtual void switchPalette(ArtPalette newPalette);
    virtual void takeDamage(int damage);


    virtual void executeSkillOne(VoidBearer& target) = 0;
    virtual void executeSkillTwo(VoidBearer& target) = 0;

    //health cap debuff for Raven
    void reduceMaxHealth(int percentage) {
        int reduction = maxHealth * percentage / 100;
        maxHealth -= reduction;
        if (health > maxHealth) {
            health = maxHealth; // Clamp current health if it exceeds new max
        }
        std::cout << name << "'s Max Health is reduced! (New Max HP: " << maxHealth << ")\n";
    }
};