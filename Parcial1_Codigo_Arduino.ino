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
char letra;
void mostrarleds(int *Lista,int);
int ALL[]   = {255,255,255,255,255,255,255,255};
float time = 4000.0;


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
  	  	letra = Serial.read();   
        delay(1000);
        imagen(letra,time);
		Serial.println("\n\n\n\n\n\n\n\n");
        break;
      }
        }
      Serial.println("(1) Verificar que los leds funcionen");
  	  Serial.println("(2) Mostrar un patron ingresado en los leds");
  	  Serial.println("(3) Mostrar una secuencia de patrones en los leds");
 	  Serial.println("(4) Salir ");
      opcion = 0;
      }
      //Mostrar secuencia de patrones
      else if(opcion == 3){ 
        publik();     
        opcion = 0;
        Serial.println("\n\n\n\n\n\n\n\n");
      }
   	  else if(opcion == 4){
        Serial.print("Adios bebe <3");
        delay(400);
    	exit(0);
    }	
    }while(opcion <1 && opcion >3);
  
}  
//Definicion de funciones--------------------------------
void verificacion(){
  for (int i=0; i<=8; i++) {

    desplazarbyte(SER,SRCLK,~ALL[i]);
    desplazarbyte(SER,SRCLK,128 >> i); 
  digitalWrite(RCLK, 1);
  digitalWrite(RCLK, 0);
  }
}
void imagen(char letra,float tiempo){
    int *valores = new int[8];
    if(letra >= 97 && letra <= 122){
    	letra -= 32; 
    }
      //para la letra A
      if(letra == 'A'){
      	int A[]  = {0,60,102,102,126,102,102,102};
		valores = A;
	  	mostrarleds(valores,tiempo);
      }
      //para letra B
      else if(letra == 'B'){
        int B[]  = {248,198,198,216,216,206,198,248};
		valores = B;
	  	mostrarleds(valores,tiempo);
      }
      //para letra C
      else if(letra == 'C'){
        int C[]  = {0,31,127,192,192,127,31,0};
      	valores = C;
	  	mostrarleds(valores,tiempo);
      }
      //para letra D
      else if(letra == 'D'){
        int D[]  = {248,252,198,195,195,198,252,248};
        valores = D;
	  	mostrarleds(valores,tiempo);
      }
      //para letra E
      else if(letra == 'E'){
        int E[]  = {255,255,224,255,255,224,255,255};
        valores = E;
	  	mostrarleds(valores,tiempo);
      }
      //para letra F
      else if(letra == 'F'){
        int F[]  = {126,126,96,124,124,96,96,96};
     	valores = F;
	  	mostrarleds(valores,tiempo);
      }
      //para letra G
      else if(letra == 'G'){
        int G[]  = {62,126,192,207,207,195,127,63};
     	valores = G;
	  	mostrarleds(valores,tiempo);
      }
      //para letra H
      else if(letra == 'H'){
        int H[]  = {195,195,195,255,255,195,195,195};
        valores = H;
	  	mostrarleds(valores,tiempo);
      }
      //para letra I
      else if(letra == 'I'){
        int I[] = {255,255,24,24,24,24,255,255};
      	valores = I;
	  	mostrarleds(valores,tiempo);
      }
      //para letra J
      else if(letra == 'J'){
        int J[]  = {255,24,24,24,152,216,120,48};
        valores = J;
	  	mostrarleds(valores,tiempo);
      }
      //para letra K
      else if(letra == 'K'){
        int K[]  = {198,204,216,240,216,204,198,195};
        valores = K;
	  	mostrarleds(valores,tiempo);
      }
      //para letra L
      else if(letra == 'L'){
        int L[]  = {48,48,48,48,48,48,62,62};
        valores = L;
	  	mostrarleds(valores,tiempo);
      }
      //para letra M
      else if(letra == 'M'){
        int M[]  = {195,231,255,219,195,195,195,195};
      	valores = M;
        mostrarleds(valores,tiempo);
      }
      //para letra N
      else if(letra == 'N'){
        int N[]  = {227,227,243,219,219,207,199,199};
        valores = N;
      	mostrarleds(valores,tiempo);
      }
      //para letra O
      else if(letra == 'O'){
        int O[]  = {255,255,195,195,195,195,255,255};
     	valores = O;
      	mostrarleds(valores,tiempo);
      }
      //para letra P
      else if(letra == 'P'){
        int P[]  = {255,227,227,227,255,254,224,224};
		valores = P;
      	mostrarleds(valores,tiempo);
      }
      //para letra Q
      else if(letra == 'Q'){
        int Q[]  = {0,60,66,66,66,70,62,1};     
      	valores = Q;
      	mostrarleds(valores,tiempo);
      }
      //para letra R
      else if(letra == 'R'){
        int R[]  = {255,255,195,223,206,204,198,195};
     	valores = R;     
      	mostrarleds(valores,tiempo);
      }
      //para letra S
      else if(letra == 'S'){
        int S[]  = {255,255,192,255,255,3,255,255};
        valores = S;
      	mostrarleds(valores,tiempo);
      }
      //para letra T
      else if(letra == 'T'){
        int T[]  = {255,255,255,60,60,60,60,60};
        valores = T;
      	mostrarleds(valores,tiempo);
      }
      //para letra U
      else if(letra == 'U'){
        int U[]  = {195,195,195,195,195,195,255,255};
        valores = U;
      	mostrarleds(valores,tiempo);
      }
      //para letra V
      else if(letra == 'V'){
        int V[]  = {129,195,195,102,102,60,60,24};
        valores = V;
      	mostrarleds(valores,tiempo);
      }
      //para letra W
      else if(letra == 'W'){
        int W[]  = {129,153,153,153,153,153,153,126};
        valores = W;
      	mostrarleds(valores,tiempo);
      }
      //para letra X
      else if(letra == 'X'){
        int X[]  = {129,195,102,60,60,102,195,129};
        valores = X;
        mostrarleds(valores,tiempo);
      }
      //para letra Y
      else if(letra == 'Y'){
      int Y[]  = {195,102,60,24,24,24,24,24};
      valores = Y;
      mostrarleds(valores,tiempo);
      }
      //para letra Z
      else if(letra == 'Z'){
       int Z[]  = {255,255,6,12,24,48,255,255};
        valores = Z;
      	mostrarleds(valores,tiempo);
      }
      //para numero 0
      else if(letra == '0'){
        int cero[]  = {60,126,102,102,102,102,126,60};
        valores = cero;
         mostrarleds(valores,tiempo);
      }
      
      //para numero 1
      else if(letra == '1'){
        int uno[]   = {24,56,88,24,24,24,24,24};
        valores = uno;
        mostrarleds(valores,tiempo);
      }
        
      
      //para numero 2
      else if(letra == '2'){
        int dos[]   = {60,126,102,12,24,48,126,126};
        valores = dos;
        mostrarleds(valores,tiempo);
      }
      
      //para numero 3
      else if(letra == '3'){
        int tres[]  = {60,126,102,14,14,102,126,60};
        valores = tres;
        mostrarleds(valores,tiempo);
      }
      
      //para numero 4
      else if(letra == '4'){
        int cuatro[]  = {14,30,54,102,255,255,6,6};
 		valores = cuatro;
        mostrarleds(valores,tiempo);
      }
      
      //para numero 5
      else if(letra == '5'){
        int cinco[] = {254,254,192,252,254,14,254,252};
        valores = cinco;
        mostrarleds(valores,tiempo);
      }
      
      //para numero 6
      else if(letra == '6'){
        int seis[]  = {30,62,112,252,254,198,254,124};
        valores = seis;
        mostrarleds(valores,tiempo);
      }
          
      
      //para numero 7
      else if(letra == '7'){
        int siete[] = {255,255,6,12,24,48,96,192};
        valores = siete;
        mostrarleds(valores,tiempo);
      
      }
      //para numero 8
      else if(letra == '8'){
        int ocho[]  = {60,66,66,60,66,66,60,0};
        valores = ocho;
        mostrarleds(valores,tiempo);
      
      }
      //para numero 9
      else if(letra == '9'){
        int nueve[] = {60,126,102,126,58,6,6,6};
        valores = nueve;
        mostrarleds(valores,tiempo);
      }
      
      //para emoji1
        else if(letra == '!'){
          int cara1[] = {0,36,36,0,66,66,60,0};
          valores = cara1;
          mostrarleds(valores,tiempo);
      
        }
        //para emoji2
      else if(letra == '"'){
        int cara2[] = {165,165,165,231,0,129,90,36};
        valores = cara2;
        mostrarleds(valores,tiempo);
      }
      
    //para emoji3
        else if(letra == '#'){
          int cara3[] = {102,102,0,126,66,66,126,0};
          valores = cara3;
          mostrarleds(valores,tiempo);
      
        }
  delete[] valores;
}
void desplazarbyte(uint8_t Pindato, uint8_t Pinreloj, uint8_t val){
  	uint8_t i = 0; 
    for (i = 0; i < 8; i++)  {
        digitalWrite(Pindato, !!(val & (1 << i)));   
        digitalWrite(Pinreloj, HIGH);
        digitalWrite(Pinreloj, LOW);            
      }
  }    

void mostrarleds(int *Lista,float tiempo){
  int contador = 0;
  while(true){
  	for (int i=0; i <= 8; i++) 
    {	desplazarbyte(SER,SRCLK,~(*(Lista+i)));//columnas
    	desplazarbyte(SER,SRCLK,128 >> i); //filas
        digitalWrite(RCLK, 1);
    	digitalWrite(RCLK, 0);    	
	}
	delay(15);
    contador = contador + 2;
    if(contador > tiempo/100){
    	break;
    }
      
  }
}
void publik(){
 char charpatron[]="";
 int Npatron;
 float Dpatron;
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
  	  Dpatron = Serial.parseFloat();
      delay(200);
      break;
    }
  }
  Dpatron = Dpatron*1000;
  Serial.println("Ingrese La secuencia de patrones: ");
  int largo = 0;
  while(true){
    if(Serial.available()){
      for(int i=0;i<=Npatron;i++){
        charpatron[i]=Serial.read();
        imagen(charpatron[i],Dpatron);
        delay(100);
        largo++;
        if(largo == Npatron){
        	break;
        }
      }
      break;
    }
  delay(200);
  }
 
  
}