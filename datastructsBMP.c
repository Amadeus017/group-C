struct BITMAP_header
{
    char name[2];
    unsigned int size; //size = 4
    int garbage;
    unsigned int image_offset; //offset from where image starts
};

struct DIB_header
{
    //using unsigned int because no values can realistically be negative
    unsigned int header_size;
    unsigned int width;
    unsigned int height; //height and width in pixels
    unsigned short int colorplane;
    unsigned short int bpp; //bits per pixel
    unsigned int comp; // comp = 0 if there is no compression
    unsigned int image_size;
};

struct rgb
{
    unsigned char red;
    unsigned char blue;
    unsigned char green; //values of red, green and blue in a pixel
};

struct imginfo
{
    int height;
    int width;
    struct rgb **rgb;
};