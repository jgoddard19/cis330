#include <stdio.h>
#include <printf.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int size=25;
	int i;
	int j;
	int array[5][5];
	FILE * f=fopen("2A_binary_file", "br");
	FILE * f2=fopen(argv[2], "w");
	for(i=0; i<5; i++) {
		fread(&array[i], 4 * sizeof(int), 5, f);
		fseek(f, 4 * sizeof(int), SEEK_CUR);
	}
	for(j=0; j<size; j++) {
		printf("array[%d]==%d\n", i, array[i]);
	}
	fclose(f);
	return 0;
}
