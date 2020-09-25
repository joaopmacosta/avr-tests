#ifndef SERVO_DRIVER_H_INCLUDED_
#define SERVO_DRIVER_H_INCLUDED_

// ISO C 99 headers.
#include <stdbool.h>

// AVR headers.
#include <avr/io.h>

#include "../../Inc/driver/io.h"

// This structure contains stepper motor's pins
typedef struct stepper_motor
{
  // A
  gpio_t a;
  // A'
  gpio_t a_;
  // B
  gpio_t b;
  // B'
  gpio_t b_;
  // phase
  int stp_ph;
} stepper_motor_t;

int step_phase[8][4]{
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}};

int microstep_phase[8][4]{
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}};

#define STEPPER_CFG_START(servo, name, val) servo_cfg_start(servo, &name##_PORT, name##_PIN, val)

#define SERVO_START(servo) servo_start(servo)
#define SERVO_STOP(servo) servo_stop(servo)
#define SERVO_BRAKE(servo) servo_brake(servo)
#define SERVO_RUN(servo) servo_run(servo)

void servo_cfg_start(servo_motor_t servo, PORT_t *port, uint8_t pin, bool value);

void servo_cfg_brake(servo_motor_t servo, PORT_t *port, uint8_t pin, bool value);

void servo_cfg_alarm_in(servo_motor_t servo, PORT_t *port, uint8_t pin);

void servo_cfg_alarm_out(servo_motor_t servo, PORT_t *port, uint8_t pin, bool value);

void servo_cfg_speed_in(servo_motor_t servo, PORT_t *port, uint8_t pin);

void servo_cfg_speed_out(servo_motor_t servo, PORT_t *port, uint8_t pin, bool value);

void servo_start(servo_motor_t servo);

void servo_stop(servo_motor_t servo);

void servo_brake(servo_motor_t servo);

void servo_run(servo_motor_t servo);

#endif //SERVO_DRIVER_H_