#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct ticket {
    char eventName[50];
    char nama[100];
    char ticketType[50];
    float ticketPrice;
    int jumlahTicket;
    float total;
    char tanggal[20];
};



typedef struct{
	char eventname[50];
	char tickettype[50];
	float ticketprice;
}menu;

menu pricelist[20]= {
{"Badminton", "TRIBUN BARAT", 50000}, {"Badminton", "TRIBUN SELATAN", 50000}, {"Badminton", "TRIBUN TIMUR", 50000},
{"Badminton", "VIP", 100000}, {"Badminton", "TRIBUN UTARA", 50000},

{"Konser Musik Klasik", "PRE-SALE", 100000}, 
{"Konser Musik Klasik", "VIP", 1000000}, {"Konser Musik Klasik", "GOLD", 600000}, {"Konser Musik Klasik", "SILVER", 400000},
{"Konser Musik Klasik", "BRONZE", 200000}, {"Konser Musik Klasik", "GREEN", 100000}, 

{"Sirkus", "VVIP", 150000}, {"Sirkus", "VIP", 100000}, { "Sirkus", "UTAMA", 75000},
{ "Sirkus", "SAMPING", 50000}, { "Sirkus", "BERDIRI", 25000}, 
};





//codingan jess kebawah------------------------------------------------------------------------------------------------------------------------
int sort_nama_pembeli();
int sort_nama_event();
void sort_data();
int penjualan_terbanyak();
int sort_total_transaksi();
int sort_tanggal();



struct tanggal{
	int dd;
	int mm;
	int yy;
};


//codingan jess keatas------------------------------------------------------------------------------------------------------------------------


int search_event(); 


// fungsi untuk display event yang ada
void displayEventOptions() {
	printf("========================================================================================================================");
    printf("\n\n\t\t\t\t\t\t Pilih Event:\n");
    printf("\n\n\t\t\t\t\t\t (1) Sirkus\n");
    printf("\n\n\t\t\t\t\t\t (2) Konser Musik Klasik\n");
    printf("\n\n\t\t\t\t\t\t (3) Badminton");
    printf("\n\n========================================================================================================================");
}

//fungsi display jenis tiket
void displayTicketOptions(const char *eventName) {
	printf("\n========================================================================================================================");
    printf("\n\n\t\t\t\t       Pilih Jenis Tiket untuk %s:\n", eventName);

    if (strcmp(eventName, "Sirkus") == 0) {
        printf("\n\t\t\t\t\t\t(1) VVIP");
        printf("\n\n\t\t\t\t\t\t(2) VIP");
        printf("\n\n\t\t\t\t\t\t(3) UTAMA");
        printf("\n\n\t\t\t\t\t\t(4) SAMPING");
        printf("\n\n\t\t\t\t\t\t(5) BERDIRI\n");
    } else if (strcmp(eventName, "Konser Musik Klasik") == 0) {
        printf("\n\t\t\t\t\t\t(1) PRE-SALE");
        printf("\n\n\t\t\t\t\t\t(2) VIP");
        printf("\n\n\t\t\t\t\t\t(3) GOLD");
        printf("\n\n\t\t\t\t\t\t(4) SILVER");
        printf("\n\n\t\t\t\t\t\t(5) BRONZE");
        printf("\n\n\t\t\t\t\t\t(6) GREEN\n");
    } else if (strcmp(eventName, "Badminton") == 0) {
        printf("\n\t\t\t\t\t\t(1) TRIBUN UTARA");
        printf("\n\n\t\t\t\t\t\t(2) TRIBUN BARAT");
        printf("\n\n\t\t\t\t\t\t(3) TRIBUN SELATAN");
        printf("\n\n\t\t\t\t\t\t(4) TRIBUN TIMUR");
        printf("\n\n\t\t\t\t\t\t(5) VIP\n");
    } else {
        printf("Event tidak valid.\n");
    }
    printf("\n========================================================================================================================");
}

void loading(){
	int i;
	system("COLOR 8F");
	for(i = 1; i <= 100; ++i){
		Sleep(5);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t         PROGRAM TIKET",i);
		printf("\n\n\n\t\t\t\t\t\t  LOADING %d%%",i);
		if(i==100)
		Sleep(1);
	}
	system("cls");
}

void loadingExit(){
	int i;
	system("COLOR 8F");
	for(i = 1; i <= 100; ++i){
		Sleep(5);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t       EXITING PROGRAM",i);
		printf("\n\n\n\t\t\t\t\t\t  LOADING %d%%",i);
		if(i==100)
		Sleep(1);
	}
	system("cls");
}

void nambahin(struct ticket sale) {
    FILE *file = fopen("sales.txt", "a");
    if (file == NULL) {
        printf("Gagal buka.\n");
        exit(1);
    }
    fprintf(file, "%s;%s;%s;%.2f;%d;%.2f;%s\n", sale.eventName, sale.nama, sale.ticketType, sale.ticketPrice, sale.jumlahTicket, sale.total, sale.tanggal);
    fclose(file);
}

