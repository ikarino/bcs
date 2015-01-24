#ifndef __UNIT_H__
#define __UNIT_H__

class Unit {
public:
    int GetPlace() { return _place; }
    void Seal() { _seal = true; }
    void GetDamage(double at);
    int GetIncidentHP() { return _hp; }
protected:
    int _place;
    int _hp;
    double _realATK;
    double _realDEF;
    bool _double_speed;
    bool _seal;
};

#endif
