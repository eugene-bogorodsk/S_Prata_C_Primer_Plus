//
//  main.c
//  chapter17
//
//  Created by пупсик on 11.05.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_17_2 использование связного списка структур
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film *next;// указывает на следующую структуру в списке
};

void show_reverse(struct film *);
char *s_gets(char *st,int n);

int main() {

    struct film *head = NULL;
    struct film *prev = NULL,*current;
    char input[TSIZE];
    
    //сбор и сохранение информации
    puts("Введите название первого фильма:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));//программа запрашивает простраство для стукртуры и присваивает ее адрес указателю current
        if (head == NULL) //адрес самой первой структуры должен быть сохранен в переменной указателя head
            head = current;
        else
            prev->next = current; //указатель на структуру выделенный в прошлый раз
        current->next = NULL;
        strcpy(current->title,input);
        puts("Введите свое значение рейтинга <0-10>:");
        scanf("%d",&current->rating);
        while(getchar() != '\n')
            ;
        puts("Введите название следующего фильма (или пустую строку для прекращения ввода):");
        prev=current;//указатель prev нужно установить так чтобы он  ссылался на текущую структуру так как после ввода названия следующего фильма текущая структура станет предыдыдущей
    }
    
    //отображение списка фильмов
    if (head == NULL)
        printf("Данные не введены.");
    else
        printf("Список фильмов:");
    current = head;//нельзя исползовать head так как это привело бы к потере указателя  на начало списка
    while (current != NULL)
    {
        printf("Фильм: %s Рейтинг: %d\n", current->title,current->rating);
        current = current->next;
    }
    
    //ex_1 отображение списка фильмов в обратную сторону через рекурсию
    //current = head;
    //printf("Список фильмов в обратную сторону:\n");
    //show_reverse(current);
    
    //программа выполненна поэтому можно освободить память
    current = head;
    while (current != NULL)
    {
       
        head = current->next;
        free(current);
        current = head;
    }
    
    puts("Программа завершена");
    return 0;
}

