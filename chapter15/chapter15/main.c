//
//  main.c
//  chapter15
//
//  Created by пупсик on 29.04.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
//list_15_1 использование операций с битами для отображения двоичного предстваления чисел
#include <stdio.h>
#include <limits.h> //для CHAR_BIT  количество битов на символ

char *itobs(int,char *);
void show_bstr(const char *);

int main(void) {
    char bin_str[CHAR_BIT*sizeof(int) +1];
    int number;
    
    puts("Введите целые числа и просматривайте их двоичное предстваления.");
    puts("Нечисловой ввод завершает программу.");
    while (scanf("%d",&number) == 1)
    {
        itobs(number,bin_str);
        printf("%d представляется как ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Программа завершена.");
    
    return 0;
}
char *itobs(int n, char *ps)
{
    int i ;
    const static int size = CHAR_BIT*sizeof(int);
    
    for (i = size - 1;i >= 0;i--, n >>=1)
        ps[i] = (01&n) + '0'; //предполагается кодировка ASCII
    ps[size] = '\0';
    
    return ps;
}

//отображение двоичной строки блоками по 4
void show_bstr(const  char *str)
{
    int i = 0;
    while (str[i]) //пока не будет получен нулевой символ
    {
        putchar(str[i]);
        if (++i%4 == 0 && str[i])
            putchar(' ');
    }
}
*//*
//ex_2 list_15_2 использование операций с битами для отображения двоичного преставления чисел
#include<stdio.h>
#include<limits.h>
char *itobs(int,char*);
void show_bstr(const char*);
int invert_end(int num,int bits);

int main(void)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;
    puts ("Вводите целые числа и просмативайте их двочиные представления.");
    puts("Нечисловой ввод завершает программу.");
    while (scanf("%d",&number) == 1)
    {
        itobs(number, bin_str);
        printf("%d представляется как \n",number);
        show_bstr(bin_str);
        putchar('\n');
        number = invert_end(number,4);
        printf("Инвертирование последних 4 битов дает\n");
        show_bstr(itobs(number,bin_str));
        putchar('\n');
    }
    puts("Программа завершена.");
    
    return 0;
}

char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT*sizeof(int);
    for (i = size - 1; i >= 0;i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';
    
    return ps;
}

