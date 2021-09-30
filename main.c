#include "circ.c"
#include "labels.c"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//#include "Circular.h"
void apostar(int, int, Lista);
void apostarPar(int, int, Lista);

void impMenu(int t) {
	puts("\n**********************");
	if (t==1) {
    printf("1: %s\n", hacer_apuesta[idioma]);
    printf("2: %s\n", girar_ruleta[idioma]);
		printf("3: %s\n", cambiar_idioma[idioma]);
		printf("4: %s\n", abandonar_juego[idioma]);
	} else if (t==2) {
		printf("1: %s\n", rojo_negro[idioma]);
		printf("2: %s\n", par_non[idioma]);
		printf("3: %s\n", pasa_falta[idioma]);
		printf("4: %s\n", docena_lbl[idioma]);
		printf("5: %s\n", columna_lbl[idioma]);
		printf("6: %s\n", numero[idioma]);
		printf("7: %s\n", atras_lbl[idioma]);
	} else if (t==3) {
		printf("1: %s\n", rojo_lbl[idioma]); //37
		printf("2: %s\n", negro_lbl[idioma]); //38
		printf("3: %s\n", atras_lbl[idioma]);
	} else if (t==4) {
		printf("1: %s\n", par_lbl[idioma]); //39
		printf("2: %s\n", non_lbl[idioma]); //40
		printf("3: %s\n", atras_lbl[idioma]);
	} else if (t==5){
		printf("1: %s\n", falta_lbl[idioma]); //41
		printf("2: %s\n", pasa_lbl[idioma]); //42
		printf("3: %s\n", atras_lbl[idioma]);
	} else if (t==6){
		printf("1: %s\n", primera_lbl[idioma]); // 43
		printf("2: %s\n", segunda_lbl[idioma]); // 44
		printf("3: %s\n", tercera_lbl[idioma]); // 45
		printf("4: %s\n", primera_segunda[idioma]); //46
		printf("5: %s\n", segunda_tercera[idioma]); //47
		printf("3: %s\n", atras_lbl[idioma]);
	} else if (t==7){
		printf("1: %s\n", derecha_lbl[idioma]); //48
		printf("2: %s\n", centro_lbl[idioma]); //49
		printf("3: %s\n", izquierda_lbl[idioma]); //50
		printf("4: %s\n", izquierda_ctr[idioma]);//51
		printf("5: %s\n", derecha_ctr[idioma]); //52
		printf("6: %s\n", atras_lbl[idioma]);
	} else if (t==8){
		printf("1: %s\n", solo_uno[idioma]);
		printf("2: %s\n", dos_contiguos[idioma]);
		printf("3: %s\n", atras_lbl[idioma]);
	} else if (t==9){
    printf("1: %s\n", ingles_label[idioma]);
		printf("2: %s\n", espanol_label[idioma]);
		printf("3: %s\n", atras_lbl[idioma]);
  }
	
	puts("**********************");
}

int pideOpc() {
	int r;
	printf("%s: ", elige_opcion[idioma]);
	scanf("%d", &r);
	return r;
}

void actualiza(int saldo, int ap, Lista l) {
	saldo += saldo;
	system("clear");
	int a=gira(0, l);
	printf("%s = $%d\n%s = $%d", saldo_lbl[idioma], saldo, apuestas_lbl[idioma], numElem(l));
}

int menu(int t) {
	int opc, max;
	switch(t) {
		case 1: max=4; break;
		case 2: max=7; break;
		case 3: max=3; break;
		case 4: max=3; break;
		case 5: max=3; break;
		case 6: max=6; break;
		case 7: max=6; break;
		case 8: max=3; break;
    case 9: max=3; break;
	}
	do {
		impMenu(t);
		opc = pideOpc();
	}while(opc<1&&opc>max);
	return opc;
}

