// baddie.h
int baddieSpawned;

struct Baddie
{
	bool dead;
	float pos[2];
	float oldPos[2];
} baddies[baddieAmount];

int spawnBaddie(float posX, float posY)
{
	for (i = 0; i < baddieAmount; i++)
	{
		if (baddies[i].dead == true)
		{
			baddies[i].pos[0] = posX;
			baddies[i].pos[1] = posY;
			baddies[i].dead = false;
			return 1;
		}
	}
	return 0;
}

int updateBaddie(int i)
{
	if (baddies[i].dead == false)
	{
		if (!(baddies[i].pos[0] <= (0 - 32)))
		{
			if ((abs(baddies[i].oldPos[0] - (baddies[i].pos[0] - speed)) >= 1))
			{
				baddies[i].pos[0] -= speed;
				gfx_Sprite(baddie, baddies[i].pos[0], baddies[i].pos[1]);
				baddies[i].oldPos[0] = baddies[i].pos[0];
				// baddies[i].oldPos[1] = baddies[i].pos[1];
				
			}
			return 1;
		}
		else
		{
			baddies[i].dead = true;
			return 1;
		}
	}
	else
	{
		return 0;
	}
}