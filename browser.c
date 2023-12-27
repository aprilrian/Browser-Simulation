#ifndef browser_C
#define browser_C
/***********************************/
/* Program   : browser.c */
/* Deskripsi : Realisasi untuk browser */
/* NIM/Nama  : 2406012112002/Aprilyanto Setiyawan Siburian
               24060121140094/Muhammad Akmal Iskandar
*/
/* Tanggal   : 30 November 2022 */
/***********************************/
#include "browser.h"
#include <stdio.h>


void SetOn (address *P) {
/* I.S. : P terdefinisi
   F.S. : situs address P disetel menjadi aktif*/
    // kamus lokal

    // algoritma
        isOn(*P) = true;
}

void SetOff (address *P) {
/* I.S. : List tidak kosong
   F.S. : situs address P disetel menjadi nonaktif*/
    // kamus lokal

    // algoritma
        isOn(*P) = false;
}

void SetOffAll (List *L) {
/* I.S. : List tidak kosong
   F.S. : semua situs disetel menjadi nonaktif*/
    // kamus lokal
        address P;

    // algoritma
        if (!ListEmpty(*L)) {
            P = First(*L);
            do {
                SetOff(&P);
                P = next(P);
            } while (P != Nil);
        }
}

void NextPage (List *L) {
/* I.S. : List tidak kosong
   F.S. : berpindah ke halaman selanjutnya*/
    // kamus lokal
        address P;

    // algoritma
        if (!ListEmpty(*L)) {
            P = First(*L);
            while (!isOn(P)) {
                P = next(P);
            }

            if (next(P) != Nil) {
                isOn(next(P)) = true;
                isOn(P) = false;
            }
        }
}

void PrevPage (List *L) {
/* I.S. : List tidak kosong
   F.S. : berpindah ke halaman sebelumnya*/
    // kamus lokal
        address P;

    // algoritma
        if (!ListEmpty(*L)) {
            P = First(*L);
            while (!isOn(P)) {
                P = next(P);
            }

            if (prev(P) != Nil) {
                isOn(prev(P)) = true;
                isOn(P) = false;
            }
        }
}

void MenuPage() {
/* I.S. : Tidak terdefinisi
   F.S. : Tampilan menu opsi yang bisa dilakukan dalam program*/

    printf("============= SIMULASI BROWSER =============\n\n");
    printf("Oleh : Aprilyanto Setiyawan Siburian (2406012112002)\n");
    printf("       Muhammad Akmal Iskandar       (24060121140094)\n");

    printf("\nSilakan gunakan perintah yang tersedia di bawah: \n");
    printf("1 : Memasukkan halaman di paling kiri\n");
    printf("2 : Memasukkan halaman di paling kanan\n");
    //printf("3 : Memasukkan halaman setelah halaman tertentu\n");
    printf("4 : Hapus halaman terkiri\n");
    printf("5 : Hapus halaman terkanan\n");
    printf("6 : Hapus halaman setelah halaman aktif\n");
    printf("7 : Pindah ke halaman selanjutnya\n");
    printf("8 : Pindah ke halaman sebelumnya\n");
    printf("9 : STOP\n");

    printf("\nWeb yang sedang aktif :\n");
}

#endif // browser_C
