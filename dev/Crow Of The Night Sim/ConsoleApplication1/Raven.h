#pragma once
#include "VoidBearer.h"
/*ToDo for Raven:
add her four arts:
* Stabilzed arts:
  Doppleganger- adds an additional attack instance, goes away after an attack/art or when switching art palettes
  Dialogue line: "seeing double?"
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
private:
    bool hasDoppleganger; // Tracks the extra attack instance state
public:
    // Constructor
    Raven();
    Raven(std::string name, int hp, int atk, int def);

    void switchPalette(ArtPalette newPalette);
    // --- STABILIZED ART PALETTE (2 Skills) ---
    void Doppleganger(VoidBearer& target);
    void ShadowStrike(VoidBearer& target);

    // --- REVERBED ART PALETTE (2 Skills) ---
    void ExistenceErasure(VoidBearer& target);
    void NullAndVoid(VoidBearer& target);
};