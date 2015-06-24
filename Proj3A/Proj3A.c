#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	unsigned char *buffer;
	int width, height, maxval;
} Image;

Image *
ReadImage(char *filename)
{
	FILE *f = fopen(filename, "rb");
	Image *img = NULL;
	char magicNum[128];
	int  width, height, maxval;

	if (f == NULL)
	{
		fprintf(stderr, "Unable to open file %s\n", filename);
		return NULL;
	}

	fscanf(f, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
/*
	printf("Magic num = %s width = %d, height = %d, maxval = %d\n",
			magicNum, width, height, maxval);
 */

	if (strcmp(magicNum, "P6") != 0)
	{
		fprintf(stderr, "Unable to read from file %s, because it is not a PNM file of type P6\n", filename);
		return NULL;
	}
	
	img = malloc(sizeof(Image));
	img->width = width;
	img->height = height;
	img->buffer = malloc(sizeof(unsigned char)*3*img->height*img->width);
	fread(img->buffer, sizeof(unsigned char), 3*img->height*img->width, f);
	fclose(f);
	return img;
}


void WriteImage(Image *img, char *filename)
{
	FILE *f = fopen(filename, "wb");
	fprintf(f, "P6\n%d %d\n255\n", img->width, img->height);
	fwrite(img->buffer, sizeof(unsigned char), 3*img->height*img->width, f);
	fclose(f);
}

Image *
YellowDiagonal(Image *input)
{
	Image *output;
	output = malloc(sizeof(Image));
	output->height = input->height;
	output->width = input->width;
	output->buffer = malloc(3*output->height*output->width);
	memcpy(output->buffer, input->buffer, 3*output->height*output->width);
	int temp = 0;
	for(int i = 0; i < output->width; i++)
	{
		if(i < output->height)
		{
			temp = 3*(output->width*i+i);
			output->buffer[temp] = 255;
			output->buffer[temp+1] = 255;
			output->buffer[temp+2] = 0;
		}
	}
	return output;
}

int main(int argc, char *argv[])
{
	char *i;
	i = argv[1];
	Image *img;
	img = ReadImage(i);
	img = YellowDiagonal(img);
	WriteImage(img, argv[2]);
	free(img);
}
