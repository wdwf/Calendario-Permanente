#include<stdio.h>
#include<locale.h>

int procurarLinha(int L, int C, int mat[L][C], int proc)
{
	//aqui você completa ....
	//esta função retorna a linha em que proc aparece na matriz
  int l,c;

	for(l = 0; l < L; l++) {
    for(c = 0; c < C; c++) {	
      if(mat[l][c] == proc) {
        return l;
			}
		}
	}
}

//Calendário permanente de 1901 a 2092

int A1[28][4], A2[28][4];
int B[28][12]=
	{{4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,6,2,4,0,2,5,1,3,6,1}};
int C[7][6];

int main()
{
	int l,c,x;
	//populando a tabela A1
	x=-3;
	for(c=0;c<4;c++)
		for(l=0;l<28;l++, x++)
			if(x<1) A1[l][c]=-1;
			else if(x<100) A1[l][c]=x;
			else if(x==100) A1[l][c]=0;
			else A1[l][c]=-1;

	//populando a tabela A2
	x=-19;
	for(c=0;c<4;c++)
		for(l=0;l<28;l++, x++)
			if(x<1) A2[l][c]=-1;
			else A2[l][c]=x;
	
	//populando a tabela C
	x=1;
	for(c=0;c<6;c++)
		for(l=0;l<7;l++, x++)
			if(x>37) C[l][c]=-1;
			else C[l][c]=x;

	int dia, mes, ano, resposta, linha;
	setlocale(LC_ALL, "Portuguese");
	printf("\nEntre com uma data no formato DD/MM/AAAA: ");
	scanf("%d/%d/%d", &dia, &mes, &ano);

	if(ano<1901 || ano>2092) printf("Erro!! O ano deve ser de 1901 a 2092.\n");

  //extraia os dois últimos dígitos para procurar em A1 ou A2 -----> 
  int anoDigito = ano % 100;
  int result;

  //aqui você completa ......
	//decida se vai usar A1 ou A2
  if(ano < 2000) {

    result = procurarLinha(28, 4, A1, anoDigito);
    //Lado A

  } else {
    result = procurarLinha(28, 4, A2, anoDigito);
    //Lado B

  }

  //com o mês eu terei uma coluna na matriz B (Janeiro é mês 1 mas corresponde à coluna 0, Fevereiro é mês 2 mas corresponde à coluna 1, ........)
	//some o dia de nascimento com o valor encontrado na matriz B
  int result_2 = dia + B[result][mes - 1];

	//procure este último cálculo na matriz C   ------> linha
  int diaDaSemana = procurarLinha(7, 6, C, result_2);

	// linha == 0 ---> Domingo
	// linha == 1 ---> Segunda 
	// ....
  switch(diaDaSemana){
    case 0:
      printf("Domingo");
      break;
    case 1:
      printf("Segunda-feira");
      break;
    case 2:
      printf("Terça-feira");
      break;
    case 3:
      printf("Quarta-feira");
      break;
    case 4:
      printf("Quinta-feira");
      break;
    case 5:
      printf("Sexta-feira");
      break;
    case 6:
      printf("Sabado");
      break;
  }

	return 0;
}
