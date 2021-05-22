//
//  main.c
//  chapter7
//
//  Created by пупсик on 19.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_7_1 cypher1.c применение ф-ций  putchar и gerchar

#include <stdio.h>
#define SPACE ' '

int main() {
    char ch;
    while((ch = getchar()) != '\n') //читаем символ пока не встретится конец строки
    {
        if ( ch == SPACE)//оставить пробел нетронутым
            putchar(ch);// символ не меняется
        else
            putchar(ch+1);//изменить другие символы
    }
    
    putchar(ch);//выводим символ новой строки
    return 0;
 }*//*
//попытаемся сделать то же самое с русской кодировкой

#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#define SPACE ' '

int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");
    wchar_t ch;
    while ((ch = getwchar()) != '\n') {
        if (ch == SPACE)
            putwchar(ch);
        else
            putwchar(ch+1);
    }
    putwchar(ch);
}
//прикольно, работает
*//*
//list_7_3 cypher2.c использование библиотеки cype.h
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    while((ch = getchar()) != '\n')
    {
        if (isalpha(ch)) //если это буква
            putchar(ch+1);
        else
            putchar(ch);
    }
    putchar(ch);
}
*//*
//list_7_4 electric.c подсчитываем сумму для счета на электроэнергию
#include<stdio.h>
#define RATE1 0.13230 //тариф за первые 360 кВт
#define RATE2 0.15040 //тариф за следующие 108 кВт
#define RATE3 0.30025 //тариф за следующие 252 кВт
#define RATE4 0.34025 //тариф когда расход превышает 720 кВа/ч
#define BREAK1 360.0 //первая точка разрыва тарифов
#define BREAK2 468.0//вторая точка разрыва тарифов
#define BREAK3 720.0 //третья точка разрыва тарифов
#define BASE1 (RATE1*BREAK1) //стоимость 360 кВт/ч
#define BASE2 (BASE1 + RATE2*(BREAK2-BREAK1)) //стоимость 468 кВт/ч
#define BASE3 (BASE1+BASE2+(RATE3*(BREAK3-BREAK2))) //стоимость 720 кВт/ч

int main(void)
{
    double kwh; //израсходованные кВт/ч
    double bill; //сумма к оплате
    
    printf("Введите объем израсходованной электроэнергии в кВт/ч.\n");
    scanf("%lf",&kwh);//%lf для типа double
    if (kwh<=BREAK1)
        bill = RATE1*kwh;
    else if (kwh<=BREAK2)//количество кВт/ч в промежутке от 360 lk 468
        bill = BASE1+RATE2*(kwh-BREAK1);
    else if (kwh<=BREAK3) //количество кВт/ч в промежутке от 468 до 720
        bill = BASE2+RATE3*(kwh-BREAK2);
    else
        bill = BASE3+RATE4*(kwh-BREAK3);
    printf("Сумма к оплате за %.1f кВт/ч составляет $%1.2f.\n",kwh,bill);
    return 0;
}
   *//*
//list_7_5 divisors.c получение делителей
#include <stdio.h>
#include<stdbool.h>
int main(void)
{
    unsigned long num;//проверяемое число
    unsigned long div;//потенциальные делители
    bool isPrime; //флаг простого число
    printf("Введите целое число для анализа;");
    printf("для завершения введите q.\n");
    while (scanf("%lu",&num))
    {
        for (div =2,isPrime = true;(div*div)<=num;div++ )
        {
            if (!(num % div)) //обязательно скобики перед  num % div иначе не работает
            {
                if ((div*div) != num)
                    printf("%lu делится на %lu и %lu.\n",num,div,num/div);
                else
                    printf("%lu делится на %lu.\n",num,div);
                isPrime = false; //число не является простым
            }
        }
        if (isPrime)
            printf("%lu является простым числом.\n",num);
        printf("Введите следующее число для анализа, для завершения введите q.\n");
    }
    printf("До свидания.\n");
    
    return 0;
    
}
*//*
//list_7_6 chcount.c использование логической операции И
#include<stdio.h>
#define PERIOD '.'
int main(void)
{
    char ch;
    int charcount = 0;
    while((ch=getchar()) != PERIOD)
    {
        if (ch != '"' && ch != '\'') //and не работает
            charcount++;
    }
    printf("Здесь имеется %d символов, отличных от кавычек.\n",charcount);
    
    return 0;
}
   *//*