int verifica(Lista l, int resul, int saldo) {
	int ganancia=0, colRes, paridad, mitad, columna, docena;
	switch(resul) {
			case 1: case 3: case 5: case 7: case 9: case 12: case 14: case 16: case 18: case 19:
			case 23: case 25: case 27: case 30: case 32: case 34: case 36: colRes = 37; break;
			default: colRes = 38; break;
	}
	if(resul%2==0&&resul!=0) { paridad = 39; } else { paridad = 40; }
	if(resul<=18&&resul>0) { mitad = 41; } else { mitad = 42; }
	if(resul<=12&&resul>0) {docena=43;} else if((resul<=24&&resul>12)){docena=44;}else{ docena = 45;}
	if(resul>0) { columna = 48 + resul%3; }
	while(!esvacia(l)){
		if(cabeza(l)==resul) {
			//puts("Ganas X35");
			saldo += 36;		
		} else if(cabeza(l)==colRes || cabeza(l)==paridad || cabeza(l)==mitad) {
			//puts("Ganas X1");
			saldo +=2;	
		} else if(cabeza(l)==docena || cabeza(l)==columna) {
			saldo +=3;
			//puts("Pierdes");
		} else if(cabeza(l)==46||cabeza(l)==47||cabeza(l)==51||cabeza(l)==51) {
			saldo+=2;
		} else if(cabeza(l)>100) {
			int num = (int)(cabeza(l)/100);
			int num1 = (int)(cabeza(l)%100);
			if(resul==num1||resul==num) {
				saldo+=18;
			} 
		}
		l=resto(l);
	}
	//
	system("clear");
	int a=gira(0, l);
	printf("%s: %d\n", resultado_lbl[idioma], resul);
	if(resul!=0) {
		if(colRes==37) {printf("%s\t", rojo_lbl[idioma]);}
    else {printf("%s\t", negro_lbl[idioma]);}
		if(paridad==39) {printf("%s\t", par_lbl[idioma]);}
    else {printf("%s\t", non_lbl[idioma]);}
		if(mitad==41) {printf("%s\n", falta_lbl[idioma]);}
    else {printf("%s\n", pasa_lbl[idioma]);}
		printf("%s %d %s\n", pertenece_lbl[idioma], docena-42, docena_lbl[idioma]);
		printf("%s %d %s\n", pertenece_lbl[idioma], columna-47, columna_lbl[idioma]);
	}
	printf("%s = $%d\n%s = $%d", saldo_lbl[idioma], saldo, apuestas_lbl[idioma], numElem(l));
	return saldo;
}

int pideApuesta(int saldo){
	if(saldo <= 0) return 0;
  int ap = 0;
  do {
		printf("\n%s ", cuanto_apuestas[idioma]);
		scanf("%d", &ap);
	} while(ap<1||ap>saldo);
	return ap;
}

int pideApuestaPar(int saldo){
	int ap = 0;
	do {
		printf("\n%s (%s):", cuanto_apuestas[idioma], multiplo_de_dos[idioma]);
		scanf("%d", &ap);
	} while((ap<2||ap>saldo)&&ap%2!=0);
	return ap;
}

