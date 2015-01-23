#ifndef __UNIT_H__
#define __UNIT_H__

class Unit {
public:
    int GetPlace() { return _place; }
    void Seal() { _seal = true; }
protected:
    int _place;
    double _realATK;
    double _realDEF;
    bool _double_speed;
    bool _seal;
};

#endif