//отображение двоичной строки блоками по 4
void show_bstr(const char *str)
{
    int i = 0;
    while (str[i]) //пока не будет получен нулевой символ
    {
        putchar(str[i]);
        if(++i%4 == 0 && str[i])
            putchar(' ');
    }
}
int invert_end(int num,int bits)
{
    int mask = 0;
    int bitval = 1;
    while(bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    
    return num ^ mask;
}
*//*
//ex_3 list 15_3 оперделение и использование полей
#include <stdio.h>
#include <stdbool.h>
//стили линии
#define SOLID 0
#define DOTTED 1
#define DASHED 2
//основные цвета
#define BLUE 4
#define GREEN 2
#define RED 1
//смешанные цвета
#define BLACK 0
#define YELLOW (RED|GREEN)
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define WHITE (RED|GREEN|BLUE)

const char *colors[8] = {"black","red","green","yellow","blue","magenta","cyan","white"};

struct box_props{
    bool opaque              :1;//или unsigned int
    unsigned int fill_color  :3;
    unsigned int             :4;
    bool show_border         :1;
    unsigned int border_color:3;
    unsigned int border_style:2;
    unsigned int             :2;
};

void show_settings(const struct box_props *pb);
int main(void)
{
    //создание и инициализация структуры box_props
    struct box_props box ={true,YELLOW,true,GREEN,DASHED};
    
    printf("Исходные настройки окна:\n");
    show_settings(&box);
    
    box.opaque = false;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    
    printf("\nИзмененные настройки окна:\n");
    show_settings(&box);
    
    return 0;
}

void show_settings(const struct box_props *pb)
{
    printf("Окно %s.\n",pb->opaque == true?"непрозарачно":"прозрачно");
    printf("Цвет фона %s.\n",colors[pb->fill_color]);
    printf("Рамка %s.\n",pb->show_border == true?"отображается":"не отображается");
    printf("Цвет рамки %s.\n",colors[pb->border_color]);
    printf("Стиль рамки ");
    switch (pb->border_style) {
        case SOLID: printf("сплошной.\n"); break;
        case DOTTED: printf("пунктирный.\n");break;
        case DASHED:printf("штриховой.\n");break;
        default:
            printf("независимого типа.\n");
            break;
    }
}
*//*
//ex_15_3 fields.c определение и использование полей
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//стили линии
#define SOLID 0
#define DOTTED 1
#define DASHED 2
//основные цвета
#define BLUE 4
#define GREEN 2
#define RED 1
//смешанные цвета
#define BLACK 0
#define YELLOW (RED|GREEN)
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define WHITE (RED|GREEN|BLUE)
//побитовые константы
#define OPAQUE 0x1
#define  FILL_BLUE 0x8
#define FILL_GREEN 0x4
#define FILL_RED 0x2
#define FILL_MASK 0xE
#define BORDER 0x100
#define BORDER_BLUE 0x800
#define BORDER_GREEN 0x400
#define BORDER_RED 0x200
#define BORDER_MASK 0xE00
#define B_SOLID  0
#define B_DOTTED 0x1000
#define B_DASHED 0x2000
#define STYLE_MASK 0x3000


const char *colors[8] = {"black","red","green","yellow","blue","magenta","cyan","white"};

struct box_props{
    bool opaque              :1;//или unsigned int
    unsigned int fill_color  :3;
    unsigned int             :4;
    bool show_border         :1;
    unsigned int border_color:3;
    unsigned int border_style:2;
    unsigned int             :2;
};

union Views //взгляд на данные как на struct  или как на struct или как на unsigned short
{
    struct box_props st_view;
    unsigned short us_view;
};

void show_settings(const struct box_props *pb);
void show_settingsL(unsigned short);
char *itobs(int n,char *ps);

int main(void)
{
    //создание объекта Views^ инициализация предствления в виде стркутуры
    union Views box = {{true,YELLOW,true,GREEN,DASHED}};
    char bin_str[8*sizeof(unsigned int) + 1];
    
    printf("Исходне настройки окна:\n");
    show_settings(&box.st_view);
    printf("\nНастройки окна с использование представления unsigned short:\n");
    show_settingsL(box.us_view);
    printf("Комбинация битов %s\n",itobs(box.us_view, bin_str));
    box.us_view &=~FILL_MASK; //очистить биты фора
    box.us_view |= (FILL_BLUE | FILL_GREEN); //переустановить фон
    box.us_view ^= OPAQUE; // переключить прозрачность
    box.us_view |= BORDER_RED;//ошибочный подход
    box.us_view &= STYLE_MASK; //очистить биты стиля
    box.us_view |= B_DOTTED; //установить пунктирный стиль
    printf("\nИзмененные настройки окна:\n");
    show_settings (&box.st_view);
    printf("\nНастройки окна с использование представления unsigned short:\n");
    show_settingsL(box.us_view);
    printf("Комбинация битов %s\n", itobs(box.us_view,bin_str));
    
    return 0;
    
}

void show_settings(const struct box_props *pb)
{
    printf("Окно %s.\n",pb->opaque == true?"непрозарачно":"прозрачно");
    printf("Цвет фона %s.\n",colors[pb->fill_color]);
    printf("Рамка %s.\n",pb->show_border == true?"отображается":"не отображается");
    printf("Цвет рамки %s.\n",colors[pb->border_color]);
    printf("Стиль рамки ");
    switch (pb->border_style) {
        case SOLID: printf("сплошной.\n"); break;
        case DOTTED: printf("пунктирный.\n");break;
        case DASHED:printf("штриховой.\n");break;
        default:
            printf("независимого типа.\n");
            break;
    }
}

void show_settingsL(unsigned short us)
{
    printf("Окно %s.\n",(us & OPAQUE) == OPAQUE?"непрозрачно":"прозрачно");
    printf("Цвет фона %s.\n",colors[(us >> 1) & 07]);
    printf("Рамка %s.\n",(us & BORDER) == BORDER?"отображается":"не отображается");
    printf("Стиль рамки ");
    switch (us & STYLE_MASK)
    {
        case B_SOLID: printf("сплошной.\n"); break;
        case B_DOTTED: printf("пунктирный.\n");break;
        case B_DASHED: printf("штриховой.\n");break;
        default:       printf("неизвестного типа.\n");break;
    }
    printf("Цвет рамки %s.\n", colors[(us>>9) & 07]);
}

char *itobs(int n,char *ps)
{
    int i;
    const static int size = CHAR_BIT*sizeof(int);
    
    for (i = size-1;i >= 0;i-- , n >>= 1)
        ps[i] = (01 & n ) +'0';
    ps[size] = '\0';
    
    return ps;
}
*/
//list_15_5 align.c использование _Alignof и _Alignas
#include <stdio.h>
int main(void)
{
    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    char _Alignas(double) cz;
    
    printf("Выравнивание char: %zd\n",_Alignof(char));
    printf("Выравнивание double: %zd\n",_Alignof(double));
    printf("&dx: %p\n",&dx);
    printf("&ca: %p\n",&ca);
    printf("&cx: %p\n",&cx);
    printf("&dz: %p\n",&dz);
    printf("&cb: %p\n",&cb);
    printf("&cz: %p\n",&cz);
    
    return 0;
}
/*
//ex_1 программа для однобайтных чисел
#include <stdio.h>
#include <string.h>
#include <math.h>

int binary_num(char*);
int main(void)
{
    char binary_code[] = "01010101";
    printf("%d \n",binary_num(binary_code));
    
    return 0;
}
int binary_num(char *str) //не забываем что первый бит в 1 означает что число отрицателное и
   в данной системе нужно использовать дополнение до 2 те если работает с 8 битами то нужно вычесть из 256 число представляющее собой 7 последних битов
{
    int n = (int)strlen(str);
    int sum = 0;
    for (int i= 1,k = n-2; i < n;++i, --k)
        if (str[i] == '1')
            sum += pow(2, k);
    if (str[0]=='1')
        sum = -(256-sum);
    
    return sum;
        
}
   *//*
//ex_2
#include <stdio.h>
#include <string.h>
#include <math.h>

int binary_num(char*);
void show_binary(int , int);

int main(int argc,char* argv[])
{

    printf("%s\n",argv[1]);// смотрим первый аргумент
    int x = binary_num(argv[1]); //переводим первый аргумент в число
    printf("%d\n",x);//смотрим значение первого аргумента
    int x_no = ~x;
    printf("%d\n",x_no);//применяем операцию НЕ к первому аргумент
    show_binary(x_no,0);//смотрим его двоичный вид после НЕ
    puts("\n");
    
    printf("%s\n",argv[2]);// смотрим второй аргумент
    int y = binary_num(argv[2]); //переводим первый аргумент в число
    printf("%d\n",y);//смотрим значение второго аргумента
    int y_no = ~y;
    printf("%d\n",y_no);//применяем операцию НЕ к второму аргументу
    show_binary(y_no,0);//смотрим его двоичный вид после НЕ
    puts("\n");
    
    printf("%d\n",x&y);//проводим операцию x&y
    show_binary(x&y, 0);//двоичное отображение операции x&y
    puts("\n");
    
    printf("%d\n",x|y);//проводим операцию x&y
    show_binary(x|y, 0);//двоичное отображение операции x&y
    puts("\n");
    
    printf("%d\n",x^y);//проводим операцию x&y
    show_binary(x^y, 0);//двоичное отображение операции x&y
    puts("");
    
}


int binary_num(char *str)
{
    int n = (int)strlen(str);
    int sum = 0;
    for (int i= 1,k = n-2; i < n;++i, --k)
        if (str[i] == '1')
            sum += pow(2, k);
    if (str[0]=='1')
        sum = -(256-sum);
    
    return sum;
        
}
//отображение двоичном виде используем аргумент ступеней который отсчитывает количество битов которые нужно отобразить
void show_binary(int x, int p)
{
    int r;
    r = x%2;
    if (x < 0) //используем дополнение до 2 в случае отрицательных чисел
        x +=256;
    if ( p < 7)
           show_binary(x/2,p+1);
       printf("%c",r == 0?'0':'1');
    return;
}
*/
/*
//ex_3 считаем количество единиц в двоичной фоарме числа
#include <stdio.h>
int num_one(int);

int main(void)
{
    
    printf("%d\n", num_one(7));
    return 0;
}

int num_one(int x)
{
    int cnt = 0;
    while (x > 0)
    {
        if (x%2 == 1)
            ++cnt;
        x /= 2;
    }
    
    return cnt;
}
*//*
//ex_4 находим бит в n-й позиции
#include <stdio.h>
int num_of_position(int,int);
int main(void)
{
    printf("%d\n",num_of_position(4,2));
    return 0;
}
int num_of_position(int x,int n)
{
    x >>= n-1;
    if (x%2 ==1)
        return 1;
    return 0;
    
}
*//*
//ex_5 цикличиский сдвиг влево
#include <stdio.h>
void shift_l(unsigned,int);

int main(void)
{
    shift_l(7, 4);
    return 0;
}

// для однобайтных чисел до 255
void shift_l(unsigned x,int k)
{
    const unsigned size_num = 8;
    
    unsigned arr[size_num]={0};
    unsigned cnt_bit = size_num-1;
    
    while (x > 0) //переводим поступившие число в двоичный вид и заполняяем соответствующие ячейки массива
    {
        arr[cnt_bit--] = x%2;
        x /= 2;
    }
    
    //отображаем двузначные значения до сдвига
    for (int i = 0; i< size_num; ++i)
        printf("%d",arr[i]);
    puts("");
    
    for (int i = 0;i < k; ++i)
    {
        int temp = arr[size_num-1];
        for (int j = size_num-1; j > 0; --j)
            arr[j] = arr[j-1];
        arr[0] = temp;
    }
    
    //отображаем двузначные значения после сдвига
    for (int i = 0; i< size_num; ++i)
        printf("%d",arr[i]);
    puts("");
}
*//*
//ex_6
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct bit_boxes {
    
    unsigned ID_print   :8;
    unsigned size_print :7;
    unsigned            :1;
    unsigned aligne     :2;
    bool bold           :1;
    bool italic         :1;
    bool underline      :1;
    unsigned            :3;
};

void show_bit_boxes(struct bit_boxes *);
int show_menu(void);
void change_print(struct bit_boxes *);
void change_size_print(struct bit_boxes *);
void change_aligne(struct bit_boxes *);
void change_bold(struct bit_boxes *);
void change_italic(struct bit_boxes *);
void change_underline(struct bit_boxes *);

int main(void)
{
    struct bit_boxes box ={1,10,false,false,false,false};
    void (*pf[6])(struct bit_boxes *) = {change_print,change_size_print,change_aligne,change_bold,change_italic,change_underline};
    
    int choice_menu;
    show_bit_boxes(&box);

    while ((choice_menu =show_menu()) != 7)
    {
        pf[choice_menu](&box);
        show_bit_boxes(&box);
    }
    return 0;
}

void change_print(struct bit_boxes *pb)
{
    unsigned _id_pr;
    puts("Введите тип шрифта 0-255");
    while (scanf("%d",&_id_pr) != 1 || _id_pr < 0 || _id_pr > 255)
    {
        puts("Тип шрифта не соответствует требуемому ( 0-255) попробуйте еще раз");
        while (getchar() !='\n')
            ;
    }
    while (getchar() !='\n')
        ;
    pb->ID_print = _id_pr;
}

void change_size_print(struct bit_boxes *pb)
{
    unsigned _size_p;
    puts("Введите размер шрифта 0-127");
    while (scanf("%d",&_size_p) != 1 || _size_p < 0 || _size_p > 127)
    {
        puts("Размер шрифта не соответствует требуемому ( 0-127) попробуйте еще раз");
        while (getchar() !='\n')
            ;
    }
    
    while (getchar() !='\n')
        ;
    
    pb->size_print = _size_p;
}
void change_aligne(struct bit_boxes *pb)
{
    puts("Выберите выравнивание:");
    puts("l) влево  c) по центру  r) вправо");
    char choice_aligne;
    while (scanf("%c",&choice_aligne) != 1 || strchr("lcr",choice_aligne) == NULL)
    {
        puts("Попробуйте еще раз выбрать буквы из меню выравнивания");
    }
    while (getchar() !='\n')
        ;
    switch (choice_aligne) {
        case 'l':
            pb->aligne=0;
            break;
        case 'c':
            pb->aligne=1;
            break;
        case 'r':
            pb->aligne=2;
            break;
        default:
            break;
    }
    
}
void change_bold(struct bit_boxes *pb)
{
    if (pb->bold)
    {
        pb->bold = false;
        puts("Полужирный шрифт отключен");
    }
    else
    {
        pb->bold = true;
        puts("Полужирный шрифт включен");
    }
}
void change_italic(struct bit_boxes *pb)
{
    if(pb->italic)
    {
        pb->italic = false;
        puts("Курсив отключен");
    }
    else
    {
        pb->italic = true;
        puts("Курсив включен");
    }
}
void change_underline(struct bit_boxes *pb)
{
    if(pb->underline)
    {
        pb->underline = false;
        puts("Подчеркивание отключено");
    }
    else
    {
        pb->underline = true;
        puts("Полужирный шрифт включен");
    }
}

void show_bit_boxes(struct bit_boxes *pb)
{
    char set_aligne[10];
    switch (pb->aligne) {
        case 0:
            strcpy(set_aligne,"left");
            break;
        case 1:
            strcpy(set_aligne,"centre");
            break;
        case 2:
            strcpy(set_aligne,"right");
            break;
        default:
            break;
    }
    
    puts("ID SIZE  ALIGNE   BOLD  ITALIC  UNDERLINE");
    printf("%d %4d %7s %6s %6s %8s\n",pb->ID_print,pb->size_print,set_aligne,pb->bold==true?"on":"off",pb->italic==true?"on":"off",pb->underline==true?"on":"off");
}

int show_menu(void)
{
    puts("Выберите нужный пункт меню для обработки текста:");
    puts("a) изменить шрифт    b) изменить размер    c) изменить выравнивание");
    puts("d) полужирный        e) курсив             f) подчеркнутый         ");
    puts("g) завершить");
    
    char choice_menu;
    
    while(scanf("%c",&choice_menu) != 1 || strchr("abcdefg", choice_menu) == NULL)
    {
        puts("Что то не так попробуйте выбрать меню ещё раз.");
    }
    while (getchar() !='\n')
        ;
    switch (choice_menu) {
        case 'a':
            return 0;
            break;
        case 'b':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        case 'd':
            return 3;
            break;
        case 'e':
            return 4;
            break;
        case 'f':
            return 5;
            break;
        default:
            return 7;
            break;
    }
}
*//*
//ex7 предыдущая программа с побитывими операциями
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

//побитывые константы для определения битов
#define UNDERLINE 0x1
#define ITALIC 0x2
#define BOLD 0x4
#define ALIGNE_LEFT 0x0
#define ALIGNE_CENTRE 0x10
#define AlIGNE_RIGHT 0x18
#define ALIGNE_MASK 0x18
#define SIZE_PRINT_MASK 0xFE00
#define ID_PRINT_MASK 0xFF0000



void show_bit_line(unsigned int);
int show_menu(void);
char * itobs(int n,char *ps);
unsigned int  change_print(unsigned  line);
unsigned int  change_size_print(unsigned  line);
unsigned int  change_aligne(unsigned linet);
unsigned int  change_bold(unsigned  line);
unsigned int  change_italic(unsigned line);
unsigned int  change_underline(unsigned  line);

int main(void)
{
   
     unsigned int (*pf[6])(unsigned line) = {change_print,change_size_print,change_aligne,change_bold,change_italic,change_underline};
    
    unsigned int bit_line=0;
    
    int choice_menu;
    show_bit_line(bit_line);
    

    while ((choice_menu =show_menu()) != 7)
    {
        bit_line = pf[choice_menu](bit_line);
        show_bit_line(bit_line);
    }
    return 0;
}

unsigned int change_print(unsigned  line)
{
    unsigned int _id_pr;
    puts("Введите тип шрифта 0-255");
    while (scanf("%d",&_id_pr) != 1 || _id_pr < 0 || _id_pr > 255)
    {
        puts("Тип шрифта не соответствует требуемому ( 0-255) попробуйте еще раз");
        while (getchar() !='\n')
            ;
    }
    
    while (getchar() !='\n')
        ;
    
    _id_pr <<= 16;
    line &=(~ID_PRINT_MASK);
    
    return _id_pr|line;
    
}

unsigned int  change_size_print(unsigned  line)
{
    unsigned int _size_p;
    puts("Введите размер шрифта 0-127");
    while (scanf("%d",&_size_p) != 1 || _size_p < 0 || _size_p > 127)
    {
        puts("Размер шрифта не соответствует требуемому ( 0-127) попробуйте еще раз");
        while (getchar() !='\n')
            ;
    }

    while (getchar() !='\n')
        ;
    
    
    _size_p <<= 8;
    line &=(~SIZE_PRINT_MASK);
    
    return _size_p|line;

}
unsigned int  change_aligne(unsigned line)
{
    puts("Выберите выравнивание:");
    puts("l) влево  c) по центру  r) вправо");
    char choice_aligne;
   
    while (scanf("%c",&choice_aligne) != 1 || strchr("lcr",choice_aligne) == NULL)
    {
        puts("Попробуйте еще раз выбрать буквы из меню выравнивания");
    }
    while (getchar() !='\n')
        ;
    
    line &= (~ALIGNE_MASK);
    switch (choice_aligne) {
        case 'l':
            line |= ALIGNE_LEFT;
            break;
        case 'c':
            line |= ALIGNE_CENTRE;
            break;
        case 'r':
            line |= AlIGNE_RIGHT;
            break;
        default:
            break;
    }
    
    return line;
}
unsigned int  change_bold(unsigned  line)
{
    line ^=BOLD;
    puts("Полужирный шрифт изменен");
    
    return line;
}

unsigned int  change_italic(unsigned  line)
{
    line ^=ITALIC;
    puts("Курсив изменен");
    
    return line;
 
}
unsigned int  change_underline(unsigned line)
{
    line ^=UNDERLINE;
    puts("Полужирный шрифт изменён");
    
    return line;
}

void show_bit_line(unsigned  line)
{
    char set_aligne[10];
    switch (line &ALIGNE_MASK) {
        case ALIGNE_LEFT:
            strcpy(set_aligne,"left");
            break;
        case ALIGNE_CENTRE:
            strcpy(set_aligne,"centre");
            break;
        case AlIGNE_RIGHT:
            strcpy(set_aligne,"right");
            break;
        default:
            break;
    }
    
    puts("ID SIZE  ALIGNE   BOLD  ITALIC  UNDERLINE");
    printf("%d %4d %7s %6s %6s %8s\n",
         line>>16,(line&(~ID_PRINT_MASK))>>8,set_aligne,(line&BOLD)==BOLD?"on":"off",(line&ITALIC)==ITALIC?"on":"off",(line&UNDERLINE)==UNDERLINE?"on":"off");
    
    char bin_str[8*sizeof(unsigned int) +1];
    printf("Комбинация битов %s\n",itobs(line,bin_str));
    puts("");

}

char * itobs(int n,char *ps)
{
    int i;
    const static int size = CHAR_BIT*sizeof(int);
    
    for(i = size-1; i >= 0; i-- , n >>= 1)
        ps[i] = (01&n)+'0';
    ps[size] = '\0';
    
    return ps;
}

int show_menu(void)
{
    puts("Выберите нужный пункт меню для обработки текста:");
    puts("a) изменить шрифт    b) изменить размер    c) изменить выравнивание");
    puts("d) полужирный        e) курсив             f) подчеркнутый         ");
    puts("g) завершить");
    
    char choice_menu;
    
    while(scanf("%c",&choice_menu) != 1 || strchr("abcdefg", choice_menu) == NULL)
    {
        puts("Что то не так попробуйте выбрать меню ещё раз.");
    }
    while (getchar() !='\n')
        ;
    switch (choice_menu) {
        case 'a':
            return 0;
            break;
        case 'b':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        case 'd':
            return 3;
            break;
        case 'e':
            return 4;
            break;
        case 'f':
            return 5;
            break;
        default:
            return 7;
            break;
    }
}
*/
