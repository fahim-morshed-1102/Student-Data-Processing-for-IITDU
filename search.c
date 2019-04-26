/**
 *                                              complete
 **/
#include<stdio.h>
#include<string.h>
#include<time.h>

extern char fnameInf[];
extern char fnameBat[];
extern struct profile{
    char name[21];
    char address[81];
    char roll[9];
    int reg_num;
    //float cgpa;
    float cgpsem[8];
    int marks[8][6];
} student[140];

/**
 *                                        search history print korte
 **/

void searchHistory(void){
    char str[1000000];                   /** ekta bisal string nisi **/
    int i=0;
    FILE *fp;

    fp=fopen("searchHistory.txt","r+");
    while(feof(fp)==0){                  /** file ses howar ag porjonto **/
        str[i++]=getc(fp);               /** sob okkhorgula oi string e nibe **/
    }
    fclose(fp);

    printf("%s",str);                    /** erpor seta print korbe **/
}

/**
 *                                               search korte
 **/

void Search(void){
	char element[100];
	int lenth,i,j,k,l=1,match=1,mark=1,equivalant=0;
	FILE* fp;
	time_t t = time(NULL);                           /** bortoman date and time hiseb korse **/
    struct tm tm = *localtime(&t);

	getchar();
	gets(element);
	printf("\n\n\t\t\t\t\tSEARCH  RESULT\n\t\t\t\t\t==============\n");
	lenth=strlen(element);

	for(i=0;i<lenth;i++){
        if(element[i]>='0'&&element[i]<='9'&&mark){ /** pura data ta jodi int hoy tobe tar ekta equivalent int hiseb korbe **/
            equivalant*=10;
            equivalant+=element[i]-'0';
        }
        else{
            equivalant=0;
            mark=0;
            break;
        }
	}
	for(i=0;i<140;i++){
        for(j=0;j<20;j++){
            for(k=0;k<lenth;k++){
                match=1;
                if(element[k]>='a'&&element[k]<='z'){/** jodi okkhor ta choto hater hoy **/
                    if((element[k]!=student[i].name[j+k])&&(element[k]-'a'+'A'!=student[i].name[j+k])){
                                                     /** tahole seta boro hater kore ba choto hater rekhe check kora hobe **/
                        match=0;
                        break;
                    }
                }
                else if(element[k]>='A'&&element[k]<='Z'){/** jodi boro hater hoy tobe **/
                    if((element[k]!=student[i].name[j+k])&&(element[k]-'A'+'a'!=student[i].name[j+k])){
                                                          /** choto hater kore ba boro hater rekhe check kora hobe **/
                        match=0;
                        break;
                    }
                }
                else{                                     /** ar nahole **/
                    if(element[k]!=student[i].name[j+k]){ /** just check kora hobe **/
                        match=0;
                        break;
                    }
                }
            }
            if(match){
                printf("\n\n%2d.Name: %s\n  ------\nAddress: %s\nRoll: %s\nReg.Num: %d\n",l++,student[i].name,student[i].address,student[i].roll,student[i].reg_num);
                break;
            }
        }
        if(match) continue;

        for(j=0;student[i].address[j]!='\0';j++){
            for(k=0;k<lenth;k++){
                match=1;
                if(element[k]>='a'&&element[k]<='z'){
                    if((element[k]!=student[i].address[j+k])&&(element[k]-'a'+'A'!=student[i].address[j+k])){
                        match=0;
                        break;
                    }
                }
                else if(element[k]>='A'&&element[k]<='Z'){
                    if((element[k]!=student[i].address[j+k])&&(element[k]-'A'+'a'!=student[i].address[j+k])){
                        match=0;
                        break;
                    }
                }
                else{
                    if(element[k]!=student[i].address[j+k]){
                        match=0;
                        break;
                    }
                }
            }
            if(match){
                printf("\n\n%d.Name: %s\nAddress: %s\n--------\nRoll: %s\nReg.Num: %d\n",l++,student[i].name,student[i].address,student[i].roll,student[i].reg_num);
                break;
            }
        }
        if(match) continue;

        for(j=0;student[i].roll[j]!='\0';j++){
            for(k=0;k<lenth;k++){
                match=1;
                if(element[k]>='a'&&element[k]<='z'){
                    if((element[k]!=student[i].roll[j+k])&&(element[k]-'a'+'A'!=student[i].roll[j+k])){
                        match=0;
                        break;
                    }
                }
                else if(element[k]>='A'&&element[k]<='Z'){
                    if((element[k]!=student[i].roll[j+k])&&(element[k]-'A'+'a'!=student[i].roll[j+k])){
                        match=0;
                        break;
                    }
                }
                else{
                    if(element[k]!=student[i].roll[j+k]){
                        match=0;
                        break;
                    }
                }
            }
            if(match){
                printf("\n\n%d.Name: %s\nAddress: %s\nRoll: %s\n-----\nReg.Num: %d\n",l++,student[i].name,student[i].address,student[i].roll,student[i].reg_num);
                break;
            }
        }
        if(match) continue;

        if(mark&&student[i].reg_num==equivalant)
            printf("\n\n%d.Name: %s\nAddress: %s\nRoll: %s\nReg.Num: %d\n--------",l++,student[i].name,student[i].address,student[i].roll,student[i].reg_num);
	}
	fp=fopen("searchHistory.txt","a+");
	fprintf(fp,"\n%4d-%2d-%2d -> %2d:%2d:%2d : %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,element);
	                                          /** search history record kora hocce **/
	fclose(fp);

	if(!(l-1)) printf("\n\t\t\t\t       RESULT NOT FOUND\n");
}

