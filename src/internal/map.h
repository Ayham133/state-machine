#ifndef MAP_H
#define MAP_H

#include "entery.h"

#define MAX_SIZE 100

/**
 * @brief all the status codes that used to signal errors/success
 */
typedef enum  {
    MAP_SUCCESS = 0,
    MAP_NULL_POINTER = -1,
    MAP_INVALID_PARAM = -2,
    MAP_OUT_OF_MEMORY = -3,
    MAP_EMPTY         = -4,
    MAP_NOT_FOUND     = -5,
}MapStatus;

#ifdef __cplusplus
extern "C"{
#endif


    /**
     * @brief   represent a colliction of entries
     */
    typedef struct Map Map;

    /**
     *
     * @brief   initiate new map
     *
     * @return  a pointer to the new map
     * @note this fucntion will return null, if any allocation process failed
     */
    Map *init_map(void);

    /**
     * @brief   get the size of the requested map
     *
     * @param mpa   the pointer to the requested map 
     * @return      the size of the requested map
     * @note    this function will return zero if the map is null
     */
    unsigned map_size(Map *map);


    /**
     * @brief   add new entry to this map
     *
     * @param map       a pointer to the object map
     * @param entery    a pointer to the entery
     *
     * @return [int]    return status code
     * @note 
     */
    int map_put(Map *map, Entery *entery);

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
    int map_get(Map *map, Entery *entery, Entery *out_value);

    //TODO: Implement this function
    // Entery *map_get_entery_by_index(Map *map, unsigned index);

    /**
     * @brief   delete map object and clear the memory
     *
     * @param map   a pointer to the pointer map, prevent dangling pointers
     * @note this fucntion will return if the pointer map is null.
     */
    void delete_map(Map **map);

#ifdef __cplusplus
}
#endif
#endif // !MAP_H
