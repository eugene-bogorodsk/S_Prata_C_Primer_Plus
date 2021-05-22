//
//  main.c
//  chapter_4
//
//  Created by пупсик on 10.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
// list_4_1 talkback.c введение в ввод и вывод
#include <stdio.h>
#include <string.h> //для прототипа функции strlen()
#define DENSITY 62.4 // плотность человека в фунтах на куб. фунт

int main(void) {
    float weight,volume;
    unsigned long size,letters;
    char name[40]; // name представляет собой массив из 40 символов
    
    printf("Здравствуйте! Как Вас зовут?\n");
    scanf("%s",name);
    printf("%s, сколько вы весите в фунтах?\n", name);
    scanf("%f", &weight);
    size = sizeof name;
    letters = strlen(name);
    volume = weight/DENSITY;
    printf("Хорошо, %s, ваш объём составляет %2.2f кубических футов.\n",name,volume);
    printf("К тому же ваше имя состоит из %ld букв,\n", letters);
    printf("и мы распологаем %ld байтами для его сохранения.\n",size);
    return 0;
}
 *//*
//list_4_2 praisel.c -  использует различные прдставления строк
#include <stdio.h>
#define PRAISE "Вы - выдающаяся личность."

int main(void)
{
    char name[40];
    printf("Как вас зовут?");
    scanf("%s",name);
    printf("Здравствуйте, %s, %s\n",name, PRAISE);
    return 0;
}
    *//*
//list_4_3 praise2.c использование zd как спецификаторов
#include <stdio.h>
#include <string.h> //предоставляет прототип strlen()
#define PRAISE "Вы - выдающаяся личность."

int main(void)
{
    char name[40];
    
    printf("Как Вас зовут?");
    scanf("%s",name);
    printf("Здравствуйте, %s, %s\n",name,PRAISE);
    printf("Ваше имя состоит из %zd символов и занимает %zd ячеек памяти.\n", strlen(name),sizeof name);
    printf("Хвалебная фраза содержит %zd символов", strlen(PRAISE));
    printf("и занимает %zd ячеек памяти.\n",sizeof(PRAISE));
    return 0;
}
// удивительно но при вводе двух слов через пробел отображается одно но функция strlen(name)
// считает все введеные символы
//Как Вас зовут?Васисуалий Лоханкин
//Здравствуйте, Васисуалий, Вы - выдающаяся личность.
//Ваше имя состоит из 20 символов и занимает 40 ячеек памяти.
*//*
//list_4_4  pizza.c использует константу pi для определения диаметра и площади пиццы
#include <stdio.h>
#define PI 3.14159

int main(void)
{
    float area,circum,radius;
    
    printf("Каков радиус вашей пиццы?\n");
    scanf("%f", &radius);
    area = PI*radius*radius;
    circum = 2.0*PI*radius;
    printf("Основные параметры вашей пиццы:\n");
    printf("длина окружности = %1.2f, площадь = %1.2f\n",circum,area);
    return 0;
}
   *//*
//list_4_5 defines.c использует именованные константы из файла limit.h и float.h
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Некоторые пределы чисел для данной системы:\n");
    printf("Наибольшее значение типа int: %d\n",INT_MAX);
    printf("Наибольшее значение для типа long long: %lld\n",LLONG_MAX);
    printf("Наименьшее значени для типа long long: %lld\n",LLONG_MIN);
    printf("В данной системе один байт = %d бит.\n",CHAR_BIT);
    printf("Наибольшее значение типа double: %e\n",DBL_MAX);
    printf("Наименьшее нормализованное значение типа float: %e\n",FLT_MIN);
    printf("Точность значений типа float = %d знаков\n",FLT_DIG);
    printf("Разница между 1.00 и минимальным значением float,которое больше 1.00 = %e\n",FLT_EPSILON);
    return 0;
}
*//*
//list_4_6 printout.c - использование спецификаторов преобразования
#include <stdio.h>
#define PI 3.141593

int main(void)
{
    int number = 7;
    float pies = 12.75;
    int cost = 7800;
    
    printf("%d участников соревнований съели %f пирожков с вишнями.\n",number,pies);
    printf("Значение pi равно %f.\n",PI);
    printf("До свидания! Ваше искусство слишком дорого объодится,\n");
    printf("%c%d\n",'$',2*cost);
    return 0;
}
*//*
//list_4_7 width.c использование модификаторов полей с целыми числами
#include <stdio.h>
#define PAGES 959
int main(void)
{
    //звездочка обозначает начало и конец кадого поля
    printf("*%d*\n",PAGES);//вывод без модификаторов поле шириной с число
    printf("*%2d*\n",PAGES);//устанавливает ширину поля 2, если число имеет больше значащих
    //цифр выыодится это число
    printf("*%10d*\n", PAGES);//генерирует поле шириной 10 знаков
    printf("*%-10d*\n", PAGES);//генерирует поле шириной 10 знаков - смещает число к левому
    //краю
    
    return 0;
}
   *//*
