#include <test.h>
#include<stdlib.h>

#include "../src/internal/entry.h"
#include "../src/internal/map.h"

TEST(init_entry_test, ENTRY)
{
    Entry *entery = init_entry("LOCKED", "COIN", "UNLOCKED", "UNLOCKED THE DOOR");

    ASSERT_NOT_NULL(entery);

    ASSERT_EQ_STR(entry_get_state(entery), "LOCKED");
    ASSERT_EQ_STR(entry_get_event(entery), "COIN");
    ASSERT_EQ_STR(entry_get_next_state(entery), "UNLOCKED");
    ASSERT_EQ_STR(entry_get_action_message(entery), "UNLOCKED THE DOOR");

    delete_entery(&entery);
}

TEST(init_map_test, MAP)
{
    Map *map = init_map();

    ASSERT_NOT_NULL(map);
    ASSERT_EQ_INT(map_size(map), 0);

}

int main(void)
{
    /* code */

    run_all_tests();
    return 0;
}
