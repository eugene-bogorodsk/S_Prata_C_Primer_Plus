//
//  rand0.c
//  chapter12
//
//  Created by пупсик on 18.03.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//

//генерация случайных чисел используется переносимый алгоритм ANSI C
/*
static unsigned long int next = 1; // начальное число

int rand0(void)
{
    //магическия формула генерации псевдослучайных чисел
    next = next * 1103515245 +12345;
    return (unsigned int) (next/65536) % 32768;
}
*//*
//list_12_9 s_and_r.c генерация ф-ций rand1()  и srand()
static unsigned long int next = 1;

int rand1(void)
{
    next = next * 1103515245 +12345;
    return (unsigned int) (next/65536) % 32768;
}

void srand1 (unsigned int seed)
{
    next = seed;
}
*/
