//
//  list3.c
//  chapter17
//
//  Created by пупсик on 17.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#include "list3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// прототип локальной функции
static void CopyToNode(Item item,List *plist);

//функции интерфейса
//устанавливае список в пустое состояние
void InitializeList(List *plist)
{
    for(int i = 0; i < MAXSIZE; ++i)
    {
        plist->entries[i].rating = 0.0;
        plist->entries[i].title[0] = '\0';
    }
    plist->items = 0;
}

//возвращает true если список пуст
bool ListIsEmpty(const List *plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

//возвращает true   если список полон
bool ListIsFull(const List *plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}

//возвращает количество узлов
unsigned int ListItemCount(const List *plist)
{
    return plist->items;
}

// создает узел для хранения элемента и добавляет его в конец списка указанного в переменной plist (медленная реализация
bool AddItem (Item item,List *plist)
{
    if (!ListIsFull(plist))
    {

        CopyToNode(item, plist);
        ++plist->items;
        return true;
    }
    else
        return false;
}
//посещает каждый узел и выполняет функцию, указанную pfun
void Traverse (const List *plist,void (*pfun) (Item item))
{
    for (int i = 0;i<plist->items; ++i)
        (*pfun)(plist->entries[i]); //применение функции к аргументу
 
}

//освобождает память выделенную функцией malloc()
//устанавливает указатель списка в NULL
void EmptyTheList(List *plist)
{
    for(int i = 0; i < MAXSIZE; ++i)
    {
        plist->entries[i].rating = 0.0;
        plist->entries[i].title[0] = '\0';
    }
    plist->items = 0;
}
//определение локальной фукнции - копирует элемент в узел
static void CopyToNode(Item item,List *plist)
{
    strcpy(plist->entries[plist->items].title,item.title);
    plist->entries[plist->items].rating = item.rating;
}


*/
