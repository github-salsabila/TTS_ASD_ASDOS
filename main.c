#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

FILE *fp;
int buffer[200];
char ch,filename[100];


void addData(){
    printf("Masukkan nama file baru: ");
    scanf("%s", &filename);
    strcat(filename, ".txt");
    fp = fopen(filename,"w");
    fclose(fp);
    printf("File %s berhasil dibuat!", filename);
}

void readData(){
    menu:
    system("cls");
    printf("Pilih file yang ingin dibaca:\n");
    printf("1. tes1.txt\n");
    printf("2. tes2.txt\n");
    printf("3. Masukan apa saja untuk keluar\n");

    int choice;
    printf("Masukan Pilhan : ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            strcpy(filename, "tes1.txt");
            break;
        case 2:
            strcpy(filename, "tes2.txt");
            break;
        default:
            printf("Pilihan tidak valid!");
            return;
            system("cls");
    }
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nGagal membuka file %s", filename);
        goto menu;
        return;

    }
    printf("\nBerikut adalah isi file %s:\n", filename);
    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }
    getch();
    fclose(fp);
    system("cls");
    goto menu;
}
void updateData() {
    int fileChoice, i = 0, len;
    char newChar;
    char buffer[1024];

    menu2:
    printf("Pilih file yang ingin diupdate:\n");
    printf("1. tes1.txt\n");
    printf("3. tes2.txt\n");
    printf("3. masukan apa saja untuk keluar\n\n");
    printf("Masukan Pilhan : ");
    scanf("%d", &fileChoice);

    if (fileChoice == 1) {
        fp = fopen("tes1.txt", "r+");
    } else if (fileChoice == 2) {
        fp = fopen("tes2.txt", "r+");
    }else {
        printf("Pilihan Tidak Ada");
        system ("pause");
        goto menu2;
        return;
    }

    printf("Masukkan karakter baru: ");
    scanf(" %c", &newChar);

    while (fgets(buffer, sizeof(buffer), fp)) {
        len = strlen(buffer);
        fseek(fp, -len, SEEK_CUR);
        for (i = 0; i < len; i++) {
            fputc(newChar, fp);
        }
    }

    fclose(fp);
    printf("Semua karakter berhasil diubah!");
    system("pause");
    goto menu2;
}


void deleteData(){
    menu3:
    system("cls");
    printf("Pilih file yang ingin dihapus:\n");
    printf("1. tes1.txt\n");
    printf("2. tes2.txt\n");
    printf("3. Masukan apa saja untuk keluar\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            strcpy(filename, "tes1.txt");
            break;
        case 2:
            strcpy(filename, "tes2.txt");
            break;
        default:
            printf("Pilihan tidak valid!");
            return;
    }
    if (remove(filename) == 0) {
        printf("File %s berhasil dihapus!\n", filename);
        system("pause");
        system("cls");
        goto menu3;
    }
    else {
        printf("Gagal menghapus file %s\n", filename);
        system("pause");
        system("cls");
        goto menu3;
    }
}

int main(){
    system ("color 73");
    int pilihan;
    menuawal:
    printf("1. Membuat File txt\n");
    printf("2. Membaca File txt\n");
    printf("3. Update data file txt\n");
    printf("4. Hapus data txt\n");
    printf("5. Keluar\n");
    printf("Masukan Pilihan : ");
    scanf("%d", &pilihan);
    switch(pilihan){

    case 1:
    system ("cls");
    addData();
    break;
    system ("cls");
    goto menuawal;

    case 2:
    readData();
    system ("cls");
    goto menuawal;

    case 3:
    system ("cls");
    updateData();
    system ("cls");
    goto menuawal;

    case 4:
    deleteData();
    system ("cls");
    goto menuawal;

    case 5:
    printf("Keluar");
    break;

    default:
        printf("pilihan tidak ada");
         system ("cls");
         break;

        goto menuawal;
    }
    return 0;
}

