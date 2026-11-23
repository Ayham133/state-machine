#include <stdlib.h>
#include <string.h>

#include "internal/map.h"
#include "internal/entry.h"

/**
     * @brief   represent a colliction of entries
     */
typedef struct Map{
    Entry *entries[MAX_SIZE];
    unsigned size;
} Map;

/**
*
* @brief   initiate new map
*
* @return  a pointer to the new map
* @note this fucntion will return null, if any allocation process failed
*/
Map *init_map(void)
{

    Map *new_map = malloc(sizeof(Map));

    if(new_map == NULL)
        return NULL;

    new_map->size = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        new_map->entries[i] = NULL;
    }

    return new_map;
}

/**
 * @brief   get the size of the requested map
 *
 * @param mpa   the pointer to the requested map
 * @return      the size of the requested map
 * @note    this function will return zero if the map is null
 */
unsigned map_size(Map *map)
{
    if(map == NULL)
        return 0;

    return map->size;
}

/**
     * @brief   add new entry to this map
     *
     * @param map   a pointer to the object map
     * @param key   the key for the new entry
     * @param value the value of the new entry
     *
     * @return [int]    return status code
     * @note this fucntion will return MAP_NULL_POINTER code if the this map is null,
     *       and this fucntion will return MAP_OUT_OF_MEMORY code if the map is full
     */
int map_put(Map *map, const char *state, const char *event, const char *next_state, const char *action_message)
{
    if(map == NULL)
        return MAP_NULL_POINTER;

    if(map->size == (MAX_SIZE - 1))
        return MAP_OUT_OF_MEMORY;

    Entry *new_entry = init_entry(state, event, next_state, action_message);
    map->entries[map->size] = new_entry;
    map->size++;

    return MAP_SUCCESS;
}

/**
     * @brief    get the requested entry from the passed key
     *
     * @param map   a pointer to the object map
     * @param key   the key to the requested entry
     * @param out_value  the place that will house the returned value
     *
     * @return [int]    return status code
     * @note 
     */
int map_get(Map *map, char *key, char *out_value)
{
    if(map == NULL) 
        return MAP_NULL_POINTER;

    if(map->size == 0)
        return MAP_EMPTY;

    if(key == NULL || strcmp(key, "") == 0)
        return MAP_INVALID_PARAM;

    // Loop through the entries, we are looking for matching event, which is in key.str2
    for (int i = 0; i < map->size; i++)
    {
        if(entry_get_state(map->entries[i])) ;
    }

}

/**
     * @brief   delete map object and clear the memory
     *
     * @param map   a pointer to the pointer map, prevent dangling pointers
     * @note this fucntion will return if the pointer map is null.
     */
void delete_map(Map **map)
{
    if(map == NULL || *map == NULL)
        return;

}
