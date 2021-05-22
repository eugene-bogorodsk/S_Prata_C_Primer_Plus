//
//  main.c
//  chapter10
//
//  Created by пупсик on 01.03.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_10_5 designate.c исползование назначенных инициализаторов
#include <stdio.h>
#define MONTHS 12

int main(void) {
    int days[MONTHS] = {31,28,[4] = 31,30,31,[1]=29};//акутальной будет повторная инициализация (компилятор выдает предупреждение)
        // все неуказанные при инициализации элементы заполняются нулями
    int i;
    for (i=0;i < MONTHS;i++)
        printf("%2d %d\n",i+1,days[i]);
    
    return 0;
}
 *//*
//list_10_6 bounds.c выход за границы массива
#include<stdio.h>
#define SIZE 4
int main(void)
{
    int value1 = 44;
    int arr[SIZE];
    int value2 = 88;
    int i;
    
    printf("value1 = %d,value2 = %d\n",value1,value2);
    for (i = -1;i <= SIZE;i++)
        arr[i]=2*i+1;
    for (i=-1;i<7;i++)
        printf("%2d %d\n",i,arr[i]); //элементы массива с идексами 5 и 6 выводят хранимый там мусор
    
    printf("value1 = %d, value2 = %d\n",value1,value2);
    printf("адрес arr[-1]: %p\n",&arr[-1]);
    printf("адрес arr[4]: %p\n",&arr[4]);
    printf("адрес value1: %p\n",&value1);
    printf("адрес value2: %p\n",&value2);
    
    return 0;
}
*//*
//list_10_7 rain.c находит суммарное значение осадков за год , среднее значение за год и за месяц по данным об осадках за несколько лет
#include<stdio.h>
#define MONTHS 12 //количество месяцев в году
#define YEARS 5 //количество лет за которые доступны данные
int main(void)
{
    //инициализация данными об осадках за 5 лет
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2},
    };
    int year,month;
    float subtot,total;
    printf("ГОД  КОЛИЧЕСТВО ОСАДКОВ(в дюймах)\n");
    for (year = 0,total = 0;year < YEARS;year++)
    {
        //для каждого года суммировать количество осадков за каждый месяц
        for (month = 0,subtot=0;month < MONTHS;month++)
            subtot += rain[year][month];
        printf("%5d %15.1f\n",2010+year,subtot);
        total += subtot;//общая сумма для всех лет
    }
    printf("\nСреднегодовое количество осадков составляет %.1f дюймов.\n\n",total/YEARS);
    printf("СРЕДНЕМЕСЯЧНОЕ ЕОЛИЧЕСТВО ОСАДКОВ:\n\n");
    printf(" Янв  Фев  Мар  Апр  Май  Июн  Июл  Авг  Сен  Окт  Ноя  Дек\n");
    for (month =0;month <MONTHS; month++)
    {
        //для каждого месяца суммировать количетсов осадков на протяжении годов
        for (year = 0,subtot =0;year < YEARS; year++)
            subtot +=rain[year][month];
        printf("%4.1f ",subtot/YEARS);
    }
    printf("\n");
    
    return 0;
}
*//*
//list_10_8 pnt_add.c сложение указателей
#include<stdio.h>
#define SIZE 4
int main(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;
    
    pti = dates; //присваивание указателю адреса массива
    ptf = bills;
    printf("%23s %15s\n","short","double");
    for (index =0; index <SIZE; index++)
        printf("указатели + %d: %10p %10p\n",index,pti + index,ptf + index);
    
    return 0;
}
*//*
//list_10_9 day_mon.c //использование формы записи с указателями
#include<stdio.h>
#define MONTHS 12
int main(void)
{
    int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    
    for (index = 0;index <MONTHS; index++)
        printf("Месяц %2d имеет %d день(дней).\n",index+1,*(days+index)); //то же самое, что и days[index]
    
    return 0;
}
   *//*
