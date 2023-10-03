#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char string[100];
char kata[80];
string mainkata[16];
int ada[16];

struct dataskorpemain{
	char nama[20];
	int score;
};

char huruf(int angka){
	char a;
	switch(angka){
		case 0: a='A'; break;
		case 1: a='B'; break;
		case 2: a='C'; break;
		case 3: a='D'; break;
		case 4: a='E'; break;
		case 5: a='F'; break;
		case 6: a='G'; break;
		case 7: a='H'; break;
		case 8: a='I'; break;
		case 9: a='J'; break;
		case 10: a='K'; break;
		case 11: a='L'; break;
		case 12: a='M'; break;
		case 13: a='N'; break;
		case 14: a='O'; break;
		case 15: a='P'; break;
		case 16: a='Q'; break;
		case 17: a='R'; break;
		case 18: a='S'; break;
		case 19: a='T'; break;
		case 20: a='U'; break;
		case 21: a='V'; break;
		case 22: a='W'; break;
		case 23: a='X'; break;
		case 24: a='Y'; break;
		case 25: a='Z'; break;
		case 26: a='a'; break;
		case 27: a='b'; break;
		case 28: a='c'; break;
		case 29: a='d'; break;
		case 30: a='e'; break;
		case 31: a='f'; break;
		case 32: a='g'; break;
		case 33: a='h'; break;
		case 34: a='i'; break;
		case 35: a='j'; break;
		case 36: a='k'; break;
		case 37: a='l'; break;
		case 38: a='m'; break;
		case 39: a='n'; break;
		case 40: a='o'; break;
		case 41: a='p'; break;
		case 42: a='q'; break;
		case 43: a='r'; break;
		case 44: a='s'; break;
		case 45: a='t'; break;
		case 46: a='u'; break;
		case 47: a='v'; break;
		case 48: a='w'; break;
		case 49: a='x'; break;
		case 50: a='y'; break;
		case 51: a='z'; break;
	}
	return a;
}

void acakhuruf(char kata[]){
	int i;
	for(i=1;i<=80;i++){
			kata[i]=huruf(rand()%52);
	}
}

void generate(){
	int i;
	acakhuruf(kata);
	printf("-------------------------\n");
	for(i=1;i<=80;i++){
		if(i%5==1){
			printf("|");
		}
		if(i==21||i==41||i==61||i==81){
			printf("\n|");
		}
		printf("%c",kata[i]);
	}
	printf("|\n");
	printf("-------------------------\n");
}

void simpan(){
	int i,pilih;
	printf("-------------------------\n");
	for(i=1;i<=80;i++){
		if(i%5==1){
			printf("|");
		}
		if(i==21||i==41||i==61||i==81){
			printf("\n|");
		}
		printf("%c",kata[i]);
	}
	printf("|\n");
	printf("-------------------------\n");
	printf("Ingin menggunakan kata-kata diatas?\n");
	printf("1. Ya\n");
	printf("2. Tidak\n");
	printf("Pilihan: ");
	scanf("%d",&pilih);
	switch(pilih){
		case 1: 
			FILE *fp;
			fp=fopen("data.txt","w");
			for(i=1;i<=80;i++){
				if(i%5==1){
					fprintf(fp,"|");
				}
				if(i==21||i==41||i==61||i==81){
					fprintf(fp,"\n|");
				}
				fprintf(fp,"%c",kata[i]);
			}
			fprintf(fp,"|\n");
			fclose(fp);
			printf("\nData berhasil disimpan. Untuk memulai permainan silahkan tekan enter lalu pilih opsi 3\n");
			break;
		case 2: printf("Silahkan tekan enter dan pilih opsi 1 untuk mengacak ulang kata\n"); break;
		default: printf("Pilihan salah! Silahkan pilih ulang di opsi 2\n"); break;
	}
}

int cek(){
	int i;
	for(i=0;i<16;i++){
		if(ada[i]==0) return 1;
	}
	return -1;
}

