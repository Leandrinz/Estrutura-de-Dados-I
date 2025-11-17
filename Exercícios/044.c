#include <stdio.h>

typedef struct 
{
    int id;
    int pontos;
}conquista;


int main(){
    FILE *file = fopen("../player_log.txt", "r+");
    
    if (file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    int n;
    
    fscanf(file, "%d", &n);
    
    int i;

    conquista c;
    
    for (i = 0; i < n; i++){
        fscanf(file, "%d %d", &c.id, &c.pontos);
        printf("%d %d\n", c.id, c.pontos);
    }
    
    fseek(file, 0, SEEK_CUR);

    fprintf(file, "\n--- SESSION CONCLUDED ---");
    
    fclose(file);
    
    return 0;
}