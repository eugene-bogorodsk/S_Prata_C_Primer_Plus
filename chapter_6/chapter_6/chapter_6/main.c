//
//  main.c
//  chapter_6
//
//  Created by пупсик on 17.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_6_cmpfit.c срванение чисел с плавающей запятой
#include <stdio.h>
#include <math.h>

int main(void) {
    const double ANSWER = 3.14159;
    double response;
    
    printf("Каково значение числа пи?\n");
    scanf("%lf",& response);
    while(fabs(response - ANSWER)>0.0001)
    {
        printf("Введите значение ещё раз.\n");
        scanf("%lf",&response);
    }
    printf("Достаточно близко!\n");
    return 0;
}
*//*
//list_6_6 t_and_f.c истинные и ложные значения в языке С
#include<stdio.h>
int main(void)
{
    int true_val,false_val;
    
    true_val = (10>2);//значение истинного отношения
    false_val = (10==2);//значение ложного отношения
    printf("true = %d; false = %d \n", true_val,false_val);
    
    return 0;
}
*//*

//list_6_7  truth.c какие значения являются истинными
#include<stdio.h>
int main(void)
{
    int n = 3;
    while(n)
        printf("%2d является истинным\n",n--);
    printf("%2d является ложным\n",n);
    n = -3;
    while(n)
        printf("%2d являются истинным\n",n++);
    printf("%2d является ложным\n",n);
}
   *//*
//list_6_8 trouble.c приводит к возникновению бесконечного цикла
#include<stdio.h>
int main(void)
{
    long num;
    long sum = 0L;
    int status;
    printf("Введите целое число для последующего суммирования ");
    printf("(или q для завершения программы):");
    status = scanf("%ld",&num);
    while (status =1) //выражение status = 1 приводит к зацикливанию программы  так применятся оператор присваивания устанавливающий переменную status в 1 , выдается предупреждение компилятора
    {
        sum+=num;
        printf("Введите следующее число (или q для завершения программы):");
        status = scanf("%ld",&num);
    }
    printf("Сумма введенных целых чисел равна %ld.\n",sum);
    
    return 0;
}
*//*
//list_6_13 postage.c применение операции запятой
#include<stdio.h>//тарифы обслуживаиня первого класса
int main(void)
{
    const int FIRST_OZ = 46;// тариф за первую унцию
    const int NEXT_OZ = 20;//тариф за каждую последующую унцию
    int ounces,cost;
    
    printf(" унция  тариф\n");
    for (ounces = 1,cost = FIRST_OZ;ounces <= 16; ounces++,cost += NEXT_OZ)
        printf("%5d $%4.2f\n",ounces,cost/100.0);
    
    return 0;
}
*//*
//list_6_14 сумма последовательности
#include<stdio.h>
int main(void)
{
    int t_ct; //счетчик элементов
    double time,power_of_2;
    int limit;
    
    printf("Введите желаемое количество элементов последовательности: ");
    scanf("%d", &limit);
    for (time = 0,power_of_2 =1,t_ct=1; t_ct <= limit; t_ct++,power_of_2 *= 2.0)
    {
        time +=1.0/power_of_2;
        printf("время = %f, когда количество элементов = %d.\n", time,t_ct);
    }
    return 0;
}
   *//*
//list_6_15 do_while.c  цикл с постусловием
#include<stdio.h>
int main(void)
{
    const int secret_code = 13;
    int code_entered;
    
    do
    {
        printf("Чтобы войти в клуб лечения трскадекафобии,\n");
        printf(" пожалуйста, введите секретный код: ");
        scanf("%d",&code_entered);
    } while (code_entered != secret_code);
    
    printf("Поздравляем! Вас вылечили!\n");
    
    return 0;
}
*//*
//list_6_17 rows1.c применение вложенных циклов
#include<stdio.h>
#define ROWS 6
#define CHARS 10

int main(void)
{
    int row;
    char ch;
    
    for (row = 0;row < ROWS;row++)
    {
        for (ch = 'A';ch <('A'+CHARS); ch++)
            printf("%c",ch);
        printf("\n");
    }
}
   *//*
