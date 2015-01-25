#include "Bloodhand.hpp"
#include "Daimajin.hpp"
#include <cstdlib>

Bloodhand::Bloodhand(int place, bool double_speed) {
    _place = place;
    _hp = 26;
    _realATK = 17 * 1.3;
    _realDEF = 21;
    _double_speed = double_speed;
    _seal = false;
}


void Bloodhand::Action(int &info, std::vector<Summon> *sm, std::vector<Daimajin> *dm) {
    printf("----------\n");
    // int dx = GetPlace()/20;  // ブラッドハンドのx座標
    // int dy = GetPlace()%20;  // ブラッドハンドのy座標

    if (rand()%4 == 0) {
        // だいまじん召喚
        printf("Arragin !\n");
        int list[] = {-21, -20, -19, -1, 1, 19, 20, 21};
        std::vector<int> blank_positions;
        for (int i = 0; i < 8; i++) {
            if ((&info)[GetPlace()+list[i]] == 0) {
                blank_positions.push_back(GetPlace()+list[i]);
            }
        }
        int daimajin_pos = blank_positions[rand()%blank_positions.size()];
        Daimajin d(daimajin_pos);
        dm->push_back(d);
        (&info)[daimajin_pos] = 2;
    } else {
        // 攻撃
    }
}
