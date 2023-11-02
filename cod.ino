#include <Servo.h> //Inclui a biblioteca do servo
Servo Servo1; //Nomeia um servo

int ledAzul = 4; //Diz que a porta 4 é a porta do led azul
int ledAmarelo = 3; //Diz que a porta 3 é a porta do led amarelo
int ledVerde = 2; //Diz que a porta 2 é a porta do led verde

int pos1 = 0; //Cria uma variável "pos1" do tipo inteiro e diz que o valor inicial dela é 0 

int tensaoPot = A1; //Diz que a tensaoPot é do tipo inteiro e está colocado na porta analogica A1

void setup()
{
  
  pinMode(ledAzul, OUTPUT); //DEFINE O PINO DO LED AZUL COMO UMA SAÍDA
  pinMode(ledAmarelo, OUTPUT); //DEFINE O PINO DO LED AMARELO COMO SAÍDA
  pinMode(ledVerde, OUTPUT); // DEFINE O PINO DO LED VERDE COMO UMA SAÍDA
  
  
  pinMode(ledAzul, HIGH); //Define que o pino do led azul terá uma tensão alta de 5V
  pinMode(ledAmarelo, HIGH); //Define que o pino do led amarelo terá uma tensão alta de 5V
  pinMode(ledVerde, HIGH); //Define que o pino do led verde terá uma tensão alta de 5V
  
  Servo1.attach(9); //Indica qual a porta que o "Servo1" vai usar, será a 9
  Servo1.write(pos1); //Diz para o "Servo1" escrever a "pos1", iniciada em 0
}	

void loop(){
  pos1 = map(analogRead(tensaoPot),0,1023,0,255); //Mapeia o potenciometro, vendo qual angulo será escrito e armazena na variável "pos1"
  Servo1.write(pos1); //Após o mapeamento e leitura ele diz para o "Servo1" escrever aquela posição
  
  if(pos1>0 and pos1<=60){ //Se a "pos1" for maior que 0 e menor ou igual a 60
    digitalWrite(ledAzul, HIGH); //Ela acende o led azul com alta iluminação
  }
  else{
    digitalWrite(ledAzul, LOW); //Se a condição não for realizada ela deixa o led azul desligado.
  }
  if(pos1>60 and pos1<=120){ //Se a "pos1" for maior do que 60 e menor ou igual que 120 
    digitalWrite(ledAmarelo, HIGH); //Ela acende o led amarelo com alta iluminação
  }
  else{
    digitalWrite(ledAmarelo, LOW); //Se a condição não for realizada ela deixa o led amarelo desligado
  }
  if(pos1>120 and pos1<=179) { //Se "pos1" for maior do que 120 e menor ou igual 179
    digitalWrite(ledVerde, HIGH); //Ela acende o led verde com alta iluminação
  }
  else{
    digitalWrite(ledVerde, LOW); //Se a condição não for realizada ela deixa o led verde desligado      
  }
  if(pos1 == 180){ //Se a "pos1" for igual 180
      delay(1000); //Delay de 1000 milissegundos
    digitalWrite(ledVerde, HIGH); //Acende o led verde com alta iluminação
    digitalWrite(ledAmarelo, HIGH); //Acende o led amarelo com alta iluminação
    digitalWrite(ledAzul, HIGH); //Acende o led azul com alta iluminação
    delay(100); //Delay de 100 milissegundos
    digitalWrite(ledVerde, LOW); //Desliga o led verde
    digitalWrite(ledAmarelo, LOW); //Desliga o led amarelo
    digitalWrite(ledAzul, LOW); //Desliga o led azul
  }
}