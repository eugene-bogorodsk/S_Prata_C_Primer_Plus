//
//  hotel.c
//  chapter9_hotel
//
//  Created by пупсик on 28.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//

#include <stdio.h> //функции управления отелем
#include "hotel.h"

int menu(void)
{
    int code,status;
    printf("\n%s%s\n",STARS,STARS);
    printf("Введите число, соответствующее выбранному отелю:\n");
    printf("1) Fairlield Arms     2) Hotel Olympic\n");
    printf("3) Chertwotrhy Plaza  4) The Stockton\n");
    printf("5) Выход\n");
    printf("%s%s\n",STARS,STARS);
    while (!(status = scanf("%d",&code)) || (code <1 || code > 5))
    {
        if (!status)
            scanf("%*s"); //отбрасывание нецелочисленного ввода
        printf("Введите целое число от 1 до 5.\n");
    }
    return code;
    
}

int getnights(void)
{
    int nights;
    printf("На сколько суток вы бронируете номер ?");
    while(!scanf("%d",&nights))
    {
        scanf("%*s"); //исключение целочисленного ввода
        printf("Введите целое число, такое как 2.\n");
    }
    return nights;
}

void showprice (double rate,int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;
    for (n= 1;n <= nights; n++, factor *= DISNOUNT)
        total +=rate*factor;
    printf("Общая стоимоть составляет $%0.2f.\n",total);
}
