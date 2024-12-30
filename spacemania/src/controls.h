// controls.h
// Scan keyboard for button presses
#include <keypadc.h>

void handleInput()
{
	// Scan keyboard for button presses
	kb_Scan();

	// Move player
	if (kb_Data[7] & kb_Down)
	{
		if (!(player.pos[1] >= (LCD_HEIGHT - 32)))
		{
			player.pos[1] += speed;
		}
	}
	if (kb_Data[7] & kb_Up)
	{
		if (!(player.pos[1] <= 0))
		{
			player.pos[1] -= speed;
		}
	}
	if (kb_Data[7] & kb_Left)
	{
		if (!(player.pos[0] <= 0))
		{
			player.pos[0] -= speed;
		}
	}
	if (kb_Data[7] & kb_Right)
	{
		if (!(player.pos[0] >= (LCD_WIDTH - 32)))
		{
			player.pos[0] += speed;
		}
	}

	// Spawn bullet on 2nd press
	if (kb_Data[1] & kb_2nd)
	{
		// If bullet has already been spawned (You cannot hold the button)
		if (bulletSpawned == 0)
		{
			spawnBullet((player.pos[0] + 16), (player.pos[1] + 8));
			bulletSpawned = 1;
		}
	}

	// Set bulletSpawned to false if button is let loose
	if (kb_Data[1] != kb_2nd)
	{
		bulletSpawned = 0;
	}

	// Spawn baddie on 2nd press
	if (kb_Data[1] & kb_Mode)
	{
		// If baddie has already been spawned (You cannot hold the button)
		if (baddieSpawned == 0)
		{
			spawnBaddie((LCD_WIDTH + 32), randInt(0, (LCD_HEIGHT - 32)));
			baddieSpawned = 1;
		}
	}

	// Set baddieSpawned to false if button is let loose
	if (kb_Data[1] != kb_Mode)
	{
		baddieSpawned = 0;
	}
}