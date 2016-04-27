/*
** my.h for lib in /home/pastor_r/test/sudoku_generator
** 
** Made by Guillaume
** Login   <doremi_g@doremi-g-HP-EliteBook-840-G2>
** 
** Started on  Sat Feb 27 03:17:22 2016 Guillaume
** Last update Wed Apr 27 14:10:05 2016 remi pastor
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

char	*fill();
int	check_map_line(int **map);
int	check_map_col(int **map);
int     check_map_carre2(int **map, int i, int j, int nb);
int	check_map_carre(int **map);
void	empty_line(int **line);
char	**func_tab_init(char **map, int **line);
void	print_new_map_sequel(int j, int i, int fd, char **map);
void	print_new_map(char **map, char *name);
void	creat_line(int **line, int i, int j, int nbr);
void	my_help();
int     resolve(int **line, int position);
void	remove_part(int **line);
void	simple_generator(int limit, int **line, char *name);
int	verif_map_line(int **map, int i, int j, int nb);
int	verif_map_col(int **map, int i, int j, int nb);
int	verif_map_carre(int **map, int i, int j, int nb);

#endif
