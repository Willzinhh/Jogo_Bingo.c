//O jogo terá três participantes;
//Cada cartela deve ter 15 números aleatórios de 1 a 60, distribuídos em 3 linhas;
//A cada rodada, um número aleatório é sorteado e o programa deve verificar se ele aparece nas cartelas dos jogadores. Os números sorteados devem ser marcados nas cartelas;
//O jogador que conseguir completar toda a cartela grita “BINGO!” e é o vencedor.
//Todo jogo deve acontecer de forma automática, ou seja, sem entradas explícitas do usuário. Utilize funções como getchar() e system("cls") para facilitar o entendimento do que acontece.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

		//funçoes chamadas ni Inicio//
int cartelas(int m[3][5], int i, int j);
int validarsorteio(int s, int usados[60], int i);
int sorteio(int m[3][5], int marcados[3][5], int s);
void setColor(int ForgC);


		//Função principal//
int main (){
  int A[3][5],B[3][5],C[3][5];
  srand(time(NULL));
  int n, p;
 
  setColor(5);
  printf("Bem-Vind@ ao Bingo!\n");
  setColor(1);
  printf("Este programa foi criado pelos alunos Willian e Talia!\n\n");
  setColor(7);
 
		//Criação das cartelas com Auxilio da função Cartelas//
 
//joagor 1 //
printf("Digite o nome do jogador 1: ");
scanf("%d", &p);
printf("\n");
while (getchar() != '\n');

printf("A cartela do jogador 1 foi gerada:\n\n");
for (int i=0;i<3;i++){
        for (int j=0;j<5;j++){
            A[i][j]=rand()%60+1;
  n= cartelas(A, i, j);
        A[i][j]=n;

    printf(" \t %d ", A[i][j]);
    }
     printf("\n");
}
printf("\n");

//jogador 2//
printf("Digite o nome do jogador 2: ");
scanf("%d", &p);
printf("\n");
while (getchar() != '\n');

printf("A cartela do jogador 2 foi gerada:\n\n");
for (int i=0;i<3;i++){
        for (int j=0;j<5;j++){
            B[i][j]=rand()%60+1;
B[i][j]= cartelas(B, i, j);
       

    printf(" \t %d ", B[i][j]);
    }
     printf("\n");
}
printf("\n");

//jogador 3//
printf("Digite o nome do jogador 3: ");
scanf("%d", &p);
printf("\n");
while (getchar() != '\n');

printf("A cartela do jogador 3 foi gerada:\n\n");
for (int i=0;i<3;i++){
        for (int j=0;j<5;j++){
            C[i][j]=rand()%60+1;
C[i][j]= cartelas(C, i, j);
       
    printf(" \t %d ", C[i][j]);
    }
     printf("\n");
}
printf("\n");

setColor(1);
printf("Vamos comecar? Aperte 'enter' para iniciar!");
setColor(7);
while (getchar() != '\n');
system("cls");
	
		// variaveis para receber valores de pontuação e para sorteio//

int A_marcados[3][5], B_marcados[3][5], C_marcados[3][5];
int Aacertos, Bacertos, Cacertos, Apontos=0, Bpontos=0, Cpontos=0, s, sn, cont;

    // Sortear os números com auxilio da função Validarsorteio//
   
    for(int i=0;i<60;i++){
int usados[60];
sn = rand() %60+1;
s = validarsorteio(sn,usados, i);
usados[i]=s;




setColor(1);
printf(" O NUMERO SORTEADO FOI %d\n",s);
setColor(7);
printf("__________________________________________________\n\n");

	//Chmar funçao para vereficar se tem aceros + incrementar pontos caso acertos sendo V //
						// com Auxilio da função Sorteio//
	
printf("Cartela do jogador 1:\n\n");
Aacertos= sorteio(A, A_marcados, s);
if(Aacertos==1){
Apontos++;
}

printf("Cartela do jogador 2:\n\n");
Bacertos=sorteio(B, B_marcados, s);
if(Bacertos==1){
Bpontos++;
}

printf("Cartela do jogador 3:\n\n");
Cacertos=sorteio(C, C_marcados, s);
if(Cacertos==1){
Cpontos++;
}

setColor(2);
printf("Pressione 'enter' para continuar :)");
setColor(7);
while (getchar() != '\n');
system("cls");

		//Variaveis para continuação do jogo e Empate//
int continuar, num1, num2,  num3;


		//Caso empate esolha se continuar e decidir um ganhador enre os empatados//
		
if(Apontos == 15 && Bpontos == 15 || Apontos == 15 && Cpontos == 15 || Bpontos == 15 && Cpontos == 15 || Apontos == 15 && Bpontos == 15 && Cpontos == 15)
{
	printf("Houve um empate entre todos os jogadores!\n");
            printf("Deseja continuar o jogo? Digite (1) para continuar ou (0) para encerrar em empate.\n");
            scanf("%d", &continuar);
            if (continuar == 0) {
                printf("O jogo terminou em empate!\n");
                break;
            } 
			else{
            	printf("Disputa para desempate:\n");
            	if(Apontos == 15)
            	{
            		num1 = rand() %60+1;
            		printf("O numero do jogador 1 eh %d\n", num1);
				}
				
				if(Bpontos == 15)
				{
					num2 = rand() %60+1;
            		printf("O numero do jogador 2 eh %d\n", num2);
				}
				
				if(Cpontos == 15)
				{
					num3 = rand() %60+1;
            		printf("O numero do jogador 3 eh %d\n", num3);
				}
				
				if(num1 > num2 || num1 > num3)
				{
					printf("Vitoria do jogador 1!!");
				}
				
				if(num2 > num1 || num2 > num3)
				{
					printf("Vitoria do jogador 2!!");
				}
				
				else{
					printf("Vitoria do jogador 3!!");
				}
            	break;
			}
}

		//Apresentação da pagina de votoria ao ganhador da partida//
		
if(Apontos==15 && Cpontos<15 && Bpontos<15){
Apontos=0;
printf(" Jogador 1 Grita BINGO!!!! \n PARABENS!!\n\n");
printf(" Deseja continuar o jogo\n Digite (1) para continuar e (0) para encerar o jogo\n\n");
scanf("%d",&continuar);
if(continuar == 0 ){
break;
}
else if(continuar == 1 ){
system("cls");
}
}

if(Bpontos==15 && Apontos<15 && Cpontos<15){
Bpontos=0;
printf(" Jogador 2 Grita BINGO!!!! \n PARABENS!!\n\n");
printf(" Deseja continuar o jogo\n Digite (1) para continuar e (0) para encerar o jogo\n\n");
scanf("%d",&continuar);
if(continuar == 0 ){
break;
}
else if(continuar == 1 ){
system("cls");
}
}

if(Cpontos==15 && Apontos<15 && Bpontos<15){
Cpontos=0;
printf(" Jogador 3 Grita BINGO!!!! \n PARABENS!!\n\n");
printf(" Deseja continuar o jogo\n Digite (1) para continuar e (0) para encerar o jogo\n\n");
scanf("%d",&continuar);
if(continuar == 0 ){
break;
}
else if(continuar == 1 ){
system("cls");
}
}
}

		
setColor(4);
printf("\n\n	O bingo chegou ao fim!");
setColor(7);
return 0;
}

		//Função auxiliar para criação das cartelas//
		
