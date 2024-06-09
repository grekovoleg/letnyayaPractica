#include "stdafx.h" //подключение библиотек
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include <clocale>
using namespace std;
using namespace System;
using namespace System::IO;
#define ENTER 13 //обозначение кнопок 
#define ESC 27
#define UP 72
#define DOWN 80
#define HOME 71
#define END 79
#define _SCL_SECURE_NO_DEPRECATE



struct z {
char name[20];//ФИО посетителей
char vid[20];//Название тарифа спортсменов
long summa;//Потраченная сумма в зале
char data[11];//Дата первого посещения
long ves;//Вес клиентов
}; //шаблон структуры для исходных данных 
struct sp {
char fio[20];
char vid[20];
long summa;
struct sp* sled;
} *spisok;//шаблон, глобальное описание структуры двустроннего списка 

struct sp2 {
char fio[20];
char vid[20];
long summa;
struct sp2* sled;
struct sp2* pred;
} *spisok2;//шаблон, глобальное описание структуры двустроннего списка 

int menu(int);//указание шаблонов используемых функций 
void maxim(struct z*, int);
void first(struct z*, int);
void text_data(char *,char *);
void kolvo(struct z *, int);
void alfalist(struct z*,int );
void vstavka(struct z*,char*, int);
void listing(struct z*, int);
void diagram(struct z*, int);
void klav(struct z*, int);
void slozhn(struct z*, int);
void obrvstavka(char*, int);
int main(array<System::String ^> ^args)
{
int NC;//количество позиций
char dan[9][90]={
"Кто и сколько потратил больше всего денег в спортзале?          ",
"Кто и когда из посетителей начал ходить в спортзал раньше всех? ",
"Количество тарифов, введённых с клавиатуры с массой свыше 80 кг ",
"Алфавитный список всех посетителей                              ",
"Диаграмма. Процентное соотношение потраченных денег             ",
"Количество и список абонементов введённых с клавиатуры          ",
"Сложный вопрос. Вес и название тарифа                           ",
"Выход                                                           ",
"                                                                ",
};
char BlankLine[ ]="                                                                  ";
int i,n;
FILE *in;
struct z *clients;
setlocale(LC_CTYPE,"Russian");//поддержка русского языка 
Console::CursorVisible::set(false);//отключаем выдимость курсора
Console::BufferHeight=Console::WindowHeight;//установка размера буфера по ширине
Console::BufferWidth=Console::WindowWidth;//установка размера буфера по высоте 
if((in=fopen("kyrsach.txt","r"))==NULL)//попытка открыть файл
{
printf("\nФайл kyrsach.txt не открыт !");//при неудачном открытии выводим соообщение  “Файл не открыт!” 
getch(); exit(1);
}
fscanf(in,"%d",&NC);
clients=(struct z*)malloc(NC*sizeof(struct z));//выделяем память
for(i=0;i<NC;i++)//считываем данные из списка  
fscanf(in,"%s%s%ld%s%ld",clients[i].name,
clients[i].vid, &clients[i].summa,
clients[i].data,&clients[i].ves);
for(i=0;i<NC;i++)//выводим данные из списка на экран
printf("\n%-20s %-20s %7ld %s %ld",
clients[i].name,
clients[i].vid, clients[i].summa,
clients[i].data,
clients[i].ves);
getch();
while(1)//в цикле создаем область для вопросов и окрашиваем её в цвета
{
//устанавливаем для букв цвет и подсветку для выбранного вопроса
Console::ForegroundColor=ConsoleColor::Green;
Console::BackgroundColor=ConsoleColor::Cyan;
Console::Clear();
Console::ForegroundColor=ConsoleColor::DarkBlue;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;//первая точка, откуда будем закрашивать область меню 
Console::CursorTop=4;
printf(BlankLine);
for(i=0;i<9;i++)//размещение вопросов 
{
Console::CursorLeft=10;
Console::CursorTop=i+5;
printf(" %s ",dan[i]);
}
Console::CursorLeft=10;//последняя точка,где будет заканчиваться выделенная область под меню 
Console::CursorTop=12;
printf(BlankLine);
n=menu(8);//выбор вопроса в меню
switch(n) {
case 1: maxim(clients,NC); break;
case 2: first(clients,NC); break;
case 3: kolvo(clients,NC); break;
case 4: alfalist(clients,NC); break;
case 5: diagram(clients,NC); break;
case 6: klav(clients,NC); break;
case 7: slozhn(clients,NC); break;
//case 7: list(clients); break;
case 8: exit(0);
}
} // конец while(1)...
return 0;
} // конец main()
int menu(int n)
{
int NC;//количество позиций
char dan[9][90]={
"Кто и сколько потратил больше всего денег в спортзале?          ",
"Кто и когда из посетителей начал ходить в спортзал раньше всех? ",
"Количество тарифов, введённых с клавиатуры с массой свыше 80 кг ",
"Алфавитный список всех посетителей                              ",
"Диаграмма. Процентное соотношение потраченных денег             ",
"Количество и список абонементов введённых с клавиатуры          ",
"Сложный вопрос. Вес и название тарифа                           ",
"Выход                                                           ",
"                                                                ",
};
char BlankLine[ ]="                                                                  ";
int y1=0,y2=n-1;//устанавливаем выделение для строчки 
char c=1;
while (c!=ESC)//при нажатии кнопки ESC, меню закроется
{
switch(c) {
case DOWN: y2=y1; y1++; break;//программирование кнопки DOWN, которая позволяет перемещаться вниз по меню
case UP: y2=y1; y1--; break;//программирование кнопки UP, которая позволяет перемещаться вверх по меню
case ENTER: return y1+1;//программирование кнопки ENTER, которая позволяет выбрать вопрос
case HOME: y2=y1; y1=0; break;//программирование кнопки HOME, которая позволяет перемещаться к первой строке в меню
case END: y2=y1; y1=n-1; break;//программирование кнопки END, которая позволяет перемещаться к последней строке в меню
}
if(y1>n-1){y2=n-1;y1=0;}//условие,когда срабатывает кнопка DOWN
if(y1<0) {y2=0;y1=n-1;}//условие,когда срабатывает кнопка UP 
Console::ForegroundColor=ConsoleColor::White;//привыборе вопроса, буквы окрашиваются в белый цвет 
Console::BackgroundColor=ConsoleColor::Blue;//привыборе вопроса, план за буквами подсвечивается голубым
Console::CursorLeft=11;
Console::CursorTop=y1+5;
printf("%s",dan[y1]);
Console::ForegroundColor=ConsoleColor::DarkBlue;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=11;
Console::CursorTop=y2+5;
printf("%s",dan[y2]);
c=getch();
} // конец while(c!=ESC)...
exit(0);
}
//Поиск максимально потраченной суммы в зале
void maxim(struct z* client, int NC)
{
int i=0; struct z best;
strcpy(best.name,client[0].name);//в переменную структуры записываем нулевой элемент
best.summa=client[0].summa;
for(i=1;i<NC;i++)
if (client[i].summa>best.summa)
{
strcpy(best.name,client[i].name);
best.summa=client[i].summa;
}
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;//задаем область, где будет выведено макс.количество  
Console::CursorTop=15;
printf("Максимально потраченная сумма в зале %ld рублей",best.summa);// Вывод максимальной суммы
Console::CursorLeft=10;//задаём область,где будет выведена максимальная сумма
Console::CursorTop=16;
printf("Потратил %s",best.name);//Вывод имени 
struct sp* spisok = nullptr; // Локальная структура списка
getch();
}
void text_data(char *s,char *sd)
{//Перевод даты рождения в строковый формат
char s0[3],month[12][9]={
"января","февраля","марта","апреля","мая","июня",
"июля","августа","сентября","октября","ноября","декабря"};
strcpy(s,sd+8);
strcat(s," ");
strncpy(s0,sd+5,2); s0[2]=0;
strcat(s,month[ atoi(s0)-1]);
strcat(s," ");
strncat(s,sd,4);
return;
}

