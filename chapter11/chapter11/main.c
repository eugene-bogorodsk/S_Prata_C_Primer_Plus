//
//  main.c
//  chapter11
//
//  Created by пупсик on 05.03.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//

/*
//list_11_3 адреса строк asresses.c
#include <stdio.h>
#define MSG "Я особенный"

int main(void) {
    
    char ar[] = MSG;
    const char *pt = MSG;
    
    printf("адрес \"Я особенный.\":%p \n","Я особенный.");
    printf("              адрес ar:%p\n", ar);
    printf("              адрес pt:%p\n",pt);
    printf("             адрес MSG:%p\n",MSG);
    printf("адрес \"Я особенный.\":%p \n","Я особенный.");
 
    return 0;
}
*//*
//list_11_4 arrchar.c массив указателей, массив строк
#include<stdio.h>
#define SLEN 50
#define LIM 5

int main(void)
{
    const char *mytalents[LIM] = {
        "Мгновенное складывание чисел",
        "Точное умножение", "Накапливание данных",
        "Исполнение инструкций с точностью до буквы",
        "Знание языка программирования С"
    };
    char yourtalents[LIM][SLEN] = {
        "Хождение по прямой",
        "Здоровый сон", "Просмотр телепередач",
        "Рассылка писем", "Чтение электронной почты"
    };
    int i;
    
    puts("Сравним наши таланты.");
    printf("%-52s %-25s\n","Мои таланты", "Ваши таланты");
    for (i = 0; i < LIM; i++)
        printf("%-75s %-25s\n", mytalents[i],yourtalents[i]);
    printf("\nразмер mytalents:%zd, размер yourtalents: %zd\n", sizeof(mytalents),sizeof(yourtalents));
    

    return 0;
}
*//*
//list_11_5 p_and_s.c указатели на строки
#include <stdio.h>
int main(void)
{
    const char *msg = "Не позволяйте себя запугать!";
    const char *copy;
    copy = msg;
    printf("%s\n",copy);
    printf("msg = %s; &msg = %p; value = %p\n",msg,&msg,msg);
    printf("copy = %s; &copy = %p; value = %p\n", copy,&copy,copy);
    
    return 0;
}
*//*
//list_11_7 fgets1.c использование функций fgets() и fputs()
//c русски текстом не работает даже при подключении wchar
#include<stdio.h>
#define STLEN 15
int main(void)
{
    char words[STLEN];
    puts("Введите строку.");
    fgets(words,STLEN,stdin);
    printf("Ваша строка. выведенная дважды (с помощью puts(), а затем fputs()):\n");
    puts(words);
    fputs(words,stdout);
    puts("Введит ещё одну строку.");
    fgets(words,STLEN,stdin);
    printf("Ваша строка. выведенная дважды (c помощью puts(), а затем fputs()):\n");
    puts(words);
    fputs(words,stdout);
    puts("Готово.");
    
    return 0;
}
   *//*
//пытаемся подключить русский текст попытка номер 2
#include<stdio.h>
#include<wchar.h>
#include<locale.h>
#define STLEN 50
int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    wchar_t words[STLEN];
    puts("Введите строку.");
    fgetws(words,STLEN,stdin);
    printf("Ваша строка. выведенная дважды (с помощью puts(), а затем fputs()):\n");
    fputws(words,stdout);
    fputws(words,stdout);
    puts("Введит ещё одну строку.");
    fgetws(words,STLEN,stdin);
    printf("Ваша строка. выведенная дважды (c помощью puts(), а затем fputs()):\n");
    fputws(words,stdout);
    fputws(words,stdout);
    puts("Готово.");
    
    return 0;
}
// все отлично работает пришлось расширить STLEN до 50 иначе ничего не влезало
*/
/*
//list_11_8 fgets2.c ипользование функций fgets()  и fputs()
#include<stdio.h>
#define STLEN 10
int main(void)
{
    char words[STLEN];
    
    puts("Введите строки (или пустую строку для выхода из программы):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Готово.");
    
    return 0;
}
*//*
//list_11_9 fgets3.c использование функции fgets()
#include <stdio.h>
#define STLEN 10
int main(void)
{
    char words[STLEN];
    int i;
    puts("Введите строки (или пустую строку для выходи из программы):");
    while(fgets(words,STLEN,stdin) != NULL && words[0] != '\n')
    {
        i = 0;
        while(words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')
            words[i] = '\0';
        else //требуется наличие words[i] == '\0';
            while (getchar() != '\n')
                continue;
        puts(words);
    }
    puts("Готово.");
    
    return 0;
}
   *//*
//list_11_16 put_put.c тестирование пользовательских функций put
#include<stdio.h>
void put1(const char*);
int put2(const char*);
int main(void)
{
    put1("Если бы у меня было столько денег,");
    put1(" сколько я мог бы потратить,\n");
    printf("Получилось %d символов.\n", put2("то я никогда не заботился бы о починке старых башмаков"));
    
    return 0;
}
void put1(const char* string)
{
    while(*string) //= *string != '\0'
        putchar(*string++);
}
int put2(const char* string)
{
    int count = 0;
    while(*string)
    {
        putchar(*string++);
        count++;
    }
    putchar('\n');
    return count;
}
      *//*
//list_11_17 test_fit.c использование функции укорачивания строк
#include<stdio.h>
#include<string.h> //содержит прототипы строковых функций
#include<wchar.h>
#include<locale.h>
void fit(wchar_t*, unsigned int);

int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");//для успешной работы с широкими символами не забывать устанавливть локаль
    
    wchar_t mesg[] = L"Все должно быть максимально простым,""но не более.\n";
    
    wprintf(L"%ls",mesg);
    fit(mesg,35);
    wprintf(L"%ls",mesg);
    puts("\nРассмотрим ещё несколько строк.");
    fputws(mesg+36,stdout);
    
    return 0;
}
void fit(wchar_t *string,unsigned int size)
{
    if (wcslen(string) > size)
        string[size] = '\0';
}*/
/*
// с широкими символами работает  некорректно
#include<stdio.h>
#include<string.h> //содержит прототипы строковых функций
#include<wchar.h>
void fit(char*,unsigned int);

int main(void)
{
    char mesg[] = "Все должно быть максимально простым,""но не более.";
    
    puts(mesg);
    fit(mesg,35);
    puts(mesg);
    puts("Рассмотрим ещё несколько строк.");
    puts(mesg+36);
    
    return 0;
}
void fit(char *string,unsigned int size)
{
    if (strlen(string) > size)
        string[size] = '\0';
}
*//*
//list_11_18 str_cat.c объединяет две строки
#include<stdio.h>
#include<string.h> //объявляет strcat()
#define SIZE 80
char *s_gets(char *st,int n);
int main(void)
{
    char flower[SIZE];
    char addon[] = " пахнет как старые валенки.";
    
    puts("Какой у вас любимый цветок?");
    if (s_gets(flower,SIZE))
    {
        strcat(flower,addon);
        puts(flower);
        puts(addon);
    }
    else
        puts("Обнаружен коец файла!");
    puts ("Программа завершена.");
    
    return 0;
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    int i = 0;
    
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
// работает без проблем
*//*
   
//list_11_19 ф-ция strncat() проверяет количество копируемых символов
//join_chk.c не работет с широкими сиволами
#include<stdio.h>
#include<string.h>
#define SIZE 50
#define BUGSIZE 13

char *s_gets(char *st,int n);
int main(void)
{
    char flower[SIZE];
    char addon[] = " пахнет как старые валенки.";
    char bug[BUGSIZE];
    int available;
    puts("Какой у Вас любимый цветок?");
    s_gets (flower,SIZE);
    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
        strcat(flower, addon);
    puts(flower);
    puts("Какое у Вас любимое насекомое?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - (int)strlen(bug) -1;
    strncat(bug,addon,available);
    puts(bug);
    
    return 0;
}
char *s_gets (char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
        while (getchar() != '\n')
            continue;
    }
    return ret_val;
}
   *//*
#include<stdio.h>
#include<string.h>
#include <wchar.h>
#include <locale.h>
#define SIZE 50
#define BUGSIZE 13

wchar_t *s_gets(wchar_t *st,int n);
int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");
    
    wchar_t flower[SIZE];
    wchar_t addon[] = L" пахнет как старые валенки.";
    wchar_t bug[BUGSIZE];
    int available;
    fputws(L"Какой у Вас любимый цветок?",stdout);
    s_gets (flower,SIZE);
    if ((wcslen(addon) + wcslen(flower) + 1) <= SIZE)
        wcscat(flower, addon);
    fputws(flower, stdout);
    puts("\nКакое у Вас любимое насекомое?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - (int)wcslen(bug) -1;
    wcsncat(bug,addon,available);
    fputws(bug,stdout);
    puts("\n");
    return 0;
}
wchar_t *s_gets (wchar_t *st, int n)
{
    wchar_t *ret_val;
    int i = 0;
    ret_val = fgetws(st,n,stdin);
    if (ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
        while (getwchar() != '\n')
            continue;
    }
    return ret_val;
}
      *//*
//list_11_21 использование ф-ции strcmp()
//compare.c
#include<stdio.h>
#include<string.h>
#define ANSWER "Грант"
#define SIZE 40
char *s_gets(char *st, int n);

int main(void)
{
    char try[SIZE];
    
    puts("Кто похоронен в могиле Гранта?");
    s_gets(try,SIZE);
    while(strcmp(try,ANSWER) != 0)
    {
        puts("Неправильно! Попытайтесь еще раз.");
        s_gets(try,SIZE);
    }
    puts("Теперь правильно!");
    
    return 0;
}
char *s_gets(char *st,int n)
{
    char *ret_val;
    int i=0;
    
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
*//*
//list_11_22
#include<stdio.h>
#include<string.h>
int main(void)
{
    printf("strcpm(\"A\",\"A\") возвращает ");
    printf("%d\n",strcmp("A","A"));
    
    printf("strcpm(\"A\",\"B\") возвращает ");
    printf("%d\n",strcmp("A","B"));
    
    printf("strcpm(\"B\",\"A\") возвращает ");
    printf("%d\n",strcmp("B","A"));
    
    printf("strcpm(\"C\",\"A\") возвращает ");
    printf("%d\n",strcmp("C","A"));
    
    printf("strcpm(\"Z\",\"a\") возвращает ");
    printf("%d\n",strcmp("Z","a"));
    
    printf("strcpm(\"apples\",\"apple\") возвращает ");
    printf("%d\n",strcmp("apples","apple"));
    
    return 0;
}
*//*
//list_11_23 quit_chk.c использование strcmp() для остановки чтения ввода
#include<stdio.h>
#include<string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"

char *s_gets(char *st,int n);

int main(void)
{
    char input[LIM][SIZE];
    int ct = 0;
    printf("Введите до  %d строк (или quit для завершения):\n",LIM);
    //программа завершает чтение выходных данных когда встречает символ EOF (в этом случае s_gets() возвращает NULL), при вводе слова quit или по достижении предела установленного в LIM
    while (ct < LIM && s_gets(input[ct],SIZE) != NULL && strcmp(input[ct],STOP) != 0)
    {
        ct++;
    }
    printf("Введено %d строк(и)\n",ct);
    
    return 0;
}
char *s_gets(char *st,int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
*//*
//list_11_24 использование функции strncmp() starsrch.c
//код переделан из начального для работы с wchar
#include<stdio.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#define LISTSIZE 6
int main()
{
    setlocale(LC_ALL,"en_US.UTF-8");
    
    const wchar_t *list[LISTSIZE] =
    {
        L"астрономия",L"астатизм",L"астрофизика",L"остракизм",L"астериз",L"астролябия"
    };
    int count = 0;
    int i;
    
    for (i = 0;i<LISTSIZE;i++)
        if (wcsncmp(list[i], L"астро", 5) == 0)
        {
            wprintf(L"Найдено:%ls\n",list[i]);
            count++;
        }
    printf("Количество слов в списке, начинающихся с астро: %d\n",count);
    
    return 0;
}
   *//*
//list_11_25 copy1.c демонстрация использования strcpy()
// код не работает в x-code какие то проблемы передачей из буфера wchar нужно разбираться в eclipse проблем нет никаких
//не работал потому что в настройках Preferences раздел Text Editting был установлен по умолчанию UTF-8 соответственно с клавиатуры заходил не тот размер
//после установки в Unicode UTF-16 все работает как часы
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<wchar.h>
#define SIZE 50
#define LIM 5

wchar_t * s_gets(wchar_t *st, int n);
int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");//если установить в UTF-16 не работает
    
    wchar_t qwords[LIM][SIZE];
    wchar_t temp[SIZE];
    int i = 0;
    printf("Введите %d слов, которые начинаются с буквы к:\n",LIM);
    while (i<LIM && s_gets(temp,SIZE))
    {
        if (temp[0] != L'к')
            printf("%ls не начинается с буквы к!\n", temp);
        else{
            wcscpy(qwords[i],temp);
            i++;
        }
    }
    puts("Список принятых слов:");
    for (i=0;i<LIM;i++)
        printf("%ls\n",qwords[i]);
    return 0;
}

wchar_t *s_gets(wchar_t *st,int n)
{
    wchar_t *ret_val;
    int i = 0;
    
    ret_val = fgetws(st,n,stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while(getwchar() != '\n')
                continue;
    }
    return ret_val;
}
     */ /*
//list_11_26 coppy2.c использование strcpy()
#include<stdio.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#define WORDS L"наихудщим"
#define SIZE 50

int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");
    const wchar_t *orig = WORDS;
    wchar_t copy[SIZE] = L"\nБудьте лучшим, чем могли бы быть.";
    wchar_t *ps;
    
    fputws(orig,stdout);
    fputws(copy,stdout);
    ps = wcscpy(copy + 8,orig);
    printf("%ls\n",copy);
    printf("%ls\n",ps);
    
    return 0;
}
*//*
//list_11_27 copy3.c использование strncpy()
//в xcode работает неустойчиво и с ошибками в eclipse без вопросов
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<wchar.h>
#define SIZE 50
#define TARGETSIZE 7
#define LIM 5
wchar_t *s_gets(wchar_t *st,int n);
int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");
    
    wchar_t qwords[LIM][SIZE];
    int i;
    for (i =0; i<LIM; i++)
        qwords[i][0]='\0';// заработало только после первоначальной очистки массива и обнуления temp на каждом цикле использования
    wchar_t temp[SIZE];
    i=0;
    printf("Введите %d слов, которые начинаются с буквы к:\n",LIM);
    while( i<LIM && s_gets(temp,SIZE))
    {
        if (temp[0] != L'к')
            printf("%ls не начинаются с буквы к:\n", temp);
        else
        {
            wcsncpy(qwords[i],temp,TARGETSIZE-1);
            //wcscpy(qwords[i],temp);
           qwords[i][TARGETSIZE-1] = '\0';
            i++;
            temp[0]='\0';
        }
    }
    puts("Список принятых слов:");
    for (i = 0;i<LIM;i++)
    {
        wprintf(L"%ls\n",qwords[i]);

    }
    
    return 0;
}
wchar_t *s_gets(wchar_t *st,int n)
{
    wchar_t *ret_val;
    int i =0;
    ret_val = fgetws(st,n,stdin);
    if (ret_val)
    {
        while (st[i] !='\n' && st[i] !='\0' && st[i] !=' ')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getwchar() !='\n')
                continue;
    }
    return ret_val;
}
   *//*
//list_11_28 format.c  форматирование строки ф-ция  sprintf() передает значени в строку
#include <stdio.h>
#define MAX 20
char *s_gets(char *st,int n);

int main(void)
{
    char first[MAX];
    char last[MAX];
    char formal[2*MAX+10];
    double prize;
    
    puts("Введите имя:");
    s_gets(first,MAX);
    puts("Введите фамилию:");
    s_gets(last,MAX);
    puts("Введите сумму денежного приза:");
    scanf("%lf",&prize);
    sprintf(formal,"%s,%-19s: $%6.2f\n",last,first,prize);
    puts(formal);
    
    return 0;
}
char *s_gets(char *st,int n)
{
    char *ret_val;
    int i =0;
    
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
      *//*
//list_11_29 sort_str.c сортировка строк
#include<stdio.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>
#define SIZE 81
#define LIM 20
#define HALT ""
void stsrt(char *strings[],int num);
char *s_gets(char *st,int n);
int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");
    
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct=0;
    int k;
    
    printf("Введите до  %d строк, и они будут отсортированы.\n",LIM);
    printf("Что бы остановить ввод, нажмите клавишу Enter в начале строки.\n");
    while( ct<LIM && s_gets(input[ct],SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct]; //установка указателей на строки
        ct++;
    }
    stsrt(ptstr,ct); //сортировка строк
    puts("\nОтсортированный список:\n");
    for (k=0;k < ct; k++)
        puts(ptstr[k]);//отсортированные указатели
    
    return 0;
}
 //ф-ция сортировки указателей на строки
void stsrt (char *strings[],int num)
{
    char *temp;
    int top,seek;
    for (top = 0; top < num-1;top++)
        for (seek = top+1;seek < num;seek++)
            if (strcmp(strings[top],strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}
char *s_gets(char *st,int n)
{
    char *ret_val;
    int i = 0;
    
    ret_val = fgets(st,n,stdin);
    if(ret_val)
     {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
         *//*
//list_11_30 модификация строк
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<wctype.h>
#include<wchar.h>
#include<locale.h>
#define LIMIT 81
void ToUpper(wchar_t *);
int PunctCount(const wchar_t *);
int main(void)
{
    setlocale(LC_ALL,"en_US.UTF-8");
    
    wchar_t line[LIMIT];
    wchar_t *find;
    
    puts("Введите строку:");
    fgetws(line,LIMIT,stdin);
    find = wcschr(line,'\n');//поиск символа новой строки
    if (find) //если адрес не является NULL
       *find = '\0';//поместите туда нулевой символ
    ToUpper(line);
    printf("%ls\n",line);
    printf("Эта строка содержит %d знаков препинания.\n",PunctCount(line));
    
    return 0;
}
void ToUpper (wchar_t *str)
{

   while (*str !='\0')
   {
        *str = towupper(*str);
        str++;
   }
}
int PunctCount(const wchar_t *str)
{
    int ct = 0;
    while (*str)
    {
        if (iswpunct(*str))
            ct++;
        str++;
    }
    return ct;
}
*//*
//list_11_33 strcnve.c использование функции strol()
#include<stdio.h>
#include <stdlib.h>
#define LIM 30
char *s_gets(char *st,int n);
int main()
{
    char number[LIM];
    char *end;
    long value;
    
    puts("Введите число (или пустую строку для выхода из программы):");
    while(s_gets(number,LIM) && number[0] != '\0')
    {
        value = strtol(number,&end,10); //по основанию 10
        printf("десятичный ввод, десятичный вывод: :%ld, прекращен на %s (%d)\n",value,end,*end);
        
        value = strtol(number,&end,16);//по основанию 16
        printf("шестандцатиричный ввод, шестнадцатиричный вывод: %ld, прекращен на %s (%d) \n",value,end,*end); //последний аргумент выводит код символа на котором прекратился ввод
        puts("Следующее число:");
    }
    puts ("Программа завершена.\n");
    
    return 0;
}
char *s_gets(char *st,int n)
{
    char *ret_val;
    int i = 0;
    
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
*//*
//myself_13 изменения в list_11_21
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ANSWER "GRANT"
#define SIZE 40
char *s_gets(char *st, int n);
char *toUpper(char*st);

int main(void)
{
    char try[SIZE];
    
    puts("Кто похоронен в могиле Гранта?");
    s_gets(try,SIZE);
    while(strcmp(toUpper(try),ANSWER) != 0)
    {
        puts("Неправильно! Попытайтесь еще раз.");
        s_gets(try,SIZE);
    }
    puts("Теперь правильно!");
    
    return 0;
}
char *s_gets(char *st,int n)
{
    char *ret_val;
    int i=0;
    
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}
char *toUpper(char * str)
{
    char *initial = str;
    while(*str)
    {
        *str = toupper(*str);
        str++;
    }
    return initial;
}
   *//*
//ex1 извлекаем по n символов из ввода
#include<stdio.h>
#include<ctype.h>
#define N 8
void s_getn(char *, int );
int main(void)
{
    char save[N+1];
    s_getn(save,N);
    puts(save);

    return 0;
}
void s_getn(char *st, int n)
{
    int i=0;
    while ((*st=getchar()) !='\n' && i<N)
    {
        st++;
        i++;
    }
    *st='\0';
}*//*
//ex2 вводим дополнительное ограничение по пробелу
#include<stdio.h>
#include<ctype.h>
#define N 12
void s_getn(char *, int );
int main(void)
{
    char save[N+1];
    s_getn(save,N);
    puts(save);

    return 0;
}
void s_getn(char *st, int n)
{
    int i=0;
    *st=getchar();
    while (*st !=' '&& *st !='\t' && *st !='\n' && i<N)
    {
        *++st=getchar();
        i++;
    }
    *st='\0';
}
*//*
//ex3 вводим  пропускаем пробелы в начале
#include<stdio.h>
#include<ctype.h>
#define N 12
void s_getn(char *, int );
int main(void)
{
    char save[N+1];
    s_getn(save,N);
    puts(save);

    return 0;
}
void s_getn(char *st, int n)
{
    int i=0;
    *st=getchar();
    while (*st ==' '|| *st =='\t')
       *st=getchar();
    while (*st !=' '&& *st !='\t' && *st !='\n' && i<N)
    {
        *++st=getchar();
        i++;
    }
    *st='\0';
}
*//*
//ex5 аналог strchr()
#include<stdio.h>
#include<string.h>
#define N 25
void s_getn(char *, int );
char* n_strchr(char*,char);
int main(void)
{
    char save[N+1];
    char *find;
    puts("Вводим строку:");
    s_getn(save,N);
    while (strcmp(save,"q"))
    {
        puts(save);
        char alpha;
        puts("Введите букву");
        scanf("%c",&alpha);
        while (getchar() != '\n')
            ;
        find = n_strchr(save, alpha);
        puts(find);
        puts("\nВведите новую строку или q для выхода");
            s_getn(save,N);
    }
    return 0;
}
void s_getn(char *st, int n)
{
    int i=0;
    *st=getchar();
    while (*st !='\n' && *st != '\0' && i<N)
    {
        *++st=getchar();
        i++;
    }
    if (*st =='\n')
        *st='\0';
    else
        while(getchar() !='\n')
            ;
}
char* n_strchr(char* st,char a)
{
    while (*st !=a && *st !='\0')
    {
        st++;
    }
    if (*st == '\0')
        return NULL;
    return st;
}*/
/*
//ex6 функция возвращающая 1 когда символ есть в строке и 0 когда нет
#include<stdio.h>
#include <string.h>
#define N 25
void s_getn(char *, int );
int is_within(char*,char);
int main(void)
{
    
    char save[N+1];
    puts("Введите строку");
    s_getn(save,N);

    while (strcmp(save,"q"))
    {

        char alpha;
        puts("Введите букву:");

        scanf("%c",&alpha);
        
        while (getchar() != '\n')
               continue;
        
        if (is_within(save,alpha)>0)
        {
            puts("Есть такая буква в этом слове.\n");
        }
        else
            puts("Мы не нашли Вашу букву(((\n");
        puts("Введите новую строку или q для выхода");
        s_getn(save,N);
    }
    puts("Программа завершена");
    return 0;
}
    
void s_getn(char *st, int n)
{
    int i=0;
    *st=getchar();

    while (*st !='\n' && st !='\0' && i<n)
    {
        *++st=getchar();
        i++;
    }
    if (*st =='\n')
        *st='\0';
    else
        while(getchar() !='\n')
            ;
}
int is_within(char* st,char a)
{
    while (*st !=a && *st !='\0')
    {
        st++;
    }
    if (*st == '\0')
        return 0;
    return 1;
}

*//*
//ex7 ф-ция mystrncpy()
#include<stdio.h>
#include<string.h>
#define N 80
#define M 10
char *mystrncpy (char *,char *,int);
void s_getn(char *, int );
int main(void)
{
    
    char initial[N];
    char copy_string[M];
    
    puts("Введите строку");
    s_getn(initial,N);
    while(strcmp(initial,"q"))
    {
        puts("Введите количество букв для копирования ( не более 50):");
        int num_let;
        scanf("%d", &num_let);
        while(getchar() != '\n')
            ;
        printf("Копия %d символов:%s \n",num_let,mystrncpy(copy_string, initial, num_let));
        puts("Введите строку новую строку или q для выхода");
        s_getn(initial,N);
    }
}
void s_getn(char *st, int n)
{
    int i=0;
    *st=getchar();

    while (*st !='\n' && st !='\0' && i<n)
    {
        *++st=getchar();
        i++;
    }
    if (*st =='\n')
        *st='\0';
    else
        while(getchar() !='\n')
            ;
}
char *mystrncpy (char *s1,char *s2,int n)
{
    int i = 0;
    char *t = s1;
    while (*s2 !='\0'&& *s2 !='\n' && i<n)
    {
        *s1 = *s2;
        s1++;s2++;
        i++;
    }
    *s1='\0';
    return t;
}
*//*
//ex8
#include <stdio.h>
#include<ctype.h>
#include<string.h>
void get_str(char*);
char* string_in(char *,char *);
int main(void)
{
    char initial[]="If you can keep your head when all about are loosing theiers and blaimint it on you";
    puts(initial);
    char fstring[25];
    puts("\nВведите подстроку:");
    fgets(fstring,25,stdin);
    char *find;
    find = strchr(fstring,'\n');
    if(find)
        *find = '\0';
    printf("Адресс inittial %p\n",&initial);
    printf("Адресс can%p\n",&initial[7]);
    printf("Адресс fstring %p\n",&fstring);
    char* adress = string_in(initial, fstring);
    if (adress)
        printf("Адресс подстроки:%p\n",adress);//указываем просто название массива а не адрес & так как в таком случае выводится адрес где хранися сама ссылака  adress а не её содреждимое
    else
        printf("Такая подстрoка остутствует в этом предложении.\n");
    
    return 0;
}
char* string_in(char *st1,char *st2)
{
    char *begin = st2;
    int ok=0;
    char * super=NULL;
    while (*st1 !='\0')
    {
        if (*st1 !=*begin)
            st1++;
        else
        {
            super = st1;
            ok=1;
            while (*begin !='\0')
            {
                if(*st1++ !=*begin++)
                {
                    ok = 0;
                    begin = st2;
                    super = NULL;
                    break;
                }
            }
        }
        if (ok)
            break;
    }
    return super;
  
}*/
/*
//ex9  выводим слово в обратном порядке
#include<stdio.h>
#include<string.h>
#define N 80
char * s_reverse(char *,int);
char * s_gets(char *, int);
int main(void)
{
    char line[N];
    puts("Введите слово:");
    s_gets(line,N);
    while (strcmp(line,"q"))
    {
        printf("Мы получили:%s\n",s_reverse(line,N));
        puts("Введите новое слово или q для выхода:");
        s_gets(line,N);
    }
   
    
    return 0;
}
char * s_gets(char *st,int n)
{
    char *ret_val;

    
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        while (*st != '\n' && *st !='\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

char * s_reverse (char *st, int M)
{
    char t;
    int i,j;
    int n = (int)strlen(st);
    for (i=0,j = n-1;i<n/2;i++,j--)
    {
        t=st[i]; st[i]=st[j];st[j]=t;
    }

    st[n]='\0';
    
    return st;
}
*//*
//ex10
#include<stdio.h>
#include<string.h>

#define N 50
char* s_get(char *,int);
char* wSpace(char*);
int main(void)
{
    puts("Вводим строку:");
    char line[N];
    s_get(line,N);
    while(strcmp(line,""))
    {
        printf("Мы получили: %s\n",wSpace(line));
        puts("Вводим новую строку или нажимаем Enter для выхода:");
        s_get(line,N);
    }
    return 0;
}
char* s_get(char *st,int n)
{
    char * ret_val;
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        while (*st !='\n' && *st !='\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while(getchar() != '\n')
                ;
    }
    return ret_val;
}
char* wSpace(char *st)
{
    char* begin = st;

    while (*st != '\0')
    {
        if (*st !=' ')
            st++;
        else
        {
            char* change= st;
            while (*(st+1) != '\0')
            {
                *st = *(st+1);
                st++;
            }
            *st='\0';
            st = change;
        }
    }
    return begin;
}
*//*
//ex11 к сожалению применение EOF в коде приводит к завершению работы программы или ее зацикливанию по этой причине ипользовался выход по нажатию Enter
#include<stdio.h>
#include<string.h>
#define N 10
#define STLEN 50
char* get_strings(char st[],int n);
int menu(void);
void strsrt2 (char * strings[],int n);
void strsrt3 (char * strings[],int n);
void strsrt4 (char * strings[],int n);
char* get_first(char* str,char *str2);
void display(char [][STLEN],int);
int main(void)
{
    puts("Введите  строки до 10 штук или нажмите Ctrl-D в начале новой строки для выхода");
    char safeOfStrings[N][STLEN];
    char *pstr[N];// массив указателей на строки
    //вводим строки
    int ct = 0;
    while (ct<N && get_strings(safeOfStrings[ct],STLEN) != NULL && safeOfStrings[ct][0] !='\0')
    {
        pstr[ct]=safeOfStrings[ct]; //установка указателей на строки
        ct++;
    }
    
    int _menu;

    while ((_menu = menu()) != 5)
    {
        switch (_menu) {
            case 1:
                display(safeOfStrings,ct);
                break;
            case 2:
                strsrt2(pstr, ct);
                break;
            case 3:
                strsrt3(pstr,ct);
                break;
            case 4:
                strsrt4(pstr, ct);
                break;
            default:
                break;
        }
    }

    return 0;
}

void strsrt4 (char * strings[],int n)
{
    char *temp;
    char first1[n],first2[n];
    int top,seek;
    for (top = 0;top < n-1; top++)
        for (seek = top + 1; seek <  n;seek++)
        {
            if (strlen(get_first(first1,strings[top]))>strlen(get_first(first2,strings[seek])))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    for (int k = 0;k < n;k++)
        puts(strings[k]);
    
}
char* get_first(char* first,char* main)//возвращает первое слово из строки
{

    char *begin = first;
    while(*main != ' ' && *main !='\0')
    {
        *first++ = *main++;

    }
    *first = '\0';
    return begin;
}
void strsrt3 (char * strings[],int n)
{
    char *temp;
    int top,seek;
    for (top = 0;top < n-1; top++)
        for (seek = top + 1; seek <  n;seek++)
        {
            if (strlen(strings[top])>strlen(strings[seek]))
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    for (int k = 0;k < n;k++)
        puts(strings[k]);
}

void strsrt2 (char * strings[],int n)
{
    char *temp;
    int top,seek;
    for (top = 0;top < n-1;top++)
        for (seek = top + 1;seek < n;seek++)
        if (strcmp(strings[top],strings[seek]) > 0)
        {
            temp = strings[top];
            strings[top] = strings[seek];
            strings[seek] = temp;
        }
    for (int k = 0;k < n;k++)
        puts(strings[k]);

}

int menu(void)//меню
{
    
    printf("Выберите дальнейшие действия, нажав соответствующую цифру:\n");
    printf("1.Вывод исходного списка слов.\n2.Вывод строк согласно последовательсности сопоставления ASCII&\n");
    printf("3. Вывод строк в порядке возрастания длины.\n");
    printf("4. Вывод строк в порядке возрастания длины первого слова в строке.\n");
    printf("5. Выход из программы\n");
    
    int p_menu;

    while ((scanf("%d",&p_menu) !=1) ||p_menu >5 || p_menu <1)
    {
        while (getchar() != '\n')
               ;
        printf("Вы ввели что то не то, попробуйте еще раз. ");
    }
    return p_menu;
        
}
void display(char arstr[][STLEN],int n)
{
    for (int j = 0;j<n;j++)
        puts(arstr[j]);
}
char* get_strings(char test[], int n)
{
   
    int i = 0;
    int ch = getchar();
   // if ( ch != EOF)
   // {
        while (ch !='\n' && ch !='\0' && i<n)
        {
            test[i]=ch;i++;
            ch=getchar();
        }
        if (ch =='\n' )
            test[i]='\0';
        else
            while(getchar() !='\n')
                ;
        return test;
   // }
   // else
   //     return NULL;
}
*//*
//ex12
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main(void)
{
    puts("Вводим текст:");
    int ch;
    int cntW,cntBL,cntLL,cntP,cntD;
    cntW=cntBL = cntLL = cntP = cntD = 0;//количество слов, количество заглавных букв, количество прописных букв, количество знаков пунктуации, количество цифр
    bool inword = false;
    
    while ((ch =getchar()) != EOF)
    {
        if (isupper(ch))
            cntBL++;
        if (islower(ch))
            cntLL++;
        if (ispunct(ch))
            cntP++;
        if (isdigit(ch))
            cntD++;
        if(!isspace(ch) && !inword)
        {
            inword = true; //начало нового слова
            cntW++; //считаем слова
        }
        if(isspace(ch) && inword)
            inword = false;
    }
    printf("Количество слов:%d\n",cntW);
    printf("Количество заглавных букв:%d\n",cntBL);
    printf("Количество прописных букв:%d\n",cntLL);
    printf("Количество знаков пунктуации:%d\n",cntP);
    printf("Количество цифр:%d\n",cntD);
    
    return 0;
}
   *//*
//ex обратный вывод из командной строки
#include<stdio.h>

char *s_reverse (char *st,int n);
int main( int argc, char *argv[])
{
    int count ;
    for (count = argc -1; count>0;count--)
        printf("%s ",argv[count]);
    
}

*//*
//ex14 реализация степенной зависимости
#include<stdio.h>
#include<stdlib.h>
double power(double a,int n);
int main(int argc,char *argv[])
{
    printf("result:%.2lf",power(atof(argv[1]),atoi(argv[2])));
}
double power(double a,int n)
{
    int res = 1;
    for (int i = 0;i < n;i++)
        res *= a;
    return res;
}
*//*
//ex15 классификация символов
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
bool isAllDigit(char *);
int main(void)
{
    char line[]="1234b56";
    printf("%d\n",isAllDigit(line));
    return 0;
}
bool isAllDigit(char * st)
{
    bool dg = true;
    while (*st !='\0')
    {
        dg *= isdigit(*st);
        st++;
    }
    return dg;
}

*/
//ex16 чтение входных данных
#include<stdio.h>
#include<ctype.h>
int  s_gets(char *, int);
char*  toUp (char *);
char * toDown (char *);
void menu(char, char *);

int main(int argc, char * argv[])
{
    puts("Вводим текст:");
    char line[50];
    char ch = argv[1][1];
    int _menu;
    while((_menu = s_gets(line,50)) != EOF)
        menu(ch,line);
    return 0;
}
void menu(char ch,char * line)
{
    
    switch (ch) {
        case 'p':
        case '\0':
            puts(line);
            break;
        case 'u':
            puts(toUp(line));
            break;
        case 'l':
            puts(toDown(line));
            break;
        default:
            break;
    }
}
char *toDown (char * st)
{
    char *begin = st;
    while (*st)
    {
        *st = tolower(*st);
        st++;
    }
    return begin;
}

char * toUp(char * st)
{
    char *begin = st;
    while (*st)
    {
        *st = toupper(*st);
        st++;
    }

    return begin;
}

int s_gets(char* test,int n)
{
   
    int i = 0;
    int ch = getchar();
   if ( ch != EOF)
    {
        while (ch !='\n' && i<n)
        {
            test[i]=ch;i++;
            ch=getchar();
        }
       if (ch =='\n' )
            test[i]='\0';
        else
            while(getchar() !='\n')
                ;
        return 1;
    }
    else
        return EOF;
}