//list_10_10 sum_arr1.c сумма элементов массива
#include<stdio.h>
#define SIZE 10
int sum(int ar[], int n);
int main(void)
{
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;
    answer = sum(marbles,SIZE);
    printf("Общая сумма элементов массива mables = %ld.\n",answer);
    printf("Объем памяти, отведенной под массив mafbless,составляет %zd байт.\n",sizeof marbles);
    
    return 0;
}
int sum(int ar[],int n)
{
    int i;
    int total = 0;
    for (i=0;i<n;i++)
        total +=ar[i];
    printf("Размер ar составялет %zd байт.\n", sizeof ar); //размер ar = 8 байтов потому что ar это не сам массив а указательна первый элемент marbles в этой сисетеме для хранения адресов применяются 8 байт
    
    return total;
}
      *//*
//list_10_11 sum_arr2.c суммирование элементов массива с передачей в функцию указателей начала и конца массива
#include<stdio.h>
#define SIZE 10
int sump(int *start,int *end);
int main(void)
{
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;
    
    answer = sump(marbles,marbles+SIZE);
    printf("Общая сумма элементов массива mables = %ld.\n",answer);
    return 0;
}
//использование арифметике указателей
int sump(int *start,int *end)
{
    int total = 0;
    while(start < end)
    {
        total +=*start; //добавить значение к total
        start++; //переместить указатель на следующий элемент
    }
    return total;
}
         *//*
//list_10_12 order.c приоритеты операций с указателями
#include<stdio.h>
int data[2] = {100,200};
int moredata[2] = {300,400};
int main(void)
{
    int *p1,*p2,*p3;
    p1 = p2 = data;
    p3= moredata;
    printf("*p1 = %d,*p2 = %d,*p3 = %d\n",*p1  ,*p2,  *p3);
    printf("*p1++ = %d, *++p2 = %d,(*p3)++ = %d\n", *p1++  ,*++p2,(*p3)++);// для p1 сначала выполняется операция с разыменнованным указателем( выводится на печать), потом он инкреминируется p3- сначала разыменовывается указатель и выводится на печать, потом это значение инкреминируется
    printf("*p1 = %d, *p2 = %d, *p3 = %d\n", *p1  ,*p2  ,*p3);// в результате для p1 значение следующего элемента массива data а для p3 = 301 ( первое значение +1)
    
    return 0;
}
            *//*