void first(struct z* client, int NC)
{//Поиск человека, который начал ходить в зал раньше всех
int i;
char s[17];
struct z* best=client;
for(i=1;i<NC;i++)
if (strcmp(client[i].data,best->data)<0)
best=&client[i];
text_data(s,best->data);
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;
Console::CursorTop=15;

Console::CursorLeft=10;
Console::CursorTop=16;
printf("Раньше всех начал ходить %s",best->name);
Console::CursorLeft=10;
Console::CursorTop=17;
printf("Первое  посещение зала было %s ",s);
getch();
}
//Поиск количества людей с тарифом, введённым с клавиатуры, с массой выше 80кг
void kolvo(struct z *client, int NC)
{
int i,k=0;
struct z* nt;
char tarif[20];
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;
Console::CursorTop=15;
printf("Введите название тарифа: ");
SetConsoleCP(1251);
gets(tarif);
SetConsoleCP(866);
for(i=0;i<NC;i++)
if (strcmp(client[i].vid,tarif)==0 && client[i].ves >79)
k++;
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=8;
Console::CursorTop=15;
printf("Всего тарифов, введённых с клавиатуры с массой выше 80 кг: ");
for (i=0,nt=client;i<NC;nt++,i++)
if (strcmp(client[i].vid,tarif)==0 && client[i].ves >79)
printf("\n\r\t %-20s %ld кг",nt->name, nt-> ves);
getch();
}

