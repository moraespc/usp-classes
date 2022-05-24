/*
    PAULO CESAR DE MORAES FILHO
    10730304
    Versao 1.0: Processa apenas Automatos Finitos DETERMINISTICOS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int estado1;
    char simbolo;
    int estado2;
}TRANSICAO;

typedef struct{
    int tamanho;
    char simbolos[10];
}ALFABETO;

typedef struct{
    int tamanhoOcupado;
    char cadeia[20];
}CADEIA;

typedef struct{
    int estados;
    int estadosIniciais;
    int estadosAceitacao;
    int listaEstadosIniciais[10];
    int listaEstadosAceitacao[10];
    int transicoes;
    ALFABETO sigma;
    TRANSICAO delta[50];
}AUTOMATO;

//ESCOPO DE FUNCOES
int verificaAFD(AUTOMATO);
void processaAFD(CADEIA, AUTOMATO);


int main(){
    int i, cadeiasEntrada, estado, afd;
    CADEIA cadeias[10];
    AUTOMATO m1;

    //PREENCHENDO O AUTOMATO GENERICAMENTE
    m1.estados = 0;
    m1.sigma.tamanho = 0;

    for(i=0; i<10; i++){
        m1.listaEstadosIniciais[i] = 0;
        m1.listaEstadosAceitacao[i] = 0;
        m1.sigma.simbolos[i] = '@';
    }

    //LEITURA DOS DADOS DO AUTOMATO
    scanf("%d", &m1.estados);
    scanf("%d", &m1.sigma.tamanho);

    for(i=0; i< m1.sigma.tamanho; i++){
        scanf("%*c");
        scanf("%c", &m1.sigma.simbolos[i]);
    }

    scanf("%d", &m1.estadosIniciais);

    if(m1.estadosIniciais == 1){
        m1.listaEstadosIniciais[0] = 1;
    }
    else{
        for(i=0; i<m1.estadosIniciais; i++){
            scanf("%*c");
            scanf("%d", &estado);
            m1.listaEstadosIniciais[estado] = 1;
        }
    }

    scanf("%d", &m1.estadosAceitacao);

    for(i=0; i<m1.estadosAceitacao; i++){
        scanf("%*c");
        scanf("%d", &estado);
        m1.listaEstadosAceitacao[estado] = 1;
    }

    scanf("%d", &m1.transicoes);

    for(i=0; i<m1.transicoes; i++){
        scanf("%d %c %d", &m1.delta[i].estado1, &m1.delta[i].simbolo, &m1.delta[i].estado2);
    }

    scanf("%d", &cadeiasEntrada);

    for(i=0; i<cadeiasEntrada; i++){
        scanf("%s", cadeias[i].cadeia);
        cadeias[i].tamanhoOcupado = strlen(cadeias[i].cadeia);
    }

    afd = verificaAFD(m1);

    if(afd){
        for(i=0; i<cadeiasEntrada; i++){
            processaAFD(cadeias[i], m1);
        }
    }

    return 0;
}

int verificaAFD(AUTOMATO m){
    int i, j;

    if(m.estadosIniciais == 1){
        for(i=0; i<m.transicoes; i++){
            for(j=i+1; j<m.transicoes; j++){
                if(m.delta[i].estado1 == m.delta[j].estado1 && m.delta[i].simbolo == m.delta[j].simbolo){
                    return 0;
                }
            }
        }
    }
    else{return 0;}

   return 1;
}

void processaAFD(CADEIA cad, AUTOMATO m){
    int i, j, simbolosCadeia, estadoAtual, temTransicao, resultado;
    char lambda;

    i = 0;
    j = 0;
    resultado = 1;
    temTransicao = 0;
    simbolosCadeia = cad.tamanhoOcupado;
    lambda = '-';

    //SE M POSSUIR MAIS DE UM ESTADO, PROCURA O INICIAL
    if(m.estados > 1){
        while(m.listaEstadosIniciais[i] != 1){
            i++;
        }
    }

    //POSICIONA O AUTOMATO NO ESTADO INICIAL
    estadoAtual = i;

    //VERIFICA SE A CADEIA LAMBDA PASSA
    if(m.listaEstadosAceitacao[i] == 1 && cad.cadeia[0] == lambda){
        resultado = 1;
    }
    else{
        while(simbolosCadeia > 0){
            for(i=0; i<m.transicoes; i++){
                if(estadoAtual == m.delta[i].estado1 && cad.cadeia[j] == m.delta[i].simbolo){
                    temTransicao = 1;
                    estadoAtual = m.delta[i].estado2;
                    break;
                }
            }
            if(temTransicao == 0){
                resultado = 0;
                break;
            }
            simbolosCadeia--;
            j++;
        }

        if(m.listaEstadosAceitacao[estadoAtual] != 1){resultado = 0;}
    }

    if(resultado == 1){printf("aceita\n");}
    else{printf("rejeita\n");}
}
