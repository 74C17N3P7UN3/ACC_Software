// ------------------------------------------------- Librerie ------------------------------------------------- //
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// ------------------------------------------------- Costanti ------------------------------------------------- //
#define DimStr 101
#define DimUtente 20
#define DimNome 14
#define DimMail 28
#define DimType 10
#define DimNomeProd 20
#define DimCat 17
#define DIM 200
#define MAX 750
#define MIN 350

// --------------------------------------------- Testata Funzioni --------------------------------------------- //
void center(char s[], int i);
void convertArr(char s[][DimStr], int pos, int lower);
void convertStr(char s[]);
void initialize(int *utentiDim, char utentiNome[][DimStr], char utentiPwd[][DimStr], int *contattiDim, char contattiNome[][DimStr], char contattiMail[][DimStr], int contattiType[], int *categorieDim, char categorie[][DimStr], int *magazzinoDim, char magazzinoNome[][DimStr], int magazzinoCodice[], char magazzinoCat[][DimStr], int magazzinoQta[], char compravendita[][DimStr], float prezzi[], float *portfolio);
void loading(void);
bool login(char utenti[][DimStr], char pwd[][DimStr], int dim, int j);
void pressEnter(int newLine, int skipBuffer);

void utentiAggiungi(char nome[][DimStr], char pwd[][DimStr], int *dim);
void utentiElimina(char nome[][DimStr], char pwd[][DimStr], int *dim);
void utentiSort(char nome[][DimStr], char pwd[][DimStr], int dim);
void portfolioModifica(float *portfolio);
bool dangerZone(void);

void contattiCrea(char nome[][DimStr], char mail[][DimStr], int type[], char prod[][DimStr], float prezzo[], int *dim, char magNome[][DimStr], int magCod[], char magCat[][DimStr], char categoria[][DimStr], int magQta[], int *dimMag, int *dimCat);
void contattiElimina(char nome[][DimStr], char mail[][DimStr], int type[], char prod[][DimStr], float prezzo[], int *dim);
void contattiCerca(char nome[][DimStr], char mail[][DimStr], int type[], int dim);
void contattiClienti(char nome[][DimStr], char mail[][DimStr], int type[], int dim);
void contattiFornitori(char nome[][DimStr], char mail[][DimStr], int type[], int dim);
void contattiTutto(char nome[][DimStr], char mail[][DimStr], int type[], int dim);
void contattiSort(char nome[][DimStr], char mail[][DimStr], int type[], char prod[][DimStr], float prezzo[], int dim);

void categorieAggiungi(char categoria[][DimStr], int *dim);
void categorieVisualizza(char categoria[][DimStr], int dim);
void categorieSort(char categoria[][DimStr], int dim);

void magazzinoAggiungi(char nome[][DimStr], int codice[], char cat[][DimStr], char categoria[][DimStr], int qta[], int *dim, int *dimCat, int skipNome);
void magazzinoTrovaNome(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim);
void magazzinoTrovaCodice(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim);
void magazzinoTrovaCategoria(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim);
void magazzinoVisualizza(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim);
void magazzinoSortNome(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim);
void magazzinoSortCrescente(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim);
void magazzinoSortDecrescente(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim);

void carico(char nome[][DimStr], int type[], char prod[][DimStr], float prezzo[], float *portfolio, int dim, char magNome[][DimStr], int magCod[], char magCat[][DimStr], char categoria[][DimStr], int magQta[], int *dimMag, int *dimCat);
void scarico(char nome[][DimStr], int type[], char prod[][DimStr], float prezzo[], float *portfolio, int dim, char magNome[][DimStr], int magQta[], int dimMag);

