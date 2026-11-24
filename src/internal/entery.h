#ifndef ENTRY_H
#define ENTRY_H

#ifdef __cplusplus
extern "C"{
#endif

    /**
     * @brief  represent an entry that has <key, value> to a Map
     */
    typedef struct Entery Entery;

    /**
     *  @brief  initiate new entry
     */
    Entery *init_entery(const char *state, const char *event, const char *next_state, const char *action_message);

    char *entery_get_state(Entery *entry);

    char *entery_get_event(Entery *entry);

    char *entery_get_next_state(Entery *entry);

    char *entery_get_action_message(Entery *entry);

    /**
     * @brief   delete this entry and clear the memeory
     *
     * @param entry    a pointer to the requested entry
     * @note
     */
    void delete_entery(Entery **entry);

#ifdef __cplusplus
}
#endif
#endif // ENTRY_H
