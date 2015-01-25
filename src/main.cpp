// main.cpp

#include "status.hpp"
#include "Summon.hpp"
#include "Bloodhand.hpp"
#include "Daimajin.hpp"
#include "Map.hpp"

#include <ctime>



int main() {
    srand((unsigned)time(NULL));
    Map *map = new Map();
    map->SetGUI();
    for (int i = 0; i < 30; i++) {
        map->Run();
    }
    // gui->random();
    return Fl::run();
}