//list_6_18 rows2.c применение зависимых вложенных циклов
#include<stdio.h>
int main(void)
{
    const int  ROWS = 6;
    const int CHARS =6;
    int row;
    char ch;
    
    for (row = 0;row < ROWS;row++)
    {
        for (ch = ('A'+ row); ch < ('A'+CHARS);ch++)
            printf("%c",ch);
        printf("\n");
    }
    return 0;
}
*//*
//list_6_19 acores_in.c использование цикла for c массивами
#include<stdio.h>
#define SIZE 10
#define PAR 72
int main(void)
{
    int index,score[SIZE];
    int sum = 0;
    float average;
    
    printf("Введите %d результатов игры в гольф:\n",SIZE);
    for(index = 0;index < SIZE;index++)
        scanf("%d",&score[index]); //чтение 10 результатов игры в гольф
    printf("Введены следующие результаты:\n");
    for (index = 0;index < SIZE;index++)
        printf("%5d",score[index]); //проверка введенной информации
    printf("\n");
    for (index = 0;index <SIZE;index++)
        sum+=score[index]; //сложение результатов
    average = (float) sum/SIZE;
    printf("Сумма результатов = %d, среднее значение = %.2f\n",sum,average);
    printf("Полученный гандикап = %.0f.\n",average-PAR);
    
    return 0;
}
   *//*
//list_6_20
#include<stdio.h>
double power(double,int);

int main(void)
{
    double x,xpow;
    int exp;
    
    printf("Введите число и положительную целую степень,");
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
    int i;
    for (i=1;i<=p;i++)
        pow*=n;
    return pow;
}
*//*
//myself_14
#include<stdio.h>
int main(void)
{
    int k;
    for (k=1,printf("%d: Hi!\n",k); printf("k=%d\n",k), k*k<26; k+=2,printf("Now k is %d\n",k))
        printf("k is %d in the loop\n",k);
    return 0;
}
*//*
//ex1 программа выводит английский алфавит
#include<stdio.h>
int main(void)
{
    char ch;
    char alphabet[26];
    int i;
    
    for (ch = 'A',i=0;ch < 'A'+26;ch++,i++)
        alphabet[i]=ch;
    for (i=0;i<26;i++)
        printf("%c",alphabet[i]);
    printf("\n");
}
*//*
//ex2 вывод горки долларов
#include<stdio.h>
const int  ROW = 5;
int main(void)
{
    int i,j;
    for (i=0; i<ROW;i++)
    {
        for (j=0;j<i+1;j++)
            printf("%c",'$');
        printf("\n");
    }
    return 0;
}
   *//*
//ex3 вывод горки букв в обратную сторону
#include<stdio.h>
const int ROW = 6;
int main(void)
{
    char ch;
    int i,j;
    for (i=0;i<ROW;i++)
    {
        for (j=0,ch='F';j<i+1;j++,ch--)
            printf("%c",ch);
        printf("\n");
            
    }
    return 0;
}
      *//*
//ex4 вывод алфавита со смещением
#include<stdio.h>
const int ROW = 6;
int main(void)
{
    int i,j,k=0; char ch;
    for(i=0;i<ROW;i++)
    {
        int c=0;//счетчик количества букв введенных в ряду
        for (j=0,ch='A'+k;j<i+1;j++,ch++)
        {
            printf("%c",ch);
            c+=1;
        }
        printf("\n");
        k+=c;//смещение от буквы А равное количеству ранее введённых букв
        
    }
    return 0;
}
         *//*
