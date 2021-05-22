//
//  main.c
//  chapter13
//
//  Created by пупсик on 02.04.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//
/*
#include <stdio.h>
#include <stdlib.h> //прототип exit()

int main(int argc, const char * argv[]) {
   
    int ch;//место для зранения каждого символа по мере чтения
    FILE *fp; //указатель файла
    unsigned long count = 0;
    if (argc != 2)
    {
        printf("Использование: %s имя_файла\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1],"r")) == NULL)
    {
        printf("Не удается открыть %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc (ch,stdout);// то же что и putchar(ch);
        count++;
    }
    fclose(fp);
    printf("\nФайл %s содержит %lu символов\n",argv[1],count);
    
    return 0;
}
 *//*
//list_13_2 reducto.c сокращение файла на две трети
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 8

int main(int argc,char *argv[])
{
    FILE *in,*out; //объявление двух указателей на FILE
    int ch;
    char name[LEN];//хранилище для имени выходного файла
    int count=0;
    
    //проверка аргументов командной строки
    if (argc <2)
    {
        fprintf(stderr,"Использование: %s имя_файла\n",argv[0]);
        exit (EXIT_FAILURE);
    }
    
    //настройка ввода
    if ((in = fopen(argv[1],"r")) == NULL)
    {
        fprintf(stderr,"Не удается открыть файл\"%s\"\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    
    //настройка вывода
    strncpy(name,argv[1],LEN-4);//копирование имени файла
    name[LEN-4] = '\0';
    strcat(name,"red");
    if ((out = fopen(name,"w")) == NULL)
    {
        fprintf(stderr,"Не удается создать выходной файл.\n");
    }
    //копирование данных
    while ((ch=getc(in)) != EOF)
        if (count++%3 == 0)
            putc(ch,out); //выводит каждый третей символ
    //очистка
    if (fclose(in) != 0 || fclose(out) !=0)
        fprintf(stderr,"Ошибка при закрытии файлов.\n");
    
    return 0;
}
*//*
//list_13_3 addaword.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];
    
    if ((fp = fopen("wordy","a+")) == NULL)
    {
        fprintf(stdout,"Ну удается открыть файл \"wordy\".\n");
        exit(EXIT_FAILURE);
    }
        puts("Введите слова для добваления в файл; для завершения");
        puts("введите сивол # в начале строки.");
        while ((fscanf(stdin,"%40s",words)==1) && words[0] != '#')
            fprintf(fp,"%s\n",words);
        
        puts("Содержимое файла:");
        rewind(fp);//возврат в начало файла
        while(fscanf(fp,"%s",words)==1)
            puts(words);
        puts("Готово!");
        if (fclose(fp) != 0)
            fprintf(stderr,"Ошибка при закрытии файла\n");
        
    return 0;
}
   *//*
//list_13_4 reverse.c
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032' //макркер конца файлов в текстовых файлах DOS
#define SLEN 81

int main(void)
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count,last;
    
    puts ("Введите имя файла для обработки:");  //например wordy
    scanf("%80s",file);
    if ((fp = fopen(file,"rb")) == NULL)
    {
        printf("reverse не удается открыть %s\n",file);
        exit(EXIT_FAILURE);
    }
    fseek(fp,0L,SEEK_END); //перейти в конец файла
    last = ftell(fp);
    for (count = 1L;count <= last;count++)
    {
        fseek(fp,-count,SEEK_END); //двигаться в обратном направлении
        ch = getc(fp);
        if (ch != CNTL_Z && ch != '\r') //файлы MS-DOS
            putchar(ch);
    }
    putchar('\n');
    fclose(fp);
    return 0;
    
}
*//*
//list 13_5 append.c добавление фодержимого файлов в файл назначения
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
char *s_gets(char *st,int n);
int main(void)
{
    FILE *fa,*fs; //fa для файла назначения, fs для исходного файла
    int files = 0; //количество добавляеых файлов
    char file_app[SLEN]; //имя файла назначения
    char file_src[SLEN]; //имя исходного файла
    int ch;
    puts("Введите имя файла назначения:");
    s_gets(file_app,SLEN);
    if ((fa = fopen(file_app,"a+"))==NULL)
    {
        fprintf(stderr,"Не удается открыть %s\n",file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
    {
        fputs("Не удается создать выходной буфер\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    puts("Введите имя первого исходного файла ( или пустую строку для завершения):");
    while(s_gets(file_src,SLEN) && file_src[0] !='\0')
    {
        if (strcmp(file_src,file_app) == 0)
            fputs("Добавить файл в  конец самого себя невозможно\n",stderr);
        else if ((fs=fopen(file_src,"r")) == NULL)
            fprintf(stderr,"Ну удается открыть %s\n",file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Ну удается создать входной буфер\n",stderr);
            }
            append(fs,fa);
            if (ferror(fs) != 0)
                fprintf(stderr,"Ошибка при чтении файла %s.\n",file_src);
            if (ferror(fa) != 0)
                fprintf(stderr,"Ошибка при записи файла %s.\n", file_app);
            fclose(fs);
            files++;
            printf("Содержимое файла %s добавлено.\n", file_src);
            puts("Введите имя следующего файла (или пустую строку для завершения):");
        }
    }
    printf("Добавление завершено. Количество добавленых файлов: %d.\n",files);
    rewind(fa);
    printf("Содержание %s:\n",file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Отображение завершено.");
    fclose(fa);
    return 0;
}

void append( FILE *source,FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; //выделить память один раз
    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp,sizeof(char),bytes,dest);
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        find = strchr(st,'\n'); //поиск символа новой строки
        if (find)               //если адрес не является NULL
            *find = '\0';       //поместить туда нулевой символ
        else
            while (getchar() != '\n')
                ;
    }
    return ret_val;
}
*//*
//list_13_6 произвольный доступ двоичный ввод вывод
#include<stdio.h>
#include<stdlib.h>
#define ARSIZE 1000
int main(void)
{
    double numbers[ARSIZE];
    double value;
    const char *file = "numbers.dst";
    int i;
    long pos;
    FILE *iofile;
    
    //создание набора значений double
    for (i = 0;i < ARSIZE; i++)
        numbers[i]= 100.0 *i +1.0/(i+1);
    //попытка открыть файл
    if ((iofile = fopen(file,"wb")) == NULL)
    {
        fprintf(stderr,"Ну удается открыть файл %s для вывода.\n",file);
        exit(EXIT_FAILURE);
    }
    //записть в файл массива в двоичном формате
    fwrite(numbers,sizeof(double),ARSIZE,iofile);
    fclose(iofile);
    if((iofile = fopen(file,"rb")) == NULL)
    {
        fprintf(stderr,"Ну удается открыт файл %s для произвольного доступа.\n",file);
        exit(EXIT_FAILURE);
    }
    
    //чтение избранных элементов из файла
    printf("Введите индекс в диапазоне 0- %d.\n",ARSIZE-1);
    while (scanf("%d",&i) && i>=0 && i<ARSIZE)
    {
        pos = (long) i*sizeof(double);// вычисление смещения
        fseek(iofile,pos,SEEK_SET);//переход на нужную позиция
        fread(&value,sizeof(double),i,iofile);
        printf("По этому индексу находится значение %f.\n",value);
        printf("Введите следующий индекс (или значение за пределами диапазона для завершеня):\n");
    }
    //завершение
    fclose(iofile);
    puts("Программа завершена.");
    return 0;
}
*//*
//hw_4
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
        
        double in_num,sum = 0;//переменные для ввода чисел и их сумма
        int num = 0;//счетчик чисел
    if (argc >2)
    {
        printf("Использование: %s имя_файла\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (argc == 2){
        
        FILE *fp;
        
        if ((fp = fopen(argv[1],"r")) == NULL)
        {
            printf("Не удается открыть %s\n",argv[1]);
            exit(EXIT_FAILURE);
        }


        while(fscanf(fp,"%lf",&in_num) == 1 )
        {

            sum+=in_num; num++;
            
        }

    }
    else
    {
        printf("Вводим по очереди числа для окончания введите 0\n");
        while (scanf("%lf",&in_num)== 1 && in_num != 0)
        {
            sum+=in_num;num++;
            
        }
    }
    printf("%f , %d\n",sum,num);
    printf("Результат: %f\n",sum/num);
}
   *//*
//hw_5 //передавалась буква i в первом аргументе
#include<stdio.h>
#define LENSTR 250
int main(int argc,char* argv[])
{
    char str[LENSTR];
    int ch, num_let,num_ch;
    FILE *fp;
    if ((fp = fopen(argv[2],"r")) == NULL)
    {
        printf("Не удается открыть %s\n",argv[2]);
        
    }
    //while (fgets(str,LENSTR,fp) != NULL)
    //    fputs(str,stdout);
    num_let=num_ch=0;
    while ((ch = fgetc(fp)) !=EOF)
    {
        
        if (ch !='\n' && num_let < LENSTR)
        {
            str[num_let]=ch;
            num_let++;
            if (ch == argv[1][0])
                num_ch++;
        }
        else
        {
            str[num_let]='\0';
            if (num_ch > 0)
                puts(str);
            num_let=num_ch=0;
        }
    }
}
*//*
//ex_1 модификация list 13_1
#include <stdio.h>
#include <stdlib.h> //прототип exit()

int main(void) {
   
    int ch;//место для зранения каждого символа по мере чтения
    FILE *fp; //указатель файла
    char file_name[20];
    unsigned long count = 0;

    printf("Введите имя файла для чтения:");
    scanf("%s",file_name);
    if ((fp = fopen(file_name,"r")) == NULL)
    {
        printf("Не удается открыть %s\n",file_name);
        printf("Проверьте имя и наличие файла.\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc (ch,stdout);// то же что и putchar(ch);
        count++;
    }
    fclose(fp);
    printf("\nФайл %s содержит %lu символов\n",file_name,count);
    
    return 0;
}
*/
/*
//ex_2 копирование файлов
#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 4096
int main(int argc,char *argv[])
{
    FILE *source,*dest; //оригинальный файл, файл назначения
    if ((source = fopen(argv[1],"r")) == NULL)
    {
        printf("Не удается открыть файл %s",argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((dest = fopen(argv[2],"w")) == NULL)
    {
        printf("Не удается открыть файл %s",argv[2]);
        exit(EXIT_FAILURE);
    }
    char temp[BUFSIZE];
    size_t bytes;
    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
    {
        fwrite(temp,sizeof(char),bytes,dest);
        puts(temp);
    }
}
*//*
//ex_3
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define BUFSIZE 4096
char *Upper(char*);
int main(int argc,char *argv[])
{
    FILE *source,*dest; //оригинальный файл, файл назначения
    char source_name[20],dest_name[20];
    puts("Вводим название оригинального файла:");
    scanf("%s",source_name);
    puts("Вводим название файла назначения:");
    scanf("%s",dest_name);
    if ((source = fopen(source_name,"r")) == NULL)
    {
        printf("Не удается открыть файл %s",argv[1]);
        puts("Проверьте название и наличие файла.\n");
        exit(EXIT_FAILURE);
    }
    if ((dest = fopen(dest_name,"w")) == NULL)
    {
        printf("Не удается открыть файл %s",argv[2]);
        exit(EXIT_FAILURE);
    }
    char temp[BUFSIZE];
    size_t bytes;
    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
    {
        fwrite(Upper(temp),sizeof(char),bytes,dest);
        puts(Upper(temp));
    }
}
char* Upper(char * str)
{
    int i=0;
    while (str[i] !='\0')
    {
        str[i]=toupper(str[i]);
        i++;
    }
    return str;
}
*//*
//ex_4 программа выводит содержимое всех файлов в командной строке
#include<stdio.h>
#include<stdlib.h>
#define STRLEN 1024
int main(int argc,char * argv[])
{
    FILE *fp;

    for (int i = 1;i <argc;i++)
    {
        if ((fp = fopen(argv[i],"r")) == NULL)
        {
            printf("Не удается открыть файл %s",argv[0]);
            exit(EXIT_FAILURE);
        }
        char temp[STRLEN];
        size_t bytes;
        while ((bytes = fread(temp,sizeof(char),STRLEN,fp)) > 0)
                puts(temp);


    }
}
*//*
//ex_5 модификация list_13_6 с передачей данных через командную строку

#include<stdio.h>
#include<stdlib.h>
#define ARSIZE 1000
int main(int argc,char *argv[])
{
    double numbers[ARSIZE];
    double value;
    const char *file = argv[1];//"numbers.dst";
    int i;
    long pos;
    FILE *iofile;
    
    //создание набора значений double
    for (i = 0;i < ARSIZE; i++)
        numbers[i]= 100.0 *i +1.0/(i+1);
    //попытка открыть файл
    if ((iofile = fopen(file,"wb")) == NULL)
    {
        fprintf(stderr,"Ну удается открыть файл %s для вывода.\n",file);
        exit(EXIT_FAILURE);
    }
    //записть в файл массива в двоичном формате
    fwrite(numbers,sizeof(double),ARSIZE,iofile);
    fclose(iofile);
    if((iofile = fopen(file,"rb")) == NULL)
    {
        fprintf(stderr,"Ну удается открыт файл %s для произвольного доступа.\n",file);
        exit(EXIT_FAILURE);
    }
    
    //чтение избранных элементов из файла
    printf("Введите индекс в диапазоне 0- %d.\n",ARSIZE-1);
    while (scanf("%d",&i) && i>=0 && i<ARSIZE)
    {
        pos = (long) i*sizeof(double);// вычисление смещения
        fseek(iofile,pos,SEEK_SET);//переход на нужную позиция
        fread(&value,sizeof(double),i,iofile);
        printf("По этому индексу находится значение %f.\n",value);
        printf("Введите следующий индекс (или значение за пределами диапазона для завершеня):\n");
    }
    //завершение
    fclose(iofile);
    puts("Программа завершена.");
    return 0;
}
*//*
//ex_6 модификация листинга 13_2 с вводом данных через стандатрный ввод
//list_13_2 reducto.c сокращение файла на две трети
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 8

int main(int argc,char *argv[])
{
    FILE *in,*out; //объявление двух указателей на FILE
    int ch;
    char name_in[25]; //имя входного файла
    char name[LEN];//хранилище для имени выходного файла
    int count=0;
    puts("Введите название входного файла");
    scanf("%s",name_in);

    //проверка аргументов командной строки

    //настройка ввода
    if ((in = fopen(name_in,"r")) == NULL)
    {
        fprintf(stderr,"Не удается открыть файл\"%s\"\n",name_in);
        puts("Проверьте имя и наличие файла");
        exit(EXIT_FAILURE);
    }
    
    //настройка вывода
    strncpy(name,argv[1],LEN-4);//копирование имени файла
    name[LEN-4] = '\0';
    strcat(name,"red");
    if ((out = fopen(name,"w")) == NULL)
    {
        fprintf(stderr,"Не удается создать выходной файл.\n");
    }
    //копирование данных
    while ((ch=getc(in)) != EOF)
        if (count++%3 == 0)
            putc(ch,out); //выводит каждый третей символ
    //очистка
    if (fclose(in) != 0 || fclose(out) !=0)
        fprintf(stderr,"Ошибка при закрытии файлов.\n");
    
    return 0;
}
   *//*
//ex_ 7 последовательное считывание строк из двух файлов
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define BUF 256
char* Upper(char * str);
char *s_gets(char *st,FILE *fp);
int main(int argc,char * argv[])
{
    FILE *fp1,*fp2;
    if ((fp1 = fopen(argv[1],"r")) == NULL)
    {
        printf("Не можем открыть файл %s",argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2],"r")) ==NULL)
    {
        printf("Не можем открыть файл %s",argv[2]);
        exit(EXIT_FAILURE);
    }
    
    char temp1[BUF];
    char temp2[BUF];

    while (s_gets(temp1,fp1) && fgets(temp2,BUF,fp2))
    {
    
            fputs(Upper(temp1),stdout);
            puts(temp2);
    }
    if (strlen(temp1)> 0) //определяем длину считанной строки
    {
        while (s_gets(temp1,fp1))
            puts(Upper(temp1));
    }
    else if (strlen(temp2) > 0)
        while (fgets(temp2,BUF,fp1))
                puts(temp2);
  
}
char* Upper(char * str)
{
    int i=0;
    while (str[i] !='\0')
    {
        str[i]=toupper(str[i]);
        i++;
    }
    return str;
}

char *s_gets(char *st,FILE *fp)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st,BUF,fp);
    if (ret_val)
    {
        find = strchr(st,'\n');
        if (find)
        {
            *find = ' ';
            *++find='\0';
        }
    }
    return ret_val;
}*/
/*
//ex_8  считаем символы в файлах
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 250
char *s_gets(char *str,int n);
int main(int argc, char *argv[])
{
    int cnt = 0; //счетчик букв
    char find_ch = argv[1][0];
    char str[STRLEN];
    
    if (argc < 2)
    {
        printf("В команде недостаточно аргументов, проверьте наличие буквы для поиска");
        exit(EXIT_FAILURE);
    }
    if (argc == 2)
    {
        printf("У Вас нет файлов для поиска.\nНачинайте воодить строки для поиска установленной в команде буквы. \nДля окончания ввода нажмите Enter в начале строки");

        while (s_gets(str,STRLEN)  && str[0] !='\0')
        {
            int i =0;
            while (str[i] !='\0')
            {
                if (str[i] == find_ch)
                    cnt++;
                i++;
            }
        }
        printf("Со страндартного входа были введены строки, содержащие %d симвлолв %c\n",cnt,find_ch);
        
    }
    if (argc >2)
    {
        FILE *fp;
        for (int i = 2;i<argc;i++)
        {
            if ((fp = fopen(argv[i],"r")) == NULL)
                printf("К сожалению Ваш файл не найден");
            else
            {
                while(fgets(str,STRLEN,fp))
                {
                    puts(str);
                    int j= 0;
                    while(str[j] != '\0')
                    {
                        if( str[j]==find_ch)
                            cnt++;
                        j++;
                    }
                }
            }
            fclose(fp);
        }
        printf("Было открыто  %d файлa(ов). В них находится %d букв(a) %c\n",argc-2,cnt,find_ch);
    }
}
char *s_gets(char *str,int n)
{
    char * ret_val;
    char *find;
    ret_val = fgets(str, STRLEN, stdin);

    if (ret_val)
    {
        find = strchr(str,'\n');
        if (find)
        {
            *find ='\0';
        }
        else
            while (getchar() != '\n')
                ;
    }
    return ret_val;
}
 *//*
//ex_9 модификация листинга 13_3 с нумерацией слов
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];
    int num_words=0; // переменная для хранения количества слов в файле
    
    if ((fp = fopen("wordy","a+")) == NULL)
    {
        fprintf(stdout,"Ну удается открыть файл \"wordy\".\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp);//устанавливаем курсор в начало файла
    
    while (fgets(words,MAX,fp)) //считаем количество строк в файле
        num_words++;
    printf("В вашем файле содержится %d слов\n",num_words);
    
    puts("Введите слова для добваления в файл; для завершения");
    puts("введите сивол # в начале строки.");
    while ((fscanf(stdin,"%40s",words)==1) && words[0] != '#') // добавляем слова с указанием номера слова
        fprintf(fp,"%d. %s\n",++num_words,words);
    
    puts("Содержимое файла:");
    rewind(fp);//возврат в начало файла
    
    while (fgets(words,MAX,fp))
        fputs(words,stdout);
    puts("Готово!");
    if (fclose(fp) != 0)
        fprintf(stderr,"Ошибка при закрытии файла\n");
        
    return 0;
}
*//*
//ex_10
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    char name[25];//массив для ввода названия файла
    puts("Введите название файла для обработки");
    scanf("%s",name);
    if ((fp = fopen(name,"r")) == NULL)
    {
        printf("Мы не можем найти указанный Вами файл, попробуйте ещё раз.");
        exit(EXIT_FAILURE);
    }
    int sizeFile=0;//переменная для определения количества элементов в файле
    rewind(fp); //устанавливаем курсор в начальную позицию
    int ch; //переменная для посимвольного считвыания данных из файла
    while ((ch = fgetc(fp)) != EOF) //считаем количество сиволов в файле
        sizeFile++;
    
    int ind;//переменная индекса для считывания данных
    long pos;//переменная для вычисления смещения
    printf("В вашем файле %d сиволов. Введите индекс в диапазоне от 0 до %d, для выхода введите -1\n",sizeFile, sizeFile);
    while (scanf("%d",&ind)  && ind >=0 && ind <sizeFile)
    {
        pos = (long) ind * sizeof(char); //вычисление смещения
        fseek(fp,pos,SEEK_SET);//переход в нужную позицию
        puts("Данные до конца строки");
        while ((ch = getc(fp)) != '\n')
            putc(ch,stdout);
        printf("\nВведите следующий индекс в диапазоне 0 - %d или -1 для выхода", sizeFile);
    }
    
    
    return 0;
}
*//*
//ex_11 поиск подстроки в файле
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 256
int main(int argc,char *argv[])
{
    FILE *fp;
    if (argc !=3)
    {
        printf("Не хватает аргументов должно быть два");
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2],"r")) == NULL)
    {
        printf("Не можем найти файл %s\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    char str[STRLEN];
    //puts(argv[1]);
    while (fgets(str, STRLEN, fp))
    {
        //printf("%s",str);
        if (strstr(str,argv[1]))
            printf("%s",str);
    }
    return 0;
}
*//*
//ex_12
#include <stdio.h>
#include <stdlib.h>
#define STR 20
#define COL 30
char tramsformation(int);
int main(void)
{
   */ /*
    int source[STR][COL];
    for (int i= 0;i<STR;++i)
        for (int j =0;j<COL;++j)
            source[i][j]=rand() % 10;
    
    if ((fp = fopen("ex12","w")) == NULL)
    {
        printf("Не удалось создать файл, попробуйте ещё раз");
        exit(EXIT_FAILURE);
    }
    for (int i= 0;i<STR;++i)
    {
        for (int j =0;j<COL;++j)
            fprintf(fp,"%d ",source[i][j]);
        fprintf(fp,"%c",'\n');
    }*//*
    FILE *fp;
    if ((fp = fopen("ex12","r")) == NULL)
    {
        printf("Проблемы с открытием файла");
        exit(EXIT_FAILURE);
    }
    
   // int source[STR][COL];

    char trans[STR][COL];
    int temp;
    for (int i= 0;i<STR;++i)
        for (int j =0;j<COL;++j)
        {
            fscanf(fp,"%d",&temp);
            trans[i][j]= tramsformation(temp);
        }
    
    for (int i= 0;i<STR;++i)
    {
        for (int j =0;j<COL;++j)
            fprintf(stdout,"%c ",trans[i][j]);
        printf("%c",'\n');
    }
    //выводим в файл для хранения
    if ((fp = fopen("ex12_out","w")) == NULL)
    {
        printf("Не удалось создать файл, попробуйте ещё раз");
        exit(EXIT_FAILURE);
    }
    for (int i= 0;i<STR;++i)
    {
        for (int j =0;j<COL;++j)
            fprintf(fp,"%c ",trans[i][j]);
        fprintf(fp,"%c",'\n');
    }

    return 0;
}
*/
/*
//ex13 упражнение 12 с использованием массива переменной длины для отображения процесса заменяемые числа установлены в 10 и 30
#include <stdio.h>
#include <stdlib.h>
#define STR 20
#define COL 30
char tramsformation(int);
int main(void)
{
    int str,col;// переменные строк и столбцов для создания массива
    
    //открываем файл
    FILE *fp;
    if ((fp = fopen("ex12_size","r")) == NULL)
    {
        printf("Проблемы с открытием файла");
        exit(EXIT_FAILURE);
    }
    //считываем данные по строкам и столбцам
    fscanf(fp,"%d %d",&str,&col);
    int trans[str][col];
    printf("%d %d \n", str,col);

    int temp; //переменная для считывания данных
    for (int i= 0;i<STR;++i)
       for (int j =0;j<COL;++j)
       {
           fscanf(fp,"%d",&temp);
           trans[i][j]= tramsformation(temp);
       }
    
    //отображаем полученные данные
    for (int i= 0;i<STR;++i)
   {
       for (int j =0;j<COL;++j)
           fprintf(stdout,"%c ",trans[i][j]);
       printf("%c",'\n');
   }
    return 0;
}

char tramsformation(int x)
{
    char out= ' ';
    switch (x) {
        case 0:
            out = ')';
            break;
        case 1:
            out = '!';
            break;
        case 2:
            out = '@';
            break;
        case 3:
            out = '#';
            break;
        case 4:
            out = '$';
            break;
        case 5:
            out = '%';
            break;
        case 6:
            out = '^';
            break;
        case 7:
            out = '&';
            break;
        case 8:
            out = '*';
            break;
        case 9:
            out = '(';
            break;
        default:
            break;
    }
    return out;
}
*/
//ex_14 обработка данных

