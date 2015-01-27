#include "Summon.hpp"
#include "Daimajin.hpp"
#include "status.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>

// #define DEBUG

Summon::Summon(int place, int monsterINDEX, int lv, int dope, bool doublespeed,
               int wATK, int wDEF, bool seal, bool invisible) {
    _place = place;
    _monsterINDEX = monsterINDEX;
    _lv = lv;
    _dope = dope;
    _wATK = wATK;
    _wDEF = wDEF;
    _invisible = invisible;

    _double_speed = doublespeed;
    _seal = seal;
    _exp = GetEXP(monsterINDEX, lv);

    SetAbilityScore();
    _hp = _maximumHP;
    _rec = GetREC(_monsterINDEX);

    _kill_count = 0;
    _active_turn = 0;
}


Summon::~Summon() {}


void Summon::ShowStatus() {
    std::string name = GetName(_monsterINDEX);
    printf("---------------------\n");
    printf("Monster: %s\n", name.c_str());
    printf("hp now : %f\n", _hp);
    printf("X = %d, Y=%d\n", _place/20, _place%20);
    printf("---------------------\n");
}


void Summon::Action(int &info,
                    std::vector<Daimajin> *dm,
                    std::vector<Summon> *sm) {
#ifdef DEBUG
    printf("************\n");
    ShowStatus();
#endif
    // 自然回復
    _hp += (double)_maximumHP/_rec;
    if (_hp > _maximumHP) {
        _hp = _maximumHP;
    }

    //
    // ここに遠距離攻撃モンスター用の処理を加える必要がある。
    // 必要になったら実装する。
    // 70F時点で炎を吐けるモンスターは
    // ラブレスのみだから不要だと思う。
    //
    if (GetMonsterINDEX() == 120 && !isSealed()) {
        // printf("Hoimin works\n");
        Hoimin(info, dm, sm);
        return;
    }

    // 隣接しているすべての敵の場所を取得。
    int list[] = {-21, -20, -19, -1, 1, 19, 20, 21};
    std::vector<int> targets;
    for (int i = 0; i < 8; ++i) {
        if ((&info)[_place + list[i]] == 2 ||
            (&info)[_place + list[i]] == 3){
            targets.push_back(_place+list[i]);
        }
    }

    // 隣接していない場合return
    if (targets.size() == 0) {
#ifdef DEBUG
        printf("No Daimajin found.\n");
#endif
        return;
    }
    _active_turn++;

    // 攻撃対象を決定
    int target_place = targets[rand() % targets.size()];
#ifdef DEBUG
    printf("Going to Attack Daimajin at %d\n", target_place);
#endif

    if (isSealed()) {
        StandardAttack(target_place, info, dm);
    } else {
        //
        // ここにモンスター別のActionを追加していく。
        //
        switch(GetMonsterINDEX()) {
        case 613:
            KillerMachine(target_place, info, dm);
            break;
        default:
            StandardAttack(target_place, info, dm);
            break;
        }
    }
}


void Summon::StandardAttack(int target_place,
                            int &info,
                            std::vector<Daimajin> *dm) {
    for (auto it = dm->begin(); it != dm->end(); ++it) {
        if (it->GetPlace() == target_place) {
            // printf("Before attack HP was: %d\n", it->GetIncidentHP());
            // printf("Daimajin was Attacked!\n");
            if (_monsterINDEX == 201 || _monsterINDEX == 203) {
                if (rand()%5 < 2) {
                    it->Tukon(_realATK);
                } else {
                    it->GetDamage(_realATK);
                }
            } else {
                it->GetDamage(_realATK);
            }
            // printf("After attack HP was: %d\n", it->GetIncidentHP());
            if (it->GetIncidentHP() <= 0) {
                dm->erase(it);
                KilledSasaki();
                (&info)[target_place] = 0;
                _kill_count++;
            }
            break;
        }
    }
};


void Summon::KillerMachine(int target_place,
                           int &info,
                           std::vector<Daimajin> *dm) {
    for (auto it = dm->begin(); it != dm->end(); ++it) {
        if (it->GetPlace() == target_place) {
            // printf("Daimajin was Attacked!\n");
            for (int i = 0; i < 2; i++) {
                it->GetDamage(_realATK);
                if (it->GetIncidentHP() <= 0) {
                    dm->erase(it);
                    KilledSasaki();
                    (&info)[target_place] = 0;
                    _kill_count++;
                    break;
                }
            }
            break;
        }
    }
};


void Summon::Get25() {
    _hp += 25;
    if (_hp > _maximumHP) {
        _hp = _maximumHP;
    }
}


