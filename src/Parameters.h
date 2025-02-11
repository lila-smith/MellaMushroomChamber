/*
  Copyright (c) 2022 FirstBuild
*/

#ifndef PARAMETERS_H
#define PARAMETERS_H

#define PARAMETER_LOG_LEVEL                         LogLevel_Verbose  // LogLevel_Debug, LogLevel_Verbose, LogLevel_Info, LogLevel_Off
// #define LIGHT_ENCODER_DIRECT

#define PARAMETER_MAX_ANALOG_OUTPUT                 (255)
#define PARAMETER_MIN_ANALOG_OUTPUT                 (0)
#define PARAMETER_APPLICATION_RUN_DELAY_MS          (100)
#define PARAMETER_APPLICATION_LOG_DELAY_MS          (1000)
#define PARAMETER_FAN_STALL_SPEED                   (20)

#define PARAMETER_HUMIDITY_MIN_SETPOINT             (50)
#define PARAMETER_HUMIDITY_MAX_SETPOINT             (90)
#define PARAMETER_HUMIDITY_PID_KP                   (float(5))
#define PARAMETER_HUMIDITY_PID_KI                   (float(0.2))
#define PARAMETER_HUMIDITY_PID_KD                   (float(0.001))
#define PARAMETER_HUMIDITY_ERROR_OFFSET             (18)
#define PARAMETER_HUMIDITY_MINIMUM_OUTPUT           (2 * PARAMETER_FAN_STALL_SPEED)

#define PARAMETER_AIR_EXCHANGE_MIN_SETPOINT         (0)
#define PARAMETER_AIR_EXCHANGE_MAX_SETPOINT         (100)
#define PARAMETER_AIR_EXCHANGE_FAN_MIN_OUTPUT       (2 * PARAMETER_FAN_STALL_SPEED)
#define PARAMETER_AIR_EXCHANGE_FAN_MAX_OUTPUT       (255)
#define PARAMETER_AIR_EXCHANGE_FAN_RAMP_STEP        (1)
#define PARAMETER_AIR_EXCHANGE_FAN_PERIOD_SEC       ((uint32_t)1800)
#define PARAMETER_AIR_EXCHANGE_FAN_DUTY_CYCLE       (100) // Should be a value between 0-100 representing the % duty cycle
#define PARAMETER_AIR_EXCHANGE_FAN_ON_DURATION_SEC  ((PARAMETER_AIR_EXCHANGE_FAN_PERIOD_SEC * PARAMETER_AIR_EXCHANGE_FAN_DUTY_CYCLE) / 100)
#define PARAMETER_AIR_EXCHANGE_FAN_OFF_DURATION_SEC ((PARAMETER_AIR_EXCHANGE_FAN_PERIOD_SEC * (100 - PARAMETER_AIR_EXCHANGE_FAN_DUTY_CYCLE)) / 100)

#define PARAMETER_LIGHTS_MIN_SETPOINT               (10)
#define PARAMETER_LIGHTS_MAX_SETPOINT               (255)
#define PARAMETER_LIGHTS_FAULT_BREATHE_PERIOD_MS    (10000)
#define PARAMETER_LIGHTS_HEARTBEAT_NORMAL_DELAY_MS  (1000)
#define PARAMETER_LIGHTS_HEARTBEAT_FAULT_DELAY_MS   (100)

#define PARAMETER_STEADYSTATE_FAULT_DELAY_SEC       (600)
#define PARAMETER_STARTUP_DELAY_SEC                 (1800)
#define PARAMETER_STARTUP_FAULT_DELAY_SEC           (PARAMETER_STARTUP_DELAY_SEC - PARAMETER_STEADYSTATE_FAULT_DELAY_SEC)

#define MS_PER_SEC                                  (1000)
#define SEC_PER_MIN                                 (60)
#define MIN_PER_HR                                  (60)
#define HRS_PER_DAY                                 (24)

#if (MS_PER_SEC % PARAMETER_APPLICATION_RUN_DELAY_MS) != 0
#error "ERROR: (MSEC_PER_SEC / PARAMETER_APPLICATION_RUN_DELAY_MS) must result in an integer"
#endif

#if (PARAMETER_STEADYSTATE_FAULT_DELAY_SEC > PARAMETER_STARTUP_DELAY_SEC)
#error "ERROR: PARAMETER_STEADYSTATE_FAULT_DELAY_SEC cannot be greater than PARAMETER_STARTUP_DELAY_SEC"
#endif

#endif   // PARAMETERS_H
