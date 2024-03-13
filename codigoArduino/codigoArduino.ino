#include <ros.h>
#include <std_msgs/String.h>
#include "src/domain/motor.h"

#define pwm1 9 // Motor Direito
#define ingA1 4 // Motor Direito
#define ingB1 3 // Motor Direito

#define pwm2 8 // Motor Esquerdo
#define ingA2 6 // Motor Esquerdo
#define ingB2 5 // Motor Esquerdo

Motor motorDireito(pwm1, ingA1, ingB1); 
Motor motorEsquerdo(pwm2, ingA2, ingB2);


void mensagemRecebida(const std_msgs::String& msg);

ros::NodeHandle nh;

ros::Subscriber <std_msgs::String> sub("/serial_arduino", &mensagemRecebida);


void setup() {
  Serial.begin(57600);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
}

void mensagemRecebida(const std_msgs::String & msg) {

  char comando = msg.data[0];
  //printf("%s", &comando);
  //Serial.println(comando);
  //for (int i = 0; i < comando; i++) {
  controlarMovimento(comando, 1200);
  delay(1000);
  //}
}

void controlarMovimento(char direcao, int tempo){
  switch (direcao) {
      case 'W':
        //SEGUIR EM FRENTE
        andarFrente(tempo); 
        break;
      case 'A':
        //ESQUERDA 90º
        virarEsquerda90(); 
        break;
      case 'S':
        //SEGUIR PARA TRAS
        andarTras(tempo); 
        break;
      case 'D':
        //DIREITA 90º
        virarDireita90(); 
        break;
      case 'P':
        //PARAR
        parar(); 
        break;
    }
}

void andarFrente(int tempo){
  motorDireito.setPwm(128);
  motorEsquerdo.setPwm(128);

  motorDireito.rodarHorario();
  motorEsquerdo.rodarAntiHorario();

  //delay(tempo);  
  //parar();
}

void andarTras(int tempo){
  motorDireito.setPwm(128);
  motorEsquerdo.setPwm(128);

  motorDireito.rodarAntiHorario();
  motorEsquerdo.rodarHorario();

  //delay(tempo);  
  //parar();
}

void virarEsquerda90(){
  motorDireito.setPwm(255);
  motorEsquerdo.setPwm(255);

  motorEsquerdo.rodarHorario();
  motorDireito.rodarHorario();
        
  //delay(1200);  
  //parar();
}

void virarDireita90(){
  motorDireito.setPwm(255);
  motorEsquerdo.setPwm(255);

  motorDireito.rodarAntiHorario();
  motorEsquerdo.rodarAntiHorario();
      
  //delay(1200);   
  //parar();
}

void parar(){
  motorDireito.parar();
  motorEsquerdo.parar();
}

