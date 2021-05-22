//
//  main.c
//  chapter14
//
//  Created by пупсик on 13.04.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_14_1 каталог для книг
#include <stdio.h>
#include <string.h>
char *s_gets(char *st,int n);
#define MAXTITL 41 //максимальная длина названия
#define MAXAUTL 31 //максимальная длина имени автора

struct book{ //шаблон структуры, дескриптором является  book
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
}; //конец объявления

int main(void) {
    
    struct book library; //объявление library в качестве переменной типа book
    
    printf("Введите название книги.\n");
    s_gets(library.title,MAXTITL); //доступ к разделу названия книги
    printf("Теперь введите ФИО автора.\n");
    s_gets(library.author,MAXAUTL);
    printf("Теперь введите цену.\n");
    scanf("%f",&library.value);
    printf("%s авторства %s: $%.2f\n",library.title,library.author,library.value);
    printf("%s: \"%s\" ($%.2f)\n",library.author,library.title,library.value);
    printf("Готово!\n");
    
    return 0;
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
                ;
    }
    return ret_val;
}
 *//*
//list_14_2 каталог для нескольких книг
#include<stdio.h>
#include<string.h>
char *s_gets(char *st,int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 //максимальное количество книг

struct book{ // установка шаблона структуры
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main(void)
{
    struct book library[MAXBKS]; //массив структур типа book
    int count = 0;
    int index;
    
    printf("Введите название книги.\n");
    printf("Нажмите enter в начале строки, чтобы закончить ввод.\n");
    while (count <MAXBKS && s_gets(library[count].title,MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Теперь введите ФИО автора.\n");
        s_gets(library[count].author,MAXAUTL);
        printf("Введите цену.\n");
        scanf("%f",&library[count++].value);
        while (getchar() !='\n')
            ; //очистить входную строку
        if (count <MAXBKS)
            printf("Введите название следующей книги\n");
    }
    if (count > 0)
    {
        printf("Каталог ваших книг.\n");
        for (index = 0;index<count;++index)
            printf("%s авторство %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
    }
    else
        printf("Вообще нет книг? Очень плохо.\n");
    
    return 0;
}
char *s_gets(char *st,int n)
{
    char * ret_val;
    char *find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st,'\n');
        if (find)
            *find = '\0';
        else
            while(getchar() !='\n')
                ;
    }
    return ret_val;
}
*//*
//list_14_3 пример вложенной структуры
#include<stdio.h>
#define LEN 40

const char* msgs[5]=
{
    "Благодарю вас за чудесный вечер,",
    "Вы однозначно продемонстрировали, что ",
    " являет собою особый тип мужчины. Мы обязательно должны встретиться",
    "за восхитительным ужином с ",
    " и весело провести время."
};

struct names{ //первая структура
    char first[LEN];
    char last[LEN];
};

struct guy{
    struct names handle; //вложенная структура
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow={ //инициализация переменной
        {"Билли","Бонс"},
        "запеченными омарами",
        "персональный тренер",
        68112.00
    };
    printf("Дорогой %s,\n\n",fellow.handle.first);
    printf("%s%s\n",msgs[0],fellow.handle.first);
    printf("%s%s",msgs[1],fellow.job);
    printf("%s\n",msgs[2]);
    printf("%s%s%s",msgs[3],fellow.favfood,msgs[4]);
    if (fellow.income > 150000.0)
        puts("!!");
    else if (fellow.income > 75000)
        puts("!");
    else
        puts(".");
    printf("\n%40s%s\n"," ","До скорой встречи,");
    printf("%40s%s\n"," ","Шейла");
           
    return 0;
}
*//*
//list_14_4 указатели на структуры
#include<stdio.h>
#define LEN 40

const char* msgs[5]=
{
    "Благодарю вас за чудесный вечер,",
    "Вы однозначно продемонстрировали, что ",
    " являет собою особый тип мужчины. Мы обязательно должны встретиться",
    "за восхитительным ужином с ",
    " и весело провести время."
};

struct names{ //первая структура
    char first[LEN];
    char last[LEN];
};

struct guy{
    struct names handle; //вложенная структура
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow[2]={

        {{"Билли","Бонс"},
        "запеченными омарами",
        "персональный тренер",
        68112.00
         },
        {{"Джим","Хокинс"},
        "рыбным фрикасе",
        "редактор таблоида",
        232400.00
        }
    };
    
    struct guy *him; //указатель на структуру
    
    printf("адрес #1:%p #2: %p\n",&fellow[0],&fellow[1]);
    him = &fellow[0]; //сообщение указателю на что указывать
    printf("адрес #1:%p #2: %p\n",him,him+1);
    printf("him->income = $%.2f: (*him).income = $%.2f\n",him->income,(*him).income);
    him++; //указатель на следующую структуру
    printf("him->favfood = %s: him->handle.last = %s\n",him->favfood,him->handle.last);
           
    return 0;
}
*//*
//list_14_5 передача членов структуры в качестве аргументов
#include <stdio.h>
#define FUNDLEN 50

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum(double,double);
int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Общая сумма на счетах у Стэна составляет $%.2f.\n",sum(stan.bankfund,stan.savefund));
    
    return 0;
}
//суммирование двух чисел типа double
double sum(double x,double y){
    return x+y;
}
*//*
//list_14_6 передача указателя на структуру
#include <stdio.h>
#define FUNDLEN 50

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum(const struct funds *);//аргумент является указателем
int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Общая сумма на счетах у Стэна составляет $%.2f.\n",sum(&stan));
    
    return 0;
}
//суммирование двух чисел типа double
double sum(const struct funds *money){
    return money->bankfund+money->savefund;

}
*//*
//list_14_7 передача структуры в качестве аргумента
#include <stdio.h>
#define FUNDLEN 50

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum(struct funds moolah);//аргумент является указателем
int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Общая сумма на счетах у Стэна составляет $%.2f.\n",sum(stan));
    
    return 0;
}
//суммирование двух чисел типа double
double sum(const struct funds moolah){
    return moolah.bankfund+moolah.savefund;

}
   *//*
//list_14_8 обработка структуры при помощи указателей
#include <stdio.h>
#include <string.h>
#define NLEN 30

struct namect{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo (const struct namect *);
char *s_gets(char *st,int n);

int main(void)
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    return 0;
}
void getinfo(struct namect *pst)
{
    printf("Введите свое имя.\n");
    s_gets(pst -> fname,NLEN);
    printf("Введите свою фамилию.\n");
    s_gets(pst -> lname,NLEN);
}
void makeinfo(struct namect *pst)
{
    pst->letters =(int)(strlen(pst -> fname) + strlen(pst -> lname));
}
void showinfo (const struct namect *pst)
{
    printf("%s %s, ваше имя и фамилия содержат %d букв.\n",pst -> fname,pst -> lname, pst -> letters);
}
char *s_gets(char *st,int n)
{
    char *rev_val;
    char *find;
    
    rev_val = fgets(st, n, stdin);
    if (rev_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                   ;
    }
    return rev_val;
}
      *//*
//list_14_9  использование структур как аргументов
#include <stdio.h>
#include <string.h>
#define NLEN 30

struct namect{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};
struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo (const struct namect);
char *s_gets(char *st,int n);

int main(void)
{
    struct namect person;
    person = getinfo();
    person = makeinfo(person);
    showinfo(person);
    return 0;
}
struct namect getinfo(void)
{
    struct namect temp;
    printf("Введите свое имя.\n");
    s_gets(temp.fname,NLEN);
    printf("Введите свою фамилию.\n");
    s_gets(temp.lname,NLEN);
    
    return temp;
}
struct namect makeinfo(struct namect info)
{
    info.letters =(int)(strlen(info.fname) + strlen(info.lname));
    
    return info;
}
void showinfo (const struct namect info)
{
    printf("%s %s, ваше имя и фамилия содержат %d букв.\n",info.fname,info.lname, info.letters);
}
char *s_gets(char *st,int n)
{
    char *rev_val;
    char *find;
    
    rev_val = fgets(st, n, stdin);
    if (rev_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                   ;
    }
    return rev_val;
}
*//*
//ex_14_10 name3.c использование указателей и malloc()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 81

struct namect { //использование указателей
    char *fname;
    char *lname;
    int letters;
};

void getinfo(struct namect *); //выделение памяти
void makeinfo (struct namect *);
void showinfo (const struct namect *);
void cleanup (struct namect *); //освобождение памяти, когда она больше не нужна
char *s_gets (char *st, int n);

