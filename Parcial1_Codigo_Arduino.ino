#define SER 2
#define SRCLK 3
#define RCLK 4
//Funcion para prender todos los leds
void verificacion();
//Funcion para mostrar el caracter en los leds
void imagen(char,int);
//Funcion para mostrar los patrones
void publik(char);
//Funcion para leer 8 bites de cada fila y mirar si estan disponibles
void desplazarbyte(uint8_t Pindato, uint8_t Pinreloj, uint8_t val);
short int opcion;
char  letra;
void mostrarleds(int L[],int);
int A[]  = {0,60,102,102,126,102,102,102};
int B[]  = {120,72,72,112,72,68,68,124};
int C[]  = {0,30,32,64,64,64,32,30};
int D[]  = {0,56,36,34,34,36,56,0};
int E[]  = {0,60,32,56,32,32,60,0};
int F[]  = {0,60,32,56,32,32,32,0};
int G[]  = {0,62,32,32,46,34,62,0};
int H[]  = {0,36,36,60,36,36,36,0};
int I[]  = {0,56,16,16,16,16,56,0};
int J[]  = {0,28,8,8,8,40,56,0};
int K[]  = {0,36,40,48,40,36,36,0};
int L[]  = {0,32,32,32,32,32,60,0};
int M[]  = {0,0,68,170,146,130,130,0};
int N[]  = {0,34,50,42,38,34,0,0};
int O[]  = {0,60,66,66,66,66,60,0};
int P[]  = {0,56,36,36,56,32,3,0};
int Q[]  = {0,60,66,66,66,70,62,1};
int R[]  = {0,56,36,36,56,36,36,0};
int S[]  = {0,60,32,60,4,4,60,0};
int T[]  = {0,124,16,16,16,16,16,0};
int U[]  = {0,66,66,66,66,36,24,0};
int V[]  = {0,34,34,34,20,20,8,0};
int W[]  = {0,130,146,84,84,40,0,0};
int X[]  = {0,66,36,24,24,36,66,0};
int Y[]  = {0,68,40,16,16,16,16,0};
int Z[]  = {0,60,4,8,16,32,60,0};
int uno[]   = {3,7,11,3,3,3,3,3};
int dos[]   = {62,66,68,8,16,32,64,255};
int tres[]  = {60,66,2,30,2,66,60,0};
int cuatro[]= {6,18,34,66,255,66,66,2};
int cinco[] = {255,164,164,255,3,3,255,0};
int seis[]  = {8,18,34,124,66,66,60,0};
int siete[] = {255,3,6,12,24,48,96,192};
int ocho[]  = {60,66,66,60,66,66,60,0};
int nueve[] = {255,195,195,255,3,3,3,3};
int cero[]  = {255,129,129,129,129,129,129,255};
int ALL[] = {255,255,255,255,255,255,255,255};
int cara1[] = {0,36,36,0,66,66,60,0};
int cara2[] = {165,165,165,231,0,129,90,36};
int cara3[] = {102,102,0,126,66,66,126,0};


void setup(){
//inicializamos el puerto serial
  Serial.begin(9600);

  //------------------------------

  //pin de salida
  pinMode(SER, OUTPUT);
  //pin de salida
  pinMode(SRCLK, OUTPUT);
  //pin de salida
  pinMode(RCLK, OUTPUT);
  Serial.println("Bienvend@. ¿Que desea hacer? ");
  Serial.println("(1) Verificar que los leds funcionen");
  Serial.println("(2) Mostrar un patron ingresado en los leds");
  Serial.println("(3) Mostrar una secuencia de patrones en los leds");
  Serial.println("(4) Salir ");
}


