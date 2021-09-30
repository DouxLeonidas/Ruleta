#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Lista.h"
#include "Cola2.h"
#define rad 13
#define varia 52

int idioma;
int gira(int, Lista);
void tablero(int, Lista);
void busca(int, int *, int *);
void texto(int);
int vacios(int i, int j);
void colorea(int, int, int);
Cola ruleta();

int gira(int rul, Lista ap) {
	int i, fa=0, j, m=0, t, limite, ext;
	int ra, re;
  Cola num = ruleta();
	srand((unsigned int)time(0));
	ra=(rand()%2000000) + 1900000;
	if(rul==1) {
		limite = 90000000;
		ext=0;
	} else { limite = ra+1; ext = 5; }
	re=rand()%36;
  for(t=ra; t<limite; t+=ra) {
     for(j = 0; j <= rad*2-ext; j++) {
		 	for(i = 0; i <= rad*2; i++) {
		 	  if(rul == 1) {
		 		int d = (rad-i)*(rad-i) + (rad-j)*(rad-j); 
			 	if( (d < rad*rad && d >= (rad-2)*(rad-2)) || (d < (rad-6)*(rad-6) && d >= (rad-7)*(rad-7)) ) {
			 		printf("\x1b[43m" "  " "\x1b[0m");
			 	} else if( d < (rad-2)*(rad-2) && d >= (rad-6)*(rad-6) ) {
			 		if(j<=rad/2 && i<=3*rad/2) {
				 		if(((i-m)/2)%2==0) {
				 			printf("\x1b[41m" "  " "\x1b[0m");
					 	} else {
					 		printf("\x1b[40m" "  " "\x1b[0m");
					 	}
				 		num = rotar(num);
			 		} else if(j<=3*rad/2 && i>=3*rad/2) {
			 			if(((j-m)/2)%2==0) {
					 		printf("\x1b[41m" "  " "\x1b[0m");
					 	} else {
					 		printf("\x1b[40m" "  " "\x1b[0m");
					 	}
			 		} else if(j>=3*rad/2 && i>=rad/2) {
			 			if(((i+m)/2)%2==0) {
				 			printf("\x1b[41m" "  " "\x1b[0m");
				 		} else {
				 			printf("\x1b[40m" "  " "\x1b[0m");
				 		}
			 		} else {
			 			if(((j+m)/2)%2==0) {
					 		printf("\x1b[41m" "  " "\x1b[0m");
					 	} else {
					 		printf("\x1b[40m" "  " "\x1b[0m");
					 	}
			 		}
			 		
			 	} else {
			 		if((i-2>rad/2 && i+1<3*rad/2)&&(j-2>rad/2 && j+1<3*rad/2)) {
			 			if(fa==1) {
				 			if(((i==rad)||(j==rad))) {
				 				printf("\x1b[47m" "  " "\x1b[0m");
				 			} else {
				 				printf("\x1b[42m" "  " "\x1b[0m");
				 			}
			 			} else {
			 				if((i==j||i==(2*rad-j))&&i-3!=rad/2&&i+2!=3*rad/2) {
				 				printf("\x1b[47m" "  " "\x1b[0m");
				 			}  else {
				 				printf("\x1b[42m" "  " "\x1b[0m");
				 			}
			 			}
			 		} else {
			 			printf("\x1b[42m" "  " "\x1b[0m");
			 		}
			 	}
			  }
			}
			//printf("\t%d", j);
			printf("\t");
			tablero(j, ap);
			puts("");
		 }
		 m++;
		 int l;
		 if(rul==1){
		 for(l=0; l<t; l++){}
     system("clear");
		 }
		 if(fa==1) {
		 	fa = 0;
		 } else {
		 	fa=1;
		 }
    }
    return re;
}

