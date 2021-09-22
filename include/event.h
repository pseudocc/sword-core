#ifndef SWORD_EVENT_H
#define SWORD_EVENT_H

#include "dtype.h"

typedef struct event_s event_t;
typedef struct req_s req_t;
typedef struct rwd_s rwd_t;

#define NBITS_NTSPT 24
#define MAXVAL_NTSPT ((1 << NBITS_NTSPT + 1) - 1)

struct event_s {
  req_t* req;
  rwd_t* rwds;
  byte_t n_rwds;
  uint_t n_tspt: NBITS_NTSPT;
};

event_t* event();
void _event(event_t* p);

#endif