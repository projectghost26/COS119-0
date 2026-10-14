#pragma once
#include "VoidBearer.h"
/*ToDo for Crow: 
add her four arts:
* Stabilzed arts:
  Breakthrough Edge- One hit 
  Dialogue line: "BREAK... TRHOUGH"
  Storm Flare- Damage overtime
  Dialouge line- "Tosing Flare"
  
  Reverbed Arts:
  Chroma Flux- two hits
  Dialogue Line: "HAVE A CHANGE... OF COLOR" 
  Hue Shift- defense down
  Dialogue line: "LETS MAKE THE WORLD BRIGHTER"

  Stats:
   Character player("Crow", 150, 30, 15);
*/

class Crow : public VoidBearer {
public:
    // Constructor
    Crow(std::string name, int hp, int atk, int def);

    // --- STABILIZED ART PALETTE (2 Skills) ---
    void stabilizedSkillOne(VoidBearer& target);
    void stabilizedSkillTwo(VoidBearer& target);

    // --- REVERBED ART PALETTE (2 Skills) ---
    void reverbedSkillOne(VoidBearer& target);
    void reverbedSkillTwo(VoidBearer& target);
};