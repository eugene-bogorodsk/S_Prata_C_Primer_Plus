//
//  steck.c
//  chapter17
//
//  Created by пупсик on 18.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
//
/*
#include "steck.h"
#include <stdlib.h>

static void CopyFromItem(Item item,Stack *ps);
static void CopyToItem(Item *pitem,Stack *ps);


void InitializeStack(Stack *ps)
{
    for (int i = 0;i < MAXSTACK; ++i)
        ps->items[i]='\0';
    ps->top = 0;
}

bool FullStack(const Stack *ps)
{
    if (ps->top == MAXSTACK)
        return true;
    else
        return false;
}

bool EmptyStack(const Stack *ps)
{
    if (ps->top == 0)
        return true;
    else
        return false;
}

bool Push(Item item,Stack *ps)
{
    if (FullStack(ps))
    {
        puts("Стэк заполнен.\n");
        return false;
    }
    CopyFromItem(item, ps);
    
    return true;
}

bool Pop(Item *pitem,Stack *ps)
{
    if (EmptyStack(ps))
        return(false);
    else
    {
        CopyToItem(pitem,ps);
        return true;
    }
}
void CopyFromItem(Item item,Stack *ps)
{
    ps->items[ps->top] = item;
    ++ps->top;
}
void CopyToItem(Item *pitem,Stack *ps)
{
    *pitem = ps->items[ps->top-1];
    --ps->top;
}
*/
