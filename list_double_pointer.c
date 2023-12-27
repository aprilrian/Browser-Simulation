#ifndef list_double_pointer_C
#define list_double_pointer_C

/***********************************/
/* Program   : list_double_pointer.c */
/* Deskripsi : Realisasi list double pointer */
/* NIM/Nama  : 2406012112002/Aprilyanto Setiyawan Siburian
               24060121140094/Muhammad Akmal Iskandar
*/
/* Tanggal   : 30 November 2022 */
/***********************************/

#include "list_double_pointer.h"
#include "browser.h"


/* ----- Test List Kosong ----- */
boolean ListEmpty (List L){
    /* Mengirim true jika list kosong */

    // kamus lokal

    // algoritma
        return First(L) == Nil;
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L) {
    /* I.S. : sembarang
       F.S. : Terbentuk list kosong */

    // kamus lokal

    // algoritma
        First(*L) = Nil;
}


/* ----- Manajemen Memori ----- */
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */

    /*Kamus Lokal*/
        address P;

    /*Algoritma*/
        P = (address)malloc(sizeof(ElmtList));
        if (P != Nil){
            info(P) = X;
            next(P) = Nil;
            prev(P) = Nil;
            isOn(P) = false;
        }
        return P;
}

void Dealokasi (address *P){
    /* I.S. : P terdefinisi
       F.S. : P dikembalikan ke sistem
       Melakukan dealokasi/pengembalian address P */
    /*Kamus Lokal*/

    /*Algoritma*/
        free(*P);
}


/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P) {
/* I.S. : Sembarang, P sudah dialokasi
   F.S. : Menambahkan elemen ber-address P sebagai elemen pertama
*/

    // kamus lokal
        address Last;

    // algoritma
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            SetOffAll(L);
            next(P) = First(*L);
            prev(First(*L)) = P;
            First(*L) = P;
        }
        SetOn(&First(*L));
}

void InsertAfter (List *L, address P, address Prec) {
/* I.S. : Prec pastilah elemen list dan bukan elemen terakhir,
          P sudah dialokasi
   F.S. : Insert P sebagai elemen sesudah elemen beralamat Prec */

    // kamus lokal

    // algoritma
        SetOffAll(L);
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
        prev(P) = Prec;
        SetOn(&P);
}

void InsertLast (List *L, address P) {
/* I.S. : Sembarang, P sudah dialokasi
   F.S. : P ditambahkan sebagai elemen terakhir yang baru */

    // kamus lokal
        address Last;

    // algoritma
        if (ListEmpty(*L)) {
            InsertFirst(L, P);
        } else {
            SetOffAll(L);

            Last = First(*L);
            while (next(Last) != Nil) {
                Last = next(Last);
            }

            next(Last) = P;
            prev(P) = Last;

            SetOn(&P);
        }
}


/* Penghapusan Sebuah Elemen */
void DelFirst (List *L) {
/* I.S. : List sembarang
   F.S. : P adalah alamat elemen pertama list sebelum penghapusan
          Elemen list berkurang satu (mungkin menjadi kosong)
          First element yang baru adalah suksesor elemen pertama yang
          lama */

    // kamus lokal
        address P;

    // algoritma
        if (!ListEmpty(*L)) {
            if (NbElmt(*L) != 1) {
                P = First(*L);
                First(*L) = next(First(*L));
                prev(First(*L)) = Nil;
                next(P) = Nil;

                Dealokasi(&P);
                SetOffAll(L);
                SetOn(&First(*L));

            } else {
                P = First(*L);
                First(*L) = Nil;
                Dealokasi(&P);
            }
        }
}

void DelLast (List *L) {
/* I.S. : List sembarang
   F.S. : P adalah alamat elemen terakhir list sebelum penghapusan
          Elemen list berkurang satu (mungkin menjadi kosong)
          Last element baru adalah predesesor elemen pertama yang
          lama, jika ada */

    // kamus lokal
        address Last, PrecLast, P;

    // algoritma
        if (!ListEmpty(*L)) {
            SetOffAll(L);

            Last = First(*L);
            PrecLast = Nil;

            while (next(Last) != Nil) {
                PrecLast = Last;
                Last = next(Last);
            }

            P = Last;
            prev(P) = Nil;

            if (PrecLast == Nil) {
                First(*L) = Nil;
                Dealokasi(&P);

            } else {
                next(PrecLast) = Nil;
                Last = PrecLast;
                SetOn(&Last);
                Dealokasi(&P);
            }
        }
}

void DelAfter (List *L) {
/* I.S. : List tidak kosong. Prec adalah anggota list L.
   F.S. : Menghapus Next(Prec) :
          Pdel adalah alamat elemen list yang dihapus*/

    // kamus lokal
        address Prec, Pdel;

    // algoritma
        if (!ListEmpty(*L)) {
            Prec = First(*L);
            while (!isOn(Prec)) {
                Prec = next(Prec);
            }

            if (next(Prec) != Nil) {
                if (next(next(Prec)) == Nil) {
                    DelLast(L);
                } else {
                    Pdel = next(Prec);

                    next(Prec) = next(next(Prec));
                    prev(next(Prec)) = Prec;

                    next(Pdel) = Nil;
                    prev(Pdel) = Nil;
                    Dealokasi(&Pdel);
                }
            }
        }
}


/* Proses Semua Elemen List */
void PrintInfo (List L) {
/* I.S. : List mungkin kosong
   F.S. : Jika list tidak kosong, semua info yg disimpan pada elemen
          list diprint
          Jika list kosong, hanya menuliskan "list kosong" */ \

    // kamus lokal
    address P;

    // algoritma
    if (ListEmpty(L)) {
        printf("\tBelum ada web yang dibuka!\n");
    } else {
        P = First(L);
        do {
            if (isOn(P)) {
                printf("\t[%s]", info(P));
            } else {
                printf("\t%s", info(P));
            }
            P = next(P);
        } while (P != Nil);
        printf("\n");
    }
}

int NbElmt (List L) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

    // kamus lokal
        address P;
        int counter;

    // algoritma
        P = First(L);
        counter = 0;

        if (First(L) != Nil) {
            while (P != Nil) {
                counter += 1;
                P = next(P);
            }
        }

        return counter;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address Search (List L, infotype X){
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    if(ListEmpty(L)){
        return Nil;
    }else{
        P = First(L);
        while(P != Nil){
            if(info(P) == X){
                return P;
            }else{
                P = next(P);
            }
        }
        return Nil;
    }
}

#endif // list_C`
