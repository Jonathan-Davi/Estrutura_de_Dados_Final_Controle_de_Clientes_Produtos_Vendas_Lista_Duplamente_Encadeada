# Sistema de Gerenciamento de Clientes, Produtos e Vendas

Este projeto foi desenvolvido por **Jonathan Davi** durante o curso da disciplina **Estruturas de Dados I** na **Universidade Federal de Uberlândia (UFU)**. O objetivo principal do projeto é a implementação de uma **Lista Duplamente Encadeada** para gerenciar dados de clientes, produtos e vendas.

## Linguagem de Programação
O código foi desenvolvido em **C**, utilizando técnicas de manipulação de estruturas de dados como listas duplamente encadeadas.

## Estrutura do Sistema

O sistema está dividido em três grandes funcionalidades principais:
1. **Clientes**
2. **Produtos**
3. **Vendas**

### Funcionalidades Implementadas

#### 1. Clientes
- `insere_cliente(noptr **inicioC, noptr *novoC, Cliente c)`: Adiciona um novo cliente à lista de clientes.
- `alterar_cliente(noptr *inicioC, long int alteraC)`: Permite alterar os dados de um cliente existente.
- `consultar_cliente(noptr *inicioC, long int consultaC)`: Consulta e exibe as informações de um cliente específico.
- `remover_cliente(noptr **inicioC, noptr *inicioV, long int removeC)`: Remove um cliente da lista, verificando possíveis vendas associadas.

#### 2. Produtos
- `insere_produto(noptr **inicioP, noptr *novoP, Produto p)`: Adiciona um novo produto à lista de produtos.
- `alterar_produto(noptr *inicioP, int alteraP)`: Modifica os dados de um produto já cadastrado.
- `consultar_produto(noptr *inicioP, int consultaP)`: Consulta os dados de um produto específico.
- `remover_produto(noptr **inicioP, noptr *inicioV, int removeP)`: Remove um produto da lista, verificando se há vendas associadas.

#### 3. Vendas
- `insere_venda(noptr **inicioV, noptr **inicioP, noptr *inicioC, noptr *novoV, Venda v)`: Registra uma nova venda associada a um cliente e um produto.
- `alterar_venda(noptr *inicioV, int alteraV)`: Altera os dados de uma venda já registrada.
- `consultar_venda(noptr *inicioV, noptr *inicioP, noptr *inicioC, int consultaV)`: Consulta os detalhes de uma venda específica.
- `remover_venda(noptr **inicioV, noptr **inicioP, noptr *inicioC, int removeV)`: Remove uma venda específica.

#### 4. Outras Funcionalidades
- `lista_cliente(noptr *inicioC)`: Exibe todos os clientes cadastrados.
- `lista_produto(noptr *inicioP)`: Lista todos os produtos cadastrados.
- `lista_venda(noptr *inicioV, noptr *inicioC, noptr *inicioP)`: Exibe todas as vendas realizadas.
- `numero_clienteE(noptr *inicioV, int valorE)`: Retorna o número de clientes que compraram mais de uma certa quantidade de produtos.
- `estoque_abaixo(noptr *inicioP, int abaixo)`: Lista os produtos cujo estoque está abaixo de um determinado valor.

