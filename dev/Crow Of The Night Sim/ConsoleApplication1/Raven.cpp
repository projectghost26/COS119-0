#include "Raven.h"
#include <iostream>
#include <cstdlib>

// Default constructor using Raven's exact stats: 75 HP, 45 Attack, 5 Defense[cite: 8]
Raven::Raven()
    : VoidBearer("Raven", 75, 45, 5), hasDoppleganger(false) {
}

// Parameterized constructor
Raven::Raven(std::string name, int hp, int atk, int def)
    : VoidBearer(name, hp, atk, def), hasDoppleganger(false) {
}

// Switching art palettes clears the Doppleganger effect
void Raven::switchPalette(ArtPalette newPalette) {
    currentPalette = newPalette;

    if (hasDoppleganger) {
        hasDoppleganger = false;
        std::cout << name << "'s Doppleganger dissipates due to the palette shift.\n";
    }
}
// ==========================================
// STABILIZED ARTS
// ==========================================

void Raven::Doppleganger(VoidBearer& target) {
    if (currentPalette != ArtPalette::Stabilized) {
        std::cout << name << " must be in the Stabilized palette to use Doppleganger!\n";
        return;
    }

    std::cout << "\n\"seeing double?\" - " << name << " invokes **Doppleganger**!\n";
    hasDoppleganger = true; // Adds an additional attack instance for the next art
    std::cout << "An illusory duplicate mirrors " << name << ", priming an extra attack instance!\n";
}

void Raven::ShadowStrike(VoidBearer& target) {
    if (currentPalette != ArtPalette::Stabilized) {
        std::cout << name << " must be in the Stabilized palette to use Shadow Strike!\n";
        return;
    }

    std::cout << "\n\"Strike from the shadows!\" - " << name << " executes **Shadow Strike**!\n";

    int hits = 2; // Default 2 hits

    // If Doppleganger is active, add an extra attack instance and consume it
    if (hasDoppleganger) {
        hits += 1;
        std::cout << "Doppleganger joins the fray, adding an extra attack instance!\n";
        hasDoppleganger = false;
    }

    for (int i = 1; i <= hits; ++i) {
        std::cout << "Hit " << i << ": ";
        int damage = (attackPower / 2) + (rand() % 6);
        target.takeDamage(damage);
    }
}

// ==========================================
// REVERBED ARTS
// ==========================================

void Raven::ExistenceErasure(VoidBearer& target) {
    if (currentPalette != ArtPalette::Reverbed) {
        std::cout << name << " must be in the Reverbed palette to use Existence Erasure!\n";
        return;
    }

    std::cout << "\n\"you are fading\" - " << name << " channels **Existence Erasure**!\n";

    int damage = attackPower + 10;
    target.takeDamage(damage);

    // 15% chance to cap/reduce enemy max health by 10%[cite: 8]
    int roll = rand() % 100;
    if (roll < 15) {
        std::cout << "CRITICAL REALITY TEAR! The target's maximum health is capped and reduced by 10%!\n";
        target.reduceMaxHealth(10); // Relies on the helper method added to VoidBearer
    }
    else {
        std::cout << "The erasure attempt flickers, but the target's core remains anchored.\n";
    }

   
}

void Raven::NullAndVoid(VoidBearer& target) {
    if (currentPalette != ArtPalette::Reverbed) {
        std::cout << name << " must be in the Reverbed palette to use Null and Void!\n";
        return;
    }

    std::cout << "\n\"Everything becomes forgetten sooner or later\" - " << name << " unleashes **Null and Void**!\n";

    int hits = 3; // Default 3 hits[cite: 8]

   

    for (int i = 1; i <= hits; ++i) {
        std::cout << "Hit " << i << ": ";
        int hitDamage = (attackPower / 3) + (rand() % 4);
        target.takeDamage(hitDamage);

        // 3% chance per hit to cap enemy max health by 5%[cite: 8]
        int roll = rand() % 100;
        if (roll < 3) {
            std::cout << "A void fracture opens on hit " << i << "! Enemy max health capped by 5%!\n";
            target.reduceMaxHealth(5); // Relies on the helper method added to VoidBearer
        }
    }
}