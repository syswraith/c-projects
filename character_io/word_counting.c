#include <stdio.h>
#define IN 1
#define OUT 0
/* these state tell the program if the current character means its inside a word or outside a word */

int main()
{
    int c, chars, nls, nws, state;
    state = OUT;

    nls = chars = nws = 0;

    while((c = getchar()) != EOF)
    {
	++chars; /* increment chars */
	if (c == '\n') {++nls;} /* increment nls */
	if (c == '\n' || c == '\t' || c == ' ') {state = OUT;} 
	else if (state == OUT)
	{
	    state = IN;
	    ++nws; /* increment wordcount */
	}
    }
    printf("Characters: %d\tWords: %d\tNewlines: %d\n", chars, nws, nls);
    return 0;
}
