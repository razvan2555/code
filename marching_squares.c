#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int R, G, B;
} pixel;

int citire_matrice_pixel(int n, int m, int maxim, pixel **a)
{
	int nr = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d %d %d", &a[i][j].R, &a[i][j].G, &a[i][j].B);
			if(a[i][j].R > maxim || a[i][j].R < 0)
			{
				printf("Eroare: valoare pixel necorespunzatoare");
				return 0;
			}
			if(a[i][j].G > maxim || a[i][j].G < 0)
			{
				printf("Eroare: valoare pixel necorespunzatoare");
				return 0;
			}
			if(a[i][j].B > maxim || a[i][j].B < 0)
			{
				printf("Eroare: valoare pixel necorespunzatoare");
				return 0;
			}
		}
	}
	if (nr % 3 != 0)
	{
		printf("Eroare: eroare citire pixeli\n");
		return 0;
	}
	return 1;
}

void free_mem_matrice_pixel(int n, pixel **a)
{
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

void afisare_matrice_pixel(int n, int m, pixel **a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%d %d %d\n", a[i][j].R, a[i][j].G, a[i][j].B);
}

void afisare_matrice(int n, int m, int **b)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
}

void afisare_matrice_double(int n, int m, double **b)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%f ", b[i][j]);
		printf("\n");
	}
}

void free_mem_matrice_double(int n, double **a)
{
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

void free_mem_matrice_int(int n, int **a)
{
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

void medie_matrice_pixel(int n, int m, pixel **a, double **b)
{
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			b[i][j] = (double)(a[i][j].R + a[i][j].G + a[i][j].B) / 3;
	}
}

void treshold(int n, int m, double **b) ///// VEZI CONDITIA DIN CHECKER DACA E > SAU >=
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			if(b[i][j] > 200) /// AM SCHIMBAT LA 100 DIN 200// PUNE 200
				b[i][j] = 1;
			else
				b[i][j] = 0;
	}
}

void binar(int n, int m, double **b, int **c)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			c[i][j] = 8 * b[i][j] + 4 * b[i][j + 1] + 2 * b[i + 1][j + 1] + b[i + 1][j];
}

void shape_0(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 1][4 * j + 1] = 0;
}

void shape_1(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 4][4 * j + 1] = 7;
	d[4 * i + 3][4 * j + 1] = 9;
	d[4 * i + 4][4 * j + 2] = 9;
}

void shape_2(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 3][4 * j + 4] = 9;
	d[4 * i + 4][4 * j + 3] = 9;
	d[4 * i + 4][4 * j + 4] = 7;
}

void shape_3(int i, int j, int **d)
{
	i--; j--;
	for (int k = 1; k < 5; k++){
		d[4 * i + 3][4 * j + k] = 9;
		d[4 * i + 4][4 * j + k] = 7;
	}
}

void shape_4(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 1][4 * j + 3] = 9;
	d[4 * i + 2][4 * j + 4] = 9;
	d[4 * i + 1][4 * j + 4] = 7;
}

void shape_5(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 1][4 * j + 3] = 9;
	d[4 * i + 2][4 * j + 4] = 9;
	d[4 * i + 1][4 * j + 4] = 7;
	d[4 * i + 3][4 * j + 1] = 9;
	d[4 * i + 4][4 * j + 2] = 9;
	d[4 * i + 4][4 * j + 1] = 7;
}

void shape_6(int i, int j, int **d)
{
	i--; j--;
	for (int k = 4 * i; k < 4 * i + 4; k++){
		d[k + 1][4 * j + 3] = 9;
		d[k + 1][4 * j + 4] = 9;
	}
}

void shape_7(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 1][4 * j + 2] = 9;
	d[4 * i + 2][4 * j + 1] = 9;
	for (int k = 4 * i; k < 4 * i + 4; k++){
		for (int q = 4 * j; q < 4 * j + 4; q++){
			if(k + q >= 4 * i + 4 * j)
				d[k + 1][q + 1] = 7;
		}
	}
}

void shape_8(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 1][4 * j + 2] = 9;
	d[4 * i + 2][4 * j + 1] = 9;
	d[4 * i + 1][4 * j + 1] = 7;
}

void shape_9(int i, int j, int **d)
{
	for (int k = 4 * (i - 1); k < 4 * i + 4; k++){
		d[k + 1][4 * j + 2] = 9;
		d[k + 1][4 * j + 1] = 7;
	}
}

