#include <stdio.h>
#include "image.h"
#include "fractal.h"

int main()
{
    image_p img = create_image(300, 300);

    //draw_julia_set(img, -0.7, 0.27015);

    draw_sierpinski_carpet(img, 0, 0, 300);

    save_pgm(img, "test.pgm");

    return 0;
}
