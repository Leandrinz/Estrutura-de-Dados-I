#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    int x;
    int y;
}Unidade;


int main(){
    int n;
    Unidade *v = (Unidade *) malloc(n * sizeof(Unidade));

    printf("Digite o valor de N: \n");
    scanf("%d", &n);
    int i,j;
    for (i = 0; i < n; i++){
        printf("Digite as coordenadas da unidade %d (x y): \n", i + 1);
        scanf("%d %d", &v->x, &v->y);
    }

    float raio;
    printf("Digite o raio da explosão: \n");
    scanf("%f", &raio);

    int cont = 0;

    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){

            float dx = v[j].x - v[i].x;
            float dy = v[j].y - v[i].y;

            float distancia = sqrt(dx * dx + dy * dy);

            if (distancia <= raio){
                cont++;
            }
        }
    }
    printf("\nTotal de duplas próximas: %d\n", cont);

    free(v);
    return 0;
}