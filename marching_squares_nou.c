#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int R, G, B;
} pixel;

int citire_matrice_pixel(int n, int m, int maxim, pixel **a)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if(scanf("%d", &a[i][j].R) != 1)
			{
				printf("Eroare: eroare citire pixeli\n");
				return 0;
			}
			if(scanf("%d", &a[i][j].G) != 1)
			{
				printf("Eroare: eroare citire pixeli\n");
				return 0;
			}
			if(scanf("%d", &a[i][j].B) != 1)
			{
				printf("Eroare: eroare citire pixeli\n");
				return 0;
			}
			if(a[i][j].R > maxim || a[i][j].R < 0)
			{
				printf("Eroare: valoare pixel necorespunzatoare\n");
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
	return 1;
}

void free_mem_matrice_pixel(int n, pixel ***a)
{
	for (int i = 0; i < n; i++) {
		free((*a)[i]);
		(*a)[i] = NULL;
	}
	free(*a);
	*a = NULL;
}

void afisare_matrice_pixel(int n, int m, pixel **a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%d %d %d\n", a[i][j].R, a[i][j].G, a[i][j].B);
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

void free_mem_matrice_double(int n, double ***a)
{
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
		(*a)[i] = NULL;
	}
	*a = NULL;
	free(a);
}

void free_mem_matrice_int(int n, int ***a)
{
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
		(*a)[i] = NULL;
	}
	*a = NULL;
	free(a);
}

void medie_matrice_pixel(int n, int m, pixel **a, double **b)
{
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			b[i][j] = (double)(a[i][j].R + a[i][j].G + a[i][j].B) / 3;
	}
}

void binar(int n, int m, int **b, int **c)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			c[i][j] = 8 * b[i][j] + 4 * b[i][j + 1] + 2 * b[i + 1][j + 1] + b[i + 1][j];
}

void shape_0(int i, int j, pixel **d)
{
	for(int q = 0; q < 4; q++)
	{
		for(int k = 0; k < 4; k++)
		{
			d[4 * i + q][4 * j + k].R = 0;
			d[4 * i + q][4 * j + k].G = 0;
			d[4 * i + q][4 * j + k].B = 0;
		}
	}
}

void shape_1(int i, int j, pixel **d)
{
	d[4 * i + 3][4 * j].R = 180;
	d[4 * i + 3][4 * j].G = 180;
	d[4 * i + 3][4 * j].B = 180;
	d[4 * i + 2][4 * j].R = 255;
	d[4 * i + 2][4 * j].G = 255;
	d[4 * i + 2][4 * j].B = 255;
	d[4 * i + 3][4 * j + 1].R = 255;
	d[4 * i + 3][4 * j + 1].G = 255;
	d[4 * i + 3][4 * j + 1].B = 255;
}

void shape_2(int i, int j, pixel **d)
{
	d[4 * i + 2][4 * j + 3].R = 255;
	d[4 * i + 2][4 * j + 3].G = 255;
	d[4 * i + 2][4 * j + 3].B = 255;
	d[4 * i + 3][4 * j + 2].R = 255;
	d[4 * i + 3][4 * j + 2].G = 255;
	d[4 * i + 3][4 * j + 2].B = 255;
	d[4 * i + 3][4 * j + 3].R = 180;
	d[4 * i + 3][4 * j + 3].G = 180;
	d[4 * i + 3][4 * j + 3].B = 180;
}

void shape_3(int i, int j, pixel **d)
{
	for (int k = 0; k < 4; k++){
		d[4 * i + 2][4 * j + k].R = 255;
		d[4 * i + 2][4 * j + k].G = 255;
		d[4 * i + 2][4 * j + k].B = 255;
		d[4 * i + 3][4 * j + k].R = 180;
		d[4 * i + 3][4 * j + k].G = 180;
		d[4 * i + 3][4 * j + k].B = 180;
	}
}

void shape_4(int i, int j, pixel **d)
{
	d[4 * i][4 * j + 2].R = 255;
	d[4 * i][4 * j + 2].G = 255;
	d[4 * i][4 * j + 2].B = 255;
	d[4 * i + 1][4 * j + 3].R = 255;
	d[4 * i + 1][4 * j + 3].G = 255;
	d[4 * i + 1][4 * j + 3].B = 255;
	d[4 * i][4 * j + 3].R = 180;
	d[4 * i][4 * j + 3].G = 180;
	d[4 * i][4 * j + 3].B = 180;
}

