/*
* PID.h contains a basic PID controller implementation that can be used in
* any circumstance with no modifications
*
* Basic Usage:
*   // Initialization
*   PID_s pid;
*   PID_init(&pid, 10, 0.1, 0.5, &error, 10e-3);
*
*   // Control Loop
*   output = PID_compute(&pid, millis());
*
* Made by: Christodoulos Sotiriou
*/
#ifndef PID_H
#define	PID_H

struct PID_s {
    float coeff_P, coeff_I, coeff_D;
    float last_error, *error;
    float integral;

    float last_pid;

    float dt;
    unsigned long int last_compute;
};

void PID_init(PID_s *pid, float P, float I, float D, float *error, float dt) {
    pid->coeff_P = P;
    pid->coeff_I = I;
    pid->coeff_D = D;

    pid->integral = 0;
    
    pid->dt = dt;
    pid->last_compute = 0;

    pid->last_error = 0;
    pid->error = error;
}
void PID_init(PID_s *pid, float P, float I, float D, float *error) {
    PID_init(pid, P, I, D, error, 5e-3);
}

float PID_compute(PID_s *pid, unsigned long int  current_time_ms) {
    float output = pid->last_pid;
    if (current_time_ms - pid->last_compute > pid->dt) {
        output = *pid->error * pid->coeff_P + 
                pid->integral * pid->coeff_I +
                (( *pid->error - pid->last_error ) / pid->dt) * pid->coeff_D;

        pid->last_compute = current_time_ms;
    }

    pid->integral += *pid->error;
    pid->last_pid = output;
    return output;
}

#endif