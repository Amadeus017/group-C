#include "Pre_def.h"

/* Mayank Chadha's (IMT2020045) contribution */
unsigned char grayscale(struct RGB rgb)
{
    return ((0.3 * rgb.red) + (0.6 * rgb.green) + (0.1 * rgb.blue));
}
void RGBImageToGrayscale(struct Image pic)
{
    int i, j;
    for (i = 0; i < pic.height; i++)
        for (j = 0; j < pic.width; j++)
            pic.rgb[i][j].red = pic.rgb[i][j].green = pic.rgb[i][j].blue = grayscale(pic.rgb[i][j]);
}

int createBWImage(struct bmp header, struct DIB_header dibheader, struct Image pic)
{
    int i;
    FILE *f = fopen("pixeldata","wb");
    RGBImageToGrayscale(pic);
    for (i = 0; i < pic.height; i++)
    {
        for(int j = 0;j<=pic.width;j++)
        {
            if(j==0)
            {
                char k = pic.rgb[i][j+1].red;
                fwrite(&k, 1, 1, f);
            }
            else
            {
                char k = pic.rgb[i][j-1].red;
                fwrite(&k, 1, 1, f);
            }
        }
    }
    fclose(f);
    return 0;
}
 