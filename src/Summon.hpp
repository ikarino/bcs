#ifndef __SUMMON_H_
#define __SUMMON_H_

#include "Unit.hpp"

class Summon : public Unit {
public:
    Summon(int _place, int _maxiumHP, int _originalATK, int _originalDEF,
           bool _double_speed, bool _seal, int wATK, int wDEF);
    ~Summon();
    int GetMHP() { return _maxiumHP; }
private:
    int _monsterINDEX;
    int _maxiumHP;
    int _wATK;
    int _wDEF;
    int _originalATK;
    int _originalDEF;
};

#endif
