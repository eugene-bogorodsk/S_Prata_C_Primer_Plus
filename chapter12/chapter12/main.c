//
//  main.c
//  chapter12
//
//  Created by пупсик on 16.03.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_12_1 hiding.c переменные в блоках
#include <stdio.h>

int main() {
    int x = 30; //исходная переменная x
    
    printf("x во внешнем блоке: %d по адресу %p\n",x,&x);
    {
        int x = 77; //новая переменная x, скрывающая первую x
        printf("x во внутреннем блоке: %d по адресу %p\n",x,&x);
    }
    printf("x во внешнем блоке: %d по адресу %p\n",x,&x);
    while (x++ < 33 ) // исходная переменная x
    {
        int x = 100;//новая переменная x, скрывающая первую x
        x++;
        printf("x в цикле while: %d по адресу %p\n",x,&x);
    }
    printf("x во внешнем блоке: %d по адресу %p\n",x,&x);
    
    return 0;
}
*//*
//list 12_2 forc99.c новые правила для блоков
#include<stdio.h>
int main(void)
{
    int n =0;
    
    printf("Первоначально  n = %d  по адресу %p\n",n,&n);
    for (int n=1;n < 3; n++)
        printf("     цикл 1: n = %d по адресу %p\n",n,&n);
    printf("   После цикла 1 n = %d по адресу %p\n",n,&n);
    for (int n = 1 ;n < 3; n++)
    {
        printf("  индекс цикла 2 n = %d по адресу %p\n",n,&n);
        int n = 6;
        printf("     цикл 2: n = %d по адресу %p\n",n,&n);
        n++;
    }
    printf("  После цикла 2 n = %d по адресу %p\n",n,&n);
    
    return 0;
}
*//*
//list 12_3 stat.c использование локальной статической переменной
#include<stdio.h>
void trystat(void);
int main(void)
{
    int count;
    for (count = 1;count <= 3; count++)
    {
        printf("Начинается итерация %d:\n",count);
        trystat();
    }
    return 0;
}
void trystat(void)
{
    int fade = 1;
    static int stay = 1;
    
    printf("fade = %d and stay = %d\n",fade++,stay++);
}
*//*
//list_12_4 global.c использование внешней переменной
#include<stdio.h>
int units = 0;//внешняя переменная
void critic(void);
int main(void)
{
    extern int units ;//необязательное повторение объявления
    
    printf("Сколько фунтов весит маленький боченок масла?\n");
    scanf("%d",&units);
    while (units != 56)
        critic();
    printf("Вы знали это!\n");
    
    return 0;
}
void critic(void)
{
    // необязательное повторения опущено
    printf("Вам не повезло. Попробуйте ещё раз.\n");
    scanf("%d",&units);
}
*//*
//list_12_5 parta.c разнообразные классы хранения
#include<stdio.h>
//#include "partb.c" //удивительно но второй файл подключать не надо
void report_count(void);
void accumulate(int k);
int count = 0; //область видимости в пределах файла, внешнее связывание

