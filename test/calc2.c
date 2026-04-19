#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[64];
    double n[32], *np;
    char o[32], *op;
    double x, y;

    printf("简易表达式计算器（支持 + - * / ( ) ）\n");
    printf("输入表达式，输入 q 或 Q 退出\n\n");

    while (1) {
        printf("输入表达式: ");
        if (!fgets(s, sizeof(s), stdin)) break;

        s[strcspn(s, "\n")] = 0; 

        if (strcmp(s, "q") == 0 || strcmp(s, "Q") == 0) {
            printf("再见！\n");
            break;
        }
        np = n - 1;
        op = o - 1;
        char *p = s;

        while (*p) {
            while (*p == ' ') p++;

            if ((*p >= '0' && *p <= '9') || *p == '.' || 
                (*p == '-' && (p == s || *(p-1) == '(' || *(p-1) == ' '))) {
                *++np = atof(p);
                while (*p && ((*p >= '0' && *p <= '9') || *p == '.')) p++;
                continue;
            }

            if (*p == '(') { 
                *++op = '('; 
                p++; 
                continue; 
            }

            if (*p == ')') {
                while (*op != '(') {
                    y = *np--; x = *np--;
                    switch (*op--) {
                        case '+': *++np = x + y; break;
                        case '-': *++np = x - y; break;
                        case '*': *++np = x * y; break;
                        case '/': *++np = x / y; break;
                    }
                }
                op--;      
                p++; 
                continue;
            }

            if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
                while (op >= o && *op != '(' &&
                       ((*op == '*' || *op == '/') || 
                        (*p == '+' || *p == '-'))) {
                    y = *np--; x = *np--;
                    switch (*op--) {
                        case '+': *++np = x + y; break;
                        case '-': *++np = x - y; break;
                        case '*': *++np = x * y; break;
                        case '/': *++np = x / y; break;
                    }
                }
                *++op = *p++;
                continue;
            }

            p++;  
        }

        while (op >= o) {
            y = *np--; x = *np--;
            switch (*op--) {
                case '+': *++np = x + y; break;
                case '-': *++np = x - y; break;
                case '*': *++np = x * y; break;
                case '/': *++np = x / y; break;
            }
        }

        printf("= %.10g\n\n", *np);
    }

    return 0;
}