void tablero(int j, Lista ap) {
	int a, x, y, c=0, p, w=0;
	int arr[numElem(ap)];
	int bien[varia];
	for(c=0; c<varia; c++)
		bien[c]=0;
	c=0;
	while(!esvacia(ap)) {
		arr[c++] = (int)cabeza(ap);
		ap = resto(ap);
	}
	for(p = 0; p < c; p++){
		ap = cons(arr[p], ap);
		bien[arr[p]]++;
	}
	if(j>=3&&j<=19) {
		for(a=42; a>=0; a--) {
			if(j>=4) {
				if(!vacios(a,j)) {
					if((j-1)%3==0) {
						if(a%3==0)
							if((j>13&&a==42)||(j>13&&a==0)) {
								printf(" ");
							} else {
								printf("\x1b[47m" " " "\x1b[0m");
							}
						else
							if((j>13&&a>=40)||(j>13&&a<=2)) {
								printf(" ");
							} else {
								if(a==41||a==40)
									if(j>5&&j<12)
										printf(" ");
									else
										printf("\x1b[47m" " " "\x1b[0m");
								else
									printf("\x1b[47m" " " "\x1b[0m");
							}
					} else {
						if(a%3==0)
							if(j>12&&a==42) {
								printf(" ");
							} else {
								if(j>12&&j<=15) {
									if((a-3)%12==0){
										printf("\x1b[47m" " " "\x1b[0m");
									} else {
										printf(" ");
									}
								} else if(j>15) {
									if((a-3)%6==0){
										printf("\x1b[47m" " " "\x1b[0m");
									} else {
										printf(" ");
									}
								} else {
									printf("\x1b[47m" " " "\x1b[0m");
								}
							}
						else {
							if((a<40&&a>=31)||(a<21&&a>=12)) {
								colorea(j, a, 1);
							} else if((a<31&&a>=21)||(a<12&&a>=2)) {
								colorea(j, a, 0);
							} else {
								printf(" ");
							}
						}
					}
				}
			} else {
				//printf("%d", (int)a%10);
			}
			int encont = 0;
			for(c=0; c<p; c++) {
				busca(arr[c], &x, &y);
				if(x==42-a&&y==j) {
					printf("\x1b[43m" "\b " "\x1b[0m");
					encont =1;
				}
			}
		}
		/*int enc = 0;
		while(enc==0&&w<varia) {
			if(bien[w]>0) {
				enc = 1;
				printf("\tHay $%d", bien[w]);
				texto(w);
				bien[w]=0;
			}
			w++;
		}*/
	}
}

void colorea(int j, int a, int color) {
	if((j<=12&&j>9)||(j<=6&&j>3)) {
		if(a<40&&a>2)
			if((a-1)%6==0||(a-2)%6==0)
				printf("\x1b[4%dm" " " "\x1b[0m", color);
			else
				printf("\x1b[4%dm" " " "\x1b[0m", !color);
		else
			printf(" ");
	} else if(j<=9&&a<40&&a>2) {
		if((a-4)%6==0||(a-5)%6==0) {
			printf("\x1b[4%dm" " " "\x1b[0m", color);
		} else
			printf("\x1b[4%dm" " " "\x1b[0m", !color);
	} else {
		printf(" ");
	}
}

int vacios(int i, int j) {
	int t, y, r=37, re = 0;
	int sec[] = {1,0,1,0,1,0,1,0,1,
					 1,0,0,0,1,0,1,0,1,
					 1,0,1,0,1,0,1,0,1,
					 1,0,0,0,1,0,1,0,1};
	/*if(j==9){
		if(i==41||i==40) {
			printf("\x1b[47m" " " "\x1b[0m");
			re=1;
		}
	}*/
	if(j==5||j==8||j==11) {
		if(i==1){
			printf("%d", 4-(j-2)/3);
			re=1;
		}
	}
	if(j==9){
		if(i==40) {
			printf("0");
			re=1;
		}
	}
	if(j==11||j==12){
		if(i==29||i==11) {
			printf("\x1b[40m" " " "\x1b[0m");
			re=1;
		}
	}
	if((j==12&&i==28)||(j==12&&i==10)) {
		printf("\x1b[40m" " " "\x1b[0m");
		re=1;
	}
	if(j==14){
		if(i==36||i==31||i==19||i==7){ printf("1"); re=1; }
		if(i==24||i==30||i==18||i==6) { printf("2");	re=1;	}
		if(i==12) {	printf("3"); re=1;}
		if(i==35||i==23||i==11) {printf(" "); re=1; }
		if(i==34){ printf("s"); re=1;	}
		if(i==33){ printf("t");	re=1;	}
		if(i==22){ printf("n"); re=1;	}
		if(i==10){ printf("r"); re=1;	}
		if(i==21||i==9){ printf("d"); re=1; }
	}
	if(j==17){
		if(i==38||i==36||i==8){ printf("1"); re=1; }
		if(i==37||i==6){ printf("-"); re=1;	}
		if(i==35){ printf("8"); re=1;	}
		if(i==7){ printf("9"); re=1;	}
		if(i==5){ printf("3"); re=1;	}
		if(i==4){ printf("6"); re=1;	}
    if(idioma != 1) {
      if(i==32){ printf("e"); re=1; }
      if(i==31){ printf("v"); re=1; }
      if(i==30){ printf("e"); re=1;	}
      if(i==29){ printf("n"); re=1;	}
      if(i==13){ printf("o"); re=1; }
      if(i==12||i==11){ printf("d"); re=1; }
    } else {
      if(i==31){ printf("p"); re=1;}
      if(i==30){ printf("a"); re=1;	}
      if(i==29){ printf("r"); re=1;	}
      if(i==13||i==11){ printf("n"); re=1; }
      if(i==12){ printf("o"); re=1; }
    }
		if(i<=26&&i>=22){ printf("\x1b[41m" " " "\x1b[0m"); re=1;	}
		if(i<=20&&i>=16){ printf("\x1b[40m" " " "\x1b[0m"); re=1;	}
		//if(i==35){ printf("m"); re=1;	}
	}
	if(j==18){	
		if(i<=26&&i>=22){ printf("\x1b[41m" " " "\x1b[0m"); re=1;	}
		if(i<=20&&i>=16){ printf("\x1b[40m" " " "\x1b[0m"); re=1;	}
	}
	for(r=37; r>3; r-=3) {
		y = 3*(((37-r)/3)+1);
		for(t=5; t<=11; t+=3) {
			if(j==t&&i==r){
				if(y>=10) {
					printf("\b");
				}
				printf("\x1b[4%dm" "%d" "\x1b[0m", sec[(int)(((t-5)/3)+3*((37-r)/3))], y);
				re=1;
			}
			y--;
		}
	}
	return re;
}

