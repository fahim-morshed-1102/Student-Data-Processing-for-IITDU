/**
 *                                                   complete
 **/
#include <stdio.h>
#include "header.h"


struct profile{
    char name[21];
    char address[81];
    char roll[9];
    int reg_num;
    float cgpsem[8];
    int marks[8][6];
} student[140];
char fnameInf[]="08thBatch\\individualInformation\\01.txt";
char fnameBat[]="08thBatch\\batchSummary.txt";



int main(){

	int c1,c2,c3,c4,c5,i;           /** ekhane c1,c2... egula na na dhape choice neyar jonno deya hoise **/

    informationTaker();            /** eta file e existing sob information ke running structure e niye jabe **/

	for(i=0;i<140;i++){
        student[i].roll[0]='B';                                /** eta structure e sob student er roll select kore dibe **/
        student[i].roll[1]=student[i].roll[2]='S';
        student[i].roll[3]='E';
        student[i].roll[4]=((i/35)+8)/10+'0';
        student[i].roll[5]=((i/35)+8)%10+'0';
        student[i].roll[6]=((i%35)+1)/10+'0';
        student[i].roll[7]=((i%35)+1)%10+'0';                  /** roll er kahini ses **/
        student[i].cgpsem[0]=cgpaCounter(i,1);                 /** etate prottek semester er cgpa giseb hoy **/
        student[i].cgpsem[1]=cgpaCounter(i,2);
        student[i].cgpsem[2]=cgpaCounter(i,3);
        student[i].cgpsem[3]=cgpaCounter(i,4);
        student[i].cgpsem[4]=cgpaCounter(i,5);
        student[i].cgpsem[5]=cgpaCounter(i,6);
        student[i].cgpsem[6]=cgpaCounter(i,7);
        student[i].cgpsem[7]=cgpaCounter(i,8);                 /** cgpa e porjontoi **/
	}

	point1:
	printf("\n\t\t\t\t\tMAIN MENU");                            /** egula just menu printing **/
	printf("\n\t\t\t\t\t=========");
	printf("\n\n1.Student Data\n2.Result\n3.Search\n0.Exit\n\nEnter your choice: ");
	scanf("%d",&c1);

	switch(c1)
	{
    case 1:
		point11:
		printf("\n\n\t\t\t\t\tSTUDENT DATA");
		printf("\n\t\t\t\t\t============");
		printf("\n\n1.Input data\n2.See data\n3.change data\n0.back\n\nEnter your choice: ");
		scanf("%d",&c2);
		switch(c2){
        case 1:
			printf("\n\nHow many data do you want to enter?(Enter 0 to back): ");
			scanf("%d",&c3);
			if(c3){
				for(i=0;i<c3;i++){
                    printf("\n\nEnter the roll: ");
					scanf("%d",&c4);
					inputData(c4);
				}
				goto point1;
			}
			else  goto point11;
        break;
        case 2:
			point112:
			printf("\n\n\t\t\t\t\tSEE DATA");
			printf("\n\t\t\t\t\t========");
			printf("\n1.Full batch\n2.Individual information\n0.Back\n\nENTER YOUR CHOICE: ");
			scanf("%d",&c3);
			switch(c3){
            case 1:
                printf("\n\nEnter the batch(0 to back): ");
                scanf("%d",&c4);
                if(c4){
                    batchView(c4);
                    goto point1;
                }
                else goto point112;
            break;
            case 2:
                printf("\n\nEnter the roll(0 to back): ");
                scanf("%d",&c4);
                if(c4) {
                    individualView(c4);
                    goto point1;
                }
                else goto point112;
            break;
            default:  goto point11;
			}
        break;
        case 3:
            printf("\n\n\t\t\t\t\tCHANGE FILE");
            printf("\n\t\t\t\t\t===========");
            printf("\n\nENTER THE ROLL(0 to back): ");
            scanf("%d",&c3);
            if(c3){
                inputData(c3);
                goto point1;
            }
            else goto point11;
        break;
        default: goto point1;
		}
    break;
    case 2:
		point12:
		printf("\n\n\t\t\t\t\tRESULT MENU");
		printf("\n\t\t\t\t\t===========");
		printf("\n\n1.Input result\n2.see result\n0.back\n\nEnter your choice: ");
		scanf("%d",&c2);
		switch(c2){
        case 1:
            point121:
            printf("\n\n\t\t\t\t\tINPUT RESULT\n\t\t\t\t\t============\n\nEnter the roll(0 to back): ");
            scanf("%d",&c3);
            if(c3){
                printf("Enter the semester of BSSE%d(0 to enter the roll again): ",c3);
                scanf("%d",&c4);
                if(c4){
                    resultInput(c3,c4);
                    goto point1;
                }
                else goto point121;
            }
            else goto point12;
        break;
        case 2:
            point122:
            printf("\n\n\t\t\t\t\tRESULT SHOWING\n\t\t\t\t\t==============\n\n1.Individual result\n2.Batch result\n0.back\n\nENTER YOUR CHOICE: ");
            scanf("%d",&c3);
            switch(c3){
            case 1:
                point1221:
                printf("\n\n\t\t\t\t\tINDIVIALS RESULT");
                printf("\n\t\t\t\t\t================\n\n1.Semester result\n2.Final result\n0.Back\n\nENTER YOUR CHOICE: ");
                scanf("%d",&c4);
                switch(c4){
                case 1:
                    printf("Enter the roll(0 to back): ");
                    scanf("%d",&c5);
                    if(c5){
                        indSemResult(c5);
                        goto point1;
                    }
                    else goto point1221;
                break;
                case 2:
                    printf("Enter the roll(0 to back): ");
                    scanf("%d",&c5);
                    if(c5){
                        indFinalResult(c5);
                        goto point1;
                    }
                    else goto point1221;
                break;
                default: goto point122;
                }
            break;
            case 2:
                point1222:
                printf("\n\n\t\t\t\t\tBATCH RESULT");
                printf("\n\t\t\t\t\t=============\n\n1.Semester result\n2.Final result\n0.Back\n\nENTER YOUR CHOICE: ");
                scanf("%d",&c4);
                switch(c4){
                case 1:
                    printf("Enter the batch(0 to back): ");
                    scanf("%d",&c5);
                    if(c5){
                        batchSemResult(c5);
                        goto point1;
                    }
                    else goto point1222;
                break;
                case 2:
                    printf("Enter the batch(0 to back): ");
                    scanf("%d",&c5);
                    if(c5){
                        batchFinalResult(c5);
                        goto point1;
                    }
                    else goto point1222;
                break;
                default: goto point122;
                }
            break;
            default: goto point12;
            }
        break;
        default: goto point1;
		}
    break;
    case 3:
		point13:
        printf("\n\n\t\t\t\t\tSEARCH OPTION");
        printf("\n\t\t\t\t\t=============\n\n1.Search\n2.Search History\n0.back\n\nEnter your choice: ");
        scanf("%d",&c2);
		switch(c2){
		case 1:
			printf("\n\nEnter any valid information (Name,Roll,Address,Reg.Number) you have: ");
			Search();
			goto point1;
		break;
		case 2:
			searchHistory();
			goto point1;
		break;
		default:goto point1;
		}
    break;
    default:
        updator();                 /** exit howar age user file e (batchSummary.txt) structure er sob data update kore dey **/
        return 0;
	}
}