//list_7_7 wordcnt.c подсчитываем символы, слова, строки
#include<stdio.h>
#include<ctype.h> //для isspace()
#include<stdbool.h> // для bool,true,false
#define STOP '|'

int main(void)
{
    char c; //прочитанный символ
    char prev;//предыдущий прочитанный символ
    long n_chars = 0L; //количество символов
    int n_lines = 0; //количество строк
    int n_words = 0; //количество слов
    int p_lines = 0; //количетсво неполных строк
    bool inword = false; // ==true если символ c находится внутри слова
    printf("Введите текст для анализа (| для завершения):\n");
    prev ='\n'; //используется для идетификации полных строк
   //+ char ar[25]; где плюсы добавлено ко коду чтобы считывать слова
   //+ int i=0;
    while ((c=getchar()) != STOP)
    {
        n_chars++; //считаем символы
        if (c=='\n')
            n_lines++; //считаем строки
        if (!isspace(c) && !inword)
        {
            inword = true;//начало нового слова
            n_words++;
        //+    ar[0]=c;
        }
        if(isspace(c) && inword)
        {
            inword = false; //достигнут конец слова
          //+  ar[i++]='\0';
         //+   printf("%s\n",ar);
          //+  i=0;
        }
    //+    if (!isspace(c) && inword)
     //+           ar[i++]=c;
        
        prev=c;
    }
    if (prev != '\n')
        p_lines = 1;
    printf("симвлолв = %ld ,слов = %d, строк = %d ",n_chars,n_words,n_lines);
    printf("неполнях строк = %d\n",p_lines);
    
    return 0;
}
*//*
//list_7_8 paint.c использование тернарного оператора
#include<stdio.h>
#define COVERAGE 350
int main(void)
{
    int sq_feet;
    int cans;
    
    printf("Введите количество квадратных футов, которые необходимо покрасить:\n");
    while( scanf("%d", &sq_feet))
    {
        cans = sq_feet/COVERAGE;
        cans += (sq_feet%COVERAGE == 0) ?0:1;
        printf("Для этого потребутеся %d %s краски.\n",cans,cans ==1 ? "банка":"банки");
        printf("Введите следующее значение (или q для завершения):\n");
    }
    return 0;
}
*//*
//list_7_9 skippart.c использование continue
#include<stdio.h>
int main(void)
{
    const float MIN = 0.0f;
    const float MAX = 100.0f;
    float score;
    float total = 0.0f;
    int n = 0;
    float min = MAX;
    float max = MIN;
    printf("Введите результат первой игры (или q для завершения):");
    while(scanf("%f",&score))
    {
        if (score<MIN || score>MAX)
        {
            printf("%0.1f - недопустимой значение. Повторите попытку:",score);
            continue;
        }
        printf("Accpting %0.1f:\n",score);
        min = (score<min) ? score:min;
        max= score>min ? score:max;
        total+=score;
        n++;
        printf("Введите результат следующией игры (или q для завершения):");
    }
    if (n>0)
    {
        printf("Среднее значение %d результатов равно %0.1f.\n",n,total/n);
        printf("Минимальное = %0.1f, максимальное = %0.1f\n",min,max);
    }
    else
        printf("Не было введено ни одного допустимого результата.\n");
}
   *//*