#include <stdio.h>
#include <stdlib.h>
#define STR 20
#define COL 30
int modif (int s,int c,const int[s][c],int,int);

int main(void)
{
   int str,col;// переменные строк и столбцов для создания массива
    // открываем файл
   FILE *fp;
   if ((fp = fopen("ex12_size","r")) == NULL)
   {
       printf("Проблемы с открытием файла");
       exit(EXIT_FAILURE);
   }
    
   //считываем данные по строкам и столбцам
   fscanf(fp,"%d %d",&str,&col);
   int source[str][col];
   printf("%d %d \n", str,col);
    
   //считываем данные
   for (int i= 0;i<STR;++i)
      for (int j =0;j<COL;++j)
          fscanf(fp,"%d",&source[i][j]);
          
       
    // модифицируем и отображаем полученные данные
       for (int i= 0;i<STR;++i)
      {
          for (int j =0;j<COL;++j)
              fprintf(stdout,"%d ",modif(str,col,source,i,j));
          printf("%c",'\n');
      }
    
    return 0;
}

int modif (int str,int col, const int ar[str][col],int i, int j)
{
    //i = 0,j=0 крайней левый угол
    if ( i==0 && j == 0 && abs(ar[i][j]-ar[i][j+1])>1 && abs(ar[i][j]-ar[i+1][j])>1)
        return 10;
    
    //верхняя строка
    if (i == 0 && j> 0 && j<col && abs(ar[i][j]-ar[i][j-1])>1 && abs(ar[i][j]-ar[i][j+1])>1 && abs(ar[i][j]-ar[i+1][j])>1)
        return 10;
    
    //верхний правый угол
    if (i == 0 && j==col && abs(ar[i][j]-ar[i][j-1])>1 && abs(ar[i][j]-ar[i+1][j])>1)
        return 10;
    
    //нижний левый угол
    if ( i == str && j == 0 && abs(ar[i][j]-ar[i-1][j])>1 && abs(ar[i][j]-ar[i][j+1])>1)
        return 10;
    
    // нижняя строка
    if (i == str && j> 0 && j<col && abs(ar[i][j]-ar[i][j-1])>1 && abs(ar[i][j]-ar[i][j+1])>1 && abs(ar[i][j]-ar[i-1][j])>1)
        return 10;
    
    // правый нижний угол
    if (i == str && j==col && abs(ar[i][j]-ar[i][j-1])>1 && abs(ar[i][j]-ar[i-1][j])>1)
        return 10;
    
    //левый столбец
    if (i>0 && i<str && j == 0 && abs(ar[i][j]-ar[i-1][j])>1 && abs(ar[i][j]-ar[i+1][j])>1 && abs(ar[i][j]-ar[i][j+1])>1)
        return 10;
        
    //правый столбец
    if (i>0 && i<str && j == col && abs(ar[i][j]-ar[i-1][j])>1 && abs(ar[i][j]-ar[i+1][j])>1 && abs(ar[i][j]-ar[i][j-1])>1)
        return 10;
    
    //все что в середине
    if (i>0 && i<str && j < col && j> 0 && abs(ar[i][j]-ar[i-1][j])>1 && abs(ar[i][j]-ar[i+1][j])>1 && abs(ar[i][j]-ar[i][j-1])>1 && abs(ar[i][j]-ar[i][j+1])>1 )
        return 20;
    
    return ar[i][j];
}
