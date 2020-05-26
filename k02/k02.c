#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z, double mu, double var);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;
    double mu, var;
    double mu_A, mu_B;
    double var_A, var_B;

    mu_A=170.8;
    mu_B=169.7;
    var_A=pow(5.43,2);
    var_B=pow(5.5,2);

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

        L1 = L1*p_stdnorm(val, mu_A, var_A);
        L2 = L2*p_stdnorm(val, mu_B, var_B);



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Likelihood for A: %f\n",L1);
    printf("Likelihood for B: %f\n",L2);

    return 0;


}

double p_stdnorm(double z, double mu, double var)
{
    return 1/sqrt(2*M_PI*var) * exp(-pow(z - mu,2)/(2*var));
}

