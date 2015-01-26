#include "Unit.hpp"
#include <cstdlib>
#include <cstdio>
#include <cmath>

void Unit::GetDamage(double at) {
    if (at == 0) {
#ifdef DEBUG
        printf("AT is 0. Just seeing how it goes.\n");
#endif
        return;
    }
    if (rand()%100 < 92) {
        int dm = static_cast<int>(1.5*floor(at*pow(0.97222222, _realDEF)
                                            *(112+rand()%32)/128 + 0.5));
        if (dm != 0) {
            _hp -= dm;
        } else {
            _hp -= 1;
        }
#ifdef DEBUG
        printf("Damage : %d\n", dm);
    } else {
        printf("Missed\n");
#endif
    }
}
