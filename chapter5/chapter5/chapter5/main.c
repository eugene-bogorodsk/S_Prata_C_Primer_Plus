//
//  main.c
//  chapter5
//
//  Created by пупсик on 14.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_5_1 shoes.c преобразование размера обуви в дюймы
#include <stdio.h>
#define ADJUST 7.31

int main(void) {
    const double SCALE = 0.333;
    double shoe,foot;
    
    shoe = 9.0;
    foot = SCALE*shoe +ADJUST;
    printf("Размер обуви (мужской)    длина ступни\n");
    printf("%10.1f %20.2f дюймов\n",shoe,foot);
    
    return 0;
}
 *//*
//list_5_2 shoes2.c вычисляем длину стопы для нескольких размеров обуви
#include <stdio.h>
#define ADJUST 7.31
int main(void)
{
    const double SCALE = 0.333;
    double shoe,foot;
    printf("Размер обуви (мужской)    длина ступни\n");
    shoe = 3.0;
    while (shoe<18.5)//начало цикла while
    {//начало блока
        foot = SCALE*shoe+ADJUST;
        printf("%10.1f %20.2f дюймов\n",shoe,foot);
        shoe=shoe+1.0;
    }
    printf("Если обувь подходит, носите её.\n");
    
    return 0;
}
*//*
//list_5_3 golf.c - таблица результатов турнира по гольфу
#include<stdio.h>
int main(void)
{
    int jane,tarzan,cheeta;
    cheeta=tarzan=jane=68;
    printf("                     чита    тарзан   джейн\n");
    printf("Счёт первого раунда %4d %8d %8d\n",cheeta,tarzan,jane);
    
    return 0;
}
*//*
//list_5_4  squares.c генерирует таблицу квадратов 20 значений
#include<stdio.h>
int main(void)
{
    int num = 1;
    while (num<21)
    {
        printf("%4d %6d\n",num,num*num);
        num=num+1;
    }
    return 0;
}
*//*
//list_5_5 wheat.c экспоненциальный рост
#include<stdio.h>
#define SQUARES 64 //количество клеток шахматной доски

int main(void)
{
    const double CROP = 2E16;//мировой урожай пшеницы в зернах
    double current,total;
    int count =1;
    printf("квадрат   добавлено      итого    ");
    printf("   процент от\n");
    printf("           зёрен         зёрен     ");
    printf("мирового урожая\n");
    
    total = current = 1.0;//начинаем с одного зёрнышка
    printf("%4d %13.2e %12.2e %12.2e\n",count,current,total,total/CROP);
    
    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;//удвоить количество зерен на следующей клетке
        total = total + current;//обновить итоговую сумму
        printf("%4d %13.2e %12.2e %12.2e\n",count,current,total,total/CROP);
    }
    printf("Вот и всё!");
    
    return 0;
}
   *//*
//list_5_8 sizeof.c оиспользование операции sizeof  с использованием модификатора %z
#include<stdio.h>
int main(void)
{
    int n=0;
    size_t intsize;
    intsize = sizeof (int);
    printf("n=%d, n состоит из %zd байтов; все значения int имеют %zd байт.\n",n,sizeof n,intsize);
    return 0;
}
*//*
//list_5_9 min_sec.c перевод секунд в минуты и секунды
#include<stdio.h>
#define SEC_PER_MIN 60
int main(void)
{
    int sec,min,left;
    
    printf("Перевод секунд в минуты и секунды!\n");
    printf("Введите количество секунд (<=0 для выхода):\n");
    scanf("%d",&sec);
    while (sec>0)
    {
        min=sec/SEC_PER_MIN;//усечённое количество минут
        left=sec%SEC_PER_MIN;//количество секунд в остатке
        printf("%d секунд - это %d минут %d секунд.\n",sec,min,left);
        printf("Введите следующее значение (<=0 для выхода):\n");
        scanf("%d",&sec);
    }
    return 0;
}
*//*
//list_5_10 add_one.c инкремент: префиксная и постфиксная формы
#include<stdio.h>
int main(void)
{
    int ultra=0,super =0;
    while(super<5)
    {
        super++;
        ++ultra;
        printf("super = %d,ultra = %d\n",super,ultra);
        
    }
    return 0;
}
*//*
//list_5_11 post_pre.c постфиксная и префиксная формы
#include<stdio.h>
int main(void)
{
    int a=1,b=1;
    int a_post,pre_b;
    
    a_post=a++;
    pre_b=++b;
    printf("a  a_post   b   pre_b\n");
    printf("%d %5d %5d %5d\n",a,a_post,b,pre_b);
    
    return 0;
}
   *//*
