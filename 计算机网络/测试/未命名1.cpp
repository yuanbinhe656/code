#include <stdio.h>
int main()
{
	char ch;
	int letter=0;
	int digit = 0;
	int other = 0;
	
	while (scanf("%c", &ch), ch != '\n')
	{
		if (ch >= '0' && '9' >= ch)
		{
			digit = digit + 1;
		}
		else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			letter = letter + 1;
		}
		else
			other = other + 1;
	}
	printf("letter: %d\n", letter);
	printf("digit: %d\n", digit);
	printf("other: %d\n", other);
	return 0;
}


