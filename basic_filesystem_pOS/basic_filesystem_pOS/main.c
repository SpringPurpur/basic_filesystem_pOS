#include <stdio.h>
#include <direct.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

void logo() {
	printf(" _____ _        _  ____   _____ \n");
	printf("|  __ (_)      | |/ __ \\ / ____|\n");
	printf("| |__) | ______| | |  | | (___  \n");
	printf("|  ___/ |_  / _` | |  | |\\___ \\ \n");
	printf("| |   | |/ / (_| | |__| |____) |\n");
	printf("|_|   |_/___\\__,_|\\____/|_____/ \n\n");
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