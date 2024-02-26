#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int N, K, k = 0, ANG[100000], AUX[100000];
long S[10000000];
void citire(FILE* f) { //functia care citeste N=nr angajati, K= puterea maxima si cele N salarii din fisier
	int x = 0;
	printf("DATELE CITITE DIN FISIERUL IN.TXT:\n");
	if (f == NULL) // conditia pentru verificarea citirii
	{
		printf("EROARE LA CITIRE!");
		exit(0);
	}
	fscanf(f, "%d", &N); // citire N
	fscanf(f, "%d", &K);// citire K
	if (K < 0 || K>9) // puterea maxima a lui K este 9 si puterea minima este 0
	{
		printf("K TREBUIE SA FIE INTRE 0 SI 9!");
		exit(0);
	}
	while (!feof(f))
	{
		fscanf(f, "%d", &ANG[x]); // citirea salariilor pana la finalul fisierului
		x++;
	}
}
void putere_10() { // functia care scade din numar puteri tot mai mici ale lui 10
	int i = 0, n;
	for (i = 0; i < N; i++)
	{
		n = 0;
		printf("%d\n", ANG[i]);
		AUX[i] = ANG[i];
		while (AUX[i]) 
		{
			if (AUX[i] >= pow(10, K - n)) 
			{
				S[k] = pow(10, K - n);
				k++;
				AUX[i] = AUX[i] - pow(10, K - n); // se scade din AUX puterea maxima posibila
			}
			else
			{
				n++; // scadem puterea maxima posibila
			}
		}
	}
}
void afisare(FILE* f) //functia de afisare
{
	int i, x = 0, suma = 0;
	for (i = 0; i < k; i++)
	{
		if (suma == ANG[x]) //daca suma bucatilor din salariul unui angajat este egala cu suma initiala
		{					// se trece la un rand nou,pentru a afisa suma urmatorului
			fprintf(f, "\n");
			suma = 0;
			x++;
		}
		fprintf(f, "%d ", S[i]);
		suma = suma + S[i];
	}
	fprintf(f, "\n");

}
int main()
{
	FILE* f, * out;
	f = fopen("in.txt", "r");
	citire(f);
	putere_10();
	out = fopen("out.txt", "w+t");
	afisare(out);
	fclose(f);
	fclose(out);
	printf("PRELUCAREA DATELOR A FOST SALVATA IN FISIERUL OUT.TXT!\n");
	system("pause");
	return 0;
}