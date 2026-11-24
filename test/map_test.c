#include <test.h>

#include "../src/internal/entery.h"
#include "../src/internal/map.h"

TEST(init_entry_test, ENTRY)
{
    Entery *entery = init_entery("LOCKED", "COIN", "UNLOCKED", "UNLOCKED THE DOOR");

    ASSERT_NOT_NULL(entery);

    ASSERT_EQ_STR(entery_get_state(entery), "LOCKED");
    ASSERT_EQ_STR(entery_get_event(entery), "COIN");
    ASSERT_EQ_STR(entery_get_next_state(entery), "UNLOCKED");
    ASSERT_EQ_STR(entery_get_action_message(entery), "UNLOCKED THE DOOR");

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
