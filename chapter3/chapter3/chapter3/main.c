//
//  main.c
//  chapter3
//
//  Created by пупсик on 09.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//

/*
//Целочисленное перполнение toobig.c
#include <stdio.h>
int main(void) {
    int i =2147483647;
    unsigned int j = 4294967295;
    
    printf("%d %d %d\n",i,i+1,i+2);
    printf("%u %u %u\n", j,j+1,j+2);
    
    return 0;
}
*/
/*
//print2.c -- дополнительные свойства функции printf()
#include <stdio.h>
int main(void) {
    unsigned int un = 3000000000;
    short end=200;
    long big=65537;
    long long verybig = 12345678908642;
    
    printf("un = %u ,but not %d\n",un,un);
    printf("end = %hd and %d\n",end,end);
    printf("big = %ld, but not %hd\n",big,big);
    printf("verybig = %lld bot not %ld\n",verybig,verybig);
    
    
    return 0;
}
*/
/*
// typesize.c = выводит размеры типов
#include <stdio.h>
int main(void)
{
    // в стандарте 99 для размеров предусмотрен спецификатор %zd
    printf("Тип int имеет размер %zd байт.\n",sizeof(int));// в типе int вмещается 4,2 млрд
 //беззнаковых чисел -4 байта 32 разряда
    printf("Тип short имеет размер %zd байт.\n",sizeof(short));
    printf("Тип char имеер размер %zd байт.\n",sizeof(char));
    printf("Тип long имеет размер %zd байт.\n",sizeof(long));
    printf("Тип long long имеет размер %zd байт.\n",sizeof(long long));
    printf("Тип double имеет размер %zd байт.\n",sizeof(double));
    printf("Тип long double имеет размер %zd байт.\n",sizeof(long double));
    return 0;
}
 */
//ex1 обработка переполнения использует библиотеки из главы 4
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("Наибольшее значение типа int: %d\n",INT_MAX);// в данной системе 2147483647
    printf("Увелечение INT_MAX на 1: %d\n",INT_MAX+1); //IDE выдает сообщение об ошибке
    //получаем максимальное отрицательное число
    printf("Наибольшее значение типа unsigned int: %u\n",UINT_MAX);//в данной системе //4294967295 , для отображения используется спецификатор u
    printf("Увелечение UINT_MAX на 1: %u\n",UINT_MAX+1);//сообщение об ошибке не поступает
    //  в результате получаем 0
    printf("Точность значений типа float = %d знаков\n",FLT_DIG);// 6 знаков
    printf("Пробуем отобразить число с 8 знаками 56.789199: %f\n",56.789199);//отображается в полном виде, так как при отображение форматируется до duble
    printf("Пробуем отобразить число с 10 знаками 56.78919963: %f\n",56.78919963);//срезается до 8
    printf("Наибольшее значение типа double: %e\n",DBL_MAX);
    printf("Пробуем увеличить DBL_MAX на 1: %e\n",DBL_MAX+1);//ничего не происходит 1 просто отбрасывается
    return 0;
}
/*
//ex2 - программа  приглашает ввести код  в ASCII  и выводит символ которому этот код
// соответствует
#include <stdio.h>
int main(void)
{
    int letter;
    printf("Введите код символа.\n");
    scanf("%d",&letter);
    printf("По коду %d находится символ %c.\n",letter,letter);
    return 0;
}
*//*
// ex3 программа издает звуковой сигнал
#include <stdio.h>
int main(void)
{
    printf("\a");//типа должно пищать
    printf("Ипуганная внезапным звуком, Вика воскликнула:\n");
    printf("\"Во имя всех звёзд, что это было!\"");
    return 0;
}
// на самом деле не издает в этой системе \a не работает (((
*//*
//ex4 отображение переменной типа float тремя способами
#include <stdio.h>
int main(void)
{
    float about;
    printf("Введите переменную с плавающей запятой: ");
    scanf("%f",&about);
    printf("\nВывод в десятичном исполнении с фиксированной запятой: %f",about);
    printf("\nВывод в экспоненциальной форме: %e",about);
    printf("\nДвочино-экспоненциальное представление: %a\n",about);
    //на самом деле число представлено в шестнадцатеричном виде с расширением p, где р это
    // степень двойки
    //данная система обеспечивает вывод 7 занчачих цифр в формате f остальные цифры отбрасываются
}*//*
//ex5 отображает возраст в секундах
#include <stdio.h>
int main(void)
{
    float sec_in_year = 1.156e+7;//количество секунд в году
    unsigned int year;
    printf("Введите Ваш возраст: ");
    scanf("%u",&year);
    printf("Ваш возраст в секундах составляет: %f секунд\n", year*sec_in_year);
    return 0;
}*/
/*
//ex6 ввод объема воды в квартах и вывод количество молекул воды в этом объеме
#include <stdio.h>
int main(void)
{
    float massaOfWaterMolecul = 3.0e-23; //масса одной молекулы воды в граммах
    float grammOfWaterInQwarta = 950.0;//количество грамм воды в одной кварте
    int QuatatyQwarts;
    printf("Введите количество кварт:");
    scanf("%f",&QuatatyQwarts);
    printf("В данном количестве кварт содержится: %e молекул воды\n",
           QuatatyQwarts*grammOfWaterInQwarta/massaOfWaterMolecul);
    return 0;
 }*//*
//ex7 перевод дюйм в сантимертры
#include <stdio.h>
int main(void)
{
    float inchesInSantimetrs = 2.54;//количество дюймов в сантимертрах
    int yourHight;
    printf("Введите Ваш рост в см:");
    scanf("%d",&yourHight);
    printf("\nВаш рост составляет %.2f дюймов\n",yourHight/inchesInSantimetrs);
    return 0;
}
*//*
//ex8 вывод объемов в американских еденицах
#include <stdio.h>
int main(void)
{
    float capsInPints = 2.0; //количество чашек в одной пинте
    float unciasInCpas = 8.0;//количество унций в одной чашке
    float tablespoonsInUncia = 2.0;//количество столовых ложек в унции
    float teaspoonsInTablespoon = 3.0;//количество чайных ложек в столовой
    int inCaps;
    printf("Введите количество чашек:");
    scanf("%d",&inCaps);
    printf("\nВ %d чашках содержится:\n",inCaps);
    printf("%.1f пинт\n",inCaps/capsInPints);
    printf("%.1f yнций\n",inCaps*unciasInCpas);
    printf("%.1f столовых ложек\n",inCaps*tablespoonsInUncia*unciasInCpas);
    printf("%.1f чайных ложек\n",inCaps*teaspoonsInTablespoon*tablespoonsInUncia*unciasInCpas);
    return 0;
}
*/
