#ifndef __BLOODHAND_H__
#define __BLOODHAND_H__

#include "Unit.hpp"
#include <vector>

class Summon;
class Daimajin;
class Bloodhand : public Unit {
public:
    Bloodhand(int place, bool double_speed);
    void Action(int &info, std::vector<Summon> *sm, std::vector<Daimajin> *dm);
private:
};

#endif