//list_10_13 операции над указателями prt_ops.c
#include<stdio.h>
int main(void)
{
    int urn[5] = {100,200,300,400,500};
    int *ptr1,*ptr2,*ptr3;
    
    ptr1 = urn; //присваивание указателю адреса
    ptr2 = &urn[2]; //тоже самое
    
    //разыменование указателя и получене адреса указателя
    printf("значение указателя, разыменованный указатель, адрес указателя:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1,*ptr1,&ptr1);
    
    //сложение целого числа с указателем
    ptr3 = ptr1+4;
    printf("\nсложение значения int c указателем:\n");
    printf("ptr1 + 4 = %p , *(ptr1+3) = %d\n",ptr1+4,*(ptr1+4)); //аналогично urn[4]
    
    //инкреминирование указателя
    ptr1++;
    printf("\nзначения, после выполнения операции ptr1++:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",ptr1,*ptr1,&ptr1);
    
    //декриминирование указателя
    ptr2--;
    printf("\nзначения после выполенния операции --ptr2:\n");
    printf("ptr2 = %p,*ptr2 = %d, &ptr2 = %p\n", ptr2,*ptr2,&ptr2);
    
    //восстановадление исходного значения
    --ptr1;
    ++ptr2;
    printf("\nвосстановление исходных значений указателей:\n");
    printf("ptr1 = %p,ptr2 = %p\n", ptr1,ptr2);
    
    //вычитание одного указателя из другого
    printf("\nвычитание одного указателя из другого:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2-ptr1 = %td\n", ptr2, ptr1, ptr2-ptr1);//разница равна 2 те объекты на которые указывают указатели отделены друг от друга двумя значениями int а не двумя байтами
    
    //вычитание целогоо значения из указателя
    printf("\nвычитание из указателя значения типа int:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n",ptr3,ptr3-2);
    return 0;
}
               *//*
//list_10_14 arf.c использование const с массивами
#include<stdio.h>
#define SIZE 5
void show_array(const double ar[],int n);
void mult_array(double ar[],int n, double mult);
int main(void)
{
    double dip[SIZE] = {20.0,17.66,8.2,15.3,22.22};
    
    printf("Исходный массив dip:\n");
    show_array(dip,SIZE);
    mult_array(dip,SIZE,2.5);
    printf("Массив после вызова функции mult_array():\n");
    show_array(dip,SIZE);
    
    return 0;
}

//выводит содержимое массива
void show_array(const double ar[],int n)
{
    int i;
    for (i=0;i < n; i++)
        printf("%8.3f ",ar[i]);
    putchar('\n');
}
//умножает каждый элемент массива на один и тот же множитель
void mult_array(double ar[],int n,double mult)
{
    int i;
    for (i=0;i<n;i++)
        ar[i] *= mult;
}
*//*
//list_10_15 zippo1.c  указатели на двумерные массивы
#include<stdio.h>
int main(void)
{
    int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
    printf(" zippo = %p, zippo + 1 = %p\n", zippo,zippo +1);
    printf("zippo[0] = %p, zippo[0]+1 = %p\n",zippo[0],zippo[0]+1);
    printf(" *zippo = %p, *zippo+1 =%p\n",*zippo, *zippo+1);
    printf("zippo[0][0] = %d\n",zippo[0][0]);
    printf(" *zippo[0] = %d\n",*zippo[0]);
    printf(" **zippo = %d\n", **zippo);
    printf("     zippo[2][1] = %d\n", zippo[2][1]);
    printf(" *(*(zippo+2)+1) = %d\n", *(*(zippo+2)+1));
    
    return 0;
}
*//*
//lsit_10_16 zippo2.c получение информации о массиве zippo с помощью переменной типа указателя
#include<stdio.h>
int main(void)
{
    int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};
    int (*pz)[2]; //указатель на массив из двух элементов типа int
    pz = zippo;
    
    printf(" pz = %p, pz+1 = %p\n", pz,pz+1);
    printf(" pz[0] = %p, pz[0]+1 = %p", pz[0], pz[0]+1);
    printf(" *pz = %p, *pz+1 = %p\n", *pz,*pz+1);
    printf("pz[0][0] = %d\n",pz[0][0]);
    printf("   *pz[0] = %d\n",*pz[0]);
    printf("  **pz = %d\n", **pz);
    printf("   pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2)+1) = %d\n", *(*(pz+2)+1));
    
    return 0;
}
*//*
//list_10_17 формы синтаксиса прототипов
#include<stdio.h>
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);
int sum2d(int (*ar)[COLS] , int rows);
int main(void)
{
    int junk[ROWS][COLS] = {
        {2,4,6,8},
        {3,5,7,9},
        {12,10,8,6}
    };
    
    sum_rows(junk,ROWS);
    sum_cols(junk, ROWS);
    printf("Сумма всех элементов = %d\n",sum2d(junk,ROWS));
    
    return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
    int r,c,tot;
    
    for (r=0;r<rows;r++)
    {
        tot = 0;
        for (c=0;c<COLS;c++)
            tot += ar[r][c];
        printf("строка %d: сумма = %d\n",r, tot);
    }
}

void sum_cols(int ar[][COLS], int rows)
{
    int r,c,tot;
    
    for (c = 0;c<COLS;c++)
    {
        tot = 0;
        for (r=0;r<rows;r++)
            tot +=ar[r][c];
        printf("столбец %d: сумма = %d\n",c,tot);
    }
}

