#include "ttifunc.h"

void fill_arr(double *arr, const unsigned int size)
{
    srand(time(NULL));
    for (unsigned int i = 0; i < size; i++)
    {
        arr[i] = rand() % (51 - 35) + 35;
    }
}

void printf_arr(double *arr, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%.2lf ", arr[i]);
    }
}

void tti(double *height, double *weight, const unsigned int size, double *tti)
{
    for (unsigned int i = 0; i < size; i++)
    {
        tti[i] = weight[i] / (height[i] * height[i]);
        printf("TTI %u. child = %.2lf\n", i + 1, tti[i]);
    }
}

void max_sort(const unsigned int size, double *TTI)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(TTI[i]<TTI[j])
            {
                double tmp=TTI[i];
                TTI[i]=TTI[j];
                TTI[j]=tmp;
            }
        }
    }
}

void read_str(char *string)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me the type of the TTI ('sovany (slim)', 'normalis (normal)', 'elhizott (fat)') : ");
        if (scanf("%[^\n]", string) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
        } else if (strcmp(string, "sovany") != 0 && strcmp(string, "normalis") != 0 && strcmp(string, "elhizott") != 0 && strcmp(string, "slim") != 0 && strcmp(string, "normal") != 0 && strcmp(string, "fat") != 0)
        {
            printf("Bad input format!\n");
            ok = false;
            while (getchar() != '\n');
        }
    } while (!ok);
}

void tti_type(double *tti, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        if (tti[i] < 18.5)
        {
            printf("Child #%u is 'sovany'.\n", i + 1);
        } else if (tti[i] <= 25 && tti[i] >= 18.5)
        {
            printf("Child #%u is 'normalis'.\n", i + 1);
        } else if (tti[i] > 25)
        {
            printf("Child #%u is 'elhizott'.\n", i + 1);
        }
    }
}

TT_details *TT_system(const unsigned int size, double *TTI, char *string)
{
    TT_details *out = malloc(size * sizeof(TT_details));
    double *tt_filtered = malloc(size * sizeof(double));
    out->size = 0;
    if(strcmp(string, "sovany") == 0 || strcmp(string, "slim") == 0)
    {
        for(int i = 0; i < size; i++)
        {
            if(TTI[i] < 18.5)
            {
                tt_filtered[out -> size] = TTI[i];
                out -> size++;
            }
        }
    }
    else if(strcmp(string, "normalis") == 0 || strcmp(string, "normal") == 0)
    {
        for(int i = 0; i < size; i++)
        {
            if(TTI[i] > 18.5 && TTI[i] <= 25)
            {
                tt_filtered[out -> size] = TTI[i];
                out -> size++;
            }
        }
    }
    else if (strcmp(string, "elhizott") == 0 || strcmp(string, "fat") == 0)
    {
        for(int i = 0; i < size; i++)
        {
            if(TTI[i] > 25)
            {
                tt_filtered[out -> size] = TTI[i];
                out -> size++;
            }
        }
    }
    out -> TT = tt_filtered;
    return out;
}

void file_write(TT_details *TT_all)
{
    FILE *file = fopen("TTI.txt", "wa");
    for(int i = 0; i < TT_all -> size; i++)
    {
        fprintf(file, "TTI %d.: %.2lf\n", i + 1, TT_all -> TT[i]);
    }
    fclose(file);
}