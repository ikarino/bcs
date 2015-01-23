#include "Bloodhand.hpp"

Bloodhand::Bloodhand(int place, bool double_speed) {
    _place = place;
    _hp = 26;
    _realATK = 17 * 1.3;
    _realDEF = 21;
    _double_speed = double_speed;
    _seal = false;
}
