// main.cpp

#include "status.hpp"
#include "Summon.hpp"
#include "Bloodhand.hpp"
#include "Daimajin.hpp"
#include "Map.hpp"
#include "Input.hpp"

#include <ctime>
#include <fstream>

void ProduceSampleInput();

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("No input file.\n");
        std::ifstream ifs("input.bcs");
        if (ifs.fail()) {
            ProduceSampleInput();
        }
        ifs.close();
        printf("Usage:\n./bcs input.bcs\n");
        exit(1);
    }
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


void ProduceSampleInput() {
    printf("Generating sample input.\n");
    std::ofstream ofs("input.bcs");
    ofs << ""
        "# comment\n"
        "# basic info\n"
        "1500\n"
        "100\n"
        "# MAP\n"
        "++++++++++++++++++++\n"
        "+------------------+\n"
        "+------------------+\n"
        "+------------------+\n"
        "+------------------+\n"
        "+------------------+\n"
        "+------60----------+\n"
        "+------------------+\n"
        "+---2-***-8--------+\n"
        "+---3-*9*----------+\n"
        "+---4-***-5--------+\n"
        "+------------------+\n"
        "+------71----------+\n"
        "+------------------+\n"
        "+------------------+\n"
        "+------------------+\n"
        "+------------------+\n"
        "+------------------+\n"
        "+------------------+\n"
        "++++++++++++++++++++\n"
        "# BLOOD DOUBLE\n"
        "2\n"
        "# Daimajin upper limit\n"
        "20\n"
        "# MONSTER\n"
        "# id, lv, dope, speed, mizu, rukani, seal, invisible\n"
        "# 0th\n"
        "613\n"
        "60\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "0\n"
        "1\n"
        "# 1st\n"
        "613\n"
        "60\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "0\n"
        "1\n"
        "# 2nd\n"
        "613\n"
        "60\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "0\n"
        "1\n"
        "# 3rd\n"
        "613\n"
        "60\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "0\n"
        "1\n"
        "# 4th\n"
        "613\n"
        "60\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "0\n"
        "1\n"
        "# 5th\n"
        "613\n"
        "99\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "0\n"
        "1\n"
        "# 6th\n"
        "206\n"
        "50\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "0\n"
        "1\n"
        "# 7th\n"
        "120\n"
        "60\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "1\n"
        "1\n"
        "# 8th\n"
        "120\n"
        "60\n"
        "0\n"
        "2\n"
        "0\n"
        "0\n"
        "1\n"
        "1\n"
        "# 9th\n"
        "606\n"
        "99\n"
        "10000\n"
        "2\n"
        "9\n"
        "0\n"
        "0\n"
        "0\n";
    ofs.close();
}