void show_reverse(struct film *current)
{
    if (current !=NULL)
    {
        show_reverse(current->next);
        printf("Фильм: %s Рейтинг: %d\n", current->title,current->rating);
    }
    else
        return;

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
            while (getchar() != '\n')
                ;
    }
    return ret_val;
}*/
/*
//list_17_4 использование связанного списка в стиле ADT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "list.h"
//#include "list2.h" // подключаем файл для решения задания 2
#include "list3.h"//подключаем файл для решения задания 3
void showmovies(Item item);
char *s_gets(char *st,int n);

int main(void)
{
    List movies;
    Item temp;
    
    // инициализация
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr,"Доступная память отсутствует! Программа завершена.\n");
        exit(1);
    }
    //сбор и сохранение информации
    puts("Введите название первого фильма:");
    while (s_gets(temp.title,TSIZE) != NULL && temp.title[0] !='\0')
    {
        puts("Введите свое значение рейтинга <0-10>:");
        scanf("%d",&temp.rating);
        while (getchar() !='\n')
            ;
        if (AddItem(temp,&movies) == false)
        {
            fprintf(stderr,"Проблема с выделением памяти\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("Список полон.");
            break;
        }
        puts("Введите название следующего фильма (или пустую строку для прекращения ввода):");
    }
    //отображение
    if (ListIsEmpty(&movies))
        printf("Данные не введены.");
    else
    {
        printf("Список фильмов:\n");
        Traverse(&movies,showmovies);
        
    }
    printf("Вы ввели %d фильмов.\n",ListItemCount(&movies));
    //очистка
    EmptyTheList(&movies);
    printf("Программа завершена.\n");
    
    return 0;
}

void showmovies(Item item)
{
    printf("Фильм %s  Рейтинг:%d\n",item.title,item.rating);
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
            *find ='\0';
        else
            while (getchar() != '\n')
                ;
    }
    return ret_val;
}*/
/*
//list_17_8  тестирование Queue c  помощью драйвера
#include <stdio.h>
#include "queue.h" //определение Queue,Item

int main(void)
{
    Queue line;
    Item temp;
    char ch;
    
    InitializeQueue(&line);
    puts("Тестирование интерфейса Queue. Введите a чтобы добавить значение,");
    puts("Введите d чтобы удалить значение, или введите q для выхода из программы");
    while((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd') // игнорировать другие вводимые данные
            continue;
        if (ch == 'a')
        {
            printf("Целое число для добавления: ");
            scanf("%d",&temp);
            if (!QueueIsFull(&line))
            {
                printf("Помещение %d в очередь\n",temp);
                EnQueue(temp,&line);
            }
            else
                puts("Очередь полна!");
        }
        else
        {
            if (QueueIsEmpty(&line))
                puts("Элементы для удаления отсутствуют!");
            else
            {
                DeQueue(&temp, &line);
                printf("Удаление %d из очереди\n",temp);
            }
        }
        printf("%d элемент(ов) в очереди\n",QueueItemCount(&line));
        puts("Введите a чтобы добавить d чтобы удалить или q для выхода из программы:");
    }
    EmptyTheQueue(&line);
    puts("Программа завершена.");
    
    return 0;
}
   *//*
//list_17_9 моделируем киоск
#include <stdio.h>
#include <stdlib.h> //для rand() и srand()
#include <time.h> // для time()
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x); //имеется новый клиент?
Item customertime(long when); //установка параметров клиента

int main(void)
{
    Queue line;
    Item temp; //данные о новом клиенте
    int hours; //количество часов моделирования
    int perhour; //среднее количество прибывающих клиентов в час
    long cycle,cyclelimit; //счетчик и граничное значение цикла
    long turnaways = 0;//количество отказов из-за переполненной очереди
    long customers = 0; //количество клиентов, присоединившихся к очереди
    long served = 0; // количество клиентов, обслуженных во время моделирования
    long sum_line = 0; //накопительное значение длины очереди
    int wait_time = 0; //время до освобождения Зигмуда
    double min_per_cust; //среднее время между прибытиями клиентов
    long line_wait = 0; //накопительное значение времени в очереди
    
    InitializeQueue(&line);
    srand((unsigned int) time(0)); //случайная инициализация rand()
    puts ("Учебный пример: консультационный киоск Зигмунда Ландера");
    puts("Введите длительность моделирования в часах:");
    scanf("%d",&hours);
    cyclelimit = MIN_PER_HR*hours;
    puts("Введите среднее количество клиентов, прибывающих за час:");
    scanf("%d",&perhour);
    min_per_cust = MIN_PER_HR/perhour;
    
    for (cycle = 0; cycle <cyclelimit; ++cycle)
    {
        if(newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line))
                ++turnaways;
            else
            {
                ++customers;
                temp = customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if (wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp, &line);// удаляем первого клиента из очереди и передаем его на обслуживание
            wait_time = temp.processtime;// время обслуживания установлено при постановке клиента в очередь
            line_wait += cycle-temp.arrive;//текущее время минус время прибытия этого клиента это время нахождения его в очереди суммируем его с временем ожидания других клиентов что бы определить суммарное время нахождения клиентов в очереди
            ++served; //увеличиваем счетчик обслуженных клиентов
        }
        if (wait_time > 0) //если время обслужинваия еще не истекло просто стоим в очереди ждем
            --wait_time;
        
        sum_line += QueueItemCount(&line);// увеличиваем счетчик находящихся в очереди клиентов
    }
    if (customers > 0)
    {
        printf("   принятых клиентов: %ld\n", customers);
        printf(" обслуженных клиентов: %ld\n",served);
        printf("       отказов:%ld\n", turnaways);
        printf("средняя длина очереди: %.2f\n",(double) sum_line/cyclelimit);
        printf("среднее время ожидания: %.2f мин\n",(double) line_wait/served);
    }
    else
        puts("Клиенты отсутствуют!");
    EmptyTheQueue(&line);
    puts("Программа завершена.");
    
    return 0;
}

//x среднее время между прибытием клиентов в минутах возвращает true если клиент появляется в течение данной минуты
bool newcustomer(double x)
{
    if (rand()*x/RAND_MAX < 1)
        return true;
    else
        return false;
}

//when время прибытия клиента функция возвращает структуру Item co временем прибытия,установленным в when и временем обслуживания установленным в случайное значение из диапазона от 1 до 3
Item customertime(long when)
{
    Item cust;
    
    cust.processtime = rand()%3 + 1;
    cust.arrive = when;
    
    return cust;
}
*//*
//list_17_12 использование двоичного дерева поиска
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include"tree.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st,int n);

#define SLEN 40

int main(void)
{
    Tree pets;
    char choice;
    
    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice) {
            case 'a':addpet(&pets);
                break;
            case 'l':showpets(&pets);
                break;
            case 'f':findpet(&pets);
            case 'n':printf("%d животных в клубе\n",TreeItemCount(&pets));
                break;
            case 'd':droppet(&pets);
                break;
            default: puts("Ошибка в switch");
                
        }
    }
    DeleteAll(&pets);
    puts("Программа завершена.");
    
    return 0;
}

char menu(void)
{
    int ch;
    puts("Программа членства в клубе Nerfville Pet Club");
    puts("Введите букву, соответствующую вашему выбору:");
    puts("a) добавление животного   l)вывод списка животных");
    puts("n)количество животных    f)поиск животных");
    puts("d) удаление животного    q)выход");
    
    while((ch = getchar()) != EOF)
    {
        while(getchar()!='\n') //отбросить остувшуюся часть строки
            ;
        ch =tolower(ch);
        if (strchr("alrfndq",ch) == NULL)
            puts("Введите букву a,l,f,n,d или q:");
        else
            break;
    }
    if (ch == EOF) //ввод смвола EOFприводит к выходу из программы
        ch = 'q';
    
    return ch;
}

void addpet(Tree *pt)
{
    Item temp;
    if (TreeIsFull(pt))
        puts("В клубе больше нет мест!");
    else
    {
        puts("Введите кличку животного:");
        s_gets(temp.petname,SLEN);
        puts("Введите вид животного:");
        s_gets(temp.petkind,SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp,pt);
    }
    
}

void showpets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("Записи отсутствуют");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    printf("Животное:%-19s  Вид: %-19s\n", item.petname,item.petkind);
}

void findpet(const Tree *pt)
{
    Item  temp;
    if (TreeIsEmpty(pt))
    {
        puts("Записи отсутствуют!");
        return;//если дерево пустое выйти из функции
    }
    
    puts("Введите кличку животного которое хотите найти:");
    s_gets(temp.petname,SLEN);
    puts("Введите вид животного:");
    s_gets (temp.petkind,SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s по имени %s",temp.petkind,temp.petname);
    if (InTree(&temp, pt))
        printf("является членом клуба.\n");
    else printf("не является членом клуба.\n");
}

void droppet(Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("Записи отсутствуют!");
        return;//если дерево пустое выйти из функции
    }
    puts("Введите кличку животного, которе нужно исключить из клуба:");
    s_gets(temp.petname,SLEN);
    puts("Введите вид животного:");
    s_gets(temp.petkind,SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s по имени %s ", temp.petkind,temp.petname);
    if (DeleteItem(&temp, pt))
        printf("исключен(а) из клуба.\n");
    else
        printf("не является членом клуба.\n");
}

void uppercase(char *str)
{
    while(*str)
    {
        *str = toupper(*str);
        ++str;
    }
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
            while (getchar() != '\n')
                   ;
    }
    return ret_val;
}
*//*
//ex_4 моделируем киоск c двумя окошками
#include <stdio.h>
#include <stdlib.h> //для rand() и srand()
#include <time.h> // для time()
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x); //имеется новый клиент?
Item customertime(long when); //установка параметров клиента

int main(void)
{
    Queue line1,line2;
    Item temp; //данные о новом клиенте
    int hours; //количество часов моделирования
    int perhour; //среднее количество прибывающих клиентов в час
    long cycle,cyclelimit; //счетчик и граничное значение цикла
    long turnaways = 0;//количество отказов из-за переполненной очереди
    long customers = 0; //количество клиентов, присоединившихся к очереди
    long served = 0; // количество клиентов, обслуженных во время моделирования
    long sum_line = 0; //накопительное значение длины очереди
    int wait_time1 = 0; //время до освобождения 1-го окна
    int wait_time2 = 0; //время до освобождения 2-го окна
    double min_per_cust; //среднее время между прибытиями клиентов
    long line_wait = 0; //накопительное значение времени в очереди
    
    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int) time(0)); //случайная инициализация rand()
    puts ("Учебный пример: консультационный киоск Зигмунда Ландера");
    puts("Введите длительность моделирования в часах:");
    scanf("%d",&hours);
    cyclelimit = MIN_PER_HR*hours;
    puts("Введите среднее количество клиентов, прибывающих за час:");
    scanf("%d",&perhour);
    min_per_cust = MIN_PER_HR/perhour;
    
    for (cycle = 0; cycle <cyclelimit; ++cycle)
    {
        if(newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line1) && QueueIsFull(&line2))
                ++turnaways;
            else
            {
                ++customers;
                temp = customertime(cycle);
                if (QueueItemCount(&line1) < QueueItemCount(&line2))
                    EnQueue(temp, &line1);
                else
                    EnQueue(temp, &line2);
            }
        }
        if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&temp, &line1);// удаляем первого клиента из очереди и передаем его на обслуживание
            wait_time1 = temp.processtime;// время обслуживания установлено при постановке клиента в очередь
            line_wait += cycle-temp.arrive;//текущее время минус время прибытия этого клиента это время нахождения его в очереди суммируем его с временем ожидания других клиентов что бы определить суммарное время нахождения клиентов в очереди
            ++served; //увеличиваем счетчик обслуженных клиентов
        }
        
        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait += cycle-temp.arrive;
            ++served;
        }
        if (wait_time1 > 0) //если время обслужинваия еще не истекло просто стоим в очереди ждем
            --wait_time1;
        
        if (wait_time2 > 0)
            --wait_time2;
        
        sum_line += QueueItemCount(&line1) + QueueItemCount(&line2);// увеличиваем счетчик находящихся в очереди клиентов
    }
    if (customers > 0)
    {
        printf("   принятых клиентов: %ld\n", customers);
        printf(" обслуженных клиентов: %ld\n",served);
        printf("       отказов:%ld\n", turnaways);
        printf("средняя длина очереди: %.2f\n",(double) sum_line/(2*cyclelimit));
        printf("среднее время ожидания: %.2f мин\n",(double) line_wait/served);
    }
    else
        puts("Клиенты отсутствуют!");
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Программа завершена.");
    
    return 0;
}

//x среднее время между прибытием клиентов в минутах возвращает true если клиент появляется в течение данной минуты
bool newcustomer(double x)
{
    if (rand()*x/RAND_MAX < 1)
        return true;
    else
        return false;
}

//when время прибытия клиента функция возвращает структуру Item co временем прибытия,установленным в when и временем обслуживания установленным в случайное значение из диапазона от 1 до 3
Item customertime(long when)
{
    Item cust;
    
    cust.processtime = rand()%3 + 1;
    cust.arrive = when;
    
    return cust;
}
*//*
//ex_5
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "steck.h"

#define MAXSTR 50
char *s_gets(char *st,int n);

int main(void)
{
    char ch;
    Stack stack;
    InitializeStack(&stack);
    puts("Вводим строку:");
    while((ch = getchar()) != '\n' && Push(ch, &stack))
          ;

    while(Pop(&ch, &stack))
        putchar(ch);
    puts("");
    
    
    return 0;
}

*//*
//ex_6
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int bi_find(int [], int, int);
int mycomp(const void *p1,const void *p2);
int main(void)
{
    int ar [MAX] = {4,17,3,1,25,43,8,9,100};
    int fnd = 30;
    qsort(ar,MAX,sizeof(int),mycomp);
    
    printf("%d\n",bi_find(ar,MAX,fnd));
    return 0;
}
int bi_find(int ar[], int n, int f)
{
    int left = 0;
    int right = n-1;
    int middle;
    while (left+1 <right)
    {
        middle = (left + right)/2;
        if (ar[middle] == f)
            return 1;
        else
        {
            if (ar[middle]< f)
                left = middle;
            else
                right = middle;
        }
    }
    return 0;
}
int mycomp(const void *p1,const void *p2)
{
    const int *a1 = (const int *) p1;
    const int *a2 = (const int *)p2;
    
    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;
}
*//*
//ex_7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

#define MAX 45

char menu(void);
void printitem(Item item);
void showwords (const Tree *pt);
void findword(const Tree  *pt);

int main(void)
{
    FILE *fin;
    char in_word[MAX];
    char file[] = "testfile.txt";
    while ((fin = fopen(file,"r")) == NULL)
    {
        fprintf(stderr,"Не удается открыть файл \"%s\"\n",file);
        exit(EXIT_FAILURE);
    }
    
    Tree trwords;
    Item temp;
    InitializeTree(&trwords);
    while (fscanf(fin,"%s",in_word) == 1)
    {
        strcpy(temp.word,in_word);
        temp.count = 1;
        AddItem(&temp, &trwords);
    }
    
    char choice;
    while ((choice = menu()) != '3')
    {
        switch (choice) {
            case '1':
                 showwords(&trwords);
                break;
            case '2':
                findword(&trwords);
                break;
            case '3':
                puts("Выходим из программы");
                break;
            default:
                break;
        }
    }
   
    DeleteAll(&trwords);
    
    puts("Программа завершена");
    
    return 0;
}

void findword(const Tree  *pt)
{

    Item temp;
    puts("Введите слово которое хотите найти");
    scanf("%s",temp.word);
    while (getchar() != '\n')
        ;
    printf("В словаре %d слов %s\n",CountOfWords(&temp,pt),temp.word);
    
}

char menu(void)
{
    int ch;
    puts("Программа подсчета слов в тексте");
    puts("Введите цифру соответствующую Вашему выбору");
    puts("1) вывод всех слов с указанием повторений");
    puts("2) количество вхождений заданного слова");
    puts("3) выход из программы");
    
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')
            ;
        ch = tolower(ch);
        if (strchr("123",ch) == NULL)
            puts("Введите цифры 1 2 или 3");
        else
            break;
    }
    if (ch == EOF)
        ch = '3';
    
    return ch;
}

void showwords (const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("Записи отсутствуют");
    else
        Traverse(pt,printitem);
}
void printitem(Item item)
{
    printf("%-10s встречается  %d раз\n",item.word,item.count);
}
*/
//ex_8 хранение списка в дереве

