#ifndef SWORD_CHARACTER_H
#define SWORD_CHARACTER_H

#include "dtype.h"

typedef struct chr_s chr_t;
typedef struct chr_node_s chr_node_t;
typedef struct chr_reln_s chr_reln_t;

typedef struct chr_stat_s chr_stat_t;

struct chr_stat_s {
  byte_t cur;
  byte_t max;
  byte_t pot;
  byte_t prog;
};

struct chr_s {
  chr_stat_t lvl;
  chr_stat_t hp;
  chr_stat_t mp;
  chr_stat_t sp;

  chr_stat_t str;
  chr_stat_t spd;
  chr_stat_t vit;
  chr_stat_t spi;

  // personality
  byte_t brave;
  byte_t forgive;
  byte_t ideal;

  byte_t explore;

  chr_reln_t* rell;
};

struct chr_node_s {
  chr_t* chr;
  chr_node_t* next;
};

struct chr_reln_s {
  chr_t* chr;
  uint_t hate;
  uint_t love;
  uint_t n_lt;
  chr_reln_t* next;
};

chr_t* chr();
void _chr(chr_t* p);

chr_node_t* chr_node(chr_t* cp);
void _chr_node(chr_node_t* p);
void chr_list_ins(chr_node_t** ip, chr_t* cp);
void chr_list_rm(chr_node_t** ip);

#endif