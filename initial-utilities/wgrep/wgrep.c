#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc == 1) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}
	char *search = argv[1];
	if (argc == 2) {
		char buff[10000];
		while (fgets(buff, sizeof(buff), stdin)) {
			if (strstr(buff, search)) {
				printf("%s", buff);
			}
		}
	}

	for (int n = 2; n < argc; n++) {
		FILE *fp = fopen(argv[n], "r");

		if (fp == NULL) {
			printf("wgrep: cannot open file\n");
			exit(1);
		}
		char *buff = NULL;
		size_t size = 0;

		while (getline(&buff, &size, fp) != -1) {
			if (strstr(buff, search)) {
				printf("%s", buff);
			}
		}
		fclose(fp);
	}

	return 0;
}