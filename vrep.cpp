#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

void botao_0(int clientID, int* jointHandlers);
void botao_1(int clientID, int* jointHandlers);
void botao_2(int clientID, int* jointHandlers);
void botao_3(int clientID, int* jointHandlers);
void botao_4(int clientID, int* jointHandlers);
void botao_5(int clientID, int* jointHandlers);
void botao_6(int clientID, int* jointHandlers);
void botao_7(int clientID, int* jointHandlers);
void botao_8(int clientID, int* jointHandlers);
void botao_9(int clientID, int* jointHandlers);
void confirma(int clientID, int* jointHandlers);
void padrao(int clientID, int* jointHandlers);

int main(int argc, char* argv[])
{
    //variavei para handler das juntas
    int handler = 0;
    //conecta com o coppelia
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);
    // Declara Arquivo
    FILE* arquivo;

    extApi_sleepMs(500);

    //verifica conexao com simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }

    // Configura o handler para cada junta do robô usando um vetor
    int jointHandlers[6];
    for (int i = 0; i < 6; i++) {
        char handlerName[100];
        sprintf(handlerName, "/base_link_respondable[0]/joint_%d", i + 1);
        simxGetObjectHandle(clientID, handlerName, &jointHandlers[i], simx_opmode_oneshot_wait);
    }

    // Abre arquivo com os números dos candidatos
    arquivo = fopen("arquivo.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    }
    char linha[100];
    //Pega cada linha do arquivo
    while (fgets(linha, 100, arquivo) != NULL)
    {
        for (int i = 0; i < strlen(linha); i++)
        {
            if (linha[i] == '0')
            {
                botao_0(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '1')
            {
                botao_1(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '2')
            {
                botao_2(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '3')
            {
                botao_3(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '4')
            {
                botao_4(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '5')
            {
                botao_5(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '6')
            {
                botao_6(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '7')
            {
                botao_7(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '8')
            {
                botao_8(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
            else if (linha[i] == '9')
            {
                botao_9(clientID, jointHandlers);
                padrao(clientID, jointHandlers);
            }
        }
        confirma(clientID, jointHandlers);
        padrao(clientID, jointHandlers);
    }
    //Fecha o arquivo
    fclose(arquivo);
    // Fecha a conexao 
    simxFinish(clientID);
    return(0);
}

void botao_0(int clientID, int* jointHandlers) {
    double jointPositions[6] = {(simxFloat) - PI / 11.5,(simxFloat) - PI / 4,(simxFloat) - PI / 30 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
    simxSetJointTargetPosition(clientID, jointHandlers[1], (simxFloat) - PI / 3.78, simx_opmode_oneshot_wait);
    extApi_sleepMs(500);
}

void botao_1(int clientID, int* jointHandlers) {
    double jointPositions[6] = { (simxFloat) - PI / 17, (simxFloat) - PI / 3.86,(simxFloat) PI / 54 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
}

void botao_2(int clientID, int* jointHandlers) {
    double jointPositions[6] = {(simxFloat) -PI / 12,(simxFloat) - PI / 3.68,(simxFloat)PI / 23 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
}

void botao_3(int clientID, int* jointHandlers) {
    double jointPositions[6] = {(simxFloat) - PI / 9.8,(simxFloat) - PI / 3.53,(simxFloat)PI / 17 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
}

void botao_4(int clientID, int* jointHandlers) {
    double jointPositions[6] = { (simxFloat) - PI / 17,(simxFloat) - PI / 3.9, (simxFloat) 0 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
}

void botao_5(int clientID, int* jointHandlers) {
    double jointPositions[6] = { (simxFloat) - PI / 12,(simxFloat) - PI / 3.87,(simxFloat)PI / 60 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
    simxSetJointTargetPosition(clientID, jointHandlers[1], (simxFloat)-PI / 3.73, simx_opmode_oneshot_wait);
    extApi_sleepMs(500);
}

void botao_6(int clientID, int* jointHandlers) {
    double jointPositions[6] = { (simxFloat) - PI / 9,(simxFloat) - PI / 3.57,(simxFloat) PI / 35 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(8000);
}

void botao_7(int clientID, int* jointHandlers) {
    double jointPositions[6] = { (simxFloat) - PI / 17,(simxFloat) - PI / 4,(simxFloat) - PI / 60 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(1500);
    }
    extApi_sleepMs(5000);
    simxSetJointTargetPosition(clientID, jointHandlers[1],(simxFloat) - PI / 3.80, simx_opmode_oneshot_wait);
    extApi_sleepMs(500);
}

void botao_8(int clientID, int* jointHandlers) {
    double jointPositions[6] = { (simxFloat) - PI / 12,(simxFloat) - PI / 4,(simxFloat) - PI / 100 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
    simxSetJointTargetPosition(clientID, jointHandlers[1], (simxFloat) - PI / 3.77, simx_opmode_oneshot_wait);
    extApi_sleepMs(500);
}

void botao_9(int clientID, int* jointHandlers) {
    double jointPositions[6] = { (simxFloat) - PI / 9, (simxFloat) - PI / 3.7, (simxFloat) PI / 60 }; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
    simxSetJointTargetPosition(clientID, jointHandlers[1], (simxFloat) - PI / 3.6, simx_opmode_oneshot_wait);
    extApi_sleepMs(500);
}

void confirma(int clientID, int* jointHandlers) {
    double jointPositions[6] = {(simxFloat) - PI / 8.2,(simxFloat) -PI / 3.87,(simxFloat) - PI / 35}; // coordenadas das juntas para a posição desejada
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(7000);
    simxSetJointTargetPosition(clientID, jointHandlers[1], (simxFloat) - PI / 3.55, simx_opmode_oneshot_wait);
    extApi_sleepMs(500);
}

void padrao(int clientID, int* jointHandlers) {
    double jointPositions[6] = { (simxFloat) 0, (simxFloat) 0, (simxFloat) 0 }; // coordenadas das juntas para a posição desejada
    simxSetJointTargetPosition(clientID, jointHandlers[1], (simxFloat)0, simx_opmode_oneshot_wait);
    extApi_sleepMs(500);
    for (int i = 0; i < 3; i++) {
        simxSetJointTargetPosition(clientID, jointHandlers[i], jointPositions[i], simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(5000);
}