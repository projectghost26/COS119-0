#include "Eagle.h"
#include <iostream>
#include <cstdlib>

// Constructor taking name, hp, atk, and def as defined in Eagle.h
Eagle::Eagle(std::string name, int hp, int atk, int def)
    : VoidBearer(name, hp, atk, def) {
}

// ==========================================
// STABILIZED ARTS
// ==========================================

void Eagle::Windswept(VoidBearer& target) {
    if (currentPalette != ArtPalette::Stabilized) {
        std::cout << name << " must be in the Stabilized palette to use Windswept!\n";
        return;
    }

    // Dialogue line and one-hit mechanic[cite: 5]
    std::cout << "\n\"Sorry did i trip you\" - " << name << " casts **Windswept**!\n";

    int damage = attackPower + 5;
    target.takeDamage(damage);
}

void Eagle::CalmingWind(VoidBearer& target) {
    if (currentPalette != ArtPalette::Stabilized) {
        std::cout << name << " must be in the Stabilized palette to use Calming Wind!\n";
        return;
    }

    // Dialogue line and 5 HP heal mechanic[cite: 5]
    std::cout << "\n\"You aint killin me just yet\" - " << name << " casts **Calming Wind**!\n";

    health += 5;
    if (health > maxHealth) {
        health = maxHealth;
    }
    std::cout << name << " recovers 5 HP! (HP: " << health << "/" << maxHealth << ")\n";
}

// ==========================================
// REVERBED ARTS
// ==========================================

void Eagle::RadianceBlaze(VoidBearer& target) {
    if (currentPalette != ArtPalette::Reverbed) {
        std::cout << name << " must be in the Reverbed palette to use Radiance Blaze!\n";
        return;
    }

    // Dialogue line and 4-hit multi-strike[cite: 5]
    std::cout << "\n\"AAAAND BURN\" - " << name << " unleashes **Radiance Blaze**!\n";

    for (int i = 1; i <= 4; ++i) {
        std::cout << "Hit " << i << ": ";
        int hitDamage = (attackPower / 4) + (rand() % 4);
        target.takeDamage(hitDamage);
    }

    // 5% chance of damage over time check[cite: 5]
    int dotRoll = rand() % 100;
    if (dotRoll < 5) {
        std::cout << target.getName() << " is scorched, suffering from a Void Burn, causing Damage over Time\n";
    }
}

void Eagle::Wildfire(VoidBearer& target) {
    if (currentPalette != ArtPalette::Reverbed) {
        std::cout << name << " must be in the Reverbed palette to use Wildfire!\n";
        return;
    }

    // Dialogue line, 1 hit, and attack-down effect[cite: 5]
    std::cout << "\n\"Feelin Hot yet?\" - " << name << " casts **Wildfire**!\n";

    int damage = attackPower + 8;
    target.takeDamage(damage);

    std::cout << target.getName() << "'s offensive capabilities are seared, lowering their attack power!\n";
}