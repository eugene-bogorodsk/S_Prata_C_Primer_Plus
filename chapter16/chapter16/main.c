//
//  main.c
//  chapter16
//
//  Created by пупсик on 06.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//

//list_16_1 пример работы с препроцессором
/*
#include <stdio.h>
#define TWO 2
#define OW "Логика - последнее убежище лишенных\
вооображения. - Оскар Уальд"

#define FOUR TWO*TWO
#define PX printf("X = %d.\n",x)
#define FMT "X = %d.\n"

int main() {
 
    int x = TWO;
    PX;
    x = FOUR;
    printf(FMT,x);
    printf("%s\n",OW);
    printf("TWO: OW\n");
    
    return 0;
}
*//*
//list_16_2 mac_arg.c макросы с аргументами
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("Результат: %d.\n",X)

int main(void)
{
    int x = 5;
    int z;
    
    printf("x = %d\n",x);
    z = SQUARE(x);
    printf("Вычисление SQARE(2): ");
    PR(z);
    printf("Вычисление SQARE(x+2): ");
    PR(SQUARE(x+2));
    printf("Вычисление 100/SQARE(2): ");
    PR(100/SQUARE(2));
    printf("x = %d.\n",x);
    printf("Вычисление SQARE(++x): ");
    PR(SQUARE(++x));
    printf("После инкрементирования x = %x.\n",x);
    
    return 0;
}
*/
/*
//list_16_3 subst.c подстановка в строке
#include <stdio.h>
#define PSQR(x) printf("Квадрат "#x" равен %d.\n",((x) *(x)) )
int main(void)
{
    int y = 5;
    PSQR(y);
    PSQR(2+4);
    
    return 0;
}
*//*
//list_16_4 glue.c использование операции ##
#include <stdio.h>
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x" #n" = %d\n", x##n);

int main(void)
{
    int XNAME(1) = 14; //превращается в int x1 = 14;
    int XNAME(2) = 20; //превращается в int x2 = 20;
    int x3 = 20;
    
    PRINT_XN(1); //превращается в printf("x1 = %d\n",x1);
    PRINT_XN(2); //превращается в printf("x2 = %d\n",x2);
    PRINT_XN(3); //превращается в printf("x3 = %d\n",x3);
    
    return 0;
}
*//*
//list_16_5 variadic.c макросы с переменным числом аргументов
#include <stdio.h>
#include <math.h>
#define PR(X, ...) printf("Сообщение "#X": "__VA_ARGS__);

int main(void)
{
    double x = 48;
    double y;
    
    y = sqrt(x);
    PR(1,"x = %g\n",x);
    PR(2,"x = %.2f, y = %.4f\n",x,y);
    
    return 0;
}
*//*
//list_16_6 
#include <stdio.h>
#include "names_st.h"

int main(void)
{
    names candidate;
    
    get_names(&candidate);
    printf("Добро пожаловать в программу, ");
    show_names(&candidate);
    printf("!\n");
    
    return 0;
}
*//*
//list_16_9 idef.c использование условной компиляции
#include <stdio.h>
#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
    int i;
    int total = 0;
    
    for (i = 1;i<=LIMIT; ++i)
    {
        total += 2*i*i + 1;
#ifdef JUST_CHECKING
        printf("i=%d, промежуточная сумма = %d\n",i,total);
#endif
    }
    
    printf("Итоговая сумма = %d\n",total);
    
    return 0;
}
*/
/*
//list_16_12 predef.c предопределенные идентификаторы
#include <stdio.h>
void why_me(void);

int main(void)
{
    printf("Файл: %s.\n",__FILE__);
    printf("Дата: %s.\n",__DATE__);
    printf("Время: %s.\n",__TIME__);
    printf("Версия: %ld.\n",__STDC_VERSION__);
    printf("Это строка %d.\n",__LINE__);
    printf("Это функция %s.\n",__func__);
    why_me();
    
    return 0;
}
void why_me()
{
    printf("Это функция %s\n",__func__);
    printf("Это строка %d.\n", __LINE__);
}
*/
/*
//list_16_13 predef.c
#include <stdio.h>

#define NYTYPE(X) _Generic((X),\
int: "int",\
float:"float",\
double:"double",\
default:"other"\
)
int main(void)
{
    int d = 5;
    
    printf("%s\n",NYTYPE(d));//d имеет тип int
    printf("%s\n",NYTYPE(2.0*d));//2.0*d имеет тип double
    printf("%s\n",NYTYPE(3L));//3L имеет тип long
    printf("%s\n",NYTYPE(&d)); //&d имеет тип int*
    
    return 0;
}
*/
/*
//list_16_14 rect_pol.c преобразует прямоугольные координаты в полярные
#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG (180/(4*atan(1)))

typedef struct polar_v{
    double magnitude;
    double angle;
} Polar_V;

typedef struct rect_v {
    double x;
    double y;
} Rect_V;

Polar_V rect_to_polar(Rect_V);

int main(void)
{
    Rect_V input;
    Polar_V result;
    
    puts("Введите координаты x и y: введите q для выхода:");
    while(scanf("%lf %lf",&input.x,&input.y) == 2)
    {
        result = rect_to_polar(input);
        printf("Модуль = %0.2f, угол = %0.2f\n",result.magnitude,result.angle);
    }
    puts("Программа завершена.");
    
    return 0;
}

Polar_V rect_to_polar(Rect_V rv)
{
    Polar_V pv;
    
    pv.magnitude = sqrt(rv.x*rv.x + rv.y*rv.y);
    if (pv.magnitude == 0)
        pv.angle = 0.0;
    else
        pv.angle = RAD_TO_DEG*atan2(rv.y, rv.x);
    
    return pv;
}
 *//*
//list_16_15  определение обобщенных макросов
#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4*atan(1)))

//обобщенная функция извлечения квадратного корня
#define SQRT(X) _Generic((X),\
long double: sqrtl,\
default:sqrt,\
float:sqrtf)(X)

//обощенная функция вычисления синуса угла, заданного в градусах
#define SIN(X) _Generic((X),\
long double:sinl((X)/RAD_TO_DEG),\
default: sin((X)/RAD_TO_DEG),\
float:   sinf((X)/RAD_TO_DEG)\
)
int main(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx =45.0L;
    
    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);
    
    printf("%.17Lf\n",y); // соотаетствует float
    printf("%.17Lf\n",yy); //соответствует default
    printf("%.17Lf\n",yyy); // соответствует long double
    
    int i =45;
    yy = SQRT(i); // соответствует default
    printf("%.17Lf\n",yy);
    yyy = SIN(xxx); // соответствует  long double
    printf("%.17Lf\n",yyy);
    
    return 0;
}
    *//*
//list_16_16 byebye.c  пример применения atexit()
#include <stdio.h>
#include <stdlib.h>
void sign_off(void);
void too_bad(void);

int main(void)
{
    int n;
    
    atexit(sign_off); //регистрация функции  sign_off()
    puts("Введите целое число:");
    if (scanf("%d",&n) != 1)
    {
        puts("Это не целое число!");
        atexit(too_bad); //регистрация функции too_bad
    }
    printf("%d является %s.\n",n, (n % 2 == 0)? "четным":"нечетным");
    return 0;
}
void sign_off(void)
{
    puts("Завершение работы очередной замечательной программы от");
    puts("SeeSaw SofWare!");
}
void too_bad(void)
{
    puts("SeeSaw SoftWare приносит искренние соболезнования");
    puts("в связи с отказом программы.");
}
*//*
//list_16_17 использоваине быстрой сортировки для упорядочивания групп чисел
#include <stdio.h>
#include <stdlib.h>

#define NUM 40
void fillarray(double ar[],int n);
void showarray(const double ar[],int n);
int mycomp(const void *p1,const void *p2);

int main(void)
{
    double vals[NUM];
    fillarray(vals,NUM);
    puts("List of rand values: ");
    showarray(vals,NUM);
    qsort(vals,NUM,sizeof(double),mycomp);
    puts("\nSorted list: ");
    showarray(vals,NUM);
    
    return 0;
}

void fillarray(double ar[],int n)
{
    int index;
    
    for(index = 0;index < n; ++index)
        ar[index] = (double)rand()/((double)rand() + 0.1);
}

void showarray(const double ar[],int n)
{
    int index;
    
    for (index = 0;index < n; ++index)
    {
        printf("%9.4f", ar[index]);
        if (index%6 == 5)
            putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}

//сортировка по возрастанию
int mycomp(const void *p1,const void *p2)
{
    // для доступа к значениям необходимо использовать указатели на double*
    const double *a1 = (const double *) p1;
    const double *a2 = (const double *) p2;
    
    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else return 1;
}
*//*
//list_16_18
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()
{
    double x,y,z;
    
    puts("Введите пару чисел (0 0 для завершения): ");
    while (scanf("%lf%lf",&x,&y) == 2 && (x != 0 || y != 0))
    {
        z = x*x - y*y; //должно быть +
        assert(z >= 0);
        printf("результатом является %f\n",sqrt(z));
        puts("Введите следующую пару чисел: ");
    }
    puts("Программа завершена.");
    return 0;
}
*//*
//list_16_8 statassert.c
#include <stdio.h>
#include <limits.h>

_Static_assert (CHAR_BIT == 16,"Ошибочно предполагается 16-битовый тип char");
int main(void)
{
    puts("Тип char имеет 16 битов.");
    
    return 0;
}
*//*
//list_16_20 исоплзование функций memcpy() и memmove()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
void show_array(const int ar[],int n);

_Static_assert(sizeof(double) == 2*sizeof(int)," double does not have double size int");

int main(void)
{
    int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int target[SIZE];
    double curious[SIZE/2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};
    
    puts("Использование memcpy():");
    puts("значения (исходные данные):");
    show_array(values,SIZE);
    memcpy(target, values, SIZE);
    puts("целевые данные (копия значений):");
    show_array(target,SIZE);
    
    puts("\nИспользование memmove() с перекрывающимися областями:");
    memmove(values +2,values,5*sizeof(int));
    puts("значения -- элементы 0-5  скопированы в элементы 2-7:");
    show_array(values, SIZE);
    
    puts("\nИспользование memcpy()  для копирования double d int:");
    memcpy(target, curious, (SIZE/2)*sizeof(double));
    puts("целевые данные -- 5 значений double в 10 позициях int:");
    show_array(target,SIZE/2);
    show_array(target+5, SIZE/2);
    
    return 0;
}

void show_array(const int ar[],int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ",ar[i]);
    putchar('\n');
}
   *//*
//list_16_21 использование переменного числа аргументов
#include <stdio.h>
#include <stdarg.h>
double sum(int,...);

int main(void)
{
    double s,t;
    
    s = sum(3,1.1,2.5,13.3);
    t = sum(6,1.1,2.1,13.1,4.1,5.1,6.1);
    printf("возвращаемое значение sum(3,1.1,2.5,13.3):");
    printf("возвращаемое значение sum(6,1.1,2.1,13.1,4.1,5.1,6.1:");
    
    return 0;
}

double sum(int lim,...)
{
    va_list ap; //объявление объекта для хранения аргументов
    double tot = 0;
    int i;
    
    va_start(ap,lim); //инициализация ap списком аргументов
    for (i = 0;i < lim; ++i)
        tot += va_arg(ap,double); //доступ  к каждому элементу в списке аргументов
    va_end(ap); //очистка
    
    return tot;
}
*//*
//ex_2  макрос для гармонического среднего
#include <stdio.h>
#define GAR_MEAN(X,Y) (2/(1/(X) +1/(Y)))

int main(void)
{
    double x = 5.0;
    double y = 1.0;
    printf("%.4f\n",GAR_MEAN(x, y)) ;
}
*//*
//ex_3
#include <stdio.h>
#include <math.h>

 typedef struct polar_dates{
    double mod;
    double angle;
}pld;

typedef struct sq_dates{
    double x;
    double y;
}sqd;

sqd change_date(const pld*);
void show_sqd(const sqd*);

int main(void)
{
    pld d1_p = {3.0,3.14/6};
    sqd d1_s= change_date(&d1_p);
    show_sqd(&d1_s);
    return 0;
}
sqd change_date(const pld * pp)
{
    sqd ch_dot;
    ch_dot.x = pp->mod*cos(pp->angle);
    ch_dot.y = pp->mod*sin(pp->angle);
    
    return ch_dot;
}
void show_sqd(const sqd *sp)
{
    printf("%.3f : %.3f\n",sp->x,sp->y);
}
*//*
//ex_4
#include <stdio.h>
#include <time.h>
void make_sm(double );
int main(void)
{
    make_sm(0.03);
    return 0;
}
void make_sm(double tt)
{
    double t1,t2;
    t1 = clock();
    t2 = clock();
    double del_t = (t2-t1)/CLOCKS_PER_SEC;
    int count = 0;
    while (del_t <tt)
    {
        printf("%c",'*');
        ++count;
        t2 = clock();
        del_t = (t2-t1)/CLOCKS_PER_SEC;
    }
    
    puts("\n");
    printf("%d\n",count);
}
*//*
//ex_5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 20
void fill_ar(int [],int n);
void foo(const int [],int,int);


int main(void)
{
    srand((int)time(0));
    int ar[NUM];
    fill_ar(ar,NUM);
    foo(ar,NUM,5);
    
    return 0;
}
void fill_ar(int ar[],int n)
{
    for (int i = 0;i < n; ++i)
        ar[i] = rand()%100;
}
void foo(const int ar[],int n,int k)
{
    int num;
    
    for (int i = 0;i < k; ++i)
    {
        num = rand()%n;
        printf("%d ",ar[num]);
    }
    puts("\n");
}
*//*
//ex_6 переопределение  list_16_17
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 5

struct names{
    char first[30];
    char last[30];
};

void showarray(const struct names[],int n);
int mycomp(const void *p1,const void *p2);

int main(void)
{
    struct names famous[NUM]={
       
        {"Paul","McCartny"},
        {"Mikle","Jeckson"},
        {"Vladimir","Putin"},
         {"John","Lenon"}
    };
    
    puts("List of names: ");
    showarray(famous,NUM);
    qsort(famous,NUM,sizeof(struct names),mycomp);
    puts("\nSorted list: ");
    showarray(famous,NUM);
    
    return 0;
}


void showarray(const struct names ar[],int n)
{
    int index;
    
    for (index = 0;index < n; ++index)
        printf("%s %s\n", ar[index].last,ar[index].first);
            putchar('\n');

}

//сортировка по возрастанию
int mycomp(const void *p1,const void *p2)
{
    int res;
    // для доступа к значениям необходимо использовать указатели на names*
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;
    
    res = strcmp(ps1->last, ps2->last);
    if (res != 0)
        return res;
    else
        return strcmp(ps1->first,ps1->first);
}
*/
//ex_7
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array(const double ar[],int n);
double * new_d_array(int n,...);

int main(void)
{
    double *p1;
    double *p2;
    
    p1 = new_d_array(5,1.2,2.3,3.4,4.5,5.6);
    p2 = new_d_array(4,100.0,20.00,8.08,-1890.8);
    show_array(p1, 5);
    show_array(p2,4);
    free(p1);
    free(p2);
    
    return 0;
}

void show_array(const double ar[],int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%.2f ",ar[i]);
    putchar('\n');
}

double * new_d_array(int n,...)
{
    va_list ap;
    int i;
    double *pd = (double*)malloc(sizeof(double)*n);
    
    va_start(ap,n);
    for (i = 0;i < n; ++i)
        pd[i] = va_arg(ap,double);
    va_end(ap);
    
    return pd;
}
