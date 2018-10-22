/**
* @fichier convolution.c
* @titre Convolution 2D
* @description 2D convolution with concurrent programming
* @auteurs Kevin Estalella & Federico Lerda
* @date 21 October 2015
* @version 1.0
*/

#include "convolution.h"

/**
* Applies convolution 2d to the image passed as parameter
* @param thread_id contains the parameters to provide for convolution 2d
* @return do not return anything
*/
void *thread(void *thread_id) {
  //we retrieve the parameters provided to the thread
  convolution_params_t *tab = (convolution_params_t *) thread_id;
  //We call the convolution function with the parameters provided
  convolution(tab->source, tab->destination, tab->filter, tab->start, tab->end);
  return NULL;
}


 /**
 * Applies convolution 2d to the image passed as parameter
 * @param source image source
 * @param destination image de destination
 * @param filter filter to apply to the image
 * @param first pixel first being processed
 * @param last last pixel being processed
 * @return ne retourne rien
 */
void convolution(img_t* source, img_t* destination, char* filter, int start, int end) {

  //recovers the filter passed as parameter
  filter_t K = getFilter(filter);

  int h, i, j;  //indices of loops for
  int N = K.size; //order of the matrix K (Kernel)
  int M = N/2;  //margin in relation to the center of Kernel
  int ligne = source->width; //line width (in pixel [if we make 2 * line we are in the second line])
  int nbrLigne = source->height; //height of the image (in pixel)
  //ariables allowing us to calculate the three components r, g and b of the image
  double calcul_r, calcul_g, calcul_b;

  //walk the whole picture. h is the position of the current pixel.
  for (h = start; h < end; h++) {

    calcul_r = 0;
    calcul_g = 0;
    calcul_b = 0;

    //test that the current position (h) is outside the margin M of the edges of the image
    if ((h > (M*ligne)) && (h < ((ligne*nbrLigne) - (M*ligne))) && ((h % ligne) > M) && ((h % ligne) < ligne-M)) {
      for (j=-M; j<=M; j++) { // Kernel line
        for (i=-M; i<=M; i++) { //Kernel column

          pixel_t *p1 = &source->data[h+(ligne*j)+i]; //recovers pixel from the base image
          double z = *(K.f+((j+M)*N)+(i+M)); //recovers the value of the Kernel (filter)

          calcul_r += z * p1->r;  //calculating the value for the red
          calcul_g += z * p1->g;  //calculating the value for the green
          calcul_b += z * p1->b;  //calculating the value for the blue
        }
      }
    }

    //recovers pixel from the destination image
    pixel_t *p2 = &destination->data[h];

    //writes pixel of the destination image with calculated values
    p2->r = test_limit(calcul_r);
    p2->g = test_limit(calcul_g);
    p2->b = test_limit(calcul_b);
  }
}

/**
* Test that the value for a color is contained between 0 and 255 (rgb code)

*/
int test_limit(double value){
  if(value > 255){
    return 255;
  } else if(value < 0){
    return 0;
  } else{
    return value;
  }
}
