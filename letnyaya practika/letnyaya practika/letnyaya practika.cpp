#include "stdafx.h" //практика
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
#define ENTER 13 //îáîçíŕ÷ĺíčĺ ęíîďîę 
#define ESC 27
#define UP 72
#define DOWN 80
#define HOME 71
#define END 79
#define _SCL_SECURE_NO_DEPRECATE



struct z {
char name[20];//ÔČÎ ďîńĺňčňĺëĺé
char vid[20];//Íŕçâŕíčĺ ňŕđčôŕ ńďîđňńěĺíîâ
long summa;//Ďîňđŕ÷ĺííŕ˙ ńóěěŕ â çŕëĺ
char data[11];//Äŕňŕ ďĺđâîăî ďîńĺůĺíč˙
long ves;//Âĺń ęëčĺíňîâ
}; //řŕáëîí ńňđóęňóđű äë˙ čńőîäíűő äŕííűő 
struct sp {
char fio[20];
char vid[20];
long summa;
struct sp* sled;
} *spisok;//řŕáëîí, ăëîáŕëüíîĺ îďčńŕíčĺ ńňđóęňóđű äâóńňđîííĺăî ńďčńęŕ 

struct sp2 {
char fio[20];
char vid[20];
long summa;
struct sp2* sled;
struct sp2* pred;
} *spisok2;//řŕáëîí, ăëîáŕëüíîĺ îďčńŕíčĺ ńňđóęňóđű äâóńňđîííĺăî ńďčńęŕ 

