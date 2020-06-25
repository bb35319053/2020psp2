#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val, double ave);
extern double var_online(double val, double average);

int main(void)
{
    double val, ss;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double average,ave;
    ave = 0;

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
    
        average = ave_online(val, ave);
        ss = var_online( val, average);

        printf("average = %.2f",average);
        printf("value = %.2f",ss);

    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}

double ave_online(double val,double ave)
{
    int i = 1;

    for(i = 1, i <= val, i++);
    {
        ave = (i - 1)*ave/i + val[i]/i;
    }

    return ave;
}

double var_online(double val, double average)
{
    double ss;
    int i;
    for(i = 1, i <= val, i++)
    {
        ss = ss + val[i];
    }

    ss = pow(ss - average,2);

    return ss;
}

