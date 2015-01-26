#include "Map.hpp"
#include "status.hpp"
#include <unistd.h>
#include <vector>

Map::Map() {
    // printf("Initializing data\n");
    //
    // ここの初期化はほとんどインプットファイルによるものに書き換える。
    //
    std::string filename("input.bcs");
    inp = new Input(filename);


    // info初期化
    for(int i = 0; i < 400; i++) {
        if (i%20 == 0 || i%20 == 19 || i/20 == 0 || i/20 == 19) {
            info[i] = 1;
        } else {
            info[i] = 0;
        }
    }
    // パラメータ初期化
    _T = 1500;
    _N = 1;

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


void Map::ShowFinishStatus(std::vector<int>* data) {
    int data_index = 0;
    printf("============RESULT============\n");
    printf("Summons\n");
    double sum = 0;
    for (auto it = summons.begin(); it != summons.end(); ++it) {
        printf("-----------------------------\n");
        printf("MONSTER: %s\n", GetName(it->GetMonsterINDEX()).c_str());
        printf("Pos X: %d, Y: %d\n", it->GetPlace()/20, it->GetPlace()%20);
        sum += (double)data->at(data_index)/_N;
        printf("EXP         : %.2f\n", (double)data->at(data_index++)/_N * 560);
        printf("Active turn : %.2f\n", (double)data->at(data_index++)/_N);
    }
    printf("==============================\n");
    printf("Total EXP: %3f\n", sum * 560);
    printf("==============================\n");
    printf("Bloodhands\n");
    for (auto it = bloodhands.begin(); it != bloodhands.end(); it++) {
        printf("-----------------------------\n");
        printf("Pos X: %d, Y: %d\n", it->GetPlace()/20, it->GetPlace()%20);
        printf(" # of daimajin    : %.2f\n", (double)data->at(data_index++)/_N);
        printf(" # of no place    : %.2f\n", (double)data->at(data_index++)/_N);
        printf(" # of upper limit : %.2f\n", (double)data->at(data_index++)/_N);
    }

}


void Map::GetFinishStatus(std::vector<int>* data) {
    int data_index = 0;
    for (auto it = summons.begin(); it != summons.end(); ++it) {
        data->at(data_index++) += it->GetKillCount();
        data->at(data_index++) += it->GetActiveTurn();
    }
    for (auto it = bloodhands.begin(); it != bloodhands.end(); it++) {
        data->at(data_index++) += it->GetArrajin();
        data->at(data_index++) += it->GetNoPlaceVainCount();
        data->at(data_index++) += it->GetUpperLimitVainCount();
    }

}


void Map::AddTestCondition() {
    info[189] = 1;
    info[209] = 1;
    info[229] = 1;
    info[190] = 1;
    info[230] = 1;
    AddDecoyKinoko(211);
    AddBloodhand(210);
    AddKillerMachine(252);
    AddKillerMachine(232);
    AddKillerMachine(212);
    AddKillerMachine(192);
    AddKillerMachine(172);
    // AddEliminator(172);
}

void Map::Run1turn() {
    // printf("Number of Daimajins are %ld\n", daimajins.size());

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
    // ブラッドハンドの行動2
    for (auto it = bloodhands.begin(); it != bloodhands.end(); ++it){
        if (it->isDoubleSpeed()) {
            it->Action(info[0], &summons, &daimajins);
        }
#ifdef GUI
        SetGUI();
#endif
    }
    // 仲間の行動2
    for (auto it = summons.begin(); it != summons.end(); ++it){
        if (it->isDoubleSpeed()) {
            it->Action(info[0], &daimajins, &summons);
        }
#ifdef GUI
        SetGUI();
#endif
    }
    // PrintInfo();
}

void Map::Run() {

    // 格納すべき情報
    // - Summon
    // * exp
    // * active
    // - Bloodhand
    // * arrajin
    // * no place
    // * upper limit
    std::vector<int> data;
    int data_number = summons.size()*2 + bloodhands.size()*3;
    for (int i = 0; i < data_number; i++) {
        data.push_back(0);
    }

    for (int n = 0; n < _N; n++) {
        // Some function to initialize
        for (int t = 0; t < _T; t++) {
            Run1turn();
        }
        for (auto it = bloodhands.begin(); it != bloodhands.end(); it++) {
            // printf("HP: %d\n", it->GetIncidentHP());
        }
        GetFinishStatus(&data);
    }
    ShowFinishStatus(&data);
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


void Map::AddEliminator(int place) {
    Summon s(place, 201, 50, 100, false, 0, 0, false, false);
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