int main(void)
{
    int value; //автоматическая переменная
    register int i; //регистровая переменная
    
    printf("Введите положительное целое число (0 для завершения):");
    while (scanf("%d",&value) && value > 0)
    {
        ++count; //использование переменной с областью видимости в пределах файла
        for (i = value; i >= 0; i--)
            accumulate(i);
        printf("Введите положительное целое число (0 для завершения):");
    }
    report_count();
    
    return 0;
}
void report_count(void)
{
    printf("Цикл выполнения %d раз(а)\n",count);
}
*//*
//list_12_8 drive0.c
#include<stdio.h>
extern int rand0(void);
int main(void)
{
    int count;
    for (count = 0; count < 5; count++)
        printf("%d\n",rand0());
    
    return 0;
}
*//*
//list_12_10 тестирование ф-ций rand() и srand()
#include<stdio.h>
#include<time.h>
extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
    int count;

   */ /*
    printf("Введите начальное число.\n");
    while (scanf("%u",&seed))
    {
        srand1(seed); //переустановка начального числа
        for (count = 0; count < 5; count++)
            printf("%d\n",rand1());
        printf("Введите следующее начальное число (q для выхода).\n");
    }
    
    printf("Программа завершена.\n");
    */
  /*  //использование time() для установки начального значения rand()
    srand1((unsigned int) time(0));
      for (count = 0; count < 5; count++)
          printf("%d\n",rand1());
    
    return 0;
}

*//*
//list_12_13 эмуляция игры в кости бросание множества костей
#include<stdio.h>
#include<stdlib.h> //для библиотечной ф-ции srand()
#include<time.h> //для ф-ции time()
#include "diceroll.h" //для ф-ции roll_n_dice() и для переменной  roll_count

int main(void)
{
    int dice,roll;
    int sides,status;
    
    srand((unsigned int) time(0)); //рандомизация случайного числа
    printf("Введите количество граней кости или 0 для завершения программ.\n");
    while (scanf("%d",&sides)==1 && sides > 0)
    {
        printf("Сколько костей?\n");
        if ((status = scanf("%d", &dice)) != 1)
        {
            if (status == EOF)
                break; //выход из цикла
            else
            {
                printf("Вы должны ввести целое число.");
                printf("Давайте начнем с начала.\n");
                while (getchar() !='\n')
                    ; //отбросить некорректный ввод
                printf("Сколько граней? Для перкращения ввдите 0.\n");
                continue; //новая итерация цикла
            }
        }
        roll = roll_n_dice(dice, sides);
        printf("Вы бросали %d раз(а), используя %d кости с %d гранями.\n", roll,dice,sides);
        printf("Сколько граней? Для прекращения введите 0.\n");
    }
    printf("Функция rollen() была вызвана %d раз(а).\n",roll_count); //используется переменная extern
    printf("Пусть удача не покидает вас!\n");
    
    return 0;
}
   *//*
//list_12_14
#include<stdio.h>
#include<stdlib.h> //для malloc() и free()

int main(void)
{
    double *ptd;
    int max = 0;
    int number;
    int i = 0;
    
    puts("Введите максимальное количество жлементов типа double.");
    if (scanf("%d",&max) != 1)
    {
        puts("Колличество введено некорректно -- программа завершена.");
        exit(EXIT_FAILURE);
    }
    ptd = (double *) malloc (max*sizeof(double));
    if (ptd == NULL)
    {
        puts("Не удалось выделить память. Программа завершена.");
        exit(EXIT_FAILURE);
    }
    // ptd теперь указывает на массив из max элементов
    puts("Введите значения (q для выхода):");
    while (i < max && scanf("%lf",&ptd[i]) ==1)
        ++i;
    printf("Введено %d элементов :\n", number =i);
    for (i = 0;i < number; i++)
    {
        printf("%7.2f",ptd[i]);
        if (i%7 == 6)
            putchar('\n');
    }
    if (i%7 != 0)
        putchar ('\n');
    puts("Программа завершена.");
    free(ptd);
    
    return 0;
}
      *//*
//list_12_15
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int static_store = 30;
const char *pcg = "Строковый литерал";
int main()
{
    int auto_store = 40;
    char auto_string[] = "Автоматический массив char";
    int *pi;
    char *pcl;
    
    pi = (int *) malloc(sizeof(int));
    *pi = 35;
    pcl = (char *) malloc(strlen("Динамическая строка")+1);
    strcpy(pcl,"Динамическая строка");
    
    printf("           static_store: %d по адресу %p\n",static_store,&static_store);
    printf("             auto_store: %d по адресу %p\n",auto_store,&auto_store);
    printf("                    *pi: %d по адрусу %p\n", *pi,pi);
    printf("             %s по адресу %p\n",pcg,pcg);
    printf("%s по адресу %p\n",auto_string,auto_string);
    printf("       %s по адресу %p\n",pcl,pcl);
    printf("         %s по адресу %p\n","Строка в кавычках","Строка в кавычках");
    free(pi);
    free(pcl);
    
    return 0;
}
*/
/*
//ex1 модификация 12_4
#include<stdio.h>
int critic(void);
int main(void)
{
    int units ;//необязательное повторение объявления
    
    printf("Сколько фунтов вести маленький боченок масла?\n");
    scanf("%d",&units);
    while (units != 56)
        units = critic();
    printf("Вы знали это!\n");
    
    return 0;
}
int critic(void)
{
    int units;
    // необязательное повторения опущено
    printf("Вам не повезло. Попробуйте ещё раз.\n");
    scanf("%d",&units);
    return units;
}
*//*
//ex2
//pe12-2b.c
#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int mode;
    printf("Введите 0 для метрического  режима или 1 для американского режима:");
    scanf("%d",&mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Введите 0 для метрического режима или 1 для американского режима");
        printf(" (-1 для завершения: ");
        scanf("%d",&mode);

    }
    
    printf("Программа завершена.\n");
    return 0;
}
*//*
//ex3 переделываем на автоматические переменные
#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
    int _mode;
    printf("Введите 0 для метрического  режима или 1 для американского режима:");
    scanf("%d",&_mode);
    while (_mode >= 0)
    {
        int mode = set_mode(_mode);
        float distance,expend;
        
        distance =get_Distance(mode);
        expend = get_Expend(mode);
        show_info(distance,expend,mode);
        printf("Введите 0 для метрического режима или 1 для американского режима");
        printf(" (-1 для завершения: ");
        scanf("%d",&_mode);

    }
    
    printf("Программа завершена.\n");
    return 0;
}
*//*
//ex4 функция возварщае количество вызовов
#include<stdio.h>
int numOfCalling(void);

int main(void)
{
    int j = 0;
    
    while (j < 5)
    {
        int k = numOfCalling();
       
        printf("Это %d(й) вызов функции.\n",k);
        j++;
    }

}
int numOfCalling(void)
{
    static int i=0;
    printf("Меня вызвали ");
    return ++i;
}
*/
/*
//ex5 массив случайных чисел сортирока по возрастанию
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 100

int main(void)
{
    const int diapazon = 10;
    int ar[N];
    for (int i=0;i<N;i++)
        ar[i]=rand() % diapazon +1;
    for (int i =0;i<N;i++)
        printf("%d ",ar[i]);
    printf("\n");
    bool not_sorted = true;
    while (not_sorted)
    {
        not_sorted = false;
        for (int i = 0;i<N-1;i++)
            if (ar[i]<ar[i+1])
            {
                int t =ar[i]; ar[i]=ar[i+1];ar[i+1]=t;
                not_sorted=true;
            }
    }
    for (int i =0;i<N;i++)
              printf("%d ",ar[i]);
    printf("\n");
    return 0;
}
 *//*
//ex6 выводим количество полученных рэндомных чисел
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000
#define D 10
int main(void)
{
    srand((unsigned int) time(0)); //рандомизация начального числа
    int ar[N];
    int count[D];
    for (int i = 0 ;i < N; i++)
        ar[i]= rand()%D +1;
    for (int i =0;i<N;i++)
        count[ar[i]-1]++;
    for (int i =0;i<D;i++)
        printf("%d - %d ",i+1,count[i]);
    
    return 0;
}
    *//*
//ex7 модификация 12_13
#include<stdio.h>
#include<stdlib.h> //для библиотечной ф-ции srand()
#include<time.h> //для ф-ции time()
#include "diceroll.h" //для ф-ции roll_n_dice() и для переменной  roll_count

int main(void)
{
    int dice;//количество костей
    int roll;//количество
    int sides;//количество граней

    int countOfDice;//количество бросаний кубика
    
    srand((unsigned int) time(0)); //рандомизация случайного числа
    printf("Введите количество бросаний или q для завершения:");
    while (scanf("%d",&countOfDice) && countOfDice>0)
    {
        printf("Введите количество граней и сколько костей.\n");
        while (scanf("%d %d",&sides,&dice)!=2 && sides <= 0)
        {
            
            printf("Что то пошло не так.");
            printf("Давайте начнем с начала.\n");
            while (getchar() !='\n')
                    ; //отбросить некорректный ввод
    
        }
        printf("Имеем %d бросаний %d костей c %d гранями\n",countOfDice,dice,sides);
        for (int i = 0;i < countOfDice;i++)
        {
            roll = roll_n_dice(dice, sides);
            printf("%d ",roll);
        }
        printf("\n");
        printf("Введите количество бросаний или q для завершения:");
    }
    printf("Функция rollen() была вызвана %d раз(а).\n",roll_count); //используется переменная extern
    printf("Пусть удача не покидает вас!\n");
    
    return 0;
}
*//*
#include<stdio.h>
#include<stdlib.h>
int *make_array(int elem,int val);
void show_array(const int ar[],int n);
int main(void)
{
    int *pa;
    int size;
    int value;
    
    printf("Введите количество элементов:");
    while (scanf("%d",&size) && size>0)
    {
        printf("Введите значение для инициализации:");
        scanf("%d",&value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa,size);
            free(pa);
        }
        printf("Введите количество элементоа (<1 для завершения):");
    }
    
    printf("Программа завершена.\n");
    return 0;
}

int *make_array(int elem,int val)
{
    int *ptd = (int *) malloc(elem*sizeof(int));
    int i=0;
    while (i<elem)
    {
        ptd[i++] =val;

    }
    return ptd;
}
void show_array(const int ar[],int n)
{
    for (int i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");
}
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LIMIT 30
int num_words(void);//запрашивает количество слов которые нужно ввести
char ** set_words(int );//вводим слова
void show_words(char** ,int n);//выводим слова
int main(void)
{
    int numWords= num_words();
    char **arOfWords = set_words(numWords);
    show_words(arOfWords,numWords);
    
    return 0;
}
int num_words(void)//запрашивает количество слов которые нужно ввести
{
    int numberOfWords;
    printf("Сколько слов Вы хотите ввести?");
    while (scanf("%d",&numberOfWords) !=1  && numberOfWords<=0)
    {
        printf("Что то пошло не так попробуйте еще раз");
        while(getchar() !='\n')
            ;
    }
    
    return numberOfWords;
}
char ** set_words(int num)//вводим слова
{
    printf("Теперь вводите %d слов:\n",num);
    char **words=(char**)malloc(num*sizeof(char*));
    for (int i = 0;i<num;i++)
    {
        char temp[LIMIT];
        scanf("%s",temp);
        int sizeOfWord = (int)strlen(temp)+1;
        words[i] = (char*) malloc(sizeOfWord*sizeof(char));
        strcpy(words[i],temp);
    
    }
    return words;
    
}
void show_words(char** words,int n)//выводим слова
{
    printf("Это был гемморой\n");
    printf("Вот введенные слова\n");
    for (int i = 0;i<n;i++)
        puts(words[i]);
    
}
