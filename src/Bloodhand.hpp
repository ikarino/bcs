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
    static void SetUpperLimit(int u) { __upper_limit = u; }
private:
    static unsigned long __upper_limit;
    int _vain_count;
};

#endif
