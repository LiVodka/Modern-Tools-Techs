#include "image.h"
#include "fractal.h"
#include <math.h>
#include <stdio.h>

# define MAX_ITER 256
# define WIDTH 300
# define HEIGHT 300

void draw_julia_set(image_p picture, double real, double imag) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double zx = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
            double zy = (y - HEIGHT / 2) / (0.5 * HEIGHT);
            int i = MAX_ITER;
            while (zx * zx + zy * zy < 4 && i > 1) {
                double tmp = zx * zx - zy * zy + real;
                zy = 2.0 * zx * zy + imag;
                zx = tmp;
                i--;
            }
            int color = (i % 256);
            set_pixel(picture, x, y, color);
        }
    }
}

void draw_sierpinski_carpet(image_p picture, int x_min, int y_min, int size) {
    if (size < 1) return;
    int new_size = size / 3;
    for (int y = y_min + new_size; y < y_min + 2 * new_size; y++) {
        for (int x = x_min + new_size; x < x_min + 2 * new_size; x++) {
            set_pixel(picture, x, y, 0);
        }
    }
    for (int dy = 0; dy < 3; dy++) {
        for (int dx = 0; dx < 3; dx++) {
            if (dx != 1 || dy != 1) {
                draw_sierpinski_carpet(picture, x_min + dx * new_size, y_min + dy * new_size, new_size);
            }
        }
    }
}

