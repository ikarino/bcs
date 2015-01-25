#include "Bloodhand.hpp"
#include "Daimajin.hpp"
#include "Summon.hpp"
#include <cstdlib>

unsigned long Bloodhand::__upper_limit  = 0;

Bloodhand::Bloodhand(int place, bool double_speed) {
    _place = place;
    _hp = 26;
    _realATK = 17 * 1.3;
    _realDEF = 21;
    _double_speed = double_speed;
    _seal = false;
    _vain_count = 0;
}


void Bloodhand::Action(int &info,
                       std::vector<Summon> *sm,
                       std::vector<Daimajin> *dm) {
    printf("##########\n");
    if (rand()%4 == 0) {
        // だいまじん召喚
        printf("Arragin !\n");
        if (dm->size() == Bloodhand::__upper_limit) {
            printf("Reached upper limit of daimajins\n");
            _vain_count++;
            return;
        }
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
        int list[] = {-21, -20, -19, -1, 1, 19, 20, 21};
        std::vector<int> targets;
        for (int i = 0; i < 8; ++i) {
            if ((&info)[_place + list[i]] == 4) {
                targets.push_back(_place+list[i]);
            }
        }

        // 囮が隣接していない場合return
        // 実際には囮がいないことはありえない。
        if (targets.size() == 0) {
            printf("No Decoy found.\n");
            printf("Is this Debug mode ?");
            return;
        }

        // 攻撃対象の囮を決定
        int target_place = targets[rand() % targets.size()];
        printf("Going to Attack Decoy at %d\n", target_place);

        for (auto it = sm->begin(); it != sm->end(); ++it) {
            if (it->GetPlace() == target_place) {
                printf("Decoy was Attacked!\n");
                it->GetDamage(_realATK);
                if (it->GetIncidentHP() <= 0) {
                    printf("Simulation Failed\n");
                    exit(0);
                }
            }
            break;
        }
    }
}
