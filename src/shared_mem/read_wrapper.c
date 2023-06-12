#if defined(USE_IN_MATLAB)
  #if defined(MATLAB_MEX_FILE)
  #include "tmwtypes.h"
  #include "simstruc_types.h"
  #else
  #include "rtwtypes.h"
  #endif
#endif

#include <math.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <windows.h>

#define cfSfunction "BY_ADTECH"
#define edfSfunction "BY_ADTECH"
#define cfEventName "eventName"
#define edfEventName "ventName"
char fileName[60];
char fileName1[60];

FILE *fo;
FILE *fr;
FILE *fw;
double m;
int j;
int i;
float a;
float b;

#define path1 "D:\\3KEY\\Simulinkdata\\read.txt"
#define path2 "D:\\3KEY\\Simulinkdata\\IC.txt"

#define u_width
#define y_width 1


void read_Outputs_wrapper(int32_t *y)
{
    typedef struct
    {
        double cf001[200];
    } cftypeMemory;

    typedef struct
    {
        double edf001[200];
    } edftypeMemory;

    HANDLE cfhModelEvent;
    HANDLE edfhModelEvent;
    HANDLE cfhMapfile;
    HANDLE edfhMapfile;
    double *cfpBuffer;
    double *edfpBuffer;
    static int First = 1;
    static int n = 1;
    cftypeMemory *cfmemory;
    edftypeMemory *edfmemory;
    if (First == 1)
    {
        memset(fileName, '\0', sizeof(fileName)); 
        sprintf(fileName, "%s", path1);
        fo = fopen(fileName, "rt");
        fscanf(fo, "%d", &j);

        memset(fileName1, '\0', sizeof(fileName1)); 
        sprintf(fileName1, "%s", path2);
        fr = fopen(fileName1, "rt");
        for (i = 0; i < j; i++)
        {
            fscanf(fr, "%f", &a);
            y[i] = a;
            fscanf(fr, "\n");
        }
        fclose(fo);
        fclose(fr);
    }
    else
    {
        cfhMapfile = CreateFileMapping((HANDLE)0xFFFFFFFF, NULL, PAGE_READWRITE,
                                       0, 200 * sizeof(double), "cfSfunction");
        cfpBuffer = (double *)MapViewOfFile(cfhMapfile,
                                            FILE_MAP_READ,
                                            0,
                                            0,
                                            200 * sizeof(double));
        cfmemory = (cftypeMemory *)cfpBuffer;
        memset(fileName, '\0', sizeof(fileName)); 
        sprintf(fileName, "%s", path1);
        fo = fopen(fileName, "rt");
        fscanf(fo, "%d", &j);

        for (i = 0; i < j; i++)
        {
            y[i] = cfmemory->cf001[i];
        }
        fclose(fo);

        ResetEvent(cfhModelEvent);
        UnmapViewOfFile(cfpBuffer);
        CloseHandle(cfhMapfile);
    }
    First = First + 1;

    if (n == 1)
    {
    }
    else
    {
        cfhMapfile = OpenFileMapping(FILE_MAP_READ, FALSE, "cfSfunction");
        cfpBuffer = (double *)MapViewOfFile(cfhMapfile, FILE_MAP_READ, 0, 0, 20 * sizeof(double)); // 200---20
        cfmemory = (cftypeMemory *)cfpBuffer;
        m = cfmemory->cf001[101];
        if (m != 0)
        {
            memset(fileName1, '\0', sizeof(fileName));
            sprintf(fileName1, "%s", path2);
            fw = fopen(fileName1, "w+");
            fseek(fw, 0, SEEK_CUR);
            for (i = 0; i < j; i++)
            {
                b = y[i]; 
                fprintf(fw, "%f\n", b);
            }
            fclose(fw);
        }
        UnmapViewOfFile(cfpBuffer);
        CloseHandle(cfhMapfile);
    }
    n = n + 1;
}
