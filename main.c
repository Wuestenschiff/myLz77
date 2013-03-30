#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
#include "enc.h"
//Ringbuffer ...PV_BUF|S_BUF...
char *rbuf;

FILE *input;

int main(int argc, char *argv[])
{
    if(argc==1){
        printf("Please provide a inputefile as first Argument\n");
        return -1;
    }
    input=fopen(argv[1], "r");
    if(input==NULL){
        printf("Invalid file\n");
        return -1;
    }
    rbuf=(char *)malloc((S_BUF_LENGTH+PV_BUF_LENGTH)*sizeof(char));
    initializePV(input,rbuf);
    encode(input,rbuf);

    return 1;
}

