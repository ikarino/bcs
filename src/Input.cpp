#include "Input.hpp"
#include "status.hpp"
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
    int summon_pos[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    std::vector<int> bloodhand_pos;
    bool flags[] = {false, false, false, false, false,
                    false, false, false, false, false, false};
    for (int i = 0; i < _mapstring.length(); i++) {
        if (i%20 == 0 || i%20 == 19 || i/20 == 0 || i/20 == 19) {
            if (_mapstring[i] != '+') {
                printf("Map string error !\n");
                printf("All the edges must be wall\n");
                exit(1);
            }
        }
        switch(_mapstring[i]) {
        case '+':
        case '-':
            break;
        case '*':
            flags[10] = true;
            bloodhand_pos.push_back(i);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            if (flags[_mapstring[i]-48]) {
                printf("Same numbers are in map input.\n");
                exit(1);
            }
            flags[_mapstring[i]-48] = true;
            summon_pos[_mapstring[i]-48] = i;
            break;
        default:
            printf("Invalid character : %s\n", &_mapstring[i]);
            exit(1);
        }
    }
    for (int i = 0; i < 11; i++) {
        if (!flags[i]) {
            printf("Something wrong with MAP input !\n");
            exit(1);
        }
    }
    // Monster Data
    std::vector<int> decoys;
    std::vector<int> invisibles;
    for (int index = 0; index < 10; index++) {
        int id = _monster_data[index*8+0];
        int lv = _monster_data[index*8+1];
        int dope = _monster_data[index*8+2];
        int speed = _monster_data[index*8+3];
        int mizu = _monster_data[index*8+4];
        int rukani = _monster_data[index*8+5];
        int seal = _monster_data[index*8+6];
        int invisible = _monster_data[index*8+7];
        try {
            GetName(id);
        } catch(...) {
            printf("Monster ID error !\n ID: %d\n", id);
            exit(1);
        }
        if (lv < 1 || lv > 99) {
            printf("Lv input error !\nLV: %d\n", lv);
            exit(1);
        }
        if (dope < 0) {
            printf("Dope input error !\ndope: %d\n", dope);
            exit(1);
        }
        if (speed != 2 && speed != 1) {
            printf("Speed input error !\nvalue : %d\n", speed);
            exit(1);
        }
        if (mizu < 0 || mizu > 9) {
            printf("Mizu input error !\nMIZU: %d\n", mizu);
            exit(1);
        }
        if (mizu == 9) {
            decoys.push_back(index);
        }
        if (rukani < 0 || rukani > 9) {
            printf("Rukani input error !\nRUKANI: %d\n", rukani);
            exit(1);
        }
        if (seal != 0 && seal != 1) {
            printf("Seal input error !\nvalue : %d\n", seal);
            exit(1);
        }
        if (invisible != 0 && invisible != 1) {
            printf("Invisible input error !\nvalue : %d\n", invisible);
            exit(1);
        }
        if (invisible == 1) {
            invisibles.push_back(index);
        }
    }
    // Blood hand check
    // ----- 隣接してる仲間が攻撃力０かチェック
    std::vector<bool> grab_not_straight;
    for (int i = 0; i < bloodhand_pos.size(); i++) {
        int neighbor[] = {-20, -1, +1, +20, -21, -19, +19, +21};
        for (int j = 0; j < 8; j++) {
            neighbor[j] += bloodhand_pos[i];
            for (int k = 0; k < 10; k++) {
                if (summon_pos[k] == neighbor[j]) {
                    bool flag = true;
                    for (int l = 0; l < decoys.size(); l++) {
                        if (decoys[l] == k) {
                            flag = false;
                            // printf("id: %d\n", decoys[l]);
                            // printf("ps: %d\n", summon_pos[k]);
                        }
                    }
                    if (flag) {
                        printf("Decoy must be 9 times weakened.\n");
                        exit(1);
                    }
                    // printf("%d\n", neighbor[j]);
                    grab_not_straight.push_back(j>3);
                }
            }
        }
    }
    // 一応
    if (bloodhand_pos.size() != grab_not_straight.size()) {
        printf("Programming error !\n");
        exit(1);
    }
    // ----- 斜めに掴んでいる場合、縦横２マスにレムオルでない仲間がいないかチェック
    for (int i = 0; i < bloodhand_pos.size(); i++) {
        if (grab_not_straight[i]) {
            int danger[] = {-40, -2, +2, +40};
            for (int j = 0; j < 4; j++) {
                danger[j] += bloodhand_pos[i];
                for (int k = 0; k < 10; k++) {
                    if (summon_pos[k] == danger[j]) {
                        bool flag = true;
                        for (int l = 0; l < invisibles.size(); l++) {
                            if (invisibles[l] == k) {
                                flag = false;
                            }
                        }
                        if (flag) {
                            printf("The position is not good.\nBloodhand may grab your summon of index %d at %d\n", k, summon_pos[k]);
                            exit(1);
                        }
                    }
                }
            }
        }
    }
    printf("Input reading finished.\n");
}
