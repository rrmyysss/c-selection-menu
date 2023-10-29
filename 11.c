#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ogrenciEkle(struct Ogrenci **bas, int numara, const char *isim, int yas) {
    struct Ogrenci *gezici = *bas;
    struct Ogrenci *yeni = yeniOgrenci(numara, isim, yas);
    if (*bas == NULL) {
        *bas = yeni;
        return;}
    while (gezici->sonraki != NULL)
        gezici = gezici->sonraki;
    gezici->sonraki = yeni;
}

void ogrenciSil(struct Ogrenci *bas, const char *arananIsim) {
    struct Ogrenci *gezici = bas;
    struct Ogrenci *silinecek;
    while (gezici != NULL && gezici->sonraki != NULL) {
        if (strcmp(gezici->isim, arananIsim) == 0) {
            silinecek = gezici->sonraki;
            gezici->sonraki = silinecek->sonraki;
            free(silinecek);
            return;}
        gezici = gezici->sonraki; }
    printf("Öğrenci bulunamadı veya silinemedi.\n");
  }

  void enUzunIsmiBul(struct Ogrenci *bas) {
    struct Ogrenci *gezici = bas;
    int enUzunUzunluk = 0;
    char enUzunIsim[50];
    while (gezici != NULL) {
        int uzunluk = strlen(gezici->isim);
        if (uzunluk > enUzunUzunluk) {
            enUzunUzunluk = uzunluk;
            strcpy(enUzunIsim, gezici->isim);}
        gezici = gezici->sonraki;}
    printf("Listedeki en uzun isim: %s\n", enUzunIsim);
    printf("Uzunluk: %d\n", enUzunUzunluk);
}

struct Ogrenci *yeniOgrenci(int numara, const char *isim, int yas) {
    struct Ogrenci *ogrenci = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
    ogrenci->numara = numara;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

void ogrenciEkle(struct Ogrenci **bas, int numara, const char *isim, int yas) {
    struct Ogrenci *gezici = *bas;
    struct Ogrenci *yeni = yeniOgrenci(numara, isim, yas);
    if (*bas == NULL) {
        *bas = yeni;
        return;}
    while (gezici->sonraki != NULL) {
        gezici = gezici->sonraki;}
    gezici->sonraki = yeni;
}

void ogrenciAra(struct Ogrenci *bas, const char *arananIsim) {
    struct Ogrenci *gezici = bas;
    int bulundu = 0;
    while (gezici != NULL) {
        if (strcmp(gezici->isim, arananIsim) == 0) {
            printf("Bulundu: %d- %s %d\n", gezici->numara, gezici->isim, gezici->yas);
            bulundu = 1; }
        gezici = gezici->sonraki; }
    if (!bulundu)
        printf("Öğrenci bulunamadı.\n");
}

struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci *sonraki;
};

void bilgileriYaz(struct Ogrenci *baslangic) {
    int sayac = 0;
    struct Ogrenci *gezici = baslangic;
    printf("Öğrenci Bilgileri:\n");
    while (gezici != NULL) {
        printf("%d- %s %d %d\n", gezici->numara, gezici->isim, gezici->yas, sayac + 201);
        sayac++;
        gezici = gezici->sonraki;}
    printf("Toplam öğrenci sayısı: %d\n", sayac);
};

int karsilastir(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);

void sirala_liste(int liste[], int boyut) {
    int sirali_liste[255];
    int bas = 0, son = boyut - 1;

    for (int i = 0; i < boyut; i++) {
        if (liste[i] % 2 == 1) {
            sirali_liste[bas] = liste[i];
            bas++;
        } else {
            sirali_liste[son] = liste[i];
            son--;
        }
    }
    printf("Sıralanmış Liste: ");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", sirali_liste[i]);
    }
    printf("\n");

