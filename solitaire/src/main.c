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

float t, dt, c, delta, m, v, u, a, fv, fd, fr;
int card, w;

float mod_delta = 1; 
float mod_c = 1;

void draw_sprite(int x, int y)
{
    switch (card)
    {
    case 0:
        gfx_Sprite(diamonds, x, y);
        break;
    case 1:
        gfx_Sprite(hearts, x, y);
        break;
    case 2:
        gfx_Sprite(spades, x, y);
        break;
    case 3:
        gfx_Sprite(clubs, x, y);
        break;
    }

    gfx_BlitBuffer();
}

void new_card()
{
    card = randInt(0, 3);
    t = randInt(5, LCD_WIDTH / 6) / w;
    w = randInt(10, 30);
    dt = 0.075;
    c = randInt(2, 8) * mod_c;
    delta = ((float)rand() / (float)RAND_MAX * 5) * mod_delta;
    m = 20;
    v = randInt(0, 100);
    u = (LCD_HEIGHT - hearts_height) - 5;
    a = 0;
    fv = 0;
    fd = 0;
    fr = 0;
}

void main(void)
{
    srand(rtc_Time());

    gfx_Begin();
    gfx_SetPalette(logo_gfx_pal, sizeof_logo_gfx_pal, 0);
    gfx_SetDrawBuffer();
    gfx_FillScreen(0x05);

    new_card();

    do
    {
        /* Scan the keypad to update kb_Data */
        kb_Scan();

        if (kb_Left)
        {
            mod_delta = mod_delta - 0,1;
        }

        if (kb_Right)
        {
            mod_delta = mod_delta + 0,1;
        }
        
        

        fv = c * u;
        fd = delta * v;
        fr = -fv - fd;
        a = fr / m;
        v = v + a * dt;
        u = u + v * dt;
        t = t + dt;

        if (t * w > LCD_WIDTH)
        {
            new_card();
        }
        else
        {
            draw_sprite(t * w, (LCD_HEIGHT - hearts_height) - abs(u));
        }

    } while (kb_Data[6] != kb_Clear);

    /* Close the graphics */
    gfx_End();
}
