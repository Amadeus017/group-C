#include <stdio.h>
#include <stdlib.h>

int openbmpfile()
{
    FILE *fp = fopen("pic.bmp", "rb");
    struct BITMAP_header header;
    struct DIB_header dib;
    printf("%d\n", sizeof(struct BITMAP_header header));
    if ((header.name[0] != 'B') || (header.name[1] != 'M'))
        {
            fclose(fp);
            return 1; 
        }
    fread(header.name, 2, 1, fp);
    fread(&header.size, 3 * sizeof(int), 1, fp);
    //fread(&header, sizeof(struct BITMAP_header), 1, fp);
    printf("First two characters: %c%c\n", header.name[0], header.name[1]);
    printf("Size: %d\n", header.size);
    printf("Offset: %d\n", header.image_offset);
    fread(&dib, sizeof(struct DIB_header), 1, fp);
    printf("Header size: %d\nWidth: %d\nHeight: %d\nColor planes: %d\nBits per plane: %d\nCompression: %d\nImage size: %d\n", dib.header_size, dib.width, dib.height, dib.colorplane, dib.bpp, dib.comp, dib.image_size);
    
    if ((dib.header_size != 40) || (dib.comp != 0) || (dib.bpp == 24))
    {
        fclose(fp);
        return 1;
    }
    fseek(fp, header.image_offset, SEEK_SET);


    fclose(fp);
}

int main()
{
    openbmpfile();
}
