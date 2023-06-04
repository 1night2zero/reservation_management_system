//
// Created by asus on 2023/6/4.
//

#include "Attraction.h"

Attraction::Attraction() = default;


Attraction::Attraction(string name, int day, int aorp, int maxNum, int Had[2][2]) {
    this->attractionsName = name;
    this->day = day;
    this->aorp = aorp;
    this->maxNum = maxNum;
    this->Had[0][0] = Had[0][0];
    this->Had[0][1] = Had[0][1];
    this->Had[1][0] = Had[1][0];
    this->Had[1][1] = Had[1][1];
}
