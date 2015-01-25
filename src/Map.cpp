#include "Map.hpp"
#include "GUIField.hpp"
#include "Daimajin.hpp"
#include <unistd.h>

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
    info[42] = 1;
    info[62] = 1;
    info[82] = 1;
    info[284] = 1;
    info[285] = 1;
    info[286] = 1;
    AddDaimajin(21);
    AddDaimajin(215);
    AddDaimajin(41);
    AddBloodhand(210);
    AddHoi(218);
    AddHoi(305);
    SetGUI();
}


void Map::Run() {
    // printf("Number of Daimajins are %ld\n", daimajins.size());
    // for (std::vector<Daimajin>::iterator it = daimajins.begin(); it != daimajins.end(); ++it){

    // ブラッドハンドの行動
    for (auto it = bloodhands.begin(); it != bloodhands.end(); ++it){
        it->Action(info[0], &summons, &daimajins);
        SetGUI();
    }
    // だいまじんの行動
    for (auto it = daimajins.begin(); it != daimajins.end(); ++it){
        it->Action(info[0], &summons);
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
    usleep(100000);
}

void Map::AddDaimajin(int place) {
    Daimajin d(place);
    daimajins.push_back(d);
    info[place] = 2;
}

void Map::AddBloodhand(int place) {
    Bloodhand b(place, true);
    bloodhands.push_back(b);
    info[place] = 3;
}

void Map::AddHoi(int place) {
    Summon s(place, 120, 99, 1000, false, 0, 0, false, false);
    summons.push_back(s);
    if (s.isInvsible()) {
        info[place] = 5;
    } else {
        info[place] = 4;
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
