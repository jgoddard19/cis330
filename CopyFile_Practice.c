#include <stdio.h>

int main(int argc, char *arvg[]) {
	FILE *f1 = NULL; *f2 = NULL;
	int i = 0;
	int fileSize = 0;
	char *buffer = NULL;
	
	if (argc != 3) {
		printf("Wrong number of arguments!!!\n");
		exit(EXIT_FAILURE);
	}

	f1 = fopen(argv[1], "r");
	if (f1 == NULL) {
		printf("Cannot locate file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	fseek(f1, 0, SEEK_END);
	fileSize = ftell(f1);
	buffer = malloc(fileSize);
	fseek(f1, 0, SEEK_SET);
	fread(buffer, sizeof(char), fileSize, f2);

	f2 = fopen(argv[2], "w");
	fwrite(buffer, sizeof(char), fileSize, f2);

	printf("The number of arguments is %d\n", argc");
	for (i = 0; i < argc; i++) {
		printf("Argument %d is %s\n", i, argv[i]);
	}

	fclose(f2);
	fclose(f1);

	free(buffer);
	return 0;
}
