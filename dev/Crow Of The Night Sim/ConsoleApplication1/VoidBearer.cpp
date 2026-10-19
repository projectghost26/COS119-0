#include "VoidBearer.h"
#include <iostream>
#include <string>

VoidBearer::VoidBearer(const std::string& charName, int hp, int atk, int def)
    : name(charName), health(hp), maxHealth(hp), attackPower(atk), defense(def), currentPalette(ArtPalette::Stabilized) {
}
std::string VoidBearer::getName() const { return name; }
int VoidBearer::getHealth() const { return health; }
int VoidBearer::getMaxHealth() const { return maxHealth; }
bool VoidBearer::isAlive() const { return health > 0; }
ArtPalette VoidBearer::getCurrentPalette() const { return currentPalette; }

void VoidBearer::switchPalette(ArtPalette newPalette) {
    currentPalette = newPalette;
}

void VoidBearer::takeDamage(int damage) {
    int actualDamage = damage - defense;
    if (actualDamage < 1) actualDamage = 1; // Minimum 1 damage

    health -= actualDamage;
    if (health < 0) health = 0;

    std::cout << name << " took " << actualDamage << " damage! (HP: " << health << "/" << maxHealth << ")\n";
}