void shape_10(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 1][4 * j + 2] = 9;
	d[4 * i + 2][4 * j + 1] = 9;
	d[4 * i + 1][4 * j + 1] = 7;
	d[4 * i + 3][4 * j + 4] = 9;
	d[4 * i + 4][4 * j + 3] = 9;
	d[4 * i + 4][4 * j + 4] = 7;
}

void shape_11(int i, int j, int **d)
{
	i--; j--;
	for (int k = 4 * i; k < 4 * i + 4; k++){
		for (int q = 4 * j; q < 4 * j + 4; q++){
			if (k == q + 1|| k <= q)
				d[k + 1][q + 1] = 7;
		}
	}
	d[4 * i + 1][4 * j + 3] = 9;
	d[4 * i + 2][4 * j + 4] = 9;
	d[4 * i + 1][4 * j + 4] = 0;
}

void shape_12(int i, int j, int **d)
{
	i--; j--;
	for (int q = 4 * j; q < 4 * j + 4; q++){
		d[4 * i + 2][q + 1] = 9;
		d[4 * i + 1][q + 1] = 7;
	}
}

void shape_13(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 3][4 * j + 4] = 9;
	d[4 * i + 4][4 * j + 3] = 9;
	for (int k = 4 * i; k < 4 * i + 4; k++){
		for (int q = 4 * j; q < 4 * j + 4; q++){	
			if(k + q <= 4 * i + 4 * j + 4)
				d[k + 1][q + 1] = 7;
		}
	}
}

void shape_14(int i, int j, int **d)
{
	i--; j--;
	d[4 * i + 3][4 * j + 1] = 9;
	d[4 * i + 4][4 * j + 2] = 9;
	for (int k = 4 * i; k < 4 * i + 4; k++){
		for (int q = 4 * j; q < 4 * j + 4; q++){	
			if(k == q + 1 || k <= q)
				d[k + 1][q + 1] = 7;
		}
	}
}

void shape_15(int i, int j, int **d)
{
	i--; j--;
	for (int k = 4 * i; k < 4 * i + 4; k++){
		for (int q = 4 * j; q < 4 * j + 4; q++){
				d[k + 1][q + 1] = 7;
		}
	}
}

void shape(int n, int m, int **x, int **d)
{
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (x[i][j] == 0)
				shape_0(i, j, d);
			if (x[i][j] == 1)
				shape_1(i, j, d);
			if (x[i][j] == 2)
				shape_2(i, j, d);
			if (x[i][j] == 3)
				shape_3(i, j, d);
			if (x[i][j] == 4)
				shape_4(i, j, d);
			if (x[i][j] == 5)
				shape_5(i, j, d);
			if (x[i][j] == 6)
				shape_6(i, j, d);
			if (x[i][j] == 7)
				shape_7(i, j, d);
			if (x[i][j] == 8)
				shape_8(i, j, d);
			if (x[i][j] == 9)
				shape_9(i, j, d);
			if (x[i][j] == 10)
				shape_10(i, j, d);
			if (x[i][j] == 11)
				shape_11(i, j, d);
			if (x[i][j] == 12)
				shape_12(i, j, d);
			if (x[i][j] == 13)
				shape_13(i, j, d);
			if (x[i][j] == 14)
				shape_14(i, j, d);
			if (x[i][j] == 15)
				shape_15(i, j, d);
		}	
	}
}

void RESIZE(int n, int m, pixel **a, pixel **r)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 4 * i; k < i * 4 + 4; k++)
				for (int q = 4 * j; q < 4 * j + 4; q++)
					r[k][q] = a[i][j];
							
	afisare_matrice_pixel(n * 4, m * 4, r);
}

void WRITE(int n, int m, int maxim, pixel **a)
{
	printf("Imagine citita cu succes [%d-%d]\n", n, m);
	printf("P3\n");
	printf("%d %d\n", n, m);
	printf("%d\n", maxim);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			printf("%d %d %d\n", a[i][j].R, a[i][j].G, a[i][j].B);
	}
	printf("Gigel a terminat");
}

