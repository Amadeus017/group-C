
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "zlib.h"
#include <assert.h>
#include "PNG_data_structure.h"
#include "BMP_data_structure.h"


#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif

#define CHUNK 16384

int def(FILE *source, FILE *dest, int level);
void write_png(int width,int height,char inputfilename[],char outputfilename[]);
void int_to_char(char *bytes, int n);
struct PNG_file* idat_writing(char filenameinput[],char filenameoutput[],struct PNG_file* file);
struct PNG_file* png_file_format(int width,int height);
struct Image readimage(FILE *fp, int height, int width);
void freeImage(struct Image pic);
int* openbmp(char * );
unsigned char grayscale(struct RGB rgb);
void RGBImageToGrayscale(struct Image pic);
int createBWImage(struct bmp header, struct DIB_header dibheader, struct Image pic);