// --------------------------------------------------- Main --------------------------------------------------- //
int main(void)
{
    // Utenti
    int utentiDim = 0;
    char utentiNome[DIM][DimStr];
    char utentiPwd[DIM][DimStr];
    // Contatti
    int contattiDim = 0;
    char contattiNome[DIM][DimStr];
    char contattiMail[DIM][DimStr];
    int contattiType[DIM] = {0};
    // Categorie
    int categorieDim = 0;
    char categorie[DIM][DimStr];
    // Magazzino
    int magazzinoDim = 0;
    char magazzinoNome[DIM][DimStr];
    int magazzinoCodice[DIM] = {0};
    char magazzinoCat[DIM][DimStr];
    int magazzinoQta[DIM] = {0};
    // Prezzi
    char compravendita[DIM][DimStr];
    float prezzi[DIM] = {0};
    float portfolio = 0;
    // Generico
    int i, menu0, menu1, menu2, menu3;
    srand(time(NULL));

    // Inizializzazione del programma
    initialize(&utentiDim, utentiNome, utentiPwd, &contattiDim, contattiNome, contattiMail, contattiType, &categorieDim, categorie, &magazzinoDim, magazzinoNome, magazzinoCodice, magazzinoCat, magazzinoQta, compravendita, prezzi, &portfolio);
    do
    {
        // -------------------------------------------- Login Menu -------------------------------------------- //
        system("cls");
        printf("----- ACC Login -----");
        printf("\nScegliere un utente:");
        for (i = 0; i < utentiDim; i++)
            printf("\n%d- %s", i + 1, utentiNome[i]);
        printf("\n0- ESCI");
        printf("\n\nInserire la scelta: ");
        scanf("%d", &menu0);
        getchar();

        if (menu0 == 0)
        {
            printf("\nUscita...\n\n");
            return 0;
        }
        else if (menu0 == 1)
            do
            {
                system("cls");
                printf("------ ACC Admin ------");
                printf("\nScegliere un\' opzione:");
                printf("\n1- Aggiungi utente");
                printf("\n2- Elimina utente");
                printf("\n3- Modifica Portfolio");
                printf("\n4- Elimina azienda");
                printf("\n0- ESCI / LOGIN");
                printf("\n\nInserire la scelta: ");
                scanf("%d", &menu1);
                getchar();
                if (menu1 >= 1 && menu1 <= 4)
                    system("cls");

                switch (menu1)
                {
                case 1:
                    utentiAggiungi(utentiNome, utentiPwd, &utentiDim);
                    break;
                case 2:
                    utentiElimina(utentiNome, utentiPwd, &utentiDim);
                    break;
                case 3:
                    portfolioModifica(&portfolio);
                    break;
                case 4:
                    if (dangerZone())
                        return 0;
                    break;
                case 0:
                    break;
                default:
                    printf("Errore! ");
                    pressEnter(0, 1);
                    break;
                }
            } while (menu1 != 0);
        else if (menu0 > utentiDim)
        {
            printf("Errore! ");
            pressEnter(0, 1);
        }
        else if (login(utentiNome, utentiPwd, utentiDim, (menu0 - 1)))
        {
            printf("\nAccesso consentito. Caricamento.\n");
            loading();

            do
            {
                // ------------------------------------------- Menu ------------------------------------------- //
                system("cls");
                printf("----- ACC Software -----");
                printf("\n\nSALDO: %.2f$", portfolio);
                printf("\n\nScegliere un\' opzione:");
                printf("\n1- CONTATTI");
                printf("\n2- CATEGORIE");
                printf("\n3- MAGAZZINO");
                printf("\n4- CARICO");
                printf("\n5- SCARICO");
                printf("\n0- ESCI / CAMBIO UTENTE");
                printf("\n\nInserire la scelta: ");
                scanf("%d", &menu1);
                getchar();

                switch (menu1)
                {
                // ----------------------------------------- Contatti ----------------------------------------- //
                case 1:
                    do
                    {
                        system("cls");
                        printf("-------- ACC Software ---------");
                        printf("\nRUBRICA - Scegliere un\'opzione:");
                        printf("\n1- Crea un contatto");
                        printf("\n2- Elimina un contatto");
                        printf("\n3- Cerca un contatto");
                        printf("\n4- Visualizza contatti");
                        printf("\n0- TORNA AL MENU");
                        printf("\n\nInserire la scelta: ");
                        scanf("%d", &menu2);
                        getchar();
                        if (menu2 >= 0 && menu2 <= 4)
                            system("cls");

                        switch (menu2)
                        {
                        case 1:
                            contattiCrea(contattiNome, contattiMail, contattiType, compravendita, prezzi, &contattiDim, magazzinoNome, magazzinoCodice, magazzinoCat, categorie, magazzinoQta, &magazzinoDim, &categorieDim);
                            break;
                        case 2:
                            contattiElimina(contattiNome, contattiMail, contattiType, compravendita, prezzi, &contattiDim);
                            break;
                        case 3:
                            contattiCerca(contattiNome, contattiMail, contattiType, contattiDim);
                            break;
                        case 4:
                            do
                            {
                                system("cls");
                                printf("------- ACC Software -------");
                                printf("\nScegliere cosa visualizzare:");
                                printf("\n1- Clienti");
                                printf("\n2- Fornitori");
                                printf("\n3- Tutto");
                                printf("\n\nInserire la scelta: ");
                                scanf("%d", &menu3);
                                getchar();
                                if (menu3 >= 1 && menu3 <= 3)
                                    system("cls");

                                switch (menu3)
                                {
                                case 1:
                                    contattiClienti(contattiNome, contattiMail, contattiType, contattiDim);
                                    break;
                                case 2:
                                    contattiFornitori(contattiNome, contattiMail, contattiType, contattiDim);
                                    break;
                                case 3:
                                    contattiTutto(contattiNome, contattiMail, contattiType, contattiDim);
                                    break;
                                default:
                                    printf("Errore! ");
                                    pressEnter(0, 1);
                                    break;
                                }
                            } while (menu3 < 1 || menu3 > 3);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Errore! ");
                            pressEnter(0, 1);
                            break;
                        }
                    } while (menu2 != 0);
                    break;
                // ----------------------------------------- Categorie ---------------------------------------- //
                case 2:
                    do
                    {
                        system("cls");
                        printf("--------- ACC Software ---------");
                        printf("\nCATEGORIE - Scegliere un\'opzione");
                        printf("\n1- Aggiungi categoria");
                        printf("\n2- Visualizza categorie");
                        printf("\n0- TORNA AL MENU");
                        printf("\n\nInserire la scelta: ");
                        scanf("%d", &menu2);
                        getchar();
                        if (menu2 >= 0 && menu2 <= 2)
                            system("cls");

                        switch (menu2)
                        {
                        case 1:
                            categorieAggiungi(categorie, &categorieDim);
                            break;
                        case 2:
                            categorieVisualizza(categorie, categorieDim);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Errore! ");
                            pressEnter(0, 1);
                            break;
                        }
                    } while (menu2 != 0);
                    break;
                // ----------------------------------------- Magazzino ---------------------------------------- //
                case 3:
                    do
                    {
                        system("cls");
                        printf("--------- ACC Software ----------");
                        printf("\nMAGAZZINO - Scegliere un\'opzione:");
                        printf("\n1- Aggiungi prodotti");
                        printf("\n2- Ricerca prodotti");
                        printf("\n3- Visualizza prodotti");
                        printf("\n0- TORNA AL MENU");
                        printf("\n\nInserire la scelta: ");
                        scanf("%d", &menu2);
                        getchar();
                        if (menu2 >= 0 && menu2 <= 3)
                            system("cls");

                        switch (menu2)
                        {
                        case 1:
                            magazzinoAggiungi(magazzinoNome, magazzinoCodice, magazzinoCat, categorie, magazzinoQta, &magazzinoDim, &categorieDim, 0);
                            break;
                        case 2:
                            do
                            {
                                system("cls");
                                printf("---------- ACC Software ----------");
                                printf("\nScegliere la modalita\' di ricerca:");
                                printf("\n1- Nome");
                                printf("\n2- Codice");
                                printf("\n3- Categoria");
                                printf("\n\nInserire la scelta: ");
                                scanf("%d", &menu3);
                                getchar();
                                if (menu3 >= 1 && menu3 <= 3)
                                    system("cls");

                                switch (menu3)
                                {
                                case 1:
                                    magazzinoTrovaNome(magazzinoNome, magazzinoCodice, magazzinoCat, magazzinoQta, magazzinoDim);
                                    break;
                                case 2:
                                    magazzinoTrovaCodice(magazzinoNome, magazzinoCodice, magazzinoCat, magazzinoQta, magazzinoDim);
                                    break;
                                case 3:
                                    magazzinoTrovaCategoria(magazzinoNome, magazzinoCodice, magazzinoCat, magazzinoQta, magazzinoDim);
                                    break;
                                default:
                                    printf("Errore! ");
                                    pressEnter(0, 1);
                                    break;
                                }
                            } while (menu3 < 1 || menu3 > 3);
                            break;
                        case 3:
                            do
                            {
                                system("cls");
                                printf("------------ ACC Software ------------");
                                printf("\nScegliere l\'ordine di visualizzazione:");
                                printf("\n1- Nome");
                                printf("\n2- Q.ta crescente");
                                printf("\n3- Q.ta decrescente");
                                printf("\n\nInserire la scelta: ");
                                scanf("%d", &menu3);
                                getchar();
                                if (menu3 >= 1 && menu3 <= 3)
                                    system("cls");

                                switch (menu3)
                                {
                                case 1:
                                    magazzinoSortNome(magazzinoNome, magazzinoCodice, magazzinoCat, magazzinoQta, magazzinoDim);
                                    break;
                                case 2:
                                    magazzinoSortCrescente(magazzinoNome, magazzinoCodice, magazzinoCat, magazzinoQta, magazzinoDim);
                                    break;
                                case 3:
                                    magazzinoSortDecrescente(magazzinoNome, magazzinoCodice, magazzinoCat, magazzinoQta, magazzinoDim);
                                    break;
                                default:
                                    printf("Errore! ");
                                    pressEnter(0, 1);
                                    break;
                                }
                            } while (menu3 < 1 || menu3 > 3);
                            magazzinoVisualizza(magazzinoNome, magazzinoCodice, magazzinoCat, magazzinoQta, magazzinoDim);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Errore! ");
                            pressEnter(0, 1);
                            break;
                        }
                    } while (menu2 != 0);
                    break;
                // ------------------------------------------ Carico ------------------------------------------ //
                case 4:
                    system("cls");
                    carico(contattiNome, contattiType, compravendita, prezzi, &portfolio, contattiDim, magazzinoNome, magazzinoCodice, magazzinoCat, categorie, magazzinoQta, &magazzinoDim, &categorieDim);
                    break;
                // ------------------------------------------ Scarico ----------------------------------------- //
                case 5:
                    system("cls");
                    scarico(contattiNome, contattiType, compravendita, prezzi, &portfolio, contattiDim, magazzinoNome, magazzinoQta, magazzinoDim);
                    break;
                case 0:
                    printf("Reindirizzamento... ");
                    Sleep(1500);
                    break;
                default:
                    printf("Errore! ");
                    pressEnter(0, 1);
                    break;
                }
            } while (menu1 != 0);
        }
    } while (menu0 != 0);

    printf("\n\n");
    return 0;
}