void printData() {
    FILE *file = fopen("sales.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        exit(1);
    }

    printf("\nSEMUA DATA YANG TELAH DIMASUKKAN\n");
    printf("================================\n");

    struct ticket temp;
    while (fscanf(file, "%[^;];%[^;];%[^;];%f;%d;%f;%19[^\n]\n", temp.eventName, temp.nama, temp.ticketType, &temp.ticketPrice, &temp.jumlahTicket, &temp.total, temp.tanggal) == 7) {
        printf("Nama Event: %s\n", temp.eventName);
        printf("Nama Pelanggan: %s\n", temp.nama);
        printf("Jenis Tiket: %s\n", temp.ticketType);
        printf("Harga Tiket: %.2f\n", temp.ticketPrice);
        printf("Jumlah Tiket: %d\n", temp.jumlahTicket);
        printf("Total tagihan: %.2f\n", temp.total);
        printf("Tanggal transaksi: %s\n", temp.tanggal);
        printf("================================\n");
    }

    fclose(file);
}

int main() {
	//loading();
	system("COLOR 3F");
    int choice;
    int numberOfSales = 0;
    struct ticket *sales = NULL;

    do {
    	printf("========================================================================================================================");
        printf("\n\n\t\t\t\t\t\tMenu utama\n");
        printf("\n\n\t\t\t\t\t\t 1. Entry\n");
        printf("\n\n\t\t\t\t\t\t 2. Sort\n");
        printf("\n\n\t\t\t\t\t\t 3. Search\n");
        printf("\n\n\t\t\t\t\t\t 4. Print data yang sudah masuk\n");
        printf("\n\n\t\t\t\t\t\t 0. keluar\n");
        printf("\n\n========================================================================================================================");
        printf("\n\n\t\t\t\t\t         Pilihanmu: ");
        
        scanf(" %d", &choice);
		system("cls");
		
        switch (choice) {
            case 1:
            	do {
                    sales = (struct ticket *)realloc(sales, (numberOfSales + 1) * sizeof(struct ticket));

                    // Display available events
                    displayEventOptions();
                    printf("\n\n\n\n\t\t\t Pilih nomor event (0 untuk kembali ke menu utama): ");
                    int eventChoice;
                    scanf("%d", &eventChoice);
					system("cls");
					
                    // Check if user wants to go back to the main menu
                    if (eventChoice == 0) {
                        break;
                    }

                    // Validate eventChoice
                    if (eventChoice < 1 || eventChoice > 3) {
                        printf("Pilihan event tidak valid.\n");
                        continue;
                    }

                    // Set Event Name berdasarkan pilihan User
                    switch (eventChoice) {
                        case 1:
                            strcpy(sales[numberOfSales].eventName, "Sirkus");
                            break;
                        case 2:
                            strcpy(sales[numberOfSales].eventName, "Konser Musik Klasik");
                            break;
                        case 3:
                            strcpy(sales[numberOfSales].eventName, "Badminton");
                            break;
                    }

                    // Menunjukkan Ticket yang available berdasarkan nama event
                    displayTicketOptions(sales[numberOfSales].eventName);
                    printf("\n\n\t\t\t\t\t   Pilih nomor jenis tiket\n\t\t\t\t\t(0 untuk kembali ke menu utama):\n\t\t\t\t\t\t      ");
                    int ticketChoice;
                    scanf("%d", &ticketChoice);
                    system("cls");
					
                    // Ngecek jika user mau balik ke main menu
                    if (ticketChoice == 0) {
                        break;
                    }

                    // Validasi TicketChoice
                    if (ticketChoice < 1 || ticketChoice > 5) {
                        printf("Pilihan jenis tiket tidak valid.\n");
                        continue;
                    }

                    // Ngeset ticket type berdasarkan eventnya
                    switch (ticketChoice) {
                        case 1:
                        	if (strcmp(sales[numberOfSales].eventName, "Konser Musik Klasik") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "PRE-SALE");
                                sales[numberOfSales].ticketPrice = 100000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Sirkus") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "VVIP");
                                sales[numberOfSales].ticketPrice = 150000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Badminton") == 0) {
                            	strcpy(sales[numberOfSales].ticketType, "TRIBUN UTARA");
                            	sales[numberOfSales].ticketPrice = 50000;
							}
                            break;
                        case 2:
                        	if (strcmp(sales[numberOfSales].eventName, "Konser Musik Klasik") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "VIP");
                                sales[numberOfSales].ticketPrice = 1000000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Sirkus") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "VIP");
                                sales[numberOfSales].ticketPrice = 100000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Badminton") == 0) {
                            	strcpy(sales[numberOfSales].ticketType, "TRIBUN BARAT");
                            	sales[numberOfSales].ticketPrice = 50000;
							}
                            break;
                            
                        case 3:
                        	if (strcmp(sales[numberOfSales].eventName, "Konser Musik Klasik") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "GOLD");
                                sales[numberOfSales].ticketPrice = 600000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Sirkus") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "UTAMA");
                                sales[numberOfSales].ticketPrice = 75000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Badminton") == 0) {
                            	strcpy(sales[numberOfSales].ticketType, "TRIBUN SELATAN");
                            	sales[numberOfSales].ticketPrice = 50000;
							}
                            break;
                        case 4:
                        	if (strcmp(sales[numberOfSales].eventName, "Konser Musik Klasik") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "SILVER");
                                sales[numberOfSales].ticketPrice = 400000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Sirkus") == 0) {
                               	strcpy(sales[numberOfSales].ticketType, "SAMPING");
                               	sales[numberOfSales].ticketPrice = 50000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Badminton") == 0) {
                           	 	strcpy(sales[numberOfSales].ticketType, "TRIBUN TIMUR");
                           	 	sales[numberOfSales].ticketPrice = 50000;
							}
                            break;
                        case 5:
                        	if (strcmp(sales[numberOfSales].eventName, "Konser Musik Klasik") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "BRONZE");
                                sales[numberOfSales].ticketPrice = 200000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Sirkus") == 0) {
                               	strcpy(sales[numberOfSales].ticketType, "BERDIRI");
                               	sales[numberOfSales].ticketPrice = 25000;
                            } else if (strcmp(sales[numberOfSales].eventName, "Badminton") == 0) {
                           	 	strcpy(sales[numberOfSales].ticketType, "VIP");
                           	 	sales[numberOfSales].ticketPrice = 100000;
							}
                            break;
                        case 6:
                        	if (strcmp(sales[numberOfSales].eventName, "Konser Musik Klasik") == 0) {
                                strcpy(sales[numberOfSales].ticketType, "GREEN");
                                sales[numberOfSales].ticketPrice = 100000;
                            }
                    }
                    
                    // lanjutkan entry
                    printf("\n\n\n\n\t\t\t\t\tNama Pelanggan:\n\t\t\t\t\t");
                    scanf(" %[^\n]", sales[numberOfSales].nama);
                    /*
                    printf("Harga Tiket: ");
                    scanf("%f", &sales[numberOfSales].ticketPrice); 
					*/
                    printf("\n\t\t\t\t\tJumlah Tiket:\n\t\t\t\t\t"); 
                    scanf("%d", &sales[numberOfSales].jumlahTicket);
                    printf("\n\t\t\t\t\tTanggal transaksi (dd/mm/yy):\n\t\t\t\t\t");
                    scanf("%s", sales[numberOfSales].tanggal);
					system("cls");
                    // kalkulasi total
                    sales[numberOfSales].total = sales[numberOfSales].jumlahTicket * sales[numberOfSales].ticketPrice;
                    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tTotal Harga: Rp %.2f\n",sales[numberOfSales].total);

					Sleep(2000);
					nambahin(sales[numberOfSales]);
                    numberOfSales++;
					system("cls");
                    
					

                } while (1);

                break;
            
			case 2:
				sort_data();
				break;
			
			case 3:
				search_event();
				break;
            case 4:
                printData();
                break;
			case 0:
				loadingExit();
				return 0;
            default:
                printf("Invalid input!\n");
        }

    } while (choice != 0);

    free(sales); 
}




