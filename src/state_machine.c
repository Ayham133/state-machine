/**
*
* @breif this is state_machine.c file, it containes implementation code.
*
*/

#include "../include/state_machine/api.h"
#include "../src/internal/map.h"

typedef struct StateMachine{
    char *state;
    Map *enteries;

} StateMachine;

/**
* @brief   initiat a new StateMachine
*
* @return  pointer to the new state machine
*/
StateMachine *init_state_machine(char *initial_state);

/**
 *
 * @brief change the state of this machine according to it's rules
 *
 */
int trigger_state_machine(StateMachine *state_machine, char *event);

/**
 * @brief delete this state machine and clear the memeory
 *
 */
void delete_state_machine(StateMachine **state_machine);