//ex5  вывод буквенной пирмамиды
#include<stdio.h>
int main(void)
{
    char ch_enter;
    printf("Ведите букву :");
    scanf("%c",&ch_enter);
    printf("Ваша пирамидка:\n");
    int row;//вводим переменную которая равна разности между кодом введенной буквы и кодом буквы А, которая определяет количество рядов для построения
    row=(int)ch_enter - (int)'A';
    
    int i; //переменная-счетчик выводимых рядов
    for (i=0;i <= row;i++)
    {
        int j;//переменная-счетчик количества пробелов для заполнения
        for (j=row-i;j>0;j--)
            printf("%c",' ');
        int k;//переменная счетчик количества букв в ряду
        char ch;//переменная для манипулирования буквами и вывода их в прямом направлении
        for (k=0,ch='A';k<i+1;k++,ch++)
            printf("%c",ch);
        //выводим буквы в обратном направлении используя как начальные - значения из предыдущего цикла
        ch-=2;k--;// порядок выполнения цикла  for сначала в теле цикла выполняем начальные установки (левые операции), затем обновляем данные (правые операции) далее производим проверку получившихся данных, если условия == 1 то выполняем операции в теле цикла
        for (;k>0;k--,ch--)
            printf("%c",ch);
        printf("\n");
    }
    return 0;
}
*//*
//ex6 вывод таблицы квадратов и кубов
#include<stdio.h>
int main(void)
{
    printf("Введите верхний и нижний пределы таблицы:");
    long up,down;
    scanf("%ld %ld",&up,&down);
    printf("число   квадрат   куб\n");
    for (;down<=up;down++)
    {
        printf("%3ld %9ld %7ld",down,down*down,down*down*down);
        printf("\n");
    }
    return 0;
}
*//*
//ex7  выводим слова в обратном порядке
//приеняемые для обработки маасивов char функции для кириллицы не подходят по причине другого размера символов
#include<stdio.h>
#include<locale.h>//подключаем библиотеку для установки кодировки utf-8
#include<string.h>
#include<wchar.h>//подключаем библиотеку для обработки симовлов типа wchar_t
int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");//устанавливаем кодировку utf-8 используем при применении кириллицы
    wchar_t word[40];// создаем массив wchar_t, в случае инициализации строкой перед кавычками пишем L ,например  L"хрен";
    //char word[40]; для использования латинских букв
    printf("Вводим слово:");
    scanf("%ls",word);// применяем спецификатор ls при считывания в массив wchar_t
    //scanf("%s",word); при использовании латинских букв
    printf("Ха-ха-ха!\n");
    int i;//при использовании типа size_t программа зацикливается как на русских так и на английских словах
    for (i=(int)wcslen(word);i>=0;i--)//используем функцию wcslen() для определения длины строки в кодировке wchar_t
       // for (i=(int)strlen(word);i>=0;i--) функция strlen для латинских букв - кодировка ASCII
        printf("%lc",word[i]);//используем спецификатор lc для вывода символов в кодировке wchar_t
        //printf("%c",word[i]); спецификатор с для вывода в кодировке ASCII
    printf("\n");
    
    return 0;
}
*//*
//ex8 операции с типом float
#include<stdio.h>
int main(void)
{
    printf("Введите два вещественных числа:");
    float a,b;
    while(scanf("%f %f",&a,&b)==2)
    {
        printf("Результат: %f\n",(b-a)/(a*b));
        printf("Введите следующую пару (или q для выхода)\n");
    }
    
    
    return 0;
}
   *//*