//codingan jess kebawah------------------------

void print_sort_menu(){
	printf("\n\n\t\t\t\t\tSilakan pilih sorting history transaksi berdasarkan:\n");
	printf("\n\t\t\t\t\t1. Nama event berdasarkan abjad\n");
	printf("\n\t\t\t\t\t2. Nama pembeli berdasarkan abjad\n");
	printf("\n\t\t\t\t\t3. Nama event berdasarkan tiket paling banyak terjual\n");
	printf("\n\t\t\t\t\t4. Total transaksi\n");
	printf("\n\t\t\t\t\t5. Tanggal\n");

	printf("\n\n\t\t\t\t\tAtau sorting JENIS TIKET berdasarkan:\n");
	printf("\n\t\t\t\t\t6. Harga\n");
	printf("\n\t\t\t\t\t7. Nama event berdasarkan abjad\n");
	printf("\n\t\t\t\t\t8. Exit\n");
	
		
	printf("\n\t\t\t\t\tMasukkan pilihan anda >> ");
}

void sort_harga_tiket(){
	int j, xuan, i;
	
	printf("\n\t\t\t\t\tSort ascending(1) or descending(2)?\n\t\t\t\t\tYour choice>> ");
	scanf("%d", &xuan);
	system("cls");
	int n=16;
	
	menu temp;
	
	if (xuan==1){
			
			for (j=0; j<n-1; j++){
				for (i=0; i<n-1; i++){
					
					if (pricelist[i].ticketprice> pricelist[i+1].ticketprice){
						temp=pricelist[i+1];
						pricelist[i+1]= pricelist[i];
						pricelist[i]=temp;
					}
				
				}
			}
	
			for (i=0; i<n; i++){
			 	printf("%-30s%-20s%-15.2f\n", pricelist[i].eventname, pricelist[i].tickettype, pricelist[i].ticketprice);
			}
	}
	

	else if (xuan==2){
			
			for (j=0; j<n-1; j++){
				for (i=0; i<n-1; i++){
					
					if (pricelist[i].ticketprice<pricelist[i+1].ticketprice){
						temp=pricelist[i+1];
						pricelist[i+1]= pricelist[i];
						pricelist[i]=temp;
					}
				
				}
			}
	
			for (i=0; i<n; i++){
			 	printf("%-30s%-20s%-15.2f\n", pricelist[i].eventname, pricelist[i].tickettype, pricelist[i].ticketprice);
			}
	}
	
	
	else printf("Invalid input!\n");
	
}


