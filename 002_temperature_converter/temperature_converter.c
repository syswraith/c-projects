#include <stdio.h>

/* 
   Day 002 Temperature converter
   Things learned:
   - variables
   - while loop 
   - arithmatic operations
   - assignment
   - float limitations
   Do not try writing it ((5/9)(fahr-32)) because 5/9 = 0.5555... and then multiplying fahr (int)
   with float gives a float output and celcius cannot be float
 */

int main()
{
    int fahr, celsius, lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    while (fahr <= upper)
    {
	celsius = (5 * (fahr-32) / 9);
	printf("%d F\t %d C\n", fahr, celsius);
	fahr += step;
    }
    return 0;
}

