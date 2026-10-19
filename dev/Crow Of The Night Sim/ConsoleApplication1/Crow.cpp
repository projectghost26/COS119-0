#include "Crow.h"
#include <iostream>
#include <cstdlib>

// Constructor using Crow's exact stats: 150 HP, 35 Attack, 15 Defense
Crow::Crow() : VoidBearer("Crow", 150, 35, 15) {}

Crow::Crow(std::string name, int hp, int atk, int def)
    : VoidBearer(name, hp, atk, def) {
}

// ==========================================
// STABILIZED ARTS
// ==========================================

void Crow::BreakthroughEdge(VoidBearer& target) {
    if (getCurrentPalette() != ArtPalette::Stabilized) {
        std::cout << getName() << " must be in the Stabilized palette to use Breakthrough Edge!\n";
        return;
    }

    std::cout << "\n\"BREAK... TRHOUGH\" - " << getName() << " casts **Breakthrough Edge**!\n";

    // 1 Hit Attack
    int damage = attackPower + 10;
    target.takeDamage(damage);
}

void Crow::StormFlare(VoidBearer& target) {
    if (getCurrentPalette() != ArtPalette::Stabilized) {
        std::cout << getName() << " must be in the Stabilized palette to use Storm Flare!\n";
        return;
    }

    std::cout << "\n\"Tosing Flare\" - " << getName() << " casts **Storm Flare**!\n";

    // Initial impact damage + sets up Damage Over Time (DoT)
    int initialDamage = attackPower + 5;
    target.takeDamage(initialDamage);

    // FIXED: Added missing quote and insertion operator (<<)
    std::cout << target.getName() << " is caught in a lingering storm flare, preparing to take void damage next turn!\n";
}

// ==========================================
// REVERBED ARTS
// ==========================================

void Crow::ChromaFlux(VoidBearer& target) {
    if (getCurrentPalette() != ArtPalette::Reverbed) {
        std::cout << getName() << " must be in the Reverbed palette to use Chroma Flux!\n";
        return;
    }

    std::cout << "\n\"HAVE A CHANGE... OF COLOR\" - " << getName() << " casts **Chroma Flux**!\n";

    // 2 Hits Attack
    std::cout << "Hit 1:";
    int hitOne = attackPower / 2 + (rand() % 5);
    target.takeDamage(hitOne);

    std::cout << "Hit 2: ";
    int hitTwo = attackPower / 2 + (rand() % 5);
    target.takeDamage(hitTwo);

    std::cout << target.getName() << "'s colors shift\n";

}

void Crow::HueShift(VoidBearer& target) {
    if (getCurrentPalette() != ArtPalette::Reverbed) {
        std::cout << getName() << " must be in the Reverbed palette to use Hue Shift!\n";
        return;
    }

    std::cout << "\n\"LETS MAKE THE WORLD BRIGHTER\" - " << getName() << " triggers **Hue Shift**!\n";

    // Deals light damage and lowers target's defense
    int damage = attackPower / 3;
    target.takeDamage(damage);

    std::cout << target.getName() << "'s colors distort, reducing their defense capability! \n";
}