int main(void)
{
    struct namect person;
    
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    
    return 0;
}

void getinfo (struct namect *pst)
{
    char temp[SLEN];
    printf("Введите своё имя.\n");
    s_gets(temp,SLEN);
    
    //выделение памяти для хранения имени
    pst->fname = (char *) malloc(strlen(temp)+1);
    
    //копирование имени в выделенню память
    strcpy(pst->fname,temp);
    printf("Введите свою фамилию.\n");
    s_gets(temp,SLEN);
    pst->lname = (char *) malloc(strlen(temp)+1);
    strcpy(pst->lname,temp);
}

void makeinfo (struct namect *pst)
{
    pst->letters = (int)(strlen(pst->fname)+strlen(pst->lname));
}

void showinfo (const struct  namect *pst)
{
    printf("%s %s, ваше имя и фамилия содержит %d букв.\n", pst->fname,pst->lname,pst->letters);
}

void cleanup (struct namect *pst)
{
    free (pst->fname);
    free (pst->lname);
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n'); //поиск новой строки
        if (find)               //если адрес не равен NULL
            *find = '\0';       //поместить туда нулевой символ
        else
            while (getchar() !='\n')
                ;
    }
    return ret_val;
}
*//*
//ex_14_11 complit.c составные литералы
#include <stdio.h>
#define MAXTITL 61
#define MAXAUTL 51

struct book{ //шаблон структуры: book десприптор
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book readfirst;
    int score;
    printf("Введите рейтинг: ");
    scanf("%d",&score);
    if(score >= 84)
        readfirst = (struct book){"Преступление и наказание",
            "Фёдор Достоевский",
            11.25 };
    else
        readfirst = (struct book){"Красивая шляпа мистера Брауна",
            "Фред Уинсом", 5.99};
    
    printf("Назначенные Вами рейтинги:\n");
    printf("%s by %s: $%.f\n",readfirst.title,readfirst.author,readfirst.value);
    
    return 0;
}
*//*
//list_14_12
#include <stdio.h>
#include <stdlib.h>

struct flex
{
    size_t count;
    double average;
    double scores[]; // поле с типом гибкого массива
};
void showFlex(const struct flex *p);
int main(void)
{
    struct flex *pf1,*pf2;
    int n = 5;
    int i;
    int tot = 0;
    
    //выделение памяти для структуры и массива
    pf1 = malloc(sizeof(struct flex) + n*sizeof(double));
    pf1->count = n;
    for (i = 0;i < n; i++)
    {
        pf1->scores[i] = 20.0 - i;
        tot +=pf1 -> scores[i];
    }
    pf1 -> average = tot/n;
    showFlex(pf1);
    n = 9;
    tot = 0;
    pf2 = malloc(sizeof(struct flex) + n*sizeof(double));
    pf2 -> count = n;
    for (i = 0;i < n;++i)
    {
        pf2 -> scores[i] = 20.0 - i/2.0;
        tot += pf2 -> scores[i];
    }
    pf2 -> average = tot/n;
    showFlex(pf2);
    free(pf1);
    free(pf2);
    
    return 0;
}

void showFlex(const struct flex *p)
{
    int i;
    printf("Рейтинги:");
    for (i = 0; i < p -> count; ++i)
        printf("%g", p -> scores[i]);
    printf("\nСреднее значение :%g\n",p -> average);
}
   *//*
//list_14_13 funds4.c передача функции массива структур
#include<stdio.h>
#define FUNDLEN 50
#define N 2

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum (const struct funds money[], int n);
int main(void)
{
    struct funds jones[N] ={
        {
            "Garlic-Melon Bank",
            4032.27,
            "Lucky's Savings and Loan",
            8543.94
        },
        {
            "Honest Jack's Bank",
            3620.88,
            "Party Time Saving",
            3802.91
            
        }
    };
    
    printf("Общая сумма на счетах у Джонсов составляет $%.2f.\n", sum(jones,N));
    
    return 0;
}

double sum (const struct funds money[],int n)
{
    double total;
    int i;
    
    for (i = 0,total = 0; i < n; ++i)
        total += money[i].bankfund + money[i].savefund;
    
    return total;
}
*//*
//list_14_14  booksave.c сохранение содержимого структуры в файле
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 //максимальное количество книг
char *s_gets(char *,int);

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS]; //массив структур
    int count = 0;
    int index,filecount;
    FILE *pbooks;
    int size = sizeof (struct book);
    if ((pbooks = fopen("book.dat","a+b")) == NULL)
    {
        printf("Не удается открыть файл book.dat\n",stderr);
        exit(1);
    }
    rewind(pbooks); //переход в начало файла
    while (count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
    {
        if (count == 0)
            puts("Текущее содержимое файла book.dat:");
        printf("%s авторства %s: $%.2f\n",library[count].title,library[count].author,library[count].value);
        count++;
    }
    filecount = count;
    if (count ==MAXBKS)
    {
        fputs("Файл book.dat заполнен.", stderr);
        exit(2);
    }
    puts("Введите название новых книг.");
    puts("Нажмите [enter] в начале строки, чтобы закончить ввод.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Теперь введите имя автора.");
        s_gets(library[count].author,MAXAUTL);
        puts("Теперь введите цену книги.");
        scanf("%f",&library[count++].value);
        while (getchar() != '\n')
            ;
        if (count < MAXBKS)
            puts("Введите название следующей книги.");
    }
    if (count > 0)
    {
        puts("Каталог ваших книг");
        for (index = 0;index < count;++index)
            printf("%s авторства %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
        fwrite(&library[filecount], size, count-filecount, pbooks);
    }
    else
        puts("Совсем нет книг? Очень плохо.\n");
    puts("Программа завершена.\n");
    fclose(pbooks);
    
    return 0;
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
            while(getchar() !='\n')
                ;
    }
    return ret_val;
}
*//*
//list_14_15 enum.c использование перечислимых значений
#include <stdio.h>
#include <string.h> //для  strcmp(),strchr()
#include<stdbool.h>
char *s_gets (char *st,int n);
enum spectrum {red,orange,yellow,green,blue,violet};
const char* colors[] = {"red","orange","yellow","green","blue","violet"};
#define LEN 30

int main(void)
{
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;
    
    puts("Введите цвет (или пустую строку для выхода):");
    while (s_gets(choice,LEN) != NULL && choice[0] !='\0')
    {
        for (color = red;color <=violet; ++color)
        {
            if (strcmp(choice,colors[color]) == 0)
            {
                color_is_found = true;
                break;
            }
        }
        if (color_is_found)
            switch (color) {
                case red:
                    puts("Розы красные.");
                    break;
                case orange:
                    puts("Маки оранжевые.");
                    break;
                case yellow:
                    puts("Подсолнухи желтые.");
                    break;
                case green:
                    puts("Трава зелёная.");
                    break;
                case blue:
                    puts("Колокольчики синии.");
                    break;
                case violet:
                    puts("Фиалки фиолетовые.");
                    break;
            }
        else
            printf("Цвет %s неизвестен.\n",choice);
        color_is_found = false;
        puts("Введите следующий цвет (или пустую строку для выхода):");
    }
    puts("Программа завершена.");
    return 0;
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
            while(getchar() !='\n')
                ;
    }
    return ret_val;
}
*//*
//list_14_16 func_ptr.c использование указателей на функции
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char *s_gets(char *st,int n);
char showmenu(void);
void eatline(void); //читает до конца строки
void show(void (*fp) (char *),char *str);
void ToUpper(char *); //преобразует строку в верхний регистр
void ToLower (char *); //преобразует строку в нижний регстр
void Transpose (char*); //меняет местами регистры
void Dummy(char *); //оставляет строку неизменной

int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *); //указывает на функцию, которая имеет аргумент типа char* и ничего не возвращает
    pfun = Dummy;
    puts("Введите строку (пустая строка - выход из программы):");
    while (s_gets(line,LEN) !=NULL && line[0] != '\0')
    {
        while ((choice = showmenu()) != 'n')
        {
            switch (choice) { //оператор switch устанавливает указатель
                case 'u':
                    pfun = ToUpper;
                    break;
                case 'l':
                    pfun = ToLower;
                    break;
                case 't':
                    pfun = Transpose;
                    break;
                case 'o':
                    pfun = Dummy;
                    break;
                default:
                    break;
            }
            strcpy(copy,line); //сделать копию для show()
            show(pfun,copy); //использовать выбранную функцию
        }
        puts("Введите строку (пустая строка = выход из прораммы ):");
    }
    puts("Программа завершена.");
    
    return 0;
}

