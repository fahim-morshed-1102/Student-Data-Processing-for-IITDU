/**
 *                                                       complete
 */
#include<stdio.h>
extern char fnameInf[];
extern char fnameBat[];
extern struct profile{
    char name[21];
    char address[81];
    char roll[9];
    int reg_num;
    float cgpsem[8];
    int marks[8][6];
} student[140];

/**
 *                                     data input neya r change korte eta use kora hoiche
 **/

void inputData(int roll){
	int batch=roll/100, serial=roll%100;
	FILE* fp;

    printf("\n\nNAME: ");
    getchar();                                         /** janina eta ken lage. kono ek rohosso jonok karone prothom okkhor ta input hossilo na **/
    gets(student[(batch-8)*35+ serial-1].name);        /** (batch-8)*35+serial-1= students position in the structure.
                                                            such as, (11-8)*35+2-1=105+1=106. thats my position in structure **/
    printf("\n\nADDRESS: ");
    gets(student[(batch-8)*35+ serial-1].address);     /**   same shit **/

    printf("\n\nREG. NUMBER: ");
    scanf("%d",&student[(batch-8)*35+ serial-1].reg_num);/**  same shit **/

    fnameInf[0]= batch/10+'0';                         /** changing the file path to store data in the file **/
    fnameInf[1]= batch%10+'0';
    fnameInf[32]= serial/10+'0';
    fnameInf[33]= serial%10+'0';                       /** end **/

    fp=fopen(fnameInf,"w+");
    fprintf(fp,"%s\n", student[(batch-8)*35+ serial-1].name);                 /** ager data gulai ekhon file e lekah hocce **/
    fprintf(fp,"%s\n", student[(batch-8)*35+ serial-1].address);
    fprintf(fp,"%s\n", student[(batch-8)*35+ serial-1].roll);
    fprintf(fp,"%d\n", student[(batch-8)*35+ serial-1].reg_num);              /** end **/
    fclose(fp);
}

/**
 *                              pura batch er personal information console e dekhate use kora hocce
 **/

void batchView(int batch){
    int i;
    printf("\n\n========================================================================================================================\n    ROLL|                NAME|                                                                         ADDRESS| REG.NUM\n========+====================+================================================================================+=========\n");
                                   /** title bar printing **/
    for(i=(batch-8)*35;i<(batch-7)*35;i++)
        printf("%8s|%20s|%80s|%8d\n",student[i].roll,student[i].name,student[i].address,student[i].reg_num);
                                   /** information printing **/
    printf("========================================================================================================================\n");
}

/**
 *                                      individual er information console e print korte use hoy
 **/

void individualView(int roll){
    int i=(roll/100-8)*35+roll%100-1;
    printf("\n\nName: %s\nAddress: %s\nRoll: %s\nReg.Num: %d\n",student[i].name,student[i].address,student[i].roll,student[i].reg_num);
}

