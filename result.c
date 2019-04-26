/**
 *                                                   complete
 **/
#include<stdio.h>
#include"header.h"
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
 *                                         karo result input neyar jonno
 **/

void resultInput(int roll,int semister){
	int i;
	FILE* fp;
	                                         /** file path changing **/
	fnameInf[0]= roll/1000+'0';              /** 1102/1000=1 **/
	fnameInf[1]=(roll/100)%10+'0';           /** (1102/100)%10=11%10=1 **/
	fnameInf[32]=(roll%100)/10+'0';          /** (1102%100)/10=02/10=0 **/
	fnameInf[33]= roll%10+'0';               /** 1102%10=2 **/

	fp=fopen(fnameInf,"a+");                 /** a+ mode e kholay ager lekhar por notun kore jog hobe **/
	fprintf(fp,"%d\n",semister);             /** semester er record rakha hocche **/
	if(semister!=7){                         /** jodi 7th semester na hoy **/
        for(i=0;i<6;i++){                    /** tahole 6 ta mark input nibe **/
            printf("\n\nENTER THE MARK OF SE%d0%d: ",semister,i+1);
            scanf("%d",&student[(roll/100-8)*35+roll%100-1].marks[semister-1][i]);
                                             /** (1102/100-8)*35+1102%100-1=(11-8)*35+02-1=105+1=106 **/
                                             /** input niye eta marks er array te rakha hocche **/
            fprintf(fp,"%d\n",student[(roll/100-8)*35+roll%100-1].marks[semister-1][i]);
                                             /** input neya data ke permanent korte file e preserve kora hocce **/
        }
        student[(roll/100-8)*35+roll%100-1].cgpsem[semister-1]=cgpaCounter((roll/100-8)*35+roll%100-1,semister);
                                             /** input neya mark diye cgpa count kore setakeo array te rakha hocce **/
	}
	else{                                    /** jodi 7th semester hoy **/
        printf("\n\nENTER THE MARK OF SE%d0%d: ",semister,1);
        scanf("%d",&student[(roll/100-8)*35+roll%100-1].marks[semister-1][0]);
                                             /** tahole 1ta input neya hobe **/
        fprintf(fp,"%d\n",student[(roll/100-8)*35+roll%100-1].marks[semister-1][0]);
        student[(roll/100-8)*35+roll%100-1].cgpsem[semister-1]=cgpaCounter((roll/100-8)*35+roll%100-1,semister);
                                             /** baki sob ek **/
	}
}

/**
 *                                          mark diye cgpa hiseb korte
 **/

float cgpaCounter(int roll,int semister){
    int i;
    float cgpa=0.0;

    if(semister==7){                                /** jodi 7th semester hoy taile kono gor korar proyojon nai **/
        if(student[roll].marks[6][0]<40) return 0.00;                                     /** egula normal things **/
        else if(student[roll].marks[6][0]>=40&&student[roll].marks[6][0]<45) return 2.00;
        else if(student[roll].marks[6][0]>=45&&student[roll].marks[6][0]<50) return 2.25;
        else if(student[roll].marks[6][0]>=50&&student[roll].marks[6][0]<55) return 2.50;
        else if(student[roll].marks[6][0]>=55&&student[roll].marks[6][0]<60) return 2.75;
        else if(student[roll].marks[6][0]>=60&&student[roll].marks[6][0]<65) return 3.00;
        else if(student[roll].marks[6][0]>=65&&student[roll].marks[6][0]<70) return 3.25;
        else if(student[roll].marks[6][0]>=70&&student[roll].marks[6][0]<75) return 3.50;
        else if(student[roll].marks[6][0]>=75&&student[roll].marks[6][0]<80) return 3.75;
        else return 4.00;                                                                  /** end **/
    }
    else{                                          /** jodi 7th semester na hoy **/
        for(i=0;i<6;i++){                          /** tahole 6 tar gor korte hobe. **/
            if(student[roll].marks[semister-1][i]<40) return 0.00;
                                                   /** jodi kono subject e fail kore taile purata 0 kore dite hobe **/
            else if(student[roll].marks[semister-1][i]>=40&&student[roll].marks[semister-1][i]<45) cgpa+= 2.00;
                                                   /** ar naile sobgula jog kore **/
            else if(student[roll].marks[semister-1][i]>=45&&student[roll].marks[semister-1][i]<50) cgpa+= 2.25;
            else if(student[roll].marks[semister-1][i]>=50&&student[roll].marks[semister-1][i]<55) cgpa+= 2.50;
            else if(student[roll].marks[semister-1][i]>=55&&student[roll].marks[semister-1][i]<60) cgpa+= 2.75;
            else if(student[roll].marks[semister-1][i]>=60&&student[roll].marks[semister-1][i]<65) cgpa+= 3.00;
            else if(student[roll].marks[semister-1][i]>=65&&student[roll].marks[semister-1][i]<70) cgpa+= 3.25;
            else if(student[roll].marks[semister-1][i]>=70&&student[roll].marks[semister-1][i]<75) cgpa+= 3.50;
            else if(student[roll].marks[semister-1][i]>=75&&student[roll].marks[semister-1][i]<80) cgpa+= 3.75;
            else cgpa+= 4.00;
        }
        return cgpa/6.00;                         /** 6 diye vag dite hobe **/
    }
}