char showmenu(void)
{
    char ans;
    puts("Введите выбранный вариант из меню:");
    puts("u) нижний регистр             l) верхний регистр");
    puts("t) поменть местами регистры   o) исходный регистр");
    puts("n) следующая строка");
    ans = getchar();  //получить ответ
    ans = tolower(ans); //преобразовать в нижний регистр
    eatline(); //избавиться от оставшейся части строки
    
    while (strchr("ulton",ans) == NULL)
    {
        puts("Введите u, l, t, o или n:");
        ans = tolower(getchar());
        eatline();
    }
    return ans;
}

void eatline(void)
{
    while (getchar() != '\n')
        ;
}

void ToUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str);
        ++str;
    }
}

void ToLower(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        ++str;
    }
}

void Transpose (char * str)
{
    while(*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}
void Dummy (char *str)
{
    //оставляет строку неизменной
}

void show (void (*fp)(char* ), char* str)
{
    (*fp)(str); //применить выбранную функцию к str
    puts(str); //отобразить результат
}

char* s_gets(char *st,int n)
{
    char* ret_val;
    char* find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() !='\n')
                ;
    }
    return ret_val;
}
*//*
//hw 3_4_5
#include <stdio.h>

struct month {
    char name[20];
    char abr[10];
    int days;
    int n_n;
};

extern int cntDays(const struct month num_month[],int n);

