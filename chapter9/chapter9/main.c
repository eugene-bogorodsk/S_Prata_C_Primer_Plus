//
//  main.c
//  chapter9
//
//  Created by пупсик on 27.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_9_1 lethead.c  выводим 40 звёзд
#include <stdio.h>
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40

void starbar(void);// прототип

int main(void) {
    starbar();// использование функции
    printf("%s\n",NAME);
    printf("%s\n",ADDRESS);
    printf("%s\n",PLACE);
    starbar();// использование функции
    
    return 0;
}

void starbar(void) // определение функции
{
    int count=1;
    for(;count<=WIDTH;count++)
        putchar('*');
    putchar('\n');
}
*//*
//list_9_2 lethead2.c функция с передачей аргументов
#include <stdio.h>
#include <string.h> //для strlen()
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megaplis,CA 949904"
#define WIDTH 40
#define SPACE ' '

void show_in_char (char ,int);

int main(void)
{
    int spaces;
    show_in_char('*', WIDTH); //использование констатнт в качестве аргументов
    putchar('\n');
    show_in_char(SPACE, 12); //использование констант в качестве аргументов
    printf("%s\n",NAME);
    spaces = (WIDTH - strlen(ADDRESS)) /2; //позволяет программе вычислить сколько пробелов нужно вывести
    show_in_char(SPACE, spaces);//ипсользование переменной в качестве аргумента
    printf("%s\n",ADDRESS);
    show_in_char(SPACE, (WIDTH - strlen(PLACE)) / 2); //использование выражения в качестве аргумента
    printf("%s\n",PLACE);
    show_in_char('*', WIDTH);
    putchar('\n');
    
    return 0;
}
//определение функции show_in_char()
void show_in_char(char ch,int num)
{
    int count=1;
    for (;count<=num;count++)
        putchar(ch);
}
*//*
//list_9_7 factor.c вычисляем факториал
#include <stdio.h>
long fact(int n);
long rfact(int n);

int main(void)
{
    int num;
    printf("Эта программа вычисляет факториалы.\n");
    printf("Введите значение в диапазоне 0-12 (q для завершения):\n");
    while (scanf("%d",&num))
    {
        if (num<0)
            printf("Отрицательные числа не подходят.\n");
        else if (num>12)
            printf("Вводимой значение должно быть меньше 13.\n");
        else
        {
            printf("цикл: факториал %d = %ld\n",num,fact(num));
            printf("рекурсия : факториал %d = %ld\n",num,rfact(num));
            
        }
    printf("Введите значение в диапазоне 0-12 (q для завершения):\n");
    }
    printf("Программа завершени.\n");
    return 0;
}

long fact (int n)// функция основанная на цикле
{
    long ans;
    for (ans = 1;n > 1;n--)
        ans *= n;
    return ans;
}

long rfact(int n) //рекурсивная версия
{
    long ans=1;
    if (n>0)
        ans *= n*rfact(n-1);
    else
        ans = 1;
    return ans;
}
*//*
//list_9_8 binary.c выводим целые числа в двоичной форме
#include<stdio.h>
void to_binary(unsigned long );
int main(void)
{
    unsigned long number;
    printf("Введите целое число (q для завершения):\n");
    while (scanf("%lu",&number))
    {
        printf("Двоичный эквивалент: ");
        to_binary(number);
        putchar('\n');
        printf("Введите целое число (q для завершения):\n");
    }
    printf("Программа завершена.\n");
    return 0;
}
void to_binary(unsigned  long n) //рекурсивная функция
{
    int r;
    r = n%2;
    if (n >= 2)
        to_binary(n/2);
    putchar( r == 0 ? '0':'1');
    return;
}
   *//*
//list_9_12 loccheck.c адреса хранения переменных
#include<stdio.h>
void mikado(int);
int main(void)
{
    int pooh = 2,bah =5;
    printf("Внутри main() pooh = %d и &pooh = %p\n",pooh,&pooh);
    printf("Внутри main() bah = %d  и &bah = %p\n",bah,&bah);
    mikado(pooh);
    
    return 0;
}
void mikado(int bah) //определение функции
{
    int pooh = 10;
    printf("Внутри mikado() pooh = %d и &pooh = %p\n",pooh,&pooh);
    printf("Внутри mikado() bah = %d и &bah = %p\n",bah,&bah);
    
}
*//*
//list_9_15 swap3.c использование указателей для обмена значениями переменных
#include<stdio.h>
void interchange(int *,int *);

int main(void)
{
    int x = 5,y = 10;
    printf("Первоначально x=%d и y = %d.\n",x,y);
    interchange(&x,&y);//передача адресов в функцию
    printf("Теперь x=%d и y=%d.\n",x,y);
    
    return 0;
}

