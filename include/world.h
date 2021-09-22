#ifndef SWORD_WORLD_H
#define SWORD_WORLD_H

#include "chr.h"

typedef struct world_s world_t;

world_t* world();
void _world(world_t* p);

// full property
uint_t* world_seed(world_t* p);

void world_add_chr(world_t* p, chr_t* cp);
void world_init(world_t* p);
bool world_evlove(world_t* p);

#endif
