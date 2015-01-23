#include "Map.hpp"
#include "GUIField.hpp"
#include "Daimajin.hpp"

Map::Map() {
    for(int i = 0; i < 400; i++) {
        if (i%20 == 0 || i%20 == 19 || i/20 == 0 || i/20 == 19) {
            info[i] = 1;
        } else {
            info[i] = 0;
        }
    }
    gui = new GUIField();
    SetGUI();

    // Test
    AddDaimajin(21);
    AddHoi(218);
    AddHoi(305);
}


void Map::Run() {
    // printf("Number of Daimajins are %ld\n", daimajins.size());
    // for (std::vector<Daimajin>::iterator it = daimajins.begin(); it != daimajins.end(); ++it){
    for (auto it = daimajins.begin(); it != daimajins.end(); ++it){
        int place_before = it->GetPlace();
        it->Action(info[0]);
        int place_after = it->GetPlace();
        info[place_before] = 0;
        info[place_after] = 2;
        SetGUI();
    }
}


void Map::SetGUI() {
    gui->setColor(info);
}

void Map::AddDaimajin(int place) {
    Daimajin d(place);
    daimajins.push_back(d);
    info[place] = 2;
    ChangeGUI(place, 2);
}

void Map::AddHoi(int place) {
    Summon s(place, 120, 30, 30, false, false, 0, 0);
    summons.push_back(s);
    info[place] = 4;
    ChangeGUI(place, 4);
}


void Map::ChangeGUI(int field_index, int color_index) {
    gui->changeColor(field_index, color_index);
}

Map::~Map() {};
