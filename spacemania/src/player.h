// player.h
struct Player
{
	float pos[2];
	float oldPos[2];
} player;

void updatePlayer(int spriteActive)
{
	if ((abs(player.oldPos[0] - player.pos[0]) >= 1) || (abs(player.oldPos[1] - player.pos[1]) >= 1) || spriteActive == 1)
	{
		gfx_Sprite(spaceship, player.pos[0], player.pos[1]);
		player.oldPos[0] = player.pos[0];
		player.oldPos[1] = player.pos[1];
	}
}