int menu(int);//óęŕçŕíčĺ řŕáëîíîâ čńďîëüçóĺěűő ôóíęöčé 
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
int NC;//ęîëč÷ĺńňâî ďîçčöčé
char dan[9][90]={
"Ęňî č ńęîëüęî ďîňđŕňčë áîëüřĺ âńĺăî äĺíĺă â ńďîđňçŕëĺ?          ",
"Ęňî č ęîăäŕ čç ďîńĺňčňĺëĺé íŕ÷ŕë őîäčňü â ńďîđňçŕë đŕíüřĺ âńĺő? ",
"Ęîëč÷ĺńňâî ňŕđčôîâ, ââĺä¸ííűő ń ęëŕâčŕňóđű ń ěŕńńîé ńâűřĺ 80 ęă ",
"Ŕëôŕâčňíűé ńďčńîę âńĺő ďîńĺňčňĺëĺé                              ",
"Äčŕăđŕěěŕ. Ďđîöĺíňíîĺ ńîîňíîřĺíčĺ ďîňđŕ÷ĺííűő äĺíĺă             ",
"Ęîëč÷ĺńňâî č ńďčńîę ŕáîíĺěĺíňîâ ââĺä¸ííűő ń ęëŕâčŕňóđű          ",
"Ńëîćíűé âîďđîń. Âĺń č íŕçâŕíčĺ ňŕđčôŕ                           ",
"Âűőîä                                                           ",
"                                                                ",
};
char BlankLine[ ]="                                                                  ";
int i,n;
FILE *in;
struct z *clients;
setlocale(LC_CTYPE,"Russian");//ďîääĺđćęŕ đóńńęîăî ˙çűęŕ 
Console::CursorVisible::set(false);//îňęëţ÷ŕĺě âűäčěîńňü ęóđńîđŕ
Console::BufferHeight=Console::WindowHeight;//óńňŕíîâęŕ đŕçěĺđŕ áóôĺđŕ ďî řčđčíĺ
Console::BufferWidth=Console::WindowWidth;//óńňŕíîâęŕ đŕçěĺđŕ áóôĺđŕ ďî âűńîňĺ 
if((in=fopen("kyrsach.txt","r"))==NULL)//ďîďűňęŕ îňęđűňü ôŕéë
{
printf("\nÔŕéë kyrsach.txt íĺ îňęđűň !");//ďđč íĺóäŕ÷íîě îňęđűňčč âűâîäčě ńîîîáůĺíčĺ  “Ôŕéë íĺ îňęđűň!” 
getch(); exit(1);
}
fscanf(in,"%d",&NC);
clients=(struct z*)malloc(NC*sizeof(struct z));//âűäĺë˙ĺě ďŕě˙ňü
for(i=0;i<NC;i++)//ń÷čňűâŕĺě äŕííűĺ čç ńďčńęŕ  
fscanf(in,"%s%s%ld%s%ld",clients[i].name,
clients[i].vid, &clients[i].summa,
clients[i].data,&clients[i].ves);
for(i=0;i<NC;i++)//âűâîäčě äŕííűĺ čç ńďčńęŕ íŕ ýęđŕí
printf("\n%-20s %-20s %7ld %s %ld",
clients[i].name,
clients[i].vid, clients[i].summa,
clients[i].data,
clients[i].ves);
getch();
while(1)//â öčęëĺ ńîçäŕĺě îáëŕńňü äë˙ âîďđîńîâ č îęđŕřčâŕĺě ĺ¸ â öâĺňŕ
{
//óńňŕíŕâëčâŕĺě äë˙ áóęâ öâĺň č ďîäńâĺňęó äë˙ âűáđŕííîăî âîďđîńŕ
Console::ForegroundColor=ConsoleColor::Green;
Console::BackgroundColor=ConsoleColor::Cyan;
Console::Clear();
Console::ForegroundColor=ConsoleColor::DarkBlue;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;//ďĺđâŕ˙ ňî÷ęŕ, îňęóäŕ áóäĺě çŕęđŕřčâŕňü îáëŕńňü ěĺíţ 
Console::CursorTop=4;
printf(BlankLine);
for(i=0;i<9;i++)//đŕçěĺůĺíčĺ âîďđîńîâ 
{
Console::CursorLeft=10;
Console::CursorTop=i+5;
printf(" %s ",dan[i]);
}
Console::CursorLeft=10;//ďîńëĺäí˙˙ ňî÷ęŕ,ăäĺ áóäĺň çŕęŕí÷čâŕňüń˙ âűäĺëĺííŕ˙ îáëŕńňü ďîä ěĺíţ 
Console::CursorTop=12;
printf(BlankLine);
n=menu(8);//âűáîđ âîďđîńŕ â ěĺíţ
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
} // ęîíĺö while(1)...
return 0;
} // ęîíĺö main()
int menu(int n)
{
int NC;//ęîëč÷ĺńňâî ďîçčöčé
char dan[9][90]={
"Ęňî č ńęîëüęî ďîňđŕňčë áîëüřĺ âńĺăî äĺíĺă â ńďîđňçŕëĺ?          ",
"Ęňî č ęîăäŕ čç ďîńĺňčňĺëĺé íŕ÷ŕë őîäčňü â ńďîđňçŕë đŕíüřĺ âńĺő? ",
"Ęîëč÷ĺńňâî ňŕđčôîâ, ââĺä¸ííűő ń ęëŕâčŕňóđű ń ěŕńńîé ńâűřĺ 80 ęă ",
"Ŕëôŕâčňíűé ńďčńîę âńĺő ďîńĺňčňĺëĺé                              ",
"Äčŕăđŕěěŕ. Ďđîöĺíňíîĺ ńîîňíîřĺíčĺ ďîňđŕ÷ĺííűő äĺíĺă             ",
"Ęîëč÷ĺńňâî č ńďčńîę ŕáîíĺěĺíňîâ ââĺä¸ííűő ń ęëŕâčŕňóđű          ",
"Ńëîćíűé âîďđîń. Âĺń č íŕçâŕíčĺ ňŕđčôŕ                           ",
"Âűőîä                                                           ",
"                                                                ",
};
char BlankLine[ ]="                                                                  ";
int y1=0,y2=n-1;//óńňŕíŕâëčâŕĺě âűäĺëĺíčĺ äë˙ ńňđî÷ęč 
char c=1;
while (c!=ESC)//ďđč íŕćŕňčč ęíîďęč ESC, ěĺíţ çŕęđîĺňń˙
{
switch(c) {
case DOWN: y2=y1; y1++; break;//ďđîăđŕěěčđîâŕíčĺ ęíîďęč DOWN, ęîňîđŕ˙ ďîçâîë˙ĺň ďĺđĺěĺůŕňüń˙ âíčç ďî ěĺíţ
case UP: y2=y1; y1--; break;//ďđîăđŕěěčđîâŕíčĺ ęíîďęč UP, ęîňîđŕ˙ ďîçâîë˙ĺň ďĺđĺěĺůŕňüń˙ ââĺđő ďî ěĺíţ
case ENTER: return y1+1;//ďđîăđŕěěčđîâŕíčĺ ęíîďęč ENTER, ęîňîđŕ˙ ďîçâîë˙ĺň âűáđŕňü âîďđîń
case HOME: y2=y1; y1=0; break;//ďđîăđŕěěčđîâŕíčĺ ęíîďęč HOME, ęîňîđŕ˙ ďîçâîë˙ĺň ďĺđĺěĺůŕňüń˙ ę ďĺđâîé ńňđîęĺ â ěĺíţ
case END: y2=y1; y1=n-1; break;//ďđîăđŕěěčđîâŕíčĺ ęíîďęč END, ęîňîđŕ˙ ďîçâîë˙ĺň ďĺđĺěĺůŕňüń˙ ę ďîńëĺäíĺé ńňđîęĺ â ěĺíţ
}
if(y1>n-1){y2=n-1;y1=0;}//óńëîâčĺ,ęîăäŕ ńđŕáŕňűâŕĺň ęíîďęŕ DOWN
if(y1<0) {y2=0;y1=n-1;}//óńëîâčĺ,ęîăäŕ ńđŕáŕňűâŕĺň ęíîďęŕ UP 
Console::ForegroundColor=ConsoleColor::White;//ďđčâűáîđĺ âîďđîńŕ, áóęâű îęđŕřčâŕţňń˙ â áĺëűé öâĺň 
Console::BackgroundColor=ConsoleColor::Blue;//ďđčâűáîđĺ âîďđîńŕ, ďëŕí çŕ áóęâŕěč ďîäńâĺ÷čâŕĺňń˙ ăîëóáűě
Console::CursorLeft=11;
Console::CursorTop=y1+5;
printf("%s",dan[y1]);
Console::ForegroundColor=ConsoleColor::DarkBlue;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=11;
Console::CursorTop=y2+5;
printf("%s",dan[y2]);
c=getch();
} // ęîíĺö while(c!=ESC)...
exit(0);
}
//Ďîčńę ěŕęńčěŕëüíî ďîňđŕ÷ĺííîé ńóěěű â çŕëĺ
void maxim(struct z* client, int NC)
{
int i=0; struct z best;
strcpy(best.name,client[0].name);//â ďĺđĺěĺííóţ ńňđóęňóđű çŕďčńűâŕĺě íóëĺâîé ýëĺěĺíň
best.summa=client[0].summa;
for(i=1;i<NC;i++)
if (client[i].summa>best.summa)
{
strcpy(best.name,client[i].name);
best.summa=client[i].summa;
}
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;//çŕäŕĺě îáëŕńňü, ăäĺ áóäĺň âűâĺäĺíî ěŕęń.ęîëč÷ĺńňâî  
Console::CursorTop=15;
printf("Ěŕęńčěŕëüíî ďîňđŕ÷ĺííŕ˙ ńóěěŕ â çŕëĺ %ld đóáëĺé",best.summa);// Âűâîä ěŕęńčěŕëüíîé ńóěěű
Console::CursorLeft=10;//çŕäŕ¸ě îáëŕńňü,ăäĺ áóäĺň âűâĺäĺíŕ ěŕęńčěŕëüíŕ˙ ńóěěŕ
Console::CursorTop=16;
printf("Ďîňđŕňčë %s",best.name);//Âűâîä čěĺíč 
struct sp* spisok = nullptr; // Ëîęŕëüíŕ˙ ńňđóęňóđŕ ńďčńęŕ
getch();
}
void text_data(char *s,char *sd)
{//Ďĺđĺâîä äŕňű đîćäĺíč˙ â ńňđîęîâűé ôîđěŕň
char s0[3],month[12][9]={
"˙íâŕđ˙","ôĺâđŕë˙","ěŕđňŕ","ŕďđĺë˙","ěŕ˙","čţí˙",
"čţë˙","ŕâăóńňŕ","ńĺíň˙áđ˙","îęň˙áđ˙","íî˙áđ˙","äĺęŕáđ˙"};
strcpy(s,sd+8);
strcat(s," ");
strncpy(s0,sd+5,2); s0[2]=0;
strcat(s,month[ atoi(s0)-1]);
strcat(s," ");
strncat(s,sd,4);
return;
}

