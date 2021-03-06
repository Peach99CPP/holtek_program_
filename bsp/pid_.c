//
// Created by peachRJ on 2021/4/3.
//

#include "pid_.h"
#include <string.h>
#define LimitMax(input, max) {  \
  if (input > max) {            \
    input = max;                \
  } else if (input < -max) {    \
    input = -max;               \
  }                             \
}                               \

void PID_init(pid_type_def *pid, PID_MODE mode, const float PID[3], float max_out, float max_iout) {
    if (pid == NULL || PID == NULL) {
        return;
    }
    pid->mode = mode;
    pid->kp_ = PID[0];
    pid->ki_ = PID[1];
    pid->kd_ = PID[2];

    pid->Pout_ = 0.0f;
    pid->Iout_ = 0.0f;
    pid->Dout_ = 0.0f;

    pid->max_out_ = max_out;
    pid->max_iout_ = max_iout;
    memset(pid->Dbuf_, 0, sizeof(pid->Dbuf_));
    memset(pid->error_, 0, sizeof(pid->error_));
}

float PID_cal(pid_type_def *pid, float ref, float set) {
    if (pid == NULL) {
        return 0.0f;
    }

    pid->error_[2] = pid->error_[1];
    pid->error_[1] = pid->error_[0];

    pid->error_[0] = set-ref;

    if (pid->mode == PID_POSITION) {
        pid->Pout_ = pid->kp_ * pid->error_[0];
        pid->Iout_ += pid->ki_ * pid->error_[0];
        pid->Dbuf_[2] = pid->Dbuf_[1];
        pid->Dbuf_[1] = pid->Dbuf_[0];
        pid->Dbuf_[0] = (pid->error_[0] - pid->error_[1]);
        pid->Dout_ = pid->kd_ * pid->Dbuf_[0];
        LimitMax(pid->Iout_, pid->max_iout_);
        pid->out_ = pid->Pout_ + pid->Iout_ + pid->Dout_;
        LimitMax(pid->out_, pid->max_out_);
    }
    else if (pid->mode == PID_DELTA) {
        pid->Pout_ = pid->kp_ * (pid->error_[0] - pid->error_[1]);
        pid->Iout_ = pid->ki_ * pid->error_[0];
        pid->Dbuf_[2] = pid->Dbuf_[1];
        pid->Dbuf_[1] = pid->Dbuf_[0];
        pid->Dbuf_[0] = (pid->error_[0] - 2.0f * pid->error_[1] + pid->error_[2]);
        pid->Dout_ = pid->kd_ * pid->Dbuf_[0];
        pid->out_ += pid->Pout_ + pid->Iout_ + pid->Dout_;
        LimitMax(pid->out_, pid->max_out_);
    }
    return pid->out_;
}

void PID_clear(pid_type_def *pid) {
    if (pid == NULL) {
        return;
    }
    memset(pid->error_, 0, sizeof(pid->error_));
    memset(pid->Dbuf_, 0, sizeof(pid->Dbuf_));
    pid->Pout_ = pid->Iout_ = pid->Dout_ = 0.0f;
    pid->out_ = 0.0f;
    pid->ref_ = pid->set_ = 0.0f;
}
pid_type_def motor_[2],tracker_;
void Global_Pid_Init()
{
    PID_clear(&motor_[0]);
    PID_clear(&motor_[1]);
    PID_clear(&tracker_);
    static const float Tracker_PID[3]={8.0f,0,0};
    static const float Motor_PID[3]={10.0f,10,0};
    static const float Motor_PID_se[3]={10.0f,10,0};
    PID_init(&motor_[0],PID_DELTA,Motor_PID_se,7000,0);
    PID_init(&motor_[1],PID_DELTA,Motor_PID,7000,0);
    PID_init(&tracker_,PID_POSITION,Tracker_PID,40,10);
}