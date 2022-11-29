#include <stdio.h>
#include <stdlib.h>

// Programa que realiza alocação dinâmica de memória e gera a multiplicação de duas matrizes, baseada em um arquivo "in.txt", que deve ser criado de acordo com o padrão abaixo:
// numLinhaMatriz1 numColunaMatriz1 numLinhaMatriz2 numColunaMatriz2

// valores de entrada matriz 1
// valores de entrada matriz 2

// 3 2 2 1

// 1 2
// 0 -1
// 1 4

// 1
// 2

void encerra()
{
    printf("Memoria insuficiente!");
    exit(1);
}

int **imat_alloc(int linhaX, int colunaY)
{
    int i, j;
    int **tmp = (int **)malloc(linhaX * sizeof(int *));
    if (tmp == NULL)
        encerra();
    for (i = 0; i < linhaX; i++)
    {
        tmp[i] = (int *)malloc(colunaY * sizeof(int));
        if (tmp[i] == NULL)
            encerra();
        for (j = 0; j < colunaY; j++)
        {
            tmp[i][j] = 0;
        }
    }
    return tmp;
}

void imat_free(int **pmat, int linhaX)
{
    int i;
    for (i = 0; i < linhaX; i++)
        free(pmat[i]);
    free(pmat);
}

int main()
{
    /************** Declara o de variaveis *******************/ �� int i, j, k, aux = 0;
    int linhaA, linhaB, colunaA, colunaB;
    int **A, **B, **C;
    FILE *fpin, *fpout;
    /************ Abertura dos arquivos **********************/
    fpin = fopen("in.TXT", "r");
    fpout = fopen("out.TXT", "w");
    if ((fpin = fopen("in.txt", "r")) == NULL)
    {
        printf("\nFalha na abertura do arquivo de entrada de dados !\a");
        goto Fim;
    }
    if ((fpout = fopen("out.txt", "w")) == NULL)
    {
        printf("\nFalha na abertura do arquivo de saida de dados !\a");
        goto Fim;
    }
    fscanf(fpin, "%d", &linhaA);
    printf("Quantidade de linhas na matriz A: %d\n", linhaA);
    fscanf(fpin, "%d", &colunaA);
    printf("Quantidade de colunas na matriz A: %d\n", colunaA);
    fscanf(fpin, "%d", &linhaB);
    printf("Quantidade de linhas na matriz B: %d\n", linhaB);
    fscanf(fpin, "%d", &colunaB);
    printf("Quantidade de colunas na matriz B: %d\n", colunaB);
    if (!linhaA > 0 && colunaA > 0 && linhaB > 0 && colunaB > 0)
    {
        printf("\nDimensoes invalidas\n");
        goto Fim;
    }
    if (linhaB != colunaA)
    {
        printf("\nA multiplicacao entre as matrizes A e B nao eh possiel.\n");
        goto Fim;
    }
    /*************************** Aloca o de mem ria para as matrizes �� �
    *****************************/
    A = imat_alloc(linhaA, colunaA);
    B = imat_alloc(linhaB, colunaB);
    C = imat_alloc(linhaA, colunaB);
    /************************* Aloca o de dados nas matrizes ��
    ********************************/
    for (i = 0; i < linhaA; i++)
    {
        for (j = 0; j < colunaA; j++)
        {
            fscanf(fpin, "%i", &aux);
            A[i][j] = aux;
        }
    }
    for (i = 0; i < linhaB; i++)
    {
        for (j = 0; j < colunaB; j++)
        {
            fscanf(fpin, "%i", &aux);
            B[i][j] = aux;
        }
    }
    for (i = 0; i < linhaA; i++)
    {
        for (j = 0; j < colunaB; j++)
        {
            C[i][j] = 0;
            aux = 0;
            for (k = 0; k < linhaB; k++)
            {
                aux += A[i][k] * B[k][j];
            }
            C[i][j] = aux;
            aux = 0;
        }
    }
    /***************** Impress o das matrizes *******************/ � printf("\nMatriz A:");
    fprintf(fpout, "Matriz A:");
    for (i = 0; i < linhaA; i++)
    {
        printf("\n");
        fprintf(fpout, "\n");
        for (j = 0; j < colunaA; j++)
        {
            printf("%-3d", A[i][j]);
            fprintf(fpout, "%-3d", A[i][j]);
        }
    }
    printf("\nMatriz B:");
    fprintf(fpout, "\nMatriz B:");
    for (i = 0; i < linhaB; i++)
    {
        printf("\n");
        fprintf(fpout, "\n");
        for (j = 0; j < colunaB; j++)
        {
            printf("%-3d", B[i][j]);
            fprintf(fpout, "%-3d", B[i][j]);
        }
    }
    printf("\nMatriz C - A x B:");
    fprintf(fpout, "\nMatriz C = A x B:");
    for (i = 0; i < linhaA; i++)
    {
        printf("\n");
        fprintf(fpout, "\n");
        for (j = 0; j < colunaB; j++)
        {
            printf("%-3d", C[i][j]);
            fprintf(fpout, "%-3d", C[i][j]);
        }
    }
    printf("\n>>> Resultados impressos em out.txt!");
    imat_free(A, linhaA);
    imat_free(B, linhaB);
    imat_free(C, linhaA);
Fim:
    if (!(fpin == NULL))
        fclose(fpin);
    if (!(fpout == NULL))
        fclose(fpout);
}