void first(struct z* client, int NC)
{//Ďîčńę ÷ĺëîâĺęŕ, ęîňîđűé íŕ÷ŕë őîäčňü â çŕë đŕíüřĺ âńĺő
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
printf("Đŕíüřĺ âńĺő íŕ÷ŕë őîäčňü %s",best->name);
Console::CursorLeft=10;
Console::CursorTop=17;
printf("Ďĺđâîĺ  ďîńĺůĺíčĺ çŕëŕ áűëî %s ",s);
getch();
}
//Ďîčńę ęîëč÷ĺńňâŕ ëţäĺé ń ňŕđčôîě, ââĺä¸ííűě ń ęëŕâčŕňóđű, ń ěŕńńîé âűřĺ 80ęă
void kolvo(struct z *client, int NC)
{
int i,k=0;
struct z* nt;
char tarif[20];
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;
Console::CursorTop=15;
printf("Ââĺäčňĺ íŕçâŕíčĺ ňŕđčôŕ: ");
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
printf("Âńĺăî ňŕđčôîâ, ââĺä¸ííűő ń ęëŕâčŕňóđű ń ěŕńńîé âűřĺ 80 ęă: ");
for (i=0,nt=client;i<NC;nt++,i++)
if (strcmp(client[i].vid,tarif)==0 && client[i].ves >79)
printf("\n\r\t %-20s %ld ęă",nt->name, nt-> ves);
getch();
}