// ------------------------------------------------- Funzioni ------------------------------------------------- //
void center(char s[], int i)
{
    int pad1, pad2;

    pad1 = (i - strlen(s)) / 2;
    pad2 = pad1;
    if (i % 2 == 0 && strlen(s) % 2 == 1)
        pad2 += 1;
    if (i % 2 == 1 && strlen(s) % 2 == 0)
        pad2 += 1;

    printf("%*s%s%*s", pad1, "", s, pad2, "");
}
void convertArr(char s[][DimStr], int pos, int lower)
{
    int i;

    for (i = 0; i < strlen(s[pos]); i++)
        if (isalpha(s[pos][i]) != 0)
        {
            if (i == 0 && lower == 0)
                s[pos][i] = toupper(s[pos][i]);
            else
                s[pos][i] = tolower(s[pos][i]);
        }
}
void convertStr(char s[])
{
    int i;

    for (i = 0; i < strlen(s); i++)
        if (isalpha(s[i]) != 0)
        {
            if (i == 0)
                s[i] = toupper(s[i]);
            else
                s[i] = tolower(s[i]);
        }
}
void initialize(int *utentiDim, char utentiNome[][DimStr], char utentiPwd[][DimStr], int *contattiDim, char contattiNome[][DimStr], char contattiMail[][DimStr], int contattiType[], int *categorieDim, char categorie[][DimStr], int *magazzinoDim, char magazzinoNome[][DimStr], int magazzinoCodice[], char magazzinoCat[][DimStr], int magazzinoQta[], char compravendita[][DimStr], float prezzi[], float *portfolio)
{
    int i;
    char utentiNomeT[DIM][DimStr] = {"admin", "magda.mongelli"};
    char utentiPwdT[DIM][DimStr] = {"admin", "MolfettaCapitale"};
    char contattiNomeT[DIM][DimStr] = {"Alberto", "Carlo", "Giacomo", "Lucia", "Paolo"};
    char contattiMailT[DIM][DimStr] = {"rossi.alberto@plastek.it", "carlomonaco1@gmail.com", "giacomo.furlan@alice.it", "lucia.granz8@gmail.com", "paolo485@gmail.com"};
    int contattiTypeT[DIM] = {2, 1, 2, 2, 1};
    char categorieT[DIM][DimStr] = {"Arredo", "Decorazioni", "Elettrodomestici", "Tecnologia"};
    char magazzinoNomeT[DIM][DimStr] = {"Armadio", "Lavatrice", "Mobile", "Piantina", "Tavolo", "Televisione"};
    int magazzinoCodiceT[DIM] = {430598, 624709, 381065, 918437, 264750, 148006};
    char magazzinoCatT[DIM][DimStr] = {"Arredo", "Elettrodomestici", "Arredo", "Decorazioni", "Arredo", "Tecnologia"};
    int magazzinoQtaT[DIM] = {68, 3, 56, 24, 12, 39};
    char compravenditaT[DIM][DimStr] = {"Televisione", "Piantina", "Armadio", "Televisione", "Armadio"};
    float prezziT[DIM] = {672.99, 8.00, 86.29, 725.99, 120.00};

    // Inizializzazione utenti
    *utentiDim = 2;
    for (i = 0; i < *utentiDim; i++)
    {
        strcpy(utentiNome[i], utentiNomeT[i]);
        strcpy(utentiPwd[i], utentiPwdT[i]);
    }

    // Inizializzazione contatti
    *contattiDim = 5;
    for (i = 0; i < *contattiDim; i++)
    {
        strcpy(contattiNome[i], contattiNomeT[i]);
        strcpy(contattiMail[i], contattiMailT[i]);
        contattiType[i] = contattiTypeT[i];
    }

    // Inizializzazione categorie
    *categorieDim = 4;
    for (i = 0; i < *categorieDim; i++)
        strcpy(categorie[i], categorieT[i]);

    // Inizializzazione magazzino
    *magazzinoDim = 6;
    for (i = 0; i < *magazzinoDim; i++)
    {
        strcpy(magazzinoNome[i], magazzinoNomeT[i]);
        magazzinoCodice[i] = magazzinoCodiceT[i];
        strcpy(magazzinoCat[i], magazzinoCatT[i]);
        magazzinoQta[i] = magazzinoQtaT[i];
    }

    // Inizializzazione compravendita
    *portfolio = 4618.43;
    for (i = 0; i < *contattiDim; i++)
    {
        strcpy(compravendita[i], compravenditaT[i]);
        prezzi[i] = prezziT[i];
    }
}
void loading(void)
{
    printf("| [                    ] 0%% ");
    Sleep(MAX);
    printf("\r/ [##                  ] 10%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r- [####                ] 20%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r\\ [######              ] 30%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r| [########            ] 40%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r/ [##########          ] 50%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r- [############        ] 60%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r\\ [##############      ] 70%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r| [################    ] 80%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r/ [##################  ] 90%% ");
    Sleep((rand() % (MAX - MIN + 1)) + MIN);
    printf("\r- [####################] 100%% ");
    Sleep(350);
    printf("\r                               ");
    Sleep(350);
    printf("\r- [####################] 100%% ");
    Sleep(350);
    printf("\r                               ");
    Sleep(350);
    printf("\r- [####################] 100%% ");
    Sleep(350);
    printf("\r                               ");
    Sleep(350);
    printf("\r- [####################] 100%% ");
    Sleep(1500);
}
bool login(char utenti[][DimStr], char pwd[][DimStr], int dim, int j)
{
    int i = 0;
    char password[DimStr];
    bool flag = false;

    system("cls");
    printf("Utente: %s", utenti[j]);
    printf("\nInserire password: ");
    gets(password);

    while (i < dim && !flag)
    {
        if (strcmp(password, pwd[j]) == 0)
            flag = true;

        i++;
    }

    if (!flag)
    {
        printf("\nPassword errata!");
        pressEnter(1, 1);
        return false;
    }
    else
        return true;
}
void pressEnter(int newLine, int skipBuffer)
{
    if (newLine == 1)
        printf("\n");
    printf("Premi invio per continuare. ");
    if (skipBuffer == 0)
        getchar();
    getchar();
}
void stampaCodice(int codice)
{
    int i, dim;

    if (codice >= 0 && codice <= 9)
        dim = 5;
    else if (codice >= 10 && codice <= 99)
        dim = 4;
    else if (codice >= 100 && codice <= 999)
        dim = 3;
    else if (codice >= 1000 && codice <= 9999)
        dim = 2;
    else if (codice >= 10000 && codice <= 99999)
        dim = 1;
    else if (codice >= 100000 && codice <= 999999)
        dim = 0;

    for (i = 0; i < dim; i++)
        printf("0");
    printf("%d", codice);
}

