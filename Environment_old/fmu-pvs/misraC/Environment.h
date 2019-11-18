#ifndef _misraC_Environment_
#define _misraC_Environment_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "misraC_basic_types.h"
#define S_RANGE 1
#define ERTU_PERC 0.2
#define MAX_PH 2
#define PHI 1
#define LAMBDA 1
#define ETA 0.9
#define A1 0.5
#define A2 0.5
#define STEP 1
#define ROBOTS 4
#define MAP_SIZE 10

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
		int32_t stepCount;
		int32_t port;
		float64_t time;
		float64_t tickSize;
		float64_t dummy;
		float64_t cell1_1; //-- real
		float64_t cell1_10; //-- real
		float64_t cell1_2; //-- real
		float64_t cell1_3; //-- real
		float64_t cell1_4; //-- real
		float64_t cell1_5; //-- real
		float64_t cell1_6; //-- real
		float64_t cell1_7; //-- real
		float64_t cell1_8; //-- real
		float64_t cell1_9; //-- real
		float64_t cell10_1; //-- real
		float64_t cell10_10; //-- real
		float64_t cell10_2; //-- real
		float64_t cell10_3; //-- real
		float64_t cell10_4; //-- real
		float64_t cell10_5; //-- real
		float64_t cell10_6; //-- real
		float64_t cell10_7; //-- real
		float64_t cell10_8; //-- real
		float64_t cell10_9; //-- real
		float64_t cell2_1; //-- real
		float64_t cell2_10; //-- real
		float64_t cell2_2; //-- real
		float64_t cell2_3; //-- real
		float64_t cell2_4; //-- real
		float64_t cell2_5; //-- real
		float64_t cell2_6; //-- real
		float64_t cell2_7; //-- real
		float64_t cell2_8; //-- real
		float64_t cell2_9; //-- real
		float64_t cell3_1; //-- real
		float64_t cell3_10; //-- real
		float64_t cell3_2; //-- real
		float64_t cell3_3; //-- real
		float64_t cell3_4; //-- real
		float64_t cell3_5; //-- real
		float64_t cell3_6; //-- real
		float64_t cell3_7; //-- real
		float64_t cell3_8; //-- real
		float64_t cell3_9; //-- real
		float64_t cell4_1; //-- real
		float64_t cell4_10; //-- real
		float64_t cell4_2; //-- real
		float64_t cell4_3; //-- real
		float64_t cell4_4; //-- real
		float64_t cell4_5; //-- real
		float64_t cell4_6; //-- real
		float64_t cell4_7; //-- real
		float64_t cell4_8; //-- real
		float64_t cell4_9; //-- real
		float64_t cell5_1; //-- real
		float64_t cell5_10; //-- real
		float64_t cell5_2; //-- real
		float64_t cell5_3; //-- real
		float64_t cell5_4; //-- real
		float64_t cell5_5; //-- real
		float64_t cell5_6; //-- real
		float64_t cell5_7; //-- real
		float64_t cell5_8; //-- real
		float64_t cell5_9; //-- real
		float64_t cell6_1; //-- real
		float64_t cell6_10; //-- real
		float64_t cell6_2; //-- real
		float64_t cell6_3; //-- real
		float64_t cell6_4; //-- real
		float64_t cell6_5; //-- real
		float64_t cell6_6; //-- real
		float64_t cell6_7; //-- real
		float64_t cell6_8; //-- real
		float64_t cell6_9; //-- real
		float64_t cell7_1; //-- real
		float64_t cell7_10; //-- real
		float64_t cell7_2; //-- real
		float64_t cell7_3; //-- real
		float64_t cell7_4; //-- real
		float64_t cell7_5; //-- real
		float64_t cell7_6; //-- real
		float64_t cell7_7; //-- real
		float64_t cell7_8; //-- real
		float64_t cell7_9; //-- real
		float64_t cell8_1; //-- real
		float64_t cell8_10; //-- real
		float64_t cell8_2; //-- real
		float64_t cell8_3; //-- real
		float64_t cell8_4; //-- real
		float64_t cell8_5; //-- real
		float64_t cell8_6; //-- real
		float64_t cell8_7; //-- real
		float64_t cell8_8; //-- real
		float64_t cell8_9; //-- real
		float64_t cell9_1; //-- real
		float64_t cell9_10; //-- real
		float64_t cell9_2; //-- real
		float64_t cell9_3; //-- real
		float64_t cell9_4; //-- real
		float64_t cell9_5; //-- real
		float64_t cell9_6; //-- real
		float64_t cell9_7; //-- real
		float64_t cell9_8; //-- real
		float64_t cell9_9; //-- real
		float64_t x_1;
		float64_t x_2;
		float64_t x_3;
		float64_t x_4;
		float64_t y_1;
		float64_t y_2;
		float64_t y_3;
		float64_t y_4;
} State;

/**
 * matrix structure
 */
 typedef struct {
		 bool obstacle;
		 bool robot;
		 float64_t pheromone; //-- real matrix
		 float64_t lastVisitTime;
		 float64_t contributions;
		 int x;
		 int y;
 } Cell;

/**
 * state with matrix
 */
typedef struct {
		Cell map[10][10]; //-- real matrix
		float64_t x[4];
		float64_t y[4];
		Cell* neighbourhood;
		int32_t nSize;
} State1;

/**
 * Global variables
 */
State1 st1;
float64_t EPSLON;
bool isInit;

/**
 * init function
 */
void init(State* st);

/**
 * sais if there is an obstacle in the cell
 */
bool hasObstacle(Cell* c);

/**
 * sais if there is another robot in the cell
 */
bool isOccupied(Cell* c);

/**
 * Compute pheromone disseminated (eD is the euclideanDistance between the cell where the robot is and the cell
 * where the robot is disseminating the pheromone)
 */
float64_t pheromoneDisseminated(float64_t eD);

/**
 * Euclidean distance
 */
float64_t euclideanDistance(float64_t x1, float64_t x2, float64_t y1, float64_t y2);

/**
 * Return the cell where the robot is located
 */
Cell* findCellFromCoordinates(State1* st1, int32_t x, int32_t y);

/**
 * Find best neighbour
 */
float64_t findNeighbourhood(State1* st1, Cell* c);

/**
 * Find best neighbour
 */
Cell* findBestNeighbour(State1* st1, Cell* c, float64_t sum);

/**
 * Move the robot
 */
void move(State1* st1, Cell* curr, Cell* best, float64_t* x, float64_t* y);

/**
 * Find the rate of evaporation
 */
float64_t evaporationRate(State* st, Cell* c);

/**
 * Update the contribution attribute to each cell where robot are moved and to each cell of the neighbourhoods
 */
void updateContribution(State1* st1, Cell* c);

/**
 * Update the pheromone
 */
void updatePheromone(State* st, State1* st1, Cell* c);

/**
 * translation function from State to State1
 */
void state2State1(State* st, State1* st1);

/**
 * translation function from State1 to State
 */
void state12State(State* st, State1* st1);

/**
 * print matrix
 */
void printTest(State* st, State1* st1);

/**
 * uniform random number between 0 and 1
 */
float64_t unifRand();

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