int ejecuta(int pro,int opc, Lista l, int saldo) {
	int a, num = 0, num1 = 0, i=0, lan;
	system("clear");
	a=gira(0, l);
	printf("%s = $%d\n%s = $%d", saldo_lbl[idioma], saldo, apuestas_lbl[idioma], numElem(l));
	switch(pro) {
		case 1:
			switch(opc) { //Menu Principal
				case 1: saldo = ejecuta(2, menu(2), l, saldo); break;
				case 2:
					if(numElem(l)>0) { 
						a=gira(1, l); saldo = verifica(l, a, saldo);
					} else {
						printf("\n%s", primero_apuesta[idioma]);	
					}
					saldo=ejecuta(1, menu(1), vacia(), saldo);
				break;
        case 3: saldo = ejecuta(9, menu(9), l, saldo); break;
				case 4: 
          printf("\n%s", adios_lbl[idioma]); saldo=0; l=vacia(); exit(0);
        break;
			}
		break;
		case 2: 	
			if(opc>=1&&opc<=6) { //Menu Apuestas
				saldo=ejecuta(opc+2, menu(opc+2), l, saldo);
				if(saldo>0||numElem(l)>0){
					saldo=ejecuta(1, menu(1), l, saldo);
				}
			}else if(opc==7) {
				saldo=ejecuta(1, menu(1), l, saldo);
			}
		break;
		case 3: //Rojo/Negro
			switch(opc) {
				case 1: apostar(37, saldo, l); break;
				case 2: apostar(38, saldo, l); break;
				case 3: saldo = ejecuta(2, menu(2), l, saldo); break;
			}
		break;
		case 4:
			switch(opc) { //Par/Non
				case 1: apostar(39, saldo, l); break;
				case 2: apostar(40, saldo, l); break;
				case 3: saldo = ejecuta(2, menu(2), l, saldo); break;
			}
		break;
		case 5:
			switch(opc) { //Falta/Pasa
				case 1: apostar(41, saldo, l); break;
				case 2: apostar(42, saldo, l); break;
				case 3: saldo= ejecuta(2, menu(2), l, saldo); break;
			}
		break;
		case 6: 
			if(opc>=1&&opc<=3) //Docena
				apostar(42+opc, saldo, l);
			if(opc>=4&&opc<=5)
				apostarPar(45+opc, saldo, l);
			else if(opc==6)
				saldo=ejecuta(2, menu(2), l, saldo);
		break;
		case 7: 
			if(opc>=1&&opc<=5) //Menu Columna
				apostar(47+opc, saldo, l);
			else if(opc==6)
				saldo=ejecuta(2, menu(2), l, saldo);
		break;
		case 8: 
			switch(opc) { //Menu Numero
				case 1: 
					do {
						printf("\n%s: ", ingrese_numero[idioma]);
						scanf("%d", &num);
					} while(num<0||num>36); 
					apostar(num, saldo, l);
				break;
				case 2:
					do {
						printf("\n%s: ", ingrese_num_1[idioma]);
						scanf("%d", &num);
					} while(num<=0||num>36);
					do {
						printf("\n%s: ", ingrese_num_2[idioma]);
						scanf("%d", &num1);
					} while(num1>0&&num1<=36&&(num-num1)!=1&&(num-num1)!=-1&&(num-num1)!=3&&(num-num1)!=-3);
					
					apostar((num*100)+num1, saldo, l);
					apostar((num1*100)+num, saldo, l);
				break;
				case 3:
					saldo = ejecuta(2, menu(2), l, saldo); break;
			}
		break;
    case 9:
      if(opc == 3) {
				ejecuta(1, menu(1), l, saldo); break;
      } else {
        idioma = opc - 1;
        system("clear");
        a=gira(0, l);
        printf("%s = $%d\n%s = $%d", saldo_lbl[idioma], saldo, apuestas_lbl[idioma], numElem(l));
      }
    break;
		default: break;
	}
	return saldo;
}

void apostar(int ap, int saldo, Lista l) {
	int i;
	for(i = pideApuesta(saldo); i > 0; i--) {
		l = cons(ap, l);
		saldo-=1;
	}
	system("clear");
	i=gira(0, l);
	printf("%s = $%d\n%s = $%d", saldo_lbl[idioma], saldo, apuestas_lbl[idioma], numElem(l));
	saldo=ejecuta(1, menu(1), l, saldo);
}

void apostarPar(int ap, int saldo, Lista l) {
	int i;
	for(i = pideApuestaPar(saldo); i > 0; i-=2) {
		l = cons(ap, l);
		saldo-=2;
	}
	system("clear");
	i=gira(0, l);
	printf("%s = $%d\n%s = $%d", saldo_lbl[idioma], saldo, apuestas_lbl[idioma], numElem(l));
	saldo=ejecuta(1, menu(1), l, saldo);
}

int main()
{	
	int idioma = 1;
  int saldo = 1000;
	while(1&&saldo>0) {
   	saldo = ejecuta(1, menu(1), vacia(), saldo);
   }
   return 0;
}