int main (void)
{
	char functie[11], type[5];
	int m, n, maxim;
	fgets(functie, 11, stdin);
	fgets(type, 5, stdin);
	if (type[0] != 'P' || type[1] != '3'){ 
		printf("Eroare: trebuie sa fie P3\n");
		return 0;
	}
	scanf("%d %d %d", &m, &n, &maxim);
	pixel **a = (pixel **)malloc(n * sizeof(pixel *));
			for (int i = 0; i < n; i++)
				a[i] = (pixel *)malloc(m * sizeof(pixel));

	if (citire_matrice_pixel(n, m, maxim, a) == 0)
	{
		free_mem_matrice_pixel(n, a);
		return 0;
	}
	pixel **r = (pixel **)calloc((n * 4), sizeof(pixel *));
			for(int i = 0; i < n * 4; i++)
				r[i] = (pixel *)calloc((m * 4), sizeof(pixel));

	
	while (scanf("%s", functie) && (functie[0] < '0' || functie[0] > '9'))
	{
		if (strcmp(functie, "WRITE") == 0)
			WRITE(n, m, maxim, a);

		if (strcmp(functie, "RESIZE") == 0)
			RESIZE(n, m, a, r);

		if (strcmp(functie, "INIT_CONTUR") == 0)
		{
			int **c = (int **)calloc(4, sizeof(int *));
			for(int i = 0; i < 4; i++)
				c[i] = (int *)calloc(4, sizeof(int));
			int o = 0;
			while(o < 16)
			{
				int i = 1; int j = 1;
				if (o == 0)
				{
					shape_0(i, j, c);
					afisare_matrice(4, 4, c);
					c = NULL;
				}
				if (o == 1)
				{
					shape_1(i, j, c);
					afisare_matrice(4, 4, c);
					c = NULL;
				}
				if (o == 2)
				{
					shape_2(i, j, c);
					afisare_matrice(4, 4, c);
					c = NULL;
				}
				if (o == 3)
				{
					shape_3(i, j, c);
					afisare_matrice(4, 4, c);
					c = NULL;
				}
				if (o == 4)
				{
					shape_4(i, j, c);
					afisare_matrice(4, 4, c);
					c = NULL;
				}
				if (o == 5)
					shape_5(i, j, c);
				if (o == 6)
					shape_6(i, j, c);
				if (o == 7)
					shape_7(i, j, c);
				if (o == 8)
					shape_8(i, j, c);
				if (o == 9)
					shape_9(i, j, c);
				if (o == 10)
					shape_10(i, j, c);
				if (o == 11)
					shape_11(i, j, c);
				if (0 == 12)
					shape_12(i, j, c);
				if (o == 13)
					shape_13(i, j, c);
				if (o == 14)
					shape_14(i, j, c);
				if (o == 15)
					shape_15(i, j, c);

			}
		}
		if (strcmp(functie, "EXIT") == 0)
		{
			free_mem_matrice_pixel(n * 4, r);
			free_mem_matrice_pixel(n, a);
			return 0;
		}
	}
	/*double **b = (double **)malloc(n * sizeof(double *));
	for (int i = 0; i < n; i++)
		b[i] = (double *)malloc(m * sizeof(double));

	medie_matrice_pixel(n, m, a, b);
	free_mem_matrice_pixel(n, a);
	treshold(n, m, b);

	// ALOCARE DINAMICA MATRICE
	int **c = (int **)calloc((n - 1), sizeof(int *));
	for(int i = 0; i < n - 1; i++)
		c[i] = (int *)calloc((m - 1), sizeof(int));
	
	binar(n, m, b, c);
	free_mem_matrice_double(n, b);
	

	int **x = (int **)calloc((n + 1), sizeof(int *));
	for(int i = 0; i < n + 1; i++)
		x[i] = (int *)calloc((m + 1), sizeof(int));
	
	for (int i = 1; i < n; i++)
		for(int j = 1; j < m; j++)
			x[i][j] = c[i - 1][j - 1];
	printf("\n\n");
	afisare_matrice(n-1, m-1, c);
	free_mem_matrice_int(n - 1, c);
	
	

	n--; m--;
	//// ALOCARE DINAMICA MATRICE
	int **d = (int **)calloc((n * 4 + 2), sizeof(int *));
	for (int i = 0; i < n * 4 + 2; i++)
		d[i] = (int *)calloc(m * 4 + 2, sizeof(int));
	
	shape(n, m, x, d);
	n = n * 4 + 2;
	m = m * 4 + 2;
	
	free_mem_matrice_int((n-2) / 4 + 2, x);
	printf("\n");
	afisare_matrice(n, m, d);
	free_mem_matrice_int(n, d);
	*/
	return 0;
}
// de facut functii pt read , write ,,,,
// de fct grid cu separeare de marching squares.
// VEZI NEAPARAT CULORILE DIN CHECKER SI SCHIMBA IN TOATE FUNCTIE CU SHAPE
//STERGE TO CE E CU VERDE LA FINAL