void utentiAggiungi(char nome[][DimStr], char pwd[][DimStr], int *dim)
{
    int i;
    bool flag;

    do
    {
        flag = false;
        printf("Inserire il nome dell\'utente: ");
        gets(nome[*dim]);
        convertArr(nome, (*dim), 1);
        if (strlen(nome[*dim]) > DimUtente)
            printf("Errore! La lunghezza massima e\' %d.\n", DimUtente);

        for (i = 0; i < *dim; i++)
            if (strcmp(nome[*dim], nome[i]) == 0)
            {
                printf("Errore! L\'utente e\' gia\' presente.\n");
                flag = true;
            }
    } while (strlen(nome[*dim]) > DimUtente || flag);

    do
    {
        printf("Inserire la password dell'utente: ");
        gets(pwd[*dim]);
        if (strlen(pwd[*dim]) > DimUtente)
            printf("Errore! La lunghezza massima e\' %d.\n", DimUtente);
    } while (strlen(pwd[*dim]) > DimUtente);

    printf("\nUtente aggiunto con successo.");
    pressEnter(1, 1);

    (*dim) += 1;
    utentiSort(nome, pwd, (*dim));
}
void utentiElimina(char nome[][DimStr], char pwd[][DimStr], int *dim)
{
    int i, num;
    char temp[DimStr];
    bool flag = false;

    system("cls");
    printf("Lista degli utenti:");
    for (i = 1; i < *dim; i++)
        printf("\n%d- %s", i, nome[i]);

    printf("\n");
    do
    {
        printf("\nInserire il numero da eliminare: ");
        scanf("%d", &num);
        if (num < 1 || num >= (*dim))
            printf("Errore! Inserire un numero valido.");
    } while (num < 1 || num >= (*dim));

    for (i = num; i < *dim - 1; i++)
    {
        strcpy(nome[i], nome[i + 1]);
        strcpy(pwd[i], pwd[i + 1]);
    }
    printf("\nUtente eliminato con successo.");

    pressEnter(1, 0);
    (*dim) -= 1;
}
void utentiSort(char nome[][DimStr], char pwd[][DimStr], int dim)
{
    int i, j;
    char temp[DimStr];

    for (i = 1; i < dim - 1; i++)
        for (j = 1; j < dim - i; j++)
            if (strcmp(nome[j], nome[j + 1]) > 0)
            {
                // Nome
                strcpy(temp, nome[j]);
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], temp);
                // Pwd
                strcpy(temp, pwd[j]);
                strcpy(pwd[j], pwd[j + 1]);
                strcpy(pwd[j + 1], temp);
            }
}
void portfolioModifica(float *portfolio)
{
    printf("Attualmente i fondi ammontanto a: %.2f$", *portfolio);
    printf("\nA quanto li vuoi impostare? ");
    scanf("%f", &(*portfolio));

    printf("\nFondi aggiornati con successo!");
    pressEnter(1, 0);
}
bool dangerZone(void)
{
    int i, num1 = 0, num2;
    char c;

    printf("ATTENZIONE! Quest\'azione e\' irreversibile!\n");
    do
    {
        printf("Si desidera eliminare il programma? (Y/N): ");
        c = getchar();
        c = tolower(c);
        getchar();
        if (c != 'y' && c != 'n')
            printf("Errore! Inserire una scelta valida!\n");
    } while (c != 'y' && c != 'n');

    if (c == 'y')
    {
        for (i = 1; i < 6; i++)
            num1 += ((rand() % 9) + 1) * pow(10, i);

        printf("\nInserire il seguente codice per");
        printf("\nconfermare l\'operazione: %d", num1);
        printf("\nCodice: ");
        scanf("%d", &num2);

        if (num1 == num2)
        {
            printf("\nCodice confermato. Eliminazione.\n");
            loading();
            remove("ACC_Software.c");
            printf("\n\n");
            return true;
        }
        else
        {
            printf("\nCodice errato! Annullamento operazione... ");
            Sleep(1500);
            return false;
        }
    }
    else
    {
        printf("\nAnnullamento operazione... ");
        Sleep(1500);
        return false;
    }
}

