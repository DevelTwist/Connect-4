/******************************************
*******************************************   
**                                       **
**    ----- CONNECT - FOUR --------      **
**                                       **
**   User:  DevelTwist                   **
**                                       **
**   Realizado:  20/10/2016              **
**                                       **
**   Ultima Actualizacion: 11/11/2016    **
**                                       **
**                                       **
*******************************************
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "conio.h"

/* NOTA: SE JUEGA CON A - W - D - S - ENTER */

void Iniciar_Mapa(int Mapa[8][8]);
void Imprimir_Mapa(int Mapa[8][8]);
void Imprimir_Selector(int Vector[8]);
int Mover_Selector1(int Vector[8],char Jugador1[20]);
int Mover_Selector2(int Vector[8],char Jugador2[20]);
void Colocar_Bolita1(int a,int Mapa[8][8],int Vector[8],char Jugador1[20]);
void Colocar_Bolita2(int a,int Mapa[8][8],int Vector[8],char Jugador2[20]);

int Lanzar_Dados(char Jugador1[20],char Jugador2[20]);

int Comprueba_Horizontal1(int Mapa[8][8]);
int Comprueba_Vertical1(int Mapa[8][8]);
int Comprueba_Diagonal1(int Mapa[8][8]);

int Comprueba_Horizontal2(int Mapa[8][8]);
int Comprueba_Vertical2(int Mapa[8][8]);
int Comprueba_Diagonal2(int Mapa[8][8]);

int Tres_Horizontal1(int Mapa[8][8]);
int Tres_Horizontal2(int Mapa[8][8]);

int Tres_Vertical1(int Mapa[8][8]);
int Tres_Vertical2(int Mapa[8][8]);

int Tres_Diagonal1(int Mapa[8][8]);
int Tres_Diagonal2(int Mapa[8][8]);

int menu();
void logo();
void Instrucciones();

/* Pre-Juego*/
void logo(){ // DISEÑO DEL LOGO DEL MENU
	
int a=3;	
	
textcolor(5);
printf("             XXXX    XXXXX    XXX     XX  XXXX    XXXX   XXXXXX     XX          ");     
printf("            XX      XX   XX   XX XX   XX  X      XX        XX      XXXX         ");
printf("           XX      XX     XX  XX  XX  XX  XXXX  XX         XX     XX  XX        ");
printf("            XX      XX   XX   XX   XX XX  X      XX        XX    XXXXXXXX       ");
printf("             XXXX    XXXXX    XX     XXX  XXXX    XXXX     XX    XX    XX      ");
printf("\n\n");
textcolor(3);
printf("             CAB                                                                ");
printf("           BA CA           AAAA A   A    XX      XX  XX    XX   XXXXX           ");
printf("          BA  AA           A  A  A A     XX      XX  XX    XX   XX              ");
printf("          ACAAABA          AAA    A      XX      XX  XX    XX     XX            ");
printf("              AA           A  A   A      XX      XX  XX    XX       XX          ");
printf("             ACBA          AAAAA  A      XXXXX   XXXXXX    XX    XXXXX          \n");
textcolor(WHITE);
};
	
int menu(){ // MENU DEL JUEGO, MOVIMIENTO, OPCIONES Y DESPLAZAMIENTO


    gotoxy(1,3);logo();


	int opcion[3]={1,2,3};
	char tecla;
	int tecla1;
	int i=0;
	int x,y;
	int j=4;
	
	x=35;
	y=20;
	
	textcolor(14);
	gotoxy(x-1,y);printf("[%d] JUGAR. \n\n  ",opcion[0]);
	gotoxy(x-1,y+2);printf("[%d] INSTRUCCIONES. \n\n ",opcion[1]);
	gotoxy(x-1,y+4);printf("[%d] SALIR. \n\n",opcion[2]);
	textcolor(WHITE);
	
	gotoxy (x,y);
	textcolor(RED);
    printf ("%c",j);
	textcolor(WHITE);
	
	gotoxy(29,28); textcolor(8); printf(" %c LUIS F. VARGAS 2016",184);
	
	do{
    while ( !kbhit()  ){}
    tecla = getch();
	
	        if (tecla == 'w' || tecla == 'W' ) {
            // Arriba
            if ( y > 20 && y <= 24) {
            	if (y < 21){
            		y = 20;
				}
                gotoxy (x, y);
                textcolor(14);
                printf("%d",opcion[i]);
                i--;
                y = y - 2;
                gotoxy ( x, y );
                textcolor(RED);
                printf ("%c",j);
                textcolor(WHITE);
            }
			} 
			
			
			else if (tecla == 's' || tecla == 'S') {
            // Abajo
            if ( y >= 20  && y  < 24 ){
            	if (y > 25){
            		y = 24;
				}
                gotoxy (x, y );
                textcolor(14);
                printf("%d",opcion[i]);
                textcolor(WHITE);
                i++;
                y = y + 2;
                gotoxy ( x, y );
                textcolor(RED);
                printf ( "%c",j);
                textcolor(WHITE);
            }
			}
            
	}while(tecla != 13);
	
	return i;
}

