#include <stdio.h>

int main() {

    int m1[6][6]={4,3,2,1,1,1,5,3,3,2,1,5,4,3,2,1,0,4,4,3,3,0,1,3,3,3,3,2,3,2,4,6,7,5,7,7};
    int m2[6][6]={3,2,2,1,0,0,5,3,4,1,2,5,4,2,2,2,0,4,5,2,3,0,1,3,3,3,3,2,3,2,4,7,7,5,7,7};
    int i, j;
    int *pm1 = &m1[0][0], *pm2 = &m2[0][0];
    int mo[8][8];

    for(i = 0; i < 3; i++) {
        for(j=0; j < 3; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i = 0; i < 3; i++) {
        for(j=0; j < 3; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 8; i++) {
        for(j=0; j < 8; j++) {
            mo[i][j] = 0;
        }
    }

    for(i=0; i < 36; i++) {
        mo[*(pm1+i)][*(pm2+i)] ++; 
    }

    printf("\n");

     for(i = 0; i < 8; i++) {
        for(j=0; j < 8; j++) {
            printf("%d ", mo[i][j]);
        }
        
        printf("\n");
 
    }

    return 0;
}