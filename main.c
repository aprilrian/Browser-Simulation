/***********************************/
/* Program   : main.c */
/* Deskripsi : file DRIVER modul List Circular */
/* NIM/Nama  : 2406012112002/Aprilyanto Setiyawan Siburian
               24060121140094/Muhammad Akmal Iskandar
*/
/* Tanggal   : 30 November 2022 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include "list_double_pointer.h"
#include "browser.h"

int main() {
    // kamus utama
    List A;
    address M, N, X;
    boolean on;
    char *web, web_prec;
    char pred;
    int i;
    size_t malloc_size;

    // algoritma
    on = true;
    i = 0;
    malloc_size = 100;

    CreateList(&A);

    while (on){
        system("cls"); // Clear Screen
        MenuPage();
        PrintInfo(A);
        printf("\nMasukkan perintah: ");
        scanf(" %c", &pred);
        switch (pred){
            case '1':
                web = malloc(malloc_size*sizeof(char));
                printf("Masukkan nama situs: ");
                scanf("%s", web);
                M = Alokasi(web);
                InsertFirst(&A, M);
                break;
            case '2':
                web = malloc(malloc_size*sizeof(char));
                printf("Masukkan nama situs: ");
                scanf("%s", web);
                M = Alokasi(web);
                InsertLast(&A, M);
                break;
            //case '3':
                web = malloc(malloc_size*sizeof(char));
                printf("Masukkan nama situs: ");
                scanf("%s", web);
                M = Alokasi(web);
                printf("Masukkan nama situs yang ingin ditambahkan setelahnya : ");
                scanf("%s", web_prec);
                if(Search(A, web_prec) != Nil){
                    InsertAfter(&A, M, Search(A, web_prec));
                    break;
                } else{
                    printf("Halaman tidak ditemukan");
                    break;
                }
            case '4':
                DelFirst(&A);
                break;
            case '5':
                DelLast(&A);
                break;
            case '6':
                if (NbElmt(A) > 1) {
                    DelAfter(&A);
                } else {
                    printf("Hanya dapat digunakan jika terdapat dua tab atau lebih");
                    sleep(2);
                }
                break;
            case '7':
                NextPage(&A);
                break;
            case '8':
                PrevPage(&A);
                break;
            case '9':
                on = false;
                printf("\nTerima kasih sudah mencoba simulasi browser ini");
                break;
            default:
                printf("Perintah tidak dikenali\n");
                sleep(2);
                break;
        }
    }

    printf("\n");
    return 0;
}
