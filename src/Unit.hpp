#ifndef __UNIT_H__
#define __UNIT_H__

class Unit {
public:
    int GetPlace() { return _place; }
    bool isSealed() { return _seal; };
    bool isDoubleSpeed() { return _double_speed; }
    int GetIncidentHP() { return _hp; }
    void Seal() { _seal = true; }
    void GetDamage(double at);
protected:
    int _place;
    double _hp;
    double _realATK;
    double _realDEF;
    bool _double_speed;
    bool _seal;
};

#endif
