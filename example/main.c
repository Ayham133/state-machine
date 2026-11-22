#include <stdlib.h>

#include "../include/state_machine/api.h"

int main(int argc, char *argv[])
{

    StateMachine *state_machine = init_state_machine("LOCKED");

    trigger_state_machine(state_machine, "push");
    trigger_state_machine(state_machine, "coin");
    trigger_state_machine(state_machine, "push");

    delete_state_machine(&state_machine);
    return EXIT_SUCCESS;
}
