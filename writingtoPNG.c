#include "Pre_def.h"


/* Chaithanya's (IMT2020054) contribution */
void write_png(int width,int height,char inputfilename[],char outputfilename[])
{
    struct PNG_file* file = png_file_format(width,height);
    FILE *fp;
    fp = fopen(outputfilename,"w");
    fwrite(&file->signature.eight_bit_data_support,8,1,fp);
    fwrite(&file->ihdr.size[0],1,1,fp);
    fwrite(&file->ihdr.size[1],1,1,fp);
    fwrite(&file->ihdr.size[2],1,1,fp);
    fwrite(&file->ihdr.size[3],1,1,fp);
    fwrite(&file->ihdr.str[0],1,1,fp);
    fwrite(&file->ihdr.str[1],1,1,fp);
    fwrite(&file->ihdr.str[2],1,1,fp);
    fwrite(&file->ihdr.str[3],1,1,fp);
    fwrite(file->ihdr.width,4,1,fp);
    fwrite(file->ihdr.height,4,1,fp);
    fwrite(&file->ihdr.Bitdepth,1,1,fp);
    fwrite(&file->ihdr.color_type,1,1,fp);
    fwrite(&file->ihdr.compression,1,1,fp);
    fwrite(&file->ihdr.filter,1,1,fp);
    fwrite(&file->ihdr.interlace,1,1,fp);
    fwrite(file->ihdr.crc,4,1,fp);
    fclose(fp);
    idat_writing(inputfilename,outputfilename,file);
    fp=fopen(outputfilename,"a");
    fwrite(&file->iend.size[0],1,1,fp);
    fwrite(&file->iend.size[1],1,1,fp);
    fwrite(&file->iend.size[2],1,1,fp);
    fwrite(&file->iend.size[3],1,1,fp);
    fwrite(&file->iend.str[0],1,1,fp);
    fwrite(&file->iend.str[1],1,1,fp);
    fwrite(&file->iend.str[2],1,1,fp);
    fwrite(&file->iend.str[3],1,1,fp);
    fwrite(file->iend.crc,4,1,fp);
    fclose(fp);
}

/* ends here */