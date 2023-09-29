/* SYSTEM */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/* CUSTOM */
#include "profile.h"
#include "utils.h"
#include "rand.h"

const char *slots_path[] = {
    "./slot1.slot",
    "./slot2.slot",
    "./slot3.slot",
    NULL,
};

profile *get_profile_slot(uint32 slot_index)
{
    profile _temp;
    FILE *file = fopen(slots_path[slot_index], "rb");
    if (file)
    {
        fread(&_temp, sizeof(profile), 1, file);
        fclose(file);

        profile *_profile = clone_profile(&_temp);
        return _profile;
    }
    else
    {
        return NULL;
    }
}

void set_profile_slot(uint32 slot_index, profile *_profile)
{
    FILE *file = fopen(slots_path[slot_index], "wb");
    fwrite(_profile, sizeof(profile), 1, file);
    fclose(file);
}

void remove_profile_slot(uint32 slot_index)
{
    remove(slots_path[slot_index]);
}

player create_player(const wchar *player_name)
{
    player _player = {{L'\0'}};
    uint32 name_size = wstrlen(player_name);
    if (PLAYER_NAME_SIZE <= name_size)
    {
        name_size = PLAYER_NAME_SIZE - 1;
    }
    memcpy(_player.name, player_name, name_size * sizeof(wchar));
    return _player;
}

profile *create_profile(uint64 level, uint64 mode, uint64 seed, player _player)
{
    profile *_profile = malloc(sizeof(profile));
    profile _temp = {level, mode, seed, _player};
    *_profile = _temp;
    return _profile;
}

profile *clone_profile(profile *_profile)
{
    uint64 seed = rdrand64();
    return create_profile(_profile->level, _profile->mode, _profile->seed, _profile->player_data);
}

profile *destroy_profile(profile *_profile)
{
    free(_profile);
    _profile = NULL;
    return _profile;
}