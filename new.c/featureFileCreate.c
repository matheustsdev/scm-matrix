
// main
int main(int argc, char* argv[]){

    FILE *featureFile;

    char *value = argv[1];
    char txtFile[] = "_quantization.txt";

    char *name = strcat(value, txtFile);

    featureFile = fopen(name, "w"); 
    if(featureFile == NULL){
        puts("File open error: save data to a text file.");
        exit(1);
    }

    //function saveVector

    fclose(featureFile);
}