int sum2d(int ar[][COLS], int rows)
{
    int r,c,tot = 0;
    for (r=0;r < rows;r++)
        for (c= 0;c<COLS;c++)
            tot +=ar[r][c];
    
    return tot;
}
*//*
//list_10_18 vararr2d.c функции использующие массивы переменной длины
#include<stdio.h>
#define ROWS 4
#define COLS 4
int sum2d(int rows,int cols,int ar[rows][cols]);
int main(void)
{
    int i,j;
    int rs=3,cs=10;
    int junk[ROWS][COLS] = {
        {2,4,6,8},
        {3,5,7,9},
        {12,10,8,6}
    };
    int morejunk[ROWS-1][COLS+2] =
    {
        {20,30,40,50,60,70},
        {5,6,7,8,9,10}
    };
    int varr[rs][cs]; //массив переменной длины
    for (i = 0;i < rs; i++)
        for (j = 0;j < cs;j++)
            varr[i][j] = i+j+j;
    printf("Традиционный массив 3х5\n");
    printf("Сумма всех элементов = %d\n", sum2d(ROWS,COLS,junk));
    printf("Традиционный массив 2х6\n");
    printf("Сумма всех элементов = %d\n", sum2d(ROWS-1,COLS+2,morejunk));
    printf("Массив переменной длины 3х10\n");
    printf("Сумма всех элементов = %d\n",sum2d(rs,cs,varr));
    
    return 0;
}
//функция с параметром типа массива переменной длины
int sum2d(int rows,int cols,int ar[rows][cols])
{
    int r,c,tot =0;
    for (r=0; r < rows; r++)
        for (c=0; c < cols; c++)
            tot += ar[r][c];
    
    return tot;
}
*//*
//list_10_19 flc.c   создание и передача в функцию составных литералов
#include <stdio.h>
#define COLS 4
int sum2d(const int ar[][COLS],int rows);
int sum(const int ar[],int n);
int main(void)
{
    int total1,total2,total3;
    int *pt1;
    int(*pt2)[COLS];
    
    pt1 = (int[2]){10,20};
    pt2 = (int[2][COLS]){{1,2,3,-9},{4,5,6,-8}};
    
    total1 = sum(pt1,2);
    total2 = sum2d(pt2,2);
    total3 = sum((int[]){4,4,4,5,5,5},6);
    printf("total1 = %d\n",total1);
    printf("total2 = %d\n", total2);
    printf("total3 = %d\n",total3);
    
    return 0;
}

int sum(const int ar[],int n)
{
    int i,total = 0;
    
    for (i=0;i < n;i++)
        total +=ar[i];
    
    return total;
}

int sum2d(const int ar[][COLS],int rows)
{
    int r,c, tot = 0;
    
    for (r=0; r <  rows; r++)
        for (c=0; c < COLS; c++)
            tot += ar[r][c];
    
    return tot;
}
   *//*
//ex1 модификация list_10_7 заменяем получение данных на указатели
#include<stdio.h>
#define MONTHS 12 //количество месяцев в году
#define YEARS 5 //количество лет за которые доступны данные
int main(void)
{
    //инициализация данными об осадках за 5 лет
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2},
    };
    int year,month;
    float subtot,total;
    printf("ГОД  КОЛИЧЕСТВО ОСАДКОВ(в дюймах)\n");
    for (year = 0,total = 0;year < YEARS;year++)
    {
        //для каждого года суммировать количество осадков за каждый месяц
        for (month = 0,subtot=0;month < MONTHS;month++)
            subtot += *(*(rain+year)+month);
        printf("%5d %15.1f\n",2010+year,subtot);
        total += subtot;//общая сумма для всех лет
    }
    printf("\nСреднегодовое количество осадков составляет %.1f дюймов.\n\n",total/YEARS);
    printf("СРЕДНЕМЕСЯЧНОЕ ЕОЛИЧЕСТВО ОСАДКОВ:\n\n");
    printf(" Янв  Фев  Мар  Апр  Май  Июн  Июл  Авг  Сен  Окт  Ноя  Дек\n");
    for (month =0;month <MONTHS; month++)
    {
        //для каждого месяца суммировать количетсов осадков на протяжении годов
        for (year = 0,subtot =0;year < YEARS; year++)
            subtot +=*(*(rain+year)+month);
        printf("%4.1f ",subtot/YEARS);
    }
    printf("\n");
    
    return 0;
}
*//*
//ex2  копирование массивов
#include<stdio.h>
void copy1(double ar1[],const double ar2[], int n);
void copy2(double *ar1,const double *ar2,int n);
void copy3(double *ar1,const double *start,const double *end);
void display_arr(const double *ar,int N);

