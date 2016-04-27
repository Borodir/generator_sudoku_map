/*
** check.c for check in /home/doremi_g/rendu/rush/sudoki-bi
** 
** Made by Guillaume
** Login   <doremi_g@doremi-g-HP-EliteBook-840-G2>
** 
** Started on  Sat Feb 27 03:17:22 2016 Guillaume
** Last update Sun Feb 28 00:16:17 2016 Remi Pastor
*/
#include "my.h"

char	*fill()
{
  char	*ch;

  ch = malloc(10);
  ch[0] = 0;
  ch[1] = 0;
  ch[2] = 0;
  ch[3] = 0;
  ch[4] = 0;
  ch[5] = 0;
  ch[6] = 0;
  ch[7] = 0;
  ch[8] = 0;
  return (ch);
}

int	check_map_line(int **map)
{
  char	*ch;
  int	i;
  int	j;

  i = 0;
  while (i < 9)
    {
      ch = fill();
      j = 0;
      while (j < 9)
	{
	  ch[map[i][j]]++;
	  if (ch[map[i][j]] > 1 && map[i][j] != 0)
	    return (-1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	check_map_col(int **map)
{
  char	*ch;
  int	i;
  int	j;

  j = 0;
  while (j < 9)
    {
      ch = fill();
      i = 0;
      while (i < 9)
	{
	  ch[map[i][j]]++;
	  if (ch[map[i][j]] >1 && map[i][j] != 0)
	      return (-1);
	  i++;
	}
      j++;
    }
  return (0);
}

int     check_map_carre2(int **map, int i, int j, int nb)
{
  int   si;
  int   sj;
  int	save;

  save = 0;
  si = (i / 3) * 3;
  sj = (j / 3) * 3;
  i = si;
  while (i < (si + 3))
    {
      j = sj;
      while (j < (sj + 3))
	{
	  if (map[i][j] == nb)
	    save++;
	  if (save > 1)
	    return (-1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	check_map_carre(int **map)
{
  int	i;
  int	j;
  int	nb;

  nb = 1;
  while (nb < 10)
    {
      i = 0;
      while (i <= 6)
	{
	  j = 0;
	  while(j <= 6)
	    {
	      if (check_map_carre2(map, i, j, nb) == -1)
		return (-1);
	      j += 3;
	    }
	  i += 3;
	}
      nb++;
    }
  return (0);
}
