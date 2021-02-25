#include "Pre_def.h"


/* Yash Koushik's (IMT2020033) contribution */
struct Image readimage(FILE *fp, int height, int width)
{
    struct Image pic;
    int i;
    pic.rgb = (struct RGB **)malloc(height * sizeof(void *));
    pic.height = height;
    pic.width = width;
    for (i = height - 1; i >= 0; i--)
    {
        pic.rgb[i] = (struct RGB *)malloc(width*sizeof(struct RGB));
        fread(pic.rgb[i], width, sizeof(struct RGB), fp);
    }
    return pic;
}

void freeImage(struct Image pic)
{
    int i;
    for (i = pic.height - 1; i >= 0; i--)
    {
        free(pic.rgb[i]);
    }
    free(pic.rgb);
}
/* ends here */


/* Yash and Mayank's contribution together */
int* openbmp(char* input)
{
    FILE *fp = fopen(input, "rb");
    struct bmp header;
    struct DIB_header dibheader;
    fread(header.name, 2, 1, fp);
    fread(&header.size, 3 * sizeof(int), 1, fp);
    fread(&dibheader, sizeof(struct DIB_header), 1, fp);
    fseek(fp, header.image_offset, SEEK_SET);
    struct Image image = readimage(fp, dibheader.height, dibheader.width);
    createBWImage(header, dibheader, image);
    fclose(fp);
    freeImage(image);
    int* dimensions = (int *)malloc(2*sizeof(int));
    dimensions[0] = dibheader.width;
    dimensions[1] = dibheader.height;
    return dimensions;
}
/* ends here */