int main(void)
{
    struct month year[12] = {
        {"Январь","янв",31,1},
        {"Февраль","фев",28,2},
        {"Март","мрт",31,3},
        {"Апрель","апр",30,4},
        {"Май","май",31,5},
        {"Июнь","июн",30,6},
        {"Июль","июл",31,7},
        {"Август","авг",31,8},
        {"Сентябрь","снт",30,9},
        {"Октябрь","окт",31,10},
        {"Ноябрь","ноя",30,11},
        {"Декабрь","дек",31,12}
    };
    return 0;
}
//имя массива является его адресом поэтому передаем в таком виде
int cntDays(const struct month num_month[],int n)
{
    int total,i;
    if (n < 1 && n > 12)
        return -1;
    else
    {
        for (i = 0,total = 0;i < n;++i) //i на 1 меньше номера месяца
        {
            total +=num_month->days;
            ++num_month;
        }
        return total;
    }
    
}*/
/*
//hw_10
#include <stdio.h>

struct gas {
    float distance;
    float gals;
    float mpg;
};

struct gas calcMPG(struct gas);
void calcMPG2(struct gas *);
int main(void)
{
    return 0;
}
struct gas calcMPG(struct gas gs)
{
    if (gs.gals > 0)
        gs.mpg = gs.distance/gs.gals;
    else
        gs.mpg = -1.0;
    
    return gs;
}

void calcMPG2(struct gas *gs)
{
    if (gs->gals > 0)
        gs->mpg = gs->distance/gs->gals;
    else
        gs->mpg = -1.0;
}
*/
/*
//ex_1 считаем количество дней по названию месяца
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct month {
    char name[20];
    char abr[10];
    int days;
    int n_n;
};

extern int cntDays(const struct month num_month[],char *);

int main(void)
{
    struct month year[12] = {
        {"January","jan",31,1},
        {"February","feb",28,2},
        {"March","mar",31,3},
        {"April","apr",30,4},
        {"May","may",31,5},
        {"June","jun",30,6},
        {"July","jul",31,7},
        {"August","aug",31,8},
        {"September","sep",30,9},
        {"October","oct",31,10},
        {"November","nov",30,11},
        {"December","dec",31,12}
    };
    
    puts("Введите название месяца");
    char name_month[20];
    scanf("%s",name_month);
    int period;
    if ((period = cntDays(year,name_month)) != -1)
        printf("%d\n",period);
    else
        printf("Что то пошло не так попробуйте ещё раз\n");
        
    return 0;
}
//имя массива является его адресом поэтому передаем в таком виде
int cntDays(const struct month num_month[],char *name_month)
{
    int total,i,n;
    bool fl = false;
    
    for (n=0;n < 12; ++n)
    {
        if (!strcmp(num_month[n].name,name_month))
        {
            fl=true;
            break;
        }

    }

    if (fl)
    {
        for (i = 0,total = 0;i <= n;i++) //i на 1 меньше номера месяца
        {
            total +=num_month[i].days;

           
        }
        return total;
    }
    else
        return -1;
}
*//*
//ex_2 считаем дни по месяцу году и дате месяцу
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> //для преобразования строки в число

struct month {
    char name[20];
    char abr[10];
    int days;
    int n_n;
};

extern int cntDays(const struct month num_month[],int month_per,int date_per,int year_per);
bool check_vis(int year_in);// проверяем високосность года
int check_month(const struct month num_month[],char*); //проверяем правильность ввода месяца
int check_date(const struct month num_month[], int , int ,int); //проверяем правильность ввода даты
void ToLower(char*);
int main(void)
{
    struct month year[12] = {
        {"january","jan",31,1},
        {"february","feb",28,2},
        {"Mmarch","mar",31,3},
        {"april","apr",30,4},
        {"may","may",31,5},
        {"june","jun",30,6},
        {"july","jul",31,7},
        {"august","aug",31,8},
        {"september","sep",30,9},
        {"october","oct",31,10},
        {"november","nov",30,11},
        {"december","dec",31,12}
    };
    
    puts("Введите датy месяц и год через пробел");
    char month_personal[20];
    int date_personal;
    int year_personal;
    int num_of_month;
    int num_of_date;
    
    while (scanf("%d %s %d",&date_personal,month_personal,&year_personal) != 3)
    {
        puts("Проверьте корректность ввода данных , например 10 may 1956 , и попробуйте ввести снова");
       

    }
    // printf("%d",atoi(month_personal));
    //проверяем правильность ввода месяца  и даты
    while ((num_of_month = check_month(year, month_personal)) == -1 || (num_of_date = check_date(year,num_of_month,date_personal,year_personal)) == -1)
    {
        puts("Проверьте дату и месяц и поробуйте ввести ещё раз.\n");
       // printf("%d %d", num_of_month,num_of_date);
        
        while (scanf("%d %s %d",&date_personal,month_personal,&year_personal) != 3)
        {
            puts("Проверьте корректность ввода данных , например 10 may 1956 , и попробуйте ввести снова");
            
        }
    }


    printf("От начала %d года до %d %s составляет %d дня(ей)\n",year_personal,date_personal,year[num_of_month].name,cntDays(year, num_of_month, num_of_date, year_personal));
        
    return 0;
}

void ToLower(char * st)
{
    while (*st)
    {
        *st = tolower(*st);
        ++st;
    }
}

bool check_vis(int year_in)
{
    if ((year_in %4 == 0 && year_in%100 !=0) || year_in%400 == 0)
        return true;
    else
        return false;
}

int check_date(const struct month num_month[], int num_of_month,int date, int year_t)
{
    int check_num = 0;
    

    if (num_of_month ==1 && check_vis(year_t))
        check_num = 29;
    else //(num_of_month !=1 && !check_vis(year_t))
        check_num =num_month[num_of_month].days;
    //printf("%d %d %d\n",date,check_num, num_of_month);
    if (date > 1 && date <= check_num)
        return date;
    else
        return -1;
}

int check_month(const struct month num_month[],char* name_month)
{
    int n;
    bool fl = false;
    bool dig = true;
    char temp[10];
    strcpy(temp, name_month);
    while(*name_month)
    {
        if (!isdigit(*name_month))
        {
            dig = false;
            break;
        }
        ++name_month;
    }
    
    if (dig)
    {
       // printf("%d\n",dig);
        n = atoi(temp);
        if (n > 1 && n <13)
            return n-1;
        else
        {
            printf("Проверьте месяц %d, кажется такого нет",n);
            return -1;
        }
    }
    else
    {
       // printf("%d\n",dig);
        ToLower(temp);
        for (n=0;n < 12; ++n)
            if (!strcmp(num_month[n].name,temp) || !strcmp(num_month[n].abr,temp))
            {
                fl=true;
                break;
            }

        if (fl)
            return n;
        else
            return -1;
    }
}
//имя массива является его адресом поэтому передаем в таком виде
int cntDays(const struct month num_month[],int month_per,int date_per,int year_per)
{
    int total,i;

        for (i = 0,total = 0;i < month_per;i++) //i на 1 меньше номера месяца

            total +=num_month[i].days;
    
    total += date_per;
    if (check_vis(year_per) && month_per > 1)
        ++total;

    return total;

}
*//*
//ex_3 
//list_14_2 каталог для нескольких книг
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char *s_gets(char *st,int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 //максимальное количество книг

struct book{ // установка шаблона структуры
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
void sort_name(struct book *[],int n);
void sort_price(struct book *[],int n);
int main(void)
{
    struct book library[MAXBKS]; //массив структур типа book
    struct book *pts [MAXBKS]; //массив указателей на структуру book
    
    int count = 0;
    int index;
    
    printf("Введите название книги.\n");
    printf("Нажмите enter в начале строки, чтобы закончить ввод.\n");
    while (count <MAXBKS && s_gets(library[count].title,MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        pts[count] = &library[count];//установке указателей на структуры массива
        printf("Теперь введите ФИО автора.\n");
        s_gets(library[count].author,MAXAUTL);
        printf("Введите цену.\n");
        scanf("%f",&library[count++].value);
        while (getchar() !='\n')
            ; //очистить входную строку
        if (count <MAXBKS)
            printf("Введите название следующей книги\n");
    }
    if (count > 0)
    {
        printf("Каталог ваших книг.\n");
        for (index = 0;index<count;++index)
            printf("%s авторство %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
        
        puts("\n");
        sort_name(pts, count);
        printf("Каталог ваших книг в алфавитном порядке по названию.\n");
        for (index = 0;index<count;++index)
            printf("%s авторство %s: $%.2f\n",pts[index]->title,pts[index]->author,pts[index]->value);
        
        puts("\n");
        sort_price(pts, count);
        printf("Каталог ваших книг по цене.\n");
        for (index = 0;index<count;++index)
            printf("%s авторство %s: $%.2f\n",pts[index]->title,pts[index]->author,pts[index]->value);
    }
    else
        printf("Вообще нет книг? Очень плохо.\n");
    
    return 0;
}

void sort_price(struct book *ptl[],int n)
{
    struct book *temp;
    bool not_sorted=true;
    while (not_sorted)
    {
        not_sorted = false;
        for (int i = 0;i < n;++i)
            if (ptl[i]->value > ptl[i+1]->value)
            {
                temp = ptl[i];ptl[i]=ptl[i+1];ptl[i+1]=temp;
                not_sorted = true;
            }
        
    }
    
}

void sort_name(struct book *pt[],int n)
{
    struct book *temp;
    bool not_sorted = true;
    while (not_sorted)
    {
        not_sorted = false;
        for (int i = 0; i < n-1; ++i)
            if (strcmp(pt[i]->title,pt[i+1]->title)>0)
            {
                temp = pt[i]; pt[i]=pt[i+1]; pt[i+1]=temp;
                not_sorted =true;
            }
                
    }
        
}
char *s_gets(char *st,int n)
{
    char * ret_val;
    char *find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st,'\n');
        if (find)
            *find = '\0';
        else
            while(getchar() !='\n')
                ;
    }
    return ret_val;
}
*//*
//ex_4
#include <stdio.h>
#define N 5
struct name {
    char fname[20];
    char lname[20];
    char farther_name[20];
};

struct member {
    int num_ID;
    struct name person;
};

void show_member(struct member* );
void show_member_b(struct member );
int main(void)
{
    struct member first_group[N] = {
        {12001,{"Martin","Iden"}},
        {12191,{"Leonardo","DeCaprio"}},
        {12315,{"Steven","Seagal","Frederic"}},
        {12400,{"Uma","Thurma","Karuna"}},
        {12521,{"Oliver","Stone","William"}}
    };
    
    for (int i = 0;i < N;++i)
        show_member(&first_group[i]);
    printf("\n");
    
    for (int i = 0;i < N;++i)
        show_member_b(first_group[i]);
    
    return 0;
}

void show_member(struct member*  gr)
{
    char fm[3] ={gr->person.farther_name[0],'.','\0'};
    
    if (gr->person.farther_name[0] =='\0')
        fm[0]='\0';

    printf("%s, %s %s-- %d\n",gr->person.lname,gr->person.fname,fm,gr->num_ID);
}

void show_member_b(struct member mb)
{
    char fm[3] ={mb.person.farther_name[0],'.','\0'};
    
    if (mb.person.farther_name[0] =='\0')
        fm[0]='\0';

    printf("%s, %s %s-- %d\n",mb.person.lname,mb.person.fname,fm,mb.num_ID);
}
*//*
//ex_5
#include <stdio.h>
#define SIZE 2
struct name {
    char fname[10];
    char lname[15];
};

struct student {
    struct name nameOfSt;
    double grade[3];
    double meanGrade;
};

void set_grades(struct student []);
void get_mean_grade(struct student[]);
void show_students(struct student[]);

int main(void)
{
    struct student Students[SIZE];

    set_grades(Students);
    get_mean_grade(Students);
    show_students(Students);
    
    return 0;
}
void set_grades(struct student std[])
{
    for (int i = 0;i < SIZE; ++i)
    {
        puts("Введите имя и фамилию студента");
        while (scanf("%s %s",std[i].nameOfSt.fname,std[i].nameOfSt.lname) != 2)
            puts("Что то пошло не так, попробуйте еще раз");
        puts("Введите оценки студента по трем предметам через пробел");
        while(scanf("%lf %lf %lf",&std[i].grade[0],&std[i].grade[1],&std[i].grade[2]) !=3)
            puts("Что то пошло не так повторите ввод");
    }
}

void get_mean_grade(struct student std[])
{
    for (int i = 0;i < SIZE; ++i)
    {
        std[i].meanGrade =(std[i].grade[0]+std[i].grade[1]+std[i].grade[2])/3;
    }
}

void show_students(struct student std[])
{
    double total_grade=0;
    puts("Данные по курсу:\n");
    puts("       Фамилия         Имя   Оценка1 Оценка2 Оценка3 Среднее\n");
    for (int i = 0;i < SIZE; ++i){
        printf("%15s %10s  %6.2lf %6.2lf %7.2lf  %6.2lf\n", std[i].nameOfSt.lname,std[i].nameOfSt.fname,std[i].grade[0],std[i].grade[1],std[i].grade[2],std[i].meanGrade);
        total_grade +=std[i].meanGrade;
    }
    
    puts("------------------------------");
    printf("Среднее значение по курсу:%.2lf\n",total_grade/SIZE);
}
*//*
//ex_6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define TEAM 16+1

struct player {
    int num_pp;
    char fname[10];
    char lname[15];
    double catches;
    double hits;
    double run;
    double home_run;
    int num_of_plays;
};
int main(void)
{
    struct player team[TEAM];
    for ( int i = 0;i < TEAM; ++i)
    {
        team[i].num_pp = 0;
        team[i].fname[0] = '\0';
        team[i].lname[0] = '\0';
        team[i].catches = 0;
        team[i].hits = 0;
        team[i].run = 0;
        team[i].home_run = 0;
        team[i].num_of_plays = 0;
        
    }
    
    int _num_pp;
    char _fname[10], _lname[15];
    double _catches, _hits, _run, _home_run;
    
    FILE *fp;
    if ((fp = fopen("/Users/pupsik/Library/Developer/Xcode/DerivedData/chapter14-abyglkuvxiphgthflxozrjttbjal/Build/Products/Debug/SeaDeavels.txt","r")) == NULL)
    {
        fputs("Не получается открыть файл.\n",stderr);
        exit(1);
    }
    rewind(fp); //переходим в начало файла

    while (fscanf(fp, "%d %s %s %lf %lf %lf %lf",&_num_pp,_fname,_lname,&_catches,&_hits,&_run,&_home_run) == 7)
    {
        team[_num_pp].num_pp = _num_pp;
        ++team[_num_pp].num_of_plays;
        strcpy(team[_num_pp].fname, _fname);
        strcpy(team[_num_pp].lname, _lname);
        team[_num_pp].catches += _catches;
        team[_num_pp].hits += _hits;
        team[_num_pp].run += _run;
        team[_num_pp].home_run += _home_run;
        
    }
    puts("Статистика по команде Морские Дьяволы");
    puts("#        Name      LName  Catches  Hits   Run   Home_Run");
    double team_catches,team_hits,team_run,team_home_run;
    team_catches = team_hits = team_run = team_home_run =0.0;
    int cnt = 0;
    
    for (int i = 0; i < TEAM; ++i)
        if (team[i].num_pp != 0)
        {
            int nop = team[i].num_of_plays;
            cnt += nop;
            printf("%2d %10s %10s %7.2lf %6.2lf %6.2lf %6.2lf\n", team[i].num_pp,team[i].fname,team[i].lname,team[i].catches/nop, team[i].hits/nop,team[i].run/nop,team[i].home_run/nop);
            team_catches += team[i].catches;
            team_hits += team[i].hits;
            team_run += team[i].run;
            team_home_run += team[i].home_run;
            
        }
    puts("----------------------------");
    printf("TOTAL:                   %7.2lf %6.2lf %6.2lf %6.2lf\n ",team_catches/cnt,team_hits/cnt,team_run/cnt,team_home_run/cnt);
    
}
   *//*
//ex_7 модификация кода 14_14 будем удалять и добавлять книги
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 //максимальное количество книг
char *s_gets(char *,int);

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    bool del_mark;
};

int main(void)
{
    struct book library[MAXBKS]; //массив структур
    int count = 0;
    int index,filecount;
    FILE *pbooks;
    int size = sizeof (struct book);
    if ((pbooks = fopen("book.dat","r+b")) == NULL)
    {
        printf("Не удается открыть файл book.dat\n",stderr);
        exit(1);
    }
    rewind(pbooks); //переход в начало файла
    //считанные из файла книги размещаем в созданном массиве
    while (count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
    {
        if (count == 0)
            puts("Текущее содержимое файла book.dat:");
        //if (library[count].del_mark)
            printf("%s авторства %s: $%.2f\n",library[count].title,library[count].author,library[count].value);
        count++;
    }
    filecount = count;
    if (count ==MAXBKS)
    {
        fputs("Файл book.dat заполнен.", stderr);
        exit(2);
    }
    //для ввода новых книг создаем отдельный массив struct book что позволит выбирать из него позиции для перезаписи на место удаленных
    struct book add_books[MAXBKS];
    puts("Введите название новых книг.");
    puts("Нажмите [enter] в начале строки, чтобы закончить ввод.");
    int add_count = 0; //количество добавленных книг
    while (add_count < MAXBKS-filecount && s_gets(add_books[add_count].title, MAXTITL) != NULL && add_books[add_count].title[0] != '\0')
    {
        add_books[add_count].del_mark = true; //устанавливаем инд. удаления в 1
        puts("Теперь введите имя автора.");
        s_gets(add_books[add_count].author,MAXAUTL);
        puts("Теперь введите цену книги.");
        scanf("%f",&add_books[add_count++].value);
        while (getchar() != '\n')
            ;
        if (add_count < MAXBKS-filecount)
            puts("Введите название следующей книги.");
    }
    //удаляем книги
    puts("Введите названия книг которые подлежат удалению, нажмите [enter] в начале строки, чтобы закончить ввод.");
    char del_book[MAXTITL];
    int del_count = 0; //количество книг к удалению
    while (count >= del_count && s_gets(del_book,MAXTITL) != NULL && del_book[0] != '\0')
    {
        for (int i = 0 ; i <count; ++i)
            if (!strcmp(library[i].title, del_book))
            {
                library[i].del_mark = false;
                ++del_count;
            }
        if (count >= del_count)
            puts("Введите название следующей книги для удаления.");
    }
    if (count < del_count)
        puts("Больше не могу, книги кончились\n");
    
   //printf("%d\n",del_count);
    rewind(pbooks); //переход в начало файла
   
    //перезаписываем файл
    long pos;//указатель на позицию для перезаписи
    int ind_rewrite = 0; //индекс перезаписываемых позиции из массива add_books
    if (count > 0 && del_count < count)
    {
        for (index = 0;index < count;++index)
        {
            if (!library[index].del_mark) // если есть отметка об удалении будем перезаписываеть на этом месте
            {
                pos = (long)index*size;
                fseek(pbooks,pos,SEEK_SET);
                
                if (ind_rewrite < add_count)
                {
                    fwrite(&add_books[ind_rewrite++], size, 1, pbooks);
                   // ++ind_rewrite;
                }
                else
                 fwrite(&library[index], size, 1, pbooks);
                    
            }
        }
        if (add_count-ind_rewrite > 0)
        {
            fseek(pbooks,0L,SEEK_END);
            fwrite(&add_books[ind_rewrite], size, add_count - ind_rewrite, pbooks);
        }
            

    }

    //отображаем записанные файлы
    rewind(pbooks); //переход в начало файла
    count = 0;
    while (count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
    {
        if (count == 0)
            puts("Текущее содержимое файла book.dat:");
        //if (library[count].del_mark)
            printf("%s авторства %s: $%.2f\n",library[count].title,library[count].author,library[count].value);
        count++;
    }
    if (count == 0)
        puts("Совсем нет книг? Очень плохо.\n");
    puts("Программа завершена.\n");
    fclose(pbooks);
    
    return 0;
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
            while(getchar() !='\n')
                ;
    }
    return ret_val;
}

*//*
//ex_8 резервирование мест в самолете
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SEATS 12

struct seat {
    int ID;
    bool isReserved;
    char fname[10];
    char lname[15];
};

char show_menu(void);
void show_cnt_free_seats(struct seat[]);
void show_list_free_seats(struct seat[]);
void show_res_seats_abc(struct seat[]);
void book_seat(struct seat[],FILE *fp);
void make_free_reserve(struct seat[],FILE *);

int main(void)
{
    //загружаем данные по загрузке самолета из файла
    struct seat yak_42[SEATS];
    int size = sizeof(struct seat);
    
    FILE *pseats;
    if((pseats = fopen("yak_42.dat","r+b")) == NULL)
    {
        printf("Не удается открыть файл с данными.\n",stderr);
        exit(1);
    }
    
    int count  = 0;
    rewind(pseats);
    while (count < SEATS && fread(&yak_42[count], size, 1, pseats) == 1)
    {
        //printf("%d %d %s %s\n",count+1,yak_42[count].ID,yak_42[count].fname,yak_42[count].lname);
        ++count;
    }
    //начальное заполнение исходного файла
    if (count == 0)
    {
        rewind(pseats);
        count = 0;
        for (int i = 1;i < 4; ++i)
        {
            for (int j = 1; j<=4;++j)
            {
                yak_42[count].ID = i*10 +j;
                yak_42[count].isReserved = false;
                yak_42[count].fname[0]='\0';
                yak_42[count].lname[0]='\0';

                fwrite(&yak_42[count], size,1,pseats);
                ++count;
            }
        }
    }
    //загружаем меню выбираем нужную функцию
    char ch_menu;

    while ((ch_menu = show_menu()) != 'f')
    {
        switch (ch_menu) {
            case 'a':
                show_cnt_free_seats(yak_42);
                break;
            case 'b':
                show_list_free_seats(yak_42);
                break;
            case 'c':
                show_res_seats_abc(yak_42);
                break;
            case 'd':
                book_seat(yak_42,pseats);
                break;
            case 'e':
                make_free_reserve(yak_42,pseats);
                break;
            default:
                puts("Попробуйте еще раз что то пошло не так.\n");
                break;
        }
        

    }
    
    puts("Программа завершена\n");
    return 0;
}
char show_menu (void)
{
    char in_ch;
    puts("\nДля выбора функции введите ее буквенную метку.");
    puts("a) Показать количество свободных мест.");
    puts("b) Показать список своббодных мест.");
    puts("c) Показать список забронированных мест в алфавитном порядке.");
    puts("d) Забронировать место для пассажира.");
    puts("e) Снять броню с места.");
    puts("f) Выйти из программы.");
    
    scanf("%c",&in_ch);
    while (getchar() !='\n')
        ;
    
    return in_ch;
}

void show_cnt_free_seats(struct seat st[])
{
    
    int free_seats = 12;
    for (int ind = 0; ind < SEATS; ++ind)
        if ( st[ind].isReserved)
            --free_seats;
    printf("На борту %d свободных мест.\n",free_seats);
     
}

void show_list_free_seats(struct seat st[])
{
    for (int ind = 0; ind < SEATS; ++ind)
    {
        if (!st[ind].isReserved)
            printf("%3d ",st[ind].ID);
        else
            printf("    ");
        if ((ind+1)%4 == 0)
            printf("\n");
    }
}
void show_res_seats_abc(struct seat st[])
{
    int busy_seats = 0;
    struct seat *pst[SEATS];
    
    //заполняем массив указателей для сортировки резервированных мест
    for (int ind = 0; ind < SEATS; ++ind)
        if ( st[ind].isReserved)
        {
            pst[busy_seats++] = &st[ind];
        }
    
    bool not_sorted = true;
    struct seat *temp;
    while (not_sorted)
    {
        not_sorted = false;
        for (int i =0;i < busy_seats-1; ++i)
        {
            if (strcmp(pst[i]->lname,pst[i+1]->lname) > 0)
            {
                temp = pst[i];pst[i] = pst[i+1];pst[i+1]=temp;
                not_sorted = false;
            }
        }
            
    }
    printf("В самолете забронированно %d мест.\n",busy_seats);
    for (int ind = 0; ind < busy_seats; ++ind)
        printf("%3d %10s %10s\n",pst[ind]->ID,pst[ind]->lname,pst[ind]->fname);
    
}
void book_seat(struct seat st[],FILE *fp)
{
    show_list_free_seats(st);
    int res_seat,ind=0;
    puts("Выберите свободное место.");
    scanf("%d",&res_seat);
    while (getchar() !='\n')
        ;
    
    bool ok = false;
    while (!ok && res_seat !=100)
    {
        for (ind = 0; ind < SEATS; ++ind)
        {
            if (res_seat == st[ind].ID && st[ind].isReserved == false)
            {
                st[ind].isReserved = true;
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            puts("Это место занято или остутвует в самолете, поробуйте выбрать другое или ввести 100 для выхода");
            scanf("%d",&res_seat);
            while(getchar() !='\n')
                ;
        }
        
    }
    if (ok)
    {
        puts("Введите имя и фамилию пассажира\n");
        scanf("%s %s",st[ind].fname,st[ind].lname);
        while(getchar() !='\n')
            ;
        
        //устанавливаем новые данные по месту
        rewind(fp);
        long pos = (long)ind*sizeof(struct seat);
        fseek(fp, pos, SEEK_SET);
        fwrite(&st[ind], sizeof(struct seat), 1,fp);
        
        puts("Резервирование успешно завершено, выберите пункт меню b) для получения новых данных о свободных местах");
    }
    else
        puts("Выход из режима резервирования");
    
}
void make_free_reserve(struct seat st[],FILE *fp)
{
    show_res_seats_abc(st);
    
    int res_seat, ind = 0;
    puts("Введите номер для снятия брони.");
    scanf("%d",&res_seat);
    while (getchar() != '\n')
        ;
    
    bool ok = false;
    while (!ok && res_seat !=100)
    {
        for (ind = 0; ind < SEATS; ++ind)
        {
            if (res_seat == st[ind].ID && st[ind].isReserved == true)
            {
                st[ind].isReserved = false;
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            puts("Это место свободно или остутвует в самолете, поробуйте выбрать другое или ввести 100 для выхода");
            scanf("%d",&res_seat);
            while(getchar() !='\n')
                ;
        }
        
    }
    if (ok)
    {
        st[ind].fname[0] = '\0'; st[ind].lname[0] = '\0';
        
        //устанавливаем новые данные по месту
        rewind(fp);
        long pos = (long)ind*sizeof(struct seat);
        fseek(fp, pos, SEEK_SET);
        fwrite(&st[ind], sizeof(struct seat), 1,fp);
        
        puts("Резервирование успешно снято, выберите пункт меню b) для получения новых данных о свободных местах");
    }
    else
        puts("Выход из режима резервирования");
}
*//*
//ex_9 резервирование мест в самолете на нескольких рейсах
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SEATS 12
#define CNTPLANE 4

struct seat {
    int ID;
    bool isReserved;
    bool confirmed;//подтверждение бронирования
    char fname[10];
    char lname[15];
};


int choice_race(int *);
char show_menu_book(int );
void show_cnt_free_seats(struct seat[]);
void show_list_free_seats(struct seat[]);
void show_res_seats_abc(struct seat[]);
void book_seat(struct seat[],FILE *);
void confirm_book(struct seat[],FILE *);
void make_free_reserve(struct seat[],FILE *);

int main(void)
{
    //загружаем данные по загрузке самолета из файла
    struct seat yak_42[SEATS];
    int size = sizeof(struct seat);
    
    FILE *pseats = NULL;
    
    //устанавливаем массив с файлами для хранения данных по рейсам
    char races[CNTPLANE][12] ={
        {"race102.dat"},
        {"race311.dat"},
        {"race444.dat"},
        {"race519.dat"}
    };
    
    int num_of_race;
    puts("Выберите номер рейса");
    puts("102  311  444  519");
 

    
    while (scanf("%d",&num_of_race) == 1)
    //верхнее меню по рейсам
    {
        int chr;
        chr = choice_race(&num_of_race);
        
        if((pseats = fopen(races[chr],"r+b")) == NULL)
        {
            printf("Не удается открыть файл с данными.\n",stderr);
            exit(1);
        }
        
        int count  = 0;
        rewind(pseats);
        while (count < SEATS && fread(&yak_42[count], size, 1, pseats) == 1)
        {
           // printf("%d %d %s %s %d %d\n",count+1,yak_42[count].ID,yak_42[count].fname,yak_42[count].lname,yak_42[count].isReserved,yak_42[count].confirmed);
            ++count;
        }
        //начальное заполнение исходного файла
        if (count == 0)
        {
            rewind(pseats);
            count = 0;
            for (int i = 1;i < 4; ++i)
            {
                for (int j = 1; j<=4;++j)
                {
                    yak_42[count].ID = i*10 +j;
                    yak_42[count].isReserved = false;
                    yak_42[count].confirmed = false;
                    yak_42[count].fname[0]='\0';
                    yak_42[count].lname[0]='\0';

                    fwrite(&yak_42[count], size,1,pseats);
                    ++count;
                }
            }
        }
        //загружаем меню выбираем нужную функцию
        char ch_menu;

        while ((ch_menu = show_menu_book(num_of_race)) != 'f')
        {
            switch (ch_menu) {
                case 'a':
                    show_cnt_free_seats(yak_42);
                    break;
                case 'b':
                    show_list_free_seats(yak_42);
                    break;
                case 'c':
                    show_res_seats_abc(yak_42);
                    break;
                case 'd':
                    book_seat(yak_42,pseats);
                    break;
                case 'e':
                    make_free_reserve(yak_42,pseats);
                    break;
                case 'g':
                    confirm_book(yak_42,pseats);
                    break;
                default:
                    puts("Попробуйте еще раз что то пошло не так.\n");
                    break;
            }
            
            
        }
        
        puts ("Введите номер рейса или q для выхода из программы.");
        puts("Возможные варианты рейсов 102 311, 444 519");
        
    }//конец меню по рейсам
    puts("Программа завершена\n");
    return 0;
}

int choice_race(int *num_of_race)
{
    int nr = 0;
    
    bool check_of_race = false;
         
     while(!check_of_race)
     {
         switch (*num_of_race) {
             case 102:
                 nr=0;
                 check_of_race = true;
                 break;
             case 311:
                 nr=1;
                 check_of_race = true;
                 break;
             case 444:
                 nr=2;
                 check_of_race = true;
                 break;
             case 519:
                 nr=3;
                 check_of_race = true;
                 break;
             default:
                 puts("Проверьте номер рейса  и повторите ввод");
                 scanf("%d",num_of_race);
                 break;
         }

     }
    while (getchar() != '\n')
        ;
    return nr;
}

char show_menu_book (int nr)
{
    char in_ch;
    printf("Рейс %d",nr);
    puts("\nДля выбора функции введите ее буквенную метку.");
    puts("a) Показать количество свободных мест.");
    puts("b) Показать список своббодных мест.");
    puts("c) Показать список забронированных мест в алфавитном порядке.");
    puts("d) Забронировать место для пассажира.");
    puts("e) Снять броню с места.");
    puts("g) Подтвердить бронирование.");
    puts("f) Закончить работу с рейсом");
    
    scanf("%c",&in_ch);
    while (getchar() !='\n')
        ;
    
    return in_ch;
}

void show_cnt_free_seats(struct seat st[])
{
    
    int free_seats = 12;
    for (int ind = 0; ind < SEATS; ++ind)
        if ( st[ind].isReserved)
            --free_seats;
    printf("На борту %d свободных мест.\n",free_seats);
     
}

void show_list_free_seats(struct seat st[])
{
    for (int ind = 0; ind < SEATS; ++ind)
    {
        if (!st[ind].isReserved)
            printf("%3d ",st[ind].ID);
        else
            printf("    ");
        if ((ind+1)%4 == 0)
            printf("\n");
    }
}
void show_res_seats_abc(struct seat st[])
{
    int busy_seats = 0;
    struct seat *pst[SEATS];
    
    //заполняем массив указателей для сортировки резервированных мест
    for (int ind = 0; ind < SEATS; ++ind)
        if ( st[ind].isReserved)
        {
            pst[busy_seats++] = &st[ind];
        }
    
    bool not_sorted = true;
    struct seat *temp;
    while (not_sorted)
    {
        not_sorted = false;
        for (int i =0;i < busy_seats-1; ++i)
        {
            if (strcmp(pst[i]->lname,pst[i+1]->lname) > 0)
            {
                temp = pst[i];pst[i] = pst[i+1];pst[i+1]=temp;
                not_sorted = false;
            }
        }
            
    }
    printf("В самолете забронированно %d мест.\n",busy_seats);
    for (int ind = 0; ind < busy_seats; ++ind)
        printf("%3d %10s %10s %2c\n",pst[ind]->ID,pst[ind]->lname,pst[ind]->fname,pst[ind]->confirmed ==true ?'Y':'N');
    
}
void book_seat(struct seat st[],FILE *fp)
{
    show_list_free_seats(st);
    int res_seat,ind=0;
    puts("Выберите свободное место.");
    scanf("%d",&res_seat);
    while (getchar() !='\n')
        ;
    
    bool ok = false;
    while (!ok && res_seat !=100)
    {
        for (ind = 0; ind < SEATS; ++ind)
        {
            if (res_seat == st[ind].ID && st[ind].isReserved == false)
            {
                st[ind].isReserved = true;
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            puts("Это место занято или остутвует в самолете, поробуйте выбрать другое или ввести 100 для выхода");
            scanf("%d",&res_seat);
            while(getchar() !='\n')
                ;
        }
        
    }
    if (ok)
    {
        puts("Введите имя и фамилию пассажира\n");
        scanf("%s %s",st[ind].fname,st[ind].lname);
        while(getchar() !='\n')
            ;
        
        //устанавливаем новые данные по месту
        rewind(fp);
        long pos = (long)ind*sizeof(struct seat);
        fseek(fp, pos, SEEK_SET);
        fwrite(&st[ind], sizeof(struct seat), 1,fp);
        
        puts("Резервирование успешно завершено, выберите пункт меню b) для получения новых данных о свободных местах");
    }
    else
        puts("Выход из режима резервирования");
    
}

void confirm_book(struct seat st[],FILE *fp)
{
    show_res_seats_abc(st);
    
    int res_seat, ind = 0;
    puts("Введите номер для подтверждения брони.");
    scanf("%d",&res_seat);
    while (getchar() != '\n')
        ;
    
    bool ok = false;
    
    while (!ok && res_seat !=100)
    {
       for (ind = 0; ind < SEATS; ++ind)
       {
           if (res_seat == st[ind].ID && st[ind].isReserved == true)
           {
               st[ind].confirmed = true;
               ok = true;
               break;
           }
       }
       if (!ok)
       {
           puts("Это место не забронировано или остутвует в самолете, поробуйте выбрать другое или ввести 100 для выхода");
           scanf("%d",&res_seat);
           while(getchar() !='\n')
               ;
       }
       
    }
    if (ok)
    {

       //устанавливаем новые данные по месту
       rewind(fp);
       long pos = (long)ind*sizeof(struct seat);
       fseek(fp, pos, SEEK_SET);
       fwrite(&st[ind], sizeof(struct seat), 1,fp);
       
       puts("Бронирование успешно подтверждено, выберите пункт меню b) для получения новых данных о свободных местах или d для просмотра списка забронированных мест.");
    }
    else
       puts("Выход из режима подтверждения брони");
       
}

void make_free_reserve(struct seat st[],FILE *fp)
{
    show_res_seats_abc(st);
    
    int res_seat, ind = 0;
    puts("Введите номер для снятия брони.");
    scanf("%d",&res_seat);
    while (getchar() != '\n')
        ;
    
    bool ok = false;
    while (!ok && res_seat !=100)
    {
        for (ind = 0; ind < SEATS; ++ind)
        {
            if (res_seat == st[ind].ID && st[ind].isReserved == true)
            {
                st[ind].isReserved = false;
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            puts("Это место свободно или остутвует в самолете, поробуйте выбрать другое или ввести 100 для выхода");
            scanf("%d",&res_seat);
            while(getchar() !='\n')
                ;
        }
        
    }
    if (ok)
    {
        st[ind].fname[0] = '\0'; st[ind].lname[0] = '\0';
        
        //устанавливаем новые данные по месту
        rewind(fp);
        long pos = (long)ind*sizeof(struct seat);
        fseek(fp, pos, SEEK_SET);
        fwrite(&st[ind], sizeof(struct seat), 1,fp);
        
        puts("Резервирование успешно снято, выберите пункт меню b) для получения новых данных о свободных местах");
    }
    else
        puts("Выход из режима резервирования");
}
   *//*
//ex_10 добавляем массив указателей на функции

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SEATS 12
#define CNTPLANE 4

struct seat {
    int ID;
    bool isReserved;
    bool confirmed;//подтверждение бронирования
    char fname[10];
    char lname[15];
};


int choice_race(int *);
int show_menu_book(int );
void show_cnt_free_seats(struct seat[],FILE *);
void show_list_free_seats(struct seat[],FILE *);
void show_res_seats_abc(struct seat[],FILE *);
void book_seat(struct seat[],FILE *);
void confirm_book(struct seat[],FILE *);
void make_free_reserve(struct seat[],FILE *);

typedef void(*seat_operation) (struct seat[],FILE *); //определяем указатель на функция как  seat_operation
//создаем массив указателей на функциии
seat_operation oper[6] = {show_cnt_free_seats, show_list_free_seats, show_res_seats_abc,book_seat, confirm_book, make_free_reserve};

int main(void)
{
    //загружаем данные по загрузке самолета из файла
    struct seat yak_42[SEATS];
    int size = sizeof(struct seat);
    
    FILE *pseats = NULL;
    
    //устанавливаем массив с файлами для хранения данных по рейсам
    char races[CNTPLANE][12] ={
        {"race102.dat"},
        {"race311.dat"},
        {"race444.dat"},
        {"race519.dat"}
    };
    
    int num_of_race;
    puts("Выберите номер рейса");
    puts("102  311  444  519");
 

    
    while (scanf("%d",&num_of_race) == 1)
    //верхнее меню по рейсам
    {
        int chr;
        chr = choice_race(&num_of_race);
        
        if((pseats = fopen(races[chr],"r+b")) == NULL)
        {
            printf("Не удается открыть файл с данными.\n",stderr);
            exit(1);
        }
        
        int count  = 0;
        rewind(pseats);
        while (count < SEATS && fread(&yak_42[count], size, 1, pseats) == 1)
        {
           // printf("%d %d %s %s %d %d\n",count+1,yak_42[count].ID,yak_42[count].fname,yak_42[count].lname,yak_42[count].isReserved,yak_42[count].confirmed);
            ++count;
        }
        //начальное заполнение исходного файла
        if (count == 0)
        {
            rewind(pseats);
            count = 0;
            for (int i = 1;i < 4; ++i)
            {
                for (int j = 1; j<=4;++j)
                {
                    yak_42[count].ID = i*10 +j;
                    yak_42[count].isReserved = false;
                    yak_42[count].confirmed = false;
                    yak_42[count].fname[0]='\0';
                    yak_42[count].lname[0]='\0';

                    fwrite(&yak_42[count], size,1,pseats);
                    ++count;
                }
            }
        }
        //загружаем меню выбираем нужную функцию
        int  num_menu;

        while ((num_menu = show_menu_book(num_of_race)) != -1)
        {
            printf("%d in main\n",num_menu);
            oper[num_menu](yak_42,pseats);
            
        }
        
        puts ("Введите номер рейса или q для выхода из программы.");
        puts("Возможные варианты рейсов 102 311, 444 519");
        
    }//конец меню по рейсам
    puts("Программа завершена\n");
    return 0;
}

int choice_race(int *num_of_race)
{
    int nr = 0;
    
    bool check_of_race = false;
         
     while(!check_of_race)
     {
         switch (*num_of_race) {
             case 102:
                 nr=0;
                 check_of_race = true;
                 break;
             case 311:
                 nr=1;
                 check_of_race = true;
                 break;
             case 444:
                 nr=2;
                 check_of_race = true;
                 break;
             case 519:
                 nr=3;
                 check_of_race = true;
                 break;
             default:
                 puts("Проверьте номер рейса  и повторите ввод");
                 scanf("%d",num_of_race);
                 break;
         }

     }
    while (getchar() != '\n')
        ;
    return nr;
}

int show_menu_book (int nr)
{
    char in_ch;
    int num_op = -1;
    printf("Рейс %d",nr);
    puts("\nДля выбора функции введите ее буквенную метку.");
    puts("a) Показать количество свободных мест.");
    puts("b) Показать список своббодных мест.");
    puts("c) Показать список забронированных мест в алфавитном порядке.");
    puts("d) Забронировать место для пассажира.");
    puts("e) Снять броню с места.");
    puts("g) Подтвердить бронирование.");
    puts("f) Закончить работу с рейсом");
    
   
    while (scanf("%c",&in_ch) != 1  || strchr("abcdegf",in_ch) == NULL)
    {
        puts("Попробуйте еще раз  выбрать опцию, что то пошло не так.");
        while (getchar() !='\n')
            ;
    }

    switch (in_ch) {
           case 'a':
               num_op=0;
               break;
           case 'b':
               num_op=1;
               break;
           case 'c':
               num_op=2;
               break;
           case 'd':
              num_op = 3;
               break;
           case 'e':
               num_op = 4;
               break;
           case 'g':
               num_op = 5;
               break;
           case 'f':
               num_op = -1;
               break;

        }
    while (getchar() !='\n')
            ;
     
    return num_op;
}

void show_cnt_free_seats(struct seat st[],FILE *fp)
{
    
    int free_seats = 12;
    for (int ind = 0; ind < SEATS; ++ind)
        if ( st[ind].isReserved)
            --free_seats;
    printf("На борту %d свободных мест.\n",free_seats);
     
}

void show_list_free_seats(struct seat st[],FILE *fp)
{
    for (int ind = 0; ind < SEATS; ++ind)
    {
        if (!st[ind].isReserved)
            printf("%3d ",st[ind].ID);
        else
            printf("    ");
        if ((ind+1)%4 == 0)
            printf("\n");
    }
}
void show_res_seats_abc(struct seat st[], FILE *fp)
{
    int busy_seats = 0;
    struct seat *pst[SEATS];
    
    //заполняем массив указателей для сортировки резервированных мест
    for (int ind = 0; ind < SEATS; ++ind)
        if ( st[ind].isReserved)
        {
            pst[busy_seats++] = &st[ind];
        }
    
    bool not_sorted = true;
    struct seat *temp;
    while (not_sorted)
    {
        not_sorted = false;
        for (int i =0;i < busy_seats-1; ++i)
        {
            if (strcmp(pst[i]->lname,pst[i+1]->lname) > 0)
            {
                temp = pst[i];pst[i] = pst[i+1];pst[i+1]=temp;
                not_sorted = false;
            }
        }
            
    }
    printf("В самолете забронированно %d мест.\n",busy_seats);
    for (int ind = 0; ind < busy_seats; ++ind)
        printf("%3d %10s %10s %2c\n",pst[ind]->ID,pst[ind]->lname,pst[ind]->fname,pst[ind]->confirmed ==true ?'Y':'N');
    
}
void book_seat(struct seat st[],FILE *fp)
{
    show_list_free_seats(st,fp);
    int res_seat,ind=0;
    puts("Выберите свободное место.");
    scanf("%d",&res_seat);
    while (getchar() !='\n')
        ;
    
    bool ok = false;
    while (!ok && res_seat !=100)
    {
        for (ind = 0; ind < SEATS; ++ind)
        {
            if (res_seat == st[ind].ID && st[ind].isReserved == false)
            {
                st[ind].isReserved = true;
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            puts("Это место занято или остутвует в самолете, поробуйте выбрать другое или ввести 100 для выхода");
            scanf("%d",&res_seat);
            while(getchar() !='\n')
                ;
        }
        
    }
    if (ok)
    {
        puts("Введите имя и фамилию пассажира\n");
        scanf("%s %s",st[ind].fname,st[ind].lname);
        while(getchar() !='\n')
            ;
        
        //устанавливаем новые данные по месту
        rewind(fp);
        long pos = (long)ind*sizeof(struct seat);
        fseek(fp, pos, SEEK_SET);
        fwrite(&st[ind], sizeof(struct seat), 1,fp);
        
        puts("Резервирование успешно завершено, выберите пункт меню b) для получения новых данных о свободных местах");
    }
    else
        puts("Выход из режима резервирования");
    
}

void confirm_book(struct seat st[],FILE *fp)
{
    show_res_seats_abc(st,fp);
    
    int res_seat, ind = 0;
    puts("Введите номер для подтверждения брони.");
    scanf("%d",&res_seat);
    while (getchar() != '\n')
        ;
    
    bool ok = false;
    
    while (!ok && res_seat !=100)
    {
       for (ind = 0; ind < SEATS; ++ind)
       {
           if (res_seat == st[ind].ID && st[ind].isReserved == true)
           {
               st[ind].confirmed = true;
               ok = true;
               break;
           }
       }
       if (!ok)
       {
           puts("Это место не забронировано или остутвует в самолете, поробуйте выбрать другое или ввести 100 для выхода");
           scanf("%d",&res_seat);
           while(getchar() !='\n')
               ;
       }
       
    }
    if (ok)
    {

       //устанавливаем новые данные по месту
       rewind(fp);
       long pos = (long)ind*sizeof(struct seat);
       fseek(fp, pos, SEEK_SET);
       fwrite(&st[ind], sizeof(struct seat), 1,fp);
       
       puts("Бронирование успешно подтверждено, выберите пункт меню b) для получения новых данных о свободных местах или d для просмотра списка забронированных мест.");
    }
    else
       puts("Выход из режима подтверждения брони");
       
}

void make_free_reserve(struct seat st[],FILE *fp)
{
    show_res_seats_abc(st,fp);
    
    int res_seat, ind = 0;
    puts("Введите номер для снятия брони.");
    scanf("%d",&res_seat);
    while (getchar() != '\n')
        ;
    
    bool ok = false;
    while (!ok && res_seat !=100)
    {
        for (ind = 0; ind < SEATS; ++ind)
        {
            if (res_seat == st[ind].ID && st[ind].isReserved == true)
            {
                st[ind].isReserved = false;
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            puts("Это место свободно или остутвует в самолете, поробуйте выбрать другое или ввести 100 для выхода");
            scanf("%d",&res_seat);
            while(getchar() !='\n')
                ;
        }
        
    }
    if (ok)
    {
        st[ind].fname[0] = '\0'; st[ind].lname[0] = '\0';
        
        //устанавливаем новые данные по месту
        rewind(fp);
        long pos = (long)ind*sizeof(struct seat);
        fseek(fp, pos, SEEK_SET);
        fwrite(&st[ind], sizeof(struct seat), 1,fp);
        
        puts("Резервирование успешно снято, выберите пункт меню b) для получения новых данных о свободных местах");
    }
    else
        puts("Выход из режима резервирования");
}

*/
//ex_11 определяем функцию transform
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100
void transform (double[],double[],int,double(*fp)(double));
double rate10(double);
double plus_div(double);
void show_ar(double[], int);

