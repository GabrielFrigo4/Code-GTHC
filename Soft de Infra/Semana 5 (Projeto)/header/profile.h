#include "new_types.h"

#define SLOT1 0
#define SLOT2 1
#define SLOT3 2
#define PLAYER_NAME_SIZE 33
#define LEVEL_SIZE PLAYER_NAME_SIZE
#define MODE_SIZE PLAYER_NAME_SIZE
#define SEED_SIZE PLAYER_NAME_SIZE

typedef struct player
{
    char name[PLAYER_NAME_SIZE];
} player;

typedef struct profile
{
    uint64 level;
    uint64 mode;
    uint64 seed;
    player player_data;
} profile;

profile *get_profile_slot(uint32 slot_index);
void set_profile_slot(uint32 slot_index, profile *_profile);
void remove_profile_slot(uint32 slot_index);
player create_player(const char *player_name);
profile *create_profile(uint64 level, uint64 mode, uint64 seed, player _player);
profile *clone_profile(profile *_profile);
profile *destroy_profile(profile *_profile);