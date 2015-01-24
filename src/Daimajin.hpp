#ifndef __DAIMAJIN_H__
#define __DAIMAJIN_H__
#include "Unit.hpp"
#include <vector>

class Summon;
class Daimajin : public Unit {
public:
    Daimajin(int place);
    void Action(int &info, std::vector<Summon> *sm);
private:
    int _hp;
};

int calc_len(int, int, int, int);
int calc_minimum(int, int, int, int);
#endif