//list_7_10 break.c использование break
#include<stdio.h>
int main(void)
{
    float length,width;
    
    printf("Введите длину прямоугольника:\n");
    while(scanf("%f",&length))
    {
        printf("Длина = %0.2f:\n",length);
        printf("Введите ширину прямоугольника:\n");
        if (!scanf("%f",&width))
            break;
        printf("Ширина = %0.2f:\n",width);
        printf("Площадь = %0.2f:\n",length*width);
        printf("Введите длину прямоугольника:\n");
    }
    printf("Программа завершена.\n");
    
    return 0;
}
      *//*
//list_7_11 animals.c использование switch
#include<stdio.h>
#include<ctype.h>
#include<wchar.h>
#include<locale.h>
int main(void)
{
    
    setlocale(LC_ALL,"en_US.UTF-8");// без подключения кодировочной таблицы UTF-8 не работатет
    wchar_t ch;
    
    printf("Дайте мне букву алфавита, и я укажу вам название животного, \nначинающееся с этой буквы.\n");
    printf("Введите букву или # для завершения.\n");
    while ((ch=getwchar()) != '#')
    {
        if (ch =='\n')
            continue;

        if (iswlower(ch)) // только строчные буквы
            switch (ch)
            {
                case L'а':// применение switch c wchar_t
                    printf("архар, дикий горный азиатский баран\n");
                    break;
                case L'б':
                    printf("бабирусса, дикая малайская свинья\n");
                    break;
                case L'к':
                    printf("коати, носуха обыкновенная\n");
                case L'в':
                    printf("выхухоль, водоплавающее существо\n");
                    break;
                case L'е':
                    printf("ехидна, игольчатый муравьед\n");
                    break;
                case L'р':
                    printf("рыболов, светлокоричневая куница\n");
                    break;
                    default:
                    printf("Вопрос озадачил!\n");
            }//конец оператора выбора
        else
            printf("Распознаются только строчные буквы кириллицей.\n");
        while( getchar() != '\n')
            continue; //пропустить оставшуюся часть входной строки
        printf("Введите следующую букву или # для завершения.\n");
    }
    printf("До свидания.\n");
    
    return 0;
}
*//*
//list_7_12 vowels.c использование множества меток
#include<stdio.h>
int main(void)
{
    char ch;
    int a_ct,e_ct,i_ct,o_ct,u_ct;
    
    a_ct=e_ct=i_ct=o_ct=u_ct=0;
    
    printf("Введите текст или # для завершения программы.\n");
    while((ch=getchar()) != '#')
    {
        switch (ch)
        {
            case 'a':
            case 'A': a_ct++;
                break;
            case 'e':
            case 'E': e_ct++;
                break;
            case 'i':
            case 'I': i_ct++;
                break;
            case 'o':
            case 'O':o_ct++;
                break;
            case 'u':
            case 'U': u_ct++;
                break;
                default:break;
        }// конец оператора switch
    } //конец цикла while
    printf("Количество гласных : A    T    I    O    U\n");
    printf("                   %4d %4d %4d %4d %4d",a_ct,e_ct,i_ct,o_ct,u_ct);
 
    return 0;
}
*//*
//myselfcontrol_10
#include <stdio.h>
int main(void)
{
    char ch;
    
    while ((ch = getchar()) != '#')
    {
        if (ch != '\n')
        {
            printf("Шаг 1\n");
            if (ch == 'b')
                break;
            if (ch == 'q')
                printf("Шаг 2\n");
            if (ch == 'q' || ch == 'h')
                printf("Шаг 3\n");
        }
        
    }
    printf("Готово\n");
    return 0;
}
*//*
//ex1 отображаем количество пробелов символов новой строки  и количество всех символов
#include<stdio.h>
#include<ctype.h>
#define STOP '#'
int main(void)
{
    char ch;
    long int ch_cnt = 0;
    int space_cnt = 0;
    int n_cnt = 0;
    printf("Вводим текст:\n");
    while((ch =getchar()) != STOP)
    {
        ch_cnt++;
        if (ch == '\n')
            n_cnt++;
        if (isspace(ch))
            space_cnt++;
    }
    printf("Результат\n");
    printf("пробелы %d, строк %d, всего символов %ld\n",space_cnt,n_cnt,ch_cnt);
    
    return 0;
}
*//*
//ex2 отображаем символы строк
//работает в кодировке ASCII для кириллицы подключите wchar_t и utf-8
#include<stdio.h>
#define STOP '#'
int main(void)
{
    char ch;
    printf("Вводим текст:\n");
    int ch_cnt = 0;
    while((ch = getchar()) != STOP)
    {
        ch_cnt++;
        if (ch != '\n')
          printf("'%c'-%d ",ch,(int)ch);
        
        if (ch_cnt % 8 == 0)
            printf("%c",'\n');
    }
    printf("%c",'\n');
    return 0;
}
   *//*
