#pragma once
#include "VoidBearer.h"
/*ToDo for Squall:
add his four arts:
* Stabilzed arts:
  Glacial Defence- Defense up
  Dialogue line: "Land a hit I wont feel a thing"
  Arctic Hook- 1 Hit
  Dialouge line- "Need an Ice Pack Mate?"

  Reverbed Arts:
  Metal Ring - 1 hit 25% chance to deal 2x damage, take no damage on text turn after cast
  Dialogue Line: "HEAR THE BELL RINGIN?... KNOCKOUT"
  Headshaker- 1 hit 2% chance for the enemy to not act in their next turm
  Dialogue line: "Oooo feelin Dizzy there Bud?"

  Stats:
   Character player("Squall", 175, 30, 30);
*/

class Squall : public VoidBearer {
private:
    bool invulnerableNextTurn;
public:
    // Constructor
    Squall();
    Squall(std::string name, int hp, int atk, int def);

    // Override takeDamage to intercept attacks when invulnerable
    void takeDamage(int damage) override;

    // --- STABILIZED ART PALETTE (2 Skills) ---
    void GlacialDefence(VoidBearer& target);
    void ArcticHook(VoidBearer& target);

    // --- REVERBED ART PALETTE (2 Skills) ---
    void MetalRing(VoidBearer& target);
    void Headshaker(VoidBearer& target);
};