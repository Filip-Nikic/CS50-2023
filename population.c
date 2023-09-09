#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int s;
    do
    {
        s = get_int("Starting population size: ");
    }
    while (s < 9);
    // TODO: Prompt for end size
    int e;
    do
    {
        e = get_int("Ending population size: ");
    }
    while (e < s);
    // TODO: Calculate number of years until we reach threshold
    int year=0;
    int pop=s;
    while (pop<e)
    {
        pop=pop+pop/3-pop/4;
        year++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", year);
}