//list_5_12 bottles.c использование декремента
#include<stdio.h>
#define MAX 10
int main(void)
{
    int count = MAX+1;
    while (--count >0)
    {
        printf("%d бутылок родниковой воды на полке, %d бутылок родниковой воды!\n",count,count);
        printf("Возьмите одни из них и пустите по кругу,\n");
        printf("%d бутылок родниковой воды!\n\n",count-1);
    }
    return 0;
}
*//*
//list_5_13 addemup.c пять видов операторов
#include <stdio.h>
int main(void) //находит сумму первых 20 чисел
{
    int count,sum; //оператор объявления
    count = 0; //оператор присваивания
    sum=0; //оператор присваивания
    while (count++<20) //oператор
        sum=sum+count;//while
    printf("sum = %d\n",sum);//оператор вызова функции
    
    return 0;
}
*//*
//list_5_14 автоматическое преобразование типов
#include<stdio.h>
int main(void)
{
    char ch;
    int i;
    float fl;
    
    fl=i=ch='C';
    printf("ch = %c, i = %d, fl = %2.2f\n",ch,i,fl);//символ С сохраняется как однобайтовое значене в переменной ch. Целочисленная i получает результат целочисленного преобразования С который представляет собой число 67 сохраненное в 4 байтах памяти Переменная fl получает результат преобразования в плавающей запятой
    
    ch=ch+1;// значеие С символьное переменной преобразуется в целое число 67 к которому затем добавляется 1 Результирующее 4 байтовое целое число 68 усекатеся до 1 байта и сохраняется в переменной ch В случае вывода со спецификатором %c число 68 интерпретируется как D
    i=fl+2*ch;//при умножении на 2 значение ch преобразутся в 4 байтовое целое (68) Результирующее целое (136) преобразуется в число с плавающей запятой  для его сложения с fl  Результат (203.0) преобразутеся в тип int и сохранятся в i
    fl=2.0*ch+i;//значение переменной ch (68  или D) преобразуется в тип с плавающей запятой для его умножения на 2.0 Значение i(203) преобразуется в значение с  плавающей запятой для выполнения сложения и результат (330.00) сохраняется в fl
    printf("ch=%c ,i = %d, fl = %2.2f\n",ch,i,fl);
    
    ch=1107;//здесь выполнятеся попытка понижения (выдается предупреждение компилятораД) когда переменной ch присваивается значение , выходящее за диапазон допустимых значений  После игнорирования лишних разрядов переменная ch получает значение равное коду символа S те 1107%256 = 83 что является кодом S
    printf("Теперь ch = %c\n",ch);
    ch=80.99;//ещё пример понижения при котором значение ch устанавливается равнм числу с плавающей запятой После усечения ch получает значение равное коду P
    printf("Теперь ch = %c\n",ch);
    
    return 0;
}
   *//*
//list_5_15 pound.c определяет функцию с аргументом
#include<stdio.h>
void pound(int );
int main(void)
{
    int times = 4;
    char ch = '!';//ASCII код равен 33
    float f = 6.0f;
    pound(times); //аргумент типа int
    pound(ch);//эквивалентно pound((int)ch); принудительное использование нужного типа
    pound(f); //эквивалентно pound((int)f); принудительное использование нужного типа
    
    return 0;
}

void pound(int n)//заголовок функции в стиле ANSI которые указывает что функция принимает один аргумент int
{
    while(n-->0)
        printf("#");
    printf("\n");
}
*//*
//list_5_16 running.c демонтсрационная программа
#include<stdio.h>
const int S_PER_M = 60; //количество секунд в минуте
const int S_PER_H = 3600;//количество секунд в часе
const double M_PER_K = 0.62137;//количество миль в км

int main(void)
{
    double distk,distm;//дистанция пробега в километрах и милях
    double rate; //средняя скорость в милях час
    int min,sec;//время пробега в минутах и секундах
    int time;//время пробега только в секундах
    double mtime;//время пробега одной мили в секундах
    int mmin,msec;//время пробега одной мили в минутах и секундах
    
    printf("Эта программа преобразует время пробега дитсанции в метрической системе\n");
    printf("во время пробега одной мили и вычисляет вашу среднюю\n");
    printf("скорость в милях в час.\n");
    printf("Введите дистанцию пробега в километрах.\n");
    scanf("%lf",&distk);//%lf для типа double
    printf("Введите время в минутах и секундах.\n");
    printf("Начните с ввода минут.\n");
    scanf("%d",&min);
    printf("Теперь введите секунды.\n");
    scanf("%d",&sec);
    //переводит время в секунды
    time = S_PER_M*min+sec;
    //переводит километры в мили
    distm = M_PER_K*distk;
    //умножение миль в секунду на количество секунд в часе дает количество миль в час
    rate = distm/time * S_PER_H;
    //деление времени на расстояние дает время пробега одной мили
    mtime = (double) time/distm;
    mmin = (int) mtime/S_PER_M;//вычисление полного количества минут
    msec = (int) mtime % S_PER_M;//вычисление остатка в секундах
    printf("Вы пробежали %1.2f км (%1.2f мили) за %d мин, %d сек.\n",distk,distm,min,sec);
    printf("Такая скорость соответствует пробегу одной мили за %d минут, ",mmin);
    printf("%d сек.\nВаша скорость составила %1.2f миль в секунду.\n",msec,rate);

    return 0;
}
*//*
//selfcontol ex9
#include<stdio.h>
const int T=103;

