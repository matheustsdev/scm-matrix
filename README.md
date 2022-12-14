# SCM Matrix

This is application of SCM matrix proposed like project in "Laboratório de programação" class.

This application use images, in PMG format, of colon TMA with just one color chanel and the same images after application of a filter. All images are made avaiables by professor.

## Building

This repository have a Makefile file to facilitate the compilation of executable file. So, is just needed use this command:

```bash
  $ make
```

Now is just run it.

## Running

To execute the application is needed inform a quantization level following this rules:

- The quantization level must be a power fo 2;
- The quantization level must be bigger than 0;
- The quantization level must be lower than 256;

The quantization level is informed by CLI on the executation of application, see like below:

```bash
  $ ./main.e <quantization level>
```

The application read all PGM files in images directory and create in the root directory a two files:

- (quantization level)\_quantization.txt, which contain one cooccurrence matrix data like list, and finished with the label of file name, per line;
- readPGMImagesOrder.txt, which contain the file names compareds for each cooccurrence matrix in order of processing.

And you're ready to go!

## Libraries

This application utilize two libraries developed by us. You can see more about they below.

### pgm.h

This libraries is, for the most part, made avaiable by professor and have this struct and this functions:

#### struct pgm

This struct have 5 fields:

- **tipo**: a int, which can be 2, if the pgm have type text, or 5, if the pgm have type binarie;
- **c**: a int number of columns;
- **r**: a int number of rows;
- **mv**: a int number which is the maxval in pgm image;
- **pData**: a pointer of unsigned char, which have all color data of the image.

#### readPGMImage

This function return void and have like parameters:

1. a pointer of one pgm struct, which gonna receive the pgm image data;
2. a pointer of char, a string, which is the name, or relative path, of the file.

#### viewPGMImage

This fucntion return void, but print in terminal all data in a pgm, and have like parameters:

1. a pointer of one pgm struct, which gonna be readed to print in terminal.

#### writePGMImage

This function return void, but create a file with pgm data, and have like parameters:

1. a pointer of one pgm struct, which gonna be readed to write the data;
2. a pointer of char, a string, which is the name, or relative path, of the file which gonna be write.
3. a int which is the max value data in pgm file.

#### quantizationMatrix

This function return void e have like parameters:

1. a pointer of int, which is a pointer of first element of one array and this array gonna receive the quantized data;
2. a pgm struct, which gonna be readed to quantize your data;
3. a int value, which gonna be the quantization level.

### utils.h

This library have some utils structs and functions developed by us. You can see more below.

#### Matrix

This struct have 3 fields:

- **column**: a int number of columns;
- **rows**: a int number of rows;
- **matrix**: a pointer of unsigned char, which have all color data of the image.

#### strArraySort

This function returns void, but sort in alphabetic order a array of strings, and have like parameters:

1. a pointer of pointer of char (\*\*char), which is the array of strings which gonna be ordened;
2. a int, which is the length of the string array.

#### getFilesName

This function returns void, but create a array of strings with name of files in some directory, and have like parameters:

1. a pointer of pointer of char (\*\*char), which is the array of strings which gonna store the names;
2. a pointer of char, a string, which is the relative path of directory.

#### countFilesInDirectory

This function return a int which is the count of files in some directory and have like parameter:

1. a pointer of char, a string, which is the relative path of directory.

#### getCooccurrenceMatrix

This function returns void, but create a cooccurrence matrix, and have like parameters:

1. a pointer of Matrix struct, which gonna receive the data of cooccurrence matrix;
2. a pointer of int, which is the first matrix to compare in cooccurrence;
3. a pointer of int, which is the second matrix to compare in cooccurrence;
4. a int, which is the total of elements in the image;

#### initializeMatrix

This function returns void, but fill a entire matrix with some value, and have like parameters:

1. a pointer of Matrix struct, which gonna be filled with a value;
2. a int, which is the value to fill the matrix.

#### saveVectorInFile

This function returns void, but write a file with matrix in a list format (1, 2, 3, 4, ...), and have like parameters:

1. a pointer of file struct, which is where the data is gonna be writed;
2. a pointer of Matrix struct, which provide the data to write in the file.
