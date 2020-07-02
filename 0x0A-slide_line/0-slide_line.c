#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_zeros_left - Remove zeros
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 */

void slide_zeros_left(int *line, size_t size)
{
int a, z, aux, index;
int count_zeros;
int lenght;
lenght = size;
for (a = 0; a < lenght; a++)
{
count_zeros = 0;
z = a;
while (line[z] == 0 && z < lenght)
{
  count_zeros += 1;
  z++;
}
index = a + count_zeros;
if (index < lenght)
{
aux = line[index];
line[index] = line[a];
line[a] = aux;
}
}
}

/**
 * slide_zeros_right - Remove zeros
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 */

void slide_zeros_right(int *line, size_t size)
{
int a, z, aux, index;
int count_zeros;
for (a = size - 1; a >= 0; a--)
{
count_zeros = 0;
z = a;
while (line[z] == 0 && z >= 0)
{
count_zeros += 1;
z--;
}
index = a - count_zeros;
if (index >= 0)
{
aux = line[index];
line[index] = line[a];
line[a] = aux;
}
}
}

/**
 * add_numbers_left - Add numbers
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 */

void add_numbers_left(int *line, size_t size)
{
int next, i, length;
length = size;
for (i = 0; i < length - 1; i++)
{
next = i + 1;
if (line[i] == line[next])
{
line[i] = line[i] + line[next];
line[next] = 0;
}
}
}

/**
 * add_numbers_right - Add numbers
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 */

void add_numbers_right(int *line, size_t size)
{
int behind, i, length;
length = size;
for (i = length - 1; i > 0; i--)
{
behind = i - 1;
if (line[i] == line[behind])
{
line[i] = line[i] + line[behind];
line[behind] = 0;
}
}
}

/**
 * slide_line - 2048 game
 *
 * @line: Pointer to the array of int
 * @size: Number of elements in @line
 * @direction: Direction of the slide
 */

int slide_line(int *line, size_t size, int direction)
{
if (direction == 1)
{
slide_zeros_right(line, size);
add_numbers_right(line, size);
slide_zeros_right(line, size);
} else if (direction == 0)
{
slide_zeros_left(line, size);
add_numbers_left(line, size);
slide_zeros_left(line, size);
} else
{
return (0);
}
return (1);
}