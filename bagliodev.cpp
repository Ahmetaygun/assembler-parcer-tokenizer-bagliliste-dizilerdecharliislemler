#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 10

struct Bagli {
    int eleman;
    int sonraki;
};

int main() {
    struct Bagli dizi[MAX_ELEMENT];
    int i, son_indeks = -1;

    // Dizinin i�ini s�f�rlama
    for (i = 0; i < MAX_ELEMENT; i++) {
        dizi[i].eleman = 0;
        dizi[i].sonraki = -1;
    }

    // Klavyeden al�nan de�erleri diziye yerle�tirme
    while (1) {
        printf("Eleman girin (0 giriniz bitir): ");
        scanf("%d", &i);
        if (i == 0) {
            break;
        }

        // Rastgele bir indeks se�me
        int indeks = rand() % MAX_ELEMENT;
        printf(" =%d.index",indeks);
        if (dizi[indeks].eleman == 0) {
            // Bo� bir indeks bulduysak eleman� buraya ekleme
            dizi[indeks].eleman = i;
            dizi[indeks].sonraki = -1;
            if (son_indeks != -1) {
                dizi[son_indeks].sonraki = indeks;
            }
            son_indeks = indeks;
        } else {
            // Bo� bir indeks bulamad�ysak arama i�lemini tekrar etme
            continue;
        }
    }

    // Dizinin i�eri�ini ba�l� liste �eklinde ekrana yazd�rma
    printf("Dizi icerigi:\n");
    i = 0;
    while (i != -1) {
        printf("%d->", dizi[i].eleman);
        i = dizi[i].sonraki;
    }
    printf("\n");

    return 0;
}

