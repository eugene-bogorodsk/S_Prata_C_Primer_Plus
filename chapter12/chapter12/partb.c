//
//  partb.c
//  chapter12
//
//  Created by пупсик on 17.03.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#include <stdio.h>

extern int count; //ссылочное объявление, внешнее связывание

static int total = 0;//статическое определение, внутреннее связывание
void accumulate(int k);//прототип

void accumulate(int k) //k имеет область видимости в пределах блока, связывание отсутствует
{
    static int subtotal = 0; //статическая переменная, связывание отсутствует
    if (k <= 0)
    {
        printf("  итерация цикла:%d\n",count);
        printf("subtotal:%d; total:%d\n",subtotal,total);
        subtotal = 0;
    }
    else
    {
        subtotal +=k;
        total += k;
    }
}
*/