//list_4_8 float.c модификаторы для типов с плавающей запятой
#include <stdio.h>

int main(void)
{
    const double RENT = 3852.99;//константа, объявленная посредством cost
    
    printf("*%f*\n",RENT);//ширина поля = количеству цифр в числе, количество цифр после за
    // пятой по умолчанию 6
    printf("*%e*\n",RENT);//одна цифра слева от десятичной точки и шесть позиций после неё
    //е+3 10 в третей степени
    printf("*%4.2f*\n",RENT);//четыре цифры слева от запятой и две после
    printf("*%3.1f*\n",RENT);// три цифры слева от запятой ( выводится сколькое есть если
    //меньше. одна после значения в дробной части округляются
    printf("*%10.3f*\n",RENT);//10 цифр слева от запятой три после в дробной части дополня
    //ется нулями
    printf("*%10.3e*\n",RENT);
    printf("*%+4.2f*\n",RENT);//вывод значения с алгебраическим знаком
    printf("*%010.2f*\n",RENT);//0 перед десять означает что незаполненные поля в целой //части заполняются незначащими нулями
    
    return 0;
}
      *//*
//list_4_9 flags.c применение флагов форматирования
#include <stdio.h>
int main(void)
{
    printf("%x %X %#x\n",31,31,31);//вывод числа 31 в шестандцатиричном виде, # обеспечивает
    //вывод символов 0х
    printf("**%d**% d**% d**\n",42,42,-42);// применение пробела приводит к появлению ведущего пробела для положительных но не отрицательных чисел
    printf("**%5d**%5.3d**%05d**%05.3d**\n",6,6,6,6);// применение спецификатора точности 5.3 для целых чисел приводит к заполнению ведующими нулями при одновременном указании флага 0 и спецификатора точности  флаг 0 игнорируется
    return 0;
}
         *//*
//list_4_10 stringf.c форматирование строк
#include <stdio.h>
#define BLURB "Authentic imitation!"

int main(void)
{
    printf("[%2s]\n",BLURB);//2s расширяет поле настолько, чб уместить все символы строки
    printf("[%24s]\n",BLURB);
    printf("[%24.5s]\n",BLURB);//модификатор точности ограничивает вывод 5 символами
    printf("[%-24.5s]\n",BLURB);//модификатор - выравнивает текст по левому краю
    
    return 0;
}
*//*
//list_4_11 intconv.c - несоответствие при преобразовании целочисленных типов
#include <stdio.h>
#define PAGES 336
#define WORDS 65618

int main(void)
{
    short num = PAGES;
    short mnum = -PAGES;
    
    printf("num как тип short и тип unsigned  short: %hd %hu\n",num,num);// модификатор h используется для отображения short и unsigned short
    printf("-num как тип short и тип unsigned shorts: %hd %hu\n",mnum,mnum);// для предоставления short используется два байта для представления целых чисел со знаком используется метод поразрадного дополнения до двойки, когда числа от 32768 до 65535 представляют отрицательные числа 65535 соответствует -1, 65534 - -2   и тд Те -336 представлено как 65535-336 или 65200
    printf("num как тип int и тип char: %d %c\n",num,num);// когда выводится 336 со спецификатором %c она просматривает только один байт из двух задействованных для хранения 335 такое усечение равнозначно делению целого числа на 256 с сохранением остатка в данном случае остаток равен 80 что представляет из себя символ P
    printf("WORDS как тип int,short и char: %d %hd %c\n",WORDS,WORDS,WORDS);// число 65618 в силу своего размера хранится как 4-байтное значение когда оно выводится со спецификатором %hd оспользуется только последние два байта что равносильно остатку от деления на 65536 в этом случае остаток равен 82 Остаток между 32767 и 65536 выводлися бы как отрицательное число
    
    return 0;
}
   *//*
//list_4_12 floatonv.c - несогласованные преобразования с плавающей запятой
#include <stdio.h>
int main(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;
    
    printf("Тип double имеет размер %zd байт\n",sizeof(double));
    printf("%.le %.le %.le %.le\n",n1,n2,n3,n4);//спецификатор le выводит 8 значащих цифр представленного числ
      
    printf("Последним целым числом было %d\n",n);
    
    return 0;
}
*//*
//вопросы для самоконтроля
#include <stdio.h>
int main(void)
{
    printf("%c%c%c",'H',105,'\41');//\41 - передача кода в 8-м видео (33 в десятичном виде)
    return 0;
}
   *//*