void contattiCrea(char nome[][DimStr], char mail[][DimStr], int type[], char prod[][DimStr], float prezzo[], int *dim, char magNome[][DimStr], int magCod[], char magCat[][DimStr], char categoria[][DimStr], int magQta[], int *dimMag, int *dimCat)
{
    int i;
    char temp[DimStr];
    bool flag = false;

    do
    {
        printf("Inserire il nome del contatto: ");
        gets(nome[*dim]);
        if (strlen(nome[*dim]) > DimNome)
            printf("Errore! La lunghezza massima e\' %d.\n", DimNome);
    } while (strlen(nome[*dim]) > DimNome);
    convertArr(nome, (*dim), 0);

    do
    {
        printf("Inserire l'email del contatto: ");
        gets(mail[*dim]);
        if (strlen(mail[*dim]) > DimMail)
            printf("Errore! La lunghezza massima e\' %d.\n", DimMail);
    } while (strlen(mail[*dim]) > DimMail);

    do
    {
        printf("Inserire tipo (Cliente / Fornitore): ");
        gets(temp);
        for (i = 0; i < strlen(temp); i++)
            temp[i] = tolower(temp[i]);

        if (strcmp(temp, "cliente") == 0 || strcmp(temp, "c") == 0)
        {
            type[*dim] = 1;
            flag = true;
        }
        else if (strcmp(temp, "fornitore") == 0 || strcmp(temp, "f") == 0)
        {
            type[*dim] = 2;
            flag = true;
        }
        else
            printf("Errore!\n");
    } while (!flag);
    flag = false;

    do
    {
        if (type[*dim] == 1)
            printf("\nInserire il prodotto che acquista: ");
        if (type[*dim] == 2)
            printf("\nInserire il prodotto che vende: ");
        gets(prod[*dim]);
        if (strlen(prod[*dim]) > DimNomeProd)
            printf("Errore! La lunghezza massima e\' %d.\n", DimNomeProd);
    } while (strlen(prod[*dim]) > DimNomeProd);
    convertArr(prod, (*dim), 0);

    do
    {
        printf("Inserire il prezzo del prodotto: ");
        scanf("%f", &prezzo[*dim]);
        getchar();
        if (prezzo[*dim] == 0)
            printf("Errore! Il prezzo non puo\' essere 0.\n");
        if (prezzo[*dim] < 0)
            printf("Errore! Il prezzo non puo\' essere negativo.\n");
    } while (prezzo[*dim] <= 0);

    // Aggiunta prodotto se non presente in magazzino
    for (i = 0; i < *dimMag; i++)
        if (strcmp(prod[*dim], magNome[i]) == 0)
            flag = true;
    if (!flag)
    {
        printf("\nIl prodotto non e\' presente in magazzino.");
        printf("\nPremi invio per aggiungerlo. ");
        getchar();
        system("cls");
        // Aggiunta del nome
        strcpy(magNome[*dimMag], prod[*dim]);
        magazzinoAggiungi(magNome, magCod, magCat, categoria, magQta, &(*dimMag), &(*dimCat), 1);
        system("cls");
        printf("Informazioni del contatto aggiornate.\n");
    }

    printf("\nContatto aggiunto con successo.");
    pressEnter(1, 1);

    (*dim) += 1;
    contattiSort(nome, mail, type, prod, prezzo, (*dim));
}
void contattiElimina(char nome[][DimStr], char mail[][DimStr], int type[], char prod[][DimStr], float prezzo[], int *dim)
{
    int i = 0;
    char temp[DimStr];
    bool flag = false;

    printf("Inserire il nome da eliminare: ");
    gets(temp);
    convertStr(temp);

    while (i < *dim && !flag)
    {
        if (strcmp(temp, nome[i]) == 0)
            flag = true;
        else
            i++;
    }

    if (flag)
    {
        for (i = i; i < *dim - 1; i++)
        {
            strcpy(nome[i], nome[i + 1]);
            strcpy(mail[i], mail[i + 1]);
            type[i] = type[i + 1];
            strcpy(prod[i], prod[i + 1]);
            prezzo[i] = prezzo[i + 1];
        }

        printf("\nContatto eliminato con successo.");
        (*dim) -= 1;
    }
    else
        printf("\nIl contatto non e\' stato trovato.");

    pressEnter(1, 1);
}
void contattiCerca(char nome[][DimStr], char mail[][DimStr], int type[], int dim)
{
    int i = 0;
    char temp[DimStr];
    bool flag = false;

    printf("Inserire il nome da cercare: ");
    gets(temp);
    convertStr(temp);

    for (i = 0; i < dim; i++)
    {
        if (strcmp(temp, nome[i]) == 0)
        {
            if (!flag)
            {
                printf("\n------------------- CONTATTI TROVATI -------------------\n");
                printf("|    Nome    |  |          E-Mail          |  |  Tipo  |\n");
                printf("\n");
            }
            center(nome[i], DimNome);
            printf("  ");
            center(mail[i], DimMail);
            printf("  ");
            if (type[i] == 1)
                center("Cliente", DimType);
            if (type[i] == 2)
                center("Fornitore", DimType);
            printf("\n");

            flag = true;
        }
    }

    if (!flag)
        printf("\nContatto non trovato.");

    pressEnter(1, 1);
}
void contattiClienti(char nome[][DimStr], char mail[][DimStr], int type[], int dim)
{
    int i;

    printf("------------------ CONTATTI (CLIENTI) ------------------\n");
    printf("|    Nome    |  |          E-Mail          |  |  Tipo  |\n");
    printf("\n");
    for (i = 0; i < dim; i++)
        if (type[i] == 1)
        {
            center(nome[i], DimNome);
            printf("  ");
            center(mail[i], DimMail);
            printf("  ");
            if (type[i] == 1)
                center("Cliente", DimType);
            if (type[i] == 2)
                center("Fornitore", DimType);
            printf("\n");
        }

    pressEnter(1, 1);
}
void contattiFornitori(char nome[][DimStr], char mail[][DimStr], int type[], int dim)
{
    int i;

    printf("----------------- CONTATTI (FORNITORI) -----------------\n");
    printf("|    Nome    |  |          E-Mail          |  |  Tipo  |\n");
    printf("\n");
    for (i = 0; i < dim; i++)
        if (type[i] == 2)
        {
            center(nome[i], DimNome);
            printf("  ");
            center(mail[i], DimMail);
            printf("  ");
            if (type[i] == 1)
                center("Cliente", DimType);
            if (type[i] == 2)
                center("Fornitore", DimType);
            printf("\n");
        }

    pressEnter(1, 1);
}
void contattiTutto(char nome[][DimStr], char mail[][DimStr], int type[], int dim)
{
    int i;

    printf("------------------- CONTATTI (TUTTO) -------------------\n");
    printf("|    Nome    |  |          E-Mail          |  |  Tipo  |\n");
    printf("\n");
    for (i = 0; i < dim; i++)
    {
        center(nome[i], DimNome);
        printf("  ");
        center(mail[i], DimMail);
        printf("  ");
        if (type[i] == 1)
            center("Cliente", DimType);
        if (type[i] == 2)
            center("Fornitore", DimType);
        printf("\n");
    }

    pressEnter(1, 1);
}
void contattiSort(char nome[][DimStr], char mail[][DimStr], int type[], char prod[][DimStr], float prezzo[], int dim)
{
    int i, j, tempnum;
    float tempfloat;
    char temp[DimStr];

    for (i = 0; i < dim - 1; i++)
        for (j = 0; j < dim - 1 - i; j++)
            if (strcmp(nome[j], nome[j + 1]) > 0)
            {
                // Nome
                strcpy(temp, nome[j]);
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], temp);
                // Mail
                strcpy(temp, mail[j]);
                strcpy(mail[j], mail[j + 1]);
                strcpy(mail[j + 1], temp);
                // Type
                tempnum = type[j];
                type[j] = type[j + 1];
                type[j + 1] = tempnum;
                // Prodotto
                strcpy(temp, prod[j]);
                strcpy(prod[j], prod[j + 1]);
                strcpy(prod[j + 1], temp);
                // Prezzo
                tempfloat = prezzo[j];
                prezzo[j] = prezzo[j + 1];
                prezzo[j + 1] = tempfloat;
            }
}

