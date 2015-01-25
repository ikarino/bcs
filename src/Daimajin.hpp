#ifndef __DAIMAJIN_H__
#define __DAIMAJIN_H__
#include "Unit.hpp"
#include <vector>

class Summon;
class Daimajin : public Unit {
public:
    explicit Daimajin(int place);
    Daimajin(int, int);
    void Action(int &info, std::vector<Summon> *sm);
    void Get25();
};
int calc_len(int, int, int, int);
int calc_minimum(int, int, int, int, int &);
#endif
