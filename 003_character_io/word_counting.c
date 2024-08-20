/*
Things learned:

*/

#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{
    int c, chars, nls, nws, state;
    state = OUT;

    nls = chars = nws = 0;

    while((c = getchar()) != EOF)
    {
	++chars;
	if (c == '\n') 
	{++nls;}
	if (c == '\n' || c == '\t' || c == ' ') 
	{state = OUT;}
	else if (state == OUT)
	{
	    state = IN;
	    ++nws;
	}
    }
    printf("Characters: %d\tWords: %d\tNewlines: %d\n", chars, nws, nls);
    return 0;
}
