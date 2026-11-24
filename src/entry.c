#include "internal/entery.h"
#include <stdlib.h>
#include <string.h>

typedef struct Vector{
    char *status;
    char *event_or_message;
}Vector;

/**
* @brief  represent an entery that has <key, value> to a Map
*/
typedef struct Entery{
    Vector key;
    Vector value;
}Entery;

/**
*
*   @brief  initiate new entery
*
*/
Entery *init_entery(const char *state, const char *event, const char *next_state, const char *action_message)
{
    Entery *new_entery = malloc(sizeof(Entery));

    if(new_entery == NULL)
        return NULL;

    new_entery->key.status =    malloc(strlen(state) + 1);
    new_entery->key.event_or_message =    malloc(strlen(event)+1);
    new_entery->value.status =  malloc(strlen(next_state) + 1);
    new_entery->value.event_or_message =  malloc(strlen(action_message) + 1);

    if(new_entery->key.status == NULL || new_entery->key.event_or_message == NULL ||
        new_entery->value.status == NULL || new_entery->value.event_or_message == NULL)
    {
        delete_entery(&new_entery);
        return NULL;
    }

    strcpy(new_entery->key.status, state);
    strcpy(new_entery->key.event_or_message, event);
    strcpy(new_entery->value.status, next_state);
    strcpy(new_entery->value.event_or_message, action_message);

    return new_entery;
}

char *entery_get_state(Entery *entery)
{
    if(entery == NULL || entery->key.status == NULL)
        return NULL;

    return entery->key.status;
}

char *entery_get_event(Entery *entery)
{
    if(entery == NULL || entery->key.event_or_message == NULL)
        return NULL;

    return entery->key.event_or_message;
}

char *entery_get_next_state(Entery *entery)
{
    if(entery == NULL || entery->value.status == NULL)
        return NULL;

    return entery->value.status;
}

char *entery_get_action_message(Entery *entery)
{
    if(entery == NULL || entery->value.event_or_message == NULL)
        return NULL;

    return entery->value.event_or_message;
}

/**
 * @brief   delete this entery and clear the memeory
 *
 * @param entery    a pointer to the requested entry
 * @note
 */
void delete_entery(Entery **entery)
{
    if (entery == NULL || *entery == NULL)
        return;

    free((*entery)->key.event_or_message);
    free((*entery)->key.status);
    free((*entery)->value.status);
    free((*entery)->value.event_or_message);
    free((*entery));
    entery = NULL;
}
