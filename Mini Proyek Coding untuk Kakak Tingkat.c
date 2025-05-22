// Mini Proyek - Coding Untuk Kakak Tingkat
// Program Menghitung Jumlah Kafein Pada Matcha

# Mini Proyek - Coding untuk Kakak Tingkat

## Identitas Mahasiswa
- Nama : A'fifah Gholimatun A'zzali
- NIM : 2403085
- Kelas : 2B PSTI

## Identitas Kakak Tingkat
- Nama : Azhar Nurulhaifa
- Angkatan : 2022
- Program Studi : PSTI

## Permintaan Program
Kakak ingin dibuatkan program untuk menghitung jumlah kafein pada Matcha dan memberikan peringatan jika jumlah kafein melebihi batas harian

## Penjelasan Program
- Bahasa pemrograman yang digunakan: C
- Fitur Utama:
  - Input jumlah jenis Matcha yang ingin dihitung
  - Input jenis Matcha
  - Input jumlah Matcha dalam gram
  - Perhitungan otomatis (gram * kafeinPerGram)
  - Output total kafein yang dikonsumsi dalam sehari
- Kondisi:
  - Jika total kafein lebih besar dari

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk memeriksa jenis Matcha
int jenisMatcha(char jenis[])
{
    return strcmp(jenis, "premium") == 0 || strcmp(jenis, "latte") == 0 || strcmp(jenis,"blended") == 0;
}

// Fungsi untuk menghitung kafein
float kafein(char jenis[], float gram)
{
float kafeinPerGram;
if (strcmp(jenis,"premium") == 0){
    kafeinPerGram = 2.8;
}
else if (strcmp(jenis, "latte") == 0){
    kafeinPerGram = 2.4;
}
else if (strcmp(jenis, "blended") == 0){
    kafeinPerGram = 2.0;
}
else{
    return 0;
}
return gram * kafeinPerGram;
}

// Fungsi untuk mengubah string menjadi huruf kecil
void toLower(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    int jumlah;
    char jenis[30];
    float gram;
    float totalKafein = 0;
    float batasKafein = 400.0; // Batas wajar komsumsi kafein dalam sehari
    
    printf("=== Matcha Tracker ===\n");
    printf("Masukkan Jumlah Jenis Matcha Yang Ingin Dihitung: ");
    scanf("%d", &jumlah);
    
    for(int i = 1; i <= jumlah; i++)
    {
        int valid = 0;
        
        while(!valid)
        {
            printf("\nJenis Matcha ke-%d: ", i);
            printf("Masukkan Jenis Matcha (Premium, Latte, Blended): ");
            scanf("%s", &jenis);
            
            toLower(jenis);
            
            if(!jenisMatcha(jenis)){
                printf("Jenis Matcha Tidak Valid! Silahkan Masukkan Ulang.\n");
            }
            else 
            {
                valid = 1;
            }
        }
        printf("Masukkan Jumlah Matcha (gram): ");
        scanf("%f", &gram);
        
        float jumlahKafein = kafein(jenis, gram);
        printf("Kafein Dari %s: %.2f mg\n", jenis, jumlahKafein);
        
        totalKafein += jumlahKafein;
    }
    printf("\n Total Konsumsi Kafein Hari Ini: %.2f mg\n", totalKafein);
    
    if(totalKafein > batasKafein)
    printf("PERINGATAN!!! : Total Kafein Melebihi Batas Harian\n");
    else
    printf("AMAN : Masih Dalam Batas Harian\n");
    
    return 0;
}