/*#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
    system("color 79");
    printf("\n\n");
    printf("\t==============================\n");
    printf("\t=         LOOPS              =\n");
    printf("\t==============================\n");

    void main(){
    void rupiahKeBTC(){
        float rupiah;
        printf("Masukkan nominal dalam bentuk rupiah\n");
        scanf("%f", &rupiah);
        printf("%.3f rupiah=%.2fBTC", rupiah, rupiah/547974483);
    }
    void rupiahKeETH(){
        float rupiah;
        printf("Masukkan nominal dalam bentuk rupiah\n");
        scanf("%f", &rupiah);
        printf("%.3f rupiah= %.2fETH", rupiah, rupiah/37897476);
    }
    void rupiahKeUSDT(){
        float rupiah;
        printf("Masukkan nominal dalam bentuk rupiah:");
        scanf("%f", &rupiah);
        printf("%.3f rupiah= %.2fUSDT", rupiah, rupiah/14342);
    }
    int nilai;
    printf("CHOICE\n");
    printf("\t1.KONVERSI ITDC KE BTC: \n");
    printf("\t2.KONVERSI ITDC KE ETH: \n");
    printf("\t3.KONVERSI ITDC KE USDT: \n");
    printf("4.EXIT: \n");
    printf("\tMasukkan pilihan anda\n");
    scanf("%d", &nilai);
    switch(nilai){
        case 1:
        rupiahKeBTC();
        break;
        case 2:
        rupiahKeETH();
        break;
        case 3:
        rupiahKeUSDT();
        break;
        default:
        printf("Maaf format nilai tidak sesuai");
        break;
    }
}
}

int main(){
    float  HargaB,Potong, bayar;
    float HargaS=2500;
    int JumlahB;

    printf("Masukkan jumlah buku yang ingin dibeli\n");
    scanf("%d", &JumlahB);
    if(JumlahB >=20 && JumlahB <=35){
            HargaB=HargaS*JumlahB;
            printf("Harga Buku", HargaB);
            Potong=(HargaB*10/100);
            printf("mendapat potonga", Potong);
            bayar=HargaB-Potong;
            printf("Maka harga yang harus dibayar adalah %2.f", bayar);
    }
    else if(JumlahB>=35 && JumlahB<=50){
            HargaB=HargaS*JumlahB;
            Potong=HargaB*15/100;
            bayar=HargaB-Potong;
            printf("Maka harga yang harus dibayar adalah %f", bayar);
    }
    else if(JumlahB>=50){
            HargaB=HargaS*JumlahB;
            Potong=HargaB*20/100;
            bayar=HargaB-Potong;
            printf("Maka harga yang harus dibayar adalah %f", bayar);
    }
    return 0;

}

void main(){
    void rupiahKeBTC(){
        float rupiah;
        printf("\tMasukkan nominal dalam bentuk rupiah =");
        scanf("\t%f", &rupiah);
        printf("\t%2.f rupiah=%.5f BTC", rupiah, rupiah/547974483);
    }
    void rupiahKeETH(){
        float rupiah;
        printf("\tMasukkan nominal dalam bentuk rupiah =");
        scanf("\t%f", &rupiah);
        printf("\t%2.f rupiah= %.5f ETH", rupiah, rupiah/37897476);
    }
    void rupiahKeUSDT(){
        float rupiah;
        printf("\tMasukkan nominal dalam bentuk rupiah =");
        scanf("\t%f", &rupiah);
        printf("\t%2.f rupiah= %.5f USDT", rupiah, rupiah/14342);
    }

    int nilai;
    system("color 79");
    printf("\n\n");
    printf("\t=================================\n");
    printf("\t||         CHOICE              ||\n");
    printf("\t================================\n");
    printf("\t||1.KONVERSI ITDC KE BTC:      ||\n");
    printf("\t||2.KONVERSI ITDC KE ETH:      ||\n");
    printf("\t||3.KONVERSI ITDC KE USDT:     ||\n");
    printf("\t||4.EXIT:                      ||\n");
    printf("\t================================\n");
    printf("\tMasukkan pilihan anda :");
    scanf("\t%d", &nilai);
    switch(nilai){
        case 1:
        rupiahKeBTC();
        break;
        case 2:
        rupiahKeETH();
        break;
        case 3:
        rupiahKeUSDT();
        break;
        default:
        printf("\tMaaf format nilai tidak sesuai");
        break;
    }
}
*/

