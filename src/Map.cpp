#include "Map.hpp"
#include "status.hpp"
#include <unistd.h>
#include <vector>
#include <cstdlib>

Map::Map(std::string filename) {
    // printf("Initializing data\n");
    //
    // ここの初期化はほとんどインプットファイルによるものに書き換える。
    //
    inp = new Input(filename);
    _N = inp->GetN();
    _T = inp->GetT();
    _upper_limit = inp->GetUpperLimit();
    Bloodhand::SetUpperLimit(_upper_limit);

#ifdef GUI
    gui = new GUIField();
    _N = 1;
#endif
}


void Map::ShowFinishStatus(std::vector<int>* data) {
    int data_index = 0;
    printf("============RESULT============\n");
    printf("Summons\n");
    double sum = 0;
    int i = 0;
    for (auto it = summons.begin(); it != summons.end(); ++it) {
        printf("-----------------------------\n");
        printf("No. %d\n", i++);
        printf("MONSTER: %s\n", GetName(it->GetMonsterINDEX()).c_str());
        printf("Pos X: %d, Y: %d\n", it->GetPlace()/20, it->GetPlace()%20);
        sum += (double)data->at(data_index)/_N;
        printf("EXP         : %.2f\n", (double)data->at(data_index++)/_N * 560);
        if (it->isDoubleSpeed()) {
            printf("Active turn : %.2f\n", (double)data->at(data_index++)/_N/2);
        } else {
            printf("Active turn : %.2f\n", (double)data->at(data_index++)/_N);
        }
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


void Map::InitWithInputFile() {
    // init
    summons.clear();
    daimajins.clear();
    bloodhands.clear();

    // reading from input file
    std::vector<int>* data = inp->GetSummonData();
    std::string mp = inp->GetMapString();

    // invisible data
    bool invisible[] = {false, false, false, false, false, false, false, false, false, false};
    for (int i = 0; i < 10; i++) {
        if (data->at(i*8+7) == 1) {
            invisible[i] = true;
        }
    }
    // Info
    int summon_place[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    std::vector<int> bloodhand_place;
    for (int i = 0; i < 400; i++) {
        switch(mp[i]) {
        case '-':
            info[i] = 0;
            break;
        case '+':
            info[i] = 1;
            break;
        case '*':
            info[i] = 3;
            bloodhand_place.push_back(i);
            break;
        default:
            int id = mp[i]-48;
            summon_place[id] = i;
            if (invisible[id]) {
                info[i] = 5;
            } else {
                info[i] = 4;
            }
            break;
        }
    }

    // Summon data
    for (int i = 0; i < 10; i++) {
        Summon s(summon_place[i], data->at(i*8+0), data->at(i*8+1),
                 data->at(i*8+2), data->at(i*8+3), data->at(i*8+4),
                 data->at(i*8+5), data->at(i*8+6), data->at(i*8+7));
        summons.push_back(s);
    }

    // Blood hand data
    if (inp->isDoubleSpeed()) {
        for (int i = 0; i < bloodhand_place.size(); i++) {
            Bloodhand b(bloodhand_place[i], true);
            bloodhands.push_back(b);
        }
    } else {
        for (int i = 0; i < bloodhand_place.size(); i++) {
            Bloodhand b(bloodhand_place[i], false);
            bloodhands.push_back(b);
        }
    }
    // printf("Initialization finished.\n");
 };


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
    // printf("HP= %d\n", summons.back().GetIncidentHP());
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
    InitWithInputFile();
    std::vector<int> data;
    int data_number = summons.size()*2 + bloodhands.size()*3;
    for (int i = 0; i < data_number; i++) {
        data.push_back(0);
    }

    for (int n = 0; n < _N; n++) {
        InitWithInputFile();
        printf("\tn=%d\n", n+1);
        for (int t = 0; t < _T; t++) {
            Run1turn();
        }
        GetFinishStatus(&data);
    }
    ShowFinishStatus(&data);
}


#ifdef GUI
void Map::SetGUI() {
    gui->setColor(info);
    // usleep(100000);
    usleep(100);
}


/*
  void Map::ChangeGUI(int field_index, int color_index) {
  gui->changeColor(field_index, color_index);
  }
*/
#endif

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


Map::~Map() {
    delete inp;
#ifdef GUI
    delete gui;
#endif
};


void Map::PrintInfo() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%d", info[i+j*20]);
        }
        printf("\n");
    }
}
