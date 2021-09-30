#include <stdio.h>
typedef int Elem;

void impElem(Elem e) {
   printf("%d", e);
}

int esIgual(Elem e, Elem t) {
   return e==t;
}

int esMenor(Elem e, Elem t) {
   return e<t;
}
