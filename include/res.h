#ifndef SWORD_RESOURCE_H
#define SWORD_RESOURCE_H

#include "dtype.h"

typedef struct res_s res_t;

typedef enum {
  RES_GOLD,
  RES_COIN,
  RES_CASH,
  RES_EXP,
  RES_REP
} res_type_t;

struct res_s {
  res_type_t type;
  uint_t amount;
};

#endif