int main(void)
{
    FILE *fp;
    double source[N];
    double target[N];
    
    if ((fp = fopen("/Users/pupsik/Downloads/27data/8/27-8b.txt","r")) == NULL)
    {
        puts("Файл не открывается");
        exit(1);
    }
    int none; fscanf(fp,"%d", &none); //считывает ненужное число
    
 
    
    for (int ind = 0;ind < N; ++ind)
        fscanf(fp,"%lf", &source[ind]);
    
    //показываем скаченный массив
    show_ar(source,N);
    
    double (*pfunc[4])(double) = {rate10,plus_div,log10,sin};
   

    for (int i = 0; i < 4; ++i)
    {
        transform(source, target,N, pfunc[i]);
        show_ar(target, N);
    }
    
 
    return 0;
}

double rate10(double num)
{
    return num/10;
}

double plus_div (double num)
{
    return (num +1)/10;
}

void transform (double source[], double target[], int num ,double(*fp)(double))
{
    for (int i = 0; i < num; ++i)
        target[i] = (*fp)(source[i]);
}
void show_ar(double ar[],int n)
{
    for (int i = 0;i < n; ++i)
    {
        printf("%7.2lf ",ar[i]);
        if ((i+1)%10 == 0)
            printf("\n");
    }
    printf("\n");
}
