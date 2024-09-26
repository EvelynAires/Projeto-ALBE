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


## *Linguagem utilizada*

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

## *Nesse arquivo você verá:*
- [Introdução](#Introdução)
- [Descrição](#Descrição)
- [Organização do Menu](#Organização-do-Menu)
- [Funções Implementadas](#Funções-Implementadas)

## *Introdução* 
O ALBE Restaurante se trata de um sistema pensado e desenvolvido para o gerenciamento interno de um restaurante. Será utilizado para facilitar e deixar mais eficiente, garantindo assim o bom funcionamento do estabelecimento.

## *Descrição* 
  O sistema do ALBE Restaurante irá contar com um menu de 7 opções, incluindo a opção de sair, foi criado para conter as funcionalidades de cadastrar funcionários, gerenciar os pedidos, ter a organização de estoque, obter o controle das reservas, 
ter a visualização do Menu de pratos do restaurante e também registrar o ponto dos funcionários. 

 No que se refere aos conteúdos aprendidos em sala, utilizaremos Tabela Hash, HEAP, AVL e Árvore Binária.
 


## *Organização do Menu* 
```
---------------------------------
      Bem-Vindo(a)!
1 - Cadastro de funcionarios
2 - Pedidos
3 - Estoque
4 - Reservas
5 - Menu de Pratos
6 - Registrar Ponto
7 - Sair
---------------------------------
```

## *Funções Implementadas*
### 1 - Cadastro de Funcionários 

### 2- Pedidos

### 3 - Estoque 

### 4 - Reservas

### 5 - Menu de Pratos
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

#### 1 - Criar um novo prato
``Prato *inserirPrato(Prato *raiz, int codigo, char nome[])``:
  Essa função insere um novo nó em uma árvore binária de busca, recebendo a raiz da árvore, o código e o nome do novo prato a ser inserido. No caso da raiz ser nula, cria um novo nó usando a função criar ABin. Caso não seja, compara o código do novo prato inserido com o código que está na raiz, se for menor, insere na sunárvore à esquerda e se for maior, na subárvore à direita, retornando a raiz já atualizada com a nova inserção.

#### 2 - Exibir todos os pratos
``void exibirPratos(Prato *raiz)``:
Ela tem como objetivo exibir os pratos, então irá percorrer e exibir todos os pratos que estarão armazenados. Recebe como parâmetro a raiz da árvore e caso não seja nula, irá fazer uma chamada recursiva para percorrer a subárvore esquerda e logo após a direita, exibindo os pratos em ordem crescente de seus códigos.

#### 3 - Buscar um prato
``Prato *buscarPrato(Prato *raiz, int codigo)``:
Essa função serve para procurar um prato específico na árvore binária de busca de acordo com o código do prato. Recebe a raiz e o código para ser achado, caso a raiz for nula ou o código do prato a ser encontrado coincida com o código buscado, a função irá retornar ou o nó atual ou NULL caso o prato não exista. E caso o código for menor do que o nó atual, irá realizar uma busca recursiva na subárvore que está à esquerda e se for maior, irá realizar à direita.

#### 4 - Deletar um prato
``Prato *deletarPrato(Prato *raiz, int codigo)``:
Ela busca o nó que contém o código que está sendo procurado, percorrendo a subárvore esquerda caso seja menor que a raiz e caso seja maior a subárvore direita e quando o nó é encontrado temos três possíveis acontecimentos: Se esse nó não tiver filhos ele é apenas removido; se ele tiver um filho, um ponteiro para esse filho substituirá o nó removido e se ele tiver dois filhos a função irá encontrar o menor valor da subárvore direita chamado sucessor, substituir os dados do nó por esse valor e depois remover o sucessor da subárvore direita. Depois da remoção, essa função retorna a raiz utilizada da árvore.

#### 5 - Alterar os dados de um prato
``void alterarPrato(Prato *raiz, int codigo)``:
Nessa função é realizada a busca pelo código, caso o código não seja encontrado, é impressa a mensagem que o prato do código informado não foi encontrado e caso seja encontrado, o nome atual do prato é mostrado e o programa irá solicitar para que o usuário digite o novo nome, exibindo logo após a confirmação a mensagem comunicando que o nome foi alterado.

#### 6 - Voltar ao menu principal 
`` case 6:
            printf("Voltando ao menu principal...\n");``:
Essa função irá sair do menu de pratos, dando assim o break e retornando ao menu principal.
            


### 6 - Registrar Ponto

### 7 - Sair


<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=120&color=FFFFFF&section=footer"/>