void Instrucciones(){ // TEXTO DE LAS INSTRUCCIONES
	
	system("cls");
	
	textcolor(14);
	printf(" Conecta 4 Se trata de un juego compuesto por un tablero situado en posicion \nvertical. El objetivo de este juego consiste en colocar cuatro fichas en una\nfila continua vertical, horizontal o diagonalmente. Se juega sobre un tablero\nde 8x8 casillas que al empezar esta vacio. \n\n");
	printf(" Ambos jugadores situan sus fichas (una por movimiento) en el tablero. La regla para colocarlas consiste en que estas siempre caen hasta abajo. Es decir una\nficha puede ser colocada bien en la parte inferior de una columna o bien sobre\notra ficha de alguna otra columna.\n\n\n");
	printf(" La partida termina si una de las siguientes condiciones se cumple: \n\n");
	printf("\n 1) Uno de los jugadores coloca cuatro o mas fichas en una linea continua\nvertical, horizontal o diagonalmente. Este jugador gana la partida. \n");
	printf("\n 2) Todas las casillas del tablero estan ocupadas y ningun jugador cumple la\ncondicion anterior para ganar. En este caso la partida finaliza en empate. \n");
	printf("\n\n\n NOTA: SE JUEGA CON A - D y El Menu Se Desplaza W - S. \n\n\n");
	textcolor(15);
	printf("\n\n\n");
	system("pause");
	
}
/*----- Juego -----*/
int main(){
	
	int Mapa[8][8];
	int Vector[8]={1,2,3,4,5,6,7,8};
	char Jugador1[20],Jugador2[20]; 
	int i;
	int Jugada1, Jugada2;
	int espacios = 64;
	int partida;
	int g1, g2,jg1,jg2;
	float empate,cont_partidas;
	int turno;
	int npartida[5],ldados=0;
	char gronda[5][20];
	int op,c;
	int r,ver,hor,dia;
	int h1,v1,d1,d2,h2,v2;
	char r1;
	
	// JUEGO //
	do{
		/* Inicializar todas los contadores en 0 para el juego */
		empate=0,partida=0,cont_partidas=0,turno=0,ldados=0,ver=0,hor=0,dia=0,h1=0,v1=0,d1=0,d2=0,h2=0,v2=0,g1=0,g2=0;
		for(i=0;i<5;i++){
			npartida[i]=-1;
		}
	do{
	system("cls");
	op = menu();
	
	if(op == 1){
		Instrucciones();
	}
	}while(op == 1);
	
		
	if(op == 0){
	system("cls");
	/* Registro de Jugadores */
	textcolor(14);
	printf ("\n\n Introduce Nombre de Jugador 1: ");
	fflush(stdin);
	textcolor(10);
	gets(Jugador1);
	textcolor(14);
	printf ("\n\n Introduce Nombre de Jugador 2: ");
	fflush(stdin);
	textcolor(11);
	gets(Jugador2);
	textcolor(WHITE);
	printf ("\n\n\n");
	system("cls");
	
 	turno = Lanzar_Dados(Jugador1,Jugador2); // DEPENDIENDO DEL RETORNO, 1 = EMPIEZA JUGADOR 1, 2 = EMPIEZA JUGADOR 2.
 	if(turno == 1){
 		strcpy(gronda[partida],Jugador1);
	 }
	 if(turno == 2){
	 	strcpy(gronda[partida],Jugador2);
	 }
	ldados++;
	npartida[partida] = partida; // Para guardar la partida en que se lanzaron los dados...
	
 do{ // Logica del Juego //
 	
 	system("cls");
 	partida++;
 	if(cont_partidas == 4){
 		partida = cont_partidas+1;;
	 }
 	textcolor(14);
 	printf ("\n\n\n\n\n\n                              PARTIDA %d                                  \n\n\n\n\n\n",partida);
 	textcolor(10);
	printf ("\t\t      %s = %d. ",Jugador1,g1);
	textcolor(11);
	printf ("\n\n\t\t   %s = %d. ",Jugador2,g2);
 	textcolor(WHITE);
 	Sleep(3000);
 	espacios = 64;
 	jg1 = 0; jg2 = 0;
 	Iniciar_Mapa(Mapa); 
 	
	do{
	
	// TURNO JUGADOR 1 //
	if (turno == 1){
	system("cls");
	printf ("\n\n\n \t\t\tBIENVENIDOS A CONECTA 4 \n\n\n\n");
	Imprimir_Selector(Vector);
	Imprimir_Mapa(Mapa);	
	gotoxy (20,26); printf ("Espacios Disponibles: %d. \n\n",espacios);
	Jugada1 = Mover_Selector1(Vector,Jugador1);
	jg1++;
	Colocar_Bolita1(Jugada1,Mapa,Vector,Jugador1);
	espacios--;
	if(espacios == 0){
		break;
	}
		
	// CONTADORES PARA HORIZONTALES VERTICALES Y DIAGONALES - RETORNAR GANADOR ----
	// Si retorna 1 Significa que el Jugador 1 Hizo conecta 4.
	r = 0;
	if(r == 0){
		r = Comprueba_Horizontal1(Mapa);
		system("cls");
		if(r == 1){
			hor++;
		}
	}
	if(r == 0){
		r = Comprueba_Vertical1(Mapa);
		system("cls");
		if(r == 1){
			ver++;
		}
	}
	if(r == 0){
		r = Comprueba_Diagonal1(Mapa);
		system("cls");
		if(r == 1){
			dia++;
		}
	}
	//-----------------------------------------------------//
	turno = 2; // variar turno en la siguiente vuelta.
	if (r == 1){
		g1++;
		turno = 1;
		system("cls");
		textcolor(14);
		printf("\t\t\t \n\n\n El Jugador %s ha ganado la partida : %d. \n\n\n Con: %d Jugadas. \n\n\n",Jugador1,partida,jg1);
		textcolor(WHITE);
		Sleep(5000);
		break;
	}
	}
	// TURNO JUGADOR 2 //
	if (turno == 2){
	system("cls");
	printf ("\n\n\n \t\t\tBIENVENIDOS A CONECTA 4 \n\n\n\n");
	Imprimir_Selector(Vector);
	Imprimir_Mapa(Mapa);
	gotoxy (20,26); printf ("Espacios Disponibles: %d. \n\n",espacios);
	Jugada2 = Mover_Selector2(Vector,Jugador2);
	jg2++;
	Colocar_Bolita2(Jugada2,Mapa,Vector,Jugador2);
	espacios--;
	if(espacios == 0){
		break;
	}
	// CONTADORES PARA HORIZONTALES VERTICALES Y DIAGONALES //
		r = 0;	
	if(r == 0){
		r = Comprueba_Horizontal2(Mapa);
		system("cls");
		if(r == 2){
			hor++;
		}
	}
	if(r == 0){
		r = Comprueba_Vertical2(Mapa);
		if(r == 2){
		system("cls");
			ver++;
		}
	}
	if(r == 0){
		r = Comprueba_Diagonal2(Mapa);
		system("cls");
		if(r == 2){
			dia++;
		}
	}
	// -------------------------------------------------------//	
	turno = 1; // Variar turno en la siguiente vuelta
	if (r == 2){
		g2++;
		turno = 2;
		system("cls");
		textcolor(14);
		printf("\t\t\t \n\n\n El Jugador %s ha ganado la partida : %d. \n\n\n Con: %d Jugadas. \n\n\n",Jugador2,partida,jg2);
		textcolor(WHITE);
		Sleep(5000);
		break;
	}
	}		
	}while(espacios > 0 );
	
	
	if (espacios == 0){ // En CASO DE EMPATE LAS FUNCIONES RECORRERAN TODO EL MAPA Y EMPEZARAN A SUMAR CONTADORES DE TRES EN LINEA y MOSTRARLAS POSTERIORMENTE JUNTO CON LAS JUGADAS.
		empate++;
		turno = Lanzar_Dados(Jugador1,Jugador2);
		if(turno == 1){
		fflush(stdin);
 		strcpy(gronda[partida],Jugador1);
	 	}
	 	if(turno == 2){
	 	fflush(stdin);
	 	strcpy(gronda[partida],Jugador2);
	 	}
		ldados++;
		npartida[partida]=partida;
		h1 = Tres_Horizontal1(Mapa);
		h2 = Tres_Horizontal2(Mapa);
		v1 = Tres_Vertical1(Mapa);
		v2 = Tres_Vertical2(Mapa);
		d1 = Tres_Diagonal1(Mapa);
		d2 = Tres_Diagonal2(Mapa);
		textcolor(10);
		printf("\n\n");
		printf(" Jugador: %s. Logro Tres en Linea: \n\n Horizontal : %d Veces. \n\n Vertical : %d Veces. \n\n Diagonal: %d Veces. \n\n",Jugador1,h1,v1,d1);
		printf("\n\n Jugador: %s. Logro %d Jugadas. \n\n",Jugador1,jg1);
		textcolor(11);
		printf("\n\n Jugador: %s. Logro Tres en Linea: \n\n Horizontal : %d Veces. \n\n Vertical : %d Veces. \n\n Diagonal: %d Veces. \n\n",Jugador2,h2,v2,d2);
		printf("\n\n Jugador: %s. Logro %d Jugadas. \n\n",Jugador2,jg2);
		textcolor(WHITE);
		system("pause");
		}
	
	if (g1 == 3){
		break; // Si el jugador 1 Logra 3 Victorias significa que es ganador indiscutible (3-1) o (3-0) o (3-2) Por lo que el juego terminara...
	}
	if (g2 == 3){
		break; // Si el jugador 2 Logra 3 Victorias significa que es ganador indiscutible (3-1) o (3-0) o (3-2) Por lo que el juego terminara...
	}
	if ( (g1 == 2 && empate == 1 && g2 == 0) || (g2 == 2 && empate == 1 && g1 == 0)){ // Si El Jugador Logro ganar la ronda 2-0 con un Empate el juego terminara...
		break;
	}
	if (g1 == 2 && g2 == 2 || empate >= 4 || (g1 == 1 && g2 == 1 && empate == 2)){
		cont_partidas = partida; // En Caso de empate El juego entrara en una ronda 5 Infinita hasta que se decida el ganador indiscutible (Es decir el mejor de 5) (3-2)
		partida = 3;
	}
		
}while(partida < 4 );
	
	
	/* Mostrar Estadisticas Finales del juego */
	system("cls");
	textcolor(14);
	printf("\n\n MOSTRANDO ESTADISTICAS POR FAVOR ESPERE ..... \n\n");
	textcolor(WHITE);
	Sleep(6000);
	system("cls");
	
	textcolor(14);
	printf("\n 1) Partidas Jugadas: %d. \n",partida);
	Sleep(400);
	printf("\n 2) Partidas Ganadas por %s: %d. \n",Jugador1,g1);
	Sleep(400);
	printf("\n 3) Partidas Ganadas por %s: %d. \n",Jugador2,g2);
	Sleep(400);
	printf("\n 4) Partidas Empatadas: %.0f. \n",empate);
	Sleep(400);
	if(g1 > g2){
		printf("\n 5) Ganador INDISCUTIBLE DEL JUEGO: %s \n",Jugador1);
		Sleep(400);
	}
	else if(g2 > g1){
		printf("\n 5) Ganador INDISCUTIBLE DEL JUEGO: %s \n",Jugador2);
		Sleep(400);
	}
	printf ("\n 6) Porcentaje de Empates: %.2f PORCIENTO \n",(empate / partida)*100);
	Sleep(400);
	printf ("\n 7) Se Lanzaron los Dados %d Veces. \n",ldados);
	Sleep(400);
	for(i = 0 ; i < partida ; i++){
	    if(npartida[i] != -1){
		printf("\n Partida: %d. ------->   Ganador: %s. \n",npartida[i]+1,gronda[i]);
		}
	}
	printf ("\n\n 8) Se Gano en total: \n\n  Vertical : %d Veces. \n  Horizontal: %d Veces. \n  Diagonal: %d Veces. \n\n\n",ver,hor,dia);
	Sleep(400);
	system("pause");
	}
	
	
	if(op == 2){
		break;
	}
	if(op != 2){
	system("cls");
	gotoxy(5,3);
	printf("\n \t\t DESEA VOLVER AL MENU? (S/N): ");
	fflush(stdin);
	scanf("%c",&r1);}
	
	}while(r1 == 's' || r1 == 'S');
	
	
	/* INFORMACION ADICIONAL Y FINAL DEL PROGRAMA */
	system("cls");
	textcolor(14);
	gotoxy(5,3);
	printf(" \t\tGRACIAS POR USAR EL PROGRAMA \n\n\n");
	printf("\n \t NOMBRE DEL PROYECTO: CONECTA 4. ");
	printf("\n\n \t REALIZADO POR: LUIS FERNANDO VARGAS G%cMEZ ",224);
	printf("\n\n \t FECHA: 04/11/2016. \n\n \t UNIVERSIDAD: UNIVERSIDAD NACIONAL EXPERIMENTAL DEL T%cCHIRA (UNET). \n\n",181);
	textcolor(WHITE);
	/***********************************************/
	
printf("\n\n\n");
system("pause");
return 0;	
}

