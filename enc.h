typedef struct Match
{
   unsigned int offset;
   unsigned int length;
}Match;



//hope I don't have to use this would be ugly
//int reachedEOF=0;

//Fills the Previewbuffer befor the encoding starts
void initializePV(FILE *input,char *rbuf);

//does the actual encoding
void encode(FILE *input, char *rbuf);

//shifts charsfrom preview to searchbuffer and refills the preview
void shiftBuf(int num_Of_Chars, FILE *input, char *rbuf);

//finds the Matching Strings
Match searchMatch(char *rbuf);

//calculate the index of a given char in Previebuffer in the Ringbuffer
int PV_index(int i);

//calculate the index of a given char in Searchbuffer in the Ringbuffer
int S_index(int i);
