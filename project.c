//converting image from 24 bit BMP format to 8 bit(greyscale) PNG format

//Group 4
//IMT2020033 Bhulaxmi Yash Koushik
//IMT2020103 Jahnavi Challa
//IMT2020045 Mayank Chadha
//IMT2020018 Rachit Agrawal
//IMT2020126 Ayushmaan Singh
//IMT2020054 Chaithanya Reddy Challapalli

#include "Pre_def.h"//included all the function prototype declarations and other libraries in one .h file

int main(int argc , char* argv[])
{
    char input[100];
    strcpy(input,argv[1]); 
    int* dimensions = openbmp(input);
    write_png(dimensions[0],dimensions[1],"pixeldata","output.png");
}

