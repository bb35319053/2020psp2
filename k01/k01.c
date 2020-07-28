#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val, double ave, int n);
extern double var_online(double val, double average, int n, double A);

int main(void)
{
    double val, ss, A, u, se;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double ave;
    ave = 0;
    int n = 1;

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
    
        ave = ave_online(val, ave, n);
         A = (n - 1)*A/n + pow(val,2)/n;
        ss = var_online(val, ave, n, A);
        n++;
    }

    u = (n + 1)*ss/n;
    se = sqrt(u/n);

    printf("sample mean : %.2f \n",ave);
    printf("sample variance : %.2f\n",ss);
    printf("population mean(estimated) : %.2f ± %.2f\n",ave, se);
    printf("population variance(estimated) : %.2f\n",ss);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}

double ave_online(double val,double ave,int n)
{
    
    ave = (n - 1)*ave/n + val/n;

    return ave;
}

double var_online(double val, double ave, int n, double A)
{
    double ss;
   // A = (n - 1)*A/n + pow(val,2)/n;
   ss = A - pow(ave,2);


    return ss;
}

