#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[101];
    char kategori[101];
    int tahun;
    int nilai;
}Artefak;

int main(){
    int N;
    scanf("%d", &N);

    Artefak a[N];
    for (int i = 0; i < N; i++){
        scanf("%s %s %d %d",
            a[i].nama,
            a[i].kategori,
            &a[i].tahun,
            &a[i].nilai);

    }
    for (int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - i - 1; j++){
            int swap = 0;
            if (strcmp(a[j].kategori, a[j+1].kategori) > 0 ){
                swap = 1;
            }
            else if(strcmp(a[j].kategori, a[j+1].kategori)== 0){
                if (a[j].tahun > a[j + 1].tahun){
                    swap = 1;
                }
                else if(a[j].tahun == a[j+1].tahun){
                    if (a[j].nilai < a[j + 1].nilai){
                        swap = 1;
                    }
                    else if(a[j].nilai == a[j + 1].nilai){
                        if (strcmp(a[j].nama, a[j + 1].nama)==0){
                            swap = 1;
                        }
                        else if(strcmp(a[j].nama, a[j + 1].nama)>0){
                            swap = 1;
                        }
                    }
                }
            }
            if(swap){
                Artefak temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

            }
        }
    }
    for(int i = 0; i < N; i++){
        printf("%s %s %d %d\n",
        a[i].nama,
        a[i].kategori,
        a[i].tahun,
        a[i].nilai);
    }
    return 0;
}

