// main.cpp

#include "status.hpp"
#include "Summon.hpp"
#include "Bloodhand.hpp"
#include "Daimajin.hpp"
#include "Map.hpp"
#include "Input.hpp"

#include <ctime>

int main(int argc, char** argv) {
    // std::string filename = "input.bcs";
    std::string filename(argv[1]);
    srand((unsigned)time(NULL));
    Map *map = new Map(filename);
    map->Run();
    // gui->random();
#ifdef GUI
    return Fl::run();
#else
    return 0;
#endif
}