void sort_nama_tiket(){
		int j; 
		int n=16;
		for (j=0; j<n; j++){
			printf("%-30s%-20s%-15.2f\n", pricelist[j].eventname, pricelist[j].tickettype, pricelist[j].ticketprice);
		}
	
}



void sort_data(){
	int xuanze;
	do{
		print_sort_menu();
		scanf("%d", &xuanze);
		system("cls");
		switch(xuanze){
			case 1:{
				sort_nama_event();
				break;
			}
			
			case 2: {
				sort_nama_pembeli();
				break;
			}
			case 3:{
				penjualan_terbanyak();
				break;
			} 
			
			case 4: {
				sort_total_transaksi();
				break;
			}
			case 5:{
				sort_tanggal();
				break;	
			}
			
			case 6:{
				sort_harga_tiket();
				break;
			}
			
			case 7:{
				sort_nama_tiket();
				break;
			}
		}
		
		
	}while (xuanze!=8);

} 


int sort_nama_event(){
	int xuan;
	printf("\n\t\t\t\t\tAscending (1) or Descending(2)?");
	printf("\n\t\t\t\t\tChoice>> ");
	scanf("%d", &xuan);
	system("cls");
	struct ticket temp;
	struct ticket mochi[5000];
	FILE *fp;
	fp= fopen("sales.txt", "r");
	
	if (fp== NULL) {
		printf("Can't open file\n"); 
		return -1;
	}
	
	int n=0;
	while (!feof(fp) && n<=5000){
		fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
               mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
			   &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
			   &mochi[n].total, mochi[n].tanggal);
               n++;
		}
		int i, j;
		
		
	if (xuan==1){
			for (j=0; j<n-1; j++){
				for (i=0; i<n-1; i++){
					if (strcmpi(mochi[i].eventName, mochi[i+1].eventName)>0){
							temp=mochi[i+1];
							mochi[i+1]= mochi[i];
							mochi[i]=temp;
					}
				}
			}

   		
			for (i=0; i<n; i++){
			 	printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
               			mochi[i].eventName, mochi[i].nama, mochi[i].ticketType, 
						mochi[i].ticketPrice, mochi[i].jumlahTicket, mochi[i].total, 
						mochi[i].tanggal);
			}
	}	
	
		
	else if (xuan==2){
			for (j=0; j<n-1; j++){
				for (i=0; i<n-1; i++){
					if (strcmpi(mochi[i].eventName, mochi[i+1].eventName)<0){
							temp=mochi[i+1];
							mochi[i+1]= mochi[i];
							mochi[i]=temp;
					}
				}
			}

   		
			for (i=0; i<n; i++){
			 	printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
               			mochi[i].eventName, mochi[i].nama, mochi[i].ticketType, 
						mochi[i].ticketPrice, mochi[i].jumlahTicket, mochi[i].total, 
						mochi[i].tanggal);
			}
	}	


	else printf("Invalid input!\n");
	
	return 0;
}


