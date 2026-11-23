#include "internal/entry.h"
#include <stdlib.h>
#include <string.h>

typedef struct Vector{
    char *status;
    char *event_or_message;
}Vector;

/**
* @brief  represent an entry that has <key, value> to a Map
*/
typedef struct Entry{
    Vector key;
    Vector value;
}Entry;

/**
*
*   @brief  initiate new entry
*
*/
Entry *init_entry(const char *state, const char *event, const char *next_state, const char *action_message)
{
    Entry *new_entry = malloc(sizeof(Entry));

    if(new_entry == NULL)
        return NULL;

    new_entry->key.status =    malloc(strlen(state) + 1);
    new_entry->key.event_or_message =    malloc(strlen(event)+1);
    new_entry->value.status =  malloc(strlen(next_state) + 1);
    new_entry->value.event_or_message =  malloc(strlen(action_message) + 1);

    if(new_entry->key.status == NULL || new_entry->key.event_or_message == NULL ||
        new_entry->value.status == NULL || new_entry->value.event_or_message == NULL)
    {
        delete_entery(&new_entry);
        return NULL;
    }

    strcpy(new_entry->key.status, state);
    strcpy(new_entry->key.event_or_message, event);
    strcpy(new_entry->value.status, next_state);
    strcpy(new_entry->value.event_or_message, action_message);

    return new_entry;
}

char *entry_get_state(Entry *entry)
{
    if(entry == NULL || entry->key.status == NULL)
        return NULL;

    return entry->key.status;
}

char *entry_get_event(Entry *entry)
{
    if(entry == NULL || entry->key.event_or_message == NULL)
        return NULL;

    return entry->key.event_or_message;
}

char *entry_get_next_state(Entry *entry)
{
    if(entry == NULL || entry->value.status == NULL)
        return NULL;

    return entry->value.status;
}

char *entry_get_action_message(Entry *entry)
{
    if(entry == NULL || entry->value.event_or_message == NULL)
        return NULL;

    return entry->value.event_or_message;
}

/**
 * @brief   delete this entry and clear the memeory
 *
 * @param entry    a pointer to the requested entry
 * @note
 */
void delete_entery(Entry **entry)
{
    if (entry == NULL || *entry == NULL)
        return;

    free((*entry)->key.event_or_message);
    free((*entry)->key.status);
    free((*entry)->value.status);
    free((*entry)->value.event_or_message);
    free((*entry));
    entry = NULL;
}