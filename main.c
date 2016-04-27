/*
** main.c for  in /home/pastor_r/test/sudoku_generator
** 
** Made by Remi Pastor
** Login   <pastor_r@epitech.net>
** 
** Started on  Sat Feb 27 22:33:47 2016 Remi Pastor
** Last update Wed Apr 27 14:10:32 2016 remi pastor
*/

#include "my.h"

void	my_help()
{
  printf("USAGE : ./generator_sudoku [filename]\n\n");
  printf("OPTION :\n");
  printf("\t-h\tdisplay this help\n");
}

int	main(int ac, char **av)
{
  int	**line;
  int	i;

  i = 0;
  if (ac == 1)
    {
      my_help();
      return (1);
    }
  else if (av[1][0] == '-' && av[1][1] == 'h')
    {
      my_help();
      return (0);
    }
  else
    {
      line = malloc(sizeof(int*) * 10);
      while (i < 9)
	line[i++] = malloc(sizeof(int) * 20);
      empty_line(line);
      simple_generator(0, line, av[1]);
    }
  return (0);
}
