/*
** simple_generator.c for  in /home/pastor_r/test/sudoku_generator
** 
** Made by Remi Pastor
** Login   <pastor_r@epitech.net>
** 
** Started on  Sat Feb 27 23:24:23 2016 Remi Pastor
** Last update Wed Apr 27 14:09:41 2016 remi pastor
*/

#include "my.h"

void	simple_generator(int limit, int **line, char *name)
{
  char	**map;

  srand(time(NULL));
  creat_line(line, (rand() % 9), (rand() % 9), (rand() % 9));
  resolve(line, 0);
  remove_part(line);
  map = func_tab_init(map, line);
  print_new_map(map, name);
}
