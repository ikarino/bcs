#include "Input.hpp"
#include <string>
#include <fstream>
#include <iostream>


Input::Input(std::string filename) {
    std::ifstream ifs(filename);
    std::string str;
    if (ifs.fail()) {
        printf("File open error");
        exit(1);
    }

    while (getline(ifs, str)) {
        std::cout << str << std::endl;
    }
}
