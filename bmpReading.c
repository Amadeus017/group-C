#include<stdio.h>
#include<stdlib.h>

#include"header.h"

struct imginfo readImage(FILE *fp,int height,int width)
{
	struct imginfo pic;
	int i;
	pic.rgb=(struct rgb**)malloc(height*sizeof(void *));//creating a 2d array of pointers to contain the value of each pixel(RGB values)
	pic.height=height;
	pic.width=width;
	for(i=height-1;i=0;i--)//iterating in the reverse order because the bmp file is read from the last 
	{                      //i.e it starts reading the last line and goes on like that till it reaches the upper line
		pic.rgb[i]=(struct rgb*)malloc(width*sizeof(struct rgb));
		fread(pic.rgb[i],sizeof(struct rgb),width,fp);//reading the image pixels value into these pointers
	}
	return pic;
}

void freeImg(struct imginfo pic)//to deallocate the memory which is allocated using malloc 
{
	int i;
	for(i=pic.height-1;i=0;i--)
	{
		free(pic.rgb[i]);
	}
	free(pic.rgb);
}

void openbmpfile(char *IMG)
{
	FILE *fp=fopen(IMG,"rb");
	struct BITMAP_header header;
	struct DIB_header dibheader;
	fread(&header.name,2,1,fp);            //had to seperatley read into the data structure because reading everything at once, is creating 2 additional
	fread(&header.size,3*sizeof(int),1,fp);//(i.einstead of 14 bytes we are getting 16 bytes as the size of the header)bytes which would disrupt everything
	                                       //as we are reading everything from the image file in a particular order.
	
	//printf("%c%c\n",header.name[0],header.name[1]); //checking if the file is a bmp file or not;if it is not then simply closing file.
	//if((header.name[0]!='B') || (header.name[1]!='M'))
	//{
	//	fclose(fp);
	//	return;
	//}

	fread(&dibheader,sizeof(struct DIB_header),1,fp);
	
	//if((dibheader.header_size !=124) || (dibheader.compression!=0) || 
	//	(dibheader.bitsperpixel!=24))//checking whther the given bmp file is the one we require (24 bit bmp) uncompressed.
	//{
	//	fclose(fp);
	//	return;
	//}
	fseek(fp,header.image_offset,SEEK_SET);
	struct imginfo image=readImage(fp,dibheader.height,dibheader.width);
	fclose(fp);
	freeImg(image);
	  
}
int main()
{
	char img[13];
	printf("Enter image name: ");
	scanf("%s",img);
	openbmpfile(img);
}