void categorieAggiungi(char categoria[][DimStr], int *dim)
{
    int i = 0;
    char temp[DimStr];
    bool flag = false;

    do
    {
        printf("Inserire la categoria: ");
        gets(temp);
        if (strlen(temp) > DimCat)
            printf("Errore! La lunghezza massima e\' %d.\n", DimCat);
    } while (strlen(temp) > DimCat);
    convertStr(temp);

    while (i < *dim && !flag)
    {
        if (strcmp(temp, categoria[i]) == 0)
            flag = true;

        i++;
    }

    if (!flag)
    {
        strcpy(categoria[*dim], temp);
        printf("\nCategoria aggiunta con successo.");
        (*dim) += 1;
        categorieSort(categoria, (*dim));
    }
    else
        printf("\nLa categoria e\' gia\' presente.");

    pressEnter(1, 1);
}
void categorieVisualizza(char categoria[][DimStr], int dim)
{
    int i;

    printf("--- CATEGORIE ---\n");
    for (i = 0; i < dim; i++)
    {
        center(categoria[i], DimCat);
        printf("\n");
    }

    pressEnter(1, 1);
}
void categorieSort(char categoria[][DimStr], int dim)
{
    int i, j;
    char temp[DimStr];

    for (i = 0; i < dim - 1; i++)
        for (j = 0; j < dim - 1 - i; j++)
            if (strcmp(categoria[j], categoria[j + 1]) > 0)
            {
                strcpy(temp, categoria[j]);
                strcpy(categoria[j], categoria[j + 1]);
                strcpy(categoria[j + 1], temp);
            }
}

