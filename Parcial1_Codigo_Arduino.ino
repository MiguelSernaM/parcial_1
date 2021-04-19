#define SER 2
#define SRCLK 3
#define RCLK 4
//Funcion para prender todos los leds
void verificacion();
//Funcion para mostrar el caracter en los leds
void imagen();
//Funcion para leer 8 bites de cada fila y mirar si estan disponibles
void desplazarbyte(uint8_t Pindato, uint8_t Pinreloj, uint8_t val);
short int opcion;
char carat, letra;
int asciiletra;
char abc[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
int ALL[] = {255,255,255,255,255,255,255,255};
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
int uno[]  = {3,7,11,3,3,3,3,3};
int dos[]  = {62,66,68,8,16,32,64,255};
int tres[]  = {60,66,2,30,2,66,60,0};
int cuatro[]  = {6,00010010,00100010,01000010,255,01000010,00000010,00000010,};
int cinco[]  = {255,10100100,10100100,255,00000011,00000011,255,00000000};
int seis[]  = {00001000,00010010,00100010,01111100,01000010,01000010,00111100,00000000};
int siete[]  = {255,00000011,00000110,00001100,00011000,00110000,01100000,11000000};
int ocho[]  = {00111100,01000010,01000010,00111100,01000010,01000010,00111100,00000000};
int nueve[]  = {255,11000011,11000011,255,00000011,00000011,00000011,00000011};
int cero[]  = {255,10000001,10000001,10000001,10000001,10000001,10000001,255};
int cara1[] = {0,00100100,00100100,00000000,01000010,01000010,00111100,0};
int cara2[] = {165,165,165,11100111,00000000,10000001,01011010,00100100};
int cara3[] = {102,102,0,01111110,01000010,01000010,01111110,00000000};


void setup(){
  //inicializamos el puerto serial
  Serial.begin(9600);
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
    do{
      opcion = Serial.read();
      delay(200);
      opcion = opcion-48;
      //Opcion de verificacion
      if(opcion == 1){
      	verificacion();
        opcion = 0;
      }
      //Opcion de mostrar patron
      else if(opcion == 2){
        Serial.println("Letra para imprimir: ");
        letra = Serial.read();
        delay(500);
        asciiletra=letra;
        if(asciiletra>64 && asciiletra<91 || asciiletra>96 && asciiletra <123)
          
        for(int i=0;i<26;i++){
          if(letra==abc[i]){
          	for (int i=0; i<8; i++) {
            	//carat=abc[i];
            	desplazarbyte(SER,SRCLK,~A[i]);
                desplazarbyte(SER,SRCLK,128 >> i);  
              
          	}
        }
      
      }
      }
      //Mostrar secuencia de patrones
      else if(opcion == 3){
        
      }
    }while(opcion <1 && opcion >3);
  }
}  
void verificacion(){
  for (int i=0; i<=8; i++) {

    desplazarbyte(SER,SRCLK,~ALL[i]);
    desplazarbyte(SER,SRCLK,128 >> i); 

  digitalWrite(RCLK, 1);
  digitalWrite(RCLK, 0);
  }
}
/*void imagen(){
  Serial.println("Por favor, ingrese la letra que sea ver en pantalla: ");
  Serial.read(letra);
    for (int i=0; i<8; i++){
   	1     >> i&(1<<i); 
          digitalWrite(SHIFT,1);
     
}digitalWrite(SHIFT,0);
	}
  digitalWrite(RCLK, 1);
  digitalWrite(RCLK, 0);

*/ 
void desplazarbyte(uint8_t Pindato, uint8_t Pinreloj, uint8_t val){
  	uint8_t i; 
    for (i = 0; i < 8; i++)  {
        digitalWrite(Pindato, !!(val & (1 << i)));   
            digitalWrite(Pinreloj, HIGH);
            digitalWrite(Pinreloj, LOW);            
      }
  }    
