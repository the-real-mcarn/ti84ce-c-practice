#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <graphx.h>
#include <keypadc.h>

/* Include the sprite data */
#include "gfx/logo_gfx.h"

/* Function for drawing the main sprite */
void draw_sprite(int x, int y)
{
    /* Fill the screen with color index 0
    /* Note that this is a super inefficient way to
    /* redraw, but it demonstrates a simple way of clearing past data */
    // gfx_FillScreen(0xFF);

    /* Draw a bunch of different styled sprites on the screen */
    
    gfx_Sprite(dvd, x, y);

    /* Copy the buffer to the screen */
    gfx_BlitBuffer(); // This is the same as gfx_Blit(gfx_buffer)
}

void random_palette() {
    gfx_SetPalette(logo_gfx_pal[randInt(0, 7)], sizeof_logo_gfx_pal, 0);
}

void main(void)
{
    /* Coordinates used for the sprite */
    int x, y;
    int gravity[2];
    float angle;

    srand(rtc_Time());

    /* Initialize the 8bpp graphics */
    gfx_Begin();

    /* Set up the palette for our sprites */
    random_palette();

    /* Start at 0, 0 */
    x = randInt(0, LCD_WIDTH - dvd_width);
    y = randInt(0, LCD_HEIGHT - dvd_height);
    gravity[0] = randInt(0, 1);
    gravity[1] = randInt(0, 1);

    gfx_SetDrawBuffer();

    gfx_FillScreen(1);

    draw_sprite(x, y);

    do
    {
        /* Scan the keypad to update kb_Data */
        kb_Scan();

        if ((x + dvd_width) <= LCD_WIDTH && x >= 0)
        {
            if (gravity[0])
            {
                x++;
            }
            else
            {
                x--;
            }
        }
        else
        {
            random_palette();
            if (gravity[0])
            {
                gravity[0] = false;
                x--;
            }
            else
            {
                gravity[0] = true;
                x++;
            }
        }

        if ((y + dvd_height) <= LCD_HEIGHT && y >= 0)
        {
            if (gravity[1])
            {
                y++;
            }
            else
            {
                y--;
            }
        }
        else
        {
            random_palette();
            if (gravity[1])
            {
                gravity[1] = false;
                y--;
            }
            else
            {
                gravity[1] = true;
                y++;
            }
        }

        draw_sprite(x, y);
    } while (kb_Data[6] != kb_Clear);

    /* Close the graphics */
    gfx_End();
}
