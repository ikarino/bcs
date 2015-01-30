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
    unsigned int GetKillCount() { return _kill_count; }
    unsigned int GetActiveTurn() { return _active_turn; }
    int GetMonsterINDEX() { return _monsterINDEX; }

    void ShowStatus();
    void Action(int &info, std::vector<Daimajin> *en, std::vector<Summon> *sm);
    void KilledSasaki();
    void SetAbilityScore();
    void StandardAttack(int target_place, int &info, std::vector<Daimajin> *dm);
    void KillerMachine(int target_place, int &info, std::vector<Daimajin> *dm);
    void Hoimin(int &info, std::vector<Daimajin> *dmm, std::vector<Summon> *sm);
    void Get25();
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
    int _rec;
    bool _invisible;

    unsigned int _kill_count;
    unsigned int _active_turn;
};

typedef std::vector<Summon>::iterator itS;
typedef std::vector<Summon*>::iterator pitS;
#endif
