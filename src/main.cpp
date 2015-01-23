// main.cpp

#include "status.hpp"
#include "Summon.hpp"
#include "Bloodhand.hpp"
#include "Daimajin.hpp"
#include "Map.hpp"

#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include <vector>


int main() {
    srand((unsigned)time(NULL));
    Map *map = new Map();
    map->SetGUI();
    for (int i = 0; i < 30; i++) {
        usleep(50000);
        map->Run();
    }
    // gui->random();
    return Fl::run();
}
