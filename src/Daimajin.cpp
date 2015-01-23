#include "Daimajin.hpp"
#include <cstdio>

Daimajin::Daimajin(int place) {
    _place = place;
    _hp = 135;
    _realATK = 44 * 1.3;
    _realDEF = 51;
    _double_speed = false;
    _seal = false;
}


void Daimajin::Action(int &info) {
    int dx = GetPlace()/20;
    int dy = GetPlace()%20;
    int out = 400;
    int tx = -1;
    int ty = -1;
    for(int x = 0; x < 20; x++) {
        for(int y = 0; y < 20; y++) {
            if ((&info)[x*20+y] != 4) { continue; };
            int len = calc_len(x, y, dx, dy);
            if (out > len) {
                out = len;
                tx = x;
                ty = y;
            }
        }
    }
    if (tx == -1) {
        printf("No Summon Found\n");
        return;
    } else {
        printf("Summon Found at x = %d, y = %d\n", tx, ty);
        _place += calc_minimum(dx, dy, tx, ty);
        return;
    }
}

int calc_len(int x, int y, int X, int Y) {
    return (x-X)*(x-X) + (y-Y)*(y-Y);
}

int calc_minimum(int x, int y, int X, int Y) {
    int ret = 0;
    int len = calc_len(x, y, X, Y);
    if (len > calc_len(x-1, y-1, X, Y)) {
        ret = -21;
        len = calc_len(x-1, y-1, X, Y);
    }
    if (len > calc_len(x-1, y, X, Y)) {
        ret = -20;
        len = calc_len(x-1, y, X, Y);
    }
    if (len > calc_len(x-1, y+1, X, Y)) {
        ret = -19;
        len = calc_len(x-1, y+1, X, Y);
    }
    if (len > calc_len(x, y-1, X, Y)) {
        ret = -1;
        len = calc_len(x, y-1, X, Y);
    }
    if (len > calc_len(x, y+1, X, Y)) {
        ret = +1;
        len = calc_len(x, y+1, X, Y);
    }
    if (len > calc_len(x+1, y-1, X, Y)) {
        ret = +19;
        len = calc_len(x+1, y-1, X, Y);
    }
    if (len > calc_len(x+1, y, X, Y)) {
        ret = 20;
        len = calc_len(x+1, y, X, Y);
    }
    if (len > calc_len(x+1, y+1, X, Y)) {
        ret = 21;
        len = calc_len(x+1, y+1, X, Y);
    }
    return ret;
}