void busca(int ap, int *x,int *y) {
	int x1, y1, x2, y2;
	switch(ap) {
		case 0: *x=2; *y=10; break;
		case 1 ... 36: *x=5+(3*(int)((ap-1)/3)); if(ap%3==2) {*y=9; } else { *y=6*((ap%3)+1); } break;
		case 37:	*x=18; *y=18; break; //rojos
		case 38:	*x=24; *y=18; break; //negros
		case 39:	*x=12; *y=18; break; //pares
		case 40:	*x=30; *y=18; break; //nones
		case 41:	*x=6; *y=18; break; //falta
		case 42:	*x=36; *y=18; break; //pasa
		case 43: *x=9; *y=15; break; //1ra 12
		case 44: *x=21; *y=15; break; //2da 12
		case 45: *x=33; *y=15; break; //3ra 12
		case 46: *x=15; *y=15; break; //1ra y 2da
		case 47: *x=27; *y=15; break; //2da y 3ra
		case 48: *x=41; *y=6; break; //3 (Derecha)
		case 49: *x=41; *y=9; break; //2 (Centro)
		case 50: *x=41; *y=12; break; //1 (Izquierda)
		case 51: *x=41; *y=10; break; //3 y 2
		case 52: *x=41; *y=7; break; //2 y 1
		case 100 ... 3635: 
			busca((int)(ap/100), &x1, &y1); 
			busca((int)(ap%100), &x2, &y2); 
			*x=abs(x2-x1); 
			*y=abs(y2-y1); 
		break;
	}
}

void texto(int bus) {	
	if(bus>=0&&bus<=36) {
		printf(" el %d.", bus);
	} else {
		switch(bus) {
			case 37:	printf(" los rojos."); break;
			case 38:	printf(" los negros."); break;
			case 39:	printf(" los pares."); break;
			case 40:	printf(" los nones."); break;
			case 41:	printf(" falta (1-18)."); break;
			case 42:	printf(" pasa (19-20)."); break;
		}
	}
}

Cola ruleta() {
	Cola num = nueva();
	num = formar(num, 0);	num = formar(num, 32);	num = formar(num, 15);	num = formar(num, 19);
	num = formar(num, 4);	num = formar(num, 21);	num = formar(num, 2);	num = formar(num, 25);
	num = formar(num, 17);	num = formar(num, 34);	num = formar(num, 6);	num = formar(num, 27);
	num = formar(num, 13);	num = formar(num, 36);	num = formar(num, 11);	num = formar(num, 30);
	num = formar(num, 8);	num = formar(num, 23);	num = formar(num, 10);	num = formar(num, 5);
	num = formar(num, 24);	num = formar(num, 26);	num = formar(num, 33);	num = formar(num, 1);
	num = formar(num, 20);	num = formar(num, 14);	num = formar(num, 31);	num = formar(num, 9);
	num = formar(num, 22);	num = formar(num, 18);	num = formar(num, 29);	num = formar(num, 7);
	num = formar(num, 28);	num = formar(num, 12);	num = formar(num, 35);	num = formar(num, 3);
	num = formar(num, 26);
	return num;
}
