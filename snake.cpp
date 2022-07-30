#include <windows.h>
#include <iostream>
#include <conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27
using namespace std;
char tecla;
int cuerpo[200][2];
int n=1;
int tam=4;
int dir=3;
int x=10, y=12;
int xc=30,yc=15;
int velocidad=100,h=1;
int score=0;
void gotoxy(int x, int y){

 HANDLE hCon;
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y = y;
 hCon= GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hCon,dwPos);

}
void pintar(){
for (int i = 2; i < 78; i++)
{
 gotoxy(i,3);
 printf("%c",205);
 gotoxy(i,23); printf("%c",205);

}
for (int i = 4; i < 23; i++)

{
 
 gotoxy(2,i);printf("%c",186);
 gotoxy(77,i); printf("%c",186);
 /* code */
}
//esquinas
gotoxy(2,3);printf("%c",201);
gotoxy(2,23);printf("%c",200);
gotoxy(77,3);printf("%c",187);
gotoxy(77,23);printf("%c",188);
 
}
void guardar_posicion(){

cuerpo[n][0]=x;
cuerpo[n][1]=y;
n++;
if(n==tam)n=1;

}
void pintar_cuerpo(){
for(int i=1;i<tam;i++){

 gotoxy(cuerpo[i][0],cuerpo[i][1]);printf("*");
}


}
void borrar_cuerpo(){

 gotoxy(cuerpo[n][0], cuerpo[n][1]);printf(" ");

}
void teclear(){
if(kbhit()){

 tecla=getch();
switch (tecla){
case ARRIBA:
if(dir!=2){

dir=1;
}
break;
case ABAJO:
if(dir!=1){

dir=2;
}
break;
case IZQUIERDA:
if(dir!=3){

dir=4;
}
break;
case DERECHA:
if(dir!=4){

dir=3;
}
break;
}}

}


void comida(){

 if(x==xc&&y==yc){
xc=(rand()%73)+4;
yc=(rand()%19)+4;
score++;
tam++;
gotoxy(xc,yc);printf("%c",64);


 }
}
bool game_over(){
if(y==3||y==23||x==2||x==77) return true;
for(int j =tam-1;j>0;j--){

if (cuerpo[j][0]==x&&cuerpo[j][1]==y){
 return true;
}


}
return false;

}
void puntos(){
gotoxy(3,1);printf("score %d",score);

}
void cambiar_velocidad(){
if(score==h*20){
 velocidad-=10;
 h++;
}
}
void imprimir_game_over(){


 system("cls");
  cout << "  _____      ___       ___  ___   _____"    << endl;
    cout << " / ___ |    /   |     /   |/   | |  ___|"  << endl;
    cout << "| |        / /| |    / /|   /| | | |__"    << endl;
    cout << "| |  _    / ___ |   / / |__/ | | |  __|"   << endl;
    cout << "| |_| |  / /  | |  / /       | | | |___"   << endl;
    cout << " ____/ /_/   |_| /_/        |_| |_____|"  << endl;
    cout << " _____   _     _   _____   _____"          << endl;
    cout << "/  _   | |   / / |  ___| |  _   "        << endl;
    cout << "| | | | | |  / /  | |__   | |_| |"         << endl;
    cout << "| | | | | | / /   |  __|  |  _  /"         << endl;
    cout << "| |_| | | |/ /    | |___  | |   "        << endl;
    cout << " _____/ |___/     |_____| |_|   "       << endl;
    cout << endl << endl;
}
int main(){
 //cuerpo
 
 
pintar(); 
gotoxy(xc,yc);printf("%c",64);
 while(tecla!=ESC&&!game_over()){
borrar_cuerpo();
guardar_posicion();
pintar_cuerpo();
comida();
puntos();
cambiar_velocidad();
teclear();
teclear();
if(dir==1) y--;
if(dir==2) y++;
if(dir==3) x++;
if(dir==4) x--;
Sleep(velocidad);

 }
 //dibujar cuerpo
for (int j=0;j<3;j++){

 gotoxy(cuerpo[j][0],cuerpo[j][1]);
 printf("*");

}
imprimir_game_over();
system("pause>null");
 return 0;
}

