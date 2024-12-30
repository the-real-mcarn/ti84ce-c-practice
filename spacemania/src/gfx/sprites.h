// convpng v7.2
// this file contains all the graphics sources for easy inclusion in a project
#ifndef __sprites__
#define __sprites__
#include <stdint.h>

#define sprites_transparent_color_index 0

#define spaceship_width 32
#define spaceship_height 32
#define spaceship_size 1026
extern uint8_t spaceship_data[1026];
#define spaceship ((gfx_sprite_t*)spaceship_data)
#define bullet_width 16
#define bullet_height 16
#define bullet_size 258
extern uint8_t bullet_data[258];
#define bullet ((gfx_sprite_t*)bullet_data)
#define baddie_width 32
#define baddie_height 32
#define baddie_size 1026
extern uint8_t baddie_data[1026];
#define baddie ((gfx_sprite_t*)baddie_data)
#define sizeof_sprites_pal 26
extern uint16_t sprites_pal[13];

#endif