void Summon::Hoimin(int &info, std::vector<Daimajin> *dm, std::vector<Summon> *sm) {
    // 周囲の負傷状況を取得
    int list[] = {-21, -20, -19, -1, 1, 19, 20, 21};
    int pos = GetPlace();
    int damaged_neighbor = 0;
    std::vector<Daimajin*> damaged_d;
    std::vector<Summon*> damaged_s;
    for (auto it = dm->begin(); it != dm->end(); ++it) {
        if (it->GetIncidentHP() == 135) {
            continue;
        }
        int d_pos = it->GetPlace();
        for (int i = 0; i < 8; i++) {
            if (d_pos == pos + list[i]) {
                damaged_neighbor++;
                damaged_d.push_back(&(*it));
            }
        }
    }
    for (auto it = sm->begin(); it != sm->end(); ++it) {
        if (it->GetIncidentHP() == it->GetMHP()) {
            continue;
        }
        int s_pos = it->GetPlace();
        for (int i = 0; i < 8; i++) {
            if (s_pos == pos + list[i]) {
                damaged_neighbor++;
                damaged_s.push_back(&(*it));
            }
        }
    }

    // ホイミするかどうか判定
    bool dohoimi = false;
    for (int i = 0; i < damaged_neighbor; i++) {
        if (rand()%4 == 0) {
            dohoimi = true;
            break;
        }
    }

    // Action
    if (dohoimi) {
        // ホイミする場合
#ifdef DEBUG
        printf("Hoimi !!!!!!!!!\n");
#endif
        _active_turn++;
        for (auto it = damaged_d.begin(); it != damaged_d.end(); it++) {
            (*it)->Get25();
        }
        for (auto it = damaged_s.begin(); it != damaged_s.end(); it++) {
            (*it)->Get25();
#ifdef DEBUG
            printf("pos x: %d y: %d\n", (*it)->GetPlace()/20, (*it)->GetPlace()%20);
#endif
        }
    } else {
        // 通常攻撃する場合
#ifdef DEBUG
        printf("Attack ?\n");
#endif
        _active_turn++;
        // ふらふら攻撃確率 30% TODO
        if (rand()%10 < 7) {
            return;
        }

        // 隣接しているすべての敵の場所を取得。
        int list[] = {-21, -20, -19, -1, 1, 19, 20, 21};
        std::vector<int> targets;
        for (int i = 0; i < 8; ++i) {
            if ((&info)[_place + list[i]] == 2 ||
                (&info)[_place + list[i]] == 3) {
                targets.push_back(_place+list[i]);
            }
        }

        // 隣接していない場合return
        if (targets.size() == 0) {
#ifdef DEBUG
            printf("No Daimajin found.\n");
#endif
            return;
        }

#ifdef DEBUG
        printf("Attack !!!!!!!!!!\n");
#endif

        // 攻撃対象を決定
        int target_place = targets[rand() % targets.size()];
#ifdef DEBUG
        printf("Going to Attack Daimajin at %d\n", target_place);
#endif
        // 通常攻撃
        StandardAttack(target_place, info, dm);
    }

}

void Summon::KilledSasaki() {
#ifdef DEBUG
    printf("Yeah ! I killed Sasaki !\n");
#endif
    if ( _lv == 99) { return; }

    _exp += 560;
    if (_exp > GetEXP(_monsterINDEX, _lv+1)) {
#ifdef DEBUG
        printf("LEVEL UP !!\n");
#endif
        _lv += 1;
        SetAbilityScore();
    }
    // printf("Finished KillSasaki()\n");
}

void Summon::SetAbilityScore() {
    _maximumHP = GetHP(_monsterINDEX, _lv) + _dope;
    _originalATK = GetAT(_monsterINDEX, _lv);
    _originalDEF = GetDF(_monsterINDEX, _lv);
    switch(_wATK) {
    case 0:
        _realATK = _originalATK * 1.3;
        break;
    case 1:
        _realATK = _originalATK * 0.5 * 1.3;
        break;
    case 2:
        _realATK = _originalATK * 0.25 * 1.3;
        break;
    case 3:
        _realATK = _originalATK * 0.125 * 1.3;
        break;
    case 4:
        _realATK = _originalATK * 0.0625 * 1.3;
        break;
    case 5:
        _realATK = _originalATK * 0.03125 * 1.3;
        break;
    case 6:
        _realATK = _originalATK * 0.015625 * 1.3;
        break;
    case 7:
        _realATK = _originalATK * 0.0078125 * 1.3;
        break;
    case 8:
        _realATK = _originalATK * 0.00390625 * 1.3;
        break;
    case 9:
        _realATK = 0;
        break;
    default:
        printf("error\nAt Summon::Summon()\n");
        exit(1);
    }

    switch(_wDEF) {
    case 0:
        _realDEF = _originalDEF;
        break;
    case 1:
        _realDEF = _originalDEF * 0.8;
        break;
    case 2:
        _realDEF = _originalDEF * 0.7;
        break;
    case 3:
        _realDEF = _originalDEF * 0.5;
        break;
    case 4:
        _realDEF = _originalDEF * 0.4;
        break;
    case 5:
        _realDEF = _originalDEF * 0.2;
        break;
    case 6:
        _realDEF = _originalDEF * 0.001;
        break;
    case 7:
        _realDEF = 0;
        break;
    default:
        printf("error\nAt Summon::Summon()\n");
        exit(1);
    }
}
