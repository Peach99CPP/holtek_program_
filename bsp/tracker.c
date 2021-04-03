//
// Created by peachRJ on 2021/4/3.
//

#include "tracker.h"
int weight[4]={-2,-1,1,2};
bool tracker_on;
int get_tracker_num(void)
{
    if(tracker_on) {
        int result = 0;
        result += weight[0] * (HAL_GPIO_ReadPin(tracker_1_GPIO_Port, tracker_1_Pin));
        result += weight[1] * (HAL_GPIO_ReadPin(tracker_2_GPIO_Port, tracker_2_Pin));
        result += weight[2] * (HAL_GPIO_ReadPin(tracker_3_GPIO_Port, tracker_3_Pin));
        result += weight[3] * (HAL_GPIO_ReadPin(tracker_4_GPIO_Port, tracker_4_Pin));
        return result;
    }
    else return 0;
}
void tracker_set(bool if_on)//是否使用循迹
{
    tracker_on=if_on;
}

