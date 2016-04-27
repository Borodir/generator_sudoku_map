/*
** resolve.c for  in /home/pastor_r/test/sudoku_generator
** 
** Made by Remi Pastor
** Login   <pastor_r@epitech.net>
** 
** Started on  Sun Feb 28 03:04:24 2016 Remi Pastor
** Last update Sun Feb 28 03:37:24 2016 Remi Pastor
*/

#include "my.h"

int     resolve(int **line, int position)
{
  int   nbr;
  int   i;
  int   j;

  nbr = 1;
  i = position / 9;
  j = position % 9;
  if (position == 9 * 9)
    return (0);
  if (line[i][j] != 0)
    return (resolve(line, position + 1));
  while (nbr < 10)
    {
      if (verif_map_line(line, i, j, nbr) == 0 &&
          verif_map_col(line, i, j, nbr) == 0 &&
          verif_map_carre(line, i, j, nbr) == 0)
        {
          line[i][j] = nbr;
          if (resolve(line, position + 1) == 0)
            return (0);
        }
      nbr++;
    }
  line[i][j] = 0;
  return (1);
}

void	remove_part(int **line)
{
  int	remove;
  int	i;
  int	j;

  srand(time(NULL));
  i = rand() % 9;
  j = rand() % 9;
  remove = 0;
  while (remove < 45)
    {
      if (line[i][j] != 0)
	{
	  line[i][j] = 0;
	  i = rand() % 9;
	  j = rand() % 9;
	  remove++;
	}
      else
	{
	  i = rand() % 9;
	  j = rand() % 9;
	}
    }
}
