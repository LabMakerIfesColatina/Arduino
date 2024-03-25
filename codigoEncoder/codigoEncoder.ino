//ky-040 ENCODER!!!

//#include <Arduino.h>
#include "src/domain/Encoder.h"

// Definindo os pinos do KY-040
#define pinDT 10
#define pinCLK 9
#define pinSW 8

// Variáveis para armazenar as leituras
int count=0;
volatile int leituraAtualDT;
volatile int leituraAnteriorDT;
boolean bool_CW;
Encoder motD(10,9);

void setup() {
    Serial.begin(9600);
    Serial.println("Iniciando Leitura...");

    pinMode(pinDT, INPUT);
    pinMode(pinCLK, INPUT);
    pinMode(pinSW, INPUT_PULLUP);

    leituraAnteriorDT = digitalRead(pinDT);
}

void loop(){

    leituraAtualDT = digitalRead(pinDT);
    if (leituraAtualDT != leituraAnteriorDT) { // check if knob is rotating
        // Sentido Horario
        if (digitalRead(pinCLK) == leituraAtualDT) {
            count ++;
            bool_CW = true;
        // Sentido anti horario
        } else {
            // if pin B state changed before pin A, rotation is counter-clockwise
            bool_CW = false;
            count--;
}
        if (bool_CW) {
            Serial.print("Sentido Horario | ");
        } else {
            Serial.print("Sentido Anti-Horario | ");
        }
        Serial.print(count);
        Serial.println(" | ");
        Serial.println(motD.read());
        Serial.println(motD.readAndReset());
    }

leituraAnteriorDT = leituraAtualDT;
}