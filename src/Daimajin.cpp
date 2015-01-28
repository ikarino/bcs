#include "Daimajin.hpp"
#include "Summon.hpp"
#include "status.hpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>

// #define DEBUG

Daimajin::Daimajin(int place) {
    // daimajin 105 34 30
    // LV.6      30 10 21
    _place = place;
    _hp = 135;
    _realATK = 44 * 1.3;
    _realDEF = 51;
    _double_speed = false;
    _seal = false;
}


Daimajin::Daimajin(int x, int y) {
    _place = x*20+y;
    _hp = 135;
    _realATK = 44 * 1.3;
    _realDEF = 51;
    _double_speed = false;
    _seal = false;
}


void Daimajin::Get25() {
    _hp += 25;
    if (_hp > 135) {
        _hp = 135;
    }
}


void Daimajin::Action(int &info, std::vector<Summon> *sm) {
#ifdef DEBUG
    printf("----------\n");
#endif
    int dx = GetPlace()/20;  // 大魔神のx座標
    int dy = GetPlace()%20;  // 大魔神のy座標
    int minimum_distance = 400;  // 大魔神と最も近いSummonとの距離
    std::vector<int> target_x;  // 最も近いSummonのx座標
    std::vector<int> target_y;  // 最も近いSummonのy座標
    std::vector<int> target_pos; // 攻撃対象vector。攻撃する前提で準備しておく。

    for(int x = 0; x < 20; x++) {
        for(int y = 0; y < 20; y++) {
            if ((&info)[x*20+y] != 4) { continue; };
            int len = calc_len(x, y, dx, dy);
            if (minimum_distance > len) {
                minimum_distance = len;
                target_x.clear();
                target_x.push_back(x);
                target_y.clear();
                target_y.push_back(y);
            } else if (minimum_distance == len) {
                target_x.push_back(x);
                target_y.push_back(y);
            }
            if (len == 1 || len == 2) {
                target_pos.push_back(x*20+y);
            }
        }
    }
    if (false) {
    } else if (minimum_distance == 400) {
        // Summon がいない。
        // シミュレーション上、起こっては困る。
#ifdef DEBUG
        printf("No Summon Found\n");
#endif
        return;
    } else if (minimum_distance == 1 || minimum_distance == 2) {
        // Summon に隣接している
#ifdef DEBUG
        printf("Next to Summon\n");
#endif
        int target = rand() % target_pos.size();
        int target_place = target_pos[target];
        int smindex = 0;
        for (auto it = sm->begin(); it != sm->end(); ++it) {
            if (it->GetPlace() == target_place) {
                // printf("Summon was Attacked !\n");
                it->GetDamage(_realATK);
                // printf("Now HP: %d\n", it->GetIncidentHP());
                if (it->GetIncidentHP() <= 0) {
                    printf("Simulation Failed\nMonster Below Died.\n");
                    printf("No. %d\n", smindex);
                    printf("MONSTER: %s\n", GetName(it->GetMonsterINDEX()).c_str());
                    printf("Place x: %d y: %d\n", it->GetPlace()/20, it->GetPlace()%20);
                    exit(0);
                }
                break;
            }
            smindex++;
        }
        // attack summon
        return;
    } else {
        // Summon が遠くにいる。
        int target = rand() % target_x.size();
#ifdef DEBUG
        printf("%ld Summons Found\n", target_x.size());
        printf("Moving toward the Summon at x = %d, y = %d\n", target_x[target], target_y[target]);
#endif
        (&info)[_place] = 0;
        // original
        _place += calc_minimum(dx, dy, target_x[target], target_y[target], info);
        // test 対象は同じで等距離の位置がある場合、ランダムで動く
        // _place = calc_minimum(_place, target_x[target]*20 + target_y[target], info);
        (&info)[_place] = 2;
        return;
    }
}


void Daimajin::Tukon(double at) {
    if (at == 0) {
#ifdef DEBUG
        printf("AT is 0. Just seeing how it goes.\n");
#endif
        return;
    }
    if (rand()%100 < 92) {
        int dm = static_cast<int>(floor(at*pow(0.97222222, _realDEF)
                                        *(112+rand()%32)/128 + 0.5));
        if (dm != 0) {
            _hp -= dm;
        } else {
            _hp -= 1;
        }
#ifdef DEBUG
        printf("Damage : %d\n", dm);
    } else {
        printf("Missed\n");
#endif
    }
}


int calc_len(int x, int y, int X, int Y) {
    return (x-X)*(x-X) + (y-Y)*(y-Y);
}


int calc_minimum(int x, int y, int X, int Y, int& info) {
    int ret = 0;
    int len = calc_len(x, y, X, Y);
    if (len > calc_len(x-1, y-1, X, Y) && (&info)[(x-1)*20 + (y-1)] == 0) {
        ret = -21;
        len = calc_len(x-1, y-1, X, Y);
    }
    if (len > calc_len(x-1, y, X, Y) && (&info)[(x-1)*20 + y] == 0) {
        ret = -20;
        len = calc_len(x-1, y, X, Y);
    }
    if (len > calc_len(x-1, y+1, X, Y) && (&info)[(x-1)*20 + (y+1)] == 0) {
        ret = -19;
        len = calc_len(x-1, y+1, X, Y);
    }
    if (len > calc_len(x, y-1, X, Y) && (&info)[x*20 + (y-1)] == 0) {
        ret = -1;
        len = calc_len(x, y-1, X, Y);
    }
    if (len > calc_len(x, y+1, X, Y) && (&info)[x*20 + (y+1)] == 0) {
        ret = +1;
        len = calc_len(x, y+1, X, Y);
    }
    if (len > calc_len(x+1, y-1, X, Y) && (&info)[(x+1)*20 + (y-1)] == 0) {
        ret = +19;
        len = calc_len(x+1, y-1, X, Y);
    }
    if (len > calc_len(x+1, y, X, Y) && (&info)[(x+1)*20 + y] == 0) {
        ret = 20;
        len = calc_len(x+1, y, X, Y);
    }
    if (len > calc_len(x+1, y+1, X, Y) && (&info)[(x+1)*20 + (y+1)] == 0) {
        ret = 21;
        len = calc_len(x+1, y+1, X, Y);
    }
    return ret;
}


int calc_len(int pos1, int pos2) {
    int x_1 = pos1/20;
    int y_1 = pos1%20;
    int x_2 = pos2/20;
    int y_2 = pos2%20;
    return (x_1-x_2)*(x_1-x_2) + (y_1-y_2)*(y_1-y_2);
}


int calc_minimum(int pos1, int pos2, int& info) {
    int neighbor[] = {-21, -20, -19, -1, 0, +1, +19, +20, +21};
    std::vector<int> min;
    int minimum = 10000000;
    for (int i = 0; i < 9; i++) {
        if (calc_len(pos1 + neighbor[i], pos2) < minimum
            && (&info)[pos1 + neighbor[i] == 0]) {
            min.clear();
            min.push_back(pos1*neighbor[i]);
        } else if (calc_len(pos1 + neighbor[i], pos2) == minimum
                   && (&info)[pos1 + neighbor[i] == 0]) {
            min.push_back(pos1*neighbor[i]);
        }
    }
    return min[rand()%min.size()];
}