//ex3 считаем целые числа
#include<stdio.h>
int main(void)
{
    int digit;
    int od_cnt = 0; //количество введенных нечётных чисел
    int od_sum = 0;//сумма введенных нечётных чисел
    int ed_cnt = 0;//количество введенных четных чисел
    int ed_sum = 0; //сумма введенных чётных чисел
    
    while(scanf("%d",&digit) && digit != 0)
    {
        if (digit % 2 == 0)
        {
            ed_cnt++;
            ed_sum += digit;
        }
        else
        {
            od_cnt++;
            od_sum += digit;
        }
    }
    printf("Количество чётных чисел %d, среднее значение %.2f\n",ed_cnt,(float)ed_sum/ed_cnt);
    printf("Количество нечётных чисел %d, среднее значение %.2f\n",od_cnt,(float)od_sum/od_cnt);
    
    return 0;
}
      *//*
//ex4 замена знаков препинания
#include<stdio.h>
#define STOP '#'
#define DOT '.'
#define BANG '!'
int main(void)
{
    char ch;
    int total_changed = 0; //количество произведённых замен
    printf("Вводим слово:\n");
    while((ch = getchar()) != STOP)
    {
        if (ch==BANG || ch == DOT)
        {
            putchar(BANG);
            total_changed++;
        }
        else if (ch != DOT)
            putchar(ch);
    }
    printf(" Всего заменили %d\n знаков",total_changed);
    return 0;
}
*//*
//ex5 используем switch
#include<stdio.h>
#define STOP '#'
#define DOT '.'
#define BANG '!'
int main(void)
{
    char ch;
    int total_changed = 0;
    while ((ch = getchar()) != STOP)
    {
        
        switch (ch) {
            case BANG:
            case DOT:
                putchar(BANG);
                total_changed++;
                break;
            default:
                break;
        }
        if (ch != DOT)
            putchar(ch);
        
    }
    printf("Всего заменили:%d\n",total_changed);
    
    return 0;
}
*//*
//ex6 считаем количество ei
#include<stdio.h>
#define E 'e'
#define I 'i'
#define STOP '#'
int main(void)
{
    char ch;
    char prev='.'; //вводим переменную предыдущего символа
    int ei_cnt = 0;//количество вхождений ei
    printf("Вводите фразу:\n");
    while ((ch = getchar()) != '#')
    {
        if (I == ch && E == prev)
            ei_cnt++;
        prev = ch;
    }
    printf("Насчитали %d штук ei\n",ei_cnt);
    return 0;
}
 *//*
//ex7 начисление налогов и заработной платы
#include<stdio.h>
#define TIME_WEEK 40.0 //стандартное количество рабочих часов в неделю
#define TARIF1 10.0 //тариф заработной платы за стандартные часы
#define TARIF2 (1.5*TARIF1) //тариф заработной платы за сверхурочные
#define SALARY_IN_WEEK (TIME_WEEK*TARIF1)//заработная плата до начисления налогов  за стнадартное количество часов
#define TAX1 0.15//налоговая ставка за первые 300 зарплаты
#define TAX2 0.2 //налоговая ставка за следующие 150 зарплаты
#define TAX3 0.25//налоговая ставка за превышение 450 зарплаты
#define SALARY1 300 //точка перехода на новую ставку налога
#define SALARY2 450 //вторая точка перехода на новую ставку налога
#define BREAK1 (SALARY1*TAX1) //налог на 300 долларов з/п
#define BREAK2 (BREAK1 +(SALARY2-SALARY1)*TAX2) //налог на 450 долларов зп

