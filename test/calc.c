#include<stdio.h>
#include<stdlib.h>

#define MAX_INPUT 100

void delSpace();
char *getEquations();
void stoi();
int calc(int *nums, char *operators);
int main()
{
    char *arr;
    printf("Please enter some equations like:1+1=2, 2+2=4, ...\n");
    printf("The process will calc it and give you correct answer\n");
    arr = getEquations();
    stoi(arr);
    return 0;
}

//5+10=15, 6+9=15, 115+225=340

char *getEquations(){
    char *arr = (char *)malloc(MAX_INPUT * sizeof(char));
    char *top=arr;
    char c;
    while( (c = getchar()) != '\n' ){
        *arr++ = c;
    }
    *arr = '\0';
    return top;
}



void stoi(char *arr)
{
    int *nums = (int *)malloc((MAX_INPUT -40) * sizeof(int));
    char *operators = (char *)malloc((MAX_INPUT  -60) * sizeof(char));
    int *top_nums = nums;
    char *top_operattors = operators;
    char c = -1;
    int i = 0;
    while(c != '\0'){
        while((c = *arr++) != ',' && c != '\0'){
            if( c >= '0' && c <= '9'){
                i = i * 10 + c - '0';
            }
            else if(c == '+' || c == '-'){
                *operators++ = c;
                break;
            }
            else if(c == '=')break;
        }
        *nums++ = i;
        i = 0;
    }
    for(int j = 0; *(top_operattors + j/3) != '\0'; j += 3 ){
        printf(" The %d equation is %s \n",j/3+1 , calc(top_nums+j, top_operattors+j/3)? "true" : "false");
    }
}    

int calc(int *nums, char *operators)
{
    if(*nums + (44 - *operators) * *(nums + 1) == *(nums + 2))
    return 1;
    else{
        printf("%d %c %d = %d", *nums, *operators, *(nums +1), *nums + *(nums + 1));
        return 0;
    }
}