//ex9 модификация ex8 с функцией
#include<stdio.h>
double foo(float,float);
int main(void)
{
    printf("Введите два вещественных числа:");
    float a,b;
    while(scanf("%f %f",&a,&b))
    {
        printf("Результат:%f\n",foo(a,b));
        printf("Введите следующую пару (или q для выхода)\n");
    }
    return 0;
}
double foo(float a,float b)
{
    return (b-a)/(b*a);
}*//*
//ex10 вывод суммы квадратов
#include<stdio.h>
int main(void)
{
    printf("Введите два числа в диапазоне которых будет вычисляться сумма квадратов:");
    int a,b;
    scanf("%d %d",&a,&b);
    while(b>a)
    {
        long sum = 0L;
        int i;
        for (i=a;i<=b;i++)
            sum+=i*i;
        printf("Cумма квадратов целых числе от %d до %d равна %ld\n",a*a,b*b,sum);
        printf("Введите следующую комбинацию пределов:");
        scanf("%d %d",&a,&b);
    }
    printf("Работа завершена\n");
    return 0;
}
*//*
//ex10 заполняем массив
#include<stdio.h>
int main(void)
{
    int ar[8];
    int i;
    printf("Заполняем массив 8-ю значениями:\n");
    for (i=0;i<8;i++)
    {
        printf("%d-й элемент:",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Ваш массив в обратном порядке:\n");
    for (i=7;i>=0;i--)
        printf("%d ",ar[i]);
    printf("\n");
    
}
*//*
//ex12 вычисление сумм бесконечных последовательностей
#include<stdio.h>
#include<math.h>
int main(void)
{
    printf("Введите максимальное число для вычисления ряда:");
    unsigned long mx;

    while(scanf("%lu",&mx))
    {
        unsigned int i,k=1;
        long double sum1,sum2;
        sum1=sum2=0.0;
        printf("Результаты по ряду 1+1/2 +1/3 +1/4 ...\n");
        for (i=1;i<=mx;i++)
        {
            sum1+=1.0/i;
            if (i%(k*100)==0)
            {
                printf("%d - %Lf\n",i,sum1);
                k*=10;
            }
        }
        printf("Total: %lu - %Lf\n",mx,sum1);
        printf("\n");
        printf("Результаты по ряду 1-1/2 +1/3 -1/4 ...\n");
        k=1;
        for (i=1;i<=mx;i++)
        {
            sum2+=pow(-1,i+1)*1/i;
            if (i%(k*100)==0)
            {
                printf("%d - %Lf\n",i,sum2);
                k*=10;
            }
        }
        printf("Total: %lu - %Lf\n",mx,sum2);
        
        printf("Введите новое число (или q для выхода):");
    }
    return 0;
}
*//*
//ex13 заполняем массив степенями двойки
#include<stdio.h>
#include<math.h>
int main(void)
{
    int ar[8];
    int i=0;
    for (;i<=8;i++)
        ar[i]=(int)pow(2,i);
    i=0;
    do
    {
        printf("%d ",ar[i]);
        i++;
    }while(i<8);
    printf("\n");
    return 0;
}
*//*
//ex14 забавляемся с двумя массивами double
#include<stdio.h>
int main(void)
{
    double ar1[8],ar2[8];
    int i=0;
    printf("Заполняем первый массив:\n");
    for(;i<8;i++)
    {
        printf("%d-й элемент:",i+1);
        scanf("%lg",&ar1[i]);
    }
    
    ar2[0]=ar1[0];
    i=1;
    for(;i<8;i++)
        ar2[i]=ar1[i]+ar2[i-1];
    
    for(i=0;i<8;i++)
        printf("%10.2f",ar1[i] );
    printf("\n");
    
    for(i=0;i<8;i++)
        printf("%10.2f",ar2[i]);
    printf("\n");
    return 0;
    
}
   *//*
//ex15
#include<stdio.h>
int main(void)
{
    char str[256];
    printf("Вводим строку :\n");
    int i=0;
    scanf("%c",&str[i]);
    while(str[i] != '\n')
    {
        i++;
        scanf("%c",&str[i]);
    }
    int k = i-1;
    for (;k>=0;k--)
        printf("%c",str[k]);
    printf("\n");

    return 0;
}
*//*
//ex15 с кириллицей работает только после двух нажатий  ENTER не понятно почему
#include<stdio.h>
#include<locale.h>
int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");
    wchar_t str[256];
    printf("Вводим строку:\n");
    int i=0;
    scanf("%lc",&str[i]);
    while (str[i] != '\n')
    {
        i++;
        scanf("%lc",&str[i]);
    }

    i--;
    for(;0<=i;i--)
        printf("%lc",str[i]);
    printf("\n");
    return 0;
}
*//*
//ex16 задача по вкладам
#include<stdio.h>
#define INITIAL 100
int main(void)
{
    float Dafna = 100;
    int i = 0;
    while(Dafna<2*INITIAL+0.0001)
    {
        Dafna+=INITIAL*0.1;
        i++;
    }
    printf("%d %.2f\n",i,Dafna);
    float Dreidra = 100;
    i=0;
    while(Dreidra<2*INITIAL+0.0001)
    {
        Dreidra+=Dreidra*0.05;
        i++;
    }
    printf("%d %.2f\n",i,Dreidra);
    return 0;
}
   *//*
//ex17 ещё задача на банковские проценты
#include<stdio.h>
#define WIN  1000000.0
#define WEED 100000.0
int main(void)
{
    int years = 0;
    float currentSum = WIN;
    while (currentSum>0.00001)
    {
        currentSum = currentSum*1.08 - WEED;
        years++;
    }
    printf("%d %f\n",years,currentSum);
    return 0;
}
      */

//ex17 задача на социальную сеть
#include <stdio.h>
#define DANBAR 150
#define INITIAL 5

int main(void)
{
    int current = 5;
    int week =0;
    while (current < DANBAR)
    {
        current= (current-(week+1))*2;
        week++;
        printf("%d %d\n",week,current);
    }
    return 0;
}
