#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int user_input_linha();
int user_input_coluna();
void inicializa_matriz(int M, int N, int matriz[M][N]);

// funcoes de suporte
int busca_vazio(int M, int N, int matriz[M][N], int i);
int busca_sequencial(int M, int N, int matriz[M][N], int linha, int chave);
int zero_trocar(int M, int N, int matriz[M][N], int linha, int chave);
int busca_indice(int M, int N, int matriz[M][N], int linha, int chave);
int num_rep(int M, int N, int matriz[M][N], int conj1, int conj2, int index);

// opcao 2
void inserir_valor(int M, int N, int matriz[M][N], int cont_conjuntos);
// opcao 3
void remover_conjunto(int M, int N, int matriz[M][N], int cont_conjuntos);
// opcao 4
void uniao_conjuntos(int M, int N, int matriz[M][N], int cont_conjuntos);
// opcao 5
void interseccao_conjuntos(int M, int N, int matriz[M][N], int cont_conjuntos);
// opcao 6
void mostrar_conjunto(int M, int N, int matriz[M][N]);
// opcao 7
void mostrar_todos(int M, int N, int matriz[M][N], int cont_conjuntos);
// opcao 8
void busca_valor(int M, int N, int matriz[M][N], int cont_conjuntos);

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    printf("Digite o número de linhas da matriz:\n");
    int const M = user_input_linha();
    printf("Digite o número de colunas da matriz:\n");
    int const N = user_input_coluna();

    int matriz[M][N];
    inicializa_matriz(M, N, matriz);

    int cont_conjuntos = 0;
    int opcao;
    
    do{
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
        printf("Selecione a operação que deseja realizar na matriz:\n\n");
        printf("1. Criar um novo conjunto vazio,\n");
        printf("2. Inserir dados em um conjunto,\n");
        printf("3. Remover um conjunto,\n");
        printf("4. Fazer a união entre dois conjuntos,\n");
        printf("5. Fazer a intersecção entre dois conjuntos,\n");
        printf("6. Mostrar um conjunto,\n");
        printf("7. Mostrar todos os conjuntos,\n");
        printf("8. Busca por um valor,\n");
        printf("9. Sair do programa.\n");
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
       
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                if(cont_conjuntos < M)
                    cont_conjuntos += 1;
                else
                    printf("Não é possível ultrapassar o limite de linhas da matriz!\n");

                break;
            
            case 2:
                inserir_valor(M, N, matriz, cont_conjuntos);

                break;

            case 3:
                remover_conjunto(M, N, matriz, cont_conjuntos);
                cont_conjuntos -= 1;

                break;
            
            case 4:
                if(cont_conjuntos < M){
                    uniao_conjuntos(M, N, matriz, cont_conjuntos);
                    cont_conjuntos++;
                }
                else
                    printf("Não é possível ultrapassar o limite de linhas da matriz!\n");
                
                break;
            
            case 5:
                if(cont_conjuntos < M){
                    interseccao_conjuntos(M, N, matriz, cont_conjuntos);
                    cont_conjuntos++;
                }
                else
                    printf("Não é possível ultrapassar o limite de linhas da matriz!\n");

                break;

            case 6:
                mostrar_conjunto(M, N, matriz);

                break;

            case 7:
                mostrar_todos(M, N, matriz, cont_conjuntos);

                break;

            case 8:
                busca_valor(M, N, matriz, cont_conjuntos);

            case 9:
                break;
            
            default:
                printf("Essa opção é inválida!\n");
                printf("As opções disponíveis compreendem de 0 até 9\n");
                printf("Insira uma nova opção!\n");
                break;
        }

    }while(opcao != 9);


    return 0;
}

int user_input_linha(){
    int user_input;
    scanf("%d", &user_input);

    return user_input;
}

int user_input_coluna(){
    int user_input;
    scanf("%d", &user_input);

    return user_input;
}

void inicializa_matriz(int M, int N, int matriz[M][N]){
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            matriz[i][j] = 0;

    return;
}

int busca_vazio(int M, int N, int matriz[M][N], int i){
    for(int j = 0; j < N; j++)
        if(matriz[i][j] != 0)
            return 0;
    
    return 1;
}

int busca_sequencial(int M, int N, int matriz[M][N], int linha, int chave){
    for(int j = 0; j < N; j++)
        if(matriz[linha][j] == chave)
            return 1;
    
    return 0;
}

int busca_indice(int M, int N, int matriz[M][N], int linha, int chave){
    for(int i = 0; i < N; i++)
        if(matriz[linha][i] == chave)
            return i;
}

int zero_trocar(int M, int N, int matriz[M][N], int linha, int chave){
    for(int j = 0; j < N; j++)
        if(matriz[linha][j] == 0)
            return j;

    return 0;
}

int num_rep(int M, int N, int matriz[M][N], int conj1, int conj2, int index){
    for(int i = 0; i < N; i++)
        if(matriz[conj1][index] == matriz[conj2][i])
            return matriz[conj2][i];

    return 0;
}

// opcao 2
void inserir_valor(int M, int N, int matriz[M][N], int cont_conjuntos){
    int linha;
    int coluna;

    printf("Digite a linha do conjunto que deseja alterar:\n");

    scanf("%d", &linha);

    if(linha > cont_conjuntos - 1){
        printf("Erro: Conjunto %d não foi criado!\n", linha);
        return;
    }
    
    int cont_coluna = 0;

    while(cont_coluna < N){
        scanf("%d", &coluna);

        if(coluna == 0)
            break;
        
        while(busca_sequencial(M, N, matriz, linha, coluna)){
            printf("Esse valor já pertence ao conjunto!\n");
            printf("Insira um novo valor:\n");

            scanf("%d", &coluna);
        }

        if(matriz[linha][cont_coluna] == 0){
            matriz[linha][cont_coluna] = coluna;
            cont_coluna++;
        }
        else{
            if(zero_trocar(M, N, matriz, linha, 0) == 0){
                printf("Não há mais espaço na linha da matriz!\n");
                break;
            }
            else{
                matriz[linha][zero_trocar(M, N, matriz, linha, 0)] = coluna;
                cont_coluna++;
            }
        }
    }
    

    return;
}

