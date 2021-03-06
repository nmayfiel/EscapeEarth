#pragma once

#include <cstdint>
#include <Carbon/Carbon.h>
#include "image.hpp"

#define K_UP        kVK_UpArrow
#define K_DOWN      kVK_DownArrow
#define K_RIGHT     kVK_RightArrow
#define K_LEFT      kVK_LeftArrow
#define K_SPACE     kVK_Space
#define K_EXIT      kVK_Escape
#define K_ENTER		kVK_Return

#define G_HEIGHT    768.0
#define G_WIDTH     (G_HEIGHT / 16.0) * 9.0

double	secondsPerFrame(uint64_t last, uint64_t current);
void		clear_image(Image *img, int32_t color);
