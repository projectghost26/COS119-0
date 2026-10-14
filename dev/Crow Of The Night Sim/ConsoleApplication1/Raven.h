#pragma once
#include "VoidBearer.h"
/*ToDo for Raven:
add her four arts:
* Stabilzed arts:
  Doppleganger- prevents one hit of damage
  Dialogue line: "Wrong one"
  ShadowStrike- 2 hits
  Dialouge line- "Strike from the shadows!"

  Reverbed Arts:
  Existence Erasure - 15% chance to Cap enemy max health by 10%
  Dialogue Line: "you are fading"
  Null and Void - 3 Hits 3% chance to cap enemy max health 5% per hit 
  Dialogue line: "Everything becomes forgetten sooner or later"

  Stats:
   Character player("Raven", 75, 45, 5);
*/

class Raven : public VoidBearer {
public:
    // Constructor
    Raven(std::string name, int hp, int atk, int def);

    // --- STABILIZED ART PALETTE (2 Skills) ---
    void stabilizedSkillOne(VoidBearer& target);
    void stabilizedSkillTwo(VoidBearer& target);

    // --- REVERBED ART PALETTE (2 Skills) ---
    void reverbedSkillOne(VoidBearer& target);
    void reverbedSkillTwo(VoidBearer& target);
};