void Iniciar_Mapa(int Mapa[8][8]){ // INICIALIZA TODOS LOS VALORES DEL TABLERO EN 0, QUE SIGNIFICAN QUE ESTAN LIBRES
	
	int i,j;
	int cont = 0;
	
	for(i = 0; i < 8 ; i++){
		for (j = 0 ; j < 8 ; j++){
			Mapa[i][j] = 0;
		}
	}
	
	
}

void Imprimir_Mapa(int Mapa[8][8]){ // IMPRIME TABLERO DE JUEGO
	
	int i,j;
	printf("\n\n");
	
	for(i = 0; i < 8 ; i++){
		printf ("\t\t");
		for(j = 0 ; j < 8 ; j++){
		
		if(Mapa[i][j]==1){
			textcolor(10);
		}
		if(Mapa[i][j]==2){
			textcolor(11);
		}
		if(Mapa[i][j]==0){
			textcolor(7);
		}
		
		printf (" [%c] ",Mapa[i][j]);
		
		
		textcolor(WHITE);
		}
		printf("\n\n");
	}


}

void Imprimir_Selector(int Vector[8]){ // Imprime Barra de Numeros
	
	int i;
	
	printf ("\t\t");
	for(i = 0 ; i < 8 ; i++){
		textcolor(3);
		printf (" [%d] ",Vector[i]);
	}
	
}