int cartelas(int m[3][5], int i, int j){
srand(time(NULL));
int cont;
    do{  
cont=0;
        for (int l=0;l<3;l++){
            for (int c=0;c<5;c++){
                     
if (m[i][j]==m[l][c] && (i!=l || j!=c)){
                m[i][j]=rand()%60+1;
                        cont++;
                    }
            }
        }
    } while(cont!=0);

return m[i][j];
}

		//Função para validar se numero sorteado ja foi utilizado//
		
int validarsorteio(int s, int usados[60], int i){
int cont, v;
do{
v=i;
cont=0;
for(v;v>=0;v--){

if(usados[v]==s){
s= rand()% 60+1;
cont++;
}
}

}while(cont>0);
return s;
}

		//Função para determinar o ganhador e marcar numeros sorteados contidos na cartela//

int sorteio(int m[3][5], int marcados[3][5], int s){
int i, j, w, acertos=0;

for(i=0;i<3;i++){
for(j=0;j<5;j++){
if(m[i][j]==s){
setColor(4); //numero com cor vermelha
printf(" \t %d ", m[i][j]);
setColor(7); //volta a cor padrao
marcados[i][j] = 1;
acertos++;
}
else if(marcados[i][j]==1){
setColor(4);
printf("\t%d", m[i][j]);
setColor(7);
}
else{
printf("\t%d", m[i][j]);
}
}
printf("\n");
}
printf("\n");
if(acertos!=0){

setColor(1);
printf(" Voce marcou o numero %d nessa rodada!!\n\n",s);
setColor(7);

}
printf("__________________________________________________\n\n");
return acertos;
}

void setColor(int ForgC){ //funcao para a troca de cor
WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}