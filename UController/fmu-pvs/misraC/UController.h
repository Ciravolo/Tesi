#ifndef _misraC_UController_
#define _misraC_UController_

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "misraC_basic_types.h"
#define TOLLERANCE 0.2
/**
 * operating modes
 */
typedef enum { X1 } Mode;

/**
 * state attributes
 */
typedef struct { 
    Mode mode;
    Mode previous_mode;
    float64_t beta; 
    float64_t k_beta; 
    float64_t k_v; 
    int32_t maneuver; 
    float64_t onDestinationOutput; 
    float64_t onDestinationInput; 
    float64_t phi; 
    float64_t rho; 
    float64_t servoLeft; 
    float64_t servoRight; 
    float64_t v; 
    float64_t w; 
    float64_t x; 
    float64_t xDesired; 
    float64_t y; 
    float64_t yDesired; 
} State;

/**
 * init function
 */
void init(State* st);

/**
 * triggers
 */
bool per_tick(State* st);
State* tick(State* st);


/**
 * leave/enter functions
 */
void enter(Mode m, State* st);
void leave(Mode m, State* st);

#endif
