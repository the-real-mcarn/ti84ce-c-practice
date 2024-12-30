// convpng v7.2
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __logo_gfx__
#define __logo_gfx__
#include <stdint.h>

#define logo_gfx_transparent_color_index 0

#define dvd_width 80
#define dvd_height 49
#define dvd_size 3922
extern uint8_t dvd_data[3922];
#define dvd ((gfx_sprite_t*)dvd_data)
#define colour_width 3
#define colour_height 3
#define colour_size 11
extern uint8_t colour_data[11];
#define colour ((gfx_sprite_t*)colour_data)
#define sizeof_logo_gfx_pal 86
extern uint16_t logo_gfx_pal[8][2];

#endif
