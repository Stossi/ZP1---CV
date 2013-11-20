#include <stdio.h>
#include <stdlib.h>

//struktura datum
typedef struct{
    char den, mesic;
    short rok;
}datum;

//struktura transakce
typedef struct{
   double castka;
   double varsymbol;
   datum splatnost;
}transakce;

//vypis jednotlivych transakci
void vypis_transakce(transakce tran){
    if (tran.varsymbol <= 10000000000){
        printf ("%3.2f, %3.0f, %i.%i.%i \n\n", tran.castka, tran.varsymbol, tran.splatnost.den, tran.splatnost.mesic, tran.splatnost.rok);
    }
    else{
        printf ("Neplatny variabilni symbol\n");
    }
}

//porovnani transakci
int porovnej_splatnost(transakce t1, transakce t2){
    if(t1.splatnost.rok < t2.splatnost.rok){
        return -1;
    }
    else if(t1.splatnost.rok == t2.splatnost.rok){
        if (t1.splatnost.mesic < t2.splatnost.mesic){
            return -1;
        }
        else if(t1.splatnost.mesic == t2.splatnost.mesic){
            if (t1.splatnost.den < t2.splatnost.den){
                return -1;
            }
            else if(t1.splatnost.den == t2.splatnost.den){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 1;
    }
}

int main(){
    transakce najem = {11000, 2012125, 1, 12, 2012};
    transakce mzda = {29537.32, 201212587, 16, 12, 2012};
    vypis_transakce(najem);
    vypis_transakce(mzda);
    porovnej_splatnost(najem, mzda);
}
