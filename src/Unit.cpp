#include "Unit.hpp"
#include <cstdlib>
#include <cstdio>
#include <cmath>

void Unit::GetDamage(double at) {
    if (at == 0) {
        printf("AT is 0. Just seeing how it goes.\n");
        return;
    }
    if (rand()%100 < 92) {
        int dm = static_cast<int>(floor(at*pow(0.97222222, _realDEF)
                                        *(112+rand()%32)/128 + 0.5));
        if (dm != 0) {
            _hp -= dm;
        } else {
            _hp -= 1;
        }
        printf("Damage : %d\n", dm);
    } else {
        printf("Missed\n");
    }
}
