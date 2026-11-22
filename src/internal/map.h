#ifndef MAP_H
#define MAP_H

#define MAX_SIZE 100

/**
 * @brief all the status codes that used to signal errors/success
 */
typedef enum  {
    MAP_SUCCESS = 0,
    MAP_NULL_POINTER = -1,
    MAP_INVALID_PARAM = -2,
    MAP_OUT_OF_MEMORY = -3
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
     * @brief   add new entry to this map
     *
     * @param map   a pointer to the object map
     * @param key   the key for the new entry
     * @param value the value of the new entry
     *
     * @return [int]    return status code
     * @note 
     */
    int map_put(Map *map, char *key, char *value);

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