int Mover_Selector1(int Vector[8],char Jugador1[20]){ // ASIGNA DONDE QUIERE JUGAR EL JUGADOR 1
	
	int dir,x,y,cx,cy;
	char tecla;
	x = 18;
	y = 7;

	int j=1,e=32;
	int i=0;
	
	textcolor(10);
	gotoxy(60,10); printf("TURNO JUGADOR: ");
	gotoxy(60,15); printf("%s",Jugador1);
	
	gotoxy (x,y);
	textcolor(10);
    printf ( "%c",j);
	textcolor(WHITE);
	
	
	
	do{
    while ( !kbhit()  ){}
    tecla = getch();
	
	        if ( tecla == 'd' || tecla == 'D') {
            // Derecha
            if ( x >= 18 && x < 53 ) {
            	if (x > 52){
            		x = 53;
				}
                gotoxy ( x, y );
                textcolor(3);
                printf ( "%d",Vector[i]);
                textcolor(WHITE);
                i++;
                x = x + 5;
                gotoxy ( x, y );
                textcolor(10);
                printf ( "%c",j);
                textcolor(WHITE);
            }
			} 
			
			
			else if ( tecla == 'a' || tecla == 'A') {
            // Izquierda
            if ( x > 18 && x <= 53 ) {
            	if (x < 19){
            		x = 18;
				}
                gotoxy ( x, y );
                textcolor(3);
                printf ( "%d",Vector[i]);
                textcolor(WHITE);
                i--;
                x = x - 5;
                gotoxy ( x, y );
                textcolor(10);
                printf ( "%c",j);
                textcolor(WHITE);
            }
			}
            
	}while(tecla != 13);
	
	
	return i;	
}

