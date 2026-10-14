#pragma once
#include <string>
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
    VoidBearer(std::string charName, int hp, int atk, int def);
    virtual ~VoidBearer() = default; // Virtual destructor for inheritance

    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    bool isAlive() const;
    ArtPalette getCurrentPalette() const;

    virtual void switchPalette(ArtPalette newPalette);
    virtual void takeDamage(int damage);


    virtual void executeSkillOne(VoidBearer& target);
    virtual void executeSkillTwo(VoidBearer& target);
};