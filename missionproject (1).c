#include <stdio.h>
void write_png(int width,int height,char inputfilename[],char outputfilename[])
{
    struct PNG_file* file = png_file_format(width,height);
    FILE *fp;
    fp = fopen(outputfilename,"w");
    fwrite(&file->signature.eight_bit_data_support,1,8,fp);
    fwrite(&file->ihdr.size[0],1,1,fp);
    fwrite(&file->ihdr.size[1],1,1,fp);
    fwrite(&file->ihdr.size[2],1,1,fp);
    fwrite(&file->ihdr.size[3],1,1,fp);
    fwrite(&file->ihdr.str[0],1,1,fp);
    fwrite(&file->ihdr.str[1],1,1,fp);
    fwrite(&file->ihdr.str[2],1,1,fp);
    fwrite(&file->ihdr.str[3],1,1,fp);
    fwrite(file->ihdr.width,1,4,fp);
    fwrite(file->ihdr.height,1,4,fp);
    fwrite(&file->ihdr.Bitdepth,1,1,fp);
    fwrite(&file->ihdr.color_type,1,1,fp);
    fwrite(&file->ihdr.compression,1,1,fp);
    fwrite(&file->ihdr.filter,1,1,fp);
    fwrite(&file->ihdr.interlace,1,1,fp);
    fwrite(&file->ihdr.crc,1,4,fp);
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
    fwrite(&file->iend.crc,1,4,fp);
    fclose(fp);
}