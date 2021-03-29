
/* controllo delle password
    spicoli piersilvio */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define dim 10 //dimensione massima della pw

int main(){

    //var. locali
    int corretto = 0; //lunghezza
    char pw[dim]; //massimo 10 carr.
    int flag_up; //flag di controllo se esistono i numero
    int flag_num; //flag di controllo se esistono car maiuscoli
    int flag; //controllo di ripetizione una volta che la pw è stata sbaglieta
    int i;


    do{
        flag = 0;//inizializzo a zero

        puts("la pw deve contenere almeno un simbolo e un numero (max. 10 caratteri)\n");
        puts("_> inserire la password: ");
        scanf("%s", pw); //massimo 10 caratteri

        if(strlen(pw) <= dim){ //se la lunghezza non supera i 10 caratteri, allora effettuo i controlli

            flag = 1; //la condizione è vera

            //inizializzo i flag ad ogni iterazione
            flag_up = 0;
            flag_num = 0;

            for(i = 0; i < dim; i++){
                flag_num += isdigit(pw[i]); //controlla ogni carattere se contiene un numero, in tal caso la funzione restituirà 1
                flag_up += isupper(pw[i]); //controlla ogni carattere se esiste la maiuscola, in tal caso la funzione restituirà 1

                //blocca il ciclo nel caso in cui sono stati trovati il carr. maiuscolo e il numero
                if((flag_num == 1)&&(flag_up == 1)){
                    i = dim;
                }
            }

            if((flag_num == 1)&&(flag_up == 1)){

                puts("_> pw corretta!\n");
                puts("_> la pw e' ");
                puts(pw);

            }else if(flag_num == 0){

                flag = 0;
                puts("_> non contiene un numero!\n");

            }else if(flag_up == 0){

                flag = 0;
                puts("_> non contiene un carattere maiuscolo!\n");

            }

        }else{ //altrimenti stampo un messaggio di errore
            flag = 0;
            puts("_> la lunghezza e' maggiore dei 10 caratteri\n");
        }

    }while(flag == 0);



    return 0;
}
