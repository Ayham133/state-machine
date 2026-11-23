#ifndef ENTRY_H
#define ENTRY_H

#ifdef __cplusplus
extern "C"{
#endif

    /**
     * @brief  represent an entry that has <key, value> to a Map
     */
    typedef struct Entry Entry;

    /**
     *  @brief  initiate new entry
     */
    Entry *init_entry(const char *state, const char *event, const char *next_state, const char *action_message);

    char *entry_get_state(Entry *entry);

    char *entry_get_event(Entry *entry);

    char *entry_get_next_state(Entry *entry);

    char *entry_get_action_message(Entry *entry);

    /**
     * @brief   delete this entry and clear the memeory
     *
     * @param entry    a pointer to the requested entry
     * @note
     */
    void delete_entery(Entry **entry);

#ifdef __cplusplus
}
#endif
#endif // ENTRY_H
