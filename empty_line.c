/*
** empty_line.c for  in /home/pastor_r/test/sudoku_generator
** 
** Made by Remi Pastor
** Login   <pastor_r@epitech.net>
** 
** Started on  Sat Feb 27 23:30:47 2016 Remi Pastor
** Last update Wed Apr 27 13:59:25 2016 remi pastor
*/

#include "my.h"

void	empty_line(int **line)
{
  int	i;
  int	j;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	line[i][j++] = 0;
      i++;
    }
}

char	**func_tab_init(char **map, int **line)
{
  int	i;
  int	j;

  i = 0;
  map = malloc(sizeof(char*) * 9 + 1);
  while (i < 9)
    {
      j = 0;
      map[i] = malloc(sizeof(char*) * 9 + 1);
      while (j < 9)
        {
          map[i][j] = line[i][j] + 48;
          j++;
        }
      i++;
    }
  return (map);
}

void	print_new_map_sequel(int j, int i, int fd, char **map)
{
  write(fd, "|", 1);
  while (j < 9)
    {
      write(fd, " ", 1);
      if (map[i][j] == '0')
	write(fd, " ", 1);
      else
	write(fd, &map[i][j], 1);
      j++;
    }
  write(fd, "|\n", 2);
}

void	print_new_map(char **map, char *name)
{
  int	i;
  int	j;
  int	fd;

  i = 0;
  if (name != NULL)
    fd = open(name, O_CREAT | O_TRUNC | O_RDWR, 0644);
  else
    fd = open("map_gen.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
  write(fd, "|------------------|\n", 21);
  while (i < 9)
    print_new_map_sequel(0, i++, fd, map);
  write(fd, "|------------------|\n", 21);
  close(fd);
}

void	creat_line(int **line, int i, int j, int nbr)
{
  int	limit;

  limit = 0;
  while (limit < 18)
    {
      while (line[i][j] != 0)
        {
          i = rand() % 9;
          j = rand() % 9;
        }
      while (nbr == 0)
        nbr = rand() % 9;
      line[i][j] = nbr;
      while (verif_map_line(line, i, j, nbr) != 0 ||
             verif_map_col(line, i, j, nbr) != 0 ||
             verif_map_carre(line, i, j, nbr) != 0)
        {
          line[i][j] = line[i][j] + 1;
          nbr = nbr + 1;
          if (line[i][j] > 9)
            {
              line[i][j] = 0;
              nbr = 0;
            }
        }
      limit++;
    }
}
