#include <stdlib.h>
#include <string.h>

#include "internal/map.h"
#include "internal/entery.h"

/**
     * @brief   represent a colliction of entries
     */
typedef struct Map{
    Entery *entries[MAX_SIZE];
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
     * @param map       a pointer to the object map
     * @param entery    a pointer to the entery
     *
     * @return [int]    return status code
     * @note 
     */
int map_put(Map *map, Entery *entery)
{
    if(map == NULL || entery == NULL)
        return MAP_NULL_POINTER;

    if(map->size == (MAX_SIZE - 1))
        return MAP_OUT_OF_MEMORY;

    map->entries[map->size] = entery;
    map->size++;

    return MAP_SUCCESS;
}

/**
     * @brief    get the requested entry from the passed key
     *
     * @param map       a pointer to the object map
     * @param entery    a pointer to the requested entery
     * @param out_value the place that will house the returned value
     *
     * @return [int]    return status code
     * @note 
     */
int map_get(Map *map, Entery *entery, Entery *out_value)
{
    if(map == NULL || entery == NULL) 
        return MAP_NULL_POINTER;

    if(map->size == 0)
        return MAP_EMPTY;


    // Loop through the entries, we are looking for matching enteries
    for (int i = 0; i < map->size; i++)
    {
        if(strcmp(entery_get_state(entery), entery_get_state(map->entries[i])) == 0)
        {
            out_value = entery;
            return MAP_SUCCESS;
        }
    }

    return MAP_NOT_FOUND;

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
