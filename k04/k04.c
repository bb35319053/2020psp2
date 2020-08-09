#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct D{double ID; int gender; double height;};

int main(void)
{
    int i,j,a,gender;
    double val,id,ID;
    char fname[FILENAME_MAX];
    char fname2[FILENAME_MAX];
    char buf[256],buf2[256];
    FILE* fp, * fp2;
    struct D data[14];
    
    i = 1;
    j = 1;

    printf("input the filename of sample height :");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';

   
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%lf",&gender,&val);

        data[i].gender = gender;
        data[i].height = val;
        i++;

    }
     if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    printf("input the filename of sample ID :");
    fgets(fname2,sizeof(fname2),stdin);
    fname[strlen(fname2)-1] = '\0';

    fp2 = fopen(fname2,"r");
    if (fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf2,sizeof(buf2),fp2) !=NULL){
        sscanf(buf2,"%lf/",&ID);
        j++;
        data[i].ID = ID;
    }
  
    if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    

    printf("which ID's data do you want? :\n");
    scanf("%lf",&id);
    a=1;
    for(i=1;i<=14;i++){
        if(data[i].ID == id){
            printf("ID : %.0lf\n",data[i].ID);
            printf("gender :");
            if(data[i].gender == 1){
                printf("male\n");
            }
            else{
                printf("fmale\n");
                }
            printf("height : %.1lf\n",data[i].height);
            a=0;
        }

    }
    if(a == 1){
        printf("No data");
    }
    return 0;


}

