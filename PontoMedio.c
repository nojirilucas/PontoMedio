#include <stdlib.h>
#include <stdio.h>

double funcao(double valor){
    return (valor * valor * valor) - (9 * valor) + 3;
}

int main(){

    double limiteInferior = 0, limiteSuperior = 1;
    double tolerancia = 1e-3;

    double funcaoInicio, pontoMedio;
    long long numeroInteracoes = 0;

    while (limiteSuperior - limiteInferior >= tolerancia) {
        printf("[%lf, %lf]\n", limiteInferior, limiteSuperior);
        funcaoInicio = funcao(limiteInferior);
        pontoMedio = (limiteInferior + limiteSuperior) / 2;
        printf("pontoMedio = %lf\n", pontoMedio);
        printf("funcao(limiteInferior) = %lf\n", funcaoInicio);
        printf("funcao(limiteSuperior) = %lf\n", funcao(limiteSuperior));
        printf("funcao(pontoMedio) = %lf\n", funcao(pontoMedio));

        if (funcaoInicio * funcao(pontoMedio) > 0)
            limiteInferior = pontoMedio;
        else
            limiteSuperior = pontoMedio;
    
        numeroInteracoes++;
    }
    printf("[%lf, %lf]\n", limiteInferior, limiteSuperior);
    printf("Numero de interacoes foram: %lld\n", numeroInteracoes);
    return 0;
}
