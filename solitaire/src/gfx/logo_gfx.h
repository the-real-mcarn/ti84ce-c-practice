// convpng v7.2
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __logo_gfx__
#define __logo_gfx__
#include <stdint.h>

#define logo_gfx_transparent_color_index 0

#define diamonds_width 34
#define diamonds_height 50
#define diamonds_size 1702
extern uint8_t diamonds_data[1702];
#define diamonds ((gfx_sprite_t*)diamonds_data)
#define hearts_width 34
#define hearts_height 50
#define hearts_size 1702
extern uint8_t hearts_data[1702];
#define hearts ((gfx_sprite_t*)hearts_data)
#define spades_width 34
#define spades_height 50
#define spades_size 1702
extern uint8_t spades_data[1702];
#define spades ((gfx_sprite_t*)spades_data)
#define clubs_width 34
#define clubs_height 50
#define clubs_size 1702
extern uint8_t clubs_data[1702];
#define clubs ((gfx_sprite_t*)clubs_data)
#define sizeof_logo_gfx_pal 12
extern uint16_t logo_gfx_pal[6];

#endif
