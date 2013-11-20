#include <stdio.h>
#include <stdlib.h>

//nejmensi spolecny delitel
int gcd(int a, int b) {
  if (b == 0){
    return a;
  }
  return gcd(b, a % b);
}

//nejmensi spolecny nasobek
int lcm(int a, int b) {
  if (a == 0 || b == 0){
    return 0;
  }
  return (a * b) / gcd(a, b);
}

//struktura zlomku
typedef struct{
   int citatel;
   int jmenovatel;
}Zlomek;

//funkce vracejici zlomek
void vypis_zlomek(Zlomek zlomek){

    printf ("zlomek je: %i/%i", zlomek.citatel, zlomek.jmenovatel);
}

//funkce pro vypocet souctu zlomku
Zlomek soucet_zlomku(Zlomek z1, Zlomek z2){

    //soucet zlomku
    int n_nas = lcm(z1.jmenovatel, z2.jmenovatel);
    Zlomek soucet;
    soucet.citatel = ((n_nas/z1.jmenovatel)*z1.citatel) + ((n_nas/z2.jmenovatel)*z2.citatel);
    soucet.jmenovatel =  n_nas;

    int euklid = gcd(soucet.citatel, soucet.jmenovatel);
    soucet.citatel = soucet.citatel/euklid;
    soucet.jmenovatel = soucet.jmenovatel/euklid;

    return soucet;
}

int main(){
    Zlomek z1 = {2, 3};
    Zlomek z2 = {1, 6};
    Zlomek soucet = soucet_zlomku(z1, z2);
    vypis_zlomek(soucet);
}
