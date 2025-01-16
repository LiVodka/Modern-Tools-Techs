#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"

/**
 * @brief Draws empty fractal, assuming image is clean
 *
 * @param picture
 */
void draw_julia_set(image_p picture, double real, double imag);

void draw_sierpinski_carpet(image_p picture, int x_min, int y_min, int size);

#endif // _FRACTAL_H_
