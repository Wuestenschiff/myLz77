#include <stdio.h>
#include 'enc.h'


int const S_BUF_LENGTH=1024;
int const PV_BUF_LENGTH=256;
int pvBufStart=0;

char* rbuf;

int main(void)
{
    rbuf=malloc (S_BUF_LENGTH+PV_BUF_LENGTH)*sizeof(char);


}

