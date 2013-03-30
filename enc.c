#include "globals.h"
#include <stdio.h>
#include "enc.h"

//Fill the PV_buf
void initializePV(FILE *input, char *rbuf){
    int i;
    char c;
    while((c=fgetc(input))!=EOF && (i < PV_BUF_LENGTH)){
        rbuf[PV_index(i++)]=c;
    }
}

void encode(FILE *input, char *rbuf){
    Match match;
    while(rbuf[PV_index(0)!=EOF]){
        match=searchMatch(rbuf);
        printf("%d\t&d\t%c\n",match.offset,match.length,rbuf[S_index(match.length)]);
        shiftBuf(input ,match.length+1,rbuf);
    }

}

void shiftBuf(int num_Of_Chars, FILE *input, char *rbuf){
    int i;
    //shift the rindbuffer
    pvBufStart=(pvBufStart+num_Of_Chars)%(T_BUF_LENGTH);
    //refill PV_Buf
    for(i=num_Of_Chars-1; i>=0;i--){
        rbuf[PV_index(PV_BUF_LENGTH-i)]=fgetc(input);
    }
}

Match searchMatch(char *rbuf){
    Match bestMatch={0,0},match={0,0};
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
    return (pvBufStart+i)%(T_BUF_LENGTH);
}
//calculate the index of a given char in Searchbuffer in the Ringbuffer
int S_index(int i){
    return (pvBufStart+i+PV_BUF_LENGTH)%(T_BUF_LENGTH);
}
