#include <stdio.h>
#include <stdlib.h>

void ana_menu(void);
int sayi_al(int, int);
int sirala(int *,int);
int ayni_sayi_ras(int *,int, int);
int ayni_sayi_kul(int *,int,int,int);
int tutturma(int *,int *,int,int);
char yeni(void);
void istatistik(int [], int [], int, int);
void yer_degistir(int *, int *);

int main()
{
    int besleme;
    int static toplam_odul=0;
    char cevap;
    int secim,secim2,i;
    char devam=0;
    int static frek_sayisal[49]= {0}, frek_sans[34]= {0}, frek_sans_arti[14]= {0},frek_on[80]= {0}, frek_super[54]= {0};
    int static sayisal_no[49]= {0}, sans_no[34]= {0}, sans_arti_no[14]= {0}, on_no[80]= {0}, super_no[54]= {0};
    int frek_sayisal2[49]= {0}, frek_sans2[34]= {0}, frek_sans_arti2[14]= {0}, frek_on2[80]= {0}, frek_super2[80]= {0};
    int sayisal_no2[49]= {0}, sans_no2[34]= {0}, sans_arti_no2[14]= {0}, on_no2[80]= {0}, super_no2[54]= {0};
    int sayac_sayisal,sayisal_oyun_odul=0,dizi1[6],dizi2[49];
    int static sayisal_toplam_odul=0;
    int dizi_sans[5],arti[1],dizi_sans_ras[34],dizi_sans_arti[14],sayac1,sayac2,sans_topu_odul=0;
    int static sans_topu_toplam=0;
    int on_numara_kul[10], on_numara_ras[80],sayac,on_numara_odul=0;
    int static on_numara_toplam=0;
    int sayac_super,super_loto_odul=0, dizi_super_kul[6],dizi_super_ras[49];
    int static super_odul=0;

    printf("Besleme degerini giriniz:");
    scanf("%d", &besleme);
    srand(besleme); //Programin kontrolu icin cekirdek degeri girdisi isteniyor..
    do
    {
        ana_menu();
        secim=sayi_al(1,3); //Ana menu icin 1-3 arasi deger girdisi isteniyor..
        switch (secim)
        {
        case 1 :
            do
            {
                printf("\n SANS OYUNLARI ALT MENUSU\n\n");
                printf("1. Sayisal Loto Oynama\n");
                printf("2. Sans Topu Oynama\n");
                printf("3. On Numara Oynama\n");
                printf("4. Super Loto Oynama\n");
                printf("5. Ana Menu\n\n");
                printf("(Toplam odulunuz: %d puan) Seciminizi giriniz:",toplam_odul);
                secim2=sayi_al(1,5); //Alt menu icin 1-5 arasi deger girdisi isteniyor..
                printf("\n");
                switch (secim2)
                {
                case 1 :
                    do
                    {
                        printf("*** Sayisal Loto Oynama ***\n\n");

                        sayac_sayisal=0; //Her sayisal oyunu icin sayac sifirlaniyor..
                        sayisal_oyun_odul=0; //Her oynanan sayisal oyunu icin kazanilan odul sifirlaniyor..
                        ayni_sayi_kul(dizi1,6,1,49); //Kullanicidan 1-49 arasinda 6 farkli sayi isteniyor..
                        sirala(dizi1,5); //Kullanicinin sayilari siralaniyor..

                        printf("\nSectiginiz sayilar: ");
                        for(i=0; i<6; i++)
                        {
                            printf("%d ",dizi1[i]);
                        }
                        printf("\nCekilis Yapiliyor\n");
                        for(i=0; i<50; i++)
                        {
                            printf("*");
                        }
                        printf("\n");
                        for(i=0; i<6; i++)
                        {
                            dizi2[i]=rand()%49+1;   //1-49 arasinda rasgele sayi seciliyor
                        }
                        ayni_sayi_ras(dizi2,6,49); //Rasgele sayilarin ayni olmamasi saglaniyor..
                        sirala(dizi2, 5); //Rasgele sayilar siralaniyor..
                        for (i=0; i<49; i++)
                        {
                            sayisal_no[i]=i+1; //Sayisal loto oyunundaki sayilarin oldugu dizi olusturuluyor..
                        }
                        for (i=0; i<6; i++)
                        {
                            frek_sayisal[dizi2[i]-1]++; //Sayisal loto oyununda cikan sayilarin oldugu dizilerdeki elemanlar artiriliyor..
                        }
                        printf("Sansli Sayilar: ");
                        for(i=0; i<6; i++)
                        {
                            printf("%d ",dizi2[i]);
                        }
                        printf("\n");
                        sayac_sayisal=tutturma(dizi1,dizi2,6,6); //Kullanicinin sayilari ve rasgele sayilar karsilastiriliyor..

                        if(sayac_sayisal==0)
                        {
                            printf("\nHicbir Sayiyi Tutturamadiniz..\n");
                            sayisal_oyun_odul=0;
                        }
                        else if(sayac_sayisal==1)
                        {
                            printf("\nBir Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if(sayac_sayisal==2)
                        {
                            printf("\nIki Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if (sayac_sayisal==3)
                        {
                            printf("\nUc Sayi Tutturdunuz..\n");
                            sayisal_oyun_odul=32;
                            printf("Bu oyunda %d puan kazandiniz..\n",sayisal_oyun_odul);
                        }
                        else if(sayac_sayisal==4)
                        {
                            printf("\nDort Sayi Tutturdunuz..\n");
                            sayisal_oyun_odul=64;
                            printf("Bu oyunda %d puan kazandiniz..\n",sayisal_oyun_odul);
                        }
                        else if(sayac_sayisal==5)
                        {
                            printf("\nBes Sayi Tutturdunuz..\n");
                            sayisal_oyun_odul=128;
                            printf("Bu oyunda %d puan kazandiniz..\n",sayisal_oyun_odul);
                        }
                        else if(sayac_sayisal==6)
                        {
                            printf("\nAlti Sayi Tutturdunuz..\n");
                            sayisal_oyun_odul=256;
                            printf("Bu oyunda %d puan kazandiniz..\n",sayisal_oyun_odul);
                        }

                        sayisal_toplam_odul+=sayisal_oyun_odul; //Sayisal oyunundaki oduller toplaniyor..
                        toplam_odul+=sayisal_oyun_odul; //Sayisaldaki oduller toplam odule ekleniyor..

                        printf("Simdiye kadar sayisal loto oyunundan toplam %d puan kazandiniz..\n\n",sayisal_toplam_odul);
                        printf("Yeni bir sayisal loto oyunu oynamak ister misiniz(e/E/h/H)? ");
                        cevap=yeni(); //Yeni bir sayisal oyunu icin soruluyor..
                    }
                    while(cevap=='e' || cevap=='E');
                    break;
                case 2 :
                    do
                    {
                        printf("*** Sans Topu Oynama ***\n\n");

                        sayac1=0; //Her sans topu oyunu icin sayaclar sifirlaniyor..
                        sayac2=0;
                        sans_topu_odul=0; //Her oynanan sans topu oyunu icin odul sifirlaniyor..
                        ayni_sayi_kul(dizi_sans,5,1,34); //Kullanicidan 1-34 arasinda 5 farkli sayi isteniyor..
                        sirala(dizi_sans,4); //Kullanici sayilari siralaniyor..
                        ayni_sayi_kul(arti,1,1,14); //Kullanicidan 1-14 arasinda 1 sayi isteniyor..

                        printf("\nSectiginiz Sayilar: ");
                        for (i=0; i<5; i++)
                        {
                            printf("%d ",dizi_sans[i]);
                        }
                        printf("+ %d\n",arti[0]);

                        for(i=0; i<5; i++)
                        {
                            dizi_sans_ras[i]=rand()%34+1;  //1-34 arasinda rasgele 6 sayi seciliyor..
                        }

                        ayni_sayi_ras(dizi_sans_ras,5,34); //Rasgele sayilarin farkli olmasi saglaniyor..
                        sirala(dizi_sans_ras, 4); //Rasgele sayilar siralaniyor..

                        dizi_sans_arti[0]=rand()%14+1;  //1-14 arasinda rasgele sayi seciliyor..

                        for (i=0; i<34; i++)
                        {
                            sans_no[i]=i+1;  //Sans topu oyunundaki sayilarin oldugu dizi olusturuluyor..
                        }

                        for (i=0; i<5; i++)
                        {
                            frek_sans[dizi_sans_ras[i]-1]++; //Sans topu oyununda cikan sayilarin oldugu dizilerdeki elemanlar artiriliyor..
                        }


                        for (i=0; i<14; i++)
                        {
                            sans_arti_no[i]=i+1;
                        }
                        for (i=0; i<1; i++)
                        {
                            frek_sans_arti[dizi_sans_arti[i]-1]++;
                        }
                        printf("Sansli Sayilar: ");
                        for(i=0; i<5; i++)
                        {
                            printf("%d ",dizi_sans_ras[i]);
                        }
                        printf("+ %d\n",dizi_sans_arti[0]);

                        sayac1=tutturma(dizi_sans,dizi_sans_ras,5,5); //Kullanici ve rasgele sayilar karsilastiriliyor..
                        sayac2=tutturma(arti,dizi_sans_arti,1,1);

                        if(sayac1==0 && sayac2==0)
                        {
                            printf("\nHicbir Sayiyi Tutturamadiniz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if(sayac1==0 && sayac2==1)
                        {
                            printf("\nArti Bir Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if (sayac1==1 && sayac2==0)
                        {
                            printf("\nBir Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if(sayac1==1 && sayac2==1)
                        {
                            printf("\nBir Arti Bir Tutturdunuz..\n");
                            sans_topu_odul=2;
                            printf("Bu oyunda %d puan kazandiniz..\n",sans_topu_odul);
                        }
                        else if (sayac1==2 && sayac2==0)
                        {
                            printf("\nIki Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if (sayac1==2 && sayac2==1)
                        {
                            printf("\nIký Arti Bir Tutturdunuz..\n");
                            sans_topu_odul=4;
                            printf("Bu oyunda %d puan kazandiniz..\n",sans_topu_odul);
                        }
                        else if(sayac1==3 && sayac2==0)
                        {
                            printf("\nUc Tutturdunuz..\n");
                            sans_topu_odul=8;
                            printf("Bu oyunda %d puan kazandiniz..\n",sans_topu_odul);
                        }
                        else if(sayac1==3 && sayac2==1)
                        {
                            printf("\nUc Arti Bir Tutturdunuz..\n");
                            sans_topu_odul=16;
                            printf("Bu oyunda %d puan kazandiniz..\n",sans_topu_odul);
                        }
                        else if(sayac1==4 && sayac2==0)
                        {
                            printf("\nDort Tutturdunuz..\n");
                            sans_topu_odul=32;
                            printf("Bu oyunda %d puan kazandiniz..\n",sans_topu_odul);
                        }
                        else if(sayac1==4 && sayac2==1)
                        {
                            printf("\nDort Arti Bir Tutturdunuz..\n");
                            sans_topu_odul=64;
                            printf("Bu oyunda %d puan kazandiniz..\n",sans_topu_odul);
                        }
                        else if(sayac1==5 && sayac2==0)
                        {
                            printf("\nBes Tutturdunuz..\n");
                            sans_topu_odul=128;
                            printf("Bu oyunda %d puan kazandiniz..\n",sans_topu_odul);
                        }
                        else if(sayac1==5 && sayac2==1)
                        {
                            printf("\nBes Arti Bir Tutturdunuz..\n");
                            sans_topu_odul=256;
                            printf("Bu oyunda %d puan kazandiniz..\n",sans_topu_odul);
                        }

                        sans_topu_toplam+=sans_topu_odul; //Sans topu oyunlarinda kazanilan toplam odul toplaniyor..
                        toplam_odul+=sans_topu_odul; //Tum oyunlar icin toplam odul toplaniyor..
                        printf("Simdiye kadar sans topu oyunundan toplam %d puan kazandiniz..\n\n",sans_topu_toplam);
                        printf("Yeni bir sans topu oyunu oynamak ister misiniz(e/E/h/H)? ");
                        cevap=yeni(); //Yeni bir sans topu oyunu icin soruluyor..
                    }
                    while(cevap=='e' || cevap=='E');
                    break;
                case 3 :
                    do
                    {
                        printf("*** On Numara Oynama ***\n\n");

                        sayac=0; //Her on numara oyunu icin sayaclar sifirlaniyor..
                        on_numara_odul=0; ////Her on numara oyunu icin odul sifirlaniyor..

                        ayni_sayi_kul(on_numara_kul,10,1,80); //Kullanicidan 1-80 arasinda 10 farkli sayi isteniyor..
                        sirala(on_numara_kul,9); //Kullanici sayilari siralaniyor..

                        printf("\nSectiginiz Sayilar: ");
                        for (i=0; i<10; i++)
                        {
                            printf("%d ",on_numara_kul[i]);
                        }

                        printf("\nCekilis Yapiliyor\n");
                        for(i=0; i<55; i++)
                        {
                            printf("*");
                        }
                        printf("\n");

                        for(i=0; i<22; i++)
                        {
                            on_numara_ras[i]=rand()%80+1;  //1-80 arasinda rasgele 10 sayi seciliyor..
                        }
                        ayni_sayi_ras(on_numara_ras,22,80); //Rasgele sayilarin farkli olmasi saglaniyor..
                        sirala(on_numara_ras, 21); //Rasgele sayilar siralaniyor..

                        for (i=0; i<80; i++)
                            on_no[i]=i+1; //On numara oyunundaki sayilarin oldugu dizi olusturuluyor..

                        for (i=0; i<10; i++)
                            frek_on[on_numara_ras[i]-1]++; //On numara oyununda cikan sayilarin oldugu dizilerdeki elemanlar artiriliyor..

                        printf("Sansli Sayilar: ");
                        for(i=0; i<22; i++)
                        {
                            printf("%d ",on_numara_ras[i]);
                        }
                        printf("\n");

                        sayac=tutturma(on_numara_kul,on_numara_ras,22,10); //Kullanicinin sayilari ve rasgele sayilar karsilastiriliyor..

                        if(sayac==0)
                        {
                            printf("\nHicbir Sayiyi Tutturamadiniz..\n");
                            on_numara_odul=8;
                            printf("Bu oyunda %d puan kazandiniz..\n",on_numara_odul);
                        }
                        else if(sayac==1)
                        {
                            printf("\nBir Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if(sayac==2)
                        {
                            printf("\nIki Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if (sayac==3)
                        {
                            printf("\nUc Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if(sayac==4)
                        {
                            printf("\nDort Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if(sayac==5)
                        {
                            printf("\nBes Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if(sayac==6)
                        {
                            printf("\nAlti Sayi Tutturdunuz..\n");
                            on_numara_odul=16;
                            printf("Bu oyunda %d puan kazandiniz..\n",on_numara_odul);
                        }
                        else if(sayac==7)
                        {
                            printf("\nYedi Sayi Tutturdunuz..\n");
                            on_numara_odul=32;
                            printf("Bu oyunda %d puan kazandiniz..\n",on_numara_odul);
                        }
                        else if(sayac==8)
                        {
                            printf("\nSekiz Sayi Tutturdunuz..\n");
                            on_numara_odul=64;
                            printf("Bu oyunda %d puan kazandiniz..\n",on_numara_odul);
                        }
                        else if(sayac==9)
                        {
                            printf("\nDokuz Sayi Tutturdunuz..\n");
                            on_numara_odul=128;
                            printf("Bu oyunda %d puan kazandiniz..\n",on_numara_odul);
                        }
                        else if(sayac==10)
                        {
                            printf("\nOn Sayi Tutturdunuz..\n");
                            on_numara_odul=256;
                            printf("Bu oyunda %d puan kazandiniz..\n",on_numara_odul);
                        }

                        on_numara_toplam+=on_numara_odul; //On numara oyununda kazanilan oduller toplaniyor..
                        toplam_odul+=on_numara_odul; //Tum oyunlarda kazanilan oduller toplaniyor..
                        printf("Simdiye kadar on numara oyunundan toplam %d puan kazandiniz..\n\n",on_numara_toplam);
                        printf("Yeni bir on numara oyunu oynamak ister misiniz(e/E/h/H)? ");
                        cevap=yeni(); //Yeni bir on numara oyunu icin soruluyor..
                    }
                    while(cevap=='e' || cevap=='E');
                    break;
                case 4 :
                    do
                    {
                        printf("*** Super Loto Oynama ***\n\n");

                        sayac_super=0; //Her super loto oyunu icin sayaclar sifirlaniyor..
                        super_loto_odul=0; //Her super loto oyununda kazanilan odul sifirlaniyor..
                        ayni_sayi_kul(dizi_super_kul,6,1,54); //Kullanicidan 1-54 arasinda 6 farkli sayi isteniyor..
                        sirala(dizi_super_kul,5); //Kullanici sayilari siralaniyor..

                        printf("\nSectiginiz Sayilar: ");
                        for(i=0; i<6; i++)
                        {
                            printf("%d ",dizi_super_kul[i]);
                        }

                        printf("\nCekilis Yapiliyor\n");
                        for(i=0; i<55; i++)
                        {
                            printf("*");
                        }
                        printf("\n");

                        for(i=0; i<6; i++)
                        {
                            dizi_super_ras[i]=rand()%54+1;  //1-54 arasinda rasgele sayi seciliyor..
                        }

                        ayni_sayi_ras(dizi_super_ras,6,54); //Rasgele sayilarin farkli olmasi saglaniyor..
                        sirala(dizi_super_ras, 5); //Rasgele sayilar siralaniyor..

                        for (i=0; i<54; i++)
                            super_no[i]=i+1; //Super loto oyunundaki sayilarin oldugu dizi olusturuluyor..

                        for (i=0; i<6; i++)
                            frek_super[dizi_super_ras[i]-1]++; //Super loto oyununda cikan sayilarin oldugu dizilerdeki elemanlar artiriliyor..

                        printf("Sansli Sayilar: ");
                        for(i=0; i<6; i++)
                        {
                            printf("%d ",dizi_super_ras[i]);
                        }
                        printf("\n");

                        sayac_super=tutturma(dizi_super_kul,dizi_super_ras,6,6); //Kullanici sayilari ve rasgele sayilar karsilastiriliyor..

                        if(sayac_super==0)
                        {
                            printf("\nHicbir Sayiyi Tutturamadiniz..\n");
                        }
                        else if(sayac_super==1)
                        {
                            printf("\nBir Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if(sayac_super==2)
                        {
                            printf("\nIki Sayi Tutturdunuz..\n");
                            printf("Bu oyunda odul kazanamadiniz..\n");
                        }
                        else if (sayac_super==3)
                        {
                            printf("\nUc Sayi Tutturdunuz..\n");
                            super_loto_odul=32;
                            printf("Bu oyunda %d puan kazandiniz..\n",super_loto_odul);
                        }
                        else if(sayac_super==4)
                        {
                            printf("\nDort Sayi Tutturdunuz..\n");
                            super_loto_odul=64;
                            printf("Bu oyunda %d puan kazandiniz..\n",super_loto_odul);
                        }
                        else if(sayac_super==5)
                        {
                            printf("\nBes Sayi Tutturdunuz..\n");
                            super_loto_odul=128;
                            printf("Bu oyunda %d puan kazandiniz..\n",super_loto_odul);
                        }
                        else if(sayac_super==6)
                        {
                            printf("\nAlti Sayi Tutturdunuz..\n");
                            super_loto_odul=256;
                            printf("Bu oyunda %d puan kazandiniz..\n",super_loto_odul);
                        }

                        super_odul+=super_loto_odul; //Super loto oyunundaki kazanilan oduller toplaniyor..
                        toplam_odul+=super_loto_odul; //Tum oyunlarda kazanilan oduller toplaniyor..
                        printf("Simdiye kadar super loto oyunundan toplam %d puan kazandiniz..\n\n",super_odul);
                        printf("Yeni bir super loto oyunu oynamak ister misiniz(e/E/h/H)? ");
                        cevap=yeni(); //Yeni bir super loto oyunu icin soruluyor..
                    }
                    while(cevap=='e' || cevap=='E');
                    break;
                case 5 :
                    break;
                }
                if(secim2==5)
                    break;
            }
            while(cevap=='h' || cevap=='H');
            break;
        case 2 :
            printf("\t*** Cekilis Istatistikleri ***\n\n");
            printf("Sayisal Loto'da En Cok Cikmis Sayilar:\n");
            printf("*Sayi*\t*Cikma Miktari*\n");
            for (i=0; i<49; i++)
                frek_sayisal2[i]=frek_sayisal[i]; //Sayisal oyununda cikan sayilarin oldugu dizi baska bir dizide tutuluyor..

            for (i=0; i<49; i++)
                sayisal_no2[i]=sayisal_no[i]; //Sayisal oyunundaki sayilar farkli bir dizide tutuluyor..

            istatistik(frek_sayisal2,sayisal_no2,49,6); //Sayisal oyununda cikan sayilarin frekansi ve sayilar istatistikte siralaniyor..

            printf("\n");
            printf("Sans Topun'da En Cok Cikmis Sayilar:\n");
            printf("*Sayi*\t*Cikma Miktari*\n");
            for (i=0; i<34; i++)
                frek_sans2[i]=frek_sans[i]; //Sans topu oyununda cikan sayilarin oldugu dizi baska bir dizide tutuluyor..

            for (i=0; i<34; i++)
                sans_no2[i]=sans_no[i]; //Sans topu oyunundaki sayilar farkli bir dizide tutuluyor..

            istatistik(frek_sans2,sans_no2,34,5); //Sans topu oyununda cikan sayilarin frekansi ve sayilar istatistikte siralaniyor.

            printf("+\n");

            for (i=0; i<14; i++)
                frek_sans_arti2[i]=frek_sans_arti[i]; //Sans topu oyununda cikan arti sayinin oldugu dizi baska bir dizide tutuluyor..

            for (i=0; i<14; i++)
                sans_arti_no2[i]=sans_arti_no[i]; //Sans topu oyunundaki arti sayi farkli bir dizide tutuluyor..

            istatistik(frek_sans_arti2,sans_arti_no2,14,1); //Sans topu oyununda cikan arti sayinin frekansi ve arti sayi istatistikte siralaniyor.

            printf("\n");
            printf("On Numara'da En Cok Cikmis Sayilar:\n");
            printf("*Sayi*\t*Cikma Miktari*\n");

            for (i=0; i<80; i++)
                frek_on2[i]=frek_on[i]; //On numara oyununda cikan sayilarin oldugu dizi baska bir dizide tutuluyor..

            for (i=0; i<80; i++)
                on_no2[i]=on_no[i]; //On numara oyunundaki sayilar farkli bir dizide tutuluyor..

            istatistik(frek_on2,on_no2,80,10); //On numara oyununda cikan sayilarin frekansi ve sayilar istatistikte siralaniyor.

            printf("\n");
            printf("Super Loto'da En Cok Cikmis Sayilar:\n");
            printf("*Sayi*\t*Cikma Miktari*\n");

            for (i=0; i<54; i++)
                frek_super2[i]=frek_super[i]; //Super loto oyununda cikan sayilarin oldugu dizi baska bir dizide tutuluyor..

            for (i=0; i<54; i++)
                super_no2[i]=super_no[i]; //Super loto oyunundaki sayilar farkli bir dizide tutuluyor..

            istatistik(frek_super2,super_no2,54,6); //Super loto oyununda cikan sayilarin frekansi ve sayilar istatistikte siralaniyor.
            break;
        case 3 :
            do
            {
                printf("Programdan cikmak istediginize emin misiniz(e/E/h/H)?");
                fflush(stdin);
                devam=getchar();
            }
            while (devam != 'e' && devam != 'E' && devam!='h' && devam!='H');
        }
        if(devam=='e' || devam=='E')
            break;
    }
    while(devam=='h' || devam=='H' || secim2==5);
    return 0;
}

int sayi_al(int alt, int ust) //Alt ve ust sinira gore sayi sayi isteniyor..
{
    int sayi;
    scanf("%d", &sayi);

    while (sayi<alt || sayi>ust) //sayi dogru girilinceye kadar bekleniyor...
    {
        printf("Lutfen %d ile %d arasinda sayi giriniz: ",alt,ust);
        scanf("%d",&sayi);
    }
    return sayi;
}

void ana_menu()
{
    printf("\n ANA MENU\n\n");
    printf("1. Sans Oyunlari\n");
    printf("2. Cekilis Istatistikleri\n");
    printf("3. Cikis\n\n");
    printf("Seciminizi giriniz:");
    return;
}

int sirala(int *dizi, int c) //Diziden gelen sayilar siralanip gonderiliyor..
{
    int k,i,gecici;
    for(k=0; k<c; k++)
    {
        for(i=0; i<c; i++)
        {
            if( dizi[i]>dizi[i+1])
            {
                gecici = dizi[i];
                dizi[i] = dizi[i+1];
                dizi[i+1] = gecici;
            }
        }
    }
    return *dizi;
}

int ayni_sayi_ras(int *dizi, int k, int t) //Dizide olusturulan rasgele sayilarin farkli olmasi saglaniyor..
{
    int n,u;
    for (n=0; n<k; n++)
    {
        for (u=0; u<n; u++)
        {
            if (dizi[n]==dizi[u])
            {
                dizi[n]=rand()%t+1;
            }
        }
    }
    return *dizi;
}

int ayni_sayi_kul(int *dizi, int k, int alt,int ust) //Kullanicidan belirli aralikta farkli sayilar girilmesi isteniyor..
{
    int i,m;
    printf(" %d - %d sayilari arasinda;\n",alt,ust);
    for(i=0; i<k; i++)
    {
        printf("%d. sayiyi giriniz: ",i+1);
        dizi[i]=sayi_al(alt,ust);

        for (m=0; m<i; m++)
        {
            while (dizi[i]==dizi[m])
            {
                printf("Girmis oldugunuz sayi zaten mevcut %d.sayiyi tekrar giriniz:",i+1);
                dizi[i]=sayi_al(alt,ust);
            }
        }
    }
    return *dizi;
}

int tutturma(int *dizi1, int *dizi2, int k, int m) //Kullanici ve rasgele sayilari karsilastiriliyor ve sayacta toplanip gonderiliyor..
{
    int t,y;
    int sayac=0;
    for (t=0; t<k; t++)
    {
        for (y=0; y<m; y++)
        {
            if (dizi2[t]==dizi1[y])
                sayac++;
        }
    }
    return sayac;
}

char yeni(void)
{
    char devam;
    do
    {
        fflush(stdin);
        devam=getchar();
    }
    while (devam != 'e' && devam != 'E' && devam!='h' && devam!='H');
    return devam;
}

void istatistik(int v1[], int v2[], int eleman_say, int sayi) //Istatistikler icin oyunlardan gelen frekanslar ve sayilar siralaniyor..
{
    int yer_degisti,gecis_say=0,i,h;
    do
    {
        yer_degisti=0;
        gecis_say++;
        for(i=0; i<eleman_say-gecis_say; i++)
        {
            if(v1[i]<v1[i+1])
            {
                yer_degistir(&v1[i],&v1[i+1]);
                yer_degistir(&v2[i],&v2[i+1]);
                yer_degisti=1;
            }
        }
    }

    while(yer_degisti==1);

    for(h=0; h<sayi; h++)
    {
        if(v2[h]==0)
            break;
        printf("%d\t%d\n",v2[h], v1[h]);
    }

    for (h=sayi; h<eleman_say; h++)
    {
        if(v2[h]==0)
            break;
        if(v1[sayi-1]==v1[h])
            printf("%d\t%d\n",v2[h], v1[h]);
    }
    return;

}

void yer_degistir(int *sayi1, int *sayi2) //Gelen degerlerin yer degistirilmesi saglaniyor..
{
    int gecici_sayi;
    gecici_sayi=*sayi1;
    *sayi1=*sayi2;
    *sayi2=gecici_sayi;
    return;
}