int sort_nama_pembeli(){
	int xuan;
	printf("\n\t\t\t\t\tAscending (1) or Descending(2)?");
	printf("\n\t\t\t\t\tChoice>>  ");
	scanf("%d", &xuan);
	system("cls");
	struct ticket temp;
	struct ticket mochi[5000];
	FILE *fp;
	fp= fopen("sales.txt", "r");
	
	if (fp== NULL) {
		printf("Can't open file\n"); 
		return -1;
	}
	
	int n=0;
	while (!feof(fp) && n<=5000){
		fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
               mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
			   &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
			   &mochi[n].total, mochi[n].tanggal);
               n++;
		}
		int i, j;
		
		
	if (xuan==1){
			for (j=0; j<n-1; j++){
				for (i=0; i<n-1; i++){
					if (strcmpi(mochi[i].nama, mochi[i+1].nama)>0){
							temp=mochi[i+1];
							mochi[i+1]= mochi[i];
							mochi[i]=temp;
					}
				}
			}

   		
			for (i=0; i<n; i++){
			 	printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
               			mochi[i].eventName, mochi[i].nama, mochi[i].ticketType, 
						mochi[i].ticketPrice, mochi[i].jumlahTicket, mochi[i].total, 
						mochi[i].tanggal);
			}
	}	
	
		
	else if (xuan==2){
			for (j=0; j<n-1; j++){
				for (i=0; i<n-1; i++){
					if (strcmpi(mochi[i].nama, mochi[i+1].nama)<0){
							temp=mochi[i+1];
							mochi[i+1]= mochi[i];
							mochi[i]=temp;
					}
				}
			}

   		
			for (i=0; i<n; i++){
			 	printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
               			mochi[i].eventName, mochi[i].nama, mochi[i].ticketType, 
						mochi[i].ticketPrice, mochi[i].jumlahTicket, mochi[i].total, 
						mochi[i].tanggal);
			}
	}	


	else printf("Invalid input!\n");
	
	return 0;
}




int penjualan_terbanyak(){
	FILE *fp;
	fp= fopen("sales.txt", "r");
	
	if (fp== NULL) {
		printf("Can't open file\n"); 
		return -1;
	}
	int counter_konser=0;
	int counter_sirkus=0;
	int counter_badmin=0;

    struct ticket mochi[5000];
	int n=0;
	while (!feof(fp) && n<=5000){
		fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
               mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
			   &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
			   &mochi[n].total, mochi[n].tanggal);
			
			   
               if (strcmpi(mochi[n].eventName, "sirkus")==0){
               		counter_sirkus++;
			   }
			   else if (strcmpi(mochi[n].eventName, "konser musik klasik")==0){
               		counter_konser++;
			   }
			   else if (strcmpi(mochi[n].eventName, "badminton")==0){
               		counter_badmin++;
			   }
			   n++;
	}
    printf("n=%d\n", n);
	
	if (counter_konser>= counter_sirkus && counter_konser >=counter_badmin && counter_sirkus>=counter_badmin){
		printf("Tiket dengan penjualan terbanyak:\n1. Konser Musik Klasik= %d\n2. Sirkus= %d\n3. Badminton= %d\n", counter_konser, counter_sirkus, counter_badmin);
	}
	else if (counter_konser>= counter_sirkus && counter_konser >=counter_badmin && counter_badmin>=counter_sirkus){
		printf("Tiket dengan penjualan terbanyak:\n1. Konser Musik Klasik= %d\n2. Badminton= %d\n3. Sirkus= %d\n", counter_konser, counter_badmin, counter_sirkus);
	}
	else if (counter_sirkus>= counter_konser && counter_sirkus >=counter_badmin && counter_konser>=counter_badmin){
		printf("Tiket dengan penjualan terbanyak:\n1. Sirkus= %d\n2. Konser Musik Klasik= %d\n3. Badminton= %d\n", counter_sirkus, counter_konser, counter_badmin);
	}
	else if (counter_sirkus>= counter_konser && counter_sirkus >=counter_badmin && counter_badmin>=counter_konser){
		printf("Tiket dengan penjualan terbanyak:\n1. Sirkus= %d\n2. Badminton= %d\n3. Konser Musik Klasik= %d\n", counter_sirkus, counter_badmin, counter_konser);
	}
	else if (counter_badmin>=counter_konser && counter_badmin >=counter_sirkus && counter_konser>=counter_sirkus){
		printf("Tiket dengan penjualan terbanyak:\n1. Badminton= %d\n2. Konser= %d\n3. Sirkus= %d\n", counter_badmin, counter_konser, counter_sirkus);
	}
	else if (counter_badmin>= counter_konser && counter_badmin >=counter_sirkus && counter_sirkus>=counter_konser){
		printf("Tiket dengan penjualan terbanyak:\n1. Badminton= %d\n2. Sirkus= %d\n3. Konser Musik Klasik= %d\n", counter_badmin, counter_sirkus, counter_konser);
	}
	
	
fclose(fp);

printf("\n\n\t\t\t\t\tBerikut detail history pesanan:\n");
	
	//kalau maxnya itu sirkus