#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include"tree8.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st,int n);

#define SLEN 40

int main(void)
{
    Tree pets;
    char choice;
    
    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice) {
            case 'a':addpet(&pets);
                break;
            case 'l':showpets(&pets);
                break;
            case 'f':findpet(&pets);
                break;
            case 'n':printf("%d животных в клубе\n",TreeItemCount(&pets));
                break;
            case 'd':droppet(&pets);
                break;
            default: puts("Ошибка в switch");
                
        }
    }
    DeleteAll(&pets);
    puts("Программа завершена.");
    
    return 0;
}

char menu(void)
{
    int ch;
    puts("Программа членства в клубе Nerfville Pet Club");
    puts("Введите букву, соответствующую вашему выбору:");
    puts("a) добавление животного   l)вывод списка животных");
    puts("n)количество животных    f)поиск животных");
    puts("d) удаление животного    q)выход");
    
    while((ch = getchar()) != EOF)
    {
        while(getchar()!='\n') //отбросить остувшуюся часть строки
            ;
        ch =tolower(ch);
        if (strchr("alrfndq",ch) == NULL)
            puts("Введите букву a,l,f,n,d или q:");
        else
            break;
    }
    if (ch == EOF) //ввод смвола EOFприводит к выходу из программы
        ch = 'q';
    
    return ch;
}

