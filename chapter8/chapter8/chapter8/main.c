//
//  main.c
//  chapter8
//
//  Created by пупсик on 24.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_8_2 эхо вывод
#include <stdio.h>

int main(void) {
    int ch;
    while ((ch=getchar()) != EOF)
        putchar(ch);
    //на imac конец файла = Ctr-D
    return 0;
}

// Запуск файла из тарминала
 //1. Перейти в папку с исходным файлом > правая клавиша >show in finder > правая клавиша >alt скопировать путь > cd <путь>
// 2. Скомпилировать файл cland main.c - o <program>
 //3. Запустить командой ./program
 // Если программа на С++ можно использовать одну из следующих команд
 clang++ -o program program.cpp
 g++ -std=c++11 -o program program.cpp
 g++-7 -std=c++11 -o program program.cpp
 
 *//*
//list_8_3 программа открывает файл и отображает его содержимое через xcode
//для запуска этой программы заходим в раздел Xcode Product>Scheme>Edit Scheme>Run>Options
//устанавливаем флажок Use custom working directory
//файл для чтения размещаем в папке Products/Debug для чего наводим курсор на исполняемый файл chapter8 правая клавиша Show in Finder
#include<stdio.h>
#include<stdlib.h> //для функции exit()
int main()
{
    int ch;
    FILE *fp;
    char fname[50]; // для хранения имени файла
    
    printf("Введите имя файла :");
    scanf("%s",fname);
    fp = fopen(fname,"r"); //открыть файл для чтения
    if (fp == NULL) //попытка завершилась неудачей
    {
        printf("Не удаётся открыть файл. Программа завершена.\n");
        exit(1); //выйти из программы
    }
    //функция getc(fp) получает символ из открытого файла
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp); //закрыть файл
    
    return 0;
}
    *//*
//list_8_4 проблемная программ угадывания числа с необходимыми исправлениями
#include<stdio.h>
int main(void)
{
    int guess = 1;
    printf("Выберите целое число  в интервале шт 1 до 100. Я попробую угадать его.\nНажмите клавишу y,если моя догадка верна и \n клавишу n в противном случае.\n");
    printf("Вашим числом является %d?",guess);
   // while(getchar() != 'y') //получить ответ сравнить с y
     //   printf("Ладно, тогда это %d?\n",++guess);
    // после ввода n программа делает два предположения -  сначала читает ответ n как отрицание того  что было загадоно число 1 и затем счтиватает символ новой строки как отрицание тго что было загадано число 2
    // для решения используем цикл while для отбрасывания остатка введенной строки включая символ новой строки  и используем if для фильтрации других ответов
    char response;
    while ((response = getchar()) != 'y') //получить ответ
    {
        if (response == 'n')
            printf("Ладно, тогда ээто %d?\n",++guess);
        else
            printf("Принимаются только варинаты y или n.\n");
        while (getchar() != 'n')
                   continue;// пропускаем часть оставшейся строки можно continue не использовать
    }
    printf("Я знал что у меня получится!\n");
    return 0;
}
*//*
//lidst_8_5 showchar1.c проблемы со смешанным вводом