if (counter_sirkus>=counter_konser && counter_sirkus>=counter_badmin){
 		if (counter_konser>=counter_badmin){
              n=0;   
              
            FILE *fp;
			fp= fopen("sales.txt", "r"); 
			
 			while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	  mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
			 	  &mochi[n].total, mochi[n].tanggal);
			 	
            
              	  if (strcmpi(mochi[n].eventName, "sirkus")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 									mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 									mochi[n].tanggal);
 			   		}
                  n++;   
 			   }
			   	fclose(fp);
				   
				   	
			   n=0;
			   
			   	//FILE *fp;
				fp= fopen("sales.txt", "r");
			   
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
		
			   
              	  if (strcmpi(mochi[n].eventName, "konser musik klasik")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			   		}
                     n++;
 			   }
 			   fclose(fp);
 			   
 			   n=0;
 			   	//FILE *fp;
				fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "badminton")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			  		 }
                  n++; 
 				}
 				
 				fclose(fp);
 	}
			//	
 		else if (counter_badmin>=counter_konser){
             n=0;
             fp= fopen("sales.txt", "r");
 			while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "sirkus")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			   	}	   
                 n++;
 			}
 			fclose(fp);

             n=0;
             fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "badminton")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			  		 }
                      n++;
 				}
 				fclose(fp);
 				
 			   n=0;
 			   fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "konser musik klasik")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			 		}
                     n++;
 				}
				fclose(fp);
			}
	}
	
	
	//
		
 		//kalau maxnya itu konser
else if (counter_konser>=counter_sirkus && counter_konser>=counter_badmin){
 		if (counter_sirkus>=counter_badmin){
             n=0;
             fp= fopen("sales.txt", "r");
 			while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	  	mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  	&mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  	&mochi[n].total, mochi[n].tanggal);
			   
              	  	if (strcmpi(mochi[n].eventName, "konser")==0){
                				printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                						mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 									mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 									mochi[n].tanggal);
 			 	  }
                   n++;
             }
             fclose(fp);
 			   n=0;
 			   fp= fopen("sales.txt", "r");
 			  	while (!feof(fp) && n<=5000){
 					fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   	mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  	&mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "sirkus")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			  		 }
                     n++;
                }fclose(fp);
			   
                n=0;
                fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "badmin")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			 	  }
                n++;
			   
 			}
 			fclose(fp);
 		}
 		
 		
 		else if (counter_badmin>=counter_sirkus){
             n=0;
             fp= fopen("sales.txt", "r");
 			while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "konser")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			   	}	   
                 n++;
 			} fclose(fp);

                 n=0;
                 fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "badmin")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			  		 }

                      n++;
 				} fclose (fp);
			   
                n=0;
				fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "sirkus")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			 		}
                     n++;
 				}
 				fclose(fp);
			}


}


 //kalau maxnya itu badmin
 else if (counter_badmin>=counter_sirkus && counter_badmin>=counter_konser){
 		if (counter_sirkus>=counter_konser){
             n=0;
             fp= fopen("sales.txt", "r");
 			while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "badmin")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			   	}
                n++;
             }
             fclose(fp);
             
             n=0;
             fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "sirkus")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			   	}
                 n++;
                
 			   }
 			   fclose (fp);
 			   
 			   n=0;
 			   fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "konser")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			  	 }
                n++;
			   
 				}
 				fclose(fp);
 			}
 		
 		
 		else if (counter_konser>=counter_sirkus){
             n=0;
             fp= fopen("sales.txt", "r");
 			while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "badmin")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			   	}	   
                 n++;
 			}
 			fclose(fp);
             n=0;
             fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "konser")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			  		 }
                      n++;
 				} fclose (fp);			   
                n=0;
                fp= fopen("sales.txt", "r");
 			   	while (!feof(fp) && n<=5000){
 				fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
             	   mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 			 	  &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
 			 	  &mochi[n].total, mochi[n].tanggal);
			   
              	  if (strcmpi(mochi[n].eventName, "sirkus")==0){
                			printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                					mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
 								mochi[n].ticketPrice, mochi[n].jumlahTicket, mochi[n].total, 
 								mochi[n].tanggal);
 			 		}
                     n++;
 				} fclose (fp);

			}
	
}

 
                
    
 }  
   
   
