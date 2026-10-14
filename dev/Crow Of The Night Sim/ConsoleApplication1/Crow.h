#pragma once
#include "VoidBearer.h"


class Crow : public VoidBearer {
public:
    // Constructor
    Crow();
    Crow(std::string name, int hp, int atk, int def);

    // --- STABILIZED ART PALETTE (2 Skills) ---
    void BreakthroughEdge(VoidBearer& target);
    void StormFlare(VoidBearer& target);

    // --- REVERBED ART PALETTE (2 Skills) ---
    void ChromaFlux(VoidBearer& target);
    void HueShift(VoidBearer& target);
};