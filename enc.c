
//Fill the
void initializePV(){
    while((c=getchar())!=EOF )
}

void encode();
void shiftBuf(int num_Of_Chars);
Match searchMatch();

//calculate the index of a given char in Previebuffer in the Ringbuffer
int PV_index(int i){
    return (pvBufStart+i)%(S_BUF_LENGTH+PV_BUF_LENGTH);
}
//calculate the index of a given char in Searchbuffer in the Ringbuffer
int S_index(int i){
    return (pvBufStart+i+PV_BUF_LENGTH)%(S_BUF_LENGTH+PV_BUF_LENGTH)
}
