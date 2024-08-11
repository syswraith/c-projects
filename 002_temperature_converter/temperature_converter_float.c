#include <stdio.h>

int main()
{
    int upper, lower, step;
    float celsius, fahr;

    upper = 300;
    lower = 0;
    step = 20;
    fahr = lower;

    while (fahr <= upper)
    {
	celsius = (5.0/9.0)*(fahr-32.0);
	printf("%9.3f\t%6.3f\n", fahr, celsius);
	fahr += step;
    }
    return 0;
}
