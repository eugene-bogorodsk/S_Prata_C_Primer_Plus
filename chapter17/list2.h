//
//  list2.h
//  chapter17
//
//  Created by пупсик on 17.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#ifndef list2_h
#define list2_h

#include <stdio.h>
#include <stdbool.h>

#define TSIZE 45 //размер массива для хранения названия
#define MAXSIZE 100
struct film
{
    char title[TSIZE];
    int rating;
};

//определение общих типов
typedef struct film Item;
typedef struct node
{
    Item item;
    struct node *next;
} Node;
//typedef Node* List;

//переопределяем List в соответствии с заданием 2
typedef struct list
{
    Node *head; //указывает на начало списка
    Node *end; //указывает на коенц списка
} List;

//прототипы функций
//оперкация: инициализация списка
//предусловаия: plist указывает на список
//постусловаия: список инициализирован пустым содержимым
void InitializeList(List *plist);

//операция: определение является ли список пустым
//plist указывает на инициализированный список
//постусловия: функция возвращает значение True если список пуст и False и противном случае
bool ListIsEmpty(const List *plist);

//операция: определение является ли список полным
//plist указывает на инициализированный список
//постусловаия: функция возвращает значение  True если список полон   и False в противном случае
bool ListIsFull(const List *plist);

//операция: определение количества элементов в списке
// plist указывает на инициализированный список
//постусловия: функция возвращает число элементов в списке
unsigned int ListItemCount(const List *plist);

//операция: добавление элемента в конец списка
//предусловие:item - элемент, добавляемый с список plist указывает на инициализированный список
//постусловия: если возможно, функция добавляет элемент в конец списка и возвращает значение True в противном случае возвращает значение  False
bool AddItem(Item,List *plist);

//операция: применение функции к каждому элементу списка plistуказывает на инициализированный список
// предусловие:pfun указывает на функцию которая принимает фргумент Item и не имеет возвращаемого значения
//постусловия: функция. указанная pfun выполняется один раз для каждого элмента в списке
void Traverse(const List *plist,void (*pfun) (Item item));

//операция: освобождение выделенной памяти, сели она есть
//    plist указывает на инициализированный список
//постусловия: любая память выделенная для списка освобождается и список устанвливается в пустое состояние
void EmptyTheList(List *plist);


#endif //list2_h
*/