void shape_5(int i, int j, pixel **d)
{
	d[4 * i][4 * j + 3].R = 255;
	d[4 * i][4 * j + 3].G = 255;
	d[4 * i][4 * j + 3].B = 255;
	d[4 * i + 1][4 * j + 3].R = 255;
	d[4 * i + 1][4 * j + 3].G = 255;
	d[4 * i + 1][4 * j + 3].B = 255;
	d[4 * i][4 * j + 3].R = 180;
	d[4 * i][4 * j + 3].G = 180;
	d[4 * i][4 * j + 3].B = 180;
	d[4 * i + 2][4 * j].R = 255;
	d[4 * i + 2][4 * j].G = 255;
	d[4 * i + 2][4 * j].B = 255;
	d[4 * i + 3][4 * j + 1].R = 255;
	d[4 * i + 3][4 * j + 1].G = 255;
	d[4 * i + 3][4 * j + 1].B = 255;
	d[4 * i + 3][4 * j].R = 180;
	d[4 * i + 3][4 * j].G = 180;
	d[4 * i + 3][4 * j].B = 180;
}

void shape_6(int i, int j, pixel **d)
{
	for (int k = 4 * i; k < 4 * i + 4; k++){
		d[k][4 * j + 2].R = 255;
		d[k][4 * j + 2].G = 255;
		d[k][4 * j + 2].B = 255;
		d[k][4 * j + 3].R = 180;
		d[k][4 * j + 3].G = 180;
		d[k][4 * j + 3].B = 180;
	}
}

void shape_7(int i, int j, pixel **d)
{
	for (int k = 4 * i; k < 4 * i + 4; k++){
		for (int q = 4 * j; q < 4 * j + 4; q++){
			if(k + q >= 4 * i + 4 * j)
			{d[k][q].R = 180; d[k][q].G = 180; d[k][q].B = 180;}
		}
	}
	d[4 * i][4 * j].R = 0;
	d[4 * i][4 * j].G = 0;
	d[4 * i][4 * j].B = 0;
	d[4 * i][4 * j + 1].R = 255;
	d[4 * i][4 * j + 1].G = 255;
	d[4 * i][4 * j + 1].B = 255;
	d[4 * i + 1][4 * j].R = 255;
	d[4 * i + 1][4 * j].G = 255;
	d[4 * i + 1][4 * j].B = 255;
	
}

void shape_8(int i, int j, pixel **d)
{
	d[4 * i][4 * j + 1].R = 255;
	d[4 * i][4 * j + 1].G = 255;
	d[4 * i][4 * j + 1].B = 255;
	d[4 * i + 1][4 * j].R = 255;
	d[4 * i + 1][4 * j].G = 255;
	d[4 * i + 1][4 * j].B = 255;
	d[4 * i][4 * j].R = 180;
	d[4 * i][4 * j].G = 180;
	d[4 * i][4 * j].B = 180;
}

void shape_9(int i, int j, pixel **d)
{
	for (int k = 4 * i; k < 4 * i + 4; k++){
		d[k][4 * j].R = 180;
		d[k][4 * j].G = 180;
		d[k][4 * j].B = 180;
		d[k][4 * j + 1].R = 255;
		d[k][4 * j + 1].G = 255;
		d[k][4 * j + 1].B = 255;
	}
}

void shape_10(int i, int j, pixel **d)
{
	d[4 * i][4 * j + 1].R = 255;
	d[4 * i][4 * j + 1].G = 255;
	d[4 * i][4 * j + 1].B = 255;
	d[4 * i + 1][4 * j].R = 255;
	d[4 * i + 1][4 * j].G = 255;
	d[4 * i + 1][4 * j].B = 255;
	d[4 * i][4 * j].R = 180;
	d[4 * i][4 * j].G = 180;
	d[4 * i][4 * j].B = 180;
	d[4 * i + 2][4 * j + 3].R = 255;
	d[4 * i + 2][4 * j + 3].G = 255;
	d[4 * i + 2][4 * j + 3].B = 255;
	d[4 * i + 3][4 * j + 2].R = 255;
	d[4 * i + 3][4 * j + 2].G = 255;
	d[4 * i + 3][4 * j + 2].B = 255;
	d[4 * i + 3][4 * j + 3].R = 180;
	d[4 * i + 3][4 * j + 3].G = 180;
	d[4 * i + 3][4 * j + 3].B = 180;
}

