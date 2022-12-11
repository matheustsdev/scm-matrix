
void saveVector(FILE *featureFile, int *matrix, int rows, int column){

    int pos = 0;

    for(int i = 0; i < column*rows; i++){
        fprintf(featureFile, "%d, ", *(matrix + i)); // convert integer to string
    }

    fseeko(featureFile, -2, SEEK_END); // change file position 
    pos = ftello(featureFile); //get position value
    ftruncate(fileno(featureFile), pos); //delete 

    putc('\n', featureFile);
}