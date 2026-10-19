#pragma once
#include "VoidBearer.h"
/*ToDo for Eagle:
add her four arts:
* Stabilzed arts:
  Windswept- One hit
  Dialogue line: "Sorry did i trip you"
  Calming Wind- Heal 5hp
  Dialouge line- "You aint killin me just yet"

  Reverbed Arts:
  Radiance Blaze - 4 hits 5% chance of damage of time
  Dialogue Line: "AAAAND BURN"
  Wildfire- 1 hit + attack down
  Dialogue line: "Feelin Hot yet?"

  Stats:
   Character player("Eagle", 125, 15, 10);
*/

class Eagle : public VoidBearer {
public:
    // Constructor
    
    Eagle(std::string name, int hp, int atk, int def);


    void executeSkillOne(VoidBearer& target) override;
    void executeSkillTwo(VoidBearer& target) override;

    // --- STABILIZED ART PALETTE (2 Skills) ---
    void Windswept(VoidBearer& target);
    void CalmingWind(VoidBearer& target);

    // --- REVERBED ART PALETTE (2 Skills) ---
    void RadianceBlaze(VoidBearer& target);
    void Wildfire(VoidBearer& target);
};