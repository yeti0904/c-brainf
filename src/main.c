#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	printf("C Brainf***\nMade by MESYETI\n");
	int i, i2, loopBegin, toprint;
	unsigned int cellAt = 0; // which cell is selected
	unsigned int cells[30000] = { 0 }; // 30000 cells for the program
	char program[29999], op, commaOP; // where the program will be stored
	// program: bf program
	// op: current operator in interpreter
	// commaOP: where input from the ',' operator is stored
	int used = 0;
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
				putchar(cells[cellAt]);
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