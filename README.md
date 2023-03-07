# gerenciamento_de_conjuntos
projeto de programação em c

O objetivo do trabalho é implementar um programa que gerencie uma 
quantidade determinada de conjuntos de valores inteiros. O modelo consiste no uso 
de uma matriz MxN, sendo M e N constantes.

Cada linha da matriz é usada para representar um conjunto de valores, sendo que 
o programa deve garantir que os limites da matriz não sejam ultrapassados. Portanto, 
não deve ser possível criar mais do que M conjuntos, e cada conjunto não pode ter mais 
do que N valores.

A matriz deve ser inicializada com zeros, indicando que está vazia. O zero, 
portanto, não é considerado como um valor válido.

O programa fornece o seguinte menu de opções:
1. Criar um novo conjunto vazio;
2. Inserir dados em um conjunto: o usuário deve informar o índice i do conjunto 
em que deseja fazer a inserção.
a. O usuário pode inserir vários valores na sequência; o processo se encerra 
quando é digitado o valor zero ou quando se atingiu a quantidade N 
(número de colunas da matriz);
b. Como um conjunto deve possuir valores distintos, o programa não considerará valores repetidos.
3. Remover um conjunto.
4. Fazer a união entre dois conjuntos: o usuário deve informar os índices dos 
conjuntos que fazem parte dessa operação; o conjunto resultante é adicionado à 
matriz de conjuntos como uma nova linha da matriz;
5. Fazer a intersecção entre dois conjuntos;
6. Mostrar um conjunto, dado o seu índice;
7. Mostrar todos os conjuntos;
8. Busca por um valor: dado um valor, deve-se mostrar os índices dos conjuntos 
que contenham esse valor;
9. Sair do programa
