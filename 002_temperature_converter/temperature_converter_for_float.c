/*
   Day 004: Temperature Converter
   Things learned:
   - For loop
   - Padding revision
   - Float revision
*/


#include <stdio.h>

int main()
{
    float fahr;
    for (fahr = 0.0; fahr <= 200; fahr+=20)
    {
	printf("%3.3f F\t%3.3f C\n", fahr, ((5.0/9.0)*(fahr - 32)));
    }
}
