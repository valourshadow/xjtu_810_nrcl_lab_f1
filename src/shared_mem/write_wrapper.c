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
#include <string.h>
#include <windows.h>
#include <fstream>

#define cfSfunction "BY_ADTECH"
#define edfSfunction "BY_ADTECH"
#define cfEventName "eventName"
#define edfEventName "ventName"
char fileName[60];
// char pathBase[256];

#define path "D:\\3KEY\\Simulinkdata\\write.txt"
#define path1 "D:\\3KEY\\Simulinkdata\\MapOut.txt"
#define path2 "D:\\3KEY\\Simulinkdata\\snap.txt"

double m;
int j;
int k;
int i;

void write_Outputs_wrapper(const int *u)
{
    FILE *fw;
    FILE *fo;
    FILE *fn;
    
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
    static int n = 1;
    cftypeMemory *cfmemory;
    edftypeMemory *edfmemory;

    edfhMapfile = CreateFileMapping((HANDLE)0xFFFFFFFF, NULL, PAGE_READWRITE, 0, 200 * sizeof(double), "edfSfunction");
    edfpBuffer = (double *)MapViewOfFile(edfhMapfile, FILE_MAP_WRITE, 0, 0, 200 * sizeof(double));
    edfmemory = (edftypeMemory *)edfpBuffer;
    memset(fileName, '\0', sizeof(fileName)); 
    sprintf(fileName, "%s", path);

    fo = fopen(fileName, "rt");
    fscanf(fo, "%d", &k);
    for (i = 0; i < k; i++)
    {
        edfmemory->edf001[i] = u[i];
    }
    fclose(fo);
    memset(fileName, '\0', sizeof(fileName)); 
    sprintf(fileName, "%s", path1);
    fw = fopen(fileName, "a+"); 
    fseek(fw, 30, SEEK_CUR);
    for (i = 0; i < k; i++)
    {
        fprintf(fw, "%f  ", u[i]); 
    }
    fprintf(fw, "\n");
    fclose(fw);
    UnmapViewOfFile(edfpBuffer);
    CloseHandle(edfhMapfile);
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
            memset(fileName, '\0', sizeof(fileName));
            sprintf(fileName, "%s", path2);
            fn = fopen(fileName, "w");
            fseek(fn, 0, SEEK_CUR);
            fprintf(fn, "\n");
            fclose(fn);
        }
        UnmapViewOfFile(cfpBuffer);
        CloseHandle(cfhMapfile);
    }
    n = n + 1;
    edfhModelEvent = CreateEvent(NULL, FALSE, FALSE, edfEventName);
    cfhModelEvent = CreateEvent(NULL, FALSE, FALSE, cfEventName);
    SetEvent(edfhModelEvent);
    WaitForSingleObject(cfhModelEvent, INFINITE);
}