void interchange(int *u,int* v)
{
    int temp;
    temp = *u; //temp получает значение на которое указывает u
    *u = *v;
    *v = temp;
}
*/
/*
//ex1 возвращает меньшее число
#include<stdio.h>
double min(double,double);
int main(void)
{
    double x,y;
    printf("Введите пару чисел:\n");
    scanf("%lf%lf",&x,&y);
    printf("Это %0.2f меньше.\n",min(x,y));
    
    return 0;
}
double min(double u, double v)
{
    return (u > v) ? v:u;
}
 *//*
//ex2  выводим набор символов между двумя числами
#include<stdio.h>
void chline(char,int ,int);
int main(void)
{
    int ch;
    int i,j;
    printf("Введите сивол\n");
    ch=getchar();
    while(ch<32 || ch>150)
    {
        printf("К сожалению такие символы не отображаются на экране, попробуйте другой\n");
        while(getchar() !='\n');
        ch = getchar();
    }
    printf("Введите номера столбцов \n");
    while(getchar() !='\n');
    
    while ((scanf("%d %d",&i,&j) !=2))
    {
        printf("К сожалению введенные числа не соответствуют заданному формату, введите что то типа 5 или 10\n");
        while(getchar() != '\n');
    }
    chline(ch,i,j);
    
    return 0;
    
}
void chline(char ch,int i,int j)
{
    int space,chares;
    for (space = 0;space <i;space++)
        putchar(' ');
    for (chares = 0;chares <j;chares++)
            putchar(ch);
    putchar('\n');

}
*//*
//ex7 вывод сиволов
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int display_char(int);
int main(void)
{
    int ch;
    ch=getchar();
    while (ch!= EOF)
    {
        putchar(ch);
        if (ch !='\n')
            printf("%d \n",display_char(ch));
        ch = getchar();
    }
          
    
    return 0;
}

int display_char(int ch)
{
    int num=-1; //возвращаемый параметр -1 по умолчанию
    
 //if (ch>31 && ch< 127)
  //{
       
        if (isalpha(ch))
        {
            if (islower(ch))
                num = ch - 96;
            else
                num = ch - 64;
            printf("- это буква, в алфавите #");
        }
        
 //}
    return num;
}
*//*
//ex8 возвращаем число в любой степени
#include<stdio.h>
double power(double,int);

int main(void)
{
    double x,xpow;
    int exp;
    
    printf("Введите число и  степень,");
    printf(" в которую \nчисло будет возведено. Для завершения программы");
    printf(" введите q.\n");
    while (scanf("%lf %d",&x,&exp) == 2)
    {
        xpow = power(x,exp); //вызов функции
        printf("%.3g в степени %d равно %.5g\n",x,exp,xpow);
        printf("Введите следующаую пару чисел или q для завершения.\n");
    }
    printf("Надеемся, что вы оценили это упражнение!\n");
    
    return 0;
}
double power(double n,int p)
{
    double pow = 1;
    int i,limit;
    limit=p;
    if (p<0)
        limit = -p;
    for (i=1;i<=limit;i++)
        pow*=n;
    if (p<0)
        pow = 1/pow;
    return pow;
}

*//*
//ex9 функция pow в рекурентной форме

#include<stdio.h>
double power(double,int);

int main(void)
{
    double x,xpow;
    int exp;
    
    printf("Введите число и  степень,");
    printf(" в которую \nчисло будет возведено. Для завершения программы");
    printf(" введите q.\n");
    while (scanf("%lf %d",&x,&exp) == 2)
    {
        xpow = power(x,exp); //вызов функции
        printf("%.3g в степени %d равно %.5g\n",x,exp,xpow);
        printf("Введите следующаую пару чисел или q для завершения упражнения.\n");
    }
    printf("Надеемся, что вы оценили это упражнение!\n");
    
    return 0;
}
double power(double n,int p)
{
    if (p < 0)
    {
        p = -p; n = 1/n;
    }
    
    if (p == 1)
        return n;
    if (p == 0)
        return 1;
    
    return n*power(n,p-1);
}
*//*
//ex 10 возвращаем число в n-й системе счисления
#include<stdio.h>
void to_base_n(unsigned long, int );
int main(void)
{
    unsigned long number;
    int system;//основание системы счисления в которую нужно перевести
    printf("Введите целое число  и основание системы счисления в которую будем переводить (q для завершения):\n");
    while (scanf("%lu %d",&number,&system) ==2)
    {
        printf("Двоичный эквивалент: ");
        to_base_n(number,system);
        putchar('\n');
        printf("Введите целое число  и основание системы счисления в которую будем переводить (q для завершения):\n");
    }
    printf("Программа завершена.\n");
    return 0;
}
void to_base_n(unsigned  long n, int m) //рекурсивная функция
{
    int r;
    r = n % m;
    if (n >= m)
        to_base_n(n/m, m);
    putchar( r + 48);
    return;
}
*/
#include<stdio.h>//фиббоначи без рекурсии

unsigned long Fibonacci(int);
int main(void)
{
    int n;
    printf("Вводим номер числа Фиббоначи:\n");
    while (scanf("%d",&n))
    {
        printf("Результат: %lu\n", Fibonacci(n));
        printf("Вводим номер числа Фиббоначи или q для выхода:\n");
    }
    
    return 0;
}
unsigned long Fibonacci(int n)
{
    int ans = 1;
    int ans_pred =1;
    int t,i;
    for (i = 2;i < n;i++)
    {
        t = ans;
        ans += ans_pred;
        ans_pred = t;
    
    }
    return ans;
}