void loop(){
  //eleccion de usuario
  
  //cuando se ingresa un dato se cumple la condicion
  if(Serial.available()){
    //ciclo en donde se recibe la opcion del usuario
    
      opcion = Serial.read();
      opcion = opcion-48;
      //Opcion de verificacion
      if(opcion == 1){
      	verificacion();
        opcion = 0;
      }
      //Opcion de mostrar patron
      else if(opcion == 2){
        Serial.println("Por favor, ingrese la letra que sea ver en pantalla: ");
        while(true){
      if(Serial.available()){
  	  	letra=Serial.read();   
        delay(1000);
		imagen(letra,5000);
        break;
      }
        }
        opcion = 0;
      }
      //Mostrar secuencia de patrones
      else if(opcion == 3){ 
        publik();
      }
    }while(opcion <1 && opcion >3);
  
}  
void verificacion(){
  for (int i=0; i<=8; i++) {

    desplazarbyte(SER,SRCLK,~ALL[i]);
    desplazarbyte(SER,SRCLK,128 >> i); 
  digitalWrite(RCLK, 1);
  digitalWrite(RCLK, 0);
  }
}
void imagen(char letra,int tiempo){
  
  delay(500);
    if(letra >= 97 && letra <= 122){
    	letra -= 32; 
    }
      //para la letra A
      if(letra == 'A'){
	  mostrarleds(A,tiempo);
      }
      //para letra B
      else if(letra == 'B'){
      mostrarleds(B,tiempo);
      }
      //para letra C
      else if(letra == 'C'){
      	mostrarleds(C,tiempo);
      }
      //para letra D
      else if(letra == 'D'){
     	mostrarleds(D,tiempo);
      }
      //para letra E
      else if(letra == 'E'){
     mostrarleds(E,tiempo);
      }
      //para letra F
      else if(letra == 'F'){
     	mostrarleds(F,tiempo);
      }
      //para letra G
      else if(letra == 'G'){
     	mostrarleds(G,tiempo);
      }
      //para letra H
      else if(letra == 'H'){
     	mostrarleds(H,tiempo);
      }
      //para letra I
      else if(letra == 'I'){
      	mostrarleds(I,tiempo) ;
      }
      //para letra J
      else if(letra == 'J'){
      	mostrarleds(J,tiempo);
      }
      //para letra K
      else if(letra == 'K'){
     	mostrarleds(K,tiempo);
      }
      //para letra L
      else if(letra == 'L'){
     	mostrarleds(L,tiempo);
      }
      //para letra M
      else if(letra == 'M'){
          mostrarleds(M,tiempo);
      }
      //para letra N
      else if(letra == 'N'){
      	mostrarleds(N,tiempo);
      }
      //para letra O
      else if(letra == 'O'){
      	mostrarleds(O,tiempo);
      }
      //para letra P
      else if(letra == 'P'){
      	mostrarleds(P,tiempo);
      }
      //para letra Q
      else if(letra == 'Q'){
      	mostrarleds(Q,tiempo);
      }
      //para letra R
      else if(letra == 'R'){
      	mostrarleds(R,tiempo);
      }
      //para letra S
      else if(letra == 'S'){
      	mostrarleds(S,tiempo);
      }
      //para letra T
      else if(letra == 'T'){
      	mostrarleds(T,tiempo);
      }
      //para letra U
      else if(letra == 'U'){
      	mostrarleds(U,tiempo);
      }
      //para letra V
      else if(letra == 'V'){
      	mostrarleds(V,tiempo);
      }
      //para letra W
      else if(letra == 'W'){
      	mostrarleds(W,tiempo);
      }
      //para letra X
      else if(letra == 'X'){
        mostrarleds(X,tiempo);
      }
      //para letra Y
      else if(letra == 'Y'){
      mostrarleds(Y,tiempo);
      }
      //para letra Z
      else if(letra == 'Z'){
      	mostrarleds(Z,tiempo);
      }
      //para numero 0
      else if(letra == '0'){
      	mostrarleds(cero,tiempo);
      }
      //para numero 1
      else if(letra == '1'){
      	mostrarleds(uno,tiempo);
      }
      //para numero 2
      else if(letra == '2'){
      	mostrarleds(dos,tiempo);
      }
      //para numero 3
      else if(letra == '3'){
      	mostrarleds(tres,tiempo);
      }
      //para numero 4
      else if(letra == '4'){
      	mostrarleds(cuatro,tiempo);
      }
      //para numero 5
      else if(letra == '5'){
      	mostrarleds(cinco,tiempo);
      }
      //para numero 6
      else if(letra == '6'){
      	mostrarleds(seis,tiempo);
      }
      //para numero 7
      else if(letra == '7'){
      	mostrarleds(siete,tiempo);
      }
      //para numero 8
      else if(letra == '8'){
      	mostrarleds(ocho,tiempo);
      }
      //para numero 9
      else if(letra == '9'){
      	mostrarleds(nueve,tiempo);
      }
      //para emoji1
        else if(letra == '!'){
          mostrarleds(cara1,tiempo);
        }
        //para emoji2
      else if(letra == '"'){
      	mostrarleds(cara2,tiempo);
      }
    //para emoji3
        else if(letra == '#'){
          mostrarleds(cara3,tiempo);
        }
}
void desplazarbyte(uint8_t Pindato, uint8_t Pinreloj, uint8_t val){
  	uint8_t i; 
    for (i = 0; i < 8; i++)  {
        digitalWrite(Pindato, !!(val & (1 << i)));   
            digitalWrite(Pinreloj, HIGH);
            digitalWrite(Pinreloj, LOW);            
      }
  }    

void mostrarleds(int L[],int tiempo){
  int contador = 0;
  while(true){
    contador = millis();
  	for (int i=0; i<=8; i++) {
    	desplazarbyte(SER,SRCLK,~L[i]);
    	desplazarbyte(SER,SRCLK,128 >> i); 
    	digitalWrite(RCLK, 1);
    	digitalWrite(RCLK, 0);
  }
    if(contador > tiempo)
      break;
  }
}
void publik(){
String Lpatron;
 char charpatron[]="";
int Npatron, Dpatron;
  Serial.println("Ingrese la cantidad de patrones que desea visualizar");
  while(true){
    if(Serial.available()){
  	  Npatron = Serial.parseInt();
      delay(200);
      break;
    }
  }
  Serial.println("Ingrese el tiempo de visualizacion en segundos entre cada patron : ");
  while(true){
    if(Serial.available()){
  	  Dpatron = Serial.parseInt();
      delay(200);
      break;     
    }
  }
  Dpatron = Dpatron*1000;
  Serial.println("Ingrese La secuencia de patrones: ");
  int largo = 0;
  while(largo < Npatron){
    if(Serial.available()){
      for(int i=0;i<=Npatron;i++){
        charpatron[i]=Serial.read();
        imagen(charpatron[i],Dpatron);
      }
    }
  delay(200);
  }
 
  
}