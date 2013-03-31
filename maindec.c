#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
#include "dec.h"
//Ringbuffer S_BUF
char *rbuf;

FILE *input, *output;

int main(int argc, char *argv[])
{
    if(argc<3){
        printf("Corect use is\n lz77_dec.e <inputfile> <outputfile>\n");
        return -1;
    }
    input=fopen(argv[1], "r");
    if(input==NULL){
        printf("Invalid file\n");
        return -1;
    }
   output=fopen(argv[2], "w+");
   if(output==NULL){
       printf("Invalid output path\n");
       fclose(input);
       return -1;
   }

    rbuf=(char *)malloc((S_BUF_LENGTH)*sizeof(char));
    decode(input,output,rbuf);
    fclose(input);
    fclose(output);

    return 1;
}

