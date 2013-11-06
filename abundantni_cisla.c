#include <stdio.h>
#include <stdlib.h>

int abundantni_cisla(int limit)
{
    int i, j = 28123, soucet, poc=0;
    int* pole = (int*)malloc(sizeof(int) * limit);

    for (j = 100000; j > 0; j--)
        {
            soucet = 0;

            for (i = 2; i < j; i++)
            {
                if (j % i == 0)
                {
                    //pole[i] = i;
                    soucet += i;//pole[i];
                }
            }
            if (soucet > j)
            {
                    poc++;
                    pole[poc-1] = j;
                    //printf("%i ", pole[poc]);
            }
        }
        for (i = 0; i < poc; i++)
            {
                /*for(j = i; j < poc; j++)
                    {
                        if (pole[i] + pole[j] <= limit)
                            {
                                printf ("%i ",pole[i]);
                            }
                    }*/
                printf ("%i ",pole[i]);
            }

}
int main()
{
    abundantni_cisla(100000);
    return 0;
}
