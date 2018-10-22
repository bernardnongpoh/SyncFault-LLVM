/**
* @fichier filter.c
* @description Contains filters and associated functions
* @auteurs Kevin Estalella & Federico Lerda
* @date 21 Octobre 2015
* @version 1.0
*/

#include "filter.h"

//declaration of the different filters
double identity[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
double sharpen[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
double edge[3][3] = {{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}};
double test[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
double blur[3][3] = {{1./9, 1./9, 1./9}, {1./9, 1./9, 1./9}, {1./9, 1./9, 1./9}};
double gauss[5][5] = {
  {1./256, 4./256, 6./256, 4./256, 1./256},
  {4./256, 16./256, 24./256, 16./256, 4./256},
  {6./256, 24./256, 36./256, 24./256, 6./256},
  {4./256, 16./256, 24./256, 16./256, 4./256},
  {1./256, 4./256, 6./256, 4./256, 1./256}
};
double unsharp[5][5] = {
  {-1./256, -4./256, -6./256, -4./256, -1./256},
  {-4./256, -16./256, -24./256, -16./256, -4./256},
  {-6./256, -24./256, 476./256, -24./256, -6./256},
  {-4./256, -16./256, -24./256, -16./256, -4./256},
  {-1./256, -4./256, -6./256, -4./256, -1./256}
};

/**
*Get name filter passed as argument
* @param *filter that we want to recover
* @return the filter and its size in a filter_t structure
*/
filter_t getFilter(char *filter) {
  filter_t K;

  if (strcmp(filter,"identity")==0) {
    K.f = (double*)identity;
    K.size = (int)sqrt(sizeof(identity)/sizeof(double));
  } else if (strcmp(filter,"sharpen")==0) {
    K.f = (double*)sharpen;
    K.size = (int)sqrt(sizeof(sharpen)/sizeof(double));
  } else if (strcmp(filter,"edge")==0) {
    K.f = (double*)edge;
    K.size = (int)sqrt(sizeof(edge)/sizeof(double));
  } else if (strcmp(filter,"blur")==0) {
    K.f = (double*)blur;
    K.size = (int)sqrt(sizeof(blur)/sizeof(double));
  } else if (strcmp(filter,"identity")==0) {
    K.f = (double*)identity;
    K.size = (int)sqrt(sizeof(identity)/sizeof(double));
  } else if (strcmp(filter,"gauss")==0) {
    K.f = (double*)gauss;
    K.size = (int)sqrt(sizeof(gauss)/sizeof(double));
  } else if (strcmp(filter,"unsharp")==0) {
    K.f = (double*)unsharp;
    K.size = (int)sqrt(sizeof(unsharp)/sizeof(double));
  } else {
    printf("Le filter %s n'existe pas!\n", filter);
    exit(1);
  }

  return K;
}
