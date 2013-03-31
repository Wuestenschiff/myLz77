#include "globals.h"
#include <stdio.h>
#include "dec.h"

void decode(FILE *input,FILE *output, char *rbuf){
    Token token;
    int i;
    char c;
    while(fread(&token,sizeof(Token),1,input)==1){
        for(i=0;i<token.length;i++){
            c=rbuf[S_index(S_BUF_LENGTH-1+token.offset)];
            sBufStart--;
            rbuf[S_index(S_BUF_LENGTH-1)]=c;
            fprintf (output, "%c",c);
        }
        c=token.c;
        sBufStart--;
        rbuf[S_index(S_BUF_LENGTH-1)]=c;
        fprintf (output, "%c",c);
    }
}

int S_index(int i){
    return (sBufStart+i)%S_BUF_LENGTH;
}
