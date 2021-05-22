//
//  pe12-2a.c
//  chapter12
//
//  Created by пупсик on 31.03.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#include "pe12-2a.h"

int  set_mode(int _mode)
{
    int mode = _mode;
    if (mode != 0 && mode !=1)
    {
        printf("Указан недопустимый режим. Используется режим 1 (американский).\n");
        mode =1;
    }
    return mode;
}

float get_Distance(int mode)
{
    float distance;
    if (mode == 0)
    {
        printf("Введите пройденной расстояние в км:");

    }
    else if (mode ==1)
    {
            printf("Введите пройденной расстояние в милях:");
    }
    scanf("%f",&distance);
    
    return distance;

}
float get_Expend(int mode)
{
    float expend;
    if (mode == 0)
     {
         printf("Введите объем израсходованного топлива в литрах:");
         
     }
     else if (mode ==1)
     {
         printf("Введите объем израсходованного топлива в галлонах:");
     }
    scanf("%f",&expend);
     
    return expend;

}
void show_info(float distance,float expend,int mode)
{
        float res;
        if (mode == 0)
        {
            res = expend*100/distance;
            printf("Расход топлива составляет %1.1f литров на 100 км.\n",res);
        }
        else if ( mode== 1)
        {
            res = distance/expend;
            printf("Расход топлива составляет %1.1f мили на галлон.\n",res);
        }
    
}
*/
/*
static int _mode;
static float _distance;
static float _expende;

void set_mode(int mode)
{
    _mode = mode;
}

void get_info(void)
{
    if (_mode == 0)
    {
        printf("Введите пройденной расстояние в км:");
        scanf("%f",&_distance);
        printf("Введите объем израсходованного топлива в литрах:");
        scanf("%f",&_expende);
    }
    else if (_mode ==1)
    {
        american_regim();
    }
    else
    {
        printf("Указан недопустимый режим. Используется режим 1 (американский).\n");
        american_regim();
    }
}
void show_info(void)
{
    float res;
    if (_mode == 0)
    {
        res = _expende*100/_distance;
        printf("Расход топлива составляет %1.1f литров на 100 км.\n",res);
    }
    else if (_mode == 1)
    {
        res = _distance/_expende;
        printf("Расход топлива составляет %1.1f мили на галлон.\n",res);
    }
}

void american_regim(void)
{
    printf("Введите пройденной расстояние в милях:");
    scanf("%f",&_distance);
    printf("Введите объем израсходованного топлива в галлонах:");
    scanf("%f", &_expende);
}
*/
