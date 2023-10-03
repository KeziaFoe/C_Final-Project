#include <stdio.h>
#include <math.h>

void inputDataVaksin(){
	printf("a. Nama Vaksin: ");
	char namaVaksin[50];
	scanf("%[^\n]",&namaVaksin);
	printf("b. Kode Batch Vaksin: ");
	char kodeBatch[10];
	scanf("%s",&kodeBatch);
	printf("c. Status Vaksin (sudah/belum): ");
	char statusVaksin[5];
	scanf("%s",&statusVaksin);
	printf("d. Masa Kadaluarsa Vaksin (YYYYMMDD): ");
	char kadaluarsaVaksin[8];
	scanf("%s",&kadaluarsaVaksin);
}

void inputDataPesertaVaksin(){
	printf("Nama: ");
	char nama[50];
	scanf("\n");
	scanf("%[^\n]",&nama);
	printf("Tempat/Tanggal Lahir: ");
	char ttl[50];
	scanf("\n");
	scanf("%[^\n]",&ttl);
	printf("Alamat sesuai NIK: ");
	char alamatNIK[50];
	scanf("\n");
	scanf("%[^\n]",&alamatNIK);
	printf("Alamat tambahan (bila tidak ada diisi '-'): ");
	char alamatTambahan[50];
	scanf("\n");
	scanf("%[^\n]",&alamatTambahan);
	printf("Nomor Handphone: ");
	char nomorHandphone[20];
	scanf("%s",&nomorHandphone);
	printf("Tenaga Kesehatan yang melakukan vaksinasi \n");
	printf("       Nama Petugas: ");
	char namaPetugas[50];
	scanf("\n");
	scanf("%[^\n]",&namaPetugas);
	printf("       Nomor Ijin Praktek Tenaga Medis: ");
	char nomorIjin[20];
	scanf("%s",&nomorIjin);
}

void dataVaksinasi(){
	printf("Nama Vaksin: ");
	char namaVaksin1[50];
	scanf("\n");
	scanf("%[^\n]",&namaVaksin1);
	printf("Nomor Batch Vaksin: ");
	char nomorVaksin1[10];
	scanf("%s",&nomorVaksin1);
	printf("Lokasi Vaksinasi: ");
	char lokasiVaksin[50];
	scanf("\n");
	scanf("%[^\n]",&lokasiVaksin);
}

void sertifikatVaksin(long long int tahun, long long int bulan, char tanggal[], char nomorinduk[], int pilih){
	int digit;
	digit=1+(int)log10(bulan);
	if(digit==1){
		printf("Nomor Sertifikat Vaksin: VKS%d-%lld0%lld%s-%s\n",pilih,tahun,bulan,tanggal,nomorinduk);
	}
	else if(digit==2){
		printf("Nomor Sertifikat Vaksin: VKS%d-%lld%lld%s-%s\n",pilih,tahun,bulan,tanggal,nomorinduk);
	}
}

int main(){
	printf("Input Data Vaksin: \n");
	inputDataVaksin();
	printf("\n");
	
	printf("Input Data Peserta Vaksin: \n");
	printf("Nomor Induk Kependudukan: ");
	char nik[12];
	scanf("%s",&nik);
	inputDataPesertaVaksin();
	printf("\n");
	
	printf("Pilih vaksinasi:\n 1. Vaksinasi pertama \n 2. Vaksinasi kedua\n");
	printf("Pilihan: ");
	int pilihan;
	scanf("%d",&pilihan);
	
	while(pilihan!=1&&pilihan!=2){
		printf("Input salah! Masukkan angka 1/2!\n");
		printf("Pilihan: ");
		scanf("%d",&pilihan);
	}
	if(pilihan==1){
		printf("Vaksinasi pertama:\n");
		dataVaksinasi();
		printf("Tanggal Vaksinasi (YYYY MM DD): ");
		char tanggalVaksinasi[2];
		long long int bulanVaksinasi,tahunVaksinasi;
		scanf("%lld %lld %s",&tahunVaksinasi,&bulanVaksinasi,&tanggalVaksinasi);
		sertifikatVaksin(tahunVaksinasi,bulanVaksinasi,tanggalVaksinasi,nik,pilihan);
		long long int digit,hasil;
		hasil=bulanVaksinasi+1;
		if(hasil!=13){
		digit=1+(int)log10(hasil);
			if(digit==1){
			printf("Tanggal vaksinasi kedua anda (YYYY MM DD): %lld 0%lld %s\n",tahunVaksinasi,hasil,tanggalVaksinasi);
			}
			else if(digit==2){
			printf("Tanggal vaksinasi kedua anda (YYYY MM DD): %lld %lld %s",tahunVaksinasi,hasil,tanggalVaksinasi);
			}
		}
		else{
			long long int hasil;
			hasil=tahunVaksinasi+1;
			printf("Tanggal vaksinasi kedua anda (YYYY MM DD): %lld 01 %s\n",hasil,tanggalVaksinasi);
		
		}
	}
	else{
		printf("Vaksinasi kedua:\n");
		dataVaksinasi();
		printf("Tanggal Vaksinasi (YYYY MM DD): ");
		long long int tahunVaksinasi,bulanVaksinasi;
		char tanggalVaksinasi[2];
		scanf("%lld %lld %s",&tahunVaksinasi,&bulanVaksinasi,&tanggalVaksinasi);
		sertifikatVaksin(tahunVaksinasi,bulanVaksinasi,tanggalVaksinasi,nik,pilihan);
		long long int hasil,digit;
		hasil=1+tahunVaksinasi;
		digit=1+(int)log10(bulanVaksinasi);
		if(digit==1){
			printf("Tanggal Vaksinasi selanjutnya (YYYY MM DD): %lld 0%lld %s\n",hasil,bulanVaksinasi,tanggalVaksinasi);
		}
		else if(digit==2){
			printf("Tanggal Vaksinasi selanjutnya (YYYY MM DD): %lld %lld %s\n",hasil,bulanVaksinasi,tanggalVaksinasi);
		}
	}
	
	return 0;
}