void addpet(Tree *pt)
{
    Item temp;
    if (TreeIsFull(pt))
        puts("В клубе больше нет мест!");
    else
    {
        puts("Введите кличку животного:");
        s_gets(temp.petname,SLEN);
        puts("Введите вид животного:");
        s_gets(temp.petkind[0],SLEN); // записываем тип животного в нулевую ячейку массива petkind
        uppercase(temp.petname);
        uppercase(temp.petkind[0]);
        temp.count = 1;//добавляем животное к списку
        AddItem(&temp,pt);
    }
    
}

void showpets(const Tree *pt)
{
    if (TreeIsEmpty(pt))
        puts("Записи отсутствуют");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    for (int i = 0 ;i < item.count; ++i)
        printf("Животное:%-19s Вид: %-19s\n",item.petname,item.petkind[i]);

}

void findpet(const Tree *pt)
{
    Item  temp;
    if (TreeIsEmpty(pt))
    {
        puts("Записи отсутствуют!");
        return;//если дерево пустое выйти из функции
    }
    // по условию мы ищем животное тольк по кличке
    puts("Введите кличку животного которое хотите найти:");
    s_gets(temp.petname,SLEN);

    uppercase(temp.petname);
  
    if (!InTree(&temp, pt))
        printf("К сождалению в клубе таких животных нет.\n");
    else
    {
        printf("У нас имеются следующие животные по  имени %s\n",temp.petname);
        printitem(FindPet(&temp,pt));
    }
}

void droppet(Tree *pt)
{
    Item temp;
    if (TreeIsEmpty(pt))
    {
        puts("Записи отсутствуют!");
        return;//если дерево пустое выйти из функции
    }
    puts("Введите кличку животного, которе нужно исключить из клуба:");
    s_gets(temp.petname,SLEN);
    puts("Введите вид животного:");
    s_gets(temp.petkind[0],SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind[0]);
    printf("%s по имени %s ", temp.petkind[0],temp.petname);
    if (DeleteItem(&temp, pt))
        printf("исключен(а) из клуба.\n");
    else
        printf("не является членом клуба.\n");
}

void uppercase(char *str)
{
    while(*str)
    {
        *str = toupper(*str);
        ++str;
    }
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
            while (getchar() != '\n')
                   ;
    }
    return ret_val;
}