const int N=5;

int main(void)
{
    double source[N] = {1.1,2.2,3.3,4.4,5.5};
    double target1[N];
    double target2[N];
    double target3[N];
    
    copy1(target1,source,N);
    copy2(target2,source,N);
    copy3(target3,source,source+N);
    
    display_arr(target1,N);
    display_arr(target2,N);
    display_arr(target3,N);
    
    return 0;
}
void copy1(double ar1[],const double ar2[], int n)
{
    int i;
    for (i=0;i<n;i++)
        ar1[i]=ar2[i];
}
void copy2(double *ar1,const double *ar2, int n)
{
    int i;
    for (i=0;i<n;i++)
        *(ar1+i)=*(ar2+i);
}
void copy3(double *ar,const double *start, const double *end)
{
    
    while(start <end)
    {
        *ar = *start;
        ar++;
        start++;
    }

}

void display_arr( const double *arr,int N)
{
    int i;
    for (i=0;i<N;i++)
        printf("%2.1f ",arr[i]);
    printf("\n");
}
*//*
//ex5,ex6
#include<stdio.h>
const int N=5;
double max_dif(const double *start,const double *end);
void reverse_show(const double * start,const double *end);

int main(void)
{
    double source[N] = {1.1,2.2,3.3,4.4,5.5};
    printf("Разница между максимальныым и минимальным значениями: %0.1f\n",max_dif(source,source+N));
    printf("Выводим массив в обратном порядке:\n");
    reverse_show(source,source+N);
    return 0;
}

double max_dif(const double *start,const double *end)
{
    double min_ar = *start;
    double max_ar = *start;
    
    while (start < end)
    {
        if (*start<min_ar)
            min_ar = *start;
        if (*start >max_ar)
            max_ar = *start;
        start++;
    }
    return max_ar-min_ar;
}
void reverse_show(const double *start,const double *end)
{
    while(start <end)
        printf("%2.1f ",*(--end));
    printf("\n");
}
*//*
//ex7
#include<stdio.h>
#define MEMORY 3
#define ORIGINE 4
void get_ar(double ar[][ORIGINE],int n);
void display2d(double ar[][ORIGINE], int n);
void copyd(double *ar1,const double *start,const double *end);
void copy2d(double ar1[][ORIGINE],const double ar2[][ORIGINE],const int n);

int main(void)
{
    
    double initial[MEMORY][ORIGINE];
    double copy_ar[MEMORY][ORIGINE];
    get_ar(initial,MEMORY);
    printf("Оригинальный массив:\n");
    display2d(initial, MEMORY);
    printf("Копия массива INITIAL:\n");
    copy2d(copy_ar,initial,ORIGINE);
    display2d(copy_ar, MEMORY);
    
    
    
    return 0;
}

void get_ar(double ar[][ORIGINE],int n)
{
    int i,j;
    printf("Создаем начальный массив %d на %d:\n",n,ORIGINE);
    for (i=0;i<n;i++)
        for(j=0;j<ORIGINE;j++)
        {
            printf("Элемент [%d][%d] ",i,j);
            scanf("%lf",&ar[i][j]);

        }
}
void copyd(double *ar,const double *start, const double *end)
{
    
    while(start <end)
    {
        *ar = *start;
        ar++;
        start++;
    }

}
void copy2d(double ar1[][ORIGINE],const double ar2[][ORIGINE],const int n)
{
    int i;
    for (i=0;i<n;i++)
        copyd(ar1[i],ar2[i],ar2[i]+n);
}
void display2d(double ar[][ORIGINE],int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
         for(j=0;j<ORIGINE;j++)
             printf("%4.1f ",ar[i][j]);
        printf("\n");
    }
}
*//*
//ex8 копируем с 3 по 5 элемент семиэлементного массива
#include<stdio.h>
void copyd(double *ar,const double *start, const double *end);
void display_arr( const double *arr,int N);
const int N=7;
const int M=3;

