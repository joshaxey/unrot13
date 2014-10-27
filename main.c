/*
 * unrot13.c - rotation 13 substitution cipher file tool
 * Copyright 2014 Josh_Axey
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
