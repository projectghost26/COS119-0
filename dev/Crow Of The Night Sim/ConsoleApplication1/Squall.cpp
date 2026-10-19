#include "Squall.h"
#include <iostream>
#include <cstdlib>

// Constructor initializes Squall and sets invulnerability flag to false

Squall::Squall(std::string name, int hp, int atk, int def)
    : VoidBearer(name, hp, atk, def) {
}
void Squall::executeSkillOne(VoidBearer& target) {
    if (currentPalette == ArtPalette::Stabilized) {
        GlacialDefence(target);
    }
    else {
        MetalRing(target);
    }
}

void Squall::executeSkillTwo(VoidBearer& target) {
    if (currentPalette == ArtPalette::Stabilized) {
        ArcticHook(target);
    }
    else {
        Headshaker(target);
    }
}
// Overridden takeDamage handles the "no damage on next turn" effect
void Squall::takeDamage(int damage) {
    if (invulnerableNextTurn) {
        std::cout << name << " takes zero damage as Metal Ring's aftershock protects them!\n";
        invulnerableNextTurn = false; // Reset the guard after blocking one turn
        return;
    }

    // Otherwise, process normal damage using the base class logic
    VoidBearer::takeDamage(damage);
}

// ==========================================
// STABILIZED ARTS
// ==========================================

void Squall::GlacialDefence(VoidBearer& target) {
    if (currentPalette != ArtPalette::Stabilized) {
        std::cout << name << " must be in the Stabilized palette to use Glacial Defence!\n";
        return;
    }

    std::cout << "\n\"Land a hit I wont feel a thing\" - " << name << " uses **Glacial Defence**!\n";
    defense += 5;
    std::cout << name << "'s defense hardens! (Current Defense: " << defense << ")\n";
}

void Squall::ArcticHook(VoidBearer& target) {
    if (currentPalette != ArtPalette::Stabilized) {
        std::cout << name << " must be in the Stabilized palette to use Arctic Hook!\n";
        return;
    }

    std::cout << "\n\"Need an Ice Pack Mate?\" - " << name << " executes **Arctic Hook**!\n";
    int damage = attackPower + 6;
    target.takeDamage(damage);
}

// ==========================================
// REVERBED ARTS
// ==========================================

void Squall::MetalRing(VoidBearer& target) {
    if (currentPalette != ArtPalette::Reverbed) {
        std::cout << name << " must be in the Reverbed palette to use Metal Ring!\n";
        return;
    }

    std::cout << "\n\"HEAR THE BELL RINGIN?... KNOCKOUT\" - " << name << " casts **Metal Ring**!\n";

    // 25% chance to deal 2x damage
    int roll = rand() % 100; // 0 to 99
    int damage = attackPower;

    if (roll < 25) {
        std::cout << "A sharp resonant strike! Deals 2x damage!\n";
        damage *= 2;
    }
    else {
        std::cout << "Standard impact.\n";
    }

    target.takeDamage(damage);

    // Set the flag so Squall takes 0 damage on the subsequent turn
    invulnerableNextTurn = true;
    std::cout << name << " ups their guard, take no damage on the next turn!\n";
}

void Squall::Headshaker(VoidBearer& target) {
    if (currentPalette != ArtPalette::Reverbed) {
        std::cout << name << " must be in the Reverbed palette to use Headshaker!\n";
        return;
    }

    std::cout << "\n\"Oooo feelin Dizzy there Bud?\" - " << name << " lands **Headshaker**!\n";

    int damage = attackPower + 4;
    target.takeDamage(damage);

    int dizzyRoll = rand() % 100;
    if (dizzyRoll < 2) {
        std::cout << target.getName() << " is too dizzy and will miss their next turn!\n";
    }
}