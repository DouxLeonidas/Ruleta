#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
	Elem dato;
	struct nodo*sig;
}*Nodo;

typedef struct CNodo{
	struct nodo *entrada;
	struct nodo *salida;
}*Cola;

int esnueva(Cola q){
	return q->salida==NULL;
		//return q->entrada==NULL;
}

Cola nueva(){
	Cola q = (Cola) malloc(sizeof(struct CNodo));
	q->salida=q->entrada=NULL;
	return q;
}

Cola formar(Cola q,Elem e){
	Nodo temp=(Nodo) malloc(sizeof(struct nodo));
	temp->dato=e;
		if(esnueva(q))
			q->entrada=q->salida=temp;
		else{
			q->entrada->sig=temp;
			q->entrada=temp;
		}
	return q;
}

Elem primero(Cola q){
	return q->salida->dato;
}

Cola atras(Cola q){
	if(q->entrada==q->salida)
		q->entrada=q->salida=NULL;
	else
		q->salida=q->salida->sig;
  return q;
}

int numElems(Cola q){
	Cola copia = nueva();
	int i=0;
	while(!esnueva(q)){
		copia=formar(copia, primero(q));
		q = atras(q);
	}
	while(!esnueva(copia)){
		q=formar(q, primero(copia));
		copia=atras(copia);
		i++;
	}
	return i;
}


Cola ImpCola(Cola q){
	Cola copia = nueva();
	while(!esnueva(q)){
		impElem(primero(q));
		copia=formar(copia, primero(q));
		q = atras(q);
	}
	while(!esnueva(copia)){
		q=formar(q, primero(copia));
		copia=atras(copia);
	}
	return copia;
}

Elem ultimo(Cola q){
	int n;
	Elem last;
	for(n=numElems(q); n>2; n--){
		q=formar(atras(q), primero(q));
	}
	last=primero(q);
	q=formar(atras(q), primero(q));
	return last;
}

Cola rotar(Cola q) {
	if(!esnueva(q)) {
		return formar((atras(q)), primero(q));
	} else {
		return q;
	}
}
//recibir como argumento cola e imprime elementos
//ImpCola


