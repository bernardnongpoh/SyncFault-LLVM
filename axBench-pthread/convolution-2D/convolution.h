#ifndef __CONVOLUTION_H_INCLUDE__
#define __CONVOLUTION_H_INCLUDE__

#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "filtre.h"

//different stock items that we pass to threads
typedef struct convolution_params_t {
  img_t* source;
  img_t* destination;
  char* filter;
  int start;  //start position for convolution
  int end;  //end position
} convolution_params_t;

void *thread(void *thread_id);
void convolution(img_t* source, img_t* destination, char* filter, int start, int end);
int test_limit(double value);

#endif
