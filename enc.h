typedef struct Match
{
   unsigned int offset;
   unsigned int length;
}Match;

//Fills the Previewbuffer befor the encoding starts
void initializePV();

//does the actual encoding
void encode();

//shifts charsfrom preview to searchbuffer and refills the preview
void shiftBuf(int num_Of_Chars);

//finds the Matching Strings
Match searchMatch();

//calculate the index of a given char in Previebuffer in the Ringbuffer
int PV_index(int i);

//calculate the index of a given char in Searchbuffer in the Ringbuffer
int S_index(int i);
