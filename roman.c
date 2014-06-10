/*
####################################################################
GLOBAL INCLUDES
####################################################################
*/

#include <stdio.h>
#include <string.h>

/*
####################################################################
CODE
####################################################################
*/

//This function assumes the string is in the correct roman form and in CAPS
int
roman_to_dec(char *roman){
    int i,sum;
    char letter='I';

    i=0;
    while(roman[i++]) i++;


    while(i>=0){

        switch(roman[i]){
            case 'I':
                if(letter == 'V'    ){
                    sum -=1;
                }else{
                    sum +=1;
                }
            break;

            case 'V':
                if(letter == 'X'    ){
                    sum -=5;
                }else{
                    sum +=5;
                    letter = 'V';
                }
            break;

            case 'X':
                if(letter == 'L'    ){
                    sum -=10;
                }else{
                    sum +=10;
                    letter = 'X';
                }
            break;

            case 'L':
                if(letter == 'C'    ){
                    sum -=50;
                }else{
                    sum +=50;
                    letter = 'L';
                }
            break;

            case 'C':
                if(letter == 'D'    ){
                    sum -=100;
                }else{
                    sum +=100;
                    letter = 'C';
                }
            break;

            case 'D':
                if(letter == 'M'    ){
                    sum -=500;
                }else{
                    sum +=500;
                    letter = 'D';
                }
            break;

            //There are bigger numbers, but are not supported by ASCII
            case 'M':
                sum +=1000;
                letter = 'M';
            break;
        }

        i--;
    }

    printf("%d\n", sum);
}

int
main(int argc, char **argv){

    roman_to_dec(argv[1]);

    return 0;
}
