#include "Summon.hpp"
#include <cstdio>
#include <cstdlib>

Summon::Summon(int place, int maxiumHP, int originalATK, int originalDEF,
               bool doublespeed, bool seal, int wATK, int wDEF) {
    _place = place;
    _maxiumHP = maxiumHP;
    _originalATK = originalATK;
    _originalDEF = originalDEF;
    _double_speed = doublespeed;
    _seal = seal;
    _wATK = wATK;
    _wDEF = wDEF;

    switch(wATK) {
    case 0:
        _realATK = originalATK * 1.3;
        break;
    case 1:
        _realATK = originalATK * 0.5 * 1.3;
        break;
    case 2:
        _realATK = originalATK * 0.25 * 1.3;
        break;
    case 3:
        _realATK = originalATK * 0.125 * 1.3;
        break;
    case 4:
        _realATK = originalATK * 0.0625 * 1.3;
        break;
    case 5:
        _realATK = originalATK * 0.03125 * 1.3;
        break;
    case 6:
        _realATK = originalATK * 0.015625 * 1.3;
        break;
    case 7:
        _realATK = originalATK * 0.0078125 * 1.3;
        break;
    case 8:
        _realATK = originalATK * 0.00390625 * 1.3;
        break;
    case 9:
        _realATK = 0;
        break;
    default:
        printf("error\nAt Summon::Summon()\n");
        exit(1);
    }

    switch(wDEF) {
    case 0:
        _realDEF = originalDEF;
        break;
    case 1:
        _realDEF = originalDEF * 0.8;
        break;
    case 2:
        _realDEF = originalDEF * 0.7;
        break;
    case 3:
        _realDEF = originalDEF * 0.5;
        break;
    case 4:
        _realDEF = originalDEF * 0.4;
        break;
    case 5:
        _realDEF = originalDEF * 0.2;
        break;
    case 6:
        _realDEF = originalDEF * 0.001;
        break;
    case 7:
        _realDEF = 0;
        break;
    default:
        printf("error\nAt Summon::Summon()\n");
        exit(1);
    }
}

Summon::~Summon() {}