void alfalist(struct z* client, int NC)//Ôîđěčđîâŕíčĺ ńďčńęŕ
{// Ńîđňčđîâęŕ âńĺő ďîńĺňčňĺëĺé ďî ŕëôŕâčňíîěó ďîđ˙äęó
int i,n;
struct sp2* nt2, *mt;
n=NC;
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::Clear();
printf("\n\t Ŕëôŕâčňíűé ńďčńîę");
printf("\t\t\t\tÎáđŕňíűé ńďčńîę");
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
void diagram(struct z *client,int NC)//ńîçäŕĺě äčŕăđŕěěó 
{// Äčŕăđŕěěŕ, ďîęŕçűâŕţůŕ˙ ńîîňíîřĺíčĺ ďîňđŕ÷ĺííűő äĺíĺă â çŕëĺ ěĺćäó ęëčĺíňŕěč
struct sp *nt;//ďĺđĺěĺĺííŕ˙ äë˙ đŕáîňű ńî ńďčńęîě 
int len,i,NColor;//i-äë˙ íîěĺđŕ ńňđîęč 
long sum = 0 ;//÷čńëî-100% 
char str1[20];
char str2[20];
System::ConsoleColor Color;//Çŕäŕ¸ň ęîíńňŕíňű, ęîňîđűĺ îďđĺäĺë˙ţň îńíîâíîé öâĺň č öâĺň ôîíŕ ęîíńîëč 
Console::ForegroundColor=ConsoleColor::Green;//öâĺň ńčěâîëîâ 
Console::BackgroundColor=ConsoleColor::Black;//öâĺň ôîíŕ   
Console::Clear();
for(i=0;i<NC;i++) sum = sum+client[i].summa ;
if(!spisok)
for(i=0;i<NC;i++)
vstavka(client,client[i].name, NC);//âńňŕâë˙ĺě čç ńďčńęŕ íŕçâŕíč˙ čěĺí č ęđŕńčě ńčěâîëű â ÷¸đíűé öâĺň 
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
if(NColor==14)//âűäĺë˙ĺě íŕ äčŕăđŕěěó öâĺňŕ
{ Color=ConsoleColor::Black; NColor=0; }
}
getch();
return ;
}
void klav(struct z *client, int NC)
{// Ďîčńę óęŕçŕííűő ňŕđčôîâ. (Ââîä íŕçâŕíč˙ ń ęëŕâčŕňóđű)

int i,k=0;
char tarif[20];
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=10;
Console::CursorTop=15;
printf("Ââĺäčňĺ íŕçâŕíčĺ ňŕđčôŕ: ");
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
printf("Ęîëč÷ĺńňâî ňŕđčôîâ c íŕçâŕíčĺě, ââĺä¸ííűě ń ęëŕâčŕňóđű: %ld",k);
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::Green;
Console::CursorLeft=11;
Console::CursorTop=18;
printf("Ńďčńîę ëţäĺé ń äŕííűě ňŕđčôîě:");
for(i=0;i<NC;i++)
	if (strcmp(client[i].vid,tarif)==0)
		printf("\n\t   %s",client[i].name);
getch();
}
void vstavka(struct z* client,char* fio, int NC)
{//Ôîđěčđîâŕíčĺ âńňŕâęč âńĺő äŕííűő
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
{//Ëţäč ń îäčíŕęîâűě âĺńîě č ňŕđčôîě
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
			printf("\n ÔČÎ: %s, Ňŕđčô: %s, Âĺń: %ld, --- ÔČÎ: %s, Ňŕđčô: %s, Âĺń: %ld,", client[i].name, client[i].vid, client[i].ves,client[j].name, client[j].vid, client[j].ves);
				flag=1;
			break;}
	}
	if (flag == 1) {break;}
	if (flag == 0) continue;
	if (flag == 0){printf("Íĺň ňŕęčő ńîâďŕäĺíčé");}
}
getch();
}
