#include "Elem.h"
#include "malloc.h"

typedef struct Nodo{
	Elem dato;
	Elem color;
	struct Nodo *sig;
	}*Lista;

int esvacia(Lista);
int numElem(Lista);
int estaEn(Elem,Lista);
int ocurrencia(Elem,Lista);

void impLista(Lista);
void impRevez(Lista);

Lista vacia();
Lista cons(Elem, Lista);
Lista pega(Lista,Lista);
Lista resto(Lista);
Lista invertir(Lista);
Lista insOrd(Elem,Lista);
Lista ordena(Lista);

Elem cabeza(Lista);


Lista vacia(){ return NULL; }

Lista cons(Elem e, Lista l){
	Lista t = (Lista) malloc(sizeof(struct Nodo));
	t -> dato = e;
	t -> sig =l;
	return t;
}
          
int esvacia(Lista l){
   return l == NULL;
} 

Elem cabeza(Lista l){ return l -> dato; }

Lista resto(Lista l){ return l -> sig; }

int numElem(Lista l){
	if(esvacia(l)) return 0;
	else return 1+ numElem( resto(l) );
}

void impLista(Lista l){
	if (!esvacia(l)){
		impElem(cabeza(l));
		impLista(resto(l));
	}
}

void impRevez(Lista l){
	if (!esvacia(l)){
		impLista(resto(l));
		impElem(cabeza(l));
	}
}

Lista pega(Lista l1,Lista l2){
	if(esvacia(l1)) return l2;
	else return cons( cabeza(l1) ,pega( resto(l1),l2 ) );
}

Lista invertir(Lista l1){
	if( esvacia(l1) ) return l1;
	else return pega( invertir( resto(l1) ) , cons(cabeza(l1),vacia()) );
}

Lista insOrd(Elem e,Lista l){
	if (esvacia(l))
		return cons(e,vacia());
	else{
		if (esMenor(e,cabeza(l)))
			return cons(e,l);
		else
			return cons( cabeza(l) , insOrd( e,resto(l) ) );
	}
}

Lista ordena(Lista l){
	if( esvacia(l) ) return l;
	else return insOrd( cabeza(l) , ordena(resto(l)) );
}

int estaEn(Elem e,Lista l){
	if (esvacia(l)) { 
		return 0;
	} else {
		if ( esIgual(e,cabeza(l)) ) {
			return 1;
		} else {
			return estaEn( e,resto(l) );
		}
	}
}

int ocurrencia(Elem e,Lista l){
	if (esvacia(l)) return 0;
	if ( esIgual(e,cabeza(l)) ) 
		return 1+ocurrencia( e,  resto(l) );

	return ocurrencia( e,  resto(l) );
}

int listaEnLista(Lista l1,Lista l2){
	if (esvacia(l1) && esvacia(l2)) 
		return 1;
	if (!esvacia(l1) || !esvacia(l2))
		if (esIgual(cabeza(l1),cabeza(l2)))
			return listaEnLista(resto(l1),resto(l2));
	return 0;
}