int main(void)
{
    int n =96;
    while(n++<T)
    {
        printf("%c ",n);
    }
    printf("\n");
}
*//*
//ex1 преобразование времени в часы и минуты
#include<stdio.h>
#define MIN_IN_H 60

int main(void)
{
    int min; //время в минутах
    printf("Введите количество минут:\n");
    scanf("%d",&min);
    while (min>0)
    {
        printf("В указанном вами количество минут содержится %d часов и %d минут\n",(int)min/MIN_IN_H,min%MIN_IN_H);
        printf("Введите новое значение минут, для выхода введите 0:\n");
        scanf("%d",&min);
    }
    return 0;
}
   *//*
//ex2 вывод последовательности чисел
#include<stdio.h>
int main(void)
{
    int d;
    printf("Введите целое число:\n");
    scanf("%d",&d);
    int t = d+10;//определяем конечное число
    printf("Следующие 10 чисел: ");
    d=d-1;//занижаем количество  d для корректного задания целого числа
    while (d++<t)
        printf("%d ",d);
    printf("\n");
}
*//*
//ex3 преобразуем количество дней в количество недель
#include<stdio.h>
const int WEEK = 7;

int main(void)
{
    int days;
    printf("Введите количество дней:\n");
    scanf("%d",&days);
    while(days>0)
    {
        printf("%d дней составляет %d недель и %d дней.\n",days,(int)days/WEEK,days%WEEK);
        printf("Введите следующее число или введите 0 для выхода.\n");
        scanf("%d",&days);
    }
    
    
    return 0;
}
*//*
//ex4 перевод см в футы и дюймы
#include<stdio.h>
#define SM_IN_INCH 2.54
#define FOOT_IN_INCH 12

int main(void)
{
    float smHight,inchHight;//высота в см и дюмах
    int footHight;//высота в дюймах
    printf("Введите высоту в см:\n");
    scanf("%f",&smHight);
    while (smHight>0)
    {
        inchHight = smHight/SM_IN_INCH;
        footHight = inchHight/FOOT_IN_INCH;
        printf("%1.1f см = %d футов %1.1f дюймов\n",smHight,footHight,inchHight-footHight*FOOT_IN_INCH);
        printf("Введите высоту в сантиметрах (<=0 для выхода из программы):");
        scanf("%f",&smHight);
    }
    printf("Работа завершена.");
    return 0;
}
*//*
//ex5 вывод первых n чисел
#include<stdio.h>
int main(void)
{
    int count,sum;
    count=sum=0;
    int n;
    printf("Введите верхнее число для подсчета суммы:\n");
    scanf("%d",&n);
    while(count++ <n)
        sum=sum+count;
    printf("sum = %d\n",sum);
    
    return 0;
}
*//*
//ex6 программа вычисляет сумму квадратов
#include<stdio.h>
int main(void)
{
    int count,sum;
    count=sum=0;
    int n;
    printf("Введите верхнее число для подсчета суммы:\n");
    scanf("%d",&n);
    while(count++<n)
        sum=sum+count*count;
    printf("Sum = %d\n",sum);
}
*//*
//ex7 получение куба вещественного числа через функцию
#include<stdio.h>

void Coob(float);
int main(void)
{
    float f;
    printf("Введите вещественное число:\n");
    scanf("%f",&f);
    Coob(f);
    
}
void Coob(float f)
{
    printf("Результат возведения в куб %.2f = %1.2f\n",f,f*f*f);
}
*//*
//ex8 программа вычисляет результат деления по модулю
#include<stdio.h>
int main(void)
{
    int first,second;
    printf("Эта программа вычисляет результат деления по модулю.\n");
    printf("Введите целое число, которое будет служить вторым операндом:\n");
    scanf("%d",&second);
    printf("Теперь введите первый операнд:\n");
    scanf("%d",&first);
    while (first>0)
    {
        printf("%d %% %d равно %d\n",first,second,first % second);
        printf("Введите следующее число для первого операнда (<= 0 для выхода из программы):\n");
        scanf("%d",&first);
    }
    printf("Готово!\n");
    
    return 0;
    
}
*/
//ex9 перевод температуры из Фарингейта в Цельсий и Кельвин
#include<stdio.h>
const double FARINGATE_CONST = 32.0;
const double CELVIN_CONST = 273.16;

void Temperatures(double);
int main(void)
{
    double faringate;
    printf("Введите температуру в Фарингейтах:\n");
    while (scanf("%lf",&faringate))
    {
        Temperatures(faringate);
        printf("Введите новое значение температуры (q для выхода из программы):\n");
    }
    
    return 0;
}
void Temperatures(double f)
{
    double celcia = 5.9/9.0*(f-FARINGATE_CONST);
    printf("Температура по Цельсию = %f\n",celcia);
    printf("Температура по Кельвину = %f\n",celcia+CELVIN_CONST);
}