int sort_total_transaksi(){
	FILE *fp;
	fp= fopen("sales.txt", "r");
	
	if (fp== NULL) {
		printf("Can't open file\n"); 
		return -1;
	}
		
	int i,j,k,n,xuan;
		
	struct ticket temp;
	struct ticket matcha[5000];
	
		n=0;
	while (!feof(fp) && n<=5000){
		fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
               matcha[n].eventName, matcha[n].nama, matcha[n].ticketType, 
			   &matcha[n].ticketPrice, &matcha[n].jumlahTicket, 
			   &matcha[n].total, matcha[n].tanggal);
			n++;
	}
	
		
	printf("\n\t\t\t\t\tSort ascending(1) or descending(2)?\n\t\t\t\t\tYour choice>> ");
	scanf("%d", &xuan);
	system("cls");
					
	if (xuan==1){
			
			for (j=0; j<n-1; j++){
				for (i=0; i<n-1; i++){
					
					if (matcha[i].total> matcha[i+1].total){
						temp=matcha[i+1];
						matcha[i+1]= matcha[i];
						matcha[i]=temp;
					}
				
				}
			}
	
			for (i=0; i<n; i++){
			 	printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                		matcha[i].eventName, matcha[i].nama, matcha[i].ticketType, 
 						matcha[i].ticketPrice, matcha[i].jumlahTicket, matcha[i].total, 
 						matcha[i].tanggal);
			}
	}
	
	else if (xuan==2){
			
			for (j=0; j<n-1; j++){
				for (i=0; i<n-1; i++){
					
					if (matcha[i].total< matcha[i+1].total){
						temp=matcha[i+1];
						matcha[i+1]= matcha[i];
						matcha[i]=temp;
					}
				
				}
			}
	
			for (i=0; i<n; i++){
			 	printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                		matcha[i].eventName, matcha[i].nama, matcha[i].ticketType, 
 						matcha[i].ticketPrice, matcha[i].jumlahTicket, matcha[i].total, 
 						matcha[i].tanggal);
			}
	}
	
	else printf("Invalid input!\n");
	
	fclose(fp);
	return 0;
}    



                 
int sort_tanggal(){
	struct tanggal date[5000];
	struct ticket mochi[5000];
	struct ticket temp;
	struct tanggal datetemp;
	FILE *fp;
	fp= fopen("sales.txt", "r");
	int xuan;
	
	int n=0;
	int i, j;
	while (!feof(fp) && n<=5000){
		fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%d/%d/%d\n",
               mochi[n].eventName, mochi[n].nama, mochi[n].ticketType, 
			   &mochi[n].ticketPrice, &mochi[n].jumlahTicket, 
			   &mochi[n].total, &date[n].dd, &date[n].mm, &date[n].yy);
               n++;
		}
		
		
printf("\n\t\t\t\t\tSort ascending (1) or descending (2)?");
printf("\n\t\t\t\t\tYour choice>>");
scanf("%d", &xuan);		
system("cls");

if (xuan==1){		
for (j=0; j<n-1; j++){
	for (i=0; i<n-1; i++){
		if (date[i].yy>date[i+1].yy){
			temp= mochi[i+1];
			mochi[i+1]=mochi[i];
			mochi[i]= temp;
			
			datetemp= date[i+1];
			date[i+1]= date[i];
			date[i]=datetemp;
		}
		
		else if (date[i].yy == date[i+1].yy){
			if (date[i].mm>date[i+1].mm){
				temp= mochi[i+1];
				mochi[i+1]=mochi[i];
				mochi[i]= temp;
				
				datetemp= date[i+1];
				date[i+1]= date[i];
				date[i]=datetemp;
			}
			else if (date[i].mm==date[i+1].mm){
				if (date[i].dd>date[i+1].dd){
					temp= mochi[i+1];
					mochi[i+1]=mochi[i];
					mochi[i]= temp;
					
					datetemp= date[i+1];
					date[i+1]= date[i];
					date[i]=datetemp;
				}
			}
			
		}
		
	}
}			

for (i=0; i<n; i++){
	printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%d/%d/%d\n",
    mochi[i].eventName, mochi[i].nama, mochi[i].ticketType, 
 	mochi[i].ticketPrice, mochi[i].jumlahTicket, mochi[i].total, 
 	date[i].dd, date[i].mm, date[i].yy);
}

}


else if (xuan==2){
			
for (j=0; j<n-1; j++){
	for (i=0; i<n-1; i++){
		if (date[i].yy<date[i+1].yy){
			temp= mochi[i+1];
			mochi[i+1]=mochi[i];
			mochi[i]= temp;
			
			datetemp= date[i+1];
			date[i+1]= date[i];
			date[i]=datetemp;
		}
		
		else if (date[i].yy == date[i+1].yy){
			if (date[i].mm<date[i+1].mm){
				temp= mochi[i+1];
				mochi[i+1]=mochi[i];
				mochi[i]= temp;
				
				datetemp= date[i+1];
				date[i+1]= date[i];
				date[i]=datetemp;
			}
			else if (date[i].mm==date[i+1].mm){
				if (date[i].dd<date[i+1].dd){
					temp= mochi[i+1];
					mochi[i+1]=mochi[i];
					mochi[i]= temp;
					
					datetemp= date[i+1];
					date[i+1]= date[i];
					date[i]=datetemp;
				}
			}
			
		}
		
	}
}			

for (i=0; i<n; i++){
	printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%d/%d/%d\n",
    mochi[i].eventName, mochi[i].nama, mochi[i].ticketType, 
 	mochi[i].ticketPrice, mochi[i].jumlahTicket, mochi[i].total, 
 	date[i].dd, date[i].mm, date[i].yy);
}

}

else printf("Invalid input!\n");

	
	fclose(fp);
	return 0;
}

//------------------------codingan jess keatas-----------------------------------------------------



//-------------------codingan haidar kebawah--------------------------------------------------