//ex1  программа выводит имя и фамилию
#include <stdio.h>
int main(void)
{
    char name[40];
    printf("Введите ваше имя:");
    scanf("%s",name);
    
    char surname[40];
    printf("Введите вашу фамилию:");
    scanf("%s",surname);
    
    printf("Ваше имя:%s\n",name);
    printf("Ваша фамилия:%s\n",surname);
    
    return 0;
}
*//*
//ex2 вывод имени в различных форматах
#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[40];
    printf("Введите ваше имя:");
    scanf("%s",name);
    printf("Варианты вывода:\n");
    printf("\"%s\"\n",name);
    printf("\"%20s\"\n",name);
    printf("\"%-20s\"\n",name);
    int width;
    width = (int)strlen(name)+3;//произведена операция приведения типа тк фция strlen возвращает значение unsigned long
    printf("%*s\n",width,name);
    
    return 0;
}
*//*
//ex3 вывод числа с плавающей запятой в различных форматах
#include<stdio.h>
int main(void)
{
    float x;
    printf("Enter the number:");
    scanf("%f",&x);
    printf("Results:\n");
    printf("%.1f %.1e\n",x,x);
    printf("%+2.3f %.3E\n",x,x);
    
    return 0;
}
*//*
//ex4 перевод роста из дюймов в футы
#include <stdio.h>
int main(void)
{
    char name[40];
    printf("Введите имя:");
    scanf("%s",name);
    float high;
    printf("Введите рост:");
    scanf("%f",&high);
    printf("%s, ваш рост составляет %.3f футов\n",name,high/12);
    
    return 0;
}
*//*
//ex5 программа запрашивает скорость загрузки в мегабитах и размер файла в мегабайтах и возвращает  время загрузки файла
#include<stdio.h>
int main(void)
{
    float velocityOfLoad;
    float volumeOfFile;
    printf("Введите скорость загрузи в мегабитах и размер файла в мегабайтах:\n");
    scanf("%f %f",&velocityOfLoad,&volumeOfFile);
    printf("При скорости загрузки %.2f мегабайт в секунду файл размером %.2f мегабайт загружается за %.2f секунд.\n",velocityOfLoad,volumeOfFile,volumeOfFile*8/velocityOfLoad);
    return 0;
}
   *//*
//ex6 программа запрашивает имя и фамилию и выводит их длину
#include<stdio.h>
#include<string.h>
int main(void)
{
    char name[40];
    printf("Введите имя:");
    scanf("%s",name);
    
    char surname[40];
    printf("Введите фамилию:");
    scanf("%s",surname);
    
    printf("%s %*s\n",name,(int)strlen(surname)+3,surname);
    printf("%*d %*lu\n",(int)strlen(name)/2,(int)strlen(name)/2,(int)strlen(surname)/2+3,strlen(surname)/2); //при использование русских букв делим результат возвращаемый функцией strlen() на два так как под киррилицу выделяется два байта а не один как под латиницу
    printf("%s %*s\n",name,(int)strlen(surname)+3,surname);
    printf("%-*lu %-*lu\n",(int)strlen(name)/2+3,strlen(name),(int)strlen(surname)/2,strlen(surname)/2);
    return 0;
}
      *//*
//ex7 вывод чисел с плавающей точкой в различных форматах
#include<stdio.h>
#include<float.h>
int main(void)
{
    double first = 1.0/3.0;
    float second = 1.0/3.0;
    
    printf("%d %d\n",FLT_DIG,DBL_DIG);//глубина вывода для float 6 знаков после точки поэтому после 6 знака выводится мусор хранящийся в ячейках памяти
    printf("%.4f %.4f\n",first,second);
    printf("%.12f %.12f\n",first,second);
    printf("%.16f %.16f\n",first,second);
    
    return 0;
}
*/
//ex8 вывод расстояния проходимого на одно галлоне бензина
#include<stdio.h>
#define LITTERSINGALLON 3.785
#define KMINMILLS 1.609
int main(void)
{
    printf("Введите количество преодолённых миль и колличество галлонов израсходованного бензина:\n");
    float spread;
    float expend;
    scanf("%f %f",&spread,&expend);
    printf("Расход бензина в американской традиции %.1f миль на галллон\n",spread/expend);
    printf("Расход бензина в европейской традиции %.1f литров на 100 км\n",100*expend*LITTERSINGALLON/(spread*KMINMILLS));
    return 0;
}
