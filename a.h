struct PNGSignature
{
    unsigned char eight_bit_data_support;
    unsigned char format_type[3];
    unsigned char dos_line_ending[2];
    unsigned char dos_display_stop;
    unsigned char unix_line_ending;
};


struct IHDR_Chunk
{
    char str[4];
    unsigned char width[4];               /* Width of image in pixels */
    unsigned char height[4];             /* Height of image in pixels */
    unsigned char Bitdepth;      /* Bits per pixel or per sample */
    unsigned char color_type;    /* Color interpretation indicator */
    unsigned char compression;   /* Compression type indicator */
    unsigned char filter;        /* Filter type indicator */
    unsigned char interlace;     /* Type of interlacing scheme used */
    unsigned char size[4];     
    unsigned char crc[4];
};


struct IDAT 
{
    unsigned char str[4];
    unsigned char size[4];
    unsigned char crc[4];
};

struct IEND
{
    unsigned char str[4];
    unsigned char size[4];
    unsigned char crc[4];
};

struct PNG_file
{
    struct PNGSignature signature;
    struct IHDR_Chunk ihdr;
    struct IDAT idat;
    struct IEND iend;
};