#include <stdlib.h>
#include "world.h"

typedef struct chr_node_s chr_node_t;
typedef struct place_map_s place_map_t;

struct chr_node_s {
  chr_t* chr;
  chr_node_t* next;
};

struct world_s {
  chr_node_t* chrl;
  place_map_t* plcm;

  uint_t seed;
};

static chr_node_t* chr_node(chr_t* cp) {
  chr_node_t* p = malloc(sizeof(chr_node_t));
  p->chr = cp;
}

static void _chr_node(chr_node_t* p) {
  if (p == NULL)
    return;
  free(p->chr);
  free(p);
}

world_t* world() {
  world_t* p = malloc(sizeof(world_t));
  p->chrl = NULL;
  p->plcm = NULL;
  return p;
}

void _world(world_t* p) {
  if (p == NULL)
    return;
  chr_node_t* np = p->chrl;
  while (np != NULL) {
    chr_node_t* tp = np->next;
    _chr_node(np);
    np = tp;
  }
  _place_map(p->plcm);
  free(p);
}

uint_t* world_seed(world_t* p) {
  if (p == NULL)
    return NULL;
  return &p->seed;
}

void world_add_chr(world_t* p, chr_t* cp) {
  if (p == NULL || cp == NULL)
    return;
  chr_node_t* np = chr_node(np);
  np->next = p->chrl;
  p->chrl = np;
}

static place_map_t* place_map();
void _place_map(place_map_t* p);

/**
 * @todo
 **/
void world_init(world_t* p) {
  if (p == NULL)
    return;
  place_map_load();
}

/**
 * @todo
 **/
bool world_evlove(world_t* p) {
  if (p == NULL)
    return false;
  return p->chrl == NULL;
}

