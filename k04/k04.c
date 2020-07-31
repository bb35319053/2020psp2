#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i,j,n,number[14];
    double val;
    char fname[FILENAME_MAX];
    char fname2[FILENAME_MAX];
    char buf[256],gender[6],ID[14];
    FILE* fp;
    FILE* fp2;
    double data[14];
    
    i = 1;
    j = 1;

    printf("input the filename of sample height :");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';

    printf("input the filename of sample ID :");
    fgets(fname2,sizeof(fname2),stdin);
    fname[strlen(fname2)-1] = '\0';

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        sscanf(buf,"%s",&gender[i]);

        data[i] = val;
        i++;

    }

    fp2 = fopen(fname2,"r");
    if (fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(ID,sizeof(ID),fp2) !=NULL){
        sscanf(ID,"%d",&number[j]);
        j++;
    }

    

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("which ID's data do you want? :\n");
    scanf("%d",&ID);

    for(n=1;n<=14;n++){
        if(ID == number[n]){
            printf("---/nID : %d/ngender :%c/nheight :%lf/n",ID, gender[n], data[n]);
        }
    }

    return 0;


}

