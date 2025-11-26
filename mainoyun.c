#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {


// --- KARAKTER DURUM DEÐÝÞKENLERÝ ---
int saglik = 100;    
int enerji = 100;    
int yemekSayisi = 0; 
int siginakBulundu = 0; // 0: Bulunmadý, 1: Bulundu
char komut;
int i;  
int sans; 
int sifreGirisi; 
int dogruSifre = 27; 
    
    

    printf("--- Basit Hayatta Kalma Simulatörü Basladi ---\n"); 
    printf("Komutlar:\n\n");
	printf("A:Avlan\n");
	printf("S:Siginak Ara \n");
	printf("E:Envanterini Gor\n");
	printf("R:Dinlen\n");
	printf("F:Bolgedeki Tehliyeyi simule et\n");
	printf("P:Sifre ile ilerleme\n");	
	printf("X:Cikis\n\n\n");
    // DO-WHILE Komut Döngüsü
    do {
        // *** Oyuncunun Durumu Gösterimi (E komutu iþlevi) ***
        printf("\n*** Durum: Saglik:%d | Enerji:%d | Yemek:%d | Siginak: %s ***\n", 
               saglik, enerji, yemekSayisi, siginakBulundu ? "VAR" : "YOK");
        printf("Komut girin: ");
        scanf(" %c", &komut); 

        // Komut Sistemi - Zorunlu SWITCH-CASE kýsmý
        switch (komut) {
            case 'A': // Avlan (Enerji azalýr, yemek kazanma ihtimali IF ile deðerlendirilir)
                printf("Avlaniyorsunuz...\n");
                
                // Enerji azalýr - Aritmetik Operatör
                enerji -= 15; 
                if (enerji < 0) enerji = 0;

                sans = rand() % 100; // Rastgele þans (sözde rastgele)
                
                // Mantýksal Operatörler (|| ve &&) zorunluluðu
                if (enerji > 50 || sans < 60) { 
                    printf("Yiyecek buldun!\n");
                    yemekSayisi++;
                } else if (sans > 60 && enerji < 40) { 
                    printf("Yaralandiniz ve yemek bulamadiniz!\n");
                    saglik -= 10;
                } else {
                    printf("Bos dondunuz.\n");
                }
                break;

            case 'S': // Sýðýnak Ara (Baþarý ihtimali IF-ELSE ile deðerlendirilir)
                printf("Siginak aranýyor...\n");
                
                
                if (siginakBulundu == 1) { 
                    printf("Zaten bir siginaginiz var.\n");
                } else if (enerji > 40 && yemekSayisi >= 1) { 
                    printf("Güvenli bir siginak buldunuz.\n");
                    siginakBulundu = 1; 
                } else {
                    printf("Yetersiz kaynak/enerji, siginak bulamadiniz.\n");
                }
                break;
                
            case 'R': // Dinlen (Enerji ve saðlýk artýþý)
                printf("Dinleniyorsunuz...\n");
                
                // Enerji ve saðlýk artýþý - Aritmetik Operatörler
                enerji += 20;
                saglik += 10;
                
                if (enerji > 100) enerji = 100;
                if (saglik > 100) saglik = 100;
                
                printf("Enerji ve saglik yukseldi.\n");
                break;
                
            case 'E': // Envanteri Görüntüle
                printf("Durum ve envanter (yukarida) listelendi.\n");
                break;
                
            case 'F': // Tehlike Serisi - Zorunlu FOR Döngüsü
                printf("!! Tehlike Basliyor (3 Tur) !!\n");
                
                for (i = 1; i <= 3; i++) { // Tehlike dalgasý simülasyonu
                    printf("--- Tur %d ---\n", i);
                    if (siginakBulundu == 1) {
                        printf("Siginak sizi korudu.\n");
                    } else {
                        printf("Zarar gordunuz.\n");
                        saglik -= 15; // Aritmetik Operatör
                        enerji -= 5;
                    }
                    if (saglik <= 0) break; 
                }
                printf("!! Tehlike Sona Erdi !!\n");
                break;
                
            case 'P': // Þifreli Ýlerleme - Zorunlu DO-WHILE Doðrulama Döngüsü
                printf("Engeli asmak icin Gaziantep\'in Plakasini girin.\n", dogruSifre); 
                
                do {
                    printf("Sifreyi (Sayi) gir: ");
                    scanf(" %d", &sifreGirisi); 
                    
                    if (sifreGirisi != dogruSifre) { 
                        printf("Yanlýs sifre! Tekrar deneyin.\n");
                        enerji -= 5;
                        if (enerji < 0) enerji = 0;
                    }
                } while (sifreGirisi != dogruSifre && enerji > 0); 

                if (sifreGirisi == dogruSifre) {
                    printf("Sifre dogru! Engeli astiniz.\n");
                } else {
                    printf("Enerjiniz tukendi, engeli asamadiniz.\n");
                }
                break;
                
            case 'X': // Çýkýþ
                printf("Simulasyondan cikiliyor.\n");
                break;
                
            default:
                printf("Gecersiz komut.\n");
        }

        // Oyun Bitti Kontrolü
        if (saglik <= 0) {
            printf("\n!!! OLDUNUZ. OYUN BÝTTÝ !!!\n");
            komut = 'X'; 
        }

    } while (komut != 'X'); 

  	return 0;
}
