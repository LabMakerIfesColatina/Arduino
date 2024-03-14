#ifndef GERENCIA_H
#define GERENCIA_H

#include "../domain/motor.h"


class Gerencia{
    private:
        Motor motorDireito;
        Motor motorEsquerdo;
        
        void andarFrente(){
            this->motorDireito.setPwm(128);
            this->motorEsquerdo.setPwm(128);

            this->motorDireito.rodarHorario();
            this->motorEsquerdo.rodarAntiHorario();
        }

        void andarTras(){
            this->motorDireito.setPwm(128);
            this->motorEsquerdo.setPwm(128);

            this->motorDireito.rodarAntiHorario();
            this->motorEsquerdo.rodarHorario();

        }

        void virarEsquerda(){
            this->motorDireito.setPwm(200);
            this->motorEsquerdo.setPwm(200);

            this->motorEsquerdo.rodarHorario();
            this->motorDireito.rodarHorario();
        }

        void virarDireita(){
            this->motorDireito.setPwm(200);
            this->motorEsquerdo.setPwm(200);

            this->motorDireito.rodarAntiHorario();
            this->motorEsquerdo.rodarAntiHorario();

        }

        void parar(){
            this->motorDireito.parar();
            this->motorEsquerdo.parar();
        }

    public:
        Gerencia(Motor mD, Motor mE) : motorDireito(mD), motorEsquerdo(mE) {
            //this->motorDireito.setPwm(120);
            //this->motorEsquerdo.setPwm(120);
        }

        void movimentacao(char direcao, int constMovimentacao){
            if(constMovimentacao==-1){ //MOVEMENTACAO POR CLICK
                switch (direcao) {
                    case 'W':
                        //SEGUIR EM FRENTE
                        this->andarFrente(); 
                        break;
                    case 'A':
                        //ESQUERDA 
                        this->virarEsquerda(); 
                        break;
                    case 'S':
                        //SEGUIR PARA TRAS
                        this->andarTras(); 
                        break;
                    case 'D':
                        //DIREITA 
                        this->virarDireita(); 
                        break;
                    default:
                        //PARAR
                        this->parar(); 
                        break;
                }
        }else{ //MOVIMENTACAO CONSTANTE
            switch (direcao) {
                case 'W':
                    //SEGUIR EM FRENTE
                    this->andarFrente(); 
                    break;
                case 'A':
                    //ESQUERDA 
                    this->virarEsquerda(); 
                    break;
                case 'S':
                    //SEGUIR PARA TRAS
                    this->andarTras(); 
                    break;
                case 'D':
                    //DIREITA 
                    this->virarDireita(); 
                    break;
                case 'P':
                    //PARAR
                    this->parar(); 
                    break;
            }
        }
    }
};

#endif
