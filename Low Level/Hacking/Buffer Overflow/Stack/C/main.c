#include <stdio.h>
#include <string.h>

typedef struct count_data {
    char key[8];
    int level;
} count_data;

int main(void){
    count_data data;
    data.level = 0;

    printf("%i\n", data.level);
    scanf("%s", data.key);
    printf("%s\n", data.key);
    printf("%i\n", data.level);

    if(!data.level){
        printf("bloqueado!\n");
    }
    else{
        printf("liberado patrão\n");
    }
    return 0;
}