int main(void)
{
    double source[N] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7};
    double target[M];
    copyd(target,source+2,source+5);
    display_arr(target,M);
}
void copyd(double *ar,const double *start, const double *end)
{
    
    while(start <end)
    {
        *ar = *start;
        ar++;
        start++;
    }

}
void display_arr( const double *arr,int N)
{
    int i;
    for (i=0;i<N;i++)
        printf("%2.1f ",arr[i]);
    printf("\n");
}
*//*
//ex9 обработка массивов переменной длины
#include<stdio.h>
void get_ar(int row,int col, double ar[row][col]);
void display2d(int row,int col,double ar[row][col]);
void copy2d(int row,int col, double ar1[row][col],const double ar2[row][col]);

int main(void)
{
    int rs = 3,cs = 5;
    double initial[rs][cs];
    double copy_ar[rs][cs];
    get_ar(rs,cs,initial);
    printf("Оригинальный массив:\n");
    display2d(rs,cs,initial);
    printf("Копия массива INITIAL:\n");
    copy2d(rs,cs,copy_ar,initial);
    display2d(rs,cs,copy_ar);
    
    
    
    return 0;
}

void get_ar(int row,int col,double ar[row][col])
{
    int i,j;
    printf("Создаем начальный массив %d на %d:\n",row,col);
    for (i=0;i<row;i++)
        for(j=0;j<col;j++)
        {
            printf("Элемент [%d][%d] ",i,j);
            scanf("%lf",&ar[i][j]);

        }
}

