#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"
//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
   List* L = create_list();
    int* elemento;
    for(size_t k = 1; k <= 10; k++)
    {
         elemento = (int*)malloc(sizeof(int));
         *elemento = k;
         pushBack(L, elemento);
    }

    return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int* elemento;
   elemento = first(L);
   while(elemento != NULL)
   {
      suma += *elemento;
      elemento = next(L);
   }

   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
   int* elemento = first(L);
   while(elemento != NULL)
   {
      if(*elemento == elem)
      {
         popCurrent(L);
      }
      elemento = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
   Stack* aux = create_stack();
   void* elemento = top(P1);
   while(elemento != NULL)
   {
      push(aux, elemento);
      pop(P1);
      elemento = top(P1);
   }

   elemento = top(aux);
   while(elemento != NULL)
   {
      push(P1, elemento);
      push(P2, elemento);
      pop(aux);
      elemento = top(aux);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* Pila = create_stack();
   int talla = strlen(cadena);
   for(int i = 0; i < talla;i++)
   {
      if(cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[')
      {
         push(Pila, &cadena[i]);
      }
      else if(cadena[i] == ')' || cadena[i] == '}' || cadena[i] == ']')
      {
         if(top(Pila) == NULL)
         {
            return 0;
         }

         char apertura = *(char*)top(Pila);
         if((cadena[i] == ')' && apertura != '(') || (cadena[i] == '}' && apertura != '{') || (cadena[i] == ']' && apertura != '['))
         {
            return 0;
         }
         pop(Pila);
      }
   }

   if(top(Pila) == NULL)
      {
         return 1;
      }
   return 0;
}