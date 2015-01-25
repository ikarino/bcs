#include "Map.hpp"
#include "status.hpp"
#include <unistd.h>

Map::Map() {
    // printf("Initializing data\n");
    //
    // ここの初期化はほとんどインプットファイルによるものに書き換える。
    //
    for(int i = 0; i < 400; i++) {
        if (i%20 == 0 || i%20 == 19 || i/20 == 0 || i/20 == 19) {
            info[i] = 1;
        } else {
            info[i] = 0;
        }
    }
#ifdef GUI
    gui = new GUIField();
    SetGUI();
#endif

    // Setting the daimajin upper limit
    upper_limit = 20;
    Bloodhand::SetUpperLimit(upper_limit);

    // Test
    AddTestCondition();
#ifdef GUI
    SetGUI();
#endif
    // printf("Finished initialization\n");
}


void Map::ShowFinishStatus() {
    printf("============RESULT============\n");
    int sum = 0;
    for (auto it = summons.begin(); it != summons.end(); ++it) {
        sum += it->GetKillCount()*560;
        printf("-----------------------------\n");
        printf("MONSTER: %s\n", GetName(it->GetMonsterINDEX()).c_str());
        printf("Pos X: %d, Y: %d\n", it->GetPlace()/20, it->GetPlace()%20);
        printf("EXP    : %d\n", it->GetKillCount()*560);
    }
    printf("==============================\n");
    printf("Total EXP: %d\n", sum);
    printf("==============================\n");
}


void Map::AddTestCondition() {
    info[189] = 1;
    info[209] = 1;
    info[229] = 1;
    info[190] = 1;
    info[230] = 1;
    AddDecoyKinoko(211);
    AddBloodhand(210);
    AddKillerMachine(192);
    AddKillerMachine(212);
    AddKillerMachine(232);
}

void Map::Run() {
    // printf("Number of Daimajins are %ld\n", daimajins.size());
    // for (std::vector<Daimajin>::iterator it = daimajins.begin(); it != daimajins.end(); ++it){

    // ブラッドハンドの行動
    for (auto it = bloodhands.begin(); it != bloodhands.end(); ++it){
        it->Action(info[0], &summons, &daimajins);
#ifdef GUI
        SetGUI();
#endif
    }
    // だいまじんの行動
    for (auto it = daimajins.begin(); it != daimajins.end(); ++it){
        it->Action(info[0], &summons);
#ifdef GUI
        SetGUI();
#endif
    }
    // 仲間の行動
    for (auto it = summons.begin(); it != summons.end(); ++it){
        it->Action(info[0], &daimajins, &summons);
#ifdef GUI
        SetGUI();
#endif
    }
    // PrintInfo();
}


void Map::SetGUI() {
    gui->setColor(info);
    // usleep(100000);
    usleep(10000);
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

void Map::AddKillerMachine(int place) {
    Summon s(place, 613, 50, 100, false, 0, 0, false, false);
    summons.push_back(s);
    if (s.isInvsible()) {
        info[place] = 5;
    } else {
        info[place] = 4;
    }
}

void Map::AddDecoyKinoko(int place) {
    Summon s(place, 606, 60, 1000, false, 9, 0, false, false);
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
