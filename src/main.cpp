// main.cpp

#include "status.hpp"
#include "Summon.hpp"
#include "Bloodhand.hpp"
#include "Daimajin.hpp"
#include "Map.hpp"
#include "Input.hpp"

#include <ctime>

int main() {
    // std::string filename = "input.bcs";
    // Input inp(filename);
    srand((unsigned)time(NULL));
    Map *map = new Map();
    map->Run();
    // gui->random();
#ifdef GUI
    return Fl::run();
#else
    return 0;
#endif
}