void magazzinoAggiungi(char nome[][DimStr], int codice[], char cat[][DimStr], char categoria[][DimStr], int qta[], int *dim, int *dimCat, int skipNome)
{
    int i = 0;
    char temp[DimStr];
    bool flag = false;

    if (skipNome == 0)
    {
        do
        {
            printf("Inserire il nome del prodotto: ");
            gets(nome[*dim]);
            if (strlen(nome[*dim]) > DimNomeProd)
                printf("Errore! La lunghezza massima e\' %d.\n", DimNomeProd);
        } while (strlen(nome[*dim]) > DimNomeProd);
        convertArr(nome, (*dim), 0);
    }

    do
    {
        printf("Inserire il codice del prodotto: ");
        scanf("%d", &codice[*dim]);
        getchar();
        if (codice[*dim] < 1 || codice[*dim] > 999999)
            printf("Errore! Inserire minimo 1 e massimo 6 cifre.\n");
    } while (codice[*dim] < 1 || codice[*dim] > 999999);

    do
    {
        printf("Inserire la categoria del prodotto: ");
        gets(temp);
        if (strlen(temp) > DimCat)
            printf("Errore! La lunghezza massima e\' %d.\n", DimCat);
    } while (strlen(temp) > DimCat);
    convertStr(temp);
    strcpy(cat[*dim], temp);

    while (i < *dimCat && !flag)
    {
        if (strcmp(temp, categoria[i]) == 0)
            flag = true;

        i++;
    }

    if (!flag)
    {
        strcpy(categoria[*dimCat], temp);
        printf("\nLa categoria non era presente ed");
        printf("\ne\' stata aggiunta con successo.\n");
        (*dimCat) += 1;
        categorieSort(categoria, (*dimCat));
    }

    printf("\nProdotto aggiunto con successo.");
    pressEnter(1, 1);

    (*dim) += 1;
    magazzinoSortNome(nome, codice, cat, qta, (*dim));
}
void magazzinoTrovaNome(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim)
{
    int i = 0;
    char temp[DimStr];
    bool flag = false;

    printf("Inserire il nome da cercare: ");
    gets(temp);
    convertStr(temp);

    while (i < dim && !flag)
    {
        if (strcmp(temp, nome[i]) == 0)
        {
            printf("\n--------------------- PRODOTTO TROVATO ----------------------\n");
            printf("|       Nome       |  | Codice |  |   Categoria   |  | Q.ta |\n");
            printf("\n");
            center(nome[i], DimNomeProd);
            printf("    ");
            stampaCodice(codice[i]);
            printf("    ");
            center(categoria[i], DimCat);
            printf("   ");
            stampaCodice(qta[i]);
            printf("\n");

            flag = true;
        }
        i++;
    }

    if (!flag)
        printf("\nProdotto non trovato.");

    pressEnter(1, 1);
}
void magazzinoTrovaCodice(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim)
{
    int i = 0, temp;
    bool flag = false;

    printf("Inserire il codice da cercare: ");
    scanf("%d", &temp);

    while (i < dim && !flag)
    {
        if (temp == codice[i])
        {
            printf("\n--------------------- PRODOTTO TROVATO ----------------------\n");
            printf("|       Nome       |  | Codice |  |   Categoria   |  | Q.ta |\n");
            printf("\n");
            center(nome[i], DimNomeProd);
            printf("    ");
            stampaCodice(codice[i]);
            printf("    ");
            center(categoria[i], DimCat);
            printf("   ");
            stampaCodice(qta[i]);
            printf("\n");

            flag = true;
        }
        i++;
    }

    if (!flag)
        printf("\nProdotto non trovato.");

    pressEnter(1, 0);
}
void magazzinoTrovaCategoria(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim)
{
    int i = 0;
    char temp[DimStr];
    bool flag = false;

    printf("Inserire la categoria da cercare: ");
    gets(temp);
    convertStr(temp);

    while (i < dim && !flag)
    {
        if (strcmp(temp, categoria[i]) == 0)
        {
            printf("\n--------------------- PRODOTTO TROVATO ----------------------\n");
            printf("|       Nome       |  | Codice |  |   Categoria   |  | Q.ta |\n");
            printf("\n");
            center(nome[i], DimNomeProd);
            printf("    ");
            stampaCodice(codice[i]);
            printf("    ");
            center(categoria[i], DimCat);
            printf("   ");
            stampaCodice(qta[i]);
            printf("\n");

            flag = true;
        }
        i++;
    }

    if (!flag)
        printf("\nProdotto non trovato.");

    pressEnter(1, 1);
}
void magazzinoVisualizza(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim)
{
    int i = 0;

    printf("\n--------------------- PRODOTTO TROVATO ----------------------\n");
    printf("|       Nome       |  | Codice |  |   Categoria   |  | Q.ta |\n");
    printf("\n");
    for (i = 0; i < dim; i++)
    {
        center(nome[i], DimNomeProd);
        printf("    ");
        stampaCodice(codice[i]);
        printf("    ");
        center(categoria[i], DimCat);
        printf("   ");
        stampaCodice(qta[i]);
        printf("\n");
    }

    pressEnter(1, 1);
}
void magazzinoSortNome(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim)
{
    int i, j, tempnum;
    char temp[DimStr];

    for (i = 0; i < dim - 1; i++)
        for (j = 0; j < dim - 1 - i; j++)
            if (strcmp(nome[j], nome[j + 1]) > 0)
            {
                // Nome
                strcpy(temp, nome[j]);
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], temp);
                // Codice
                tempnum = codice[j];
                codice[j] = codice[j + 1];
                codice[j + 1] = tempnum;
                // Categoria
                strcpy(temp, categoria[j]);
                strcpy(categoria[j], categoria[j + 1]);
                strcpy(categoria[j + 1], temp);
                // Quantità
                tempnum = qta[j];
                qta[j] = qta[j + 1];
                qta[j + 1] = tempnum;
            }
}
void magazzinoSortCrescente(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim)
{
    int i, j, tempnum;
    char temp[DimStr];

    for (i = 0; i < dim - 1; i++)
        for (j = 0; j < dim - 1 - i; j++)
            if (qta[j] > qta[j + 1])
            {
                // Nome
                strcpy(temp, nome[j]);
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], temp);
                // Codice
                tempnum = codice[j];
                codice[j] = codice[j + 1];
                codice[j + 1] = tempnum;
                // Categoria
                strcpy(temp, categoria[j]);
                strcpy(categoria[j], categoria[j + 1]);
                strcpy(categoria[j + 1], temp);
                // Quantità
                tempnum = qta[j];
                qta[j] = qta[j + 1];
                qta[j + 1] = tempnum;
            }
}
void magazzinoSortDecrescente(char nome[][DimStr], int codice[], char categoria[][DimStr], int qta[], int dim)
{
    int i, j, tempnum;
    char temp[DimStr];

    for (i = 0; i < dim - 1; i++)
        for (j = 0; j < dim - 1 - i; j++)
            if (qta[j] < qta[j + 1])
            {
                // Nome
                strcpy(temp, nome[j]);
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], temp);
                // Codice
                tempnum = codice[j];
                codice[j] = codice[j + 1];
                codice[j + 1] = tempnum;
                // Categoria
                strcpy(temp, categoria[j]);
                strcpy(categoria[j], categoria[j + 1]);
                strcpy(categoria[j + 1], temp);
                // Quantità
                tempnum = qta[j];
                qta[j] = qta[j + 1];
                qta[j + 1] = tempnum;
            }
}

