#ifndef ESCAPEEARTH_H
#define ESCAPEEARTH_H

#include <cstdint>

#define K_UP        126
#define K_DOWN      125
#define K_RIGHT     124
#define K_LEFT      123
#define K_SPACE     49
#define G_WIDTH     768
#define G_HEIGHT    768

double	secondsPerFrame(uint64_t last, uint64_t current);

#endif
