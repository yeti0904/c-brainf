#include <stdio.h>
#include <string.h>
int main() {
	printf("C Brainf***\nMade by MESYETI\n");
	int i;
	int i2;
	unsigned int cellAt = 0; // which cell is selected
	unsigned int cells[30000] = { 0 }; // 30000 cells for the program
	char program[29999]; // where the program will be stored
	char op; // operator in the program
	int used = 0;
	int loopBegin;
	int toprint;
	char commaOP; // , operator
	printf("Type your Brainf*** program here> ");
	scanf("%s", program);
	printf("\n");
	for (i = 0; i < strlen(program); i++) {
		op = program[i];
		switch (op) {
			case '+': {
				++ cells[cellAt];
				break;
			}
			case '-': {
				-- cells[cellAt];
				break;
			}
			case '>': {
				++ cellAt;
				++ used;
				break;
			}
			case '<': {
				-- cellAt;
				break;
			}
			case '[': {
				if (cells[cellAt] != 0) {
					loopBegin = i;
				}
				else {
					while (program[i] != ']') {
						++ i;
					}
				}
				break;
			}
			case ']': {
				if (cells[cellAt] == 0) {
					break;
				}
				else {
					i = loopBegin;
				}
				break;
			}
			case '.': {
				toprint = cells[cellAt];
				printf("%c", (char)toprint);
				break;
			}
			case ',': {
				cells[cellAt] = getchar();
				break;
			}
		}
	}
	printf("\nProgram finished.\nThe cell view will now be displayed, how many cells do you want to view? ");
	int view;
	scanf("%i",&view);
	printf("\n");
	for(i=0 ; i<view ; i++) {
		printf("[ %u ] ", cells[i]);
	}
	++ cellAt;
	printf("\nThe program finished at cell %i.\n", cellAt);
	return 0;
}