void copy2d(int row,int col, double ar1[row][col],const double ar2[row][col])
{
    int i,j;
    for (i=0;i<row;i++)
        for(j=0;j<col;j++)
            ar1[i][j] = ar2[i][j];
              
}
void display2d(int row,int col,double ar[row][col])
{
    int i,j;
    for (i=0;i<row;i++)
    {
         for(j=0;j<col;j++)
             printf("%4.1f ",ar[i][j]);
        printf("\n");
    }
}
*/
/*
#include<stdio.h>
#include<math.h>
double foo(double x);
int main(void)
{
    const double eps = 0.00001;
    double start = -2-eps;
    double end = 2-eps;
    double step;
    for (step = start; step < end; step +=0.000001)
        if (fabs(foo(step)) < eps)
            printf("%f %f\n",step,foo(step));
}
double foo(double x)
{
    return (pow((x-2),2)/2 +18/(pow((x-2),2)))-( 7*((x-2)/2 - 3/(x-2))+2);
}
 *//*
//ex10 суммируем значения в двух массивах
#include<stdio.h>
void get_ar(int ar[],int n);
void sum_ar(const int ar1[], const int ar2[], int ar3[],int n);
void display(const int ar[],int n);
const int N = 4;

int main(void)
{
    int ar1[N],ar2[N],ar_total[N];
    printf("Создаем  1-й начальный массив:\n");
    get_ar(ar1,N);
    printf("Создаем  2-й начальный массив:\n");
    get_ar(ar2,N);
    printf("1-й массив:\n");
    display(ar1,N);
    printf("2-й массив:\n");
    display(ar2,N);
    sum_ar(ar1,ar2,ar_total,N);
    
    
    return 0;
}
void get_ar(int ar[],int n)
{
    int i;
    printf("Вводим  %d значения:\n", n);
    for (i=0;i<n;i++)
        scanf("%d",&ar[i]);
}
void display(const int ar[],int n)
{
    int i;
    for (i=0;i<n;i++)
           printf("%d ",ar[i]);
    printf("\n");
}
void sum_ar(const int ar1[], const int ar2[],int ar3[],int n)
{
    int i;
    for (i=0;i < n;i++)
        ar3[i] = ar1[i]+ar2[i];
    printf("Сумма массивов:\n");
    display(ar3, n);
}
*//*

//еx11 инициализируем двумерный массив и удваиваем его значения

#include<stdio.h>
#define MEMORY 3
#define ORIGINE 5
void get_ar(int ar[][ORIGINE],int n);
void display2d(int ar[][ORIGINE], int n);
void two_times_ar(int ar[][ORIGINE],int n);

int main(void)
{
    
    int initial[MEMORY][ORIGINE];

    get_ar(initial,MEMORY);
    printf("Оригинальный массив:\n");
    display2d(initial, MEMORY);
    printf("Массив с удвоенными значениями:\n");
    two_times_ar(initial,MEMORY);
    display2d(initial, MEMORY);
    
    
    return 0;
}

void get_ar(int ar[][ORIGINE],int n)
{
    int i,j;
    printf("Создаем начальный массив %d на %d:\n",n,ORIGINE);
    for (i=0;i<n;i++)
        for(j=0;j<ORIGINE;j++)
        {
            printf("Элемент [%d][%d] ",i,j);
            scanf("%d",&ar[i][j]);

        }
}

void two_times_ar(int ar[][ORIGINE],int n)
{
    int i,j;
    for (i=0;i<n;i++)
        for(j=0;j<ORIGINE;j++)
            ar[i][j] *=2;
}

void display2d(int ar[][ORIGINE],int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
         for(j=0;j<ORIGINE;j++)
             printf("%4d ",ar[i][j]);
        printf("\n");
    }
}
*//*
//ex12 создаем функции для list 10_7

#include<stdio.h>
#define MONTHS 12 //количество месяцев в году
#define YEARS 5 //количество лет за которые доступны данные
void year_rain(const float rain[][MONTHS],int year); //функция выводит годовое количество осадков
void months_rain(const float rain[][MONTHS],int year);//функция выводит среднемесячное количество осадков

int main(void)
{
    //инициализация данными об осадках за 5 лет
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2},
    };
    year_rain(rain,YEARS);
    months_rain(rain, YEARS);
    
    return 0;
}
void year_rain(const float rain[][MONTHS],int year)
{
    int month;
    float subtot,total;
    printf("ГОД  КОЛИЧЕСТВО ОСАДКОВ(в дюймах)\n");
    for (year = 0,total = 0;year < YEARS;year++)
    {
        //для каждого года суммировать количество осадков за каждый месяц
        for (month = 0,subtot=0;month < MONTHS;month++)
            subtot += *(*(rain+year)+month);
        printf("%5d %15.1f\n",2010+year,subtot);
        total += subtot;//общая сумма для всех лет
    }
    printf("\nСреднегодовое количество осадков составляет %.1f дюймов.\n\n",total/YEARS);
}
void months_rain(const float rain[][MONTHS],int year)
{
    int month;
    float subtot;
    printf("СРЕДНЕМЕСЯЧНОЕ ЕОЛИЧЕСТВО ОСАДКОВ:\n\n");
    printf(" Янв  Фев  Мар  Апр  Май  Июн  Июл  Авг  Сен  Окт  Ноя  Дек\n");
    for (month =0;month <MONTHS; month++)
    {
        //для каждого месяца суммировать количетсов осадков на протяжении годов
        for (year = 0,subtot =0;year < YEARS; year++)
            subtot +=*(*(rain+year)+month);
        printf("%4.1f ",subtot/YEARS);
    }
    printf("\n");
    

}
   *//*
//ex13  обработка двумерного массива
#include <stdio.h>
#define ROWS 3
#define COLONS 5
void get_dates(double [][COLONS],int );
double middle_rows(double *, double *);
double middle_total(double [][COLONS], int);
double get_max(double [][COLONS], int);
void display(double [][COLONS], int);
int main(void)
{
    double ar[ROWS][COLONS];
    get_dates(ar,ROWS);
    int i;
    printf("Среднее значение по каждому ряду:\n");
    for (i = 0;i < ROWS; i++)
    {
        printf("%d-й ряд: %.2f\n",i+1,middle_rows(ar[i],ar[i]+COLONS));
    }
    printf("Среднее значение по всему массиву:%.2f\n",middle_total(ar, ROWS));
    printf("Максимальное значение в массиве:%.2f\n",get_max(ar,ROWS));
    
    return 0;
}
void get_dates(double ar[][COLONS],int row)
{
    int i,j;
    printf("Создаем начальный массив %d на %d:\n",row,COLONS);
    for (i=0;i<row;i++)
        for(j=0;j<COLONS;j++)
        {
            printf("Элемент [%d][%d] ",i,j);
            scanf("%lf",&ar[i][j]);

        }
    display(ar, ROWS);
}

void display(double ar[][COLONS],int row)
{
    printf("Отображаем полученные данные:\n");
    int i,j;
    for (i=0;i<row;i++)
    {
         for(j=0;j<COLONS;j++)
             printf("%4.1f ",ar[i][j]);
        printf("\n");
    }
}

double middle_rows(double *start, double *end)
{
    size_t n = end-start;
    double totalOfRow = 0.0;
    while (start < end)
    {
        totalOfRow += *start;
        start++;
    }
    return totalOfRow/n;
}

double middle_total(double ar[][COLONS], int row)
{
    double totalOfAr = 0.0;
    int i,j;
    for (i=0;i<row;i++)
    {
         for(j=0;j<COLONS;j++)
             totalOfAr += ar[i][j];
    }
    
    return totalOfAr/(row*COLONS);
}

double get_max(double ar[][COLONS], int row)
{
    
      int i,j;
      double maxOfAr = ar[0][0];
      for (i=0;i<row;i++)
      {
           for(j=0;j<COLONS;j++)
               if (ar[i][j] > maxOfAr)
                   maxOfAr =ar[i][j];
      }
    
    return maxOfAr;
}
*/
//ex14 предудущее упражнение с применением массивов переменной длины
#include <stdio.h>