int Mover_Selector2(int Vector[8],char Jugador2[20]){ // ASIGNA DONDE QUIERE JUGAR EL JUGADOR 2
	
	int dir,x,y,cx,cy;
	char tecla;
	x = 18;
	y = 7;
	cx = 0;
	cy = 0;
	int j=2,e=32;
	int i=0;
	
	textcolor(11);
	gotoxy(60,10); printf("TURNO JUGADOR:  ");
	gotoxy(60,15); printf("%s",Jugador2);
	
	gotoxy (x,y);
	textcolor(11);
    printf ( "%c",j);
	textcolor(WHITE);
	
	
	do{
    while ( !kbhit()  ){}
    tecla = getch();
	
	        if ( tecla == 'd' || tecla == 'D' ) {
            // Derecha
            if ( x >= 18 && x < 53 ) {
            	if (x > 52){
            		x = 53;
				}
                gotoxy ( x, y );
                textcolor(3);
                printf ( "%d",Vector[i]);
                textcolor(WHITE);
                i++;
                x = x + 5;
                gotoxy ( x, y );
                textcolor(11);
                printf ( "%c",j);
                textcolor(WHITE);
            }
			} 
			
			
			else if ( tecla == 'a' || tecla == 'A' ) {
            // Izquierda
            if ( x > 18 && x <= 53 ) {
            	if (x < 19){
            		x = 18;
				}
                gotoxy ( x, y );
                textcolor(3);
                printf ( "%d",Vector[i]);
                textcolor(WHITE);
                i--;
                x = x - 5;
                gotoxy ( x, y );
                textcolor(11);
                printf ( "%c",j);
                textcolor(WHITE);
            }
			}
            
	}while(tecla != 13);
	
	
	return i;	
}

void Colocar_Bolita1(int a,int Mapa[8][8],int Vector[8],char Jugador1[20]){  // ASIGNA EL VALOR 1 - JUGADA DEL JUGADOR 1
	
	int i=0;
	int salir = 0;
	
	do{
	
	if(Mapa[i][a] == 0){
				
		do{
			i++;
		}while(Mapa[i][a] == 0 && i <= 7);
		i = i-1;
		Mapa[i][a] = 1;
		salir = 1;
	}
	
	else{
		a = Mover_Selector1(Vector,Jugador1);
	}
	
	}while(salir == 0);
	
}

