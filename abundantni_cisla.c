#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int abundantni_cisla(int limit)
{
    int i, j, soucet, poc=0;
    int* pole = (int*)malloc(sizeof(int) * limit);

    //projde vsechna cisla
    for (j = 1; j < limit; j++)
        {
            soucet = 0;

            for (i = 2; i <= sqrt(j); i++)
            {
                if ((j % i == 0)&&(i < (j/i)))
                {
                    if(i < j/i)
                        {
                            soucet += j/i;
                        }
                    soucet += i;
                }
            }
            if (soucet > j)
            {
                    poc++;
                    pole[poc-1] = j;
            }
        }
        //return poc;
        //vypis pole
        for (i = 0; i < poc; i++)
            {
                printf ("%i ",pole[i]);
            }
}
int main()
{
    //printf("%i \n",abundantni_cisla(100000));
    abundantni_cisla(1000000);
    return 0;
}
