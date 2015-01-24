#include "Summon.hpp"
#include "Daimajin.hpp"
#include "status.hpp"
#include <cstdio>
#include <cstdlib>

Summon::Summon(int place, int monsterINDEX, int lv, int dope, bool doublespeed,
       int wATK, int wDEF, bool seal, bool invisible) {
    _place = place;
    _monsterINDEX = monsterINDEX;
    _lv = lv;
    _dope = dope;
    _wATK = wATK;
    _wDEF = wDEF;
    _invisible = invisible;

    _hp = _maximumHP;
    _double_speed = doublespeed;
    _seal = seal;
    _exp = GetEXP(monsterINDEX, lv);

    SetAbilityScore();
}


Summon::~Summon() {}

void Summon::Action(int &info, std::vector<Daimajin> *sm) {
    // 隣接しているすべての敵の場所を取得。
    int list[] = {-21, -20, -19, -1, 1, 19, 20, 21};
    std::vector<int> targets;
    for (int i = 0; i < 8; ++i) {
        if ((&info)[_place + list[i]] == 2) {
            targets.push_back(_place+list[i]);
        }
    }

    // 隣接していない場合return
    if (targets.size() == 0) {
        return;
    }

    // 攻撃対象を決定
    int target_place = rand() % targets.size();

    // ここから先はモンスターの種類によって異なると思う。
    // とりあえず単純攻撃だけ実装しておく。
    for (auto it = sm->begin(); it != sm->end(); ++it) {
        if (it->GetPlace() == target_place) {
            printf("Daimajin was Attacked!\n");
            it->GetDamage(_realATK);
            if (it->GetIncidentHP() <= 0) {
                sm->erase(it);
                KilledSasaki();
            }
        }
    }
}


void Summon::KilledSasaki() {
    printf("Yeah ! I killed Sasaki !\n");
    _exp += 560;
    if (_exp > GetEXP(_monsterINDEX, _lv)) {
        printf("LEVEL UP !!\n");
        _lv += 1;
        SetAbilityScore();
    }
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
