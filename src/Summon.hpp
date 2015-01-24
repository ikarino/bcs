#ifndef __SUMMON_H_
#define __SUMMON_H_

#include "Unit.hpp"
#include <vector>

class Daimajin;
class Summon : public Unit {
public:
    Summon(int place, int monsterINDEX, int lv, int dope, bool doublespeed,
           int watk, int wdef, bool seal, bool inivisible);
    ~Summon();
    bool isInvsible() { return _invisible; }
    int GetMHP() { return _maximumHP; }
    int GetIncidentEXP() { return _exp; }
    void Action(int &info, std::vector<Daimajin> *en);
    void KilledSasaki();
    void SetAbilityScore();
private:
    int _monsterINDEX;
    int _lv;
    int _dope;
    int _maximumHP;
    int _wATK;
    int _wDEF;
    int _originalATK;
    int _originalDEF;
    int _exp;
    bool _invisible;
};

#endif
