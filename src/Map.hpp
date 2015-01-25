#ifndef __MAP_H__
#define __MAP_H__

#include "Summon.hpp"
#include "Daimajin.hpp"
#include "Bloodhand.hpp"
#include "GUIField.hpp"
#include <vector>

class GUIField;

class Map {
public:
    Map();
    ~Map();
    void SetGUI();
    void ChangeGUI(int field_index, int color_index);
    void SetInfo(int place, int index) { info[place] = index; };
    void AddDaimajin(int place);
    void AddBloodhand(int place);
    void AddHoi(int place);
    void Run();
    void PrintInfo();
private:
    // Input inp;
    std::vector<Summon> summons;
    std::vector<Daimajin> daimajins;
    std::vector<Bloodhand> bloodhands;
    int upper_limit;
    int info[400];
    /*
      info == 0 : empty
      info == 1 : wall or paralyzed daimajin
      info == 2 : daimajin
      info == 3 : bloodhand
      info == 4 : summon visible
      info == 5 : summon invisible
     */
    GUIField *gui;
};

#endif
