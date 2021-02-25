#include "Pre_def.h"

/* Rachit Agrawal's (IMT2020018) contribution */
void int_to_char(char *bytes, int n)
{
    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;
}

struct PNG_file* idat_writing(char filenameinput[],char filenameoutput[],struct PNG_file* file)
{
    FILE* fp1 = fopen(filenameinput,"rb");
    FILE* fp2 = fopen("temp.png","wb+");
    fseek(fp1,0,SEEK_SET);
    def(fp1,fp2,3);
    fseek(fp2,0,SEEK_END);
    unsigned int length = ftell(fp2);

    char data[length];
    int_to_char(file->idat.size,length);
    file->idat.str[0] = 'I';
    file->idat.str[1] = 'D';
    file->idat.str[2] = 'A';
    file->idat.str[3] = 'T';
    fseek(fp2,0,SEEK_SET);
    fread(data,sizeof(char),length,fp2);
    
    char crc_array[4+length];
    crc_array[0] = 'I';
    crc_array[1] = 'D';
    crc_array[2] = 'A';
    crc_array[3] = 'T';
    for(int i = 0;i<length;i++)
    {
        crc_array[4+i] = data[i];
    }
    
    int_to_char(file->idat.crc,crc32(0,crc_array,4+length));
    fclose(fp2);
    remove("temp.png");

    FILE* fp3 = fopen(filenameoutput,"ab");
    fwrite(file->idat.size,sizeof(int),1,fp3);
    fwrite(file->idat.str,sizeof(char),4,fp3);
    fseek(fp1,0,SEEK_SET);   
    def(fp1,fp3,3);
    fwrite(file->idat.crc,sizeof(int),1,fp3);
    fclose(fp1);
    fclose(fp3);
    remove("pixeldata");

    return(file);
}

struct PNG_file* png_file_format(int width,int height)
{   
    struct PNG_file* file;
    file = (struct PNG_file*)malloc(sizeof(struct PNG_file));
    
    file->signature.eight_bit_data_support = 0x89;
    file->signature.format_type[0] = 'P';
    file->signature.format_type[1] = 'N';
    file->signature.format_type[2] = 'G';
    file->signature.dos_line_ending[0] = 0x0D;
    file->signature.dos_line_ending[1] = 0x0A;
    file->signature.dos_display_stop = 0x1A;
    file->signature.unix_line_ending = 0x0A;

    int_to_char(file->ihdr.size,13);
    file->ihdr.str[0] = 'I';
    file->ihdr.str[1] = 'H';
    file->ihdr.str[2] = 'D';
    file->ihdr.str[3] = 'R';
    int_to_char(file->ihdr.width,width);
    int_to_char(file->ihdr.height,height);
    file->ihdr.Bitdepth = (0x8);
    file->ihdr.color_type = (0x0);
    file->ihdr.compression = (0x0);
    file->ihdr.filter = (0x0);
    file->ihdr.interlace = (0x0);
    int_to_char(file->ihdr.crc,crc32(0,(char*)&file->ihdr,17));

    int_to_char(file->iend.size,0);
    file->iend.str[0] = 'I';
    file->iend.str[1] = 'E';
    file->iend.str[2] = 'N';
    file->iend.str[3] = 'D';
    int_to_char(file->iend.crc,crc32(0,(char*)&file->iend,4));
    
    return(file);
}
/* ends here */