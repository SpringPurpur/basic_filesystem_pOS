#include <stdio.h>
#include <direct.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

void logo() {
	printf("  _____      _      _             _  ____   _____ \n");
	printf(" |  __ \\    (_)    | |           (_)/ __ \\ / ____|\n");
	printf(" | |__) | __ _  ___| |_ ___ _ __  _| |  | | (___  \n");
	printf(" |  ___/ '__| |/ _ \\ __/ _ \\ '_ \\| | |  | |\\___ \\ \n");
	printf(" | |   | |  | |  __/ ||  __/ | | | | |__| |____) |\n");
	printf(" |_|   |_|  |_|\\___|\\__\\___|_| |_|_|\\____/|_____/ \n\n");
}



int main(int argc, char* argv[]) {
	logo();
	char workingDirectory[BUFFER_SIZE] = { '\0' };
	char userInput[BUFFER_SIZE] = { '\0' };
	while (strcmp(userInput, "exit") != 0) {
		if (_getcwd(workingDirectory, sizeof(workingDirectory)) != NULL) {
			printf("%s>", workingDirectory);
		}
		else {
			perror("_getcwd() error. Path could not be retrieved");
			return 1;
		}
		scanf_s("%1023s", &userInput, BUFFER_SIZE - 1);
	}
	return 0;
}