void alfalist(struct z* client, int NC)//Формирование списка
{// Сортировка всех посетителей по алфавитному порядку
int i,n;
struct sp2* nt2, *mt;
n=NC;
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::Clear();
printf("\n\t Алфавитный список");
printf("\t\t\t\tОбратный список");
printf("\n\t");
printf("\t\n");
if(!spisok2)
for(i=0;i<NC;i++)
obrvstavka(client[i].name,client[i].summa);
for(nt2=spisok2; nt2!=0; nt2=nt2->sled)
printf("\n %-20s %ld",nt2->fio,nt2->summa);
for(nt2=spisok2, mt=0; nt2!=0; mt=nt2, nt2=nt2->sled);
Console::CursorTop=4;
for(nt2=mt,i=0;nt2!=0; i++,nt2=nt2->pred){
Console::CursorLeft=56;
printf("%-20s %ld",nt2->fio,nt2->summa);
Console::CursorTop+=1;
}
getch();
}
void diagram(struct z *client,int NC)//создаем диаграмму 
{// Диаграмма, показывающая соотношение потраченных денег в зале между клиентами
struct sp *nt;//перемеенная для работы со списком 
int len,i,NColor;//i-для номера строки 
long sum = 0 ;//число-100% 
char str1[20];
char str2[20];
System::ConsoleColor Color;//Задаёт константы, которые определяют основной цвет и цвет фона консоли 
Console::ForegroundColor=ConsoleColor::Green;//цвет символов 
Console::BackgroundColor=ConsoleColor::Black;//цвет фона   
Console::Clear();
for(i=0;i<NC;i++) sum = sum+client[i].summa ;
if(!spisok)
for(i=0;i<NC;i++)
vstavka(client,client[i].name, NC);//вставляем из списка названия имен и красим символы в чёрный цвет 
Color=ConsoleColor::Black; NColor=0;
for(nt=spisok,i=0; nt!=0; nt=nt->sled,i++)
{
sprintf(str1,"%s",nt->fio);
sprintf(str2,"%3.1f%%",(nt->summa*100./sum));
Console::ForegroundColor=ConsoleColor::Green;
Console::BackgroundColor= ConsoleColor::Black;
Console::CursorLeft=5; Console::CursorTop=i+1;
printf(str1);
Console::CursorLeft=20;
printf("%s",str2);
Console::BackgroundColor=++Color; NColor++;
Console::CursorLeft=30;
for(len=0; len<nt->summa*100/sum; len++) printf(" ");
if(NColor==14)//выделяем на диаграмму цвета
{ Color=ConsoleColor::Black; NColor=0; }
}
getch();
return ;
}
void klav(struct z *client, int NC)
{// Поиск указанных тарифов. (Ввод названия с клавиатуры)

int i,k=0;
char tarif[20];
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;
Console::CursorTop=15;
printf("Введите название тарифа: ");
SetConsoleCP(1251);
gets(tarif);
SetConsoleCP(866);
for(i=0;i<NC;i++)
	if (strcmp(client[i].vid,tarif)==0)
		k++;
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::Clear();
Console::CursorLeft=11;
Console::CursorTop=16;
printf("Количество тарифов c названием, введённым с клавиатуры: %ld",k);
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=11;
Console::CursorTop=18;
printf("Список людей с данным тарифом:");
for(i=0;i<NC;i++)
	if (strcmp(client[i].vid,tarif)==0)
		printf("\n\t   %s",client[i].name);
getch();
}
void vstavka(struct z* client,char* fio, int NC)
{//Формирование вставки всех данных
int i;
struct sp *nov,*nt,*z=0;
for(nt=spisok; nt!=0 && strcmp(nt->fio,fio)<0; z=nt, nt=nt->sled);
if(nt && strcmp(nt->fio,fio)==0) return;
nov=(struct sp *) malloc(sizeof(struct sp));
strcpy(nov->fio,fio);
nov->sled=nt;
nov->summa=0;
for(i=0;i<NC;i++)
if(strcmp(client[i].name,fio)==0)
nov->summa+=client[i].summa;
if(!z) spisok=nov;
else z->sled=nov;
return;
}

void obrvstavka(char* fio, int summa)
{
struct sp2 *nov2,*nt2,*z2=0;
for(nt2=spisok2; nt2!=0 && strcmp(nt2->fio,fio)<0; z2=nt2, nt2=nt2->sled);
if(nt2 && strcmp(nt2->fio,fio)==0) return;
nov2=(struct sp2 *) malloc(sizeof(struct sp2));
strcpy(nov2->fio,fio);
nov2->summa=summa;
nov2->pred=z2;
nov2->sled=nt2;
if(!z2) spisok2=nov2;
else z2->sled=nov2;
if(nt2) nt2->pred=nov2;
return;
}
void slozhn (struct z* client, int NC)
{//Люди с одинаковым весом и тарифом
int i,j;
int flag=0;
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::Clear();
for (i=0; i<NC;i++)
{
	for (j=i+1; j<NC; j++)
	{
		if ((client[i].ves == client[j].ves)&& (strcmp(client[i].vid, client[j].vid)==0))
		{
			printf("\n ФИО: %s, Тариф: %s, Вес: %ld, --- ФИО: %s, Тариф: %s, Вес: %ld,", client[i].name, client[i].vid, client[i].ves,client[j].name, client[j].vid, client[j].ves);
				flag=1;
			break;}
	}
	if (flag == 1) {break;}
	if (flag == 0) continue;
	if (flag == 0){printf("Нет таких совпадений");}
}
getch();
}