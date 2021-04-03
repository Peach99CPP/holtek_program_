//
// Created by peachRJ on 2021/4/3.
//

#ifndef HOLTEK_TRACKER_H
#define HOLTEK_TRACKER_H

#include <stdbool.h>
#include "main.h"
int get_tracker_num(void);
extern bool tracker_on;
void tracker_set(bool if_on);
#endif //HOLTEK_TRACKER_H
