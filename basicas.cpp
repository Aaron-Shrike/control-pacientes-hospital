#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

#define MAX 50
#define LIM 50


// operacions basicas de datos simples

int leeEntero(char msje[], int min, int max)
{ int num;
  do{
     printf("%s", msje);
     scanf("%d", &num);
  }while(!(num>=min && num<=max));
  return num;
}

float leeReal(char msje[], float min, float max)
{ float num;
  do{
     printf("%s", msje);
     scanf("%f", &num);
  }while(!(num>=min && num<=max));
  return num;
}


//Adicionales
 char leeSexo(char msje[])
{
	char rpta;

   cout << " F : Femenino" <<endl;
   cout << " M : Masculinoino" <<endl;
   do{
   	printf("%s", msje);
      fflush(stdin);            
      scanf("%c",&rpta);
      rpta= toupper(rpta);
   }while(!(rpta=='F' || rpta== 'M'));
   return rpta;
}

//gotoxy  
void gotoxy(int x,int y){ 
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;  
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);  
} 

