/*
** verif.c for verif in /home/doremi_g/rendu/rush/sudoki-bi
** 
** Made by Guillaume
** Login   <doremi_g@doremi-g-HP-EliteBook-840-G2>
** 
** Started on  Fri Feb 26 23:47:23 2016 Guillaume
** Last update Sun Feb 28 00:53:21 2016 Remi Pastor
*/
#include "my.h"

int	verif_map_line(int **map, int i, int j, int nb)
{
  int	x;

  x = 0;
  while (x < 9)
    {
      if (map[i][x] == nb && x != j)
	return (-1);
      x++;
    }
  return (0);
}

int	verif_map_col(int **map, int i, int j, int nb)
{
  int	y;

  y = 0;
  while (y < 9)
    {
      if (map[y][j] == nb && y != i)
	return (-1);
      y++;
    }
  return (0);
}

int	verif_map_carre(int **map, int i, int j, int nb)
{
  int	sauvi;
  int	sauvj;
  int	si;
  int	sj;

  sauvi = i;
  sauvj= j;
  si = (i / 3) * 3;
  sj = (j / 3) * 3;
  i = si;
  while (i < (si + 3))
    {
      j = sj;
      while (j < (sj + 3))
	{
	  if (map[i][j] == nb && i != sauvi && j != sauvj)
	      return (-1);
	  j++;
	}
      i++;
    }
  return (0);
}
