#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_ROWS 4000
#define MAX_COLS 8

typedef struct {
    char location[101];
    char location2[101];
    int price;
    int rooms;
    int bathroom;
    int carpark;
    char type[101];
    char furnish[101];
} DATA;

int readCSV(DATA data[], const char *filename);
int isAlpha(const char *str);
void removeNull(char *str);

void displayData(DATA data[], int totalRow);
void selectRow(DATA data[], int totalRow, const char *column, const char *query);
void sortBy(DATA data[], int totalRow, const char *column, const char *order);
void exportData(DATA data[], int totalRow, const char *filename);

int main() {
    DATA data[MAX_ROWS];
    int totalRows = readCSV(data, "file.csv");

    if (totalRows == -1) {
        printf("file not found.\n");
        exit(1);
    }

    int user_input;
    char column[50], query[50], order[4], newFile[50];

    do {
        system("cls");

        printf("What do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\nYour user_input: ");
        scanf("%d", &user_input);

        switch (user_input) {
            case 1:
                printf("Number of rows: ");
                int totalRow;
                scanf("%d", &totalRow);
                displayData(data, totalRow);
                break;
            case 2:
                printf("Choose column: ");
                scanf("%s", column);
                printf("What data do you want to find? ");
                scanf("%s", query);
                selectRow(data, totalRows, column, query);
                break;
            case 3:
                printf("Choose column: ");
                scanf("%s", column);
                printf("ascending or descending ? ");
                scanf("%s", order);
                sortBy(data, totalRows, column, order);
                break;
            case 4:
                printf("File name: ");
                scanf(" %s", newFile);
                exportData(data, totalRows, newFile);
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Invalid user_input.\n");
                break;
        }

        if (user_input != 5) {
            printf("\nPress any key to continue...");
            getch();
        }

    } while (user_input != 5);
    return 0;
}

void displayData(DATA data[], int totalRow) {
    printf("\n%-25s%-25s%-15s%-12s%-15s%-15s%-25s%s\n", "Location", "Location 2", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");

    for (int i = 0; i < totalRow && i < MAX_ROWS; i++) {
        printf("%-25s%-25s%-15d%-12d%-15d%-15d%-25s%s\n",
               data[i].location, data[i].location2, data[i].price,
               data[i].rooms, data[i].bathroom, data[i].carpark,
               data[i].type, data[i].furnish);
    }
}

void selectRow(DATA data[], int totalRow, const char *column, const char *query) {
    int found = 0;
    for (int i = 0; i < totalRow && i < MAX_ROWS; i++) {
        if ((strstr(data[i].location, query) && strcmp(column, "Location") == 0) ||
            (strstr(data[i].location2, query) && strcmp(column, "Location 2") == 0) ||
            (strstr(data[i].type, query) && strcmp(column, "Type") == 0) ||
            (strcmp(column, "Price") == 0 && data[i].price == atoi(query)) ||
            (strcmp(column, "Rooms") == 0 && data[i].rooms == atoi(query)) ||
            (strcmp(column, "Bathroom") == 0 && data[i].bathroom == atoi(query)) ||
            (strcmp(column, "Carpark") == 0 && data[i].carpark == atoi(query)) ||
            (strstr(data[i].furnish, query) && strcmp(column, "Furnish") == 0)) {

            if (!found) {
                printf("Data found. Detail of data:\n");
                printf("%-25s%-25s%-15s%-12s%-15s%-15s%-25s%s\n", "Location", "Location 2", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                found = 1;
            }

            printf("%-25s%-25s%-15d%-12d%-15d%-15d%-25s%s\n",
                   data[i].location, data[i].location2, data[i].price,
                   data[i].rooms, data[i].bathroom, data[i].carpark,
                   data[i].type, data[i].furnish);
        }
    }

    if (!found) {
        printf("Data not found!\n");
    }
    getch();
}

void sortBy(DATA data[], int totalRow, const char *column, const char *order) {
    int i, j;
    DATA temp;

    for (i = 0; i < totalRow - 1; i++) {
        for (j = 0; j < totalRow - i - 1; j++) {
            int compareResult;

            if (strcmp(column, "Location") == 0) {
                compareResult = strcmp(data[j].location, data[j + 1].location);
            } else if (strcmp(column, "Location 2") == 0) {
                compareResult = strcmp(data[j].location2, data[j + 1].location2);
            } else if (strcmp(column, "Price") == 0) {
                compareResult = data[j].price - data[j + 1].price;
            } else if (strcmp(column, "Rooms") == 0) {
                compareResult = data[j].rooms - data[j + 1].rooms;
            } else if (strcmp(column, "Bathroom") == 0) {
                compareResult = data[j].bathroom - data[j + 1].bathroom;
            } else if (strcmp(column, "Carpark") == 0) {
                compareResult = data[j].carpark - data[j + 1].carpark;
            } else if (strcmp(column, "Type") == 0) {
                compareResult = strcmp(data[j].type, data[j + 1].type);
            } else if (strcmp(column, "Furnish") == 0) {
                compareResult = strcmp(data[j].furnish, data[j + 1].furnish);
            } else {
                printf("Invalid column\n");
                return;
            }

            if ((strcmp(order, "asc") == 0 && compareResult > 0) ||
                (strcmp(order, "desc") == 0 && compareResult < 0)) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("Enter Data:\n");
    displayData(data, 10);
}

int readCSV(DATA data[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char line[500];
    int row = 0;

    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return -1;
    }

    while (fgets(line, sizeof(line), file) != NULL && row < MAX_ROWS) {
        sscanf(line, "%49[^,],%49[^,],%d,%d,%d,%d,%49[^,],%49[^\n]",
               data[row].location, data[row].location2, &data[row].price,
               &data[row].rooms, &data[row].bathroom, &data[row].carpark,
               data[row].type, data[row].furnish);
        row++;
    }

    fclose(file);
    return row;
}

int isAlpha(const char *str) {
    while (*str) {
        if (!isalnum(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

void removeNull(char *str) {
    while (*str) {
        if (*str == ' ') {
            *str = '_';
        }
        str++;
    }
}

void exportData(DATA data[], int totalRow, const char *filename) {

    if (strchr(filename, ' ') != NULL) {
        printf("Invalid filename. Please avoid spaces.\n");
        return;
    }

    char sanitizedFilename[50];
    strcpy(sanitizedFilename, filename);
    removeNull(sanitizedFilename);

    if (!isAlpha(sanitizedFilename)) {
        printf("Invalid filename. Please use only alphanumeric characters.\n");
        return;
    }

    char outputFilename[50];
    snprintf(outputFilename, sizeof(outputFilename), "%s.csv", sanitizedFilename);

    FILE *checkFile = fopen(outputFilename, "r");
    if (checkFile != NULL) {
        fclose(checkFile);
        printf("File '%s' already exists.\n", outputFilename);
        return;
    }

    FILE *file = fopen(outputFilename, "w");
    if (file == NULL) {
        printf("Error creating the file.\n");
        return;
    }

    fprintf(file, "Location,Location 2,Price,Rooms,Bathroom,Carpark,Type,Furnish\n");
    for (int i = 0; i < totalRow && i < MAX_ROWS; i++) {
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n",
               data[i].location, data[i].location2, data[i].price,
               data[i].rooms, data[i].bathroom, data[i].carpark,
               data[i].type, data[i].furnish);
    }

    fclose(file);
    printf("Data successfully written to file %s!\n", outputFilename);
}

