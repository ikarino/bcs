// Copyright 2014 ikarino
#include "status.hpp"
#include <cstdlib>
#include <iostream>

int GetEXP(int sp, int lv) {
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int htsz_ex[99] = {0, 3, 10, 30, 50, 100, 150, 200, 300, 500, 800, 1000, 1200, 1500, 1800, 2000, 2500, 3000, 4000, 5000, 6500, 8000, 10000, 13000, 16000, 20000, 25000, 30000, 36000, 42000, 48000, 54000, 60000, 70000, 80000, 90000, 100000, 115000, 130000, 145000, 160000, 175000, 200000, 230000, 260000, 290000, 320000, 350000, 380000, 410000, 440000, 470000, 500000, 530000, 560000, 590000, 620000, 650000, 680000, 710000, 750000, 790000, 830000, 870000, 910000, 950000, 990000, 1030000, 1070000, 1120000, 1170000, 1220000, 1270000, 1320000, 1370000, 1420000, 1470000, 1520000, 1570000, 1620000, 1670000, 1720000, 1770000, 1820000, 1880000, 1940000, 2000000, 2060000, 2120000, 2180000, 2240000, 2300000, 2360000, 2420000, 3000000, 5000000, 7000000, 9000000, 9990000};
  int kgsz_ex[99] = {0, 10, 30, 60, 120, 160, 300, 500, 750, 1000, 1250, 1600, 2000, 2600, 3200, 4000, 5000, 6500, 8000, 9500, 11000, 13000, 16000, 19000, 22000, 25000, 28000, 31000, 36000, 42000, 48000, 54000, 60000, 70000, 80000, 90000, 100000, 115000, 130000, 145000, 160000, 175000, 200000, 230000, 260000, 290000, 320000, 350000, 380000, 410000, 440000, 470000, 500000, 530000, 560000, 590000, 620000, 650000, 680000, 710000, 750000, 790000, 830000, 870000, 910000, 950000, 990000, 1030000, 1070000, 1120000, 1170000, 1220000, 1270000, 1320000, 1370000, 1420000, 1470000, 1520000, 1570000, 1620000, 1670000, 1720000, 1770000, 1820000, 1880000, 1940000, 2000000, 2060000, 2120000, 2180000, 2240000, 2300000, 2360000, 2420000, 3000000, 5000000, 7000000, 9000000, 9990000};
  int bgsz_ex[99] = {0, 35, 100, 300, 600, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 13000, 15000, 17000, 20000, 23000, 26000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 70000, 80000, 90000, 100000, 115000, 130000, 145000, 160000, 175000, 200000, 230000, 260000, 290000, 320000, 350000, 380000, 410000, 440000, 470000, 500000, 530000, 560000, 590000, 620000, 650000, 680000, 710000, 750000, 790000, 830000, 870000, 910000, 950000, 990000, 1030000, 1070000, 1120000, 1170000, 1220000, 1270000, 1320000, 1370000, 1420000, 1470000, 1520000, 1570000, 1620000, 1670000, 1720000, 1770000, 1820000, 1880000, 1940000, 2000000, 2060000, 2120000, 2180000, 2240000, 2300000, 2360000, 2420000, 3000000, 5000000, 7000000, 9000000, 9990000};
  int bnbn_ex[99] = {0, 150, 500, 1300, 2500, 4000, 8000, 16000, 20000, 30000, 40000, 60000, 80000, 100000, 130000, 160000, 190000, 220000, 250000, 280000, 310000, 340000, 370000, 400000, 440000, 480000, 520000, 560000, 600000, 640000, 680000, 720000, 760000, 800000, 840000, 880000, 920000, 960000, 1000000, 1040000, 1090000, 1140000, 1190000, 1240000, 1290000, 1340000, 1390000, 1440000, 1490000, 1540000, 1590000, 1640000, 1690000, 1740000, 1790000, 1840000, 1890000, 1940000, 1990000, 2040000, 2090000, 2140000, 2190000, 2240000, 2290000, 2340000, 2390000, 2440000, 2490000, 2540000, 2590000, 2640000, 2690000, 2740000, 2790000, 2840000, 2890000, 2940000, 2990000, 3040000, 3100000, 3160000, 3220000, 3400000, 3600000, 3800000, 4000000, 4200000, 4400000, 4600000, 4800000, 5000000, 5500000, 6000000, 6500000, 7000000, 8000000, 9000000, 9990000};
  int kgbn_ex[99] = {0, 45, 200, 600, 1000, 1600, 2500, 3500, 4500, 5500, 7000, 8500, 10000, 20000, 30000, 50000, 70000, 90000, 110000, 130000, 150000, 170000, 190000, 210000, 230000, 240000, 250000, 260000, 270000, 280000, 290000, 300000, 310000, 320000, 330000, 340000, 350000, 360000, 370000, 380000, 390000, 400000, 410000, 420000, 430000, 440000, 450000, 460000, 470000, 480000, 490000, 500000, 510000, 520000, 530000, 540000, 550000, 560000, 570000, 580000, 630000, 680000, 730000, 780000, 830000, 880000, 930000, 980000, 1030000, 1090000, 1150000, 1210000, 1270000, 1330000, 1390000, 1450000, 1510000, 1570000, 1630000, 1690000, 1750000, 1810000, 1870000, 1930000, 1990000, 2050000, 2110000, 2170000, 2230000, 2310000, 2390000, 2470000, 2550000, 2630000, 3000000, 5000000, 7000000, 9000000, 9990000};
  int bgbn_ex[99] = {0, 55, 300, 900, 1300, 2000, 3500, 5000, 7500, 10000, 12500, 15500, 20000, 30000, 40000, 50000, 70000, 90000, 110000, 130000, 150000, 170000, 190000, 210000, 230000, 240000, 250000, 260000, 270000, 280000, 290000, 300000, 310000, 320000, 330000, 340000, 350000, 360000, 370000, 380000, 390000, 400000, 410000, 420000, 430000, 440000, 450000, 460000, 470000, 480000, 490000, 500000, 510000, 520000, 530000, 540000, 550000, 560000, 570000, 580000, 630000, 680000, 730000, 780000, 830000, 880000, 930000, 980000, 1030000, 1090000, 1150000, 1210000, 1270000, 1330000, 1390000, 1450000, 1510000, 1570000, 1630000, 1690000, 1750000, 1810000, 1870000, 1930000, 1990000, 2050000, 2110000, 2170000, 2230000, 2310000, 2390000, 2470000, 2550000, 2630000, 3000000, 5000000, 7000000, 9000000, 9990000};
  int kgtk_ex[99] = {0, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000, 1100000, 1200000, 1300000, 1400000, 1500000, 1600000, 1700000, 1800000, 1900000, 2000000, 2100000, 2200000, 2300000, 2400000, 2500000, 2600000, 2700000, 2800000, 2900000, 3000000, 3100000, 3200000, 3300000, 3400000, 3500000, 3600000, 3700000, 3800000, 3900000, 4000000, 4100000, 4200000, 4300000, 4400000, 4500000, 4600000, 4700000, 4800000, 4900000, 5000000, 5100000, 5200000, 5300000, 5400000, 5500000, 5600000, 5700000, 5800000, 5900000, 6000000, 6100000, 6200000, 6300000, 6400000, 6500000, 6600000, 6700000, 6800000, 6900000, 7000000, 7100000, 7200000, 7300000, 7400000, 7500000, 7600000, 7700000, 7800000, 7900000, 8000000, 8100000, 8200000, 8300000, 8400000, 8500000, 8600000, 8700000, 8800000, 8900000, 9000000, 9100000, 9200000, 9300000, 9400000, 9500000, 9600000, 9700000, 9990000};
  int sytk_ex[99] = {0, 100, 350, 900, 1300, 2000, 3500, 5000, 7500, 10000, 12500, 15500, 20000, 30000, 40000, 50000, 70000, 90000, 110000, 130000, 150000, 170000, 190000, 210000, 230000, 270000, 300000, 330000, 360000, 380000, 390000, 420000, 470000, 520000, 570000, 620000, 670000, 720000, 770000, 820000, 870000, 920000, 970000, 1020000, 1070000, 1120000, 1170000, 1220000, 1270000, 1320000, 1380000, 1440000, 1500000, 1560000, 1620000, 1680000, 1740000, 1800000, 1860000, 1920000, 1980000, 2040000, 2100000, 2160000, 2220000, 2280000, 2340000, 2400000, 2460000, 2520000, 2580000, 2640000, 2700000, 2760000, 2820000, 2880000, 2940000, 3000000, 3060000, 3120000, 3180000, 3250000, 3320000, 3390000, 3460000, 3530000, 3600000, 3670000, 3740000, 3810000, 3880000, 3950000, 4020000, 4090000, 4160000, 5000000, 7000000, 9000000, 9990000};

  switch(sp/100) {
    case 1:
      return htsz_ex[lv-1];
      break;
    case 2:
      return kgsz_ex[lv-1];
      break;
    case 3:
      return bgsz_ex[lv-1];
      break;
    case 4:
      return bnbn_ex[lv-1];
      break;
    case 5:
      return kgbn_ex[lv-1];
      break;
    case 6:
      return bgbn_ex[lv-1];
      break;
    case 7:
      return kgtk_ex[lv-1];
      break;
    case 8:
      return sytk_ex[lv-1];
      break;
  }

  return -1;
}
int GetHP(int sp, int lv){  int hp;
  switch(sp/100){
    case 1:
      switch(sp%100){
        case 1:
          hp=8;
          break;
        case 2:
          hp=35;
          break;
        case 3:
          hp=85;
          break;
        case 4:
          hp=62;
          break;
        case 5:
          hp=50;
          break;
        case 6:
          hp=45;
          break;
        case 7:
          hp=70;
          break;
        case 8:
          hp=5;
          break;
        case 9:
          hp=6;
          break;
        case 10:
          hp=100;
          break;
        case 11:
          hp=35;
          break;
        case 12:
          hp=45;
          break;
        case 13:
          hp=100;
          break;
        case 14:
          hp=7;
          break;
        case 15:
          hp=42;
          break;
        case 16:
          hp=50;
          break;
        case 17:
          hp=40;
          break;
        case 18:
          hp=25;
          break;
        case 19:
          hp=134;
          break;
        case 20:
          hp=28;
          break;
        case 21:
          hp=45;
          break;
        case 22:
          hp=12;
          break;
        case 23:
          hp=50;
          break;
        case 24:
          hp=90;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
          break;
      }
      hp+=hp1(lv);
      break;
    case 2:
      switch(sp%100){
        case 1:
          hp=100;
          break;
        case 2:
          hp=48;
          break;
        case 3:
          hp=48;
          break;
        case 4:
          hp=35;
          break;
        case 5:
          hp=78;
          break;
        case 6:
          hp=55;
          break;
        case 7:
          hp=150;
          break;
        case 8:
          hp=50;
          break;
        case 9:
          hp=60;
          break;
        case 10:
          hp=80;
          break;
        case 11:
          hp=40;
          break;
        case 12:
          hp=42;
          break;
        case 13:
          hp=23;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      hp+=hp2(lv);
      break;
    case 3:
      switch(sp%100){
        case 1:
          hp=30;
          break;
        case 2:
          hp=31;
          break;
        case 3:
          hp=41;
          break;
        case 4:
          hp=30;
          break;
        case 5:
          hp=32;
          break;
        case 6:
          hp=26;
          break;
        case 7:
          hp=17;
          break;
        case 8:
          hp=36;
          break;
        case 9:
          hp=33;
          break;
        case 10:
          hp=50;
          break;
        case 11:
          hp=47;
          break;
        case 12:
          hp=33;
          break;
        case 13:
          hp=21;
          break;
        case 14:
          hp=15;
          break;
        case 15:
          hp=35;
          break;
        case 16:
          hp=28;
          break;
        case 17:
          hp=19;
          break;
        case 18:
          hp=34;
          break;
        case 19:
          hp=31;
          break;
        case 20:
          hp=6;
          break;
        case 21:
          hp=25;
          break;
        case 22:
          hp=125;
          break;
        case 23:
          hp=23;
          break;
        case 24:
          hp=37;
          break;
        case 25:
          hp=50;
          break;
        case 26:
          hp=20;
          break;
        case 27:
          hp=35;
          break;
        case 28:
          hp=21;
          break;
        case 29:
          hp=35;
          break;
        case 30:
          hp=21;
          break;
        case 31:
          hp=44;
          break;
        case 32:
          hp=46;
          break;
        case 33:
          hp=26;
          break;
        case 34:
          hp=49;
          break;
        case 35:
          hp=60;
          break;
        case 36:
          hp=35;
          break;
        case 37:
          hp=90;
          break;
        case 38:
          hp=41;
          break;
        case 39:
          hp=31;
          break;
        case 40:
          hp=40;
          break;
        case 41:
          hp=6;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      hp+=hp3(lv);
      break;
    case 4:
      switch(sp%100){
        case 1:
          hp=60;
          break;
        case 2:
          hp=55;
          break;
        case 3:
          hp=22;
          break;
        case 4:
          hp=80;
          break;
        case 5:
          hp=50;
          break;
        case 6:
          hp=70;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      hp+=hp4(lv);
      break;
    case 5:
      switch(sp%100){
        case 1:
          hp=48;
          break;
        case 2:
          hp=42;
          break;
        case 3:
          hp=150;
          break;
        case 4:
          hp=39;
          break;
        case 5:
          hp=44;
          break;
        case 6:
          hp=38;
          break;
        case 7:
          hp=75;
          break;
        case 8:
          hp=150;
          break;
        case 9:
          hp=45;
          break;
        case 10:
          hp=120;
          break;
        case 11:
          hp=30;
          break;
        case 12:
          hp=20;
          break;
        case 13:
          hp=70;
          break;
        case 14:
          hp=50;
          break;
        case 15:
          hp=97;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      hp+=hp5(lv);
      break;
    case 6:
      switch(sp%100){
        case 1:
          hp=17;
          break;
        case 2:
          hp=70;
          break;
        case 3:
          hp=100;
          break;
        case 4:
          hp=15;
          break;
        case 5:
          hp=55;
          break;
        case 6:
          hp=38;
          break;
        case 7:
          hp=22;
          break;
        case 8:
          hp=200;
          break;
        case 9:
          hp=39;
          break;
        case 10:
          hp=18;
          break;
        case 11:
          hp=55;
          break;
        case 12:
          hp=135;
          break;
        case 13:
          hp=60;
          break;
        case 14:
          hp=40;
          break;
        case 15:
          hp=37;
          break;
        case 16:
          hp=34;
          break;
        case 17:
          hp=35;
          break;
        case 18:
          hp=35;
          break;
        case 19:
          hp=35;
          break;
        case 20:
          hp=45;
          break;
        case 21:
          hp=105;
          break;
        case 22:
          hp=31;
          break;
        case 23:
          hp=35;
          break;
        case 24:
          hp=48;
          break;
        case 25:
          hp=65;
          break;
        case 26:
          hp=38;
          break;
        case 27:
          hp=45;
          break;
        case 28:
          hp=55;
          break;
        case 29:
          hp=105;
          break;
        case 30:
          hp=41;
          break;
        case 31:
          hp=28;
          break;
        case 32:
          hp=128;
          break;
        case 33:
          hp=120;
          break;
        case 34:
          hp=35;
          break;
        case 35:
          hp=120;
          break;
        case 36:
          hp=50;
          break;
        case 37:
          hp=50;
          break;
        case 38:
          hp=55;
          break;
        case 39:
          hp=100;
          break;
        case 40:
          hp=135;
          break;
        case 41:
          hp=17;
          break;
        case 42:
          hp=55;
          break;
        case 43:
          hp=35;
          break;
        case 44:
          hp=35;
          break;
        case 45:
          hp=33;
          break;
        case 46:
          hp=20;
          break;
        case 47:
          hp=130;
          break;
        case 48:
          hp=20;
          break;
        case 49:
          hp=35;
          break;
        case 50:
          hp=110;
          break;
        case 51:
          hp=51;
          break;
        case 52:
          hp=35;
          break;
        case 53:
          hp=75;
          break;
        case 54:
          hp=60;
          break;
        case 55:
          hp=130;
          break;
        case 56:
          hp=90;
          break;
        case 57:
          hp=51;
          break;
        case 58:
          hp=34;
          break;
        case 59:
          hp=95;
          break;
        case 60:
          hp=25;
          break;
        case 61:
          hp=140;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      hp+=hp6(lv);
      break;
    case 7:
      switch(sp%100){
        case 1:
          hp=130;
          break;
        case 2:
          hp=145;
          break;
        case 3:
          hp=100;
          break;
        case 4:
          hp=135;
          break;
        case 5:
          hp=132;
          break;
        case 6:
          hp=131;
          break;
        case 7:
          hp=150;
          break;
        case 8:
          hp=133;
          break;
        case 9:
          hp=131;
          break;
        case 10:
          hp=135;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      hp+=hp7(lv);
      break;
    case 8:
      switch(sp%100){
        case 1:
          hp=5;
          break;
        case 2:
          hp=10;
          break;
        case 3:
          hp=6;
          break;
        case 4:
          hp=5;
          break;
        case 5:
          hp=10;
          break;
        case 6:
          hp=5;
          break;
        case 7:
          hp=100;
          break;
        case 8:
          hp=4;
          break;
        case 9:
          hp=150;
          break;
        case 10:
          hp=6;
          break;
        case 11:
          hp=26;
          break;
        case 12:
          hp=200;
          break;
        case 13:
          hp=10;
          break;
        case 14:
          hp=50;
          break;
        case 15:
          hp=6;
          break;
        case 16:
          hp=35;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      hp+=hp8(lv);
      break;
  }
  return hp;
}

int GetAT(int sp, int lv){  int at;
  switch(sp/100){
    case 1:
      switch(sp%100){
        case 1:
          at=6;
          break;
        case 2:
          at=20;
          break;
        case 3:
          at=30;
          break;
        case 4:
          at=19;
          break;
        case 5:
          at=21;
          break;
        case 6:
          at=15;
          break;
        case 7:
          at=35;
          break;
        case 8:
          at=2;
          break;
        case 9:
          at=3;
          break;
        case 10:
          at=50;
          break;
        case 11:
          at=16;
          break;
        case 12:
          at=16;
          break;
        case 13:
          at=45;
          break;
        case 14:
          at=5;
          break;
        case 15:
          at=20;
          break;
        case 16:
          at=16;
          break;
        case 17:
          at=11;
          break;
        case 18:
          at=14;
          break;
        case 19:
          at=52;
          break;
        case 20:
          at=10;
          break;
        case 21:
          at=19;
          break;
        case 22:
          at=7;
          break;
        case 23:
          at=15;
          break;
        case 24:
          at=44;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      at+=at1(lv);
      break;
    case 2:
      switch(sp%100){
        case 1:
          at=30;
          break;
        case 2:
          at=30;
          break;
        case 3:
          at=16;
          break;
        case 4:
          at=15;
          break;
        case 5:
          at=32;
          break;
        case 6:
          at=17;
          break;
        case 7:
          at=45;
          break;
        case 8:
          at=23;
          break;
        case 9:
          at=31;
          break;
        case 10:
          at=45;
          break;
        case 11:
          at=25;
          break;
        case 12:
          at=21;
          break;
        case 13:
          at=18;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      at+=at2(lv);
      break;
    case 3:
      switch(sp%100){
        case 1:
          at=18;
          break;
        case 2:
          at=19;
          break;
        case 3:
          at=11;
          break;
        case 4:
          at=20;
          break;
        case 5:
          at=15;
          break;
        case 6:
          at=8;
          break;
        case 7:
          at=8;
          break;
        case 8:
          at=10;
          break;
        case 9:
          at=17;
          break;
        case 10:
          at=16;
          break;
        case 11:
          at=23;
          break;
        case 12:
          at=17;
          break;
        case 13:
          at=9;
          break;
        case 14:
          at=11;
          break;
        case 15:
          at=17;
          break;
        case 16:
          at=14;
          break;
        case 17:
          at=12;
          break;
        case 18:
          at=14;
          break;
        case 19:
          at=13;
          break;
        case 20:
          at=10;
          break;
        case 21:
          at=11;
          break;
        case 22:
          at=40;
          break;
        case 23:
          at=13;
          break;
        case 24:
          at=19;
          break;
        case 25:
          at=25;
          break;
        case 26:
          at=10;
          break;
        case 27:
          at=20;
          break;
        case 28:
          at=9;
          break;
        case 29:
          at=16;
          break;
        case 30:
          at=10;
          break;
        case 31:
          at=10;
          break;
        case 32:
          at=19;
          break;
        case 33:
          at=15;
          break;
        case 34:
          at=20;
          break;
        case 35:
          at=27;
          break;
        case 36:
          at=14;
          break;
        case 37:
          at=19;
          break;
        case 38:
          at=13;
          break;
        case 39:
          at=20;
          break;
        case 40:
          at=11;
          break;
        case 41:
          at=10;
          break;
      }
      at+=at3(lv);
      break;
    case 4:
      switch(sp%100){
        case 1:
          at=26;
          break;
        case 2:
          at=22;
          break;
        case 3:
          at=10;
          break;
        case 4:
          at=28;
          break;
        case 5:
          at=20;
          break;
        case 6:
          at=21;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      at+=at4(lv);
      break;
    case 5:
      switch(sp%100){
        case 1:
          at=22;
          break;
        case 2:
          at=20;
          break;
        case 3:
          at=50;
          break;
        case 4:
          at=20;
          break;
        case 5:
          at=22;
          break;
        case 6:
          at=9;
          break;
        case 7:
          at=25;
          break;
        case 8:
          at=50;
          break;
        case 9:
          at=21;
          break;
        case 10:
          at=40;
          break;
        case 11:
          at=12;
          break;
        case 12:
          at=40;
          break;
        case 13:
          at=30;
          break;
        case 14:
          at=10;
          break;
        case 15:
          at=31;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      at+=at5(lv);
      break;
    case 6:
      switch(sp%100){
        case 1:
          at=13;
          break;
        case 2:
          at=15;
          break;
        case 3:
          at=45;
          break;
        case 4:
          at=10;
          break;
        case 5:
          at=22;
          break;
        case 6:
          at=20;
          break;
        case 7:
          at=12;
          break;
        case 8:
          at=180;
          break;
        case 9:
          at=8;
          break;
        case 10:
          at=9;
          break;
        case 11:
          at=25;
          break;
        case 12:
          at=55;
          break;
        case 13:
          at=20;
          break;
        case 14:
          at=8;
          break;
        case 15:
          at=18;
          break;
        case 16:
          at=9;
          break;
        case 17:
          at=10;
          break;
        case 18:
          at=11;
          break;
        case 19:
          at=10;
          break;
        case 20:
          at=21;
          break;
        case 21:
          at=45;
          break;
        case 22:
          at=10;
          break;
        case 23:
          at=20;
          break;
        case 24:
          at=19;
          break;
        case 25:
          at=20;
          break;
        case 26:
          at=22;
          break;
        case 27:
          at=10;
          break;
        case 28:
          at=23;
          break;
        case 29:
          at=34;
          break;
        case 30:
          at=17;
          break;
        case 31:
          at=18;
          break;
        case 32:
          at=65;
          break;
        case 33:
          at=25;
          break;
        case 34:
          at=17;
          break;
        case 35:
          at=39;
          break;
        case 36:
          at=15;
          break;
        case 37:
          at=15;
          break;
        case 38:
          at=18;
          break;
        case 39:
          at=15;
          break;
        case 40:
          at=30;
          break;
        case 41:
          at=9;
          break;
        case 42:
          at=8;
          break;
        case 43:
          at=10;
          break;
        case 44:
          at=11;
          break;
        case 45:
          at=10;
          break;
        case 46:
          at=8;
          break;
        case 47:
          at=40;
          break;
        case 48:
          at=13;
          break;
        case 49:
          at=20;
          break;
        case 50:
          at=40;
          break;
        case 51:
          at=22;
          break;
        case 52:
          at=14;
          break;
        case 53:
          at=25;
          break;
        case 54:
          at=23;
          break;
        case 55:
          at=40;
          break;
        case 56:
          at=29;
          break;
        case 57:
          at=20;
          break;
        case 58:
          at=12;
          break;
        case 59:
          at=28;
          break;
        case 60:
          at=11;
          break;
        case 61:
          at=51;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      at+=at6(lv);
      break;
    case 7:
      switch(sp%100){
        case 1:
          at=60;
          break;
        case 2:
          at=60;
          break;
        case 3:
          at=50;
          break;
        case 4:
          at=60;
          break;
        case 5:
          at=50;
          break;
        case 6:
          at=51;
          break;
        case 7:
          at=80;
          break;
        case 8:
          at=51;
          break;
        case 9:
          at=66;
          break;
        case 10:
          at=65;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      at+=at7(lv);
      break;
    case 8:
      switch(sp%100){
        case 1:
          at=20;
          break;
        case 2:
          at=1;
          break;
        case 3:
          at=12;
          break;
        case 4:
          at=13;
          break;
        case 5:
          at=1;
          break;
        case 6:
          at=10;
          break;
        case 7:
          at=35;
          break;
        case 8:
          at=7;
          break;
        case 9:
          at=45;
          break;
        case 10:
          at=40;
          break;
        case 11:
          at=17;
          break;
        case 12:
          at=55;
          break;
        case 13:
          at=6;
          break;
        case 14:
          at=10;
          break;
        case 15:
          at=10;
          break;
        case 16:
          at=0;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      at+=at8(lv);
      break;
  }
  return at;
}

int GetDF(int sp, int lv){
  int df;
  switch(sp/100){
    case 1:
      switch(sp%100){
        case 1:
          df=5;
          break;
        case 2:
          df=10;
          break;
        case 3:
          df=29;
          break;
        case 4:
          df=18;
          break;
        case 5:
          df=20;
          break;
        case 6:
          df=15;
          break;
        case 7:
          df=35;
          break;
        case 8:
          df=2;
          break;
        case 9:
          df=3;
          break;
        case 10:
          df=50;
          break;
        case 11:
          df=15;
          break;
        case 12:
          df=11;
          break;
        case 13:
          df=35;
          break;
        case 14:
          df=2;
          break;
        case 15:
          df=14;
          break;
        case 16:
          df=24;
          break;
        case 17:
          df=10;
          break;
        case 18:
          df=17;
          break;
        case 19:
          df=52;
          break;
        case 20:
          df=9;
          break;
        case 21:
          df=19;
          break;
        case 22:
          df=5;
          break;
        case 23:
          df=16;
          break;
        case 24:
          df=30;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      df+=df1(lv);
      break;
    case 2:
      switch(sp%100){
        case 1:
          df=35;
          break;
        case 2:
          df=20;
          break;
        case 3:
          df=18;
          break;
        case 4:
          df=13;
          break;
        case 5:
          df=31;
          break;
        case 6:
          df=10;
          break;
        case 7:
          df=45;
          break;
        case 8:
          df=23;
          break;
        case 9:
          df=27;
          break;
        case 10:
          df=30;
          break;
        case 11:
          df=13;
          break;
        case 12:
          df=13;
          break;
        case 13:
          df=5;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      df+=df2(lv);
      break;
    case 3:
      switch(sp%100){
        case 1:
          df=19;
          break;
        case 2:
          df=14;
          break;
        case 3:
          df=14;
          break;
        case 4:
          df=19;
          break;
        case 5:
          df=18;
          break;
        case 6:
          df=11;
          break;
        case 7:
          df=7;
          break;
        case 8:
          df=8;
          break;
        case 9:
          df=15;
          break;
        case 10:
          df=18;
          break;
        case 11:
          df=19;
          break;
        case 12:
          df=16;
          break;
        case 13:
          df=10;
          break;
        case 14:
          df=10;
          break;
        case 15:
          df=18;
          break;
        case 16:
          df=18;
          break;
        case 17:
          df=13;
          break;
        case 18:
          df=12;
          break;
        case 19:
          df=15;
          break;
        case 20:
          df=3;
          break;
        case 21:
          df=11;
          break;
        case 22:
          df=35;
          break;
        case 23:
          df=14;
          break;
        case 24:
          df=18;
          break;
        case 25:
          df=50;
          break;
        case 26:
          df=6;
          break;
        case 27:
          df=10;
          break;
        case 28:
          df=7;
          break;
        case 29:
          df=10;
          break;
        case 30:
          df=9;
          break;
        case 31:
          df=15;
          break;
        case 32:
          df=21;
          break;
        case 33:
          df=13;
          break;
        case 34:
          df=24;
          break;
        case 35:
          df=20;
          break;
        case 36:
          df=9;
          break;
        case 37:
          df=25;
          break;
        case 38:
          df=18;
          break;
        case 39:
          df=35;
          break;
        case 40:
          df=12;
          break;
        case 41:
          df=3;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      df+=df3(lv);
      break;
    case 4:
      switch(sp%100){
        case 1:
          df=27;
          break;
        case 2:
          df=22;
          break;
        case 3:
          df=10;
          break;
        case 4:
          df=29;
          break;
        case 5:
          df=20;
          break;
        case 6:
          df=27;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      df+=df4(lv);
      break;
    case 5:
      switch(sp%100){
        case 1:
          df=15;
          break;
        case 2:
          df=22;
          break;
        case 3:
          df=40;
          break;
        case 4:
          df=18;
          break;
        case 5:
          df=17;
          break;
        case 6:
          df=10;
          break;
        case 7:
          df=29;
          break;
        case 8:
          df=55;
          break;
        case 9:
          df=19;
          break;
        case 10:
          df=36;
          break;
        case 11:
          df=12;
          break;
        case 12:
          df=10;
          break;
        case 13:
          df=20;
          break;
        case 14:
          df=15;
          break;
        case 15:
          df=36;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      df+=df5(lv);
      break;
    case 6:
      switch(sp%100){
        case 1:
          df=20;
          break;
        case 2:
          df=5;
          break;
        case 3:
          df=45;
          break;
        case 4:
          df=8;
          break;
        case 5:
          df=22;
          break;
        case 6:
          df=12;
          break;
        case 7:
          df=12;
          break;
        case 8:
          df=150;
          break;
        case 9:
          df=10;
          break;
        case 10:
          df=8;
          break;
        case 11:
          df=26;
          break;
        case 12:
          df=52;
          break;
        case 13:
          df=25;
          break;
        case 14:
          df=11;
          break;
        case 15:
          df=16;
          break;
        case 16:
          df=14;
          break;
        case 17:
          df=15;
          break;
        case 18:
          df=14;
          break;
        case 19:
          df=16;
          break;
        case 20:
          df=23;
          break;
        case 21:
          df=47;
          break;
        case 22:
          df=12;
          break;
        case 23:
          df=17;
          break;
        case 24:
          df=14;
          break;
        case 25:
          df=20;
          break;
        case 26:
          df=20;
          break;
        case 27:
          df=15;
          break;
        case 28:
          df=18;
          break;
        case 29:
          df=30;
          break;
        case 30:
          df=17;
          break;
        case 31:
          df=13;
          break;
        case 32:
          df=53;
          break;
        case 33:
          df=35;
          break;
        case 34:
          df=19;
          break;
        case 35:
          df=50;
          break;
        case 36:
          df=18;
          break;
        case 37:
          df=15;
          break;
        case 38:
          df=18;
          break;
        case 39:
          df=5;
          break;
        case 40:
          df=45;
          break;
        case 41:
          df=13;
          break;
        case 42:
          df=5;
          break;
        case 43:
          df=15;
          break;
        case 44:
          df=14;
          break;
        case 45:
          df=14;
          break;
        case 46:
          df=10;
          break;
        case 47:
          df=40;
          break;
        case 48:
          df=14;
          break;
        case 49:
          df=10;
          break;
        case 50:
          df=40;
          break;
        case 51:
          df=21;
          break;
        case 52:
          df=13;
          break;
        case 53:
          df=28;
          break;
        case 54:
          df=17;
          break;
        case 55:
          df=45;
          break;
        case 56:
          df=27;
          break;
        case 57:
          df=22;
          break;
        case 58:
          df=15;
          break;
        case 59:
          df=26;
          break;
        case 60:
          df=10;
          break;
        case 61:
          df=45;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      df+=df6(lv);
      break;
    case 7:
      switch(sp%100){
        case 1:
          df=48;
          break;
        case 2:
          df=55;
          break;
        case 3:
          df=50;
          break;
        case 4:
          df=55;
          break;
        case 5:
          df=50;
          break;
        case 6:
          df=55;
          break;
        case 7:
          df=80;
          break;
        case 8:
          df=51;
          break;
        case 9:
          df=53;
          break;
        case 10:
          df=55;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      df+=df7(lv);
      break;
    case 8:
      switch(sp%100){
        case 1:
          df=1;
          break;
        case 2:
          df=1;
          break;
        case 3:
          df=4;
          break;
        case 4:
          df=1;
          break;
        case 5:
          df=100;
          break;
        case 6:
          df=200;
          break;
        case 7:
          df=15;
          break;
        case 8:
          df=4;
          break;
        case 9:
          df=20;
          break;
        case 10:
          df=4;
          break;
        case 11:
          df=15;
          break;
        case 12:
          df=29;
          break;
        case 13:
          df=5;
          break;
        case 14:
          df=100;
          break;
        case 15:
          df=100;
          break;
        case 16:
          df=5;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      df+=df8(lv);
      break;
  }
  return df;
}

int GetMXLV(int sp){
  int mxlv;
  switch(sp/100){
    case 1:
      switch(sp%100){
        case 1:
          mxlv=5;
          break;
        case 2:
          mxlv=9;
          break;
        case 3:
          mxlv=9;
          break;
        case 4:
          mxlv=99;
          break;
        case 5:
          mxlv=9;
          break;
        case 6:
          mxlv=9;
          break;
        case 7:
          mxlv=9;
          break;
        case 8:
          mxlv=99;
          break;
        case 9:
          mxlv=99;
          break;
        case 10:
          mxlv=9;
          break;
        case 11:
          mxlv=3;
          break;
        case 12:
          mxlv=99;
          break;
        case 13:
          mxlv=9;
          break;
        case 14:
          mxlv=99;
          break;
        case 15:
          mxlv=99;
          break;
        case 16:
          mxlv=99;
          break;
        case 17:
          mxlv=9;
          break;
        case 18:
          mxlv=99;
          break;
        case 19:
          mxlv=99;
          break;
        case 20:
          mxlv=99;
          break;
        case 21:
          mxlv=99;
          break;
        case 22:
          mxlv=99;
          break;
        case 23:
          mxlv=9;
          break;
        case 24:
          mxlv=99;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      break;
    case 2:
      switch(sp%100){
        case 1:
          mxlv=99;
          break;
        case 2:
          mxlv=99;
          break;
        case 3:
          mxlv=99;
          break;
        case 4:
          mxlv=99;
          break;
        case 5:
          mxlv=99;
          break;
        case 6:
          mxlv=99;
          break;
        case 7:
          mxlv=99;
          break;
        case 8:
          mxlv=99;
          break;
        case 9:
          mxlv=99;
          break;
        case 10:
          mxlv=99;
          break;
        case 11:
          mxlv=99;
          break;
        case 12:
          mxlv=99;
          break;
        case 13:
          mxlv=99;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      break;
    case 3:
      switch(sp%100){
        case 1:
          mxlv=99;
          break;
        case 2:
          mxlv=99;
          break;
        case 3:
          mxlv=99;
          break;
        case 4:
          mxlv=99;
          break;
        case 5:
          mxlv=99;
          break;
        case 6:
          mxlv=99;
          break;
        case 7:
          mxlv=99;
          break;
        case 8:
          mxlv=99;
          break;
        case 9:
          mxlv=99;
          break;
        case 10:
          mxlv=99;
          break;
        case 11:
          mxlv=99;
          break;
        case 12:
          mxlv=99;
          break;
        case 13:
          mxlv=99;
          break;
        case 14:
          mxlv=99;
          break;
        case 15:
          mxlv=99;
          break;
        case 16:
          mxlv=99;
          break;
        case 17:
          mxlv=99;
          break;
        case 18:
          mxlv=99;
          break;
        case 19:
          mxlv=99;
          break;
        case 20:
          mxlv=99;
          break;
        case 21:
          mxlv=99;
          break;
        case 22:
          mxlv=99;
          break;
        case 23:
          mxlv=99;
          break;
        case 24:
          mxlv=99;
          break;
        case 25:
          mxlv=99;
          break;
        case 26:
          mxlv=99;
          break;
        case 27:
          mxlv=99;
          break;
        case 28:
          mxlv=5;
          break;
        case 29:
          mxlv=99;
          break;
        case 30:
          mxlv=99;
          break;
        case 31:
          mxlv=99;
          break;
        case 32:
          mxlv=99;
          break;
        case 33:
          mxlv=99;
          break;
        case 34:
          mxlv=99;
          break;
        case 35:
          mxlv=99;
          break;
        case 36:
          mxlv=99;
          break;
        case 37:
          mxlv=99;
          break;
        case 38:
          mxlv=99;
          break;
        case 39:
          mxlv=99;
          break;
        case 40:
          mxlv=99;
          break;
        case 41:
          mxlv=99;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      break;
    case 4:
      switch(sp%100){
        case 1:
          mxlv=99;
          break;
        case 2:
          mxlv=99;
          break;
        case 3:
          mxlv=99;
          break;
        case 4:
          mxlv=99;
          break;
        case 5:
          mxlv=99;
          break;
        case 6:
          mxlv=99;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      break;
    case 5:
      switch(sp%100){
        case 1:
          mxlv=99;
          break;
        case 2:
          mxlv=99;
          break;
        case 3:
          mxlv=99;
          break;
        case 4:
          mxlv=99;
          break;
        case 5:
          mxlv=99;
          break;
        case 6:
          mxlv=99;
          break;
        case 7:
          mxlv=99;
          break;
        case 8:
          mxlv=99;
          break;
        case 9:
          mxlv=99;
          break;
        case 10:
          mxlv=99;
          break;
        case 11:
          mxlv=99;
          break;
        case 12:
          mxlv=99;
          break;
        case 13:
          mxlv=99;
          break;
        case 14:
          mxlv=99;
          break;
        case 15:
          mxlv=99;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      break;
    case 6:
      switch(sp%100){
        case 1:
          mxlv=99;
          break;
        case 2:
          mxlv=99;
          break;
        case 3:
          mxlv=99;
          break;
        case 4:
          mxlv=5;
          break;
        case 5:
          mxlv=99;
          break;
        case 6:
          mxlv=99;
          break;
        case 7:
          mxlv=5;
          break;
        case 8:
          mxlv=99;
          break;
        case 9:
          mxlv=99;
          break;
        case 10:
          mxlv=99;
          break;
        case 11:
          mxlv=99;
          break;
        case 12:
          mxlv=99;
          break;
        case 13:
          mxlv=99;
          break;
        case 14:
          mxlv=99;
          break;
        case 15:
          mxlv=99;
          break;
        case 16:
          mxlv=99;
          break;
        case 17:
          mxlv=99;
          break;
        case 18:
          mxlv=99;
          break;
        case 19:
          mxlv=99;
          break;
        case 20:
          mxlv=99;
          break;
        case 21:
          mxlv=99;
          break;
        case 22:
          mxlv=99;
          break;
        case 23:
          mxlv=99;
          break;
        case 24:
          mxlv=99;
          break;
        case 25:
          mxlv=99;
          break;
        case 26:
          mxlv=99;
          break;
        case 27:
          mxlv=99;
          break;
        case 28:
          mxlv=99;
          break;
        case 29:
          mxlv=99;
          break;
        case 30:
          mxlv=99;
          break;
        case 31:
          mxlv=99;
          break;
        case 32:
          mxlv=99;
          break;
        case 33:
          mxlv=99;
          break;
        case 34:
          mxlv=99;
          break;
        case 35:
          mxlv=99;
          break;
        case 36:
          mxlv=99;
          break;
        case 37:
          mxlv=99;
          break;
        case 38:
          mxlv=99;
          break;
        case 39:
          mxlv=99;
          break;
        case 40:
          mxlv=99;
          break;
        case 41:
          mxlv=99;
          break;
        case 42:
          mxlv=99;
          break;
        case 43:
          mxlv=99;
          break;
        case 44:
          mxlv=99;
          break;
        case 45:
          mxlv=99;
          break;
        case 46:
          mxlv=99;
          break;
        case 47:
          mxlv=99;
          break;
        case 48:
          mxlv=99;
          break;
        case 49:
          mxlv=99;
          break;
        case 50:
          mxlv=99;
          break;
        case 51:
          mxlv=99;
          break;
        case 52:
          mxlv=99;
          break;
        case 53:
          mxlv=99;
          break;
        case 54:
          mxlv=99;
          break;
        case 55:
          mxlv=99;
          break;
        case 56:
          mxlv=99;
          break;
        case 57:
          mxlv=99;
          break;
        case 58:
          mxlv=99;
          break;
        case 59:
          mxlv=99;
          break;
        case 60:
          mxlv=99;
          break;
        case 61:
          mxlv=99;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      break;
    case 7:
      switch(sp%100){
        case 1:
          mxlv=10;
          break;
        case 2:
          mxlv=10;
          break;
        case 3:
          mxlv=10;
          break;
        case 4:
          mxlv=10;
          break;
        case 5:
          mxlv=10;
          break;
        case 6:
          mxlv=99;
          break;
        case 7:
          mxlv=99;
          break;
        case 8:
          mxlv=10;
          break;
        case 9:
          mxlv=99;
          break;
        case 10:
          mxlv=10;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      break;
    case 8:
      switch(sp%100){
        case 1:
          mxlv=9;
          break;
        case 2:
          mxlv=99;
          break;
        case 3:
          mxlv=9;
          break;
        case 4:
          mxlv=9;
          break;
        case 5:
          mxlv=99;
          break;
        case 6:
          mxlv=99;
          break;
        case 7:
          mxlv=99;
          break;
        case 8:
          mxlv=9;
          break;
        case 9:
          mxlv=99;
          break;
        case 10:
          mxlv=9;
          break;
        case 11:
          mxlv=99;
          break;
        case 12:
          mxlv=99;
          break;
        case 13:
          mxlv=99;
          break;
        case 14:
          mxlv=99;
          break;
        case 15:
          mxlv=99;
          break;
        case 16:
          mxlv=99;
          break;
        default:
          std::cout << "モンスターの種類識別番号が不正です" << std::endl;
          exit(1);
      }
      break;
  }
  return mxlv;
}






int hp1(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
  }
  int hp;
  switch(lv){
    case 1:
      hp=0;
      break;
    case 2:
      hp=8;
      break;
    case 3:
      hp=15;
      break;
    case 4:
      hp=21;
      break;
    case 5:
      hp=26;
      break;
    case 6:
      hp=30;
      break;
    case 7:
      hp=33;
      break;
    case 8:
      hp=36;
      break;
    case 9:
      hp=39;
      break;
    case 10:
      hp=42;
      break;
    case 11:
      hp=45;
      break;
    case 12:
      hp=48;
      break;
    case 13:
      hp=51;
      break;
    case 14:
      hp=54;
      break;
    case 15:
      hp=57;
      break;
    case 16:
      hp=59;
      break;
    case 17:
      hp=61;
      break;
    case 18:
      hp=63;
      break;
    case 19:
      hp=65;
      break;
    case 20:
      hp=67;
      break;
    case 21:
      hp=68;
      break;
    case 22:
      hp=69;
      break;
    case 23:
      hp=70;
      break;
    case 24:
      hp=71;
      break;
    case 25:
      hp=72;
      break;
    case 26:
      hp=73;
      break;
    case 27:
      hp=74;
      break;
    case 28:
      hp=75;
      break;
    case 29:
      hp=76;
      break;
    case 30:
      hp=77;
      break;
    case 31:
      hp=78;
      break;
    case 32:
      hp=79;
      break;
    case 33:
      hp=80;
      break;
    case 34:
      hp=81;
      break;
    case 35:
      hp=82;
      break;
    case 36:
      hp=83;
      break;
    case 37:
      hp=84;
      break;
    case 38:
      hp=85;
      break;
    case 39:
      hp=86;
      break;
    case 40:
      hp=87;
      break;
    case 41:
      hp=88;
      break;
    case 42:
      hp=89;
      break;
    case 43:
      hp=90;
      break;
    case 44:
      hp=91;
      break;
    case 45:
      hp=92;
      break;
    case 46:
      hp=93;
      break;
    case 47:
      hp=94;
      break;
    case 48:
      hp=95;
      break;
    case 49:
      hp=96;
      break;
    case 50:
      hp=97;
      break;
    case 51:
      hp=98;
      break;
    case 52:
      hp=99;
      break;
    case 53:
      hp=100;
      break;
    case 54:
      hp=101;
      break;
    case 55:
      hp=102;
      break;
    case 56:
      hp=103;
      break;
    case 57:
      hp=104;
      break;
    case 58:
      hp=105;
      break;
    case 59:
      hp=106;
      break;
    case 60:
      hp=107;
      break;
    case 61:
      hp=108;
      break;
    case 62:
      hp=109;
      break;
    case 63:
      hp=110;
      break;
    case 64:
      hp=111;
      break;
    case 65:
      hp=112;
      break;
    case 66:
      hp=113;
      break;
    case 67:
      hp=114;
      break;
    case 68:
      hp=115;
      break;
    case 69:
      hp=116;
      break;
    case 70:
      hp=117;
      break;
    case 71:
      hp=118;
      break;
    case 72:
      hp=119;
      break;
    case 73:
      hp=120;
      break;
    case 74:
      hp=121;
      break;
    case 75:
      hp=122;
      break;
    case 76:
      hp=123;
      break;
    case 77:
      hp=124;
      break;
    case 78:
      hp=125;
      break;
    case 79:
      hp=126;
      break;
    case 80:
      hp=127;
      break;
    case 81:
      hp=128;
      break;
    case 82:
      hp=129;
      break;
    case 83:
      hp=130;
      break;
    case 84:
      hp=131;
      break;
    case 85:
      hp=132;
      break;
    case 86:
      hp=133;
      break;
    case 87:
      hp=134;
      break;
    case 88:
      hp=135;
      break;
    case 89:
      hp=136;
      break;
    case 90:
      hp=137;
      break;
    case 91:
      hp=138;
      break;
    case 92:
      hp=139;
      break;
    case 93:
      hp=140;
      break;
    case 94:
      hp=141;
      break;
    case 95:
      hp=142;
      break;
    case 96:
      hp=143;
      break;
    case 97:
      hp=144;
      break;
    case 98:
      hp=145;
      break;
    case 99:
      hp=146;
      break;
  }
  return hp;
}

int at1(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int at;
  switch(lv){
    case 1:
      at=0;
      break;
    case 2:
      at=9;
      break;
    case 3:
      at=14;
      break;
    case 4:
      at=18;
      break;
    case 5:
      at=21;
      break;
    case 6:
      at=24;
      break;
    case 7:
      at=27;
      break;
    case 8:
      at=30;
      break;
    case 9:
      at=33;
      break;
    case 10:
      at=36;
      break;
    case 11:
      at=38;
      break;
    case 12:
      at=40;
      break;
    case 13:
      at=42;
      break;
    case 14:
      at=44;
      break;
    case 15:
      at=46;
      break;
    case 16:
      at=47;
      break;
    case 17:
      at=48;
      break;
    case 18:
      at=49;
      break;
    case 19:
      at=50;
      break;
    case 20:
      at=51;
      break;
    case 21:
      at=52;
      break;
    case 22:
      at=53;
      break;
    case 23:
      at=54;
      break;
    case 24:
      at=55;
      break;
    case 25:
      at=56;
      break;
    case 26:
      at=57;
      break;
    case 27:
      at=58;
      break;
    case 28:
      at=59;
      break;
    case 29:
      at=60;
      break;
    case 30:
      at=61;
      break;
    case 31:
      at=62;
      break;
    case 32:
      at=63;
      break;
    case 33:
      at=64;
      break;
    case 34:
      at=65;
      break;
    case 35:
      at=66;
      break;
    case 36:
      at=67;
      break;
    case 37:
      at=68;
      break;
    case 38:
      at=69;
      break;
    case 39:
      at=70;
      break;
    case 40:
      at=71;
      break;
    case 41:
      at=71;
      break;
    case 42:
      at=71;
      break;
    case 43:
      at=72;
      break;
    case 44:
      at=72;
      break;
    case 45:
      at=73;
      break;
    case 46:
      at=73;
      break;
    case 47:
      at=74;
      break;
    case 48:
      at=74;
      break;
    case 49:
      at=75;
      break;
    case 50:
      at=76;
      break;
    case 51:
      at=76;
      break;
    case 52:
      at=76;
      break;
    case 53:
      at=76;
      break;
    case 54:
      at=76;
      break;
    case 55:
      at=76;
      break;
    case 56:
      at=76;
      break;
    case 57:
      at=76;
      break;
    case 58:
      at=76;
      break;
    case 59:
      at=76;
      break;
    case 60:
      at=76;
      break;
    case 61:
      at=76;
      break;
    case 62:
      at=76;
      break;
    case 63:
      at=76;
      break;
    case 64:
      at=76;
      break;
    case 65:
      at=76;
      break;
    case 66:
      at=76;
      break;
    case 67:
      at=76;
      break;
    case 68:
      at=76;
      break;
    case 69:
      at=76;
      break;
    case 70:
      at=76;
      break;
    case 71:
      at=76;
      break;
    case 72:
      at=76;
      break;
    case 73:
      at=76;
      break;
    case 74:
      at=76;
      break;
    case 75:
      at=76;
      break;
    case 76:
      at=76;
      break;
    case 77:
      at=76;
      break;
    case 78:
      at=76;
      break;
    case 79:
      at=76;
      break;
    case 80:
      at=76;
      break;
    case 81:
      at=76;
      break;
    case 82:
      at=76;
      break;
    case 83:
      at=76;
      break;
    case 84:
      at=76;
      break;
    case 85:
      at=76;
      break;
    case 86:
      at=76;
      break;
    case 87:
      at=76;
      break;
    case 88:
      at=76;
      break;
    case 89:
      at=76;
      break;
    case 90:
      at=76;
      break;
    case 91:
      at=76;
      break;
    case 92:
      at=76;
      break;
    case 93:
      at=76;
      break;
    case 94:
      at=76;
      break;
    case 95:
      at=76;
      break;
    case 96:
      at=76;
      break;
    case 97:
      at=76;
      break;
    case 98:
      at=76;
      break;
    case 99:
      at=76;
      break;
  }
  return at;
}

int df1(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int df;
  switch(lv){
    case 1:
      df=0;
      break;
    case 2:
      df=2;
      break;
    case 3:
      df=4;
      break;
    case 4:
      df=6;
      break;
    case 5:
      df=8;
      break;
    case 6:
      df=10;
      break;
    case 7:
      df=12;
      break;
    case 8:
      df=14;
      break;
    case 9:
      df=16;
      break;
    case 10:
      df=18;
      break;
    case 11:
      df=20;
      break;
    case 12:
      df=22;
      break;
    case 13:
      df=23;
      break;
    case 14:
      df=24;
      break;
    case 15:
      df=25;
      break;
    case 16:
      df=26;
      break;
    case 17:
      df=27;
      break;
    case 18:
      df=28;
      break;
    case 19:
      df=29;
      break;
    case 20:
      df=30;
      break;
    case 21:
      df=31;
      break;
    case 22:
      df=32;
      break;
    case 23:
      df=33;
      break;
    case 24:
      df=34;
      break;
    case 25:
      df=35;
      break;
    case 26:
      df=36;
      break;
    case 27:
      df=37;
      break;
    case 28:
      df=38;
      break;
    case 29:
      df=39;
      break;
    case 30:
      df=40;
      break;
    case 31:
      df=40;
      break;
    case 32:
      df=40;
      break;
    case 33:
      df=40;
      break;
    case 34:
      df=40;
      break;
    case 35:
      df=40;
      break;
    case 36:
      df=40;
      break;
    case 37:
      df=40;
      break;
    case 38:
      df=40;
      break;
    case 39:
      df=40;
      break;
    case 40:
      df=40;
      break;
    case 41:
      df=40;
      break;
    case 42:
      df=40;
      break;
    case 43:
      df=40;
      break;
    case 44:
      df=40;
      break;
    case 45:
      df=40;
      break;
    case 46:
      df=40;
      break;
    case 47:
      df=40;
      break;
    case 48:
      df=40;
      break;
    case 49:
      df=40;
      break;
    case 50:
      df=40;
      break;
    case 51:
      df=40;
      break;
    case 52:
      df=40;
      break;
    case 53:
      df=40;
      break;
    case 54:
      df=40;
      break;
    case 55:
      df=40;
      break;
    case 56:
      df=40;
      break;
    case 57:
      df=40;
      break;
    case 58:
      df=40;
      break;
    case 59:
      df=40;
      break;
    case 60:
      df=40;
      break;
    case 61:
      df=40;
      break;
    case 62:
      df=40;
      break;
    case 63:
      df=40;
      break;
    case 64:
      df=40;
      break;
    case 65:
      df=40;
      break;
    case 66:
      df=40;
      break;
    case 67:
      df=40;
      break;
    case 68:
      df=40;
      break;
    case 69:
      df=40;
      break;
    case 70:
      df=40;
      break;
    case 71:
      df=40;
      break;
    case 72:
      df=40;
      break;
    case 73:
      df=40;
      break;
    case 74:
      df=40;
      break;
    case 75:
      df=40;
      break;
    case 76:
      df=40;
      break;
    case 77:
      df=40;
      break;
    case 78:
      df=40;
      break;
    case 79:
      df=40;
      break;
    case 80:
      df=40;
      break;
    case 81:
      df=40;
      break;
    case 82:
      df=40;
      break;
    case 83:
      df=40;
      break;
    case 84:
      df=40;
      break;
    case 85:
      df=40;
      break;
    case 86:
      df=40;
      break;
    case 87:
      df=40;
      break;
    case 88:
      df=40;
      break;
    case 89:
      df=40;
      break;
    case 90:
      df=40;
      break;
    case 91:
      df=40;
      break;
    case 92:
      df=40;
      break;
    case 93:
      df=40;
      break;
    case 94:
      df=40;
      break;
    case 95:
      df=40;
      break;
    case 96:
      df=40;
      break;
    case 97:
      df=40;
      break;
    case 98:
      df=40;
      break;
    case 99:
      df=40;
      break;
  }
  return df;
}

int hp2(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
  }
  int hp;
  switch(lv){
    case 1:
      hp=0;
      break;
    case 2:
      hp=3;
      break;
    case 3:
      hp=6;
      break;
    case 4:
      hp=9;
      break;
    case 5:
      hp=11;
      break;
    case 6:
      hp=13;
      break;
    case 7:
      hp=15;
      break;
    case 8:
      hp=17;
      break;
    case 9:
      hp=19;
      break;
    case 10:
      hp=21;
      break;
    case 11:
      hp=23;
      break;
    case 12:
      hp=25;
      break;
    case 13:
      hp=27;
      break;
    case 14:
      hp=29;
      break;
    case 15:
      hp=30;
      break;
    case 16:
      hp=31;
      break;
    case 17:
      hp=32;
      break;
    case 18:
      hp=33;
      break;
    case 19:
      hp=34;
      break;
    case 20:
      hp=35;
      break;
    case 21:
      hp=36;
      break;
    case 22:
      hp=37;
      break;
    case 23:
      hp=38;
      break;
    case 24:
      hp=39;
      break;
    case 25:
      hp=40;
      break;
    case 26:
      hp=41;
      break;
    case 27:
      hp=42;
      break;
    case 28:
      hp=43;
      break;
    case 29:
      hp=44;
      break;
    case 30:
      hp=47;
      break;
    case 31:
      hp=49;
      break;
    case 32:
      hp=50;
      break;
    case 33:
      hp=51;
      break;
    case 34:
      hp=52;
      break;
    case 35:
      hp=53;
      break;
    case 36:
      hp=54;
      break;
    case 37:
      hp=55;
      break;
    case 38:
      hp=56;
      break;
    case 39:
      hp=57;
      break;
    case 40:
      hp=58;
      break;
    case 41:
      hp=59;
      break;
    case 42:
      hp=60;
      break;
    case 43:
      hp=61;
      break;
    case 44:
      hp=62;
      break;
    case 45:
      hp=63;
      break;
    case 46:
      hp=64;
      break;
    case 47:
      hp=65;
      break;
    case 48:
      hp=66;
      break;
    case 49:
      hp=67;
      break;
    case 50:
      hp=67;
      break;
    case 51:
      hp=67;
      break;
    case 52:
      hp=67;
      break;
    case 53:
      hp=67;
      break;
    case 54:
      hp=67;
      break;
    case 55:
      hp=67;
      break;
    case 56:
      hp=67;
      break;
    case 57:
      hp=67;
      break;
    case 58:
      hp=67;
      break;
    case 59:
      hp=67;
      break;
    case 60:
      hp=67;
      break;
    case 61:
      hp=67;
      break;
    case 62:
      hp=67;
      break;
    case 63:
      hp=67;
      break;
    case 64:
      hp=67;
      break;
    case 65:
      hp=67;
      break;
    case 66:
      hp=67;
      break;
    case 67:
      hp=67;
      break;
    case 68:
      hp=67;
      break;
    case 69:
      hp=67;
      break;
    case 70:
      hp=67;
      break;
    case 71:
      hp=67;
      break;
    case 72:
      hp=67;
      break;
    case 73:
      hp=67;
      break;
    case 74:
      hp=67;
      break;
    case 75:
      hp=67;
      break;
    case 76:
      hp=67;
      break;
    case 77:
      hp=67;
      break;
    case 78:
      hp=67;
      break;
    case 79:
      hp=67;
      break;
    case 80:
      hp=67;
      break;
    case 81:
      hp=67;
      break;
    case 82:
      hp=67;
      break;
    case 83:
      hp=67;
      break;
    case 84:
      hp=67;
      break;
    case 85:
      hp=67;
      break;
    case 86:
      hp=67;
      break;
    case 87:
      hp=67;
      break;
    case 88:
      hp=67;
      break;
    case 89:
      hp=67;
      break;
    case 90:
      hp=67;
      break;
    case 91:
      hp=67;
      break;
    case 92:
      hp=67;
      break;
    case 93:
      hp=67;
      break;
    case 94:
      hp=67;
      break;
    case 95:
      hp=67;
      break;
    case 96:
      hp=67;
      break;
    case 97:
      hp=67;
      break;
    case 98:
      hp=67;
      break;
    case 99:
      hp=67;
      break;
  }
  return hp;
}

int at2(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int at;
  switch(lv){
    case 1:
      at=0;
      break;
    case 2:
      at=2;
      break;
    case 3:
      at=4;
      break;
    case 4:
      at=6;
      break;
    case 5:
      at=8;
      break;
    case 6:
      at=11;
      break;
    case 7:
      at=14;
      break;
    case 8:
      at=17;
      break;
    case 9:
      at=20;
      break;
    case 10:
      at=23;
      break;
    case 11:
      at=26;
      break;
    case 12:
      at=29;
      break;
    case 13:
      at=32;
      break;
    case 14:
      at=35;
      break;
    case 15:
      at=37;
      break;
    case 16:
      at=39;
      break;
    case 17:
      at=41;
      break;
    case 18:
      at=43;
      break;
    case 19:
      at=45;
      break;
    case 20:
      at=47;
      break;
    case 21:
      at=49;
      break;
    case 22:
      at=51;
      break;
    case 23:
      at=53;
      break;
    case 24:
      at=55;
      break;
    case 25:
      at=57;
      break;
    case 26:
      at=58;
      break;
    case 27:
      at=59;
      break;
    case 28:
      at=60;
      break;
    case 29:
      at=61;
      break;
    case 30:
      at=62;
      break;
    case 31:
      at=63;
      break;
    case 32:
      at=64;
      break;
    case 33:
      at=65;
      break;
    case 34:
      at=66;
      break;
    case 35:
      at=67;
      break;
    case 36:
      at=68;
      break;
    case 37:
      at=69;
      break;
    case 38:
      at=70;
      break;
    case 39:
      at=71;
      break;
    case 40:
      at=72;
      break;
    case 41:
      at=73;
      break;
    case 42:
      at=74;
      break;
    case 43:
      at=75;
      break;
    case 44:
      at=76;
      break;
    case 45:
      at=77;
      break;
    case 46:
      at=78;
      break;
    case 47:
      at=79;
      break;
    case 48:
      at=80;
      break;
    case 49:
      at=81;
      break;
    case 50:
      at=82;
      break;
    case 51:
      at=83;
      break;
    case 52:
      at=84;
      break;
    case 53:
      at=85;
      break;
    case 54:
      at=86;
      break;
    case 55:
      at=87;
      break;
    case 56:
      at=88;
      break;
    case 57:
      at=89;
      break;
    case 58:
      at=90;
      break;
    case 59:
      at=91;
      break;
    case 60:
      at=92;
      break;
    case 61:
      at=93;
      break;
    case 62:
      at=94;
      break;
    case 63:
      at=95;
      break;
    case 64:
      at=96;
      break;
    case 65:
      at=97;
      break;
    case 66:
      at=98;
      break;
    case 67:
      at=99;
      break;
    case 68:
      at=100;
      break;
    case 69:
      at=101;
      break;
    case 70:
      at=102;
      break;
    case 71:
      at=103;
      break;
    case 72:
      at=104;
      break;
    case 73:
      at=105;
      break;
    case 74:
      at=106;
      break;
    case 75:
      at=107;
      break;
    case 76:
      at=108;
      break;
    case 77:
      at=109;
      break;
    case 78:
      at=110;
      break;
    case 79:
      at=111;
      break;
    case 80:
      at=112;
      break;
    case 81:
      at=113;
      break;
    case 82:
      at=114;
      break;
    case 83:
      at=115;
      break;
    case 84:
      at=116;
      break;
    case 85:
      at=117;
      break;
    case 86:
      at=118;
      break;
    case 87:
      at=119;
      break;
    case 88:
      at=120;
      break;
    case 89:
      at=121;
      break;
    case 90:
      at=122;
      break;
    case 91:
      at=123;
      break;
    case 92:
      at=124;
      break;
    case 93:
      at=125;
      break;
    case 94:
      at=126;
      break;
    case 95:
      at=127;
      break;
    case 96:
      at=128;
      break;
    case 97:
      at=129;
      break;
    case 98:
      at=130;
      break;
    case 99:
      at=131;
      break;
  }
  return at;
}

int df2(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int df;
  switch(lv){
    case 1:
      df=0;
      break;
    case 2:
      df=2;
      break;
    case 3:
      df=4;
      break;
    case 4:
      df=6;
      break;
    case 5:
      df=8;
      break;
    case 6:
      df=9;
      break;
    case 7:
      df=10;
      break;
    case 8:
      df=11;
      break;
    case 9:
      df=12;
      break;
    case 10:
      df=13;
      break;
    case 11:
      df=14;
      break;
    case 12:
      df=15;
      break;
    case 13:
      df=16;
      break;
    case 14:
      df=17;
      break;
    case 15:
      df=18;
      break;
    case 16:
      df=19;
      break;
    case 17:
      df=20;
      break;
    case 18:
      df=21;
      break;
    case 19:
      df=22;
      break;
    case 20:
      df=23;
      break;
    case 21:
      df=24;
      break;
    case 22:
      df=25;
      break;
    case 23:
      df=26;
      break;
    case 24:
      df=27;
      break;
    case 25:
      df=28;
      break;
    case 26:
      df=29;
      break;
    case 27:
      df=30;
      break;
    case 28:
      df=31;
      break;
    case 29:
      df=32;
      break;
    case 30:
      df=33;
      break;
    case 31:
      df=33;
      break;
    case 32:
      df=33;
      break;
    case 33:
      df=33;
      break;
    case 34:
      df=33;
      break;
    case 35:
      df=33;
      break;
    case 36:
      df=33;
      break;
    case 37:
      df=33;
      break;
    case 38:
      df=33;
      break;
    case 39:
      df=33;
      break;
    case 40:
      df=33;
      break;
    case 41:
      df=33;
      break;
    case 42:
      df=33;
      break;
    case 43:
      df=33;
      break;
    case 44:
      df=33;
      break;
    case 45:
      df=33;
      break;
    case 46:
      df=33;
      break;
    case 47:
      df=33;
      break;
    case 48:
      df=33;
      break;
    case 49:
      df=33;
      break;
    case 50:
      df=33;
      break;
    case 51:
      df=33;
      break;
    case 52:
      df=33;
      break;
    case 53:
      df=33;
      break;
    case 54:
      df=33;
      break;
    case 55:
      df=33;
      break;
    case 56:
      df=33;
      break;
    case 57:
      df=33;
      break;
    case 58:
      df=33;
      break;
    case 59:
      df=33;
      break;
    case 60:
      df=33;
      break;
    case 61:
      df=33;
      break;
    case 62:
      df=33;
      break;
    case 63:
      df=33;
      break;
    case 64:
      df=33;
      break;
    case 65:
      df=33;
      break;
    case 66:
      df=33;
      break;
    case 67:
      df=33;
      break;
    case 68:
      df=33;
      break;
    case 69:
      df=33;
      break;
    case 70:
      df=33;
      break;
    case 71:
      df=33;
      break;
    case 72:
      df=33;
      break;
    case 73:
      df=33;
      break;
    case 74:
      df=33;
      break;
    case 75:
      df=33;
      break;
    case 76:
      df=33;
      break;
    case 77:
      df=33;
      break;
    case 78:
      df=33;
      break;
    case 79:
      df=33;
      break;
    case 80:
      df=33;
      break;
    case 81:
      df=33;
      break;
    case 82:
      df=33;
      break;
    case 83:
      df=33;
      break;
    case 84:
      df=33;
      break;
    case 85:
      df=33;
      break;
    case 86:
      df=33;
      break;
    case 87:
      df=33;
      break;
    case 88:
      df=33;
      break;
    case 89:
      df=33;
      break;
    case 90:
      df=33;
      break;
    case 91:
      df=33;
      break;
    case 92:
      df=33;
      break;
    case 93:
      df=33;
      break;
    case 94:
      df=33;
      break;
    case 95:
      df=33;
      break;
    case 96:
      df=33;
      break;
    case 97:
      df=33;
      break;
    case 98:
      df=33;
      break;
    case 99:
      df=33;
      break;
  }
  return df;
}

int hp3(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int hp;
  switch(lv){
    case 1:
      hp=0;
      break;
    case 2:
      hp=4;
      break;
    case 3:
      hp=8;
      break;
    case 4:
      hp=11;
      break;
    case 5:
      hp=14;
      break;
    case 6:
      hp=17;
      break;
    case 7:
      hp=20;
      break;
    case 8:
      hp=23;
      break;
    case 9:
      hp=26;
      break;
    case 10:
      hp=29;
      break;
    case 11:
      hp=32;
      break;
    case 12:
      hp=35;
      break;
    case 13:
      hp=38;
      break;
    case 14:
      hp=41;
      break;
    case 15:
      hp=44;
      break;
    case 16:
      hp=45;
      break;
    case 17:
      hp=46;
      break;
    case 18:
      hp=47;
      break;
    case 19:
      hp=48;
      break;
    case 20:
      hp=49;
      break;
    case 21:
      hp=50;
      break;
    case 22:
      hp=51;
      break;
    case 23:
      hp=52;
      break;
    case 24:
      hp=53;
      break;
    case 25:
      hp=54;
      break;
    case 26:
      hp=55;
      break;
    case 27:
      hp=56;
      break;
    case 28:
      hp=57;
      break;
    case 29:
      hp=58;
      break;
    case 30:
      hp=59;
      break;
    case 31:
      hp=60;
      break;
    case 32:
      hp=60;
      break;
    case 33:
      hp=61;
      break;
    case 34:
      hp=61;
      break;
    case 35:
      hp=62;
      break;
    case 36:
      hp=62;
      break;
    case 37:
      hp=63;
      break;
    case 38:
      hp=63;
      break;
    case 39:
      hp=64;
      break;
    case 40:
      hp=64;
      break;
    case 41:
      hp=65;
      break;
    case 42:
      hp=65;
      break;
    case 43:
      hp=66;
      break;
    case 44:
      hp=66;
      break;
    case 45:
      hp=67;
      break;
    case 46:
      hp=67;
      break;
    case 47:
      hp=68;
      break;
    case 48:
      hp=68;
      break;
    case 49:
      hp=69;
      break;
    case 50:
      hp=69;
      break;
    case 51:
      hp=70;
      break;
    case 52:
      hp=70;
      break;
    case 53:
      hp=71;
      break;
    case 54:
      hp=71;
      break;
    case 55:
      hp=72;
      break;
    case 56:
      hp=72;
      break;
    case 57:
      hp=73;
      break;
    case 58:
      hp=73;
      break;
    case 59:
      hp=74;
      break;
    case 60:
      hp=74;
      break;
    case 61:
      hp=75;
      break;
    case 62:
      hp=75;
      break;
    case 63:
      hp=76;
      break;
    case 64:
      hp=76;
      break;
    case 65:
      hp=77;
      break;
    case 66:
      hp=77;
      break;
    case 67:
      hp=78;
      break;
    case 68:
      hp=78;
      break;
    case 69:
      hp=79;
      break;
    case 70:
      hp=79;
      break;
    case 71:
      hp=80;
      break;
    case 72:
      hp=80;
      break;
    case 73:
      hp=81;
      break;
    case 74:
      hp=81;
      break;
    case 75:
      hp=82;
      break;
    case 76:
      hp=82;
      break;
    case 77:
      hp=83;
      break;
    case 78:
      hp=83;
      break;
    case 79:
      hp=84;
      break;
    case 80:
      hp=84;
      break;
    case 81:
      hp=84;
      break;
    case 82:
      hp=84;
      break;
    case 83:
      hp=84;
      break;
    case 84:
      hp=84;
      break;
    case 85:
      hp=84;
      break;
    case 86:
      hp=84;
      break;
    case 87:
      hp=84;
      break;
    case 88:
      hp=84;
      break;
    case 89:
      hp=84;
      break;
    case 90:
      hp=84;
      break;
    case 91:
      hp=84;
      break;
    case 92:
      hp=84;
      break;
    case 93:
      hp=84;
      break;
    case 94:
      hp=84;
      break;
    case 95:
      hp=84;
      break;
    case 96:
      hp=84;
      break;
    case 97:
      hp=84;
      break;
    case 98:
      hp=84;
      break;
    case 99:
      hp=84;
      break;
  }
  return hp;
}

int at3(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int at;
  switch(lv){
    case 1:
      at=0;
      break;
    case 2:
      at=5;
      break;
    case 3:
      at=10;
      break;
    case 4:
      at=14;
      break;
    case 5:
      at=17;
      break;
    case 6:
      at=20;
      break;
    case 7:
      at=22;
      break;
    case 8:
      at=24;
      break;
    case 9:
      at=26;
      break;
    case 10:
      at=28;
      break;
    case 11:
      at=30;
      break;
    case 12:
      at=32;
      break;
    case 13:
      at=34;
      break;
    case 14:
      at=36;
      break;
    case 15:
      at=38;
      break;
    case 16:
      at=39;
      break;
    case 17:
      at=39;
      break;
    case 18:
      at=40;
      break;
    case 19:
      at=40;
      break;
    case 20:
      at=40;
      break;
    case 21:
      at=40;
      break;
    case 22:
      at=40;
      break;
    case 23:
      at=40;
      break;
    case 24:
      at=40;
      break;
    case 25:
      at=40;
      break;
    case 26:
      at=40;
      break;
    case 27:
      at=40;
      break;
    case 28:
      at=40;
      break;
    case 29:
      at=40;
      break;
    case 30:
      at=40;
      break;
    case 31:
      at=40;
      break;
    case 32:
      at=40;
      break;
    case 33:
      at=40;
      break;
    case 34:
      at=40;
      break;
    case 35:
      at=40;
      break;
    case 36:
      at=40;
      break;
    case 37:
      at=40;
      break;
    case 38:
      at=40;
      break;
    case 39:
      at=40;
      break;
    case 40:
      at=40;
      break;
    case 41:
      at=40;
      break;
    case 42:
      at=40;
      break;
    case 43:
      at=40;
      break;
    case 44:
      at=40;
      break;
    case 45:
      at=40;
      break;
    case 46:
      at=40;
      break;
    case 47:
      at=40;
      break;
    case 48:
      at=40;
      break;
    case 49:
      at=40;
      break;
    case 50:
      at=40;
      break;
    case 51:
      at=40;
      break;
    case 52:
      at=40;
      break;
    case 53:
      at=40;
      break;
    case 54:
      at=40;
      break;
    case 55:
      at=40;
      break;
    case 56:
      at=40;
      break;
    case 57:
      at=40;
      break;
    case 58:
      at=40;
      break;
    case 59:
      at=40;
      break;
    case 60:
      at=40;
      break;
    case 61:
      at=40;
      break;
    case 62:
      at=40;
      break;
    case 63:
      at=40;
      break;
    case 64:
      at=40;
      break;
    case 65:
      at=40;
      break;
    case 66:
      at=40;
      break;
    case 67:
      at=40;
      break;
    case 68:
      at=40;
      break;
    case 69:
      at=40;
      break;
    case 70:
      at=40;
      break;
    case 71:
      at=40;
      break;
    case 72:
      at=40;
      break;
    case 73:
      at=40;
      break;
    case 74:
      at=40;
      break;
    case 75:
      at=40;
      break;
    case 76:
      at=40;
      break;
    case 77:
      at=40;
      break;
    case 78:
      at=40;
      break;
    case 79:
      at=40;
      break;
    case 80:
      at=40;
      break;
    case 81:
      at=40;
      break;
    case 82:
      at=40;
      break;
    case 83:
      at=40;
      break;
    case 84:
      at=40;
      break;
    case 85:
      at=40;
      break;
    case 86:
      at=40;
      break;
    case 87:
      at=40;
      break;
    case 88:
      at=40;
      break;
    case 89:
      at=40;
      break;
    case 90:
      at=40;
      break;
    case 91:
      at=40;
      break;
    case 92:
      at=40;
      break;
    case 93:
      at=40;
      break;
    case 94:
      at=40;
      break;
    case 95:
      at=40;
      break;
    case 96:
      at=40;
      break;
    case 97:
      at=40;
      break;
    case 98:
      at=40;
      break;
    case 99:
      at=40;
      break;
  }
  return at;
}

int df3(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int df;
  switch(lv){
    case 1:
      df=0;
      break;
    case 2:
      df=2;
      break;
    case 3:
      df=4;
      break;
    case 4:
      df=6;
      break;
    case 5:
      df=8;
      break;
    case 6:
      df=10;
      break;
    case 7:
      df=12;
      break;
    case 8:
      df=14;
      break;
    case 9:
      df=16;
      break;
    case 10:
      df=18;
      break;
    case 11:
      df=20;
      break;
    case 12:
      df=22;
      break;
    case 13:
      df=24;
      break;
    case 14:
      df=26;
      break;
    case 15:
      df=28;
      break;
    case 16:
      df=30;
      break;
    case 17:
      df=32;
      break;
    case 18:
      df=34;
      break;
    case 19:
      df=36;
      break;
    case 20:
      df=38;
      break;
    case 21:
      df=40;
      break;
    case 22:
      df=42;
      break;
    case 23:
      df=44;
      break;
    case 24:
      df=46;
      break;
    case 25:
      df=48;
      break;
    case 26:
      df=50;
      break;
    case 27:
      df=52;
      break;
    case 28:
      df=54;
      break;
    case 29:
      df=55;
      break;
    case 30:
      df=56;
      break;
    case 31:
      df=57;
      break;
    case 32:
      df=57;
      break;
    case 33:
      df=58;
      break;
    case 34:
      df=58;
      break;
    case 35:
      df=59;
      break;
    case 36:
      df=59;
      break;
    case 37:
      df=60;
      break;
    case 38:
      df=60;
      break;
    case 39:
      df=61;
      break;
    case 40:
      df=61;
      break;
    case 41:
      df=62;
      break;
    case 42:
      df=62;
      break;
    case 43:
      df=63;
      break;
    case 44:
      df=63;
      break;
    case 45:
      df=64;
      break;
    case 46:
      df=64;
      break;
    case 47:
      df=65;
      break;
    case 48:
      df=65;
      break;
    case 49:
      df=66;
      break;
    case 50:
      df=66;
      break;
    case 51:
      df=67;
      break;
    case 52:
      df=67;
      break;
    case 53:
      df=68;
      break;
    case 54:
      df=68;
      break;
    case 55:
      df=69;
      break;
    case 56:
      df=69;
      break;
    case 57:
      df=70;
      break;
    case 58:
      df=70;
      break;
    case 59:
      df=71;
      break;
    case 60:
      df=71;
      break;
    case 61:
      df=72;
      break;
    case 62:
      df=72;
      break;
    case 63:
      df=73;
      break;
    case 64:
      df=73;
      break;
    case 65:
      df=74;
      break;
    case 66:
      df=74;
      break;
    case 67:
      df=75;
      break;
    case 68:
      df=75;
      break;
    case 69:
      df=76;
      break;
    case 70:
      df=76;
      break;
    case 71:
      df=77;
      break;
    case 72:
      df=77;
      break;
    case 73:
      df=78;
      break;
    case 74:
      df=78;
      break;
    case 75:
      df=79;
      break;
    case 76:
      df=79;
      break;
    case 77:
      df=80;
      break;
    case 78:
      df=80;
      break;
    case 79:
      df=81;
      break;
    case 80:
      df=81;
      break;
    case 81:
      df=82;
      break;
    case 82:
      df=82;
      break;
    case 83:
      df=83;
      break;
    case 84:
      df=83;
      break;
    case 85:
      df=84;
      break;
    case 86:
      df=84;
      break;
    case 87:
      df=85;
      break;
    case 88:
      df=85;
      break;
    case 89:
      df=86;
      break;
    case 90:
      df=86;
      break;
    case 91:
      df=87;
      break;
    case 92:
      df=87;
      break;
    case 93:
      df=88;
      break;
    case 94:
      df=88;
      break;
    case 95:
      df=89;
      break;
    case 96:
      df=89;
      break;
    case 97:
      df=90;
      break;
    case 98:
      df=90;
      break;
    case 99:
      df=91;
      break;
  }
  return df;
}

int hp4(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int hp;
  switch(lv){
    case 1:
      hp=0;
      break;
    case 2:
      hp=5;
      break;
    case 3:
      hp=10;
      break;
    case 4:
      hp=15;
      break;
    case 5:
      hp=20;
      break;
    case 6:
      hp=25;
      break;
    case 7:
      hp=30;
      break;
    case 8:
      hp=35;
      break;
    case 9:
      hp=40;
      break;
    case 10:
      hp=45;
      break;
    case 11:
      hp=50;
      break;
    case 12:
      hp=55;
      break;
    case 13:
      hp=60;
      break;
    case 14:
      hp=65;
      break;
    case 15:
      hp=70;
      break;
    case 16:
      hp=75;
      break;
    case 17:
      hp=80;
      break;
    case 18:
      hp=85;
      break;
    case 19:
      hp=90;
      break;
    case 20:
      hp=93;
      break;
    case 21:
      hp=96;
      break;
    case 22:
      hp=99;
      break;
    case 23:
      hp=102;
      break;
    case 24:
      hp=105;
      break;
    case 25:
      hp=108;
      break;
    case 26:
      hp=111;
      break;
    case 27:
      hp=114;
      break;
    case 28:
      hp=117;
      break;
    case 29:
      hp=120;
      break;
    case 30:
      hp=122;
      break;
    case 31:
      hp=124;
      break;
    case 32:
      hp=126;
      break;
    case 33:
      hp=128;
      break;
    case 34:
      hp=130;
      break;
    case 35:
      hp=132;
      break;
    case 36:
      hp=134;
      break;
    case 37:
      hp=136;
      break;
    case 38:
      hp=138;
      break;
    case 39:
      hp=140;
      break;
    case 40:
      hp=142;
      break;
    case 41:
      hp=144;
      break;
    case 42:
      hp=146;
      break;
    case 43:
      hp=148;
      break;
    case 44:
      hp=150;
      break;
    case 45:
      hp=152;
      break;
    case 46:
      hp=154;
      break;
    case 47:
      hp=156;
      break;
    case 48:
      hp=158;
      break;
    case 49:
      hp=160;
      break;
    case 50:
      hp=161;
      break;
    case 51:
      hp=162;
      break;
    case 52:
      hp=163;
      break;
    case 53:
      hp=164;
      break;
    case 54:
      hp=165;
      break;
    case 55:
      hp=166;
      break;
    case 56:
      hp=167;
      break;
    case 57:
      hp=168;
      break;
    case 58:
      hp=169;
      break;
    case 59:
      hp=170;
      break;
    case 60:
      hp=171;
      break;
    case 61:
      hp=172;
      break;
    case 62:
      hp=173;
      break;
    case 63:
      hp=174;
      break;
    case 64:
      hp=175;
      break;
    case 65:
      hp=176;
      break;
    case 66:
      hp=177;
      break;
    case 67:
      hp=178;
      break;
    case 68:
      hp=179;
      break;
    case 69:
      hp=180;
      break;
    case 70:
      hp=181;
      break;
    case 71:
      hp=182;
      break;
    case 72:
      hp=183;
      break;
    case 73:
      hp=184;
      break;
    case 74:
      hp=185;
      break;
    case 75:
      hp=186;
      break;
    case 76:
      hp=187;
      break;
    case 77:
      hp=188;
      break;
    case 78:
      hp=189;
      break;
    case 79:
      hp=190;
      break;
    case 80:
      hp=191;
      break;
    case 81:
      hp=192;
      break;
    case 82:
      hp=193;
      break;
    case 83:
      hp=194;
      break;
    case 84:
      hp=195;
      break;
    case 85:
      hp=196;
      break;
    case 86:
      hp=197;
      break;
    case 87:
      hp=198;
      break;
    case 88:
      hp=199;
      break;
    case 89:
      hp=200;
      break;
    case 90:
      hp=201;
      break;
    case 91:
      hp=202;
      break;
    case 92:
      hp=203;
      break;
    case 93:
      hp=204;
      break;
    case 94:
      hp=205;
      break;
    case 95:
      hp=206;
      break;
    case 96:
      hp=207;
      break;
    case 97:
      hp=208;
      break;
    case 98:
      hp=209;
      break;
    case 99:
      hp=210;
      break;
  }
  return hp;
}

int at4(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int at;
  switch(lv){
    case 1:
      at=0;
      break;
    case 2:
      at=10;
      break;
    case 3:
      at=16;
      break;
    case 4:
      at=21;
      break;
    case 5:
      at=26;
      break;
    case 6:
      at=31;
      break;
    case 7:
      at=36;
      break;
    case 8:
      at=39;
      break;
    case 9:
      at=42;
      break;
    case 10:
      at=45;
      break;
    case 11:
      at=48;
      break;
    case 12:
      at=51;
      break;
    case 13:
      at=54;
      break;
    case 14:
      at=57;
      break;
    case 15:
      at=60;
      break;
    case 16:
      at=63;
      break;
    case 17:
      at=66;
      break;
    case 18:
      at=69;
      break;
    case 19:
      at=72;
      break;
    case 20:
      at=74;
      break;
    case 21:
      at=76;
      break;
    case 22:
      at=78;
      break;
    case 23:
      at=80;
      break;
    case 24:
      at=82;
      break;
    case 25:
      at=84;
      break;
    case 26:
      at=86;
      break;
    case 27:
      at=88;
      break;
    case 28:
      at=90;
      break;
    case 29:
      at=92;
      break;
    case 30:
      at=94;
      break;
    case 31:
      at=96;
      break;
    case 32:
      at=98;
      break;
    case 33:
      at=99;
      break;
    case 34:
      at=100;
      break;
    case 35:
      at=101;
      break;
    case 36:
      at=102;
      break;
    case 37:
      at=103;
      break;
    case 38:
      at=104;
      break;
    case 39:
      at=105;
      break;
    case 40:
      at=106;
      break;
    case 41:
      at=107;
      break;
    case 42:
      at=107;
      break;
    case 43:
      at=108;
      break;
    case 44:
      at=108;
      break;
    case 45:
      at=109;
      break;
    case 46:
      at=109;
      break;
    case 47:
      at=110;
      break;
    case 48:
      at=110;
      break;
    case 49:
      at=111;
      break;
    case 50:
      at=111;
      break;
    case 51:
      at=112;
      break;
    case 52:
      at=112;
      break;
    case 53:
      at=113;
      break;
    case 54:
      at=113;
      break;
    case 55:
      at=114;
      break;
    case 56:
      at=114;
      break;
    case 57:
      at=115;
      break;
    case 58:
      at=115;
      break;
    case 59:
      at=116;
      break;
    case 60:
      at=116;
      break;
    case 61:
      at=117;
      break;
    case 62:
      at=117;
      break;
    case 63:
      at=118;
      break;
    case 64:
      at=118;
      break;
    case 65:
      at=119;
      break;
    case 66:
      at=119;
      break;
    case 67:
      at=120;
      break;
    case 68:
      at=120;
      break;
    case 69:
      at=121;
      break;
    case 70:
      at=121;
      break;
    case 71:
      at=122;
      break;
    case 72:
      at=122;
      break;
    case 73:
      at=123;
      break;
    case 74:
      at=123;
      break;
    case 75:
      at=124;
      break;
    case 76:
      at=124;
      break;
    case 77:
      at=125;
      break;
    case 78:
      at=125;
      break;
    case 79:
      at=126;
      break;
    case 80:
      at=126;
      break;
    case 81:
      at=127;
      break;
    case 82:
      at=127;
      break;
    case 83:
      at=128;
      break;
    case 84:
      at=128;
      break;
    case 85:
      at=129;
      break;
    case 86:
      at=129;
      break;
    case 87:
      at=130;
      break;
    case 88:
      at=130;
      break;
    case 89:
      at=131;
      break;
    case 90:
      at=131;
      break;
    case 91:
      at=132;
      break;
    case 92:
      at=132;
      break;
    case 93:
      at=133;
      break;
    case 94:
      at=133;
      break;
    case 95:
      at=134;
      break;
    case 96:
      at=134;
      break;
    case 97:
      at=135;
      break;
    case 98:
      at=135;
      break;
    case 99:
      at=136;
      break;
  }
  return at;
}

int df4(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int df;
  switch(lv){
    case 1:
      df=0;
      break;
    case 2:
      df=2;
      break;
    case 3:
      df=4;
      break;
    case 4:
      df=6;
      break;
    case 5:
      df=8;
      break;
    case 6:
      df=10;
      break;
    case 7:
      df=12;
      break;
    case 8:
      df=14;
      break;
    case 9:
      df=16;
      break;
    case 10:
      df=18;
      break;
    case 11:
      df=19;
      break;
    case 12:
      df=20;
      break;
    case 13:
      df=21;
      break;
    case 14:
      df=22;
      break;
    case 15:
      df=23;
      break;
    case 16:
      df=24;
      break;
    case 17:
      df=25;
      break;
    case 18:
      df=26;
      break;
    case 19:
      df=27;
      break;
    case 20:
      df=28;
      break;
    case 21:
      df=29;
      break;
    case 22:
      df=30;
      break;
    case 23:
      df=31;
      break;
    case 24:
      df=32;
      break;
    case 25:
      df=33;
      break;
    case 26:
      df=34;
      break;
    case 27:
      df=35;
      break;
    case 28:
      df=36;
      break;
    case 29:
      df=37;
      break;
    case 30:
      df=38;
      break;
    case 31:
      df=39;
      break;
    case 32:
      df=40;
      break;
    case 33:
      df=41;
      break;
    case 34:
      df=42;
      break;
    case 35:
      df=43;
      break;
    case 36:
      df=44;
      break;
    case 37:
      df=45;
      break;
    case 38:
      df=46;
      break;
    case 39:
      df=47;
      break;
    case 40:
      df=48;
      break;
    case 41:
      df=49;
      break;
    case 42:
      df=50;
      break;
    case 43:
      df=51;
      break;
    case 44:
      df=52;
      break;
    case 45:
      df=53;
      break;
    case 46:
      df=54;
      break;
    case 47:
      df=55;
      break;
    case 48:
      df=56;
      break;
    case 49:
      df=57;
      break;
    case 50:
      df=58;
      break;
    case 51:
      df=59;
      break;
    case 52:
      df=60;
      break;
    case 53:
      df=61;
      break;
    case 54:
      df=62;
      break;
    case 55:
      df=63;
      break;
    case 56:
      df=64;
      break;
    case 57:
      df=65;
      break;
    case 58:
      df=66;
      break;
    case 59:
      df=67;
      break;
    case 60:
      df=68;
      break;
    case 61:
      df=69;
      break;
    case 62:
      df=70;
      break;
    case 63:
      df=71;
      break;
    case 64:
      df=72;
      break;
    case 65:
      df=73;
      break;
    case 66:
      df=74;
      break;
    case 67:
      df=75;
      break;
    case 68:
      df=76;
      break;
    case 69:
      df=77;
      break;
    case 70:
      df=78;
      break;
    case 71:
      df=79;
      break;
    case 72:
      df=80;
      break;
    case 73:
      df=81;
      break;
    case 74:
      df=82;
      break;
    case 75:
      df=83;
      break;
    case 76:
      df=84;
      break;
    case 77:
      df=85;
      break;
    case 78:
      df=86;
      break;
    case 79:
      df=87;
      break;
    case 80:
      df=88;
      break;
    case 81:
      df=89;
      break;
    case 82:
      df=90;
      break;
    case 83:
      df=91;
      break;
    case 84:
      df=92;
      break;
    case 85:
      df=93;
      break;
    case 86:
      df=94;
      break;
    case 87:
      df=95;
      break;
    case 88:
      df=96;
      break;
    case 89:
      df=97;
      break;
    case 90:
      df=98;
      break;
    case 91:
      df=99;
      break;
    case 92:
      df=100;
      break;
    case 93:
      df=101;
      break;
    case 94:
      df=102;
      break;
    case 95:
      df=103;
      break;
    case 96:
      df=104;
      break;
    case 97:
      df=105;
      break;
    case 98:
      df=106;
      break;
    case 99:
      df=107;
      break;
  }
  return df;
}

int hp5(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int hp;
  switch(lv){
    case 1:
      hp=0;
      break;
    case 2:
      hp=3;
      break;
    case 3:
      hp=6;
      break;
    case 4:
      hp=9;
      break;
    case 5:
      hp=12;
      break;
    case 6:
      hp=15;
      break;
    case 7:
      hp=17;
      break;
    case 8:
      hp=19;
      break;
    case 9:
      hp=21;
      break;
    case 10:
      hp=23;
      break;
    case 11:
      hp=25;
      break;
    case 12:
      hp=27;
      break;
    case 13:
      hp=29;
      break;
    case 14:
      hp=31;
      break;
    case 15:
      hp=33;
      break;
    case 16:
      hp=35;
      break;
    case 17:
      hp=37;
      break;
    case 18:
      hp=39;
      break;
    case 19:
      hp=41;
      break;
    case 20:
      hp=43;
      break;
    case 21:
      hp=45;
      break;
    case 22:
      hp=47;
      break;
    case 23:
      hp=49;
      break;
    case 24:
      hp=51;
      break;
    case 25:
      hp=53;
      break;
    case 26:
      hp=55;
      break;
    case 27:
      hp=57;
      break;
    case 28:
      hp=59;
      break;
    case 29:
      hp=61;
      break;
    case 30:
      hp=63;
      break;
    case 31:
      hp=64;
      break;
    case 32:
      hp=65;
      break;
    case 33:
      hp=66;
      break;
    case 34:
      hp=67;
      break;
    case 35:
      hp=68;
      break;
    case 36:
      hp=69;
      break;
    case 37:
      hp=70;
      break;
    case 38:
      hp=71;
      break;
    case 39:
      hp=72;
      break;
    case 40:
      hp=73;
      break;
    case 41:
      hp=74;
      break;
    case 42:
      hp=75;
      break;
    case 43:
      hp=76;
      break;
    case 44:
      hp=77;
      break;
    case 45:
      hp=78;
      break;
    case 46:
      hp=79;
      break;
    case 47:
      hp=80;
      break;
    case 48:
      hp=81;
      break;
    case 49:
      hp=82;
      break;
    case 50:
      hp=83;
      break;
    case 51:
      hp=84;
      break;
    case 52:
      hp=85;
      break;
    case 53:
      hp=86;
      break;
    case 54:
      hp=87;
      break;
    case 55:
      hp=88;
      break;
    case 56:
      hp=89;
      break;
    case 57:
      hp=90;
      break;
    case 58:
      hp=91;
      break;
    case 59:
      hp=92;
      break;
    case 60:
      hp=93;
      break;
    case 61:
      hp=94;
      break;
    case 62:
      hp=95;
      break;
    case 63:
      hp=96;
      break;
    case 64:
      hp=97;
      break;
    case 65:
      hp=98;
      break;
    case 66:
      hp=99;
      break;
    case 67:
      hp=100;
      break;
    case 68:
      hp=101;
      break;
    case 69:
      hp=102;
      break;
    case 70:
      hp=103;
      break;
    case 71:
      hp=104;
      break;
    case 72:
      hp=105;
      break;
    case 73:
      hp=106;
      break;
    case 74:
      hp=107;
      break;
    case 75:
      hp=108;
      break;
    case 76:
      hp=109;
      break;
    case 77:
      hp=110;
      break;
    case 78:
      hp=111;
      break;
    case 79:
      hp=112;
      break;
    case 80:
      hp=113;
      break;
    case 81:
      hp=114;
      break;
    case 82:
      hp=115;
      break;
    case 83:
      hp=116;
      break;
    case 84:
      hp=117;
      break;
    case 85:
      hp=118;
      break;
    case 86:
      hp=119;
      break;
    case 87:
      hp=120;
      break;
    case 88:
      hp=121;
      break;
    case 89:
      hp=122;
      break;
    case 90:
      hp=123;
      break;
    case 91:
      hp=124;
      break;
    case 92:
      hp=125;
      break;
    case 93:
      hp=126;
      break;
    case 94:
      hp=127;
      break;
    case 95:
      hp=128;
      break;
    case 96:
      hp=129;
      break;
    case 97:
      hp=130;
      break;
    case 98:
      hp=131;
      break;
    case 99:
      hp=132;
      break;
  }
  return hp;
}

int at5(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int at;
  switch(lv){
    case 1:
      at=0;
      break;
    case 2:
      at=5;
      break;
    case 3:
      at=9;
      break;
    case 4:
      at=12;
      break;
    case 5:
      at=14;
      break;
    case 6:
      at=16;
      break;
    case 7:
      at=18;
      break;
    case 8:
      at=20;
      break;
    case 9:
      at=22;
      break;
    case 10:
      at=23;
      break;
    case 11:
      at=24;
      break;
    case 12:
      at=26;
      break;
    case 13:
      at=28;
      break;
    case 14:
      at=30;
      break;
    case 15:
      at=32;
      break;
    case 16:
      at=34;
      break;
    case 17:
      at=36;
      break;
    case 18:
      at=38;
      break;
    case 19:
      at=40;
      break;
    case 20:
      at=42;
      break;
    case 21:
      at=43;
      break;
    case 22:
      at=43;
      break;
    case 23:
      at=44;
      break;
    case 24:
      at=44;
      break;
    case 25:
      at=45;
      break;
    case 26:
      at=45;
      break;
    case 27:
      at=46;
      break;
    case 28:
      at=46;
      break;
    case 29:
      at=47;
      break;
    case 30:
      at=47;
      break;
    case 31:
      at=48;
      break;
    case 32:
      at=49;
      break;
    case 33:
      at=50;
      break;
    case 34:
      at=51;
      break;
    case 35:
      at=52;
      break;
    case 36:
      at=53;
      break;
    case 37:
      at=54;
      break;
    case 38:
      at=55;
      break;
    case 39:
      at=56;
      break;
    case 40:
      at=58;
      break;
    case 41:
      at=60;
      break;
    case 42:
      at=62;
      break;
    case 43:
      at=64;
      break;
    case 44:
      at=66;
      break;
    case 45:
      at=68;
      break;
    case 46:
      at=70;
      break;
    case 47:
      at=72;
      break;
    case 48:
      at=74;
      break;
    case 49:
      at=76;
      break;
    case 50:
      at=78;
      break;
    case 51:
      at=80;
      break;
    case 52:
      at=82;
      break;
    case 53:
      at=84;
      break;
    case 54:
      at=86;
      break;
    case 55:
      at=88;
      break;
    case 56:
      at=90;
      break;
    case 57:
      at=92;
      break;
    case 58:
      at=94;
      break;
    case 59:
      at=96;
      break;
    case 60:
      at=98;
      break;
    case 61:
      at=100;
      break;
    case 62:
      at=102;
      break;
    case 63:
      at=104;
      break;
    case 64:
      at=106;
      break;
    case 65:
      at=108;
      break;
    case 66:
      at=110;
      break;
    case 67:
      at=112;
      break;
    case 68:
      at=114;
      break;
    case 69:
      at=116;
      break;
    case 70:
      at=118;
      break;
    case 71:
      at=120;
      break;
    case 72:
      at=122;
      break;
    case 73:
      at=124;
      break;
    case 74:
      at=126;
      break;
    case 75:
      at=128;
      break;
    case 76:
      at=130;
      break;
    case 77:
      at=132;
      break;
    case 78:
      at=134;
      break;
    case 79:
      at=136;
      break;
    case 80:
      at=138;
      break;
    case 81:
      at=140;
      break;
    case 82:
      at=142;
      break;
    case 83:
      at=144;
      break;
    case 84:
      at=146;
      break;
    case 85:
      at=148;
      break;
    case 86:
      at=150;
      break;
    case 87:
      at=152;
      break;
    case 88:
      at=154;
      break;
    case 89:
      at=156;
      break;
    case 90:
      at=158;
      break;
    case 91:
      at=160;
      break;
    case 92:
      at=162;
      break;
    case 93:
      at=164;
      break;
    case 94:
      at=166;
      break;
    case 95:
      at=168;
      break;
    case 96:
      at=170;
      break;
    case 97:
      at=172;
      break;
    case 98:
      at=174;
      break;
    case 99:
      at=176;
      break;
  }
  return at;
}

int df5(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int df;
  switch(lv){
    case 1:
      df=0;
      break;
    case 2:
      df=1;
      break;
    case 3:
      df=2;
      break;
    case 4:
      df=3;
      break;
    case 5:
      df=4;
      break;
    case 6:
      df=5;
      break;
    case 7:
      df=6;
      break;
    case 8:
      df=9;
      break;
    case 9:
      df=12;
      break;
    case 10:
      df=15;
      break;
    case 11:
      df=18;
      break;
    case 12:
      df=21;
      break;
    case 13:
      df=24;
      break;
    case 14:
      df=25;
      break;
    case 15:
      df=26;
      break;
    case 16:
      df=27;
      break;
    case 17:
      df=28;
      break;
    case 18:
      df=29;
      break;
    case 19:
      df=30;
      break;
    case 20:
      df=31;
      break;
    case 21:
      df=31;
      break;
    case 22:
      df=31;
      break;
    case 23:
      df=31;
      break;
    case 24:
      df=31;
      break;
    case 25:
      df=31;
      break;
    case 26:
      df=31;
      break;
    case 27:
      df=31;
      break;
    case 28:
      df=31;
      break;
    case 29:
      df=31;
      break;
    case 30:
      df=31;
      break;
    case 31:
      df=31;
      break;
    case 32:
      df=31;
      break;
    case 33:
      df=31;
      break;
    case 34:
      df=31;
      break;
    case 35:
      df=31;
      break;
    case 36:
      df=31;
      break;
    case 37:
      df=31;
      break;
    case 38:
      df=31;
      break;
    case 39:
      df=31;
      break;
    case 40:
      df=31;
      break;
    case 41:
      df=31;
      break;
    case 42:
      df=31;
      break;
    case 43:
      df=31;
      break;
    case 44:
      df=31;
      break;
    case 45:
      df=31;
      break;
    case 46:
      df=31;
      break;
    case 47:
      df=31;
      break;
    case 48:
      df=31;
      break;
    case 49:
      df=31;
      break;
    case 50:
      df=31;
      break;
    case 51:
      df=31;
      break;
    case 52:
      df=31;
      break;
    case 53:
      df=31;
      break;
    case 54:
      df=31;
      break;
    case 55:
      df=31;
      break;
    case 56:
      df=31;
      break;
    case 57:
      df=31;
      break;
    case 58:
      df=31;
      break;
    case 59:
      df=31;
      break;
    case 60:
      df=31;
      break;
    case 61:
      df=31;
      break;
    case 62:
      df=31;
      break;
    case 63:
      df=31;
      break;
    case 64:
      df=31;
      break;
    case 65:
      df=31;
      break;
    case 66:
      df=31;
      break;
    case 67:
      df=31;
      break;
    case 68:
      df=31;
      break;
    case 69:
      df=31;
      break;
    case 70:
      df=31;
      break;
    case 71:
      df=31;
      break;
    case 72:
      df=31;
      break;
    case 73:
      df=31;
      break;
    case 74:
      df=31;
      break;
    case 75:
      df=31;
      break;
    case 76:
      df=31;
      break;
    case 77:
      df=31;
      break;
    case 78:
      df=31;
      break;
    case 79:
      df=31;
      break;
    case 80:
      df=31;
      break;
    case 81:
      df=31;
      break;
    case 82:
      df=31;
      break;
    case 83:
      df=31;
      break;
    case 84:
      df=31;
      break;
    case 85:
      df=31;
      break;
    case 86:
      df=31;
      break;
    case 87:
      df=31;
      break;
    case 88:
      df=31;
      break;
    case 89:
      df=31;
      break;
    case 90:
      df=31;
      break;
    case 91:
      df=31;
      break;
    case 92:
      df=31;
      break;
    case 93:
      df=31;
      break;
    case 94:
      df=31;
      break;
    case 95:
      df=31;
      break;
    case 96:
      df=31;
      break;
    case 97:
      df=31;
      break;
    case 98:
      df=31;
      break;
    case 99:
      df=31;
      break;
  }
  return df;
}

int hp6(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int hp;
  switch(lv){
    case 1:
      hp=0;
      break;
    case 2:
      hp=8;
      break;
    case 3:
      hp=15;
      break;
    case 4:
      hp=21;
      break;
    case 5:
      hp=26;
      break;
    case 6:
      hp=30;
      break;
    case 7:
      hp=33;
      break;
    case 8:
      hp=35;
      break;
    case 9:
      hp=36;
      break;
    case 10:
      hp=37;
      break;
    case 11:
      hp=38;
      break;
    case 12:
      hp=39;
      break;
    case 13:
      hp=40;
      break;
    case 14:
      hp=41;
      break;
    case 15:
      hp=42;
      break;
    case 16:
      hp=43;
      break;
    case 17:
      hp=44;
      break;
    case 18:
      hp=45;
      break;
    case 19:
      hp=46;
      break;
    case 20:
      hp=47;
      break;
    case 21:
      hp=48;
      break;
    case 22:
      hp=49;
      break;
    case 23:
      hp=50;
      break;
    case 24:
      hp=51;
      break;
    case 25:
      hp=52;
      break;
    case 26:
      hp=53;
      break;
    case 27:
      hp=54;
      break;
    case 28:
      hp=55;
      break;
    case 29:
      hp=56;
      break;
    case 30:
      hp=57;
      break;
    case 31:
      hp=58;
      break;
    case 32:
      hp=59;
      break;
    case 33:
      hp=60;
      break;
    case 34:
      hp=61;
      break;
    case 35:
      hp=62;
      break;
    case 36:
      hp=63;
      break;
    case 37:
      hp=64;
      break;
    case 38:
      hp=65;
      break;
    case 39:
      hp=66;
      break;
    case 40:
      hp=67;
      break;
    case 41:
      hp=68;
      break;
    case 42:
      hp=69;
      break;
    case 43:
      hp=70;
      break;
    case 44:
      hp=71;
      break;
    case 45:
      hp=72;
      break;
    case 46:
      hp=73;
      break;
    case 47:
      hp=74;
      break;
    case 48:
      hp=75;
      break;
    case 49:
      hp=76;
      break;
    case 50:
      hp=77;
      break;
    case 51:
      hp=78;
      break;
    case 52:
      hp=79;
      break;
    case 53:
      hp=80;
      break;
    case 54:
      hp=81;
      break;
    case 55:
      hp=82;
      break;
    case 56:
      hp=83;
      break;
    case 57:
      hp=84;
      break;
    case 58:
      hp=85;
      break;
    case 59:
      hp=86;
      break;
    case 60:
      hp=86;
      break;
    case 61:
      hp=86;
      break;
    case 62:
      hp=86;
      break;
    case 63:
      hp=86;
      break;
    case 64:
      hp=86;
      break;
    case 65:
      hp=86;
      break;
    case 66:
      hp=86;
      break;
    case 67:
      hp=86;
      break;
    case 68:
      hp=86;
      break;
    case 69:
      hp=86;
      break;
    case 70:
      hp=86;
      break;
    case 71:
      hp=86;
      break;
    case 72:
      hp=86;
      break;
    case 73:
      hp=86;
      break;
    case 74:
      hp=86;
      break;
    case 75:
      hp=86;
      break;
    case 76:
      hp=86;
      break;
    case 77:
      hp=86;
      break;
    case 78:
      hp=86;
      break;
    case 79:
      hp=86;
      break;
    case 80:
      hp=86;
      break;
    case 81:
      hp=86;
      break;
    case 82:
      hp=86;
      break;
    case 83:
      hp=86;
      break;
    case 84:
      hp=86;
      break;
    case 85:
      hp=86;
      break;
    case 86:
      hp=86;
      break;
    case 87:
      hp=86;
      break;
    case 88:
      hp=86;
      break;
    case 89:
      hp=86;
      break;
    case 90:
      hp=86;
      break;
    case 91:
      hp=86;
      break;
    case 92:
      hp=86;
      break;
    case 93:
      hp=86;
      break;
    case 94:
      hp=86;
      break;
    case 95:
      hp=86;
      break;
    case 96:
      hp=86;
      break;
    case 97:
      hp=86;
      break;
    case 98:
      hp=86;
      break;
    case 99:
      hp=86;
      break;
  }
  return hp;
}

int at6(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int at;
  switch(lv){
    case 1:
      at=0;
      break;
    case 2:
      at=2;
      break;
    case 3:
      at=4;
      break;
    case 4:
      at=6;
      break;
    case 5:
      at=8;
      break;
    case 6:
      at=10;
      break;
    case 7:
      at=12;
      break;
    case 8:
      at=14;
      break;
    case 9:
      at=15;
      break;
    case 10:
      at=16;
      break;
    case 11:
      at=16;
      break;
    case 12:
      at=17;
      break;
    case 13:
      at=17;
      break;
    case 14:
      at=18;
      break;
    case 15:
      at=18;
      break;
    case 16:
      at=19;
      break;
    case 17:
      at=19;
      break;
    case 18:
      at=20;
      break;
    case 19:
      at=20;
      break;
    case 20:
      at=21;
      break;
    case 21:
      at=21;
      break;
    case 22:
      at=22;
      break;
    case 23:
      at=22;
      break;
    case 24:
      at=23;
      break;
    case 25:
      at=23;
      break;
    case 26:
      at=24;
      break;
    case 27:
      at=24;
      break;
    case 28:
      at=25;
      break;
    case 29:
      at=25;
      break;
    case 30:
      at=26;
      break;
    case 31:
      at=26;
      break;
    case 32:
      at=27;
      break;
    case 33:
      at=27;
      break;
    case 34:
      at=28;
      break;
    case 35:
      at=28;
      break;
    case 36:
      at=29;
      break;
    case 37:
      at=29;
      break;
    case 38:
      at=30;
      break;
    case 39:
      at=30;
      break;
    case 40:
      at=31;
      break;
    case 41:
      at=31;
      break;
    case 42:
      at=32;
      break;
    case 43:
      at=32;
      break;
    case 44:
      at=33;
      break;
    case 45:
      at=33;
      break;
    case 46:
      at=34;
      break;
    case 47:
      at=34;
      break;
    case 48:
      at=35;
      break;
    case 49:
      at=35;
      break;
    case 50:
      at=35;
      break;
    case 51:
      at=35;
      break;
    case 52:
      at=35;
      break;
    case 53:
      at=35;
      break;
    case 54:
      at=35;
      break;
    case 55:
      at=35;
      break;
    case 56:
      at=35;
      break;
    case 57:
      at=35;
      break;
    case 58:
      at=35;
      break;
    case 59:
      at=35;
      break;
    case 60:
      at=35;
      break;
    case 61:
      at=35;
      break;
    case 62:
      at=35;
      break;
    case 63:
      at=35;
      break;
    case 64:
      at=35;
      break;
    case 65:
      at=35;
      break;
    case 66:
      at=35;
      break;
    case 67:
      at=35;
      break;
    case 68:
      at=35;
      break;
    case 69:
      at=35;
      break;
    case 70:
      at=35;
      break;
    case 71:
      at=35;
      break;
    case 72:
      at=35;
      break;
    case 73:
      at=35;
      break;
    case 74:
      at=35;
      break;
    case 75:
      at=35;
      break;
    case 76:
      at=35;
      break;
    case 77:
      at=35;
      break;
    case 78:
      at=35;
      break;
    case 79:
      at=35;
      break;
    case 80:
      at=35;
      break;
    case 81:
      at=35;
      break;
    case 82:
      at=35;
      break;
    case 83:
      at=35;
      break;
    case 84:
      at=35;
      break;
    case 85:
      at=35;
      break;
    case 86:
      at=35;
      break;
    case 87:
      at=35;
      break;
    case 88:
      at=35;
      break;
    case 89:
      at=35;
      break;
    case 90:
      at=35;
      break;
    case 91:
      at=35;
      break;
    case 92:
      at=35;
      break;
    case 93:
      at=35;
      break;
    case 94:
      at=35;
      break;
    case 95:
      at=35;
      break;
    case 96:
      at=35;
      break;
    case 97:
      at=35;
      break;
    case 98:
      at=35;
      break;
    case 99:
      at=35;
      break;
  }
  return at;
}

int df6(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int df;
  switch(lv){
    case 1:
      df=0;
      break;
    case 2:
      df=6;
      break;
    case 3:
      df=11;
      break;
    case 4:
      df=15;
      break;
    case 5:
      df=18;
      break;
    case 6:
      df=21;
      break;
    case 7:
      df=23;
      break;
    case 8:
      df=25;
      break;
    case 9:
      df=27;
      break;
    case 10:
      df=29;
      break;
    case 11:
      df=31;
      break;
    case 12:
      df=33;
      break;
    case 13:
      df=35;
      break;
    case 14:
      df=37;
      break;
    case 15:
      df=39;
      break;
    case 16:
      df=41;
      break;
    case 17:
      df=43;
      break;
    case 18:
      df=45;
      break;
    case 19:
      df=47;
      break;
    case 20:
      df=48;
      break;
    case 21:
      df=49;
      break;
    case 22:
      df=50;
      break;
    case 23:
      df=51;
      break;
    case 24:
      df=52;
      break;
    case 25:
      df=53;
      break;
    case 26:
      df=54;
      break;
    case 27:
      df=55;
      break;
    case 28:
      df=56;
      break;
    case 29:
      df=57;
      break;
    case 30:
      df=58;
      break;
    case 31:
      df=59;
      break;
    case 32:
      df=60;
      break;
    case 33:
      df=61;
      break;
    case 34:
      df=62;
      break;
    case 35:
      df=63;
      break;
    case 36:
      df=64;
      break;
    case 37:
      df=65;
      break;
    case 38:
      df=66;
      break;
    case 39:
      df=67;
      break;
    case 40:
      df=68;
      break;
    case 41:
      df=69;
      break;
    case 42:
      df=70;
      break;
    case 43:
      df=71;
      break;
    case 44:
      df=72;
      break;
    case 45:
      df=73;
      break;
    case 46:
      df=74;
      break;
    case 47:
      df=75;
      break;
    case 48:
      df=76;
      break;
    case 49:
      df=77;
      break;
    case 50:
      df=78;
      break;
    case 51:
      df=79;
      break;
    case 52:
      df=80;
      break;
    case 53:
      df=81;
      break;
    case 54:
      df=82;
      break;
    case 55:
      df=83;
      break;
    case 56:
      df=84;
      break;
    case 57:
      df=85;
      break;
    case 58:
      df=86;
      break;
    case 59:
      df=87;
      break;
    case 60:
      df=88;
      break;
    case 61:
      df=90;
      break;
    case 62:
      df=92;
      break;
    case 63:
      df=94;
      break;
    case 64:
      df=96;
      break;
    case 65:
      df=98;
      break;
    case 66:
      df=100;
      break;
    case 67:
      df=102;
      break;
    case 68:
      df=104;
      break;
    case 69:
      df=106;
      break;
    case 70:
      df=108;
      break;
    case 71:
      df=110;
      break;
    case 72:
      df=112;
      break;
    case 73:
      df=114;
      break;
    case 74:
      df=116;
      break;
    case 75:
      df=118;
      break;
    case 76:
      df=120;
      break;
    case 77:
      df=122;
      break;
    case 78:
      df=124;
      break;
    case 79:
      df=126;
      break;
    case 80:
      df=127;
      break;
    case 81:
      df=129;
      break;
    case 82:
      df=130;
      break;
    case 83:
      df=132;
      break;
    case 84:
      df=133;
      break;
    case 85:
      df=135;
      break;
    case 86:
      df=136;
      break;
    case 87:
      df=138;
      break;
    case 88:
      df=139;
      break;
    case 89:
      df=141;
      break;
    case 90:
      df=142;
      break;
    case 91:
      df=144;
      break;
    case 92:
      df=145;
      break;
    case 93:
      df=147;
      break;
    case 94:
      df=148;
      break;
    case 95:
      df=150;
      break;
    case 96:
      df=151;
      break;
    case 97:
      df=153;
      break;
    case 98:
      df=154;
      break;
    case 99:
      df=158;
      break;
  }
  return df;
}

int hp7(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int hp;
  switch(lv){
    case 1:
      hp=0;
      break;
    case 2:
      hp=10;
      break;
    case 3:
      hp=15;
      break;
    case 4:
      hp=20;
      break;
    case 5:
      hp=25;
      break;
    case 6:
      hp=30;
      break;
    case 7:
      hp=35;
      break;
    case 8:
      hp=40;
      break;
    case 9:
      hp=45;
      break;
    case 10:
      hp=55;
      break;
    case 11:
      hp=55;
      break;
    case 12:
      hp=55;
      break;
    case 13:
      hp=55;
      break;
    case 14:
      hp=55;
      break;
    case 15:
      hp=55;
      break;
    case 16:
      hp=55;
      break;
    case 17:
      hp=55;
      break;
    case 18:
      hp=55;
      break;
    case 19:
      hp=55;
      break;
    case 20:
      hp=55;
      break;
    case 21:
      hp=55;
      break;
    case 22:
      hp=55;
      break;
    case 23:
      hp=55;
      break;
    case 24:
      hp=55;
      break;
    case 25:
      hp=55;
      break;
    case 26:
      hp=55;
      break;
    case 27:
      hp=55;
      break;
    case 28:
      hp=55;
      break;
    case 29:
      hp=55;
      break;
    case 30:
      hp=55;
      break;
    case 31:
      hp=55;
      break;
    case 32:
      hp=55;
      break;
    case 33:
      hp=55;
      break;
    case 34:
      hp=55;
      break;
    case 35:
      hp=55;
      break;
    case 36:
      hp=55;
      break;
    case 37:
      hp=55;
      break;
    case 38:
      hp=55;
      break;
    case 39:
      hp=55;
      break;
    case 40:
      hp=55;
      break;
    case 41:
      hp=55;
      break;
    case 42:
      hp=55;
      break;
    case 43:
      hp=55;
      break;
    case 44:
      hp=55;
      break;
    case 45:
      hp=55;
      break;
    case 46:
      hp=55;
      break;
    case 47:
      hp=55;
      break;
    case 48:
      hp=55;
      break;
    case 49:
      hp=55;
      break;
    case 50:
      hp=55;
      break;
    case 51:
      hp=55;
      break;
    case 52:
      hp=55;
      break;
    case 53:
      hp=55;
      break;
    case 54:
      hp=55;
      break;
    case 55:
      hp=55;
      break;
    case 56:
      hp=55;
      break;
    case 57:
      hp=55;
      break;
    case 58:
      hp=55;
      break;
    case 59:
      hp=55;
      break;
    case 60:
      hp=55;
      break;
    case 61:
      hp=55;
      break;
    case 62:
      hp=55;
      break;
    case 63:
      hp=55;
      break;
    case 64:
      hp=55;
      break;
    case 65:
      hp=55;
      break;
    case 66:
      hp=55;
      break;
    case 67:
      hp=55;
      break;
    case 68:
      hp=55;
      break;
    case 69:
      hp=55;
      break;
    case 70:
      hp=55;
      break;
    case 71:
      hp=55;
      break;
    case 72:
      hp=55;
      break;
    case 73:
      hp=55;
      break;
    case 74:
      hp=55;
      break;
    case 75:
      hp=55;
      break;
    case 76:
      hp=55;
      break;
    case 77:
      hp=55;
      break;
    case 78:
      hp=55;
      break;
    case 79:
      hp=55;
      break;
    case 80:
      hp=55;
      break;
    case 81:
      hp=55;
      break;
    case 82:
      hp=55;
      break;
    case 83:
      hp=55;
      break;
    case 84:
      hp=55;
      break;
    case 85:
      hp=55;
      break;
    case 86:
      hp=55;
      break;
    case 87:
      hp=55;
      break;
    case 88:
      hp=55;
      break;
    case 89:
      hp=55;
      break;
    case 90:
      hp=55;
      break;
    case 91:
      hp=55;
      break;
    case 92:
      hp=55;
      break;
    case 93:
      hp=55;
      break;
    case 94:
      hp=55;
      break;
    case 95:
      hp=55;
      break;
    case 96:
      hp=55;
      break;
    case 97:
      hp=55;
      break;
    case 98:
      hp=55;
      break;
    case 99:
      hp=55;
      break;
  }
  return hp;
}

int at7(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int at;
  switch(lv){
    case 1:
      at=0;
      break;
    case 2:
      at=70;
      break;
    case 3:
      at=140;
      break;
    case 4:
      at=200;
      break;
    case 5:
      at=260;
      break;
    case 6:
      at=310;
      break;
    case 7:
      at=360;
      break;
    case 8:
      at=410;
      break;
    case 9:
      at=460;
      break;
    case 10:
      at=510;
      break;
    case 11:
      at=515;
      break;
    case 12:
      at=519;
      break;
    case 13:
      at=522;
      break;
    case 14:
      at=524;
      break;
    case 15:
      at=526;
      break;
    case 16:
      at=528;
      break;
    case 17:
      at=530;
      break;
    case 18:
      at=532;
      break;
    case 19:
      at=534;
      break;
    case 20:
      at=536;
      break;
    case 21:
      at=538;
      break;
    case 22:
      at=540;
      break;
    case 23:
      at=542;
      break;
    case 24:
      at=544;
      break;
    case 25:
      at=546;
      break;
    case 26:
      at=548;
      break;
    case 27:
      at=550;
      break;
    case 28:
      at=552;
      break;
    case 29:
      at=554;
      break;
    case 30:
      at=556;
      break;
    case 31:
      at=558;
      break;
    case 32:
      at=560;
      break;
    case 33:
      at=562;
      break;
    case 34:
      at=564;
      break;
    case 35:
      at=566;
      break;
    case 36:
      at=568;
      break;
    case 37:
      at=570;
      break;
    case 38:
      at=572;
      break;
    case 39:
      at=574;
      break;
    case 40:
      at=576;
      break;
    case 41:
      at=578;
      break;
    case 42:
      at=580;
      break;
    case 43:
      at=582;
      break;
    case 44:
      at=584;
      break;
    case 45:
      at=586;
      break;
    case 46:
      at=588;
      break;
    case 47:
      at=590;
      break;
    case 48:
      at=592;
      break;
    case 49:
      at=594;
      break;
    case 50:
      at=595;
      break;
    case 51:
      at=596;
      break;
    case 52:
      at=597;
      break;
    case 53:
      at=598;
      break;
    case 54:
      at=599;
      break;
    case 55:
      at=600;
      break;
    case 56:
      at=601;
      break;
    case 57:
      at=602;
      break;
    case 58:
      at=603;
      break;
    case 59:
      at=604;
      break;
    case 60:
      at=605;
      break;
    case 61:
      at=606;
      break;
    case 62:
      at=607;
      break;
    case 63:
      at=608;
      break;
    case 64:
      at=609;
      break;
    case 65:
      at=610;
      break;
    case 66:
      at=611;
      break;
    case 67:
      at=612;
      break;
    case 68:
      at=613;
      break;
    case 69:
      at=614;
      break;
    case 70:
      at=615;
      break;
    case 71:
      at=616;
      break;
    case 72:
      at=617;
      break;
    case 73:
      at=618;
      break;
    case 74:
      at=619;
      break;
    case 75:
      at=620;
      break;
    case 76:
      at=621;
      break;
    case 77:
      at=622;
      break;
    case 78:
      at=623;
      break;
    case 79:
      at=624;
      break;
    case 80:
      at=625;
      break;
    case 81:
      at=626;
      break;
    case 82:
      at=627;
      break;
    case 83:
      at=628;
      break;
    case 84:
      at=629;
      break;
    case 85:
      at=630;
      break;
    case 86:
      at=631;
      break;
    case 87:
      at=632;
      break;
    case 88:
      at=633;
      break;
    case 89:
      at=634;
      break;
    case 90:
      at=635;
      break;
    case 91:
      at=636;
      break;
    case 92:
      at=637;
      break;
    case 93:
      at=638;
      break;
    case 94:
      at=639;
      break;
    case 95:
      at=640;
      break;
    case 96:
      at=641;
      break;
    case 97:
      at=642;
      break;
    case 98:
      at=643;
      break;
    case 99:
      at=644;
      break;
  }
  return at;
}

int df7(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int df;
  switch(lv){
    case 1:
      df=0;
      break;
    case 2:
      df=30;
      break;
    case 3:
      df=35;
      break;
    case 4:
      df=40;
      break;
    case 5:
      df=45;
      break;
    case 6:
      df=50;
      break;
    case 7:
      df=55;
      break;
    case 8:
      df=60;
      break;
    case 9:
      df=65;
      break;
    case 10:
      df=70;
      break;
    case 11:
      df=74;
      break;
    case 12:
      df=77;
      break;
    case 13:
      df=79;
      break;
    case 14:
      df=80;
      break;
    case 15:
      df=81;
      break;
    case 16:
      df=82;
      break;
    case 17:
      df=83;
      break;
    case 18:
      df=84;
      break;
    case 19:
      df=85;
      break;
    case 20:
      df=86;
      break;
    case 21:
      df=87;
      break;
    case 22:
      df=88;
      break;
    case 23:
      df=89;
      break;
    case 24:
      df=90;
      break;
    case 25:
      df=91;
      break;
    case 26:
      df=92;
      break;
    case 27:
      df=93;
      break;
    case 28:
      df=94;
      break;
    case 29:
      df=95;
      break;
    case 30:
      df=96;
      break;
    case 31:
      df=97;
      break;
    case 32:
      df=98;
      break;
    case 33:
      df=99;
      break;
    case 34:
      df=100;
      break;
    case 35:
      df=101;
      break;
    case 36:
      df=102;
      break;
    case 37:
      df=103;
      break;
    case 38:
      df=104;
      break;
    case 39:
      df=105;
      break;
    case 40:
      df=106;
      break;
    case 41:
      df=107;
      break;
    case 42:
      df=108;
      break;
    case 43:
      df=109;
      break;
    case 44:
      df=110;
      break;
    case 45:
      df=111;
      break;
    case 46:
      df=112;
      break;
    case 47:
      df=113;
      break;
    case 48:
      df=114;
      break;
    case 49:
      df=115;
      break;
    case 50:
      df=116;
      break;
    case 51:
      df=117;
      break;
    case 52:
      df=118;
      break;
    case 53:
      df=119;
      break;
    case 54:
      df=120;
      break;
    case 55:
      df=121;
      break;
    case 56:
      df=122;
      break;
    case 57:
      df=123;
      break;
    case 58:
      df=124;
      break;
    case 59:
      df=125;
      break;
    case 60:
      df=126;
      break;
    case 61:
      df=127;
      break;
    case 62:
      df=128;
      break;
    case 63:
      df=129;
      break;
    case 64:
      df=130;
      break;
    case 65:
      df=131;
      break;
    case 66:
      df=132;
      break;
    case 67:
      df=133;
      break;
    case 68:
      df=134;
      break;
    case 69:
      df=135;
      break;
    case 70:
      df=136;
      break;
    case 71:
      df=137;
      break;
    case 72:
      df=138;
      break;
    case 73:
      df=139;
      break;
    case 74:
      df=140;
      break;
    case 75:
      df=141;
      break;
    case 76:
      df=142;
      break;
    case 77:
      df=143;
      break;
    case 78:
      df=144;
      break;
    case 79:
      df=145;
      break;
    case 80:
      df=146;
      break;
    case 81:
      df=147;
      break;
    case 82:
      df=148;
      break;
    case 83:
      df=149;
      break;
    case 84:
      df=150;
      break;
    case 85:
      df=151;
      break;
    case 86:
      df=152;
      break;
    case 87:
      df=153;
      break;
    case 88:
      df=154;
      break;
    case 89:
      df=155;
      break;
    case 90:
      df=156;
      break;
    case 91:
      df=157;
      break;
    case 92:
      df=158;
      break;
    case 93:
      df=159;
      break;
    case 94:
      df=160;
      break;
    case 95:
      df=161;
      break;
    case 96:
      df=162;
      break;
    case 97:
      df=163;
      break;
    case 98:
      df=164;
      break;
    case 99:
      df=165;
      break;
  }
  return df;
}


int hp8(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int hp;
  switch(lv){
    case 1:
      hp=0;
      break;
    case 2:
      hp=0;
      break;
    case 3:
      hp=0;
      break;
    case 4:
      hp=0;
      break;
    case 5:
      hp=0;
      break;
    case 6:
      hp=0;
      break;
    case 7:
      hp=0;
      break;
    case 8:
      hp=0;
      break;
    case 9:
      hp=0;
      break;
    case 10:
      hp=0;
      break;
    case 11:
      hp=0;
      break;
    case 12:
      hp=0;
      break;
    case 13:
      hp=0;
      break;
    case 14:
      hp=0;
      break;
    case 15:
      hp=0;
      break;
    case 16:
      hp=0;
      break;
    case 17:
      hp=0;
      break;
    case 18:
      hp=0;
      break;
    case 19:
      hp=0;
      break;
    case 20:
      hp=0;
      break;
    case 21:
      hp=0;
      break;
    case 22:
      hp=0;
      break;
    case 23:
      hp=0;
      break;
    case 24:
      hp=0;
      break;
    case 25:
      hp=0;
      break;
    case 26:
      hp=0;
      break;
    case 27:
      hp=0;
      break;
    case 28:
      hp=0;
      break;
    case 29:
      hp=0;
      break;
    case 30:
      hp=0;
      break;
    case 31:
      hp=0;
      break;
    case 32:
      hp=0;
      break;
    case 33:
      hp=0;
      break;
    case 34:
      hp=0;
      break;
    case 35:
      hp=0;
      break;
    case 36:
      hp=0;
      break;
    case 37:
      hp=0;
      break;
    case 38:
      hp=0;
      break;
    case 39:
      hp=0;
      break;
    case 40:
      hp=0;
      break;
    case 41:
      hp=0;
      break;
    case 42:
      hp=0;
      break;
    case 43:
      hp=0;
      break;
    case 44:
      hp=0;
      break;
    case 45:
      hp=0;
      break;
    case 46:
      hp=0;
      break;
    case 47:
      hp=0;
      break;
    case 48:
      hp=0;
      break;
    case 49:
      hp=0;
      break;
    case 50:
      hp=0;
      break;
    case 51:
      hp=0;
      break;
    case 52:
      hp=0;
      break;
    case 53:
      hp=0;
      break;
    case 54:
      hp=0;
      break;
    case 55:
      hp=0;
      break;
    case 56:
      hp=0;
      break;
    case 57:
      hp=0;
      break;
    case 58:
      hp=0;
      break;
    case 59:
      hp=0;
      break;
    case 60:
      hp=0;
      break;
    case 61:
      hp=0;
      break;
    case 62:
      hp=0;
      break;
    case 63:
      hp=0;
      break;
    case 64:
      hp=0;
      break;
    case 65:
      hp=0;
      break;
    case 66:
      hp=0;
      break;
    case 67:
      hp=0;
      break;
    case 68:
      hp=0;
      break;
    case 69:
      hp=0;
      break;
    case 70:
      hp=0;
      break;
    case 71:
      hp=0;
      break;
    case 72:
      hp=0;
      break;
    case 73:
      hp=0;
      break;
    case 74:
      hp=0;
      break;
    case 75:
      hp=0;
      break;
    case 76:
      hp=0;
      break;
    case 77:
      hp=0;
      break;
    case 78:
      hp=0;
      break;
    case 79:
      hp=0;
      break;
    case 80:
      hp=0;
      break;
    case 81:
      hp=0;
      break;
    case 82:
      hp=0;
      break;
    case 83:
      hp=0;
      break;
    case 84:
      hp=0;
      break;
    case 85:
      hp=0;
      break;
    case 86:
      hp=0;
      break;
    case 87:
      hp=0;
      break;
    case 88:
      hp=0;
      break;
    case 89:
      hp=0;
      break;
    case 90:
      hp=0;
      break;
    case 91:
      hp=0;
      break;
    case 92:
      hp=0;
      break;
    case 93:
      hp=0;
      break;
    case 94:
      hp=0;
      break;
    case 95:
      hp=0;
      break;
    case 96:
      hp=0;
      break;
    case 97:
      hp=0;
      break;
    case 98:
      hp=0;
      break;
    case 99:
      hp=0;
      break;
  }
  return hp;
}

int at8(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int at;
  switch(lv){
    case 1:
      at=0;
      break;
    case 2:
      at=0;
      break;
    case 3:
      at=0;
      break;
    case 4:
      at=0;
      break;
    case 5:
      at=0;
      break;
    case 6:
      at=0;
      break;
    case 7:
      at=0;
      break;
    case 8:
      at=0;
      break;
    case 9:
      at=0;
      break;
    case 10:
      at=0;
      break;
    case 11:
      at=0;
      break;
    case 12:
      at=0;
      break;
    case 13:
      at=0;
      break;
    case 14:
      at=0;
      break;
    case 15:
      at=0;
      break;
    case 16:
      at=0;
      break;
    case 17:
      at=0;
      break;
    case 18:
      at=0;
      break;
    case 19:
      at=0;
      break;
    case 20:
      at=0;
      break;
    case 21:
      at=0;
      break;
    case 22:
      at=0;
      break;
    case 23:
      at=0;
      break;
    case 24:
      at=0;
      break;
    case 25:
      at=0;
      break;
    case 26:
      at=0;
      break;
    case 27:
      at=0;
      break;
    case 28:
      at=0;
      break;
    case 29:
      at=0;
      break;
    case 30:
      at=0;
      break;
    case 31:
      at=0;
      break;
    case 32:
      at=0;
      break;
    case 33:
      at=0;
      break;
    case 34:
      at=0;
      break;
    case 35:
      at=0;
      break;
    case 36:
      at=0;
      break;
    case 37:
      at=0;
      break;
    case 38:
      at=0;
      break;
    case 39:
      at=0;
      break;
    case 40:
      at=0;
      break;
    case 41:
      at=0;
      break;
    case 42:
      at=0;
      break;
    case 43:
      at=0;
      break;
    case 44:
      at=0;
      break;
    case 45:
      at=0;
      break;
    case 46:
      at=0;
      break;
    case 47:
      at=0;
      break;
    case 48:
      at=0;
      break;
    case 49:
      at=0;
      break;
    case 50:
      at=0;
      break;
    case 51:
      at=0;
      break;
    case 52:
      at=0;
      break;
    case 53:
      at=0;
      break;
    case 54:
      at=0;
      break;
    case 55:
      at=0;
      break;
    case 56:
      at=0;
      break;
    case 57:
      at=0;
      break;
    case 58:
      at=0;
      break;
    case 59:
      at=0;
      break;
    case 60:
      at=0;
      break;
    case 61:
      at=0;
      break;
    case 62:
      at=0;
      break;
    case 63:
      at=0;
      break;
    case 64:
      at=0;
      break;
    case 65:
      at=0;
      break;
    case 66:
      at=0;
      break;
    case 67:
      at=0;
      break;
    case 68:
      at=0;
      break;
    case 69:
      at=0;
      break;
    case 70:
      at=0;
      break;
    case 71:
      at=0;
      break;
    case 72:
      at=0;
      break;
    case 73:
      at=0;
      break;
    case 74:
      at=0;
      break;
    case 75:
      at=0;
      break;
    case 76:
      at=0;
      break;
    case 77:
      at=0;
      break;
    case 78:
      at=0;
      break;
    case 79:
      at=0;
      break;
    case 80:
      at=0;
      break;
    case 81:
      at=0;
      break;
    case 82:
      at=0;
      break;
    case 83:
      at=0;
      break;
    case 84:
      at=0;
      break;
    case 85:
      at=0;
      break;
    case 86:
      at=0;
      break;
    case 87:
      at=0;
      break;
    case 88:
      at=0;
      break;
    case 89:
      at=0;
      break;
    case 90:
      at=0;
      break;
    case 91:
      at=0;
      break;
    case 92:
      at=0;
      break;
    case 93:
      at=0;
      break;
    case 94:
      at=0;
      break;
    case 95:
      at=0;
      break;
    case 96:
      at=0;
      break;
    case 97:
      at=0;
      break;
    case 98:
      at=0;
      break;
    case 99:
      at=0;
      break;
  }
  return at;
}

int df8(int lv){
  if(lv<0 || lv>99) {
    std::cout << "レベルの値が不正です" << std::endl;
    exit(1);
  }
  int df;
  switch(lv){
    case 1:
      df=0;
      break;
    case 2:
      df=3;
      break;
    case 3:
      df=6;
      break;
    case 4:
      df=9;
      break;
    case 5:
      df=12;
      break;
    case 6:
      df=15;
      break;
    case 7:
      df=18;
      break;
    case 8:
      df=21;
      break;
    case 9:
      df=24;
      break;
    case 10:
      df=26;
      break;
    case 11:
      df=28;
      break;
    case 12:
      df=30;
      break;
    case 13:
      df=32;
      break;
    case 14:
      df=34;
      break;
    case 15:
      df=36;
      break;
    case 16:
      df=38;
      break;
    case 17:
      df=40;
      break;
    case 18:
      df=42;
      break;
    case 19:
      df=44;
      break;
    case 20:
      df=46;
      break;
    case 21:
      df=48;
      break;
    case 22:
      df=50;
      break;
    case 23:
      df=52;
      break;
    case 24:
      df=54;
      break;
    case 25:
      df=56;
      break;
    case 26:
      df=58;
      break;
    case 27:
      df=60;
      break;
    case 28:
      df=62;
      break;
    case 29:
      df=64;
      break;
    case 30:
      df=66;
      break;
    case 31:
      df=68;
      break;
    case 32:
      df=70;
      break;
    case 33:
      df=72;
      break;
    case 34:
      df=74;
      break;
    case 35:
      df=76;
      break;
    case 36:
      df=78;
      break;
    case 37:
      df=80;
      break;
    case 38:
      df=82;
      break;
    case 39:
      df=84;
      break;
    case 40:
      df=86;
      break;
    case 41:
      df=88;
      break;
    case 42:
      df=90;
      break;
    case 43:
      df=92;
      break;
    case 44:
      df=94;
      break;
    case 45:
      df=96;
      break;
    case 46:
      df=98;
      break;
    case 47:
      df=100;
      break;
    case 48:
      df=102;
      break;
    case 49:
      df=104;
      break;
    case 50:
      df=106;
      break;
    case 51:
      df=108;
      break;
    case 52:
      df=110;
      break;
    case 53:
      df=112;
      break;
    case 54:
      df=114;
      break;
    case 55:
      df=116;
      break;
    case 56:
      df=118;
      break;
    case 57:
      df=120;
      break;
    case 58:
      df=122;
      break;
    case 59:
      df=124;
      break;
    case 60:
      df=126;
      break;
    case 61:
      df=128;
      break;
    case 62:
      df=130;
      break;
    case 63:
      df=132;
      break;
    case 64:
      df=134;
      break;
    case 65:
      df=136;
      break;
    case 66:
      df=138;
      break;
    case 67:
      df=140;
      break;
    case 68:
      df=142;
      break;
    case 69:
      df=144;
      break;
    case 70:
      df=146;
      break;
    case 71:
      df=148;
      break;
    case 72:
      df=150;
      break;
    case 73:
      df=152;
      break;
    case 74:
      df=154;
      break;
    case 75:
      df=156;
      break;
    case 76:
      df=158;
      break;
    case 77:
      df=160;
      break;
    case 78:
      df=162;
      break;
    case 79:
      df=164;
      break;
    case 80:
      df=166;
      break;
    case 81:
      df=168;
      break;
    case 82:
      df=170;
      break;
    case 83:
      df=172;
      break;
    case 84:
      df=174;
      break;
    case 85:
      df=176;
      break;
    case 86:
      df=178;
      break;
    case 87:
      df=180;
      break;
    case 88:
      df=182;
      break;
    case 89:
      df=184;
      break;
    case 90:
      df=186;
      break;
    case 91:
      df=188;
      break;
    case 92:
      df=190;
      break;
    case 93:
      df=192;
      break;
    case 94:
      df=194;
      break;
    case 95:
      df=196;
      break;
    case 96:
      df=198;
      break;
    case 97:
      df=200;
      break;
    case 98:
      df=202;
      break;
    case 99:
      df=204;
      break;
  }
  return df;
}

int GetREC(int sp){
  int rec;
  switch(sp/100){
    case 1:
      switch(sp%100){
        case 1:
          rec=50;
          break;
        case 2:
          rec=50;
          break;
        case 3:
          rec=50;
          break;
        case 4:
          rec=100;
          break;
        case 5:
          rec=50;
          break;
        case 6:
          rec=50;
          break;
        case 7:
          rec=50;
          break;
        case 8:
          rec=50;
          break;
        case 9:
          rec=50;
          break;
        case 10:
          rec=100;
          break;
        case 11:
          rec=50;
          break;
        case 12:
          rec=100;
          break;
        case 13:
          rec=50;
          break;
        case 14:
          rec=50;
          break;
        case 15:
          rec=100;
          break;
        case 16:
          rec=50;
          break;
        case 17:
          rec=50;
          break;
        case 18:
          rec=50;
          break;
        case 19:
          rec=100;
          break;
        case 20:
          rec=50;
          break;
        case 21:
          rec=50;
          break;
        case 22:
          rec=50;
          break;
        case 23:
          rec=50;
          break;
        case 24:
          rec=100;
          break;
      }
      break;
    case 2:
      switch(sp%100){
        case 1:
          rec=100;
          break;
        case 2:
          rec=30;
          break;
        case 3:
          rec=50;
          break;
        case 4:
          rec=50;
          break;
        case 5:
          rec=30;
          break;
        case 6:
          rec=50;
          break;
        case 7:
          rec=100;
          break;
        case 8:
          rec=100;
          break;
        case 9:
          rec=100;
          break;
        case 10:
          rec=50;
          break;
        case 11:
          rec=50;
          break;
        case 12:
          rec=50;
          break;
        case 13:
          rec=50;
          break;
      }
      break;
    case 3:
      switch(sp%100){
        case 1:
          rec=50;
          break;
        case 2:
          rec=50;
          break;
        case 3:
          rec=50;
          break;
        case 4:
          rec=50;
          break;
        case 5:
          rec=50;
          break;
        case 6:
          rec=50;
          break;
        case 7:
          rec=50;
          break;
        case 8:
          rec=50;
          break;
        case 9:
          rec=100;
          break;
        case 10:
          rec=100;
          break;
        case 11:
          rec=100;
          break;
        case 12:
          rec=50;
          break;
        case 13:
          rec=50;
          break;
        case 14:
          rec=100;
          break;
        case 15:
          rec=100;
          break;
        case 16:
          rec=50;
          break;
        case 17:
          rec=50;
          break;
        case 18:
          rec=50;
          break;
        case 19:
          rec=50;
          break;
        case 20:
          rec=50;
          break;
        case 21:
          rec=50;
          break;
        case 22:
          rec=50;
          break;
        case 23:
          rec=50;
          break;
        case 24:
          rec=150;
          break;
        case 25:
          rec=50;
          break;
        case 26:
          rec=50;
          break;
        case 27:
          rec=50;
          break;
        case 28:
          rec=50;
          break;
        case 29:
          rec=50;
          break;
        case 30:
          rec=50;
          break;
        case 31:
          rec=50;
          break;
        case 32:
          rec=50;
          break;
        case 33:
          rec=50;
          break;
        case 34:
          rec=50;
          break;
        case 35:
          rec=50;
          break;
        case 36:
          rec=50;
          break;
        case 37:
          rec=100;
          break;
        case 38:
          rec=50;
          break;
        case 39:
          rec=50;
          break;
        case 40:
          rec=50;
          break;
        case 41:
          rec=50;
          break;
      }
      break;
    case 4:
      switch(sp%100){
        case 1:
          rec=100;
          break;
        case 2:
          rec=50;
          break;
        case 3:
          rec=50;
          break;
        case 4:
          rec=100;
          break;
        case 5:
          rec=100;
          break;
        case 6:
          rec=100;
          break;
      }
      break;
    case 5:
      switch(sp%100){
        case 1:
          rec=50;
          break;
        case 2:
          rec=100;
          break;
        case 3:
          rec=100;
          break;
        case 4:
          rec=50;
          break;
        case 5:
          rec=50;
          break;
        case 6:
          rec=50;
          break;
        case 7:
          rec=100;
          break;
        case 8:
          rec=100;
          break;
        case 9:
          rec=50;
          break;
        case 10:
          rec=100;
          break;
        case 11:
          rec=50;
          break;
        case 12:
          rec=50;
          break;
        case 13:
          rec=100;
          break;
        case 14:
          rec=50;
          break;
        case 15:
          rec=100;
          break;
      }
      break;
    case 6:
      switch(sp%100){
        case 1:
          rec=50;
          break;
        case 2:
          rec=150;
          break;
        case 3:
          rec=50;
          break;
        case 4:
          rec=50;
          break;
        case 5:
          rec=50;
          break;
        case 6:
          rec=50;
          break;
        case 7:
          rec=50;
          break;
        case 8:
          rec=100;
          break;
        case 9:
          rec=50;
          break;
        case 10:
          rec=50;
          break;
        case 11:
          rec=100;
          break;
        case 12:
          rec=100;
          break;
        case 13:
          rec=100;
          break;
        case 14:
          rec=50;
          break;
        case 15:
          rec=50;
          break;
        case 16:
          rec=50;
          break;
        case 17:
          rec=50;
          break;
        case 18:
          rec=50;
          break;
        case 19:
          rec=50;
          break;
        case 20:
          rec=100;
          break;
        case 21:
          rec=100;
          break;
        case 22:
          rec=50;
          break;
        case 23:
          rec=50;
          break;
        case 24:
          rec=50;
          break;
        case 25:
          rec=100;
          break;
        case 26:
          rec=50;
          break;
        case 27:
          rec=50;
          break;
        case 28:
          rec=50;
          break;
        case 29:
          rec=100;
          break;
        case 30:
          rec=50;
          break;
        case 31:
          rec=50;
          break;
        case 32:
          rec=100;
          break;
        case 33:
          rec=100;
          break;
        case 34:
          rec=50;
          break;
        case 35:
          rec=100;
          break;
        case 36:
          rec=50;
          break;
        case 37:
          rec=100;
          break;
        case 38:
          rec=50;
          break;
        case 39:
          rec=50;
          break;
        case 40:
          rec=100;
          break;
        case 41:
          rec=50;
          break;
        case 42:
          rec=150;
          break;
        case 43:
          rec=50;
          break;
        case 44:
          rec=50;
          break;
        case 45:
          rec=50;
          break;
        case 46:
          rec=50;
          break;
        case 47:
          rec=100;
          break;
        case 48:
          rec=50;
          break;
        case 49:
          rec=50;
          break;
        case 50:
          rec=50;
          break;
        case 51:
          rec=50;
          break;
        case 52:
          rec=50;
          break;
        case 53:
          rec=50;
          break;
        case 54:
          rec=50;
          break;
        case 55:
          rec=100;
          break;
        case 56:
          rec=50;
          break;
        case 57:
          rec=50;
          break;
        case 58:
          rec=50;
          break;
        case 59:
          rec=50;
          break;
        case 60:
          rec=50;
          break;
        case 61:
          rec=100;
          break;
      }
      break;
    case 7:
      switch(sp%100){
        case 1:
          rec=100;
          break;
        case 2:
          rec=100;
          break;
        case 3:
          rec=100;
          break;
        case 4:
          rec=100;
          break;
        case 5:
          rec=50;
          break;
        case 6:
          rec=100;
          break;
        case 7:
          rec=150;
          break;
        case 8:
          rec=100;
          break;
        case 9:
          rec=100;
          break;
        case 10:
          rec=100;
          break;
      }
      break;
    case 8:
      switch(sp%100){
        case 1:
          rec=50;
          break;
        case 2:
          rec=50;
          break;
        case 3:
          rec=150;
          break;
        case 4:
          rec=50;
          break;
        case 5:
          rec=50;
          break;
        case 6:
          rec=50;
          break;
        case 7:
          rec=100;
          break;
        case 8:
          rec=50;
          break;
        case 9:
          rec=100;
          break;
        case 10:
          rec=150;
          break;
        case 11:
          rec=50;
          break;
        case 12:
          rec=100;
          break;
        case 13:
          rec=30;
          break;
        case 14:
          rec=100;
          break;
        case 15:
          rec=50;
          break;
        case 16:
          rec=50;
          break;
      }
      break;
  }
  return rec;
}

std::string GetName(int sp) {
  switch(sp) {
    case 101:
      return "いたずらもぐら";
      break;
    case 102:
      return "がいこつけんし";
      break;
    case 103:
      return "かげのきし";
      break;
    case 104:
      return "キラースター";
      break;
    case 105:
      return "グール";
      break;
    case 106:
      return "くさった死体";
      break;
    case 107:
      return "しりょうのきし";
      break;
    case 108:
      return "スライム";
      break;
    case 109:
      return "スライムベス";
      break;
    case 110:
      return "スライムベホマズン";
      break;
    case 111:
      return "タホドラキー";
      break;
    case 112:
      return "デビルアンカー";
      break;
    case 113:
      return "どくどくゾンビ";
      break;
    case 114:
      return "ドラキー";
      break;
    case 115:
      return "ドラキーマ";
      break;
    case 116:
      return "ハエまどう";
      break;
    case 117:
      return "ファイヤーケロッグ";
      break;
    case 118:
      return "ブラウニー";
      break;
    case 119:
      return "プラチナキング";
      break;
    case 120:
      return "ホイミスライム";
      break;
    case 121:
      return "メイジももんじゃ";
      break;
    case 122:
      return "ももんじゃ";
      break;
    case 123:
      return "リビングデッド";
      break;
    case 124:
      return "リビングハンマー";
      break;
    case 201:
      return "エリミネーター";
      break;
    case 202:
      return "キメラ";
      break;
    case 203:
      return "さつじんき";
      break;
    case 204:
      return "しにがみ";
      break;
    case 205:
      return "スターキメラ";
      break;
    case 206:
      return "スモールグール";
      break;
    case 207:
      return "デスストーカー";
      break;
    case 208:
      return "トロル";
      break;
    case 209:
      return "トロルボンバー";
      break;
    case 210:
      return "ベロベロ";
      break;
    case 211:
      return "マミー";
      break;
    case 212:
      return "ミイラおとこ";
      break;
    case 213:
      return "ゆうれい";
      break;
    case 301:
      return "アイアンタートル";
      break;
    case 302:
      return "あめふらし";
      break;
    case 303:
      return "アローインプ";
      break;
    case 304:
      return "あんこくつむり";
      break;
    case 305:
      return "岩とびあくま";
      break;
    case 306:
      return "エビルポット";
      break;
    case 307:
      return "おおナメクジ";
      break;
    case 308:
      return "おどる宝石";
      break;
    case 309:
      return "ガニラス";
      break;
    case 310:
      return "キラーマンティス";
      break;
    case 311:
      return "ぐんたいガニ";
      break;
    case 312:
      return "ケダモン";
      break;
    case 313:
      return "ゴースト";
      break;
    case 314:
      return "さそりかまきり";
      break;
    case 315:
      return "じごくのハサミ";
      break;
    case 316:
      return "しびれマイマイ";
      break;
    case 317:
      return "ストローマウス";
      break;
    case 318:
      return "スライムブレス";
      break;
    case 319:
      return "タッフペンギー";
      break;
    case 320:
      return "タマゴロン";
      break;
    case 321:
      return "ちゅうまじゅう";
      break;
    case 322:
      return "つかいま";
      break;
    case 323:
      return "つのうしがい";
      break;
    case 324:
      return "ドラゴスライム";
      break;
    case 325:
      return "ドラゴメタル";
      break;
    case 326:
      return "ドルイド";
      break;
    case 327:
      return "どろにんぎょう";
      break;
    case 328:
      return "バブルスライム";
      break;
    case 329:
      return "パペットマン";
      break;
    case 330:
      return "ファーラット";
      break;
    case 331:
      return "ベビーサタン";
      break;
    case 332:
      return "ヘルゴースト";
      break;
    case 333:
      return "マージスター";
      break;
    case 334:
      return "ミニデーモン";
      break;
    case 335:
      return "メイジキメラ";
      break;
    case 336:
      return "メガザルロック";
      break;
    case 337:
      return "メダパニシックル";
      break;
    case 338:
      return "メトロゴースト";
      break;
    case 339:
      return "ランドアーマー";
      break;
    case 340:
      return "リリパット";
      break;
    case 341:
      return "ワンダーエッグ";
      break;
    case 401:
      return "アークデーモン";
      break;
    case 402:
      return "ギガンテス";
      break;
    case 403:
      return "キラースコップ";
      break;
    case 404:
      return "グレイトホーン";
      break;
    case 405:
      return "ゴーレム";
      break;
    case 406:
      return "レノファイター";
      break;
    case 501:
      return "あくましんかん";
      break;
    case 502:
      return "うごくせきぞう";
      break;
    case 503:
      return "キースドラゴン";
      break;
    case 504:
      return "グレイトマーマン";
      break;
    case 505:
      return "じごくのつかい";
      break;
    case 506:
      return "スカイフロッグ";
      break;
    case 507:
      return "ストーンマン";
      break;
    case 508:
      return "ダースドラゴン";
      break;
    case 509:
      return "デーモントード";
      break;
    case 510:
      return "ドラゴン";
      break;
    case 511:
      return "バーサーカー";
      break;
    case 512:
      return "ひとくいばこ";
      break;
    case 513:
      return "ひょうがまじん";
      break;
    case 514:
      return "ミミック";
      break;
    case 515:
      return "ようがんまじん";
      break;
    case 601:
      return "アイアンアント";
      break;
    case 602:
      return "イエティ";
      break;
    case 603:
      return "いしにんぎょう";
      break;
    case 604:
      return "おおきづち";
      break;
    case 605:
      return "おおめだま";
      break;
    case 606:
      return "おばけキノコ";
      break;
    case 607:
      return "おばけヒトデ";
      break;
    case 608:
      return "ガーゴイル";
      break;
    case 609:
      return "きとうし";
      break;
    case 610:
      return "きめんどうし";
      break;
    case 611:
      return "キラーアーマー";
      break;
    case 612:
      return "キラープラスター";
      break;
    case 613:
      return "キラーマシン";
      break;
    case 614:
      return "ぐんたいアリ";
      break;
    case 615:
      return "げんじゅつし";
      break;
    case 616:
      return "コロヒーロー";
      break;
    case 617:
      return "コロファイター";
      break;
    case 618:
      return "コロプリースト";
      break;
    case 619:
      return "コロマージ";
      break;
    case 620:
      return "さまようよろい";
      break;
    case 621:
      return "じごくのよろい";
      break;
    case 622:
      return "しびれくらげ";
      break;
    case 623:
      return "シャーマン";
      break;
    case 624:
      return "シャドーナイト";
      break;
    case 625:
      return "シルバーデビル";
      break;
    case 626:
      return "スーパーテンツク";
      break;
    case 627:
      return "スペクテット";
      break;
    case 628:
      return "ゾンビマスター";
      break;
    case 629:
      return "だいまじん";
      break;
    case 630:
      return "だいまどう";
      break;
    case 631:
      return "ダンスキャロット";
      break;
    case 632:
      return "デスマシーン";
      break;
    case 633:
      return "デビルロード";
      break;
    case 634:
      return "テンツク";
      break;
    case 635:
      return "どぐう戦士";
      break;
    case 636:
      return "どくやずきん";
      break;
    case 637:
      return "ドッグスナイパー";
      break;
    case 638:
      return "ドラゴンキッズ";
      break;
    case 639:
      return "ばくだん岩";
      break;
    case 640:
      return "バズズ";
      break;
    case 641:
      return "はねせんにん";
      break;
    case 642:
      return "ビッグスロース";
      break;
    case 643:
      return "プチヒーロー";
      break;
    case 644:
      return "プチファイター";
      break;
    case 645:
      return "プチプリースト";
      break;
    case 646:
      return "プチマージ";
      break;
    case 647:
      return "フライングデビル";
      break;
    case 648:
      return "ベビーニュート";
      break;
    case 649:
      return "ベホマスライム";
      break;
    case 650:
      return "マージマタンゴ";
      break;
    case 651:
      return "マタンゴ";
      break;
    case 652:
      return "まどうし";
      break;
    case 653:
      return "マンドラゴラ";
      break;
    case 654:
      return "ミステリドール";
      break;
    case 655:
      return "メタルハンター";
      break;
    case 656:
      return "メラリザード";
      break;
    case 657:
      return "モシャスナイト";
      break;
    case 658:
      return "ようじゅつし";
      break;
    case 659:
      return "ラストテンツク";
      break;
    case 660:
      return "ラリホーアント";
      break;
    case 661:
      return "ランガー";
      break;
    case 701:
      return "アトラス";
      break;
    case 702:
      return "エビルエスターク";
      break;
    case 703:
      return "キングスライム";
      break;
    case 704:
      return "こうてつまじん";
      break;
    case 705:
      return "ゴールデンスライム";
      break;
    case 706:
      return "ゴールドマン";
      break;
    case 707:
      return "ジャスティス兄";
      break;
    case 708:
      return "スライムエンペラー";
      break;
    case 709:
      return "トロルキング";
      break;
    case 710:
      return "ベリアル";
      break;
    case 801:
      return "あやしいかげ";
      break;
    case 802:
      return "オニオーン";
      break;
    case 803:
      return "サンダーラット";
      break;
    case 804:
      return "シャドー";
      break;
    case 805:
      return "たまねぎマン";
      break;
    case 806:
      return "はぐれメタル";
      break;
    case 807:
      return "バブリン";
      break;
    case 808:
      return "はりせんもぐら";
      break;
    case 809:
      return "プヨンターゲット";
      break;
    case 810:
      return "プラズママウス";
      break;
    case 811:
      return "ブラッドハンド";
      break;
    case 812:
      return "ポムポムボム";
      break;
    case 813:
      return "マドハンド";
      break;
    case 814:
      return "メタルキング";
      break;
    case 815:
      return "メタルスライム";
      break;
    case 816:
      return "笑いぶくろ";
      break;
    default:
      std::cout << "モンスターの識別番号違うから。マジでそういうの困るからやめて。" << std::endl;
      exit(1);
      break;
  }
}