/**
 *                                        ekjoner final result print korte
 **/

void indFinalResult(int roll){
    int semester,i;
    float j=0.0,result;
	printf("\nTILL SEMESTER: ");                                    /** koto semester porjonto result print korbe seta **/
	scanf("%d",&semester);

	for(i=0;i<semester;i++){                                        /** toto semester porjonto **/
        printf("\nSEMESTER %d: %.2f",i+1,student[(roll/100-8)*35+roll%100-1].cgpsem[i]);  /** roll diye position ber korar formula **/
        j+=student[(roll/100-8)*35+roll%100-1].cgpsem[i];           /** cgpa jog kore **/
	}
	printf("\n\nFINAL CGPA TILL SEMESTER %d: %.2f",semester,j/semester);/** gor kore print korte hobe **/
}

/**
 *                                    karo ek semester er result print korte
 **/

void indSemResult(int roll){
	int semester;
	printf("\nENTER THE SEMESTER: ");
	scanf("%d",&semester);
	if(semester!=7){                  /** jodi 7th semester na hoy tobe 6 ta mark prinbt korte hobe **/
        printf("\n\nTHE RESULT OF %s\n\nSE%d01: %d\nSE%d02: %d\nSE%d03: %d\nSE%d04: %d\nSE%d05: %d\nSE%d06: %d\n\nCGPA: %.2f",student[(roll/100-8)*35+roll%100-1].name,semester,student[(roll/100-8)*35+roll%100-1].marks[semester-1][0],semester,student[(roll/100-8)*35+roll%100-1].marks[semester-1][1],semester,student[(roll/100-8)*35+roll%100-1].marks[semester-1][2],semester,student[(roll/100-8)*35+roll%100-1].marks[semester-1][3],semester,student[(roll/100-8)*35+roll%100-1].marks[semester-1][4],semester,student[(roll/100-8)*35+roll%100-1].marks[semester-1][5],student[(roll/100-8)*35+roll%100-1].cgpsem[semester-1]);
	}
	else                              /** nahole 1 ta print korte hobe **/
        printf("\n\nTHE RESULT OF %s\n\nSE%d01: %d\n\nCGPA: %.2f",student[(roll/100-8)*35+roll%100-1].name,semester,student[(roll/100-8)*35+roll%100-1].marks[semester-1][0],student[(roll/100-8)*35+roll%100-1].cgpsem[semester-1]);
}

/**
 *                                    pura batch er final result print korte
 **/

void batchFinalResult(int batch){
	int k,semester,i;
    float j=0.0,result;
	printf("\nTILL SEMESTER: ");
	scanf("%d",&semester);

	printf("\n\n FINAL RESULT TILL SEMESTER-%d OF %dth BATCH\n===========================================\n     ROLL|                NAME| CGPA\n=========+====================+======",semester,batch);
	                                /** title bar printing **/
	for(k=(batch-8)*35;k<(batch-7)*35;k++){
	    j=0.0;
        for(i=0;i<semester;i++)
            j+=student[k].cgpsem[i];
        printf("\n %s|%20s| %.2f",student[k].roll,student[k].name,j/semester);
                                   /** final cgpa kothao na jomanor fole notun kore hiseb korte hoiche **/
	}
}

/**
 *                                  pura batch er semester er result print korte
 **/

void batchSemResult(int batch){
	int k,semester,i;
    float j=0.0,result;
	printf("\nSEMESTER: ");
	scanf("%d",&semester);

	printf("\n\n RESULT OF SEMESTER-%d OF %dth BATCH\n====================================\n     ROLL|                NAME|CGPA \n=========+====================+=====",semester,batch);
	                              /** title bar **/
	for(k=(batch-8)*35;k<(batch-7)*35;k++)
        printf("\n %s|%20s| %.2f",student[k].roll,student[k].name,student[k].cgpsem[semester-1]);
}

