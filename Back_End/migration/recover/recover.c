#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int loop(FILE *jpeg, FILE *original, BYTE *buffer, int j);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //Open image
    FILE *f = fopen(argv[1], "r");

    //Check failure to obtain adress
    if (f == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    BYTE *buffer = malloc(512);
    if (buffer == NULL)
    {
        return 1;
    }

    //Read blocks in loop until we find the biginning of the jpgs. remember they are stored one next to the other.
    while (!((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0)))
    {

        fread(buffer, sizeof(BYTE), 512, f);

    }

    int j = 0;

    //String for filename
    char filename[((sizeof(int) * 3) + (sizeof(char) * 4))];

    //Store name on string
    sprintf(filename, "%03i.jpg", j);

    //Open file
    FILE *img = fopen(filename, "w");

    //Copy buffer on new file
    fwrite(buffer, sizeof(BYTE), 512, img);

    j++;

    //recursive loop 
    loop(img, f, buffer, j);
    free(buffer);

}



int loop(FILE *jpeg, FILE *original, BYTE *buffer, int j)
{
    //Check for end of file
    int x;
    if ((x = (fread(buffer, sizeof(BYTE), 512, original))) < 512)
    {
        fwrite(buffer, sizeof(BYTE), x, jpeg);
        fclose(jpeg);
        return 1;
    }

    //Check for start of new jpeg
    else if (((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0)))
    {
        //Close previous file
        fclose(jpeg);

        //Repeat process
        char filename[((sizeof(int) * 3) + (sizeof(char) * 4))];

        sprintf(filename, "%03i.jpg", j);

        FILE *img = fopen(filename, "w");

        fwrite(buffer, sizeof(BYTE), 512, img);

        j++;

        loop(img, original, buffer, j);
    }
    
    //Check for continuity of current jpeg
    else
    {
        fwrite(buffer, sizeof(BYTE), 512, jpeg);
        loop(jpeg, original, buffer, j);
    }
    return 1;
}