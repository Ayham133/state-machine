#ifndef API_H
#define API_H

#define VERSION_MAJOR 1
#define VERSION_MINOR 0

/**
 * @brief All the status codes for this state machine
 */
typedef enum{
    STATE_MACHINE_SUCCESS = 0,
    STATE_MACHINE_NULL_POINTER = -1,
    STATE_MACHINE_INVALID_PARAM = -2,
    STATE_MACHINE_OUT_OF_MEMEORY = -3,
}StateMachineStatus;

#ifdef __cplusplus
extern "C"{
#endif

    typedef struct StateMachine StateMachine;

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

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // API_H
