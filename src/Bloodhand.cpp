#include "Bloodhand.hpp"
#include "Daimajin.hpp"
#include "Summon.hpp"
#include "status.hpp"
#include <cstdlib>

// #define DEBUG
unsigned long Bloodhand::__upper_limit  = 0;

Bloodhand::Bloodhand(int place, bool double_speed) {
    _place = place;
    _hp = 26;
    _realATK = 17 * 1.3;
    _realDEF = 21;
    _double_speed = double_speed;
    _seal = false;

    _arragin_count = 0;
    _upper_limit_vain_count = 0;
    _no_place_vain_count = 0;
}


void Bloodhand::Action(int &info,
                       std::vector<Summon> *sm,
                       std::vector<Daimajin> *dm) {
#ifdef DEBUG
    printf("##########\n");
#endif
    if (rand()%4 == 0) {
        // だいまじん召喚
#ifdef DEBUG
        printf("Arragin !\n");
#endif
        _arragin_count++;
        if (dm->size() == Bloodhand::__upper_limit) {
#ifdef DEBUG
            printf("Reached upper limit of daimajins\n");
#endif
            _upper_limit_vain_count++;
            return;
        }
        int list[] = {-21, -20, -19, -1, 1, 19, 20, 21};
        std::vector<int> blank_positions;
        for (int i = 0; i < 8; i++) {
            if ((&info)[GetPlace()+list[i]] == 0) {
                blank_positions.push_back(GetPlace()+list[i]);
            }
        }
        // 召喚スペースが無い場合
        if (blank_positions.size() == 0) {
#ifdef DEBUG
            printf("No place to Arragin ! Shit !\n");
#endif
            _no_place_vain_count++;
            return;
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
#ifdef DEBUG
            printf("No Decoy found.\n");
            printf("Is this Debug mode ?");
#endif
            return;
        }

        // 攻撃対象の囮を決定
        int target_place = targets[rand() % targets.size()];
#ifdef DEBUG
        printf("Going to Attack Decoy at %d\n", target_place);
#endif
        int smindex = 0;
        for (itS it = sm->begin(); it != sm->end(); ++it) {
            if (it->GetPlace() == target_place) {
                // printf("Decoy was Attacked!\n");
                it->GetDamage(_realATK);
                if (it->GetIncidentHP() <= 0) {
                    printf("Simulation Failed\n");
                    printf("No. %d\n", smindex);
                    printf("MONSTER: %s\n", GetName(it->GetMonsterINDEX()).c_str());
                    printf("Place x: %d y: %d\n", it->GetPlace()/20, it->GetPlace()%20);
                    exit(0);
                }
                break;
            }
            smindex++;
        }
    }
}