void permainan(){
	char tampilhuruf[100];
	int i;
	FILE *fp;
	fp=fopen("data.txt","r");
	if(fp==NULL){
		printf("Data tidak ditemukan. Silahkan generate kata ulang\n"); exit(1);
	}
	printf("-------------------------\n");
	while(fgets(tampilhuruf,100,fp)){
		printf("%s",tampilhuruf);
	}
	printf("-------------------------\n");
	fclose(fp);
	FILE *fb;
	fb=fopen("data.txt","r");
	while(fscanf(fp,"|%[^|]|%[^|]|%[^|]|%[^|]|\n",&mainkata[i],&mainkata[i+1],&mainkata[i+2],&mainkata[i+3])!=EOF){
		i=i+4;
	}
	fclose(fb);
	int mulai;
	printf("Mulai main?\n");
	printf("1. Ya\n");
	printf("2. Tidak\n");
	printf("Pilihan: ");
	scanf("%d",&mulai);
	while(mulai!=1&&mulai!=2){
		printf("Input salah! Silahkan masukkan angka 1 atau 2!\n");
		printf("Pilihan: ");
		scanf("%d",&mulai);
	}
	switch(mulai){
		case 1:{
			system("pause");
			system("cls");
			struct dataskorpemain pemain;
			printf("Masukkan nama pemain: "); fflush(stdin); gets(pemain.nama);
			int i,index,tebak,tebakkomp,scorekomputer=0;
			for(i=0;i<16;i++){
				ada[i]=0;
			}
			do{
				printf("-------------------------\n");
				printf("|  1  |  2  |  3  |  4  |\n");
				printf("|  5  |  6  |  7  |  8  |\n");
				printf("|  9  |  10 |  11 |  12 |\n");
				printf("|  13 |  14 |  15 |  16 |\n");
				printf("-------------------------\n");
				printf("Game mulai ...\n");
				index=rand()%16;
				while(ada[index]==1){
					index=rand()%16;
				}
				printf("Di kotak manakah tulisan %s berada?\n",mainkata[index]);
				printf("Giliran %s menebak kotak: ",pemain.nama);
				scanf("%d",&tebak);
				while(tebak<1&&tebak>16){
					printf("Input salah! Masukkan angka 1-16.\n");
					printf("Giliran %s menebak kotak: ",pemain.nama);
					scanf("%d",&tebak);
				}
				if(tebak-1==index){
					printf("Benar!\n");
					ada[index]=1;
					pemain.score=pemain.score+10;
				}
				else{
					printf("Salah!\n");
					printf("Giliran Kompie menebak kotak: ");
					tebakkomp=rand()%16+1;
					while(tebakkomp==tebak){
						tebakkomp=rand()%16+1;
					}
					printf("%d\n",tebakkomp);
					if(tebakkomp-1==index){
						printf("Benar!\n");
						ada[index]=1;
						scorekomputer=scorekomputer+10;
					}
					else{
						printf("Salah!\n");
					}
				}
				system("pause");
				system("cls");
			} while(cek()!=-1);
			printf("Score %s: %d\n",pemain.nama,pemain.score);
			printf("Score Kompie: %d\n",scorekomputer);
			FILE *fp;
			fp=fopen("score.txt","a");
			if(pemain.score>=scorekomputer){
				fprintf(fp,"%s %d\n",pemain.nama,pemain.score);
			}
			else{
				fprintf(fp,"Kompie %d\n",scorekomputer);
			}
			fclose(fp);
			printf("Data pemenang berhasil disimpan\n");
		} break;
		case 2:	printf("Kembali ke menu utama\n"); break;
	}
}

void swap(struct dataskorpemain *a, struct dataskorpemain *b){
	struct dataskorpemain temp;
	strcpy(temp.nama, a->nama);
	temp.score=a->score;
	strcpy(a->nama, b->nama);
	a->score=b->score;
	strcpy(b->nama, temp.nama);
	b->score=temp.score;
}

void sort(struct dataskorpemain skor[], int i){
	int j,k,low;
	for(j=0;j<i-1;j++){
		low=j;
		for(k=j+1;k<i;k++)
			if(skor[low].score<skor[k].score) low=k;
			if(low>j) swap(&skor[j],&skor[low]);
	}	
}

void print(struct dataskorpemain skor[], int i){
	int j;
	printf("Rank:\n");
	printf("(R). Nama-Score\n");
	for(j=0;j<i;j++){
		printf("%d. %s-%d\n",j+1,skor[j].nama,skor[j].score);
	}
}

void pemenang(){
	struct dataskorpemain skor[101];
	int i;
	FILE *fp;
	fp=fopen("score.txt","r");
	while(fscanf(fp,"%s %d\n",&skor[i].nama,&skor[i].score)!=EOF){
		i++;
	}
	fclose(fp);
	sort(skor,i);
	print(skor,i);
}

void keluar(){
	printf("Terima kasih!\n");
}

int main(){
	int pilih;
	do{
		printf("----------GAME TEBAK LETAK KATA----------\n\n");
		printf("Pilihan menu:\n");
		printf("1. Generate kata baru\n");
		printf("2. Simpan hasil generate kata\n");
		printf("3. Mulai permainan\n");
		printf("4. Tampilkan nama pemenang\n");
		printf("0. Keluar\n");
		printf("Pilihan: ");
		scanf("%d",&pilih);
		switch(pilih){
			case 1: generate(); break;
			case 2: simpan(); break;
			case 3: permainan(); break;
			case 4: pemenang(); break;
			case 0: keluar(); break;
			default: printf("Pilihan yang dimasukkan salah! Silahkan pilih nomor 0-4!\n"); break;
		}
		system("pause");
		system("cls");
	}while(pilih!=0);
	return 0;
}