void Colocar_Bolita2(int a,int Mapa[8][8],int Vector[8],char Jugador2[20]){ // ASIGNA EL VALOR 2 - JUGADA DEL JUGADOR 2

	
	int i=0;
	int salir = 0;
	
	
	do{
	if(Mapa[i][a] == 0){
				
	while(Mapa[i][a] == 0 && i <= 7){
		i= i+1;
	}
		i = i-1;
		Mapa[i][a] = 2;
		salir = 1;
	}
	
	else{
		a = Mover_Selector2(Vector,Jugador2);
	}
	}while(salir == 0);

}

int Comprueba_Horizontal1(int Mapa[8][8]){  // HORIZONTAL TURNO 1
	
	int i,j;
	int cont = 0;
	int ganar = 0;
	
	for(i = 0; i < 8 ; i++){
		cont = 0;
		for (j = 0 ; j < 8 ; j++){
			if (Mapa[i][j] == 1){
				cont++;
			}
			else{
				cont = 0;
			}
			if (cont == 4){
				system("cls");
				Imprimir_Mapa(Mapa);
				textcolor(14);
				printf (" SE HA DETECTADO 4 EN LINEA EN LAS SIGUIENTES POSICIONES: \n\n  [%d][%d] - [%d][%d] - [%d][%d] - [%d][%d]. \n\n DE MANERA HORIZONTAL \n\n",i,j,i,j-1,i,j-2,i,j-3);
				textcolor(WHITE);
				ganar = 1;
				system("pause");
				break;
			}
		} 
	}
	
	return ganar;
}

int Comprueba_Vertical1(int Mapa[8][8]){ // VERTICAL TURNO 1
	
	int i,j;
	int cont = 0;
	int ganar = 0;
	
	for(i = 0; i < 8 ; i++){
		cont = 0;
		for (j = 0 ; j < 8 ; j++){
			if (Mapa[j][i] == 1){
				cont++;
			}
			else{
				cont = 0;
			}
			if (cont == 4){
				system("cls");
				Imprimir_Mapa(Mapa);
				textcolor(14);
				printf (" SE HA DETECTADO 4 EN LINEA EN LAS SIGUIENTES POSICIONES: \n\n  [%d][%d] - [%d][%d] - [%d][%d] - [%d][%d]. \n\n DE MANERA VERTICAL \n\n",j,i,j-1,i,j-2,i,j-3,i);
				textcolor(WHITE);
				system("pause");
				ganar = 1;
				break;
			}
		} 
	}
	
	return ganar;	
}

int Comprueba_Diagonal1(int Mapa[8][8]){ // DIAGONAL TURNO 1
	
	int i,j;
	int ganar = 0;
		
	for (i = 0 ; i < 8 ; i++){
		for (j = 0 ; j < 8 ; j++){
			
			if(Mapa[i][j]==1 && Mapa[i+1][j-1]==1 && Mapa[i+2][j-2]==1 && Mapa[i+3][j-3]==1 && (i+3) < 8 && (j-3) > -1){
				system("cls");
				Imprimir_Mapa(Mapa);
				textcolor(14);
				printf (" SE HA DETECTADO 4 EN LINEA EN LAS SIGUIENTES POSICIONES: \n\n  [%d][%d] - [%d][%d] - [%d][%d] - [%d][%d]. \n\n DE MANERA DIAGONAL \n\n",i,j,i+1,j-1,i+2,j-2,i+3,j-3);
				textcolor(WHITE);
				ganar = 1;
				system("pause");
			}
			
			if(Mapa[i][j]==1 && Mapa[i+1][j+1]==1 && Mapa[i+2][j+2]==1&& Mapa[i+3][j+3]==1 && (j+3) < 8 && (i+3) < 8 ){
				system("cls");
				Imprimir_Mapa(Mapa);
				textcolor(14);
				printf (" SE HA DETECTADO 4 EN LINEA EN LAS SIGUIENTES POSICIONES: \n\n [%d][%d] - [%d][%d] - [%d][%d] - [%d][%d]. \n\n DE MANERA DIAGONAL \n\n",i,j,i+1,j+1,i+2,j+2,i+3,j+3);
				textcolor(WHITE);
				ganar = 1;
				system("pause");
			}
			
			
			
		}
	}
		
	return ganar;
	
}

