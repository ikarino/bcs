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
    int GetArrajin() { return _arragin_count; }
    int GetNoPlaceVainCount() { return _no_place_vain_count; }
    int GetUpperLimitVainCount() { return _upper_limit_vain_count; }
    static void SetUpperLimit(int u) { __upper_limit = u; }
private:
    static unsigned long __upper_limit;
    int _upper_limit_vain_count;
    int _no_place_vain_count;
    int _arragin_count;
};

typedef std::vector<Bloodhand>::iterator itB;
#endif
