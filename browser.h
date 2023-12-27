#ifndef browser_H
#define browser_H

/***********************************/
/* Program   : browser.h */
/* Deskripsi : Modul untuk browser */
/* NIM/Nama  : 2406012112002/Aprilyanto Setiyawan Siburian
               24060121140094/Muhammad Akmal Iskandar
*/
/* Tanggal   : 30 November 2022 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "list_double_pointer.h"


void SetOn (address *P);
/* I.S. : P terdefinisi
   F.S. : situs address P disetel menjadi aktif*/

void SetOff (address *P);
/* I.S. : P terdefinisi
   F.S. : situs address P disetel menjadi nonaktif*/

void SetOffAll (List *L);
/* I.S. : List tidak kosong
   F.S. : semua situs disetel menjadi nonaktif*/

void NextPage (List *L);
/* I.S. : List tidak kosong
   F.S. : berpindah ke halaman selanjutnya*/

void PrevPage (List *L);
/* I.S. : List tidak kosong
   F.S. : berpindah ke halaman sebelumnya*/

void MenuPage();
/* I.S. : Tidak terdefinisi 
   F.S. : Tampilan menu opsi yang bisa dilakukan dalam program*/

#endif // browser_H