void shape_11(int i, int j, pixel **d)
{
	for (int k = 4 * i; k < 4 * i + 4; k++)
		for (int q = 4 * j; q < 4 * j + 4; q++)
		{d[k][q].R = 180; d[k][q].G = 180; d[k][q].B = 180;}
	d[4 * i][4 * j + 2].R = 255;
	d[4 * i][4 * j + 2].G = 255;
	d[4 * i][4 * j + 2].B = 255;
	d[4 * i + 1][4 * j + 3].R = 255;
	d[4 * i + 1][4 * j + 3].G = 255;
	d[4 * i + 1][4 * j + 3].B = 255;
	d[4 * i][4 * j + 3].R = 0;
	d[4 * i][4 * j + 3].G = 0;
	d[4 * i][4 * j + 3].B = 0;
}

void shape_12(int i, int j, pixel **d)
{
	for (int q = 4 * j; q < 4 * j + 4; q++){
		d[4 * i + 1][q].R = 255;
		d[4 * i + 1][q].G = 255;
		d[4 * i + 1][q].B = 255;
		d[4 * i][q].R = 180;
		d[4 * i][q].G = 180;
		d[4 * i][q].B = 180;
	}
}

void shape_13(int i, int j, pixel **d)
{
	for(int q = 0; q < 4; q++)
	{
		for(int k = 0; k < 4; k++)
		{
			d[4 * i + q][4 * j + k].R = 180;
			d[4 * i + q][4 * j + k].G = 180;
			d[4 * i + q][4 * j + k].B = 180;
		}
	}
	d[4 * i + 2][4 * j + 3].R = 255;
	d[4 * i + 2][4 * j + 3].G = 255;
	d[4 * i + 2][4 * j + 3].B = 255;
	d[4 * i + 3][4 * j + 2].R = 255;
	d[4 * i + 3][4 * j + 2].G = 255;
	d[4 * i + 3][4 * j + 2].B = 255;
	d[4 * i + 3][4 * j + 3].R = 0;
	d[4 * i + 3][4 * j + 3].G = 0;
	d[4 * i + 3][4 * j + 3].B = 0;
}

void shape_14(int i, int j, pixel **d)
{
	d[4 * i + 2][4 * j].R = 255;
	d[4 * i + 2][4 * j].G = 255;
	d[4 * i + 2][4 * j].B = 255;
	d[4 * i + 3][4 * j + 1].R = 255;
	d[4 * i + 3][4 * j + 1].G = 255;
	d[4 * i + 3][4 * j + 1].B = 255;
	for (int k = 4 * i; k < 4 * i + 4; k++){
		for (int q = 4 * j; q < 4 * j + 4; q++){	
			if(k == q + 1 || k <= q)
			{d[k][q].R = 180; d[k][q].G = 180; d[k][q].B = 180;}
		}
	}
}

void shape_15(int i, int j, pixel **d)
{
	for (int k = 4 * i; k < 4 * i + 4; k++)
		for (int q = 4 * j; q < 4 * j + 4; q++)
			{d[k][q].R = 180; d[k][q].G = 180; d[k][q].B = 180;}
}

void shape(int n, int m, int **x, pixel **d)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
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
}

void WRITE(int n, int m, int maxim, pixel **a)
{
	printf("P3\n");
	printf("%d %d\n", n, m);
	printf("%d\n", maxim);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			printf("%d %d %d\n", a[i][j].R, a[i][j].G, a[i][j].B);
	}
}

