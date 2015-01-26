#include "Input.hpp"
#include <string>
#include <fstream>


Input::Input(std::string filename) {
    std::ifstream ifs(filename);
    std::string str;
    if (ifs.fail()) {
        printf("File open error");
        exit(1);
    }
    int line_number = 1;
    while (getline(ifs, str)) {
        if (str[0] == '#' || str[0] == '\n') {
            continue;
        }
        switch(line_number) {
        case 1:
            try {
                _T = stoi(str);
                if (_T <= 0 || _T > 1800) {
                    printf("Turn input Error !\n");
                    printf("Turn Number must be between 1 and 1800");
                    exit(1);
                }
            } catch (...) {
                printf("Turn input Error !\n");
                printf("Couldn't convert string to int.\n");
                exit(1);
            }
            break;
        case 2:
            try {
                _N = stoi(str);
                if (_N <= 0) {
                    printf("Trial input Error !\n");
                    printf("Trial Number is negative");
                    exit(1);
                }
            } catch (...) {
                printf("Trial input Error !\n");
                printf("Couldn't convert string to int.\n");
                exit(1);
            }
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            if (str.length() != 20) {
                printf("Map input error !\n");
                printf("The line must be 20 characters.\n");
                exit(1);
            }
            _mapstring += str;
            break;
        case 23:
            if (str[0] == '1') {
                _bh2 = false;
            } else if (str[0] == '2') {
                _bh2 = true;
            } else {
                printf("Blood Hand speed setting error !\n");
                printf("This input must be 1 or 2");
                printf("Reading line is below:\n%s", str.c_str());
                exit(1);
            }
            break;
        case 24:
            try {
                _upper_limit = stoi(str);
                if (_upper_limit <= 0 || _upper_limit > 28) {
                    printf("Daimajin upper limit input error !\n");
                    printf("Upper limit must be between 0 and 28\n");
                    exit(1);
                }
            } catch (...) {
                printf("Daimajin upper limit input error !\n");
                exit(1);
            }
            break;
        default:
            if (line_number < 105) {
                try {
                    int data = stoi(str);
                    _monster_data.push_back(data);
                } catch (...) {
                    printf("Monster data input error !\n");
                    printf("Couldn't convert string to int.\n");
                    exit(1);
                }
            }
            break;
        }
        line_number += 1;
    } // switch

    // ここからインプットファイルのエラー処理
    // MapとMonster Data
    // Mapについては、
    // - 使用されている文字が適切であること
    // - 0-9の数値文字列が含まれていること
    // - ブラハンが1匹以上含まれていること
    // - 周囲が壁で構成されていること
    //
    // Monster Dataについては、
    // - それぞれのパラメータが適切な範囲内であること
    //
    // あとまわしにすることは、
    // - ブラハンが仲間を引き寄せる配置でないこと
    // - ブラハンに隣接している仲間が完全に弱化されていること
}
