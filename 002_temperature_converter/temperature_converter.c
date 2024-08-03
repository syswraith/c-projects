#include <stdio.h>

/* 
   Day 002 Temperature converter
   Things learned:
   - variables
   - while loop 
   - arithmatic operations
   - assignment
   - float limitations
   - right-justification and padding
   - adding just the right amount of zeroes (001, 002, 012, 013, 120, 360)
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
	printf("%6.3d F\t %3d C\n", fahr, celsius);
	fahr += step;
    }
    return 0;
}

