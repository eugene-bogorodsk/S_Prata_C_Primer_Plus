//
//  tree8.c
//  chapter17
//
//  Created by пупсик on 21.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//

#include "tree8.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//локальный тип данных
typedef struct pair {
    Trnode *parent;
    Trnode *child;
}Pair;

//прототипы локальных функций
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1,const Item *i2);
static bool ToRight(const Item *i1,const Item *i2);
static void AddNode(Trnode *new_node,Trnode *root);
static void InOrder(const Trnode *root,void (*pfin)(Item item));
static Pair SeekItem(const Item *pi,const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);


//определение функций
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    if(ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree *ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}
// модификация AddItem под упражнение 7
bool AddItem(const Item *pi,Tree *ptree)
{
    if (SeekItem(pi,ptree).child != NULL)
    {
        //записыаем новый тип животного в следующую ячейку массива petkind
        strcpy(SeekItem(pi, ptree).child->item.petkind[pi->count],pi->petkind[0]);
        SeekItem(pi,ptree).child->item.count += pi->count;//увеличиваем на 1 количество животных с одинаковой кличкой
        ++ptree->size;//увеличиваем количество животных в списке
        
        return true;
    }
    else
    {
        Trnode *new_node;
     
        if (TreeIsFull(ptree))
        {
            fprintf(stderr,"Дерево переполненно\n");
            return false; //преждевременный возврат
        }
   
        new_node = MakeNode(pi); //указывает на новый узел
        if (new_node == NULL)
        {
            fprintf(stderr,"Не удалось создать узел\n");
            return false; //преждевременный возврат
        }
        //успешное создание нового узла
        ptree->size++;
        
        if (ptree->root == NULL) //случай 1: дерево пустое
            ptree -> root = new_node; //новый узел - корень дерева
        else //случай2: дерево не пустое
            AddNode(new_node,ptree->root);// добавление узла к дереву
        return true;//возврат в случае успеха
        }
}
/*
bool AddItem(const Item *pi,Tree *ptree)
{
    Trnode *new_node;
    
    if (TreeIsFull(ptree))
    {
        fprintf(stderr,"Дерево переполненно\n");
        return false; //преждевременный возврат
    }
    if (SeekItem(pi,ptree).child != NULL)
    {
        fprintf(stderr,"Попытка добавления дублированного элемента\n");
        return false; //преждевременный возврат
    }
    new_node = MakeNode(pi); //указывает на новый узел
    if (new_node == NULL)
    {
        fprintf(stderr,"Не удалось создать узел\n");
        return false; //преждевременный возврат
    }
    //успешное создание нового узла
    ptree->size++;
    
    if (ptree->root == NULL) //случай 1: дерево пустое
        ptree -> root = new_node; //новый узел - корень дерева
    else //случай2: дерево не пустое
        AddNode(new_node,ptree->root);// добавление узла к дереву
    return true;//возврат в случае успеха
}
*/
bool InTree(const Item *pi,const Tree *ptree)
{
    return (SeekItem(pi,ptree).child == NULL) ? false:true;
}
/*
//добавлено для решения задания 7
int CountOfWords(const Item *pi,const Tree *ptree)
{
    return (SeekItem(pi,ptree).child == NULL) ? 0:SeekItem(pi, ptree).child->item.count;
}
*/
//добавляем для решения задания 8 функцию возвращающую найденное значение Item

Item FindPet (const Item *pi,const Tree *ptree)
{
    return SeekItem(pi,ptree).child ->item;
}

bool DeleteItem(const Item *pi,Tree *ptree)
{
    Pair look;
    look = SeekItem(pi,ptree);
    if (look.child == NULL)
        return false;
    if (look.child->item.count ==1)
    {
        if (look.parent == NULL) //удаление корневого элемента
            DeleteNode(&ptree->root);
        else if (look.parent -> left == look.child)
            DeleteNode(&look.parent -> left);
        else
            DeleteNode(&look.parent -> right);
        --ptree->size;
        
         return true;
    }
    else
    {
        for (int i = 0;i<look.child->item.count;++i)
            if (strcmp(look.child->item.petkind[i], pi->petkind[0]) == 0)
            {
                for (int j =i;j<look.child->item.count-1;++j)
                    strcpy(look.child->item.petkind[i], look.child->item.petkind[i+1]);
                --look.child->item.count;
                --ptree->size;
                return true;
            }
        return false;
    }
}
void Traverse(const Tree *ptree,void (*pfun) (Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root,pfun);
}
void DeleteAll(Tree *ptree)
{
    if(ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}
//локальные функции
static void InOrder(const Trnode *root,void(*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder (root->left,pfun);
        (*pfun)(root->item);
        InOrder (root ->right,pfun);
    }
}
static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}
static void AddNode(Trnode * new_node,Trnode *root)
{
    if (ToLeft (&new_node->item,&root->item))
    {
     if (root->left == NULL)
         root->left = new_node;
        else
            AddNode(new_node,root->left);
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if(root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node,root->right);
    }
    else
    {
        fprintf(stderr,"Ошибка местоположения в AddNode()\n");
        exit(1);
    }
}


static bool ToLeft(const Item *i1,const Item *i2)
{
    int comp1;
    if ((comp1 = strcmp(i1->petname,i2->petname)) < 0)
        return true;
   // else if (comp1 == 0 && strcmp(i1->petkind,i2->petkind) < 0) //нет необходимости искать животное до вида так как будем выводить все виды с этой кличкой
   //     return true;
    else
        return false;
}

static bool ToRight(const Item *i1,const Item *i2)
{
    int comp1;
    if((comp1 = strcmp(i1->petname,i2->petname))> 0)
        return true;
  //  else if (comp1 == 0 && strcmp(i1->petkind,i2->petkind) > 0)
 //       return true;
    else
        return false;
}

static Trnode *MakeNode(const Item *pi)
{
    Trnode *new_node;
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekItem(const Item *pi,const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    
    if (look.child == NULL)
        return look; //преждевременный возврат
    
    while (look.child !=NULL)
    {
        if (ToLeft(pi,&(look.child->item)))
        {
            look.parent=look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent=look.child;
            look.child = look.child->right;
        }
        else //если элемент расположен не слева ни справа од должен быть таким же  look.chld - это адрес узла содержащего элемент
            break;
    }
    return look; // возврат в случае успеха
}

static void DeleteNode(Trnode **ptr)
//адрес родительского элемента указывающего на целевой узел
{
    Trnode *temp;
    if ((*ptr) -> left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else //удалаемый узел имеет два дочерних узла
    {
        //выяснение присоединения правого поддерева
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}
