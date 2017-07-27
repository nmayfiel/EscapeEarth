template <class p1_ammo_enemy_template>

void checkColliders(GameData *game)
{
	for (int i = 0; i < game->pm.count; i++)
	{
		for (int j = 0; j < game->em.count; j++)
		{
			if (game->pm.projectile[i].pos.x + game->images[game->pm.projectile[i].tx].width/2 >= game->em.projectile[j].pos.x - game->images[game->em.projectile[j].tx].width) // projectile rightmost, enemy leftmost
			{
				if (game->pm.projectile[i].pos.y + game->images[game->pm.projectile[i].tx].height >= game->em.projectile[j].pos.y) //projectile downmost, enemy upmost
				{
					checkCollisionBox(game->em.projectile[j].pos.x - game->images[game->em.projectile[j].tx].width, game->pm.projectile[i].pos.x + game->images[game->pm.projectile[i].tx].width/2, game->em.projectile[j].pos.y, game->pm.projectile[i].pos.y + game->images[game->pm.projectile[i].tx].height);
				}
				if (game->pm.projectile[i].pos.y <= game->em.projectile[j].pos.y + game->images[game->em.projectile[j].tx].height) // projectile upmost, enemy downmost,
				{
					checkCollisionBox(game->em.projectile[j].pos.x - game->images[game->em.projectile[j].tx].width, game->pm.projectile[i].pos.x + game->images[game->pm.projectile[i].tx].width/2, game->pm.projectile[i].pos.y, game->em.projectile[j].pos.y + game->images[game->em.projectile[j].tx].height);
				}
			}
			if (game->pm.projectile[i].pos.x - game->images[game->pm.projectile[i].tx].width/2 <= game->em.projectile[j].pos.x + game->images[game->em.projectile[j].tx].width) //projectile leftmost, enemy rightmost
			{
				if (game->pm.projectile[i].pos.y + game->images[game->pm.projectile[i].tx].height >= game->em.projectile[j].pos.y) // pm downmost, em upmost
				{
					checkCollisionBox(game->pm.projectile[i].pos.x - game->images[game->pm.projectile[i].tx].width/2, game->em.projectile[j].pos.x + game->images[game->em.projectile[j].tx].width, game->em.projectile[j].pos.y, game->pm.projectile[i].pos.y + game->images[game->pm.projectile[i].tx].height);
				}
				if (game->pm.projectile[i].pos.y <= game->em.projectile[j].pos.y + game->images[game->em.projectile[j].tx].height) //pm upmost, em downmost
				{
					checkCollisionBox(game->pm.projectile[i].pos.x - game->images[game->pm.projectile[i].tx].width/2, game->em.projectile[j].pos.x + game->images[game->em.projectile[j].tx].width, game->pm.projectile[i].pos.y, game->em.projectile[j].pos.y + game->images[game->em.projectile[j].tx].height);
				}
			}
		}
	}
}

void checkCollisionBox(Gamedata *Game, p1_ammo_enemy_template *obj1, p1_ammo_enemy_template *obj2, x1, x2, y1, y2)
{
	int32_t buff1 = (int32_t *)(game->images[obj1->tx].data);
	int32_t buff2 = (int32_t *)(game->images[obj2->tx].data);
	int checki1, checki2 = 0;
	int startx1, starty1, startx2, starty2 = 0;

	if (obj1->y < y1) //assuming obj->y is the value of the top-left pixel
		starty1 = (game->images[obj1->tx].width * (y1 - obj1->y));
	if (obj1->x < x1)
		startx1 = (x1 - obj1->x);
	if (obj2->y < y1)
		starty2 = (game->images[obj2->tx].width * (y1 - obj2->yi));
	if (obj2->x < x1)
		startx2 = (x1 - obj2->x);

	int i1 = starty1 + startx1;
	int i2 = starty2 + startx2;

	nl1 = 0;
	nl2 = 0;
	y = y1;
	while (y < y2)
	{
		x = x1;
		while (x < x2)
		{
			if (x > obj1->x + game->images[obj1->tx].width || x < obj1->x)
			{
				nl1 = 1;
			}
			else
			{
				if (nl1 == 1 && i1 != starty1 + startx1)
					i1 += game->images[obj1->tx].width - (x - obj1->x);
				check_i1 = 1;
				nl1 = 0;
			}
			if (x > obj2->x + game->images[obj2->tx].width || x < obj2->x)
			{
				nl2 = 1;
			}
			else
			{
				if (nl2 == 1 && i2 != starty2 + startx2)
					i2 += game->images[obj2->tx].width - (x - obj2->x);
				check_i2 = 1;
				nl2 = 0;
			}

			if (check_i1 && check_i2)
			{
				if (i1 >= game->images[obj1->tx].size_in_pixels || i2 >= game->images[obj2->tx].size_in_pixels)
					return ;
				if (!(buff1[i1] & 0x00FFFFFF) && !(buff2[i2] & 0x00FFFFFF))
				{
					collide(obj1, obj2);
					return ;
				}
				i1++;
				i2++;
				check_i1 = 0;
				check_i2 = 0;
			}
			x++;
		}
		y++;
	}
}

void collide(p1_ammo_enemy_template *obj1, p1_ammo_enemy_template *obj2)
{
	oldhp = obj1->hp;
	obj1->hp -= obj2->hp;
	obj2->hp -= oldhp;
}