int main() {

  int secim;
  printf("1-Klavyeden -1 girilinceye kadar, girilen tüm tek sayıları listenin başına, çift sayıları ise listenin sonuna ekleyen fonksiyon\n"
         "2-Listeye rastgele üretilmiş 100 sayı eklensin, girilen tüm sayıları büyükten küçüğe sıralayan ve ekrana basan fonksiyon\n"
         "3-Öğrenci numarası, isim ve yaşının saklı tutulduğu, listedeki tüm düğümleri Dolaşan, öğrenci bilgilerinin tümünü ekrana yazan ve sayan fonksiyon\n"
         "4-Listede öğrenci adına göre kayıt arama yapan fonksiyon\n"
         "5-Listede öğrenci adına göre kayıt arama yapan fonksiyon\n"
         "6-Listede en uzun ismin olduğu kaydı yazdıran fonksiyon\n");
  printf("hangi islemi yapmak istiyorsunuz? ");
  scanf("%d",&secim);

  switch (secim) {

    case 1 :
    int girilen_sayilar[255];
    int sayi, count = 0;
    printf("Sayilari girin (-1 girerek bitirin):\n");
    while (1) {
      printf("Sayi: ");
      scanf("%d", &sayi);
      if (sayi == -1)
        break;
    girilen_sayilar[count] = sayi;
    count++; }
    sirala_liste(girilen_sayilar, count);

    case 2 :
      int sayilar[MAX_SIZE];
      int girilen_sayi, count = 0;
      printf("Rastgele 100 sayi ekleniyor:\n");
      for (int i = 0; i < 100; i++) {
        sayilar[i] = rand() % 1000;
        count++; }
      printf("Ekstra sayi ekleyin:\n");
      while (count < MAX_SIZE) {
        printf("Sayi: ");
        scanf("%d", &girilen_sayi);
        sayilar[count] = girilen_sayi;
        count++;
        if (count >= 255)
            break;  }
      qsort(sayilar, count, sizeof(int), karsilastir);
      printf("Siralama sonrasi liste:\n");
      for (int i = 0; i < count; i++)
        printf("%d ", sayilar[i]);
      printf("\n");

    case 3 :
      struct Ogrenci *bas = NULL;
      struct Ogrenci *ogrenci1 = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
      struct Ogrenci *ogrenci2 = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
      ogrenci1->numara = 201;
      strcpy(ogrenci1->isim, "Saliha");
      ogrenci1->yas = 27;
      ogrenci1->sonraki = ogrenci2;
      ogrenci2->numara = 203;
      strcpy(ogrenci2->isim, "Ece");
      ogrenci2->yas = 19;
      ogrenci2->sonraki = NULL;
      bas = ogrenci1;
      bilgileriYaz(bas);
      free(ogrenci1);
      free(ogrenci2);

    case 4 :
        struct Ogrenci *bas = NULL;
        ogrenciEkle(&bas, 101, "Ahmet", 21);
        ogrenciEkle(&bas, 102, "Mehmet", 20);
        ogrenciEkle(&bas, 103, "Ayşe", 22);
        char arananIsim[50];
        printf("Aranacak öğrenci adını girin: ");
        scanf("%s", arananIsim);
        ogrenciAra(bas, arananIsim);

    case 5 :
        struct Ogrenci *bas = NULL;
        ogrenciEkle(&bas, 101, "Ahmet", 21);
        ogrenciEkle(&bas, 102, "Mehmet", 20);
        ogrenciEkle(&bas, 103, "Ayşe", 22);
        char arananIsim[50];
        printf("Aranacak öğrenci adını girin: ");
        scanf( "%s", arananIsim);
        ogrenciAra(bas, arananIsim);
        ogrenciSil(bas, arananIsim);
        printf("Liste güncellendikten sonra:\n");
        struct Ogrenci *gezici = bas;
        while (gezici != NULL) {
            printf("%d- %s %d\n", gezici->numara, gezici->isim, gezici->yas);
            gezici = gezici->sonraki; }

      case 6 :

        struct Ogrenci *bas = NULL;
        ogrenciEkle(&bas, 101, "Ahmet", 21);
        ogrenciEkle(&bas, 102, "Mehmet", 20);
        ogrenciEkle(&bas, 103, "Abdurrahmangazi", 22);
        ogrenciEkle(&bas, 104, "Ayşe", 22);
        enUzunIsmiBul(bas);
  }
  return 0;
}
