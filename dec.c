#include "globals.h"
#include <stdio.h>
#include "dec.h"

void decode(FILE *input,FILE *output, char *rbuf){
    Token token;
    int i;
    char c;
    while(fread(&token,sizeof(Token),1,input)==1){
        //dealing with matching token
        for(i=0;i<token.length;i++){
            //get Matching chars
            c=rbuf[S_index(S_BUF_LENGTH-1-token.offset)];
            //shift Buffer
            sBufStart=(sBufStart+1)%S_BUF_LENGTH;
            //fill buffer with new char
            rbuf[S_index(S_BUF_LENGTH-1)]=c;
            fprintf(output, "%c",c);
        }
        //add the new char to buffer (but not eof)
        c=token.c;
        sBufStart=(sBufStart+1)%S_BUF_LENGTH;
        rbuf[S_index(S_BUF_LENGTH-1)]=c;
        if(c!=EOF){
            fprintf(output, "%c",c);
        }
    }
}

int S_index(int i){
    return (sBufStart+i)%S_BUF_LENGTH;
}