void carico(char nome[][DimStr], int type[], char prod[][DimStr], float prezzo[], float *portfolio, int dim, char magNome[][DimStr], int magCod[], char magCat[][DimStr], char categoria[][DimStr], int magQta[], int *dimMag, int *dimCat)
{
    int i, j = 0, k, posMag, tempnum;
    float prezziTmp[DIM] = {0}, tot;
    char temp[DimStr], tempItem[DimStr], nomiTmp[DIM][DimStr];
    bool flag = false;

    // ------------------------------------- Controllo prodotto magazzino ------------------------------------- //
    do
    {
        printf("Inserire il prodotto da comprare: ");
        gets(tempItem);
        if (strlen(tempItem) > DimNomeProd)
            printf("Errore! La lunghezza massima e\' %d.\n", DimNomeProd);
    } while (strlen(tempItem) > DimNomeProd);
    convertStr(tempItem);

    for (i = 0; i < *dimMag; i++)
        if (strcmp(tempItem, magNome[i]) == 0)
        {
            posMag = i;
            flag = true;
        }
    if (!flag)
    {
        printf("\nIl prodotto non e\' presente in magazzino.");
        printf("\nPremi invio per aggiungerlo. ");
        getchar();
        system("cls");
        // Aggiunta del nome
        strcpy(magNome[*dimMag], tempItem);
        magazzinoAggiungi(magNome, magCod, magCat, categoria, magQta, &(*dimMag), &(*dimCat), 1);
        system("cls");
        printf("Il prodotto e\' ora inserito ma nessun fornitore lo\n");
        printf("vende. Aggiungere almeno un fornitore che lo venda.\n");
        pressEnter(1, 1);
        return;
    }

    // ---------------------------------------- Ricerca dei fornitori ----------------------------------------- //
    flag = false;
    for (i = 0; i < dim; i++)
    {
        if (type[i] == 2 && (strcmp(tempItem, prod[i]) == 0))
        {
            strcpy(nomiTmp[j], nome[i]);
            prezziTmp[j] = prezzo[i];

            if (!flag)
            {
                printf("\n---- FORNITORI TROVATI -----\n");
                printf("|    Nome    |  |  Prezzo  |\n");
                printf("\n");
            }
            center(nomiTmp[j], DimNome);
            printf("  ");
            printf("%10.2f$", prezziTmp[j]);
            printf("\n");

            flag = true;
            j++;
        }
    }

    // ----------------------------------- Acquisto per nome del fornitore ------------------------------------ //
    if (flag)
    {
        do
        {
            printf("\nInserire il nome del fornitore: ");
            gets(temp);
            convertStr(temp);

            i = 0;
            flag = false;
            while (i < j && !flag)
            {
                if (strcmp(temp, nomiTmp[i]) == 0)
                {
                    k = i;
                    flag = true;
                }
                else
                    k = -1;
                i++;
            }
            if (k == -1)
                printf("Errore! Inserire un fornitore valido.");
        } while (k == -1);

        // ------------------------------------- Selezione della quantità ------------------------------------- //
        do
        {
            printf("Inserire la quantita\' da acquistare: ");
            scanf("%d", &tempnum);
            getchar();

            tot = (float)tempnum * prezziTmp[k];
            if (tot > *portfolio && prezziTmp[k] < *portfolio)
                printf("Errore! Non si hanno abbastanza fondi.\n");
            else if (prezziTmp[k] > *portfolio)
            {
                printf("\nErrore! Non si puo\' comprare nemmeno");
                printf("\nun prodotto. Inserire piu\' fondi.\n");
                flag = false;
            }
        } while (tot > *portfolio && flag);

        if (flag)
        {
            printf("\nOrdine effettuato da %s di:\n", nomiTmp[k]);
            printf("%d %s per un totale di: %.2f$", tempnum, tempItem, tot);
            *portfolio -= tot;
            magQta[posMag] += tempnum;
        }
    }
    else
        printf("\nNessun fornitore vende %s.", tempItem);

    pressEnter(1, 1);
}
void scarico(char nome[][DimStr], int type[], char prod[][DimStr], float prezzo[], float *portfolio, int dim, char magNome[][DimStr], int magQta[], int dimMag)
{
    int i, j = 0, k, posMag, tempnum;
    float prezziTmp[DIM] = {0}, tot;
    char temp[DimStr], tempItem[DimStr], nomiTmp[DIM][DimStr];
    bool flag = false;

    // ------------------------------------- Controllo prodotto magazzino ------------------------------------- //
    do
    {
        printf("Inserire il prodotto da vendere: ");
        gets(tempItem);
        if (strlen(tempItem) > DimNomeProd)
            printf("Errore! La lunghezza massima e\' %d.\n", DimNomeProd);
    } while (strlen(tempItem) > DimNomeProd);
    convertStr(tempItem);

    for (i = 0; i < dimMag; i++)
        if (strcmp(tempItem, magNome[i]) == 0)
        {
            posMag = i;
            flag = true;
        }
    if (!flag)
    {
        printf("\nIl prodotto non e\' presente in magazzino.\n");
        printf("Questo significa che nessun cliente compra");
        printf("\ntale prodotto. Assicurati di avere almeno");
        printf("\nun prodotto da vendere prima di riprovare.\n");
        pressEnter(1, 1);
        return;
    }

    // ----------------------------------------- Ricerca dei clienti ------------------------------------------ //
    flag = false;
    for (i = 0; i < dim; i++)
    {
        if (type[i] == 1 && (strcmp(tempItem, prod[i]) == 0))
        {
            strcpy(nomiTmp[j], nome[i]);
            prezziTmp[j] = prezzo[i];

            if (!flag)
            {
                printf("\n----- CLIENTI TROVATI ------\n");
                printf("|    Nome    |  |  Prezzo  |\n");
                printf("\n");
            }
            center(nomiTmp[j], DimNome);
            printf("  ");
            printf("%10.2f$", prezziTmp[j]);
            printf("\n");

            flag = true;
            j++;
        }
    }

    // ------------------------------------- Vendita per nome del cliente ------------------------------------- //
    if (flag)
    {
        do
        {
            printf("\nInserire il nome del cliente: ");
            gets(temp);
            convertStr(temp);

            i = 0;
            flag = false;
            while (i < j && !flag)
            {
                if (strcmp(temp, nomiTmp[i]) == 0)
                {
                    k = i;
                    flag = true;
                }
                else
                    k = -1;
                i++;
            }
            if (k == -1)
                printf("Errore! Inserire un cliente valido.");
        } while (k == -1);

        // ------------------------------------- Selezione della quantità ------------------------------------- //
        do
        {
            printf("Inserire la quantita\' da vendere: ");
            scanf("%d", &tempnum);
            getchar();

            tot = (float)tempnum * prezziTmp[k];
            if (tempnum > magQta[posMag] && magQta[posMag] > 0)
                printf("Errore! Inserire una quantita\' valida.\n");
            else if (magQta[posMag] == 0)
            {
                printf("\nErrore! Non si puo\' vendere nemmeno");
                printf("\nun prodotto. Acquistane almeno uno.\n");
                flag = false;
            }
        } while (tempnum > magQta[posMag] && flag);

        if (flag)
        {
            printf("\nVendita effettuata per %s di:\n", nomiTmp[k]);
            printf("%d %s per un totale di: %.2f$", tempnum, tempItem, tot);
            *portfolio += tot;
            magQta[posMag] -= tempnum;
        }
    }
    else
        printf("\nNessun cliente compra %s.", tempItem);

    pressEnter(1, 1);
}
