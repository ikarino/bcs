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
    for (int i = 0; i < 1500; i++) {
        map->Run();
    }
    map->ShowFinishStatus();
    // gui->random();
#ifdef GUI
    return Fl::run();
#else
    return 0;
#endif
}