#include<stdio.h>
void display(char,int,int);
int main(void)
{
    int ch;// выводимый символ читает его как int  чтобы сделать возможным проверку на EOF который =-1 однако в функцию   display передается как char
    int rows, cols; //количество строк и столбцов
    printf("Введите символ и два целых числа:\n");
    while ((ch = getchar()) != '\n')
    {
        //scanf("%d %d",&rows,&cols);//ф-ция scanf оставляет символ \n во входной очереди, который потом считывается getchar что означает конец цикла
        //добавляем проверку на ввод двух чисел
        if (scanf("%d %d",&rows,&cols) != 2)
            break;
        display(ch,rows,cols);
        //для решения проблемы добавляем строку, считывающую все знаки включая символ \n
        while( getchar() != '\n');
        printf("Введите ещё один символ и два целых числа;\n");
        printf("для завершения введите символ новой строки.\n");
    }
    printf("Программа завершена.\n");
    return 0;
}
void display(char cr,int lines,int width)
{
    int row,col;
    for (row = 1; row <= lines; row++)
    {
        for (col = 1;col <= width; col++)
            putchar(cr);
        putchar('\n'); //закончить строку и начать новую
    }
}
*//*
//list_8_7 checking.c проверка допустимости ввода
#include<stdio.h>
#include<stdbool.h>
long get_long(void); //проверка является ли ввод целочисленным
bool bad_limits(long begin, long end, long low,long high); //проверка допустимы ли границы диапазона
//вычисление суммы квадратов целых чисел от a до b
double sum_squares(long,long);
int main(void)
{
    const long MIN = -10000000L;//нижний предел диапазона
    const long MAX = +10000000L;//верхний предел диапазона
    long start; //начало диапзона
    long stop; //конец диапазона
    double answer;
    printf(" Это программа вычисляет сумму квадратов целых чисел в заданном диапазоне.\n Нижняя граница не должна быть меньше %ld,\nа верхняя не должна быть больше %ld.\nвведите значения пределов (для завершения введите 0 для обоих пределов):\nнижний предел: ",MIN,MAX);
    start = get_long();
    printf("верхний предел: ");
    stop = get_long();
    while (start !=0 || stop !=0)
    {
        if (bad_limits(start,stop,MIN,MAX))
            printf("Повторите попытку.\n");
        else
        {
            answer = sum_squares(start,stop);
            printf("Сумма квадратов целых чисел от %ld до %ld равна %g\n",start,stop,answer);
        }
        printf ("Введите значения пределов (для завершения введите 0 для обоих пределов):\nнижний предел: ");
        start = get_long();
        printf("верхний предел: ");
        stop = get_long();
    }
    printf("Программа завершена.\n");
    return 0;
}
long get_long(void)
{
    long input;
    char ch;
    while(scanf("%ld",&input) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch); //отбросить неправильный ввод
        printf(" не является целочисленным.\nВведите целое число, такое как 25, -178 или 3: ");
    }
    return input;
}
double sum_squares(long a,long b)
{
    double total = 0;
    long i;
    for (i=a; i<=b;i++)
        total +=(double)i*(double)i;
    return total;
}
bool bad_limits(long begin,long end,long low,long high)
{
    bool not_good = false;
    if (begin > end)
    {
        printf("%ld не меньше чем %ld.\n",begin,end);
        not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("Значения должны быть равны %ld или больше.\n",low);
        not_good = true;
    }
    if (begin > high || end > high)
    {
        printf("Значения долны быть равны %ld или меньше.\n",high);
    }
    return not_good;
}
*//*
//list_8_8 menuitte.c пример обработки меню
#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void)
{
    int choice;
   //void count(void);
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a':
                printf("Покупайте дёшево, продовайте дорого.\n");
                break;
            case 'b':
                putchar('\007');//ANSI звуковой сигнал не работает)))
                break;
            case 'c':
                count();
                break;
                default:
                printf("Ошибка!\n");
                break;
        }
    }
    printf("Программа завершена.\n");
    return 0;
}
void count(void)
{
    int n,i;
    printf("До какого предела вести подсчёт? Введите целое число:\n");
    n=get_int();
    for (i=1;i <= n;i++)
        printf("%d\n",i);
    while(getchar() != '\n')
        continue;
}
char get_choice(void)
{
    int ch;
    printf("Введите букву, соответствующую выбранному варианту:\n");
    printf("a.совет      b.звонок      c.подсчёт    q.выход\n");
    ch=get_first();
    while(ch != 'a' && ch != 'b' && ch != 'c' && ch != 'q')
    {
        printf("Выберите a,b,c или q.\n");
        ch= get_first();
    }
    return ch;
}// забыл определить эту функцию программа не запускается компилятор об ошибке не сообщает пришлось запускать в eclipse там выявил
char get_first(void)
{
    int ch;
    ch = getchar();
    while(getchar() != '\n');
    return ch;
}
int get_int(void)
{
    int input;
    char ch;
    while (scanf("%d",&input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch); //отбросить неправильный ввод
        printf(" не являются целочисленными.\nВведите целое число, такое как 25, -178 или 3: ");
    }
    return input;
}
*//*
//ex1 считаем количество символов в входе до EOF
#include <stdio.h>
int main(void)
{
    printf("Вводим строки по окончанию нажимаем Ctrl-D\n");
    long count = 0;
    while (getchar() != EOF)
        count++;
    printf("В вашем тексте %ld символов, включая \\n и проблы \n",count);
    return 0;
}
*//*
//ex2 выводим символы и код символа
#include<stdio.h>
#include<string.h>
int main(void)
{
    printf("Начинаем ввод, для окончания нажмите Ctrl-D:\n");
    int ch;
    char symbol[10];
    int count = 0;
    
    while ((ch =getchar()) !=EOF)
    {
        count++;
        switch (ch) {
            case 0:
                strcpy(symbol,"Ctrl-2");
                break;
            case 1:
                strcpy(symbol,"Ctrl-A");
                break;
            case 2:
                strcpy(symbol,"Ctrl-B");
                break;
            case 3:
                strcpy(symbol,"Ctrl-C");
                break;
            case 4:
                strcpy(symbol,"Ctrl-D");
                break;
            case 5:
                strcpy(symbol,"Ctrl-E");
                break;
            case 6:
                strcpy(symbol,"Ctrl-F");
                break;
            case 7:
                strcpy(symbol,"Ctrl-G");
                break;
            case 8:
                strcpy(symbol,"b");
                break;
            case 9:
                strcpy(symbol,"\\t");
                break;
            case 10:
                strcpy(symbol,"\\n");
                break;
            case 11:
                strcpy(symbol,"\v");
                break;
            case 12:
                strcpy(symbol,"\f");
                break;
            case 13:
                strcpy(symbol,"\f");
                break;
            case 14:
                strcpy(symbol,"Ctrl-N");
                break;
            case 15:
                strcpy(symbol,"Ctrl-O");
                break;
            case 16:
                strcpy(symbol,"Ctrl-P");
                break;
            case 17:
                strcpy(symbol,"Ctrl-Q");
                break;
            case 18:
                strcpy(symbol,"Ctrl-R");
                break;
            case 19:
                strcpy(symbol,"Ctrl-S");
                break;
            case 20:
                strcpy(symbol,"Ctrl-T");
                break;
            case 21:
                strcpy(symbol,"Ctrl-U");
                break;
            case 22:
                strcpy(symbol,"Ctrl-V");
                break;
            case 23:
                strcpy(symbol,"Ctrl-W");
                break;
            case 24:
                strcpy(symbol,"Ctrl-X");
                break;
            case 25:
                strcpy(symbol,"Ctrl-Y");
                break;
            case 26:
                strcpy(symbol,"Ctrl-Z");
                break;
            case 27:
                strcpy(symbol,"Esc");
                break;
            case 28:
                strcpy(symbol,"Ctrl-\\");
                break;
            case 29:
                strcpy(symbol,"Ctrl-]");
                break;
            case 30:
                strcpy(symbol,"Ctrl-6");
                break;
            case 31:
                strcpy(symbol,"Ctrl -");
                break;
                
            default:
                symbol[0]=ch;
                symbol[1]='\0';
                break;
        }
      
       printf("'%s'-%d ",symbol,ch);
       if (count % 10 == 0)
           printf("\n");
    }
    printf("\n");
    return 0;
}
*//*
//ex3 считаем прописные и строчные буквы
#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int ch;
    int upper_cnt=0;// количество прописных букв
    int lower_cnt=0;//количество строчных букв
    int other_cnt=0;//количество других знаков
    printf("Вводим текст:\n");
    while((ch = getchar()) != EOF)
    {
        if (islower(ch))
            lower_cnt++;
        else if (isupper(ch))
            upper_cnt++;
        else
            other_cnt++;
    }
    printf("В результате получен прописных:%d , строчных:%d , иных:%d \n",upper_cnt,lower_cnt,other_cnt);
    return 0;
}
*//*
//ex4 считаем среднее количество букв в словах
#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int ch;
    int letter_cnt=0;//количество букв в словах
    int words_cnt=0;//количество слов
    printf("Вводим текст:\n");
    while ((ch=getchar()) != EOF)
    {
        if (islower(ch) || isupper(ch))
            letter_cnt++;
        if (ch ==' ' || ch =='\n')
            words_cnt++;
    }
    printf("Всего слов: %d, среднее количество букв в слове: %.2f\n", words_cnt,(float)letter_cnt/words_cnt);
    return 0;
}*/
/*
//ex5 улулчшенная версия  программы из листинга 8.4
//целый день боролся, победил Кто молодец, я молодец
#include<stdio.h>
#define MAX 100
#define MIN 1
int main(void)
{
    
    int guess = 50;//начальное значение угаданного числа
    int min_guess = MIN;//переменная при угадывании для мин
    int max_guess = MAX;//переменная при угадывании для макс
    printf("Выберите целое число  в интервале шт 1 до 100. Я попробую угадать его.\nНажмите клавишу y,если моя догадка верна или клавишу n в противном случае.\n");
    printf("Вашим числом является %d?\n",guess);

    char response1;// буквы y и n для угадывания правильности ответа
    int response2;//бвукы b и l для подсказок
    response1 =getchar();
    while (response1 != 'y' && response1 != 'n') //получить ответ
    {
        printf("Принимаются только варинаты y или n.\n");
        while (getchar() != '\n')
                   continue;// пропускаем часть оставшейся строки можно continue не использовать
        response1 = getchar();
    }
    if (response1 == 'n')
    {
        printf("ОК, Ваше число больше или меньше указанного?\nНажмите b если больше или l  если меньше:\n");
        while(getchar() !='\n');
    
        response2 = getchar();

        while(response2 != 'b' && response2 != 'l')
        {
               
            printf("Я не поняла что это вы там нажимаете, попробуйте ещё раз\n");
            while(getchar() !='\n');
            response2 = getchar();
        }
        
        while ((response2 =='b' || response2 =='l') && response2 !='y')
        {
            if (response2 =='b')
                min_guess = guess;
    
            else if (response2 == 'l')
                max_guess = guess;
            
            guess = ( max_guess - min_guess)/2 +min_guess;

            
            printf("Ладно, тогда это %d? \nНажмите y если угадала или b если число больше или l, если меньше\n",guess);
            while(getchar() != '\n');
            
            response2 = getchar();
            
            while(response2 != 'b' && response2 != 'l' && response2 != 'y')
                  {
                      
                      printf("Опять двадцать пять, попробуйте ещё раз\n");
                      while(getchar() !='\n');
                      response2 = getchar();
                  }
        }
        printf("Я такая умная, не правда ли?\n");
    }
    else if (response1 == 'y')
        printf("Я знала что у меня получится c первого раза !\n");
    
    return 0;
}
*//*
//ex6  модернизируем функцию get_first которая пропускает пробельные символы
#include<stdio.h>
char get_first(void);

int main(void)
{
    int ch;
    printf("Вводим  букву соответсвтующую выбранному варианту:\n");
    printf("a) обедать  b) заватрак  c) ужин   q)пора спать\n");
    ch = get_first();
    while ( ch !='a' && ch !='b' && ch !='c' && ch !='q')
    {
        printf("Это что то не то выберите a b c q:\n");
        ch = get_first();
    }
    while (( ch != 'q'))
    {
        printf ("Ну вот поспали, тепрь нужно поесть\nВыберите меню:\n");
        printf("a) обедать  b) заватрак  c) ужин   q)пора спать\n");
        ch = get_first();
        while ( ch !='a' && ch !='b' && ch !='c' && ch !='q')
        {
            printf("Это что то не то выберите a b c q:\n");
            ch = get_first();
        }
       
    }
    printf("Ну вот поели, теперь можно поспать\n");
    
    return 0;
}
char get_first(void)
{
    int ch;
    ch = getchar();
    
    while(ch ==' ' || ch =='\t')//ch=getchar убрать внутрь цикла не получается так как начинает выполняться два getchar()
        ch=getchar();

    while(getchar() != '\n');
    return ch;
}
   *//*
//ex7 модификация упр 8 из 7 главы
#include<stdio.h>
#define TIME_WEEK 40.0 //стандартное количество рабочих часов в неделю
#define TAX1 0.15//налоговая ставка за первые 300 зарплаты
#define TAX2 0.2 //налоговая ставка за следующие 150 зарплаты
#define TAX3 0.25//налоговая ставка за превышение 450 зарплаты
#define SALARY1 300 //точка перехода на новую ставку налога
#define SALARY2 450 //вторая точка перехода на новую ставку налога
#define BREAK1 (SALARY1*TAX1) //налог на 300 долларов з/п
#define BREAK2 (BREAK1 +(SALARY2-SALARY1)*TAX2) //налог на 450 долларов зп

char  menu(void);//функция для вывода и обработки меню

int main(void)
{
    float TARIF1 = 10.00;
    int choice;
    
    choice = menu();

    while (choice != 'q')
    {
        switch (choice) {
            case 'a':
                TARIF1 = 8.75;
                break;
            case 'b':
                TARIF1 = 9.33;
                break;
            case 'c':
                TARIF1 = 10.00;
                break;
            case 'd':
                TARIF1 = 11.2;
                break;
            case 'q':
                break;
        }
 
        float TARIF2 = 1.5*TARIF1;
        float SALARY_IN_WEEK = TIME_WEEK*TARIF1;
        float time_week; //количество отработанных в неделю часов
        
        printf("Введите количество отработотанных в неделю часов\n");
        while(!scanf("%f",&time_week))
        {
            printf("Данные не соответствуют формату, попробуйте ещё раз.\n");
            while(getchar() != '\n');
        }
        while(getchar() != '\n');
        
        float bill;//заработная плата начисленная за отработанные часы
        if (time_week<=40)
            bill = TARIF1*time_week;
        else
            bill = SALARY_IN_WEEK + (time_week - TIME_WEEK)*TARIF2;
        
        float bill_clear; // заработная плата после вычета налогов
        float tax; //налоаг начисленный на заработную плату
        
        if (bill <=SALARY1) //чистая зарплата и налог при з/п <= 300
        {
            tax = bill*TAX1;
            bill_clear = bill - tax;
        }
        else if (bill <= SALARY2)
        {
            tax = BREAK1 + (bill - SALARY1)*TAX2;
            bill_clear = bill - tax;
        }
        else
        {
            tax = BREAK2 + (bill - SALARY2)*TAX3;
            bill_clear = bill - tax;
        }
        
        printf("Выполненно  Налог   Чистые\n");
        printf("%8.2f %8.2f %8.2f\n",bill,tax,bill_clear);
        printf("\n");
        
        //повторный запрос для ввода значений
        printf("Продолжение расчета.\n");
        choice = menu();

    }
    
    printf("Вычисления закончены\n");
    
    return 0;
}

char menu()
{
    int choice;
   printf("Выберите желаемую тарифную ставку:\n");
   printf("a) $8.75/h                    b) $9.33/h\n");
   printf("c) $10.00/h                   d) $11.2/h\n");
   printf("q) Exit\n");
   
   choice = getchar();
   while(choice !='a' && choice !='b' && choice !='c' && choice !='d' && choice !='q')
   {
       printf("Ввод некорректен повторите попытку\n");
       while(getchar() != '\n');
       choice = getchar();
   }
    return choice;
}
*/