int Comprueba_Horizontal2(int Mapa[8][8]){  // HORIZONTAL TURNO 2
	
	int i,j;
	int cont = 0;
	int ganar = 0;
	
	for(i = 0; i < 8 ; i++){
		cont = 0;
		for (j = 0 ; j < 8 ; j++){
			if (Mapa[i][j] == 2){
				cont++;
			}
			else{
				cont = 0;
			}
			if (cont == 4){
				system("cls");
				Imprimir_Mapa(Mapa);
				textcolor(14);
				printf (" SE HA DETECTADO 4 EN LINEA EN LAS SIGUIENTES POSICIONES: \n\n  [%d][%d] - [%d][%d] - [%d][%d] - [%d][%d]. \n\n DE MANERA HORIZONTAL \n\n",i,j,i,j-1,i,j-2,i,j-3);
				textcolor(WHITE);
				system("pause");
				ganar = 2;
				break;
			}
		} 
	}
	
	return ganar;
}

int Comprueba_Vertical2(int Mapa[8][8]){ // VERTICAL TURNO 2
	
	int i,j;
	int cont = 0;
	int ganar = 0;
	
	for(i = 0; i < 8 ; i++){
		cont = 0;
		for (j = 0 ; j < 8 ; j++){
			if (Mapa[j][i] == 2){
				cont++;
			}
			else{
				cont = 0;
			}
			if (cont == 4){
				system("cls");
				Imprimir_Mapa(Mapa);
				textcolor(14);
				printf (" SE HA DETECTADO 4 EN LINEA EN LAS SIGUIENTES POSICIONES: \n\n  [%d][%d] - [%d][%d] - [%d][%d] - [%d][%d]. \n\n DE MANERA VERTICAL \n\n",j,i,j-1,i,j-2,i,j-3,i);
				textcolor(WHITE);
				system("pause");
				ganar = 2;
				break;
			}
		} 
	}
	
	return ganar;	
}

int Comprueba_Diagonal2(int Mapa[8][8]){ // DIAGONAL TURNO 2
	
	int i,j;
	int ganar = 0;
		
	for (i = 0 ; i < 8 ; i++){
		for (j = 0 ; j < 8 ; j++){
			
			if(Mapa[i][j]==2 && Mapa[i+1][j-1]==2 && Mapa[i+2][j-2]==2 && Mapa[i+3][j-3]== 2 && (i+3) < 8 && (j-3) > -1 ){
				system("cls");
				Imprimir_Mapa(Mapa);
				textcolor(14);
				printf (" SE HA DETECTADO 4 EN LINEA EN LAS SIGUIENTES POSICIONES: \n\n [%d][%d] - [%d][%d] - [%d][%d] - [%d][%d]. \n\n DE MANERA DIAGONAL \n\n",i,j,i+1,j-1,i+2,j-2,i+3,j-3);
				ganar = 2;
				textcolor(WHITE);
				system("pause");
			}
			
			if(Mapa[i][j]==2 && Mapa[i+1][j+1]==2 && Mapa[i+2][j+2]==2 && Mapa[i+3][j+3]==2 && (i+3) < 8 && (j+3) < 8 ){
				system("cls");
				Imprimir_Mapa(Mapa);
				textcolor(14);
				printf (" SE HA DETECTADO 4 EN LINEA EN LAS SIGUIENTES POSICIONES: \n\n [%d][%d] - [%d][%d] - [%d][%d] - [%d][%d]. \n\n DE MANERA DIAGONAL \n\n",i,j,i+1,j+1,i+2,j+2,i+3,j+3);
				ganar = 2;
				textcolor(WHITE);
				system("pause");
			}
			
			
			
		}
	}
		
	return ganar;
	
}

int Lanzar_Dados(char Jugador1[20],char Jugador2[20]){ // Lanzamiento de dados para decidir quien empieza turno.
	
	int j1= 0, j2 = 0;
	int turno=0;
	
	do{     // Decidir Quien Empieza..........
	system("cls");
	textcolor(5);
	printf ("\n\n  Lanzando Dados : \n\n");
	textcolor(15);
	Sleep(2000);
	srand (time(NULL));
	j1 = rand() % 11 + 1;
	j2 = rand() % 11 + 1;
		
	if (j1 > j2 ){
		turno = 1;
		textcolor(10);
		printf (" [%c] Jugador 1:  %s. dados : %d. \n\n",1,Jugador1,j1);
		textcolor(11);
		printf (" [%c] Jugador 2:  %s. dados : %d. \n\n",2,Jugador2,j2);
		textcolor(14);
		printf ("\n\n  EMPIEZA JUGADOR : %s. \n\n\n",Jugador1);
		textcolor(WHITE);
		system("pause");
	}
	if (j2 > j1 ){
		turno = 2;
		textcolor(10);
		printf (" [%c] Jugador 1:  %s. dados : %d. \n\n",1,Jugador1,j1);
		textcolor(11);
		printf (" [%c] Jugador 2:  %s. dados : %d. \n\n",2,Jugador2,j2);
		textcolor(14);
		printf ("\n\n  EMPIEZA JUGADOR : %s. \n\n\n",Jugador2);
		textcolor(WHITE);
		system("pause");
	}
	if (j2 == j1){
		turno = 0;
		textcolor(10);
		printf (" [%c] Jugador 1:  %s. dados : %d. \n\n",1,Jugador1,j1);
		textcolor(11);
		printf (" [%c] Jugador 2:  %s. dados : %d. \n\n",2,Jugador2,j2);
		textcolor(14);
		printf ("\t\t EMPATE VOLVIENDO A LANZAR DADOS....... \n\n\n");
		Sleep(4000);
		textcolor(WHITE);
	}
	
	}while(turno == 0);
	
	
	
	return turno;
}

