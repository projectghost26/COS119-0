#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Raven.h"
#include "Eagle.h"
#include "Squall.h"
#include "Crow.h"

VoidBearer* createRandomCharacterEnemy() {
    int enemyChoice = std::rand() % 4;

    switch (enemyChoice) {
    case 0:
        return new Crow("Crow projection", 150, 35, 15);
    case 1:
        return new Raven("Raven projection", 75, 45, 5);
    case 2:
        return new Squall("Squall projection", 150, 20, 20);
    default:
        return new Eagle("Eagle projection", 125, 15, 10);
    }
}

// Builds a fresh player so every round starts at full health
VoidBearer* createPlayer(int choice) {
    switch (choice) {
    case 1:
        std::cout << "\n[Eagle Eye]: Operative Crow deployed.\n [Crow]: Hey Im Crow, I hope i dont disapoint\n";
        return new Crow("Crow", 150, 35, 15);
    case 2:
        std::cout << "\n[Eagle Eye]: Operative Raven deployed.\n [Raven}: Agent Raven deployed, dont get in my way\n";
        return new Raven("Raven", 75, 45, 5);
    case 3:
        std::cout << "\n[Eagle Eye]: Operative Squall deployed.\n [Squall]: Ill keep on hittin em till they stay down\n";
        return new Squall("Squall", 150, 20, 20);
    case 4:
        std::cout << "\n[Eagle Eye]: Operative Eagle deployed.\n [Eagle}: heh of course you'd choose me ill keep you safe\n";
        return new Eagle("Eagle", 125, 15, 10);
    }
    return nullptr;
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string userName;

    std::cout << "Hello Early Bird, I am yours truely Eagle and before you ask Yes i made the eagle eye you are using right now.\n";
    std::cout << "Welcome to Nighthawk where we erase our pasts to protect the future blah blah blah you are here to fight. So thats Why i setup this little simulation.\n";
    std::cout << "To train the early birds without them... yknow actually dying. So lets go over how this will work you will pick one of 4 operative Avatars from team Shadowfeather(trademark pending) to pick between.\n";
    std::cout << "Crow, Raven, Squall, annnnd Me :)\n";
    std::cout << "Crow is an allrounder can take hits and hit back her voidpowers are Lightning and.. conjuring shit through stars with a cat made out of said stars. Dont ask me how that functions i still got no clue just be nice to Tali. \n";
    std::cout << "Raven is little miss gloomy, murder death kill you get the vibe. Powers are shadows allowing you to make another you and Antimatter allowing you to erase anyone you dont like. \n";
    std::cout << "then theres... ugh Squall uhhhh left right good night is his specialty just... punch shit.. what you wanna know his powers? Fine Ice and Metal he does nothing special about it he too old to understand the elegance of our powers \n";
    std::cout << "Saving the best for last theres Moi, My powers are Wind and Fire, i can heall i can damage i can debuff. I can already tell what you are thinking Eagle seems to be the best choice and.. You'd be right i am the best one here... maybe besides Crow \n";
    std::cout << "alright now that you know your choices imma need your name so i can save it to the Eagle Eye\n";
    std::cout << "Name: ";
    std::cin >> userName;
    if (userName == "Cyrin") {
        std::cout << "oh ehe thats a uhhhh nice name..... anyway \n";
    }
    else if (userName == "Natasha") {
        std::cout << "oh neat i had an old friend with the same name, Anyway\n";
    }
    std::cout << "Welcome " << userName << " to Nighthawk. Dont worry Your name wont be saved to everyone's Eagle Eye just your own\n";
    std::cout << "Now its time to make your choice, which operative template do you choose? \n";
    std::cout << "========================================\n";
    std::cout << "       SELECT YOUR OPERATIVE AVATAR     \n";
    std::cout << "========================================\n";
    std::cout << "1. Crow (Art Student Void Powers: Lightning & Constellations)\n";
    std::cout << "2. Raven (Reformed assassin Void Powers: Shadow & Antimatter)\n";
    std::cout << "3. Squall (Retired Boxer Void Powers: Ice & Metal)\n";
    std::cout << "4. Eagle (Former CIA counterintel Void Powers: Wind & Fire)\n";

    int choice = 0;
    while (choice < 1 || choice > 4) {
        std::cout << "Enter your choice (1-4): ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            choice = 0;
        }
    }

    bool running = true;
    int enemyCountMode = 1; // 1 = Standard 1v1, 2 = Additional enemy (1v2)

    // Outer loop: one iteration per simulation round
    while (running) {
        VoidBearer* player = createPlayer(choice);

        std::cout << "\n========================================\n";
        std::cout << "       SIMULATION COMBAT INITIATED      \n";
        std::cout << "========================================\n";
        std::cout << "[Eagle Eye]: Spawning combat training hologram...\n\n";

        std::vector<VoidBearer*> enemies;
        for (int i = 0; i < enemyCountMode; ++i) {
            enemies.push_back(createRandomCharacterEnemy());
        }
        for (size_t i = 0; i < enemies.size(); ++i) {
            std::cout << "[Eagle Eye]: Target " << (i + 1) << " acquired -> " << enemies[i]->getName() << " (HP: " << enemies[i]->getHealth() << ")\n";
        }

        bool battleActive = true;

        // combat
        while (battleActive) {
            std::cout << "\n----------------------------------------\n";
            std::cout << "YOUR TURN (HP: " << player->getHealth() << "):\n";
            std::cout << "1. Execute Skill One\n";
            std::cout << "2. Execute Skill Two\n";
            std::cout << "3. Switch Art Palette (Stabilized <-> Reverbed)\n";
            std::cout << "Enter action (1-3): ";

            int action;
            std::cin >> action;

            if (action == 1 || action == 2) {
                if (enemies.empty()) {
                    battleActive = false;
                    break;
                }
                VoidBearer* target = nullptr;
                if (enemies.size() == 1) {
                    target = enemies[0];
                }
                else {
                    std::cout << "\nSelect Target:\n";
                    for (size_t i = 0; i < enemies.size(); ++i) {
                        std::cout << (i + 1) << ". " << enemies[i]->getName() << " (HP: " << enemies[i]->getHealth() << ")\n";
                    }
                    int targetChoice;
                    std::cout << "Enter target number (1-" << enemies.size() << "): ";
                    std::cin >> targetChoice;

                    if (targetChoice >= 1 && targetChoice <= static_cast<int>(enemies.size())) {
                        target = enemies[targetChoice - 1];
                    }
                    else {
                        target = enemies[0];
                        std::cout << "Invalid choice. Defaulting to target 1.\n";
                    }
                }

                if (action == 1) {
                    player->executeSkillOne(*target);
                }
                else {
                    player->executeSkillTwo(*target);
                }

                // Remove defeated enemies
                for (auto it = enemies.begin(); it != enemies.end(); ) {
                    if ((*it)->getHealth() <= 0) {
                        std::cout << "\n[Eagle Eye]: " << (*it)->getName() << " has been neutralized!\n";
                        delete* it;
                        it = enemies.erase(it);
                    }
                    else {
                        ++it;
                    }
                }
            }
            else if (action == 3) {
                if (player->getCurrentPalette() == ArtPalette::Stabilized) {
                    player->switchPalette(ArtPalette::Reverbed);
                    std::cout << player->getName() << " shifted palette to **Reverbed**!\n";
                }
                else {
                    player->switchPalette(ArtPalette::Stabilized);
                    std::cout << player->getName() << " shifted palette to **Stabilized**!\n";
                }
                continue;
            }
            else {
                std::cout << "Invalid action. Turn skipped!\n";
                continue;
            }

            // Victory check
            if (enemies.empty()) {
                std::cout << "\n========================================\n";
                std::cout << "       SIMULATION CLEARED: VICTORY!     \n";
                std::cout << "========================================\n";
                std::cout << "[Eagle Eye]: Training hologram neutralized! Outstanding performance, " << userName << ".\n";
                battleActive = false;
                break;
            }

            std::cout << "\n[Eagle Eye]: Hologram status stable. Counter-attacking...\n";

            // Every surviving enemy retaliates
            for (auto* foe : enemies) {
                int enemyMove = std::rand() % 100;
                if (enemyMove < 25) { // 25% chance to toggle palette
                    if (foe->getCurrentPalette() == ArtPalette::Stabilized) {
                        foe->switchPalette(ArtPalette::Reverbed);
                        std::cout << foe->getName() << " shifts their Art Palette to Reverbed!\n";
                    }
                    else {
                        foe->switchPalette(ArtPalette::Stabilized);
                        std::cout << foe->getName() << " shifts their Art Palette to Stabilized!\n";
                    }
                }
                else {
                    int skillChoice = (std::rand() % 2) + 1;
                    if (skillChoice == 1) {
                        foe->executeSkillOne(*player);
                    }
                    else {
                        foe->executeSkillTwo(*player);
                    }
                }

                if (player->getHealth() <= 0) break;
            }

            if (player->getHealth() <= 0) {
                std::cout << "\n========================================\n";
                std::cout << "          SIMULATION FAILED             \n";
                std::cout << "========================================\n";
                std::cout << "[Eagle Eye]: Vital signs flatlining... Better luck Next Time little " << userName << ".\n";
                battleActive = false;
            }
        }

        // Clean up this round's memory (once, after the battle)
        for (auto* e : enemies) {
            delete e;
        }
        enemies.clear();
        delete player;
        player = nullptr;

        // Post-battle menu
        int postChoice = 0;
        std::cout << "\n========================================\n";
        std::cout << "         SIMULATION CONCLUDED           \n";
        std::cout << "========================================\n";
        std::cout << "1. Rematch\n";
        std::cout << "2. Increase Challenge\n";
        std::cout << "3. End simulation\n";
        std::cout << "Enter your choice (1-3): ";
        if (!(std::cin >> postChoice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            postChoice = 3;
        }

        if (postChoice == 1) {
            enemyCountMode = 1;
            std::cout << "\n[Eagle Eye]: Rebooting standard simulation...\n";
        }
        else if (postChoice == 2) {
            enemyCountMode = 2;
            std::cout << "\n[Eagle Eye]: Challenge increase additional enemy deployed...\n";
        }
        else {
            running = false;
            std::cout << "\n[Eagle Eye]: Shutting down Nighthawk simulation. Farewell, " << userName << ".\n";
        }
    }

    return 0;
}