//ex8 калькулятор
#include<stdio.h>
char get_choice(void);
char get_first(void);
float get_first_digit(void);
float get_second_digit(void);
float get_float(void);
void add_function(float,float);
void substraction(float,float);
void devision(float,float);
void multiplication(float,float);

int main(void)
{
    int choice;
    
    while ((choice = get_choice()) != 'q')
    {
        switch (choice) {
            case 'A':
            case 'a':
                add_function(get_first_digit(),get_second_digit());
                break;
            case 'S':
            case 's':
                substraction(get_first_digit(),get_second_digit());
                break;
            case 'M':
            case 'm':
                multiplication(get_first_digit(),get_second_digit());
                break;
            case 'D':
            case 'd':
                devision(get_first_digit(),get_second_digit());
                break;
            default:
                break;
        }
    }
    printf("Программа завершена.\n");
    
    return 0;
}

char get_choice(void)
{
    int ch;
    printf("Выберите желаемую операцию:\n");
    printf("a.сложение    s.вычитание     m.умножение\n");
    printf("d.деление     q.завершение\n");
    ch = get_first();
    while( ch != 'a' && ch !='s' && ch !='m' && ch!='d' && ch !='q')
    {
        printf("Выберите a, s, m, d или q\n");
        ch = get_first();
    }
    
    return ch;
}

