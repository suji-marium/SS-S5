#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int start,locctr=0,length;
    char label[10],opcode[10],operand[10];
    char code[10],mneumonic[10];
    FILE *fp1,*fp2,*fp3,*fp4;
    fp1=fopen("input.txt","r");
    fp2=fopen("opcode.txt","r");
    fp3=fopen("symtab.txt","w");
    fp4=fopen("interme.txt","w");

    fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);

    if(strcmp(opcode,"START")==0)
    {
        start=atoi(operand);
        //printf("%d\n",start);
        locctr=start;
        //printf("%d\n",locctr);
        fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    }
    else
    {
        locctr=0;
    }

    while(strcmp(opcode,"END")!=0)
    {
        fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"**")!=0)
        {
            fprintf(fp3,"%s\t%d\n",label,locctr);
        }
        fscanf(fp2,"%s\t%s",code,mneumonic);

        while(strcmp(code,"END")!=0)
        {
            if(strcmp(code,opcode)==0)
            {
                locctr+=3;
                break;
            }
            fscanf(fp2,"%s\t%s",code,mneumonic);
        }

        if(strcmp(opcode,"WORD")==0)
        {
            locctr+=3;
        }
        else if(strcmp(opcode,"BYTE")==0)
        {
            locctr+=1;
        }
        else if(strcmp(opcode,"RESW")==0)
        {
            locctr+=3*(atoi(operand));
        }
        else if(strcmp(opcode,"RESB")==0)
        {
            locctr+=atoi(operand);
        }
       fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    }
    fprintf(fp4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    length=locctr-start;
    printf("Length of the code %d",length);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

}
