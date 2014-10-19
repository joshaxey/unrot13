#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    unsigned char *inBuf, *outBuf;
    int d, b;
    char c;

    fin = fopen("myfilein.bin","rb");
    fout = fopen("myfileout.bin","wb");

    inBuf = malloc(0x20000000*sizeof(char));
    outBuf = malloc(0x20000000*sizeof(char));

    setvbuf( fin , inBuf, _IOFBF , 0x20000000 );
    setvbuf( fout , outBuf, _IOFBF , 0x20000000 );

    while(1)
    {
        d = fgetc(fin);
        if(d != EOF)
        {
            c = d;
            if (('a' <= c && 'n' > c) || ('A' <= c && 'N' > c))
                b = c + 13;
            else if (('n' <= c && 'z' >= c) || ('N' <= c && 'Z' >= c))
                b = c - 13;
            else
                b = c;
            fputc(b, fout);
        }
        else
        {
            fclose(fin);
            fclose(fout);
            break;
        }
    }

    return 0;
}