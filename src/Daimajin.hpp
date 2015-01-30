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
    void Tukon(double at);
};

// original
int calc_len(int, int, int, int);
int calc_minimum(int, int, int, int, int &);
// test 対象は同じで等距離の位置がある場合、ランダムで動く
int calc_len(int, int);
int calc_minimum(int, int, int &);


typedef std::vector<Daimajin>::iterator itD;
typedef std::vector<Daimajin*>::iterator pitD;
#endif
