#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple calculator */

static void run(void);

static void help(void);

int
main(int argc, char *argv[])
{
	char version[10] = "1.0alpha\n";
	int input;

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-v")) {
			printf("calculator-%s", version);
			exit(0);
		} else if (!strcmp(argv[1], "-id")) {
			sscanf(argv[2], "%d", &input);
			printf("Input Decimal: %s\n", argv[2]);
			if (!strcmp(argv[3], "-od"))
				printf("Result in decimal is: %d\n", input);
			else if (!strcmp(argv[3], "-oh"))
				printf("Result in hexadecimal is: %X\n", input);
		} else if (!strcmp(argv[1], "-ih")) {
			sscanf(argv[2], "%x", &input);
			printf("Input Hexadecimal: %s\n", argv[2]);
			if (!strcmp(argv[3], "-od"))
				printf("Result in decimal is: %d\n", input);
			else if (!strcmp(argv[3], "-oh"))
				printf("Result in hexadecimal is: %X\n", input);
		} else {
			help();
			exit(1);
		}
		exit(0);
	}
	run();
	return 0;
}

static void
run(void)
{
	double num1, num2, result;
	char operator;

	printf("======================\n");
	printf("===== Calculator =====\n");
	printf("======================\n");
	printf("\nCalculate 2 numbers\n");
	printf("Digit a number: ");
	scanf("%lf", &num1);
	printf("Digit an operator: ");
	scanf(" %c", &operator);
	printf("Digit another number: ");
	scanf("%lf", &num2);

	switch(operator) {
		default:
			  fputs("Invalid operator\n"
				"Try (+, -, *, /)\n", stderr);
			  exit(1);
			  break;
		case '+':
			  result = num1 + num2;
			  break;
		case '-':
			  result = num1 - num2;
			  break;
		case '*':
			  result = num1 * num2;
			  break;
		case '/':
			  result = num1 / num2;
			  break;
	}
	printf("The result is: %.2f\n", result);
}

static void
help(void)
{
	fputs("Help:\n"
		" -v = version\n"
		" -id = input decimal\n"
		" -ih = input hexadecimal\n"
		" -od = output decimal\n"
		" -oh = output hexadecimal\n", stderr);
	exit(1);
}
