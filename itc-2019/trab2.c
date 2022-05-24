/*
    PAULO CESAR DE MORAES FILHO
    10730304
    Versao 1.1: Simulador para Maquina de Turing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITO_FALSO 100
#define START_CABECA 50

typedef struct{
    char simbolo[20];
    int tamanho;
}ALFABETO;

typedef struct{
    char fitaInfinita[INFINITO_FALSO];
    int posCabeca;
}FITA;

typedef struct{
    int estadoAtual;
    char simboloLido;
    char simboloEscrito;
    char moveFita;
    int proximoEstado;
}TRANSICAO;

typedef struct{
    char caracteres[20];
    int tamanhoOcupado;
}CADEIA;

typedef struct{
    ALFABETO sigma;
    ALFABETO sigmaLinha;
    ALFABETO sigmaTotal;
    FITA fita;
    int numeroEstados;
    int numeroTransicoes;
    int estadoInicial;
    int estadoAceitacao;
    TRANSICAO delta[50];
}MAQUINA_TURING;

//PROTOTIPO DE FUNCOES
void processaTuring(MAQUINA_TURING);

int main(){
    int i, j, k, cadeiasEntrada;
    CADEIA lista_w[10];
    MAQUINA_TURING mt;

    // 1) INICIALIZANDO A MAQUINA DE TURING
    // 1.1) PREENCHIMENTO DA FITA SUPOSTAMENTE INFINITA
        //PREENCHE A FITA COM BRANCO

    for(i=0; i<INFINITO_FALSO; i++){
        mt.fita.fitaInfinita[i] = 'B';
    }

    mt.fita.posCabeca = START_CABECA; //TENTATIVA DE SIMULAR UMA FITA INFINITA (ESPACOS EM BRANCO PARA A ESQUERDA E DIREITA)

    // 1.2) LENDO A PARTIR DO ARQUIVO DE ENTRADA
    // 1.2.1) NUMERO DE ESTADOS
    scanf("%d", &mt.numeroEstados);

    // 1.2.2) ALFABETO SIGMA
    scanf("%d", &mt.sigma.tamanho);

    for(i=0; i<mt.sigma.tamanho; i++){
        scanf("%*c");
        scanf ("%c", &mt.sigma.simbolo[i]);
        mt.sigmaTotal.simbolo[i] = mt.sigma.simbolo[i];
    }

    // 1.2.3) ALFABETO SIGMA ESTENDIDO (LINHA)
    scanf("%d", &mt.sigmaLinha.tamanho);
    mt.sigmaTotal.tamanho = mt.sigma.tamanho + mt.sigmaLinha.tamanho;

    for(i=0; i<mt.sigmaLinha.tamanho; i++){
        scanf("%*c");
        scanf ("%c", &mt.sigmaLinha.simbolo[i]);
        mt.sigmaTotal.simbolo[i+mt.sigma.tamanho] = mt.sigmaLinha.simbolo[i];
    }

    // 1.2.4) ESTADO DE ACEITACAO
    scanf("%d", &mt.estadoAceitacao);

    // 1.2.5) NUMERO DE TRANSICOES
    scanf("%d", &mt.numeroTransicoes);

    // 1.2.6) LEITURA DO DELTA (TRANSICOES)
    for(i=0; i<mt.numeroTransicoes; i++){
        scanf("%d %c %d %c %c", &mt.delta[i].estadoAtual, &mt.delta[i].simboloLido, &mt.delta[i].proximoEstado, &mt.delta[i].simboloEscrito, &mt.delta[i].moveFita);
    }

    // 1.2.7) NUMERO DE CADEIAS A SEREM TESTADAS
    scanf("%d", &cadeiasEntrada);

    // 1.2.8) LEITURA DAS CADEIAS DE ENTRADA
    for(i=0; i<cadeiasEntrada; i++){
        scanf("%s", lista_w[i].caracteres);
        lista_w[i].tamanhoOcupado = strlen(lista_w[i].caracteres);
    }

    // 2) PROCESSAMENTO DAS CADEIAS DE ENTRADA
    for(i=0; i<cadeiasEntrada; i++){

        //ESCREVE A CADEIA A SER PROCESSADA NA FITA
            //FAZ A LIMPEZA DA FITA
        for(k=0; k<INFINITO_FALSO; k++){
            mt.fita.fitaInfinita[k] = 'B';
        }

        for(j=0; j<lista_w[i].tamanhoOcupado; j++){
            mt.fita.fitaInfinita[mt.fita.posCabeca] = lista_w[i].caracteres[j];
            mt.fita.posCabeca++;
        }

        //REPOSICIONA A CABECA NO INICIO DA CADEIA
        mt.fita.posCabeca = START_CABECA;

        //INICIA O PROCESSAMENTO
        processaTuring(mt);
    }

    return 0;
}

void processaTuring(MAQUINA_TURING m){
    int i, estadoAtual, temTransicao, resultado, processando;
    char lambda;

    i = 0;

    resultado = 1;
    lambda = '-';
    processando = 1;

    //POSICIONA A MAQUINA NO ESTADO INICIAL
    estadoAtual = 0;

    //VERIFICA SE A CADEIA LAMBDA PASSA
    if(m.estadoAceitacao == 0 && m.fita.fitaInfinita[m.fita.posCabeca] == lambda){
        resultado = 1;
    }
    else{
        while(processando){
            temTransicao = 0;

            for(i=0; i<m.numeroTransicoes; i++){
                if(estadoAtual == m.delta[i].estadoAtual && m.fita.fitaInfinita[m.fita.posCabeca] == m.delta[i].simboloLido){
                    temTransicao = 1;
                    estadoAtual = m.delta[i].proximoEstado;
                    m.fita.fitaInfinita[m.fita.posCabeca] = m.delta[i].simboloEscrito;

                    if(m.delta[i].moveFita == 'R'){
                        m.fita.posCabeca+= 1;
                    }
                    else{
                        if(m.delta[i].moveFita == 'L'){
                            m.fita.posCabeca += -1;
                        }
                    }
                    break;
                }
            }

            if(temTransicao == 0){
                processando = 0;
            }
        }
        if(estadoAtual != m.estadoAceitacao){resultado = 0;}
    }

    if(resultado == 1){printf("aceita\n");}
    else{printf("rejeita\n");}
}
