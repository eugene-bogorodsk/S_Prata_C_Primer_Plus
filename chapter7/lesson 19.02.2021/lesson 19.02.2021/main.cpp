//
//  main.cpp
//  lesson 19.02.2021
//
//  Created by пупсик on 19.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#include <iostream>
using namespace std;
const int Day = 7;

int main()
{
    const char *arrptrs [Day] {"Пон", "Втор", "Сред", "Чет", "Пят", "Суб", "Вос"};
    for (int i = 0; i<Day; i++)
    {
        cout<<arrptrs[i]<<endl;
    }
    return 0;
}


#include <iostream>
#include <ctype.h>
using namespace std;
bool comparission(const char *);
int main()
{
    char t[250]="В7л7су7родла7сь7е7лочкаа";
    cout<<comparission(t)<<endl;
    cout<<strlen(t)<<endl;
}
bool comparission(const char* t )
{
  int sum = 0;
    for(int i=0; i<strlen(t); i++)
    {
        if(isdigit(t[i]))
            sum+=(int)t[i]-48;
    }
    return sum==strlen(t);
}
*/

#include <iostream>

using namespace std;
bool foo(const int arr[] ,int);
int main()
{
    const int n = 3;
    const int arr [n][3]={
        {1,4,6},
        {5,2,5},
        {8,6,4},
    };
    for(int i=0; i<n; i++)
    {
        if(foo(arr[i],n))
           cout<<i<<endl;
    
    
    }
    return 0;
}
bool foo(const int arr[],int size)
{
    
    
    int cntp=1 ,cntn = 1; //устав счетчики для монот возраст и убыв послед
    for (int i=1; i<size; i++)
    {
        if(arr[i]>=arr[i-1])
            cntp++;
        else if (arr[i]<=arr[i-1])
            cntn++;
    }

    return ((cntp == size) or (cntn == size));
}

