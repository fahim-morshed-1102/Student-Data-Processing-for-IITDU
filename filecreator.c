/**
 *                                                     complete
 **/
#include<stdio.h>
#include<string.h>

extern struct profile{
    char name[21];
    char address[81];
    char roll[9];
    int reg_num;
    float cgpsem[8];
    int marks[8][6];
} student[140];
extern char fnameInf[];
extern char fnameBat[];

/**
 *                                         sob information structure e niye aste
 **/

void informationTaker(void){
    int i,j,k,batch,serial;
    FILE* fp;

    for(i=0;i<140;i++){                      /** 140 joner data nite **/
        batch=i/35+8;
        serial=i%35+1;

        fnameInf[0]= batch/10+'0';           /** file path changing **/
        fnameInf[1]= batch%10+'0';
        fnameInf[32]= serial/10+'0';
        fnameInf[33]= serial%10+'0';

        fp=fopen(fnameInf,"r+");

        fgets(student[i].name,21,fp);
        student[i].name[strlen(student[i].name)-1]='\0'; /** name er seser new line ta kete dite **/

        fgets(student[i].address,81,fp);
        student[i].address[strlen(student[i].address)-1]='\0';/** address " " " **/

        fgets(student[i].roll,10,fp);
        student[i].roll[strlen(student[i].roll)-1]='\0'; /** roll " " " **/

        fscanf(fp,"%d",&student[i].reg_num);

        while(!feof(fp)){                                /** file ses hoyar ag porjonto **/
            fscanf(fp,"%d",&j);
            if(j!=7) for(k=0;k<6;k++){                   /** jodi 7th semester na hoy tobe 6ta mark input nibe **/
                fscanf(fp,"%d",&student[i].marks[j-1][k]);
            }
            else fscanf(fp,"%d",&student[i].marks[6][0]);/** ar naile 1 ta mark input nibe **/
        }

        fclose(fp);
    }
}

/**
 *                                           user file e sob data update korbe
 **/

void updator(void){
    int batch,serial;
    FILE* fp;

    for(batch=8;batch<12;batch++){
        fnameBat[0]=batch/10+'0';
        fnameBat[1]=batch%10+'0';
        fp=fopen(fnameBat,"w+");
        fprintf(fp,"=================================================================================================================================================================================\n");
        fprintf(fp,"      ROLL|                NAME|                                                                         ADDRESS| REG.NUM|CGPA-1|CGPA-2|CGPA-3|CGPA-4|CGPA-5|CGPA-6|CGPA-7|CGPA-8\n");
        fprintf(fp,"==========+====================+================================================================================+========+======+======+======+======+======+======+======+======\n");
                                                /** title bar **/
        for(serial=1;serial<36;serial++){
            fprintf(fp,"%10s|%20s|%80s|%8d|%6.2f|%6.2f|%6.2f|%6.2f|%6.2f|%6.2f|%6.2f|%6.2f\n",student[(batch-8)*35+ serial-1].roll,student[(batch-8)*35+ serial-1].name,student[(batch-8)*35+ serial-1].address,student[(batch-8)*35+ serial-1].reg_num,student[(batch-8)*35+serial-1].cgpsem[0],student[(batch-8)*35+serial-1].cgpsem[1],student[(batch-8)*35+serial-1].cgpsem[2],student[(batch-8)*35+serial-1].cgpsem[3],student[(batch-8)*35+serial-1].cgpsem[4],student[(batch-8)*35+serial-1].cgpsem[5],student[(batch-8)*35+serial-1].cgpsem[6],student[(batch-8)*35+serial-1].cgpsem[7]);
        }
        fclose(fp);
    }
}