// opcao 3
void remover_conjunto(int M, int N, int matriz[M][N], int cont_conjuntos){
    int linha;

    printf("Informe a linha do conjunto que deseja alterar:\n");
    do{
        scanf("%d", &linha);

        if(linha > cont_conjuntos || linha < 0)
            printf("Esse conjunto não existe, selecione outro:\n");

    }while(linha > cont_conjuntos || linha < 0);

    for(int j = 0; j < N; j++)
        matriz[linha][j] = 0;

    for(int i = linha; i < M-1; i++)
        for(int j = 0; j < N; j++)
            matriz[i][j] = matriz[i+1][j]; 

    return;
}

// opcao 4
void uniao_conjuntos(int M, int N, int matriz[M][N], int cont_conjuntos){
    int conj1, conj2;
    
    printf("Selecione dois conjuntos para realizar a união:\n");
    do{
        scanf("%d%d", &conj1, &conj2);

        if(conj1 < 0 || conj1 > cont_conjuntos || conj2 < 0 || conj2 > cont_conjuntos)
            printf("Insira valores válidos para os conjuntos que deseja realizar a união:\n");

    }while(conj1 < 0 || conj1 > cont_conjuntos || conj2 < 0 || conj2 > cont_conjuntos);
    
    int aux[N];
        
        for(int i = 0; i < N; i++)
            aux[i] = 0;

        int h = 0;

        for(int i = 0; i < N; i++)
            if(busca_sequencial(M, N, matriz, conj1, matriz[conj2][i]) == 0){
                aux[h] = matriz[conj2][i];
                h++;
            }
        
        int tamanho_aux = 0;
        int tamanho_conj1 = 0;

        for(int i = 0; i < N; i++){
            if(aux[i] != 0)
                tamanho_aux++;
            if(matriz[conj1][i] != 0)
                tamanho_conj1++;
        }

        if(tamanho_aux + tamanho_conj1 > N){
            printf("Não é possível realizar a união, pois ela é maior que o tamanho do conjunto!\n");
            cont_conjuntos -= 1;
        }
        else{
            int index = 0;

            for(int i = 0; i < N; i++){
                matriz[cont_conjuntos][i] = matriz[conj1][i];
                if(matriz[cont_conjuntos][i] == matriz[conj1][i] && matriz[conj1][i] != 0)
                    index++;
            }

            int j = 0;

            for(int i = index; i < N; i++){
                if(aux[j] != 0){
                    matriz[cont_conjuntos][i] = aux[j];
                    j++;
                }
            }
        }
    
    return;
}

// opcao 5
void interseccao_conjuntos(int M, int N, int matriz[M][N], int cont_conjuntos){
    int conj1, conj2;

    printf("Selecione dois conjuntos para realizar a intersecção:\n");
    do{
        scanf("%d%d", &conj1, &conj2);

        if(conj1 < 0 || conj1 > cont_conjuntos || conj2 < 0 || conj2 > cont_conjuntos)
            printf("Insira valores válidos para os conjuntos que deseja realizar a intersecção:\n");

    }while(conj1 < 0 || conj1 > cont_conjuntos || conj2 < 0 || conj2 > cont_conjuntos);
    
    int index = 0;

    for(int i = 0; i < N; i++){
        matriz[cont_conjuntos][i] = num_rep(M, N, matriz, conj1, conj2, index);
        index++;
    }

    return;
}

// opcao 6
void mostrar_conjunto(int M, int N, int matriz[M][N]){
    int linha;

    do{
        printf("Selecione o conjunto que deseja exibir:\n");
        scanf("%d", &linha);

        if(linha > M || linha < 0)
            printf("O conjunto selecionado não existe, escolha outro!\n");

    }while(linha > M || linha < 0);

    if(busca_vazio(M, N, matriz, linha))
        printf("%d = vazio\n", linha);
    else{
        printf("%d = ", linha);
        for(int j = 0; j < N; j++)
            if (matriz[linha][j] != 0)
                printf("%d ", matriz[linha][j]);
        printf("\n");
    }
    
    return;
}

// opcao 7
void mostrar_todos(int M, int N, int matriz[M][N], int cont_conjuntos){
    if(cont_conjuntos == 0){
        printf("Não existem conjuntos criados no momento!\n");

        return;
    }
    
    printf("Há %d conjuntos:\n", cont_conjuntos);
    
    int i = 0;

    while(i < cont_conjuntos){
        if(busca_vazio(M, N, matriz, i)){
            printf("%d = vazio\n", i);
            i++;
        }
        else{
            printf("%d = ", i);
        
            for(int j = 0; j < N; j++)
                if(matriz[i][j] != 0)
                    printf("%d ", matriz[i][j]);

            printf("\n");
            i++;
        }
    }
    
    return;
}

// opcao 8
void busca_valor(int M, int N, int matriz[M][N], int cont_conjuntos){
    int chave;
    
    printf("Insira um valor para buscar os conjuntos que o possuem:\n");
    scanf("%d", &chave);

    printf("Conjuntos que contêm o valor %d: ", chave);
    
    int verifica = 0;

    for(int i = 0; i < M; i++){
        if(busca_sequencial(M, N, matriz, i, chave)){
            printf("%d ", i);
            verifica++;
        }
    }

    if(verifica == 0)
        printf("nenhum");

    printf("\n");

    return;
}

