#ifndef SWORD_DTYPE_H
#define SWORD_DTYPE_H

#include <stdbool.h>

#ifdef EMCC_BUILD
#include <emscripten/emscripten.h>
#define STAYIN_ALIVE EMSCRIPTEN_KEEPALIVE
#else
#define STAYIN_ALIVE
#endif

typedef unsigned char byte_t;
typedef unsigned int uint_t;

#endif
