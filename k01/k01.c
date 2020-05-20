#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave)
extern double var_online()

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
    
    ave = ave_online(val,ave);
    printf("average = %.2f",ave);

    printf("value = %.2f",val);

    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}

double ave_online(double val,double ave)
{
    double ss;
    ave = 0;

    for(i = 1, i <= val, i++)
    {
        ss = (i - 1)*pow(ave,2)/i + val[i]/i - (i - 1)*ave/i + val[i]/i;
        ave = (i - 1)*ave/i + val[i]/i;
    }

    printf("average = %f", ave);
    printf("value = %f", ss);
}