int search_event(){
    FILE *fp;
    fp= fopen("sales.txt", "r");

    if (fp== NULL) {
        printf("Tidak bisa membuka file!\n"); 
        return -1;
    }
char search_option[20];
    int i,j,k,n,found;
    struct ticket matcha[5000];
do{


	
    printf("\n\n\t\t\t\t\tPilih opsi pencarian:\n\n\t\t\t\t\t1. Nama Event\n\n\t\t\t\t\t2. Nama pembeli\n\n\t\t\t\t\t3. Tanggal Pembelian\n\n\t\t\t\t\t4. Search tiket berdasarkan budget Anda\n\n\t\t\t\t\t5. Exit\n");
    printf("\n\n\t\t\t\t\tMasukkan pilihan anda:\n\t\t\t\t\t          ");
	scanf("%s", search_option); getchar();
	system("cls");

	if(strcmp(search_option, "1") == 0){
    char eventName[50];
    printf("\n\n\n\n\n\t\t\t\t\tMasukkan nama event: \n\t\t\t\t\t");
    scanf(" %[^\n]", eventName);
    system("cls");

    n=0;
    while (!feof(fp) && n<=5000){
        fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
               matcha[n].eventName, matcha[n].nama, matcha[n].ticketType, 
               &matcha[n].ticketPrice, &matcha[n].jumlahTicket, 
               &matcha[n].total, matcha[n].tanggal);
        n++;
    }

    found = 0;
    for (i=0; i<n; i++){
        if (strcasecmp(matcha[i].eventName, eventName) == 0){
            printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                   matcha[i].eventName, matcha[i].nama, matcha[i].ticketType, 
                   matcha[i].ticketPrice, matcha[i].jumlahTicket, matcha[i].total, 
                   matcha[i].tanggal);
            found = 1;
        }
    }

    if (!found) printf("Nama event tidak ditemukan.\n");
	}
	else if(strcmp(search_option, "2") == 0){
        char customerName[50];
        printf("\n\t\t\t\t\tMasukkan nama pembeli: \n\t\t\t\t\t");
        scanf(" %[^\n]", customerName);
        system("cls");

        n=0;
        while (!feof(fp) && n<=5000){
            fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
                   matcha[n].eventName, matcha[n].nama, matcha[n].ticketType, 
                   &matcha[n].ticketPrice, &matcha[n].jumlahTicket, 
                   &matcha[n].total, matcha[n].tanggal);
            n++;
        }

        found = 0;
        for (i=0; i<n; i++){
            if (strcasecmp(matcha[i].nama, customerName) == 0){
                printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                       matcha[i].eventName, matcha[i].nama, matcha[i].ticketType, 
                       matcha[i].ticketPrice, matcha[i].jumlahTicket, matcha[i].total, 
                       matcha[i].tanggal);
                found = 1;
            }
        }

        if (!found) printf("Nama pembeli tidak ditemukan.\n");
    }
    else if(strcmp(search_option, "3") == 0){
        char search_date[50];
        printf("\n\t\t\t\t\tMasukkan tanggal pembelian: \n\t\t\t\t\t");
        scanf("%[^\n]", search_date);
        system("cls");

        n=0;
        while (!feof(fp) && n<=5000){
            fscanf(fp, "%[^;];%[^;];%[^;];%f;%d;%f;%[^\n]\n",
                   matcha[n].eventName, matcha[n].nama, matcha[n].ticketType, 
                   &matcha[n].ticketPrice, &matcha[n].jumlahTicket, 
                   &matcha[n].total, matcha[n].tanggal);
            n++;
        }

        found = 0;
        for (i=0; i<n; i++){
            if (strcasecmp(matcha[i].tanggal, search_date) == 0){
                printf("%-30s%-15s%-15s%-15.2f%-15d%-15.2f%-15s\n",
                       matcha[i].eventName, matcha[i].nama, matcha[i].ticketType, 
                       matcha[i].ticketPrice, matcha[i].jumlahTicket, matcha[i].total, 
                       matcha[i].tanggal);
                found = 1;
            }
        }

        if (found==0) printf("Tanggal tidak ditemukan.\n");
	}
	
	
	 else if(strcmp(search_option, "4") == 0){
        int budget;
        printf("\n\t\t\t\t\tMasukkan budget anda>> ");
        scanf("%d", &budget);
        system("cls");
        
        n=0;
        int i;
        int found=0;
        
        for (i=0; i<16; i++){
        	if(pricelist[i].ticketprice<=budget){
        		printf("%-30s%-20s%-15.2f\n", pricelist[i].eventname, pricelist[i].tickettype, pricelist[i].ticketprice);
        		found=1;
			}
		}
		if (found==1){
			printf("\nDiatas adalah tiket yang sesuai dengan budget Anda.\n");
		}
		
		if (found==0){
			printf("Tidak ditemukan\n\n\n");
		}	
			
  }
	

} while  (strcmp(search_option, "5")!=0);
    fclose(fp);
    return 0;
}

//---------------------------------------------------codingan haidar keatas--------------------------------------------------