void get_dates(int r,int c, double [r][c]);
double middle_rows(double *, double *);
double middle_total(int r,int c, double [r][c]);
double get_max(int r,int c, double [r][c]);
void display(int r,int c, double [r][c]);
int main(void)
{
    int rows = 3, colons = 5;
    double ar[rows][colons];
    get_dates(rows,colons,ar);
    int i;
    printf("Среднее значение по каждому ряду:\n");
    for (i = 0;i < rows; i++)
    {
        printf("%d-й ряд: %.2f\n",i+1,middle_rows(ar[i],ar[i]+colons));
    }
    printf("Среднее значение по всему массиву:%.2f\n",middle_total(rows,colons,ar));
    printf("Максимальное значение в массиве:%.2f\n",get_max(rows,colons,ar));
    
    return 0;
}
void get_dates(int row,int colons, double ar[row][colons])
{
    int i,j;
    printf("Создаем начальный массив %d на %d:\n",row,colons);
    for (i=0;i<row;i++)
        for(j=0;j<colons;j++)
        {
            printf("Элемент [%d][%d] ",i,j);
            scanf("%lf",&ar[i][j]);

        }
    display(row,colons,ar);
}

void display(int row,int colons, double ar[row][colons])
{
    printf("Отображаем полученные данные:\n");
    int i,j;
    for (i=0;i<row;i++)
    {
         for(j=0;j<colons;j++)
             printf("%4.1f ",ar[i][j]);
        printf("\n");
    }
}

double middle_rows(double *start, double *end)
{
    size_t n = end-start;
    double totalOfRow = 0.0;
    while (start < end)
    {
        totalOfRow += *start;
        start++;
    }
    return totalOfRow/n;
}

double middle_total(int row,int colons, double ar[row][colons])
{
    double totalOfAr = 0.0;
    int i,j;
    for (i=0;i<row;i++)
    {
         for(j=0;j<colons;j++)
             totalOfAr += ar[i][j];
    }
    
    return totalOfAr/(row*colons);
}

double get_max(int row,int colons, double ar[row][colons])
{
    
      int i,j;
      double maxOfAr = ar[0][0];
      for (i=0;i<row;i++)
      {
           for(j=0;j<colons;j++)
               if (ar[i][j] > maxOfAr)
                   maxOfAr =ar[i][j];
      }
    
    return maxOfAr;
}
