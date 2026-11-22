#ifndef API_H
#define API_H

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define MAX_BUFFER_SIZE 4096

/**
 * @brief All the status codes for this state machine
 */
typedef enum{
    STATE_MACHINE_SUCCESS = 0,
    STATE_MACHINE_NULL_POINTER = -1,
    STATE_MACHINE_INVALID_PARAm = -2,
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
    StateMachine *init_state_machine();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // API_H
