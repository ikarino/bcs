#ifndef __BLOODHAND_H__
#define __BLOODHAND_H__

#include "Unit.hpp"


class Bloodhand : public Unit {
public:
    Bloodhand(int place, bool double_speed);
private:
    int _hp;
};

#endif
