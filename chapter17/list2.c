//
//  list2.c
//  chapter17
//
//  Created by пупсик on 17.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#include "list2.h"
#include <stdio.h>
#include <stdlib.h>

// прототип локальной функции
static void CopyToNode(Item item,Node *node);

//функции интерфейса
//устанавливае список в пустое состояние
void InitializeList(List *plist)
{
    plist->head = NULL;
    plist->end = NULL;
}

//возвращает true если список пуст
bool ListIsEmpty(const List *plist)
{
    if (plist->head == NULL)
        return true;
    else
        return false;
}

//возвращает true   если список полон
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;
    pt =(Node* )malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    
    return full;
}

//возвращает количество узлов
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;

    Node *pnode = plist->head; //установка в начало списка
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;//установка в следующий узел

    }
    
    
    return count;
}

// создает узел для хранения элемента и добавляет его в конец списка указанного в переменной plist (медленная реализация
bool AddItem (Item item,List *plist)
{
    Node *pnew;
    //Node *scan = *plist;
    
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false; // выход из функции в случае ошибки
    CopyToNode(item,pnew);
    pnew->next=NULL;
    if (plist->head == NULL) //список пуст поэтому поместить pnew в начало списка
    {
        plist->head = pnew;
        plist->end = pnew;
    }
    else
    {
        plist->end->next = pnew;
        plist->end = pnew;
       // while(scan->next != NULL)
        //    scan = scan->next; //поиск конца списка
       // scan->next=pnew; //добавляем pnew в конец
    }
    
    return true;
}
//посещает каждый узел и выполняет функцию, указанную pfun
void Traverse (const List *plist,void (*pfun) (Item item))
{
    Node *pnode = plist->head; //установка в начало списка
    while(pnode != NULL)
    {
        (*pfun)(pnode ->item); //применение функции к аргументу
        pnode = pnode->next;
    }
}

//освобождает память выделенную функцией malloc()
//устанавливает указатель списка в NULL
void EmptyTheList(List *plist)
{
    Node *psave=plist->head;
    while (psave->next != NULL)
    {
        psave = plist->head->next;// сохраняет адрес следующего узла
        free(plist->head); //освобождение текущего узла
        plist->head = psave; //переход к следующему узлу
    }
}
//определение локальной фукнции - копирует элемент в узел
static void CopyToNode(Item item,Node *pnode)
{
    pnode ->item = item; //копирование структуры
}

*/
