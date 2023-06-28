//Ultrasons

//Frente Esquerda
#define TRIG1 3
#define ECHO1 2
//Frente Direita
#define TRIG2 4
#define ECHO2 5

//Modulo Rele
#define IN1 11
#define IN2 12
#define IN3 10
#define IN4 9

//Chaves

//Chave Lado
#define CHAVEL A4
//Push Button
#define PUSHB A3

//Constantes

//Distancia maxima para ultrassom ler - cm
#define distMaxima 90

//Leituras

//Ultrasons
float dist1, dist2;
//Tcrts
int s1, s2, s3;

//Flags

//Flag inicio
int flag = 0;

void setup() {
  //Ultrasons
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);
  //Modulo Rele
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //Chaves
  pinMode(CHAVEL, INPUT_PULLUP);
  pinMode(PUSHB, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  controle();
}
