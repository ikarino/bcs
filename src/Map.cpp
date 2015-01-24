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
    AddDaimajin(215);
    AddHoi(218);
    AddHoi(305);
}


void Map::Run() {
    // printf("Number of Daimajins are %ld\n", daimajins.size());
    // for (std::vector<Daimajin>::iterator it = daimajins.begin(); it != daimajins.end(); ++it){

    // だいまじんの行動
    for (auto it = daimajins.begin(); it != daimajins.end(); ++it){
        int place_before = it->GetPlace();
        it->Action(info[0], &summons);
        int place_after = it->GetPlace();
        info[place_before] = 0;
        info[place_after] = 2;
        SetGUI();
    }
    // 仲間の行動
    for (auto it = summons.begin(); it != summons.end(); ++it){
        it->Action(info[0], &daimajins);
        SetGUI();
    }
    // PrintInfo();
}


void Map::SetGUI() {
    gui->setColor(info);
}

void Map::AddDaimajin(int place) {
    Daimajin d(place);
    printf("HP : %d\n", d.GetIncidentHP());
    daimajins.push_back(d);
    info[place] = 2;
    ChangeGUI(place, 2);
}

void Map::AddHoi(int place) {
    Summon s(place, 120, 30, 0, false, 0, 0, false, false);
    summons.push_back(s);
    if (s.isInvsible()) {
        info[place] = 5;
        ChangeGUI(place, 5);
    } else {
        info[place] = 4;
        ChangeGUI(place, 4);
    }
}


void Map::ChangeGUI(int field_index, int color_index) {
    gui->changeColor(field_index, color_index);
}

Map::~Map() {};


void Map::PrintInfo() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%d", info[i+j*20]);
        }
        printf("\n");
    }
}
