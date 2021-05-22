//
//  names_st.c
//  chapter16
//
//  Created by пупсик on 07.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#include <stdio.h>
#include "names_st.h"
//определения функций
void get_names(names *ps)
{
    printf("Введите свое имя:");
    s_gets(ps -> first,SLEN);
    
    printf("Введите свою фамилию: ");
    s_gets(ps -> last,SLEN);
}

void show_names(const names *pn)
{
    printf("%s %s", pn->first,pn->last);
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    char *find;
    
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        find = strchr(st,'\n');
        if (find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    
    return ret_val;
}
*/
