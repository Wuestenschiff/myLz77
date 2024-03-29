#include "globals.h"
#include <stdio.h>
#include "enc.h"



//Fill the PV_buf
void initializePV(FILE *input, char *rbuf){
    int i=0;
    char c;
    while((i < PV_BUF_LENGTH) &&  (c=fgetc(input))!=EOF){
        rbuf[PV_index(i++)]=c;
    }
    if (c==EOF){
        rbuf[PV_index(i)]=c;
    }
}

void encode(FILE *input, FILE *output, char *rbuf){
    Match match;
    char c;
    while((c=rbuf[PV_index(0)])!=EOF && c!=NULL){
        match=searchMatch(rbuf);
        //debug
       // printf("%d\t%d\t%c\n",match.offset,match.length,rbuf[PV_index(match.length)]);
        Token token={match.offset,match.length,rbuf[PV_index(match.length)]};
        fwrite(&token,sizeof(Token),1,output);
        shiftBuf(match.length+1,input,rbuf);
    }

}

void shiftBuf(int num_Of_Chars, FILE *input, char *rbuf){
    int i;
    char c;
    //shift the rindbuffer
    sBufStart=(sBufStart+num_Of_Chars)%(T_BUF_LENGTH);
    //refill PV_Buf
    for(i=num_Of_Chars-1; i>=0;i--){
          c=fgetc(input);
          rbuf[PV_index(PV_BUF_LENGTH-1-i)]=c;
    }
}

Match searchMatch(char *rbuf){
    Match bestMatch={0,0},match;
    int i1,i2;
    for (i1=S_BUF_LENGTH-1;i1>=0;i1--){
        match.length=0;
        match.offset=0;
        i2=0;
        while(rbuf[S_index(i1+i2)]==rbuf[PV_index(i2)] && i2<PV_BUF_LENGTH){
            match.offset=S_BUF_LENGTH-1-i1;
            match.length=++i2;
        }
        if(match.length>bestMatch.length){
            bestMatch=match;
        }
    }
   return bestMatch;
}

//calculate the index of a given char in Previebuffer in the Ringbuffer
int PV_index(int i){
    return (sBufStart+i+S_BUF_LENGTH)%(T_BUF_LENGTH);
}
//calculate the index of a given char in Searchbuffer in the Ringbuffer
int S_index(int i){
    return (sBufStart+i)%(T_BUF_LENGTH);
}

