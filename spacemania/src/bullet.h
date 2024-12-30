// bullet.h
int bulletSpawned;

struct Bullet
{
	bool dead;
	float pos[2];
	float oldPos[2];
} bullets[bulletAmount];

int spawnBullet(float posX, float posY)
{
	for (i = 0; i < bulletAmount; i++)
	{
		if (bullets[i].dead == true)
		{
			bullets[i].pos[0] = posX;
			bullets[i].pos[1] = posY;
			bullets[i].dead = false;
			return 1;
		}
	}
	return 0;
}

int updateBullet(int i)
{
	if (bullets[i].dead == false)
	{
		if (!(bullets[i].pos[0] >= (LCD_WIDTH + 16)))
		{
			if (abs(bullets[i].oldPos[0] - (bullets[i].pos[0] += speed)) >= 1)
			{
				bullets[i].pos[0] += speed;
				gfx_Sprite(bullet, bullets[i].pos[0], bullets[i].pos[1]);
				bullets[i].oldPos[0] = bullets[i].pos[0];
			}
			return 1;
		}
		else
		{
			bullets[i].dead = true;
			return 1;
		}
	} else {
		return 0;
	}
}