int Tres_Horizontal1(int Mapa[8][8]){ // COMPRUEBA 3 EN LINEA HORIZONTAL DEL JUGADOR 1 EN CASO DE EMPATE
	
	int i,j;
	int cont = 0;
	int ganar = 0;
	
	for(i = 0; i < 8 ; i++){
		cont = 0;
		for (j = 0 ; j < 8 ; j++){
			if (Mapa[i][j] == 1){
				cont++;
			}
			else{
				cont = 0;
			}
			if (cont == 3){
				ganar++;
			}
		} 
	}

	return ganar;	
	}	
	
int Tres_Horizontal2(int Mapa[8][8]){ // COMPRUEBA 3 EN LINEA HORIZONTAL DEL JUGADOR 2 EN CASO DE EMPATE
	
	int i,j;
	int ganar=0;
	int cont = 0;

	for(i = 0; i < 8 ; i++){
		cont = 0;
		for (j = 0 ; j < 8 ; j++){
			if (Mapa[i][j] == 2){
				cont++;
			}
			else{
				cont = 0;
			}
			if (cont == 3){
				ganar++;
			}
		} 
	}
	
	return ganar;
}

int Tres_Vertical1(int Mapa[8][8]){ // COMPRUEBA 3 EN LINEA VERTICAL DEL JUGADOR 1 EN CASO DE EMPATE
	
	int i,j;
	int cont = 0;
	int ganar = 0;
	
	for(i = 0; i < 8 ; i++){
		cont = 0;
		for (j = 0 ; j < 8 ; j++){
			if (Mapa[j][i] == 1){
				cont++;
			}
			else{
				cont = 0;
			}
			if (cont == 3){
				ganar++;
			}
		} 
	}
	
	return ganar;
	}
	
int Tres_Vertical2(int Mapa[8][8]){ // COMPRUEBA 3 EN LINEA VERTICAL DEL JUGADOR 2 EN CASO DE EMPATE
	
	int i,j;
	int cont=0;
	int ganar=0;
	
	for(i = 0; i < 8 ; i++){
		cont = 0;
		for (j = 0 ; j < 8 ; j++){
			if (Mapa[j][i] == 2){
				cont++;
			}
			else{
				cont = 0;
			}
			if (cont == 3){
				ganar++;
			}
		} 
	}
	
	return ganar;
}

int Tres_Diagonal1(int Mapa[8][8]){ // COMPRUEBA 3 EN LINEA DIAGONAL DEL JUGADOR 1 EN CASO DE EMPATE
	
	int i,j;
	int dia=0;
		
	for (i = 0 ; i < 8 ; i++){
		for (j = 0 ; j < 8 ; j++){
			
			if(Mapa[i][j]==1 && Mapa[i+1][j-1]==1 && Mapa[i+2][j-2]==1 && (i+2) < 8){
				dia++;
			}
			
			if(Mapa[i][j]==1 && Mapa[i+1][j+1]==1 && Mapa[i+2][j+2]==1 && (i+2) < 8 ){
				dia++;
			}
						
		}
	}
		
	return dia++;
}

int Tres_Diagonal2(int Mapa[8][8]){ // COMPRUEBA 3 EN LINEA DIAGONAL DEL JUGADOR 2 EN CASO DE EMPATE
	
	int i,j;
	int dia=0;
		
	for (i = 0 ; i < 8 ; i++){
		for (j = 0 ; j < 8 ; j++){
			
			if(Mapa[i][j]==2 && Mapa[i+1][j-1]==2 && Mapa[i+2][j-2]==2 && (i+2) < 8){
				dia++;
			}
			
			if(Mapa[i][j]==2 && Mapa[i+1][j+1]==2 && Mapa[i+2][j+2]==2 && (i+2) < 8 ){
				dia++;
			}
						
		}
	}
		
	return dia++;
}


