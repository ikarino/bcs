#ifndef __DAIMAJIN_H__
#define __DAIMAJIN_H__
#include "Unit.hpp"

class Daimajin : public Unit {
public:
    Daimajin(int place);
    void Action(int &info);
private:
    int _hp;
};

int calc_len(int, int, int, int);
int calc_minimum(int, int, int, int);
#endif
