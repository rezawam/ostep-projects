#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	for (size_t n = 1; n < argc; n++) {
		FILE *fp = fopen(argv[n], "r");

		if (fp == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}
		char buff[10000];
		while (fgets(buff, sizeof(buff), fp)) {
			printf("%s", buff);
		}
		fclose(fp);
	}

	return 0;
}