#include <stdlib.h>
#include "chr.h"

chr_node_t* chr_node(chr_t* cp) {
  chr_node_t* p = malloc(sizeof(chr_node_t));
  p->chr = cp;
}

void _chr_node(chr_node_t* p) {
  if (p == NULL)
    return;
  free(p);
}