int main(void)
{
    float time_week; //количество отработанных в неделю часов
    printf("Введите количество отработотанных в неделю часов\n");
    scanf("%f",&time_week);
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
    
    return 0;
}
*//*
//ex8 меняем тарифные ставки через switch
#include<stdio.h>
#define TIME_WEEK 40.0 //стандартное количество рабочих часов в неделю
#define TAX1 0.15//налоговая ставка за первые 300 зарплаты
#define TAX2 0.2 //налоговая ставка за следующие 150 зарплаты
#define TAX3 0.25//налоговая ставка за превышение 450 зарплаты
#define SALARY1 300 //точка перехода на новую ставку налога
#define SALARY2 450 //вторая точка перехода на новую ставку налога
#define BREAK1 (SALARY1*TAX1) //налог на 300 долларов з/п
#define BREAK2 (BREAK1 +(SALARY2-SALARY1)*TAX2) //налог на 450 долларов зп

int main(void)
{
    float TARIF1 = 10.00;
    int num_of_tarif=100;
    
    printf("Введите число, соответствующее желаемой тарифной ставке или действию:\n");
    printf("1) $8.75/h                    2) $9.33/h\n");
    printf("3) $10.00/h                   4) $11.2/h\n");
    printf("5) Exit");
    
    while(!(scanf("%d",&num_of_tarif)) || num_of_tarif<1 || num_of_tarif>5)
        printf("Ввод некорректен повторите попытку\n");
    
    while (num_of_tarif != 5)
    {
        switch (num_of_tarif) {
            case 1:
                TARIF1 = 8.75;
                break;
            case 2:
                TARIF1 = 9.33;
                break;
            case 3:
                TARIF1 = 10.00;
                break;
            case 4:
                TARIF1 = 11.2;
                break;
            case 5:
                break;
        }
 
        float TARIF2 = 1.5*TARIF1;
        float SALARY_IN_WEEK = TIME_WEEK*TARIF1;
        float time_week; //количество отработанных в неделю часов
        printf("Введите количество отработотанных в неделю часов\n");
        scanf("%f",&time_week);
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
        
        //повторный запрос для ввода значений
        printf("Введите число, соответствующее желаемой тарифной ставке или действию:\n");
        printf("1) $8.75/h                    2) $9.33/h\n");
        printf("3) $10.00/h                   4) $11.2/h\n");
        printf("5) Exit\n");
        printf("\n");
       
           while(!(scanf("%d",&num_of_tarif)) || num_of_tarif<1 || num_of_tarif>5)
               printf("Ввод некорректен повторите попытку\n");
           
    }
    
    printf("Вычисления закончены\n");
    
    return 0;
}
*//*
//ex9 выводим простые числа
#include <stdio.h>
#include<stdbool.h>
int main(void)
{
    
    unsigned long num_limit;//число в диапазоне которого ищутся простые числа
    unsigned long num; //переменная для перебора чисел в диапазоне
    unsigned long div;// переменная для перебора делителей
    bool isPrime;//флаг простого числа
    
    printf("Введите число для установки диапазона, для завершения введите q\n");
   
    while(scanf("%lu",&num_limit))
    {
        printf("В дипазоне от 2 до %lu находятся следующие простые числа\n",num_limit);
        for (num=2,isPrime = true;num<=num_limit;num++,isPrime = true)//устанавливаем isPrime в  true на каждой итерации
        {
            for (div=2;div*div <=num;div++)
            {
                if (num % div == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                printf("%lu ",num);
        }
        printf("\n");
        printf("Введите число для установки диапазона, для завершения введите q\n");
    }
    
    return 0;
}
*//*
//ex10 вычиспление суммы налога
#include<stdio.h>
#include<string.h>
#define TAX_RATE1 0.15 //налоговая ставка для первого уровня налогообложения
#define TAX_RATE2 0.28 //налоговая ставка для второго уровня налогооблажения
#define ALONE 17850.0 //уровень дохода по первому уровню для одиноких
#define CHIEF_OF_FAMILY 23900.0 //уровень дохода по первому уровню для глав семейств
#define JOINT 29750.0 //уровень дохода по первому уровню для совместного ведения хозяйства
#define SEPARATE 14875.0 //уровень дохода по первому уровню для раздельного ведения хозяйства


int main(void)
{
    int status = 100;//переменная статуса получателя дохода
    float input;//полученный доход
    float min_input=10000.0;//миниальный уровень дохода для первого уровня налогооблажения
    float min_tax=min_input*TAX_RATE1;//сумма налога для первого уровня налогооблажения
    float tax_total;//сумма налога на доход
    char type[40];
    printf("Введите статус получателя дохода:\n");
    printf("1) для одиноких        2)для глав семейств\n");
    printf("3) для лиц, состоящих в браке и ведущих совместное хозяйство\n");
    printf("4) для лиц, состоящих в браке и раздельно ведущих хозяйство\n");
    printf("5) для выхода из программы ведения расчётов\n");
  
    while (!(scanf("%d",&status)) || status<1 ||status>5)
        printf("Данные не приняты, укажите корректное значение");
    
    while (status !=5)
    {
        switch (status) {
            case 1:
                min_input = ALONE;
                min_tax = ALONE*TAX_RATE1;
                strcpy(type,"ALONE");
                break;
            case 2:
                min_input = CHIEF_OF_FAMILY;
                min_tax = CHIEF_OF_FAMILY*TAX_RATE1;
                strcpy(type,"CHIEF OF FAMILY");
                break;
            case 3:
                min_input = JOINT;
                min_tax = JOINT*TAX_RATE1;
                strcpy(type,"JOINT");
                break;
            case 4:
                min_input = SEPARATE;
                min_tax = SEPARATE*TAX_RATE1;
                strcpy(type,"SEPARATE");
                break;
            default:
                break;
        }
        printf("Введите уровень дохода:");
        scanf("%f",&input);
        
        if (input <= min_input)
            tax_total = input*TAX_RATE1;
        else
            tax_total = min_tax + (input - min_input)*TAX_RATE2;
        
        printf("При уровне дохода %.2f сумма налога для типа %s составит %.2f , чистый доход - %.2f\n",input,type,tax_total,input-tax_total);
        printf("\n");
        
        //ввод значений для повторного использования
        printf("Введите статус получателя дохода для новых получателей:\n");
        printf("1) для одиноких        2)для глав семейств\n");
        printf("3) для лиц, состоящих в браке и ведущих совместное хозяйство\n");
        printf("4) для лиц, состоящих в браке и раздельно ведущих хозяйство\n");
        printf("5) для выхода из программы ведения расчётов\n");
        while (!(scanf("%d",&status)) || status<1 ||status>5)
            printf("Данные не приняты, укажите корректное значение");
    }
    printf("Расчёты завершены, удачных доходов\n");
    
    return 0;
}

*/
//ex11 вычисление затрат на закупку овощей
#include<stdio.h>
#define ARTISHOKE 2.05
#define BEET 1.15
#define CARROT 1.00
#define DISCOUNT 0.05
#define DISCOUNT_LIMIT 100.0 //сумма с которой скидка предоставляется
#define WEIGHT1 5.0 //шкала весов для доставки 1 уровень
#define WEIGHT2 20.0 //шкала весов для доставки 2 уровень
#define DELIVERY1 6.5 //стоимость доставки груза до 5 фунтов
#define DELIVERY2 14.0 //стоимость доставки груза от 5 до 20 фунтов
#define MAX_DELIVERY 0.5 //стоимость доставки за каждый фунт превышающий 20

int main(void)
{
    float artishoke_weight=0;//вес артишоков в заказе
    float beet_weight=0;//вес свеклы в заказе
    float carrot_weight=0;//вес моркови в заказе
    float total_weight;//общий вес заказа
    float artishoke_cost=0;//стоимость заказа артишоков
    float beet_cost =0;//стоимость заказа свёклы
    float carrot_cost = 0;//стоимость заказа моркови
    float total_cost;//общая сумма заказа без скидки
    float discount=0;//размер скидки
    float delivery_total = DELIVERY1;//стоимость доставки
    
    char type;// тип заказываемого продукта
    float weight;//вес продукта
    printf("Укажите желаемый для заказа продукт:\n");
    printf("a) для заказа артишоков        b) для заказа свеклы    c) для заказа моркови\n");
    printf("q) для окончания ввода\n");
    
    while((type = getchar()) != 'q')
    {
        printf("Укажите вес продукта в заказе:\n");
        while(!scanf("%f",&weight))
            printf("Не соответсвующий формат, повторите ввод\n");
        switch (type) {
            case 'a':
            case'A':
                artishoke_weight +=weight;
                artishoke_cost +=artishoke_weight*ARTISHOKE;
                break;
            case 'b':
            case 'B':
                beet_weight +=weight;
                beet_cost +=beet_weight*BEET;
                break;
            case 'c':
            case 'C':
                carrot_weight +=weight;
                carrot_cost +=carrot_weight*CARROT;
                break;
            default:
                break;
        }
        
        while(getchar() != '\n') ; //!!!! ОЧЕНЬ ВАЖНЫЙ МОМЕНТ БЕЗ ЭТОГО ОПЕРАТОРА КОД РАБОТАТЬ НЕ БУДЕТ Пропускаем все знаки до конца строки
        // предложение дополнительного заказа
        printf("Укажите, какие продукты вы желаете заказать дополнительно, для окончания заказа нажмите q:\n");
        printf("a) для заказа артишоков        b) для заказа свеклы    c) для заказа моркови\n");
           printf("q) для окончания ввода\n");

    }
    //рачет веса и стоимости
    total_weight = artishoke_weight+beet_weight+carrot_weight;
    total_cost = artishoke_cost+beet_cost+carrot_cost;
    if (total_cost > DISCOUNT_LIMIT)
        discount = total_cost*DISCOUNT;
    
    //расчет доставки
    if (total_weight <= WEIGHT1)
        delivery_total = DELIVERY1;
    else if (total_weight <= WEIGHT2)
        delivery_total = DELIVERY2;
    else
        delivery_total = DELIVERY2 + (total_weight - WEIGHT2)*MAX_DELIVERY;
    
    //вывод данных
    printf("TOTAL:\n");
    printf("Товар       Вес    Цена/фунт   Всего\n");
    if (artishoke_cost >0)
        printf("Артишоки   %4.2f %8.2f %10.2f\n",artishoke_weight,ARTISHOKE,artishoke_cost);
    if (beet_cost > 0)
        printf("Свёкла     %4.2f %8.2f %10.2f\n",beet_weight,BEET,beet_cost);
    if (carrot_cost > 0)
        printf("Морковь    %4.2f %8.2f %10.2f\n",carrot_weight,CARROT,carrot_cost);
    printf("Всего стоимость заказка:         %0.2f\n",total_cost);
    printf("Скидка                           %0.2f\n",discount);
    printf("Стоимость заказа со кидкой:      %0.2f\n",total_cost-discount);
    printf("Стоимость доставки:              %0.2f\n",delivery_total);
    printf("ОБЩАЯ СТОИМОСТЬ ЗАКАЗА:          %0.2f\n",total_cost-discount+delivery_total);
}

