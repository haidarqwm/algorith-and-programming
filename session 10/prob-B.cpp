#include <stdio.h>
#include <string.h>

struct orang
{
    char nama[15];
    int nilai;
};

int main ()
{
    int testCase;
    int ngulang;
    int index = 0;
    char searchBy[15];
    struct orang murid[1001];
    struct orang sementara;
    scanf("%d", &testCase);
    for(int i = 0; i < testCase; i++)
    {
        scanf("%d", &ngulang);
        for(int j = 0; j < ngulang; j++)
        {
            scanf(" %[^#]#%d", &murid[j].nama, &murid[j].nilai);
        }
        for(int l = 0; l < ngulang-1; l++)
        {
            for(int k = 0; k < ngulang-1; k++)
            {
                if(murid[k].nilai < murid[k+1].nilai)
                {
                    sementara = murid[k];
                    murid[k] = murid[k+1];
                    murid[k+1] = sementara;
                }
                if(murid[k].nilai == murid[k+1].nilai)
                {
                    if(strcmp(murid[k].nama, murid[k+1].nama) > 0)
                    {
                        sementara = murid[k];
                        murid[k] = murid[k+1];
                        murid[k+1] = sementara;
                    }
                }
            }
        }
        scanf("%s", searchBy);
        for(int m = 0; m < ngulang; m++)
        {
            if(strcmp(murid[m].nama, searchBy) == 0)
            {
                index = m;
                break;
            }
        } 

        printf("Case #%d: %d\n", i+1, index+1);
    }


    return 0;
}