// Variables for collision detection
float distance = 0;
float difference[2];
int a;

// Check collisions
void checkCollision() {
	for (i = 0; i < (baddieAmount - 1); i++)
	{
		if (baddies[i].dead)
		{
			continue;
		}

		// Collision baddie x bullet
		for (a = 0; a < (bulletAmount - 1); a++)
		{
			if (bullets[a].dead)
			{
				continue;
			}
			

			//// Difference x
			difference[0] = (baddies[i].pos[0] + (32 / 2)) - (bullets[a].pos[0] + (16 / 2));
			//// Difference y
			difference[1] = (baddies[i].pos[1] + (32 / 2)) - (bullets[a].pos[1] + (16 / 2));

			// Calculate diffence
			distance = sqrt(pow(difference[0], 2) + pow(difference[1], 2));
			if (!baddies[i].dead && !bullets[a].dead && distance <= 11)
			{
				bullets[a].dead = true;
				baddies[i].dead = true;
			}
		}

		// Collision baddie x player
		//// Difference x
		difference[0] = (baddies[i].pos[0] + (32 / 2)) - (player.pos[0] + (32 / 2));
		//// Difference y
		difference[1] = (baddies[i].pos[1] + (32 / 2)) - (player.pos[1] + (32 / 2));

		// Calculate diffence
		distance = sqrt(pow(difference[0], 2) + pow(difference[1], 2));
		if (distance <= 15)
		{
			// Gameover
		}
	}
}