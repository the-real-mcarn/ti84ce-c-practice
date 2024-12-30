// Libraries lol
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <debug.h>
#include <graphx.h>

// Graphics
#include "gfx/sprites.h"

// set global vars
const int bulletAmount = 5;
const int baddieAmount = 6;
int spriteActive = 0;
int gamestate = 0;
float speed = 0.5;
int i;
float t;
float dt;

// Include entity headers
#include "player.h"
#include "bullet.h"
#include "baddie.h"
#include "collision.h"
#include "controls.h"

void setup()
{
	boot_Set48MHzModeI();

	/* Initialize the 8bpp graphics */
	gfx_Begin();

	/* Set up the palette for our sprites */
	gfx_SetPalette(sprites_pal, sizeof_sprites_pal, 0);

	// Clear screen
	gfx_FillScreen(01);

	// Player starting position
	player.pos[0] = 10;
	player.pos[1] = 136;
	player.oldPos[0] = 10;
	player.oldPos[1] = 10;

	// Reset all bullets
	for (i = 0; i < bulletAmount; i++)
	{
		bullets[i].dead = true;
		bullets[i].pos[0] = 0;
		bullets[i].pos[1] = 0;
	}

	// Reset all baddies
	for (i = 0; i < baddieAmount; i++)
	{
		baddies[i].dead = true;
		baddies[i].pos[0] = 0;
		baddies[i].pos[1] = 0;
	}
}

void main(void)
{
	setup();
	do
	{

		// Handle user input
		handleInput();

		// Move all alive bullets
		for (i = 0; i < bulletAmount; i++)
		{
			if (updateBullet(i) == 1)
			{
				spriteActive = 1;
			}
		}

		// Move all alive baddies
		for (i = 0; i < baddieAmount; i++)
		{
			if (updateBaddie(i) == 1)
			{
				spriteActive = 1;
			}
		}

		checkCollision();

		// Redraw player if position has changed or if a bullet has been fired
		updatePlayer(spriteActive);

	} while (kb_Data[6] != kb_Clear);

	// Close the graphics
	gfx_End();
}