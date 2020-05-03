#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
run(void)
{
	double num1, num2, result;
	char operator;

	printf("======================\n");
	printf("======Calculator======\n");
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
	printf("The result is: %f\n", result);
}

static void
help(void)
{
	fputs("Help:\n"
		" -v = version\n"
		" -id = input decimal\n"
		" -ih = input hexadecimal\n"
		" -ib = input binary\n"
		" -od = output decimal\n"
		" -oh = output hexadecimal\n"
		" -ob = output binary\n", stderr);
	exit(1);
}

int
main(int argc, char *argv[])
{
	char version[10] = "1.0alpha\n";

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-v")) {
			printf("calculator-%s", version);
			exit(0);
		} else if (!strcmp(argv[i], "-id")) {
		} else if (!strcmp(argv[i], "-ih")) {
		} else if (!strcmp(argv[i], "-ib")) {
		} else if (!strcmp(argv[i], "-od")) {
		} else if (!strcmp(argv[i], "-oh")) {
		} else if (!strcmp(argv[i], "-ob")) {
		} else {
			help();
			exit(1);
		}
	}
	run();

	return 0;
}