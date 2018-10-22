/**
* @fichier filter.h
* @description Contains structures and prototypes of functions
* @auteurs Kevin Estalella & Federico Lerda
* @date 21 Octobre 2015
* @version 1.0
*/

#ifndef __KERNEL_H_INCLUDE__
#define __KERNEL_H_INCLUDE__

#include <math.h> 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Stock the address of a filter and its size
typedef struct filter_t {
  double *f;
  int size;
} filter_t;

filter_t getFilter(char *filter);

#endif //__KERNEL_H_INCLUDE__