void INIT_CONTUR()
{
	pixel **c = (pixel **)malloc(4 * sizeof(pixel *));
	for (int i = 0; i < 4; i++)
		c[i] = (pixel *)malloc(4 * sizeof(pixel));
	int i, j, o = 0;
	while(o < 16)
	{
		i = 0; j = 0;
		if (o == 0)
		{
			shape_0(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 1)
		{
			shape_1(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 2)
		{
			shape_2(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 3)
		{
			shape_3(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 4)
		{
			shape_4(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 5)
		{
			shape_5(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 6)
		{
			shape_6(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 180)
		{
			shape_7(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 8)
		{
			shape_8(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 255)
		{
			shape_9(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
			}
		if (o == 10)
		{
			shape_10(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 11)
		{
			shape_11(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 12)
		{
			shape_12(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 13)
		{
			shape_13(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 14)
		{
			shape_14(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		if (o == 15)
		{
			shape_15(i, j, c);
			afisare_matrice_pixel(4, 4, c);
			printf("\n");
		}
		for(int h = 0; h < 4; h++)
			for(int g = 0; g < 4; g++)
			{
				c[h][g].R = 0;
				c[h][g].G = 0;
				c[h][g].B = 0;
			}
		o++;
	}
}

void GRID(int n, int m, pixel **a, double **b, int **c)
{
	medie_matrice_pixel(n, m, a, b);
	
	for (int i = 0; i <= n; i += 4){
		for (int j = 0; j <= m; j += 4){
			if(i == 0)
			{
				if(j == 0)
				{
					b[i][j] += b[i + 1][j + 1];
					b[i][j] /= 2;
				}
				else if(j == m)
					{
						b[i][j] += b[i + 1][j - 1];
						b[i][j] /= 2;
					}
					else
					{
						b[i][j] += b[i + 1][j - 1] + b[i + 1][j + 1];
						b[i][j] /= 3;
					}
			}
			else if(i == n)
			{
				if(j == 0)
				{
					b[i][j] += b[i - 1][j + 1];
					b[i][j] /= 2;
				}
				else 
					if(j == m)
					{
						b[i][j] += b[i - 1][j - 1];
						b[i][j] /= 2;
					}
					else
					{
						b[i][j] += b[i - 1][j - 1] + b[i - 1][j + 1];
						b[i][j] /= 3;
					}
			}
			else
			{
				if(j == m)
				{
					b[i][j] += b[i - 1][j - 1] + b[i + 1][j - 1];
					b[i][j] /= 3;
				}
				else
				{
					b[i][j] += b[i - 1][j - 1] + b[i - 1][j + 1] + b[i + 1][j - 1] + b[i + 1][j + 1];
					b[i][j] /= 4;
				}
			}		
		}
	}
	for (int i = 0; i <= n; i += 4)
		for (int j = 0; j <= m; j += 4)
			if(b[i][j] >= 200)
				c[i / 4][j / 4] = 1;
			else
				c[i /4][j / 4] = 0;
	
	free_mem_matrice_double(n + 1, &b);
	printf("Grid calculat cu success [%d - %d] matrice grid\n", n / 4 + 1, m / 4 + 1);
}

void MARCH(int n, int m, pixel **a, double **b, int **c, int **d, pixel **e, int okg)
{
	c = (int **)malloc((n / 4 + 1) * sizeof(int *));
	for (int i = 0; i < (n / 4 + 1); i++)
		c[i] = (int *)malloc((m / 4 + 1) * sizeof(int));

	if(okg == 0)
	{	
		GRID(n, m, a, b, c);
		n = n / 4 + 1;
		m = m / 4 + 1;
		binar(n, m, c, d);
	}
	else
		binar(n / 4 + 1, m / 4 + 1, c, d);
	
	free_mem_matrice_int(n, &c);
}

int main (void)
{
	char functie[30], type[5];
	int m, n, maxim, oka = 0, okb = 0, okc = 0, okd = 0, oke = 0, okr = 0, nrr, okg = 0, nra, nrb, nrc, nrd, nre, okresize = 0;
	pixel **a = NULL, **r = NULL, **e = NULL;
	double **b;
	int **c, **d;
	
	while (scanf("%s", functie) && (functie[0] < '0' || functie[0] > '0') && 
	strcmp(functie, "EXIT") != 0)
	{ 
		if(strcmp(functie, "RESIZE") == 0)
		{
			if(okresize == 1)
			{
				if(oka == 1)
					free_mem_matrice_pixel(n, &a);
				n = nrr; m = nrr;
				nra = n;
				a = (pixel **)malloc(n * sizeof(pixel *));
				for (int i = 0; i < n; i++)
					a[i] = (pixel *)malloc(m * sizeof(pixel));
				oka = 1;
				
				for(int i = 0; i < n; i++)
					for(int j = 0; j < n; j++)
						a[i][j] = r[i][j];

				free_mem_matrice_pixel(nrr, &r);
				okr = 0;
				okresize = 0;
			}

			r = (pixel **)malloc((n * 4) * sizeof(pixel *));
			for(int i = 0; i < (n * 4); i++)
				r[i] = (pixel *)calloc((m * 4), sizeof(pixel));
			
			okresize = 1;
			RESIZE(n, m, a, r);
			nrr = n * 4;
			okr = 1;
			printf("Imagine redimensionata cu succes [%d-%d]\n", nrr, nrr);
		}
		if (strcmp(functie, "INIT_CONTUR") == 0)
		{
			c = (int **)calloc(4, sizeof(int *));
			for(int i = 0; i < 4; i++)
				c[i] = (int *)calloc(4, sizeof(int));
			INIT_CONTUR();
			free_mem_matrice_int(4, &c);
		}
		if (strcmp(functie, "GRID") == 0)
		{
			b = (double **)calloc(n + 1, sizeof(double *));
			for (int i = 0; i < n + 1; i++)
				b[i] = (double *)calloc(m + 1, sizeof(double));
			okb = 1; nrb = n + 1;

			c = (int **)malloc((n / 4 + 1) * sizeof(int *));
			for (int i = 0; i < (n / 4 + 1); i++)
				c[i] = (int *)malloc((m / 4 + 1) * sizeof(int));
			okc = 1; nrc = n / 4 + 1;

			if (okresize == 1)
			{
				GRID(n, m, r, b, c);
				free_mem_matrice_pixel(nrr, &r);
				okr = 0;
			}
			else
			{
				GRID(n, m, a, b, c);
				free_mem_matrice_pixel(nra, &a);
				oka = 0;
			}
			free_mem_matrice_double(nrb, &b);
				okb = 0;

			okg = 1;
		}
		if (strcmp(functie, "MARCH") == 0)
		{
			d = (int **)malloc((n / 4) * sizeof(int *));
			for (int i = 0; i < (n / 4); i++)
				d[i] = (int *)malloc((m / 4) * sizeof(int));
			okd = 1; nrd = n / 4;

			if(okresize == 1)
				MARCH(n, m, r, b, c, d, e, okg);
			else
				MARCH(n, m, a, b, c, d, e, okg);
			e = (pixel **)calloc(n, sizeof(pixel *));
			for (int i = 0; i < n; i++)
				e[i] = (pixel *)calloc(m, sizeof(pixel));
			oke = 1; nre = n;
			
			shape(n / 4 , m / 4, d, e);
		}
		if (strcmp(functie, "WRITE") == 0)
		{
			if (okresize == 1)
				WRITE(nrr, nrr, maxim, r);
			else
				WRITE(nra, nra, maxim, a);
			
		}

		if (strcmp(functie, "READ") == 0)
		{
			if (oka == 1)
				free_mem_matrice_pixel(nra, &a);
			okresize = 0;
			fgets(functie, 11, stdin);
			fgets(type, 5, stdin);
			if (type[0] != 'P' || type[1] != '3')
			{ 
				printf("Eroare: trebuie sa fie P3\n");
				return 0;
			}
			scanf("%d %d %d", &n, &m, &maxim);

			a = (pixel **)malloc(n * sizeof(pixel *));
			for (int i = 0; i < n; i++)
				a[i] = (pixel *)malloc(m * sizeof(pixel));

			oka = 1;	
			nra = n;

			if (citire_matrice_pixel(n, m, maxim, a) == 0)
			{
				free_mem_matrice_pixel(nra, &a);
				return 0;
			}
			printf("Imagine citita cu succes [%d-%d]\n", n, m);
		}
	}
	if(strcmp(functie, "EXIT") == 0)
		printf("Gigel a terminat");
	if(oka == 1)
		free_mem_matrice_pixel(nra, &a);
	if(okb == 1)
		free_mem_matrice_double(nrb, &b);
	if(okc == 1)
		free_mem_matrice_int(nrc, &c);
	if(okd == 1)
		free_mem_matrice_int(nrd, &d);
	if(oke == 1)
		free_mem_matrice_pixel(nre, &e);
	if(okr == 1)
		free_mem_matrice_pixel(nrr, &r);	
	
	
	return 0;
}
// de facut functii pt read , write ,,,,
// de fct grid cu separeare de marching squares.
// VEZI NEAPARAT CULORILE DIN CHECKER SI SCHIMBA IN TOATE FUNCTIE CU SHAPE
//STERGE TO CE E CU VERDE LA FINAL