char get_first(void)
{
    int ch;
    ch = getchar();
    while (ch == ' ' || ch == '\t')
           ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}
float get_first_digit(void)
{
    float digit;
    printf("Введите первое число:\n");
    digit = get_float();
    return digit;
    
}
float get_second_digit(void)
{
    float digit;
    printf("Введите второе число:\n");
    digit = get_float();
    return digit;
    
}

float get_float(void)
{
    char ch;
    float number;
    while(!scanf("%f",&number))
    {
        while ((ch = getchar()) !='\n')
                putchar(ch);
        printf(" не является числом с плавающей точкой. Введите число, такое как 2.5, -1,78e8 или 3:\n");
    }
    while ((ch = getchar()) !='\n');
    
    return number;
}

void add_function(float f,float s)
{
    printf("%.1f + %.1f = %.1f\n",f,s,f+s);
}

void substraction(float f,float s)
{
    printf("%.1f - %.1f = %.1f\n",f,s,f-s);
}
void devision(float f,float s)
{
   while(s == 0)
   {
        printf("Введите число отличное от 0:\n");
        s=get_float();
    }
    printf("%.1f / %.1f = %.1f\n",f,s,f/s);
}

void multiplication(float f,float s)
{
    printf("%.1f * %.1f = %.1f\n",f,s,f*s);
}
