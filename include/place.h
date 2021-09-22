#ifndef SWORD_PLACE_H
#define SWORD_PLACE_H

#include "chr.h"
#include "event.h"

typedef struct place_s place_t;

struct place_s {
  chr_node_t* chrl;
  iacts_t* iacts;
};

place_t* place();
void _place(place_t* p);

#endif
