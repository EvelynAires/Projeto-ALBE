<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=120&color=FFFFFF"/>

[![Typing SVG](https://readme-typing-svg.herokuapp.com/?color=FFFFFF&size=35&center=true&vCenter=true&width=1000&lines=Albe's+Restaurant;Artur,+Luiz,+Beatriz+e+Evelyn+:%29)](https://git.io/typing-svg)

<h1 align="center">Albe's Restaurant</h1>
<h2 align="center">Laboratório de Algoritmos e Estruturas de Dados II</h2>

## *Docente da turma*
- [Kennedy Reurison Lopes]()

## *Componentes da equipe*
- [Ana Beatriz Almeida da Silva](https://github.com/biiaalmeida)
- [Artur Carvalho Gama](https://github.com/Arturzip)
- [Evelyn Cristina de Oliveira Gomes](https://github.com/EvelynAires)
- [Luiz Eduardo de A. Rodrigues](https://github.com/LuizEdu-AR)

 ## *Linguagem Utilizada*

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;


## *Nesse arquivo você verá:*
- [Introdução](#Introdução)
- [Estrutura de Dados](#Estrutura-de-Dados)
- [Organização](#Organização)
- [Funcionalidades do Sistema](#Funcionalidades-do-Sistema)
- [Compilando e Executando o Sistema](#Compilando-e-Executando-o-Sistema)

### *Introdução* 
O ALBE Restaurante se trata de um sistema pensado e desenvolvido para o gerenciamento interno de um restaurante, irá contar com um menu principal de 6 opções onde estará disponibilizando um controle de funcionários, pedidos e estoque do restaurante, Será utilizado para facilitar e deixar mais eficiente, garantindo assim o bom funcionamento do estabelecimento.

### *Estrutura de Dados* 
- Tabela Hash: Uma tabela hash é uma estrutura de dados que armazena pares chave-valor, permitindo a localização rápida de um valor a partir de sua chave. Ela utiliza uma função hash para transformar a chave em um índice no array, onde o valor correspondente é armazenado. Caso duas chaves resultem no mesmo índice (colisão), a tabela hash utiliza métodos para resolver esse conflito; no nosso caso, usamos o método de encadeamento. Isso torna as operações de busca e inserção rápidas e eficientes, logo,  tanto busca quanto inserção se beneficiam da eficiência da tabela hash.

- Árvore AVL: Uma árvore AVL é uma estrutura que organiza dados de forma que o algoritmo possa encontrá-los rapidamente, mantendo o equilíbrio entre suas partes. Isso ajuda a evitar que a árvore fique muito desbalanceada, garantindo que as operações de busca, adição e remoção sejam rápidas. Quando se adiciona ou remove dados, a árvore se ajusta automaticamente para manter esse equilíbrio.
  
- Árvore Binária de Busca: Uma árvore binária de busca organiza dados de forma que cada nó tem um valor, e os valores à esquerda são menores enquanto os da direita são maiores. Isso facilita a busca, onde através de comparações, o algoritmo navega pela árvore. Ao adicionar ou remover dados, a árvore se ajusta para manter essa ordem, garantindo que a busca continue rápida.
  
- Fila: Uma fila é uma estrutura de dados que armazena elementos em ordem, seguindo o princípio "primeiro a entrar, primeiro a sair" (FIFO). Os elementos são adicionados no final e removidos do início. É útil em situações como gerenciamento de tarefas e impressão de documentos.

## *Organização* 
```
📁 - Projeto-ALBE
│
├───Restaurante
│   ├───Restaurante.c
│   └───Restaurante.h
├───Validacoes
│   ├───Validacoes.c
│   └───Validacoes.h
├───main.c
└───README.md
```

## *Funcionalidades do Sistema*
###  Menu Principal
```
---------------------------------
      Bem-Vindo(a)!
1 - Cadastro de funcionarios
2 - Pedidos
3 - Estoque
4 - Menu de Pratos
5 - Registrar Ponto
6 - Sair
---------------------------------
```
### 1 - Cadastro de Funcionários
```
1 - Registrar funcionario
2 - Deletar funcionario
3 - Mostrar funcionarios
4 - Modificar dados
5 - Retornar ao menu principal
```
  Ao selecionar essa opção teremos um menu, implementado com a tabela hash e é responsável pelo controle de funcionários no restaurante, disponibilizando o registro de funcionários para cadastrar os seus dados como o nome, sua função, o pin e o status, disponibilizando também a remoção de funcionários, para exibir os funcionários que estão cadastrados, modificar os dados já cadastrados de um funcionário e a opção de retornar ao menu principal.

### 2- Pedidos
```
   === Menu Pedidos ===
1 - Adicionar pedido
2 - Remover primeiro pedido
3 - Ver fila de pedidos
4 - Sair
```
 Nessa opção, o usuário poderá ter o gerenciamento dos pedidos realizados através do menu de pedidos que foi implementado com fila, disponibilizando as opções de adicionar um pedido, remover o primeiro elemento adicionado e de ver a fila de pedidos atual.
 

### 3 - Estoque 
```
Menu do Estoque:
1 - Inserir um produto
2 - Buscar produto no estoque
3 - Remover produto/quantidade
4 - Exibir todo o estoque
5 - Sair
```
Ao escolher essa opção, irá ser apresentado um menu de estoques implementado com árvore AVL e que disponibilizará as opções de inserir um produto ao estoque, de buscar um produto já adicionado, de remover um produto e de remover a quantidade de um produto e também de exibir todos os produtos que estão no estoque.

### 4 - Menu de Pratos
```
---- Menu de Pratos ----
1 - Criar um novo prato
2 - Exibir todos os pratos
3 - Buscar um prato
4 - Deletar um prato
5 - Alterar os dados de um prato
6 - Voltar ao menu principal
------------------------
```
Selecionando essa opção o usuário terá acesso ao menu de pratos que foi implementado utilizando a árvore binária de busca e ele poderá gerenciar através das funcionalidades de criar um novo prato, exibir todos os pratos, buscar um prato adicionado, deletar um prato e de alterar os dados de um prato que foi adicionado.

### 5 - Registrar Ponto
Nessa opção foi utilizado a tabela hash para ser  realizado o registro de ponto dos funcionários.

### 6 - Sair
 Ao optar o 6, o programa será encerrado.

 ## *Linguagem Utilizada*

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

## *Compilando e Executando o Sistema*
- Utilize o terminal de sua preferência para compilar o programa.
- Navegue até o diretório onde o projeto está localizado.
  
   ```caminho/da/pasta/do/projeto.```
- Compile o código usando o GCC.
  
   ```gcc Restaurante/Restaurante.c Validacoes/validacoes.c main.c -o programa```
- Execute o programa já compilado.

   ```./programa```
- E então utilize e aproveite o nosso sistema.
<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=120&color=FFFFFF&section=footer"/>
