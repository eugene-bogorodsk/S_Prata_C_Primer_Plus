//
//  steck.h
//  chapter17
//
//  Created by пупсик on 18.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#ifndef steck_h
#define steck_h

#include <stdio.h>
#include <stdbool.h>

typedef char Item;
#define MAXSTACK 100

typedef struct stack
{
    Item items[MAXSTACK]; //содержит сведения о стеке
    int top; //индекс первой пустой ячейки
} Stack;

//операция: инициализация стэка
//предусловия:ps указывает на стэк
//постусловия:стэк инициализирован пустым значением
void InitializeStack(Stack *ps);
 
//операция: проверяет является ли стэк полным
//предусловия:ps указывает на ранее инициализированный стэк
//постусловия: возвращает true если стэк полный иначе возвращает false
bool FullStack(const Stack *ps);

//операция: проверяет является ли стэк пустым
//предусловия: ps указывает на иницициализированный стэк
//постусловия:возвращает true если стэк пустой иначе возвращает false
bool EmptyStack(const Stack *ps);


//операция: заталкиваем элемент в стэк
//предусловия:ps указывает на ранее инициализированный стэк элемент должен помещаться в верхушку стэка
//постусловия: если стэк не полон элемент помещается в верхушку стека и фукнция возвращает значение true иначе стэк остается неизменным а функция возвращает false
bool Push(Item item,Stack *ps);

//операция: удаляет жлемент из верхушки стека
//предусловия:ps указывает на инициализированный стэк
//постусловия: если стэк не пуст элемент в верхушке стэка поируется в  *pitem и удаляется из стека а функция возвращает значение true если операци опустошает стэк стэк переустанавливается в пустое состояние Если стэк пуст с самого начала он остается неизменным а функция возвращает false
bool Pop(Item *pitem,Stack *ps);

#endif // steck_h
*/