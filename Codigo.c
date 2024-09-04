#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int dia;
  int mes;
  int ano;
}Data;

typedef struct{
  char rua[50];
  int numero;
  char cidade[50];
  char estado[50];
}Endereco;

typedef struct{
  long int cpf;
  char nome[50];
  long int telefone;
  Endereco enderecocliente;
  Data datanascimentocliente;
}Cliente;

typedef struct{
  int codigo;
  char desc[30];
  int quantidadeestoque;
  float precounitario;
}Produto;

typedef struct{
  int codigodavenda;
  Cliente cpfcliente;
  Produto codigoproduto;
  int quantidadecomprada;
}Venda;

typedef struct no{
  Data listaData;
  Endereco listaEndereco;
  Cliente listaCliente;
  Produto listaProduto;
  Venda listaVenda;
  struct no *proximo;
  struct no *anterior;
}noptr;

//Cliente -< OK >-
void insere_cliente(noptr **inicioC, noptr *novoC, Cliente c); //Opção 1 - 1 | Adicionar cliente -< OK >-
void alterar_cliente(noptr *inicioC, long int alteraC); //Opção 1 - 2 | Alterar Cliente -< OK >-
void consultar_cliente(noptr *inicioC, long int consultaC); //Opção 1 - 3 | Cosultar cliente -< OK >-
void remover_cliente(noptr **inicioC, noptr *inicioV, long int removeC); //Opção 1 - 4 | Deleção cliente -< OK >-

//Produto -< OK >-
void insere_produto(noptr **inicioP, noptr *novoP, Produto p); //Opção 2 - 1 | Adicionar produto -< OK >-
void alterar_produto(noptr *inicioP, int alteraP); //Opção 2 - 2 | Alterar produto -< OK >-
void consultar_produto(noptr *inicioP, int consultaP); //Opção 2 - 3 | Consultar produto -< OK >-
void remover_produto(noptr **inicioP,noptr *inicioV,  int removeP); //Opção 2 - 4 | Deleção de produto -< OK >-

//Venda -< OK >-
void insere_venda(noptr **inicioV, noptr **inicioP, noptr *inicioC, noptr *novoV, Venda v); //Opção 3 - 1 | Adicionar venda -< OK >-
void alterar_venda(noptr *inicioV, int alteraV); //Opção 3 - 2 | Alterar venda -< OK >-
void consultar_venda(noptr *inicioV, noptr *inicioP, noptr *inicioC, int consultaV); //Opção 3 - 3 | Consultar venda -< OK >-
void remover_venda(noptr **inicioV, noptr **inicioP, noptr *inicioC, int removeV); //Opção 3 - 4 | Remover venda -< OK >-

//Diversos -< OK >-
void lista_cliente(noptr *inicioC); //Opção 4 | Todos os clientes -< OK >-
void lista_produto(noptr *inicioP); //Opção 5 | Todos os produtos -< OK >-
void lista_venda(noptr *inicioV, noptr *inicioC, noptr *inicioP); //Opção 6 | Todas as vendas -< OK >-
void numero_clienteE(noptr *inicioV, int valorE); //Opção 7 | Número de clientes que compraram acima de uma quantidade -< OK >-
void estoque_abaixo(noptr *inicioP, int abaixo); //Opção 8 | Produtos que estão com estoque abaixo de um valor -< OK >-

//------------------------------------------------------------------------
int main(void) {

  int menu1=-1, menuC, menuP, menuV, menu7;
  int altP, consultP, removP, qntabaixo, consultV, removV, compE;
  long int altC, consultC, removC, altV;
  Cliente cadastro;
  Produto prod;
  Venda vend;
  noptr *inicioC, *inicioP, *inicioV;
  noptr *infoC, *infoP, *infoV;
  inicioC = NULL;
  inicioP = NULL;
  inicioV = NULL;

  while(menu1!=9){
    printf("\n| 1 <-> Opções do cliente\t\t\t\t\t\t\t\t\t|\n| 2 <-> Opções do produto\t\t\t\t\t\t\t\t\t|\n| 3 <-> Opções de venda\t\t\t\t\t\t\t\t\t\t|\n| 4 <-> Todos o clientes cadastrados\t\t\t\t\t\t|\n| 5 <-> Todos os produtos cadastrados\t\t\t\t\t\t|\n| 6 <-> Todas as vendas efetivadas\t\t\t\t\t\t\t|\n| 7 <-> Número de clientes que compraram acima de um valor\t|\n| 8 <-> Produtos que estão com estoque abaixo de um valor\t|\n| 9 <-> Finalizar programa\t\t\t\t\t\t\t\t\t|\n\n--> ");
    scanf("%d", &menu1);

    switch(menu1){
      case 1:
        printf("\n\t-<->-|Cliente|-<->-\n| 1 <-> Adicionar cliente\t|\n| 2 <-> Alterar cliente\t\t|\n| 3 <-> Consultar cliente\t|\n| 4 <-> Remover cliente\t\t|\n| 5 <-> Voltar\t\t\t\t|\n\n--> ");
        scanf("%d", &menuC);
        switch(menuC){
          case 1:
            printf("\nCPF: ");
            scanf("%ld", &cadastro.cpf);
            printf("Nome: ");
            getchar();
            fgets(cadastro.nome, sizeof(cadastro.nome), stdin);
            printf("Telefone: ");
            scanf("%ld", &cadastro.telefone);
            printf("Rua: ");
            getchar();
            fgets(cadastro.enderecocliente.rua, sizeof(cadastro.enderecocliente.rua), stdin);
            printf("Número: ");
            scanf("%d", &cadastro.enderecocliente.numero);
            printf("Cidade: ");
            getchar();
            fgets(cadastro.enderecocliente.cidade, sizeof(cadastro.enderecocliente.cidade), stdin);
            printf("Estado: ");
            fflush(stdin);
            fgets(cadastro.enderecocliente.estado, sizeof(cadastro.enderecocliente.estado), stdin);
            do{
              printf("Dia: ");
              scanf("%d", &cadastro.datanascimentocliente.dia);
              if(cadastro.datanascimentocliente.dia < 1 || cadastro.datanascimentocliente.dia > 30)
                printf("Dia inválido. Digite um valor entre 1 e 31.\n");
            }while(cadastro.datanascimentocliente.dia < 1 || cadastro.datanascimentocliente.dia > 30);

            do{
              printf("Mês: ");
              scanf("%d", &cadastro.datanascimentocliente.mes);
              if(cadastro.datanascimentocliente.mes < 1 || cadastro.datanascimentocliente.mes > 12)
                printf("Mês inválido. Digite um valor entre 1 e 12.\n");
            }while(cadastro.datanascimentocliente.mes < 1 || cadastro.datanascimentocliente.mes > 12);

            do{
              printf("Ano: ");
              scanf("%d", &cadastro.datanascimentocliente.ano);
                if(cadastro.datanascimentocliente.ano <= 1950 || cadastro.datanascimentocliente.ano > 2023)
                  printf("Ano inválido. Digite um valor acima de 1950.\n");
            }while(cadastro.datanascimentocliente.ano <= 1950 || cadastro.datanascimentocliente.ano > 2023);
            
            insere_cliente(&inicioC, infoC, cadastro);
          break;

          case 2:
            if(inicioC==NULL){
              printf("\n\tNenhum cliente cadastrado!\n");
            }else{
              printf("\nDigite o CPF do cliente que deseja alterar: ");
              scanf("%ld", &altC);
              alterar_cliente(inicioC, altC);
            }
          break;

          case 3:  
            if(inicioC==NULL){
              printf("\n\tNenhum cliente cadastrado!\n");
            }else{
              printf("\nDigite o CPF do cliente que deseja consultar: ");
              scanf("%ld", &consultC);
              consultar_cliente(inicioC, consultC);
            }
          break;

          case 4:  
            if(inicioC==NULL){
              printf("\n\tNenhum cliente cadastrado!\n");
            }else{
              printf("\nDigite o CPF do cliente que deseja remover: ");
              scanf("%ld", &removC);
              remover_cliente(&inicioC, inicioV, removC);
            }
          break;

          case 5:
          break;

          default:
            printf("\n\tOpção inválida!\n");
          break;
        }
      break;

      case 2:
        printf("\n\t-<->-|Produto|-<->-\n| 1 <-> Adicionar produto\t|\n| 2 <-> Alterar produto\t\t|\n| 3 <-> Consultar produto\t|\n| 4 <-> Remover produto\t\t|\n| 5 <-> Voltar\t\t\t\t|\n\n--> ");
      scanf("%d", &menuP);
        switch(menuP){
          case 1:
            printf("\nCódigo: ");
            scanf("%d", &prod.codigo);
            printf("Descrição: ");
            getchar();
            fgets(prod.desc, sizeof(prod.desc), stdin);
            printf("Estoque: ");
            scanf("%d", &prod.quantidadeestoque);
            printf("Preço unitário: ");
            scanf("%f", &prod.precounitario);
            insere_produto(&inicioP, infoP, prod);
          break;

          case 2:
            if(inicioP==NULL){
              printf("\n\tNenhum produto cadastrado!\n");
            }else{
              printf("\nDigite o código do produto que deseja alterar: ");
              scanf("%d", &altP);
              alterar_produto(inicioP, altP);
            }
          break;

          case 3:
            if(inicioP==NULL){
              printf("\n\tNenhum produto cadastrado!\n");
            }else{
              printf("\nEntre com o código do produto que deseja consultar: ");
              scanf("%d", &consultP);
              consultar_produto(inicioP, consultP);
            }
          break;

          case 4:
            if(inicioP==NULL){
              printf("\n\tNenhum produto cadastrado!\n");
            }else{
              printf("\nDigite o código do produto que deseja remover: ");
              scanf("%d", &removP);
              remover_produto(&inicioP , inicioV, removP);
            }
          break;

          case 5:
          break;

          default:
            printf("\n\tOpção inválida!!\n");
          break;
        }
      break;

      case 3:
        printf("\n\t-<->-|Venda|-<->-\n| 1 <-> Adicionar venda\t\t|\n| 2 <-> Alterar venda\t\t|\n| 3 <-> Consultar venda\t\t|\n| 4 <-> Remover venda\t\t|\n| 5 <-> Voltar\t\t\t\t|\n\n--> ");
        scanf("%d", &menuV);
        switch(menuV){
          case 1:
            if(inicioC==NULL || inicioP==NULL){
              printf("\n\tRealize todos os cadastros primeiro!\n");
            }else{
              printf("\nCódigo: ");
              scanf("%d", &vend.codigodavenda);
              printf("CPF Cliente: ");
              scanf("%ld", &vend.cpfcliente.cpf);
              printf("Código do prduto: ");
              scanf("%d", &vend.codigoproduto.codigo);
              printf("Quantidade: ");
              scanf("%d", &vend.quantidadecomprada);
              insere_venda(&inicioV, &inicioP, inicioC, infoV, vend);
            }
          break;

          case 2:
            if(inicioV==NULL){
              printf("\n\tNenhuma venda cadastrada!\n");
            }else{
              printf("\nDigite o código da venda que deseja alterar: ");
              scanf("%ld", &altV);
              alterar_venda(inicioV, altV);
            }
          break;

          case 3:
            if(inicioC==NULL || inicioP==NULL || inicioV==NULL){
              printf("\n\tRealize todos os cadastros primeiro!!\n");
            }else{
              printf("\nEntre com a venda que deseja consultar: ");
              scanf("%d", &consultV);
              consultar_venda(inicioV, inicioP, inicioC, consultV);
            }
          break;

          case 4:
            if(inicioC==NULL || inicioP==NULL || inicioV==NULL){
              printf("\n\tRealize todos os cadastros primeiro!!\n");
            }else{
              printf("\nEntre com a venda que deseja remover: ");
              scanf("%d", &removV);
              remover_venda(&inicioV, &inicioP, inicioC, removV);
            }
          break;

          case 5:
          break;

          default:
            printf("\n\tOpção inválida!!\n");
          break;
        }
      break;

      case 4:
        if(inicioC==NULL){
          printf("\n\tNenhum cliente registrado!\n");
        }else{
          lista_cliente(inicioC);
        }
      break;

      case 5:
        if(inicioP==NULL){
          printf("\n\tNenhum produto registrado!\n");
        }else{
          lista_produto(inicioP);
        }
      break;

      case 6:
        if(inicioV==NULL){
          printf("\n\tNenhuma venda registrada!\n");
        }else{
          lista_venda(inicioV, inicioC, inicioP);
        }
      break;

      case 7:
        if(inicioV==NULL || inicioC==NULL || inicioP==NULL){
          printf("\n\tRealize todos os cadastros primeiro!\n");
        }else{
          printf("\nEntre com a quantidade que deseja comparar: ");
          scanf("%d", &compE);
          numero_clienteE(inicioV, compE);
          }     
      break;

      case 8:
        if(inicioP==NULL){
          printf("\n\tNenhum produto registrado!\n");
        }else{
          printf("\nEntre com a quantidade de estoque que deseja comparar: ");
          scanf("%d", &qntabaixo);
          estoque_abaixo(inicioP, qntabaixo);
        }
      break;

      case 9:
        printf("\n\tFinalizando programa!\n\t.\n\t.\n\t.\n\n");
      break;

      default:
        printf("\n\tOpção inválida!!\n");
      break;
    }
  }
  return 0;
}

//-------------------------------------------------------------------
void insere_cliente(noptr **inicioC, noptr *novoC, Cliente c){
  
  noptr *aux;
  aux = *inicioC;
  
  while(aux != NULL){
    if (aux->listaCliente.cpf == c.cpf) {
      printf("\n\n\t-<->- !!ERRO!! -<->-\n\tCliente já cadastrado!\n\n");
      free(novoC);
      return;
    }
    aux = aux->proximo;
  }

  novoC = (noptr *)malloc(sizeof(noptr));
  if (!novoC) {
    printf("\nSem memória!");
    return;
  }
  
  strcpy(novoC->listaCliente.nome, c.nome);
  novoC->listaCliente.cpf = c.cpf;
  novoC->listaCliente.telefone = c.telefone;
  strcpy(novoC->listaCliente.enderecocliente.rua, c.enderecocliente.rua);
  novoC->listaCliente.enderecocliente.numero = c.enderecocliente.numero;
  strcpy(novoC->listaCliente.enderecocliente.cidade, c.enderecocliente.cidade);
  strcpy(novoC->listaCliente.enderecocliente.estado, c.enderecocliente.estado);
  novoC->listaCliente.datanascimentocliente.dia = c.datanascimentocliente.dia;
  novoC->listaCliente.datanascimentocliente.mes = c.datanascimentocliente.mes;
  novoC->listaCliente.datanascimentocliente.ano = c.datanascimentocliente.ano;
  novoC->anterior = NULL;

  if(*inicioC == NULL){
    novoC->proximo = NULL;
    *inicioC = novoC;
  } 
    else if(novoC->listaCliente.cpf < (*inicioC)->listaCliente.cpf){
      novoC->proximo = *inicioC;
      (*inicioC)->anterior = novoC;
      *inicioC = novoC;
    } 
      else{
        aux = *inicioC;
        while (aux->proximo && novoC->listaCliente.cpf > aux->proximo->listaCliente.cpf)
          aux = aux->proximo;
        novoC->proximo = aux->proximo;
        if (aux->proximo)
          aux->proximo->anterior = novoC;
        aux->proximo = novoC;
        novoC->anterior = aux;
      }
}

//-------------------------------------------------------------------
void alterar_cliente(noptr *inicioC, long int alteraC){

  int flag = 0;
  noptr *p;
  p = inicioC;

  while(p!=NULL && flag == 0){
    if(p->listaCliente.cpf == alteraC){
      flag = 1;
      printf("\n\t|Novos Dados|\n");
      printf("\nNome: ");
      getchar();
      fgets(p->listaCliente.nome, sizeof(p->listaCliente.nome), stdin);
      printf("Telefone: ");
      scanf("%ld", &p->listaCliente.telefone);
      printf("Rua: ");
      getchar();
      fgets(p->listaCliente.enderecocliente.rua, sizeof(p->listaCliente.enderecocliente.rua), stdin);
      printf("Número: ");
      scanf("%d", &p->listaCliente.enderecocliente.numero);
      printf("Cidade: ");
      getchar();
      fgets(p->listaCliente.enderecocliente.cidade, sizeof(p->listaCliente.enderecocliente.cidade), stdin);
      printf("Estado: ");
      fflush(stdin);
      fgets(p->listaCliente.enderecocliente.estado, sizeof(p->listaCliente.enderecocliente.estado), stdin);

      do{
        printf("Dia: ");
        scanf("%d", &p->listaCliente.datanascimentocliente.dia);
        if(p->listaCliente.datanascimentocliente.dia <= 0 || p->listaCliente.datanascimentocliente.dia >= 31)
          printf("Dia inválido. Digite um valor entre 1 e 31.\n");
        }while(p->listaCliente.datanascimentocliente.dia <= 0 || p->listaCliente.datanascimentocliente.dia >= 31);

      do{
        printf("Mês: ");
        scanf("%d", &p->listaCliente.datanascimentocliente.mes);
        if(p->listaCliente.datanascimentocliente.mes < 1 || p->listaCliente.datanascimentocliente.mes > 12)
          printf("Mês inválido. Digite um valor entre 1 e 12.\n");
        }while(p->listaCliente.datanascimentocliente.mes < 1 || p->listaCliente.datanascimentocliente.mes > 12);

      do{
        printf("Ano: ");
        scanf("%d", &p->listaCliente.datanascimentocliente.ano);
        if(p->listaCliente.datanascimentocliente.ano <= 1950 || &p->listaCliente.datanascimentocliente.ano > 2023)
          printf("Ano inválido. Digite um valor acima de 1950.\n");
        }while(p->listaCliente.datanascimentocliente.ano <= 1950 || p->listaCliente.datanascimentocliente.ano > 2023);
      

      return;
    }
    p=p->proximo;
  }
  
  printf("\n\tCliente com o CPF: %ld. Não foi encontrado!!\n", alteraC);
}

//-----------------------------------------------------------------------
void consultar_cliente(noptr *inicioC, long int consultaC){
  
  int flag = 0;
  noptr *p;
  p = inicioC;

  while(p!=NULL && flag==0){
    if(p->listaCliente.cpf == consultaC){
      flag = 1;
      printf("\n|Cliente|\nNome: %sCPF: %ld\nTelefone: %ld\nRua: %sNúmero: %d\nCidade: %sEstado: %sNascimento: %d/%d/%d\n", p->listaCliente.nome, p->listaCliente.cpf, p->listaCliente.telefone, p->listaCliente.enderecocliente.rua, p->listaCliente.enderecocliente.numero, p->listaCliente.enderecocliente.cidade, p->listaCliente.enderecocliente.estado, p->listaCliente.datanascimentocliente.dia, p->listaCliente.datanascimentocliente.mes, p->listaCliente.datanascimentocliente.ano); 
      return;
      }
    p = p->proximo; 
  }

  printf("\n\tCliente com o CPF: %ld. Não foi encontrado!!\n", consultaC);
}

//------------------------------------------------------------------------------
void remover_cliente(noptr **inicioC, noptr *inicioV, long int removeC){

  int flag = 0;
  noptr *p;
  p = *inicioC;
  noptr *auxV = inicioV;
  
  while (auxV != NULL) {
    if (auxV->listaVenda.cpfcliente.cpf == removeC) {
      printf("\nO cliente está cadastrado em uma venda e não pode ser removido.\n");
      return;
    }
    auxV = auxV->proximo;
  }

  while(p!=NULL && flag==0){
    if(p->listaCliente.cpf == removeC){
      flag = 1;
      printf("\nCPF: %ld\nCliente: %sFoi removido com sucesso!!\n", p->listaCliente.cpf, p->listaCliente.nome);
      if(p->anterior==NULL){
        *inicioC = p->proximo;
        if(*inicioC)
          (*inicioC)->anterior = NULL;
      }else{
        p->anterior->proximo = p->proximo;
        if(p->proximo)
          p->proximo->anterior = p->anterior;
      }
      free(p);
      return;
    }
    p=p->proximo;
  }

  printf("\n\tCliente com o CPF: %ld. Não foi encontrado!\n", removeC);
}

//---------------------------------------------------------------------
void insere_produto(noptr **inicioP, noptr *novoP, Produto p){

  noptr *aux;
  aux = *inicioP;

  while(aux!=NULL){
    if(aux->listaProduto.codigo == p.codigo){
      printf("\n\n\t-<->- !!ERRO!! -<->-\n\tProduto já cadastrado!\n\n");
      free(novoP);
      return;
    }
    aux = aux->proximo;
  }
  
  novoP = (noptr *)malloc(sizeof(noptr));
  if (!novoP) {
    printf("\nSem memória!");
    return;
  }
  
  novoP->listaProduto.codigo = p.codigo;
  strcpy(novoP->listaProduto.desc, p.desc);
  novoP->listaProduto.quantidadeestoque = p.quantidadeestoque;
  novoP->listaProduto.precounitario = p.precounitario;
  novoP->anterior = NULL;
  
  if(*inicioP == NULL){
    novoP->proximo = NULL;
    *inicioP = novoP;
  } 
    else if(novoP->listaProduto.codigo < (*inicioP)->listaProduto.codigo){
      novoP->proximo = *inicioP;
      (*inicioP)->anterior = novoP;
      *inicioP = novoP;
    } 
      else{
        aux = *inicioP;
        while(aux->proximo && novoP->listaProduto.codigo > aux->proximo->listaProduto.codigo)
          aux = aux->proximo;
        novoP->proximo = aux->proximo;
        if(aux->proximo)
          aux->proximo->anterior = novoP;
        aux->proximo = novoP;
        novoP->anterior = aux;
      }
}

//------------------------------------------------------------------
void alterar_produto(noptr *inicioP, int alteraP){

  int flag = 0;
  noptr *p;
  p = inicioP;

  while(p!=NULL && flag==0){
    if(p->listaProduto.codigo == alteraP){
      flag = 1;
      printf("\n\t|Novos dados do produto|\n");
      printf("Descrição: ");
      getchar();
      fgets(p->listaProduto.desc, sizeof(p->listaProduto.desc), stdin);
      printf("Estoque: ");
      scanf("%d", &p->listaProduto.quantidadeestoque);
      printf("Preço unitário: ");
      scanf("%f", &p->listaProduto.precounitario);
      return;
    }
    p = p->proximo;
  }

  printf("\n\tProduto com o código: %d. Não foi encontrado!\n", alteraP);
}

//--------------------------------------------------------------
void consultar_produto(noptr *inicioP, int consultaP){

  int flag = 0;
  noptr *p;
  p = inicioP;

  while(p!=NULL && flag==0){
    if(p->listaProduto.codigo == consultaP){
      flag = 1;
      printf("\n|Produto|\nCódigo: %d\nDescrição: %sEstoque: %d\nPreço unitário: %.2f\n", p->listaProduto.codigo, p->listaProduto.desc, p->listaProduto.quantidadeestoque, p->listaProduto.precounitario);
      return;
    }
    p = p->proximo;
  }

  printf("\n\tProduto com o código: %d. Não foi encontrado!\n", consultaP);
}

//--------------------------------------------------------------------------
void remover_produto(noptr **inicioP,noptr *inicioV,  int removeP){

  int flag=0;
  noptr *p;
  p = *inicioP;
  noptr *auxV;
  auxV = inicioV;

  while (auxV != NULL) {
    if (auxV->listaVenda.codigoproduto.codigo == removeP) {
      printf("\nO produto está cadastrado em uma venda e não pode ser removido.\n");
      return;
    }
    auxV = auxV->proximo;
  }

  while(p!=NULL && flag==0){
    if(p->listaProduto.codigo == removeP){
      flag = 1;
      printf("\nProduto: %sCódigo: %d\nFoi removido com sucesso!!\n", p->listaProduto.desc, p->listaProduto.codigo);
      if(p->anterior==NULL){
        *inicioP = p->proximo;
        if(*inicioP)
          (*inicioP)->anterior = NULL;
      }else{
        p->anterior->proximo = p->proximo;
        if(p->proximo)
          p->proximo->anterior = p->anterior;
      }
      free(p);
      return;
    }
    p = p->proximo;
  }
  printf("\n\tProduto com o código %d, não foi encontrado!\n", removeP);
}

//-----------------------------------------------------------------------------
void insere_venda(noptr **inicioV, noptr **inicioP, noptr *inicioC, noptr *novoV, Venda v){
  
    noptr *cliente = inicioC;
    noptr *aux = *inicioV;
    noptr *produto = *inicioP;

    novoV = (noptr *)malloc(sizeof(noptr));
    if (!novoV) {
        printf("\nSem memória!");
        return;
    }

    novoV->listaVenda.codigodavenda = v.codigodavenda;
    novoV->listaVenda.cpfcliente.cpf = v.cpfcliente.cpf;
    novoV->listaVenda.codigoproduto.codigo = v.codigoproduto.codigo;
    novoV->listaVenda.quantidadecomprada = v.quantidadecomprada;
    novoV->anterior = NULL;
    novoV->proximo = NULL;

    while(cliente != NULL && cliente->listaCliente.cpf != v.cpfcliente.cpf){
        cliente = cliente->proximo;
    }

    if(cliente == NULL){
        printf("\nCliente não encontrado!\n");
        free(novoV);
        return;
    }

    novoV->listaCliente = cliente->listaCliente;

    if(*inicioV == NULL){
      *inicioV = novoV;
    }else if (novoV->listaVenda.codigodavenda < (*inicioV)->listaVenda.codigodavenda){
        novoV->proximo = *inicioV;
        (*inicioV)->anterior = novoV;
        *inicioV = novoV;
    }else{
        while(aux->proximo && novoV->listaVenda.codigodavenda > aux->proximo->listaVenda.codigodavenda)
          aux = aux->proximo;
        novoV->proximo = aux->proximo;
        if(aux->proximo)
            aux->proximo->anterior = novoV;
        aux->proximo = novoV;
        novoV->anterior = aux;
    }

    while(produto != NULL && produto->listaProduto.codigo != v.codigoproduto.codigo){
      produto = produto->proximo;
    }

    if(produto == NULL){
      printf("\nProduto não encontrado!\n");
      free(novoV);
      return;
    }

    if(produto->listaProduto.quantidadeestoque >= v.quantidadecomprada){
      produto->listaProduto.quantidadeestoque -= v.quantidadecomprada;
    }else{
      printf("\nQuantidade insuficiente do produto!\n");
      free(novoV);
      return;
    }
}

//------------------------------------------------------------------------
void alterar_venda(noptr *inicioV, int alteraV){
  
  int flag = 0;
  noptr *p = inicioV;

  while (p != NULL && flag == 0) {
    if (p->listaVenda.codigodavenda == alteraV) {
      flag = 1;
      printf("\n\t|Novos dados da venda|\n");
      printf("CPF do cliente: ");
      scanf("%ld", &(p->listaVenda.cpfcliente.cpf));
      printf("Código do produto: ");
      scanf("%d", &(p->listaVenda.codigoproduto.codigo));
      printf("Quantidade comprada: ");
      scanf("%d", &(p->listaVenda.quantidadecomprada));
      return;
    }
    p = p->proximo;
  }

  printf("\n\tVenda com o código: %d não encontrada!\n", alteraV);
}

//--------------------------------------------------------------------------------
void consultar_venda(noptr *inicioV, noptr *inicioP, noptr *inicioC, int consultaV){

  int flag=0;
  noptr *p;
  p=inicioV;

  while(p!=NULL && flag==0){
    if(p->listaVenda.codigodavenda == consultaV){
      flag=1;
      printf("\nCódigo: %d\nCliente: %ld\nProduto: %d\nQuantidade: %d\n", p->listaVenda.codigodavenda, p->listaVenda.cpfcliente.cpf, p->listaVenda.codigoproduto.codigo, p->listaVenda.quantidadecomprada);
      return;
    }
    p=p->proximo;
  }
  printf("\n\tCódigo da venda não encontrado!!\n");
}

//---------------------------------------------------------------------------
void remover_venda(noptr **inicioV, noptr **inicioP, noptr *inicioC, int removeV){

  int flag=0;
  noptr *p;
  noptr *aux;
  p=*inicioV;
  aux = *inicioP;

  while(p!=NULL && flag==0){
    if(p->listaVenda.codigodavenda == removeV){
      flag=1;
      printf("\nVenda com o código: %d. Foi removida com sucesso!!\n", p->listaVenda.codigodavenda);
      if(p->anterior==NULL){
        *inicioV = p->proximo;
        if(*inicioV)
          (*inicioV)->anterior = NULL;
      }else{
        p->anterior->proximo = p->proximo;
        if(p->proximo)
          p->proximo->anterior = p->anterior;
      }
      aux->listaProduto.quantidadeestoque += p->listaVenda.quantidadecomprada;
      free(p);
      return;
    }
    p=p->proximo;
  }
  printf("\n\tVenda com o código %d, não foi encontrada!\n", removeV);
}

//------------------------------------------------------------------------------
void lista_cliente(noptr *inicioC){

  if(inicioC==NULL){
    printf("\n\tNenhum cliente cadastrado!\n");
    return;
  }

  noptr *p;
  p = inicioC;
  printf("\n|Lista dos clientes|\n");
  while(p){
    printf("\nNome: %sCPF: %ld\nTelefone: %ld\nRua: %sNúmero: %d\nCidade: %sEstado: %sNascimento: %d/%d/%d\n", p->listaCliente.nome, p->listaCliente.cpf, p->listaCliente.telefone, p->listaCliente.enderecocliente.rua, p->listaCliente.enderecocliente.numero, p->listaCliente.enderecocliente.cidade, p->listaCliente.enderecocliente.estado, p->listaCliente.datanascimentocliente.dia, p->listaCliente.datanascimentocliente.mes, p->listaCliente.datanascimentocliente.ano); 
    p = p->proximo;
  }
  printf("\n");
}

//----------------------------------------------------------------------------
void lista_produto(noptr *inicioP){

  if(inicioP==NULL){
    printf("\n\tNenhum produto cadastrado!\n");
    return;
  }

  noptr *p;
  p=inicioP;
  printf("\n|Todos os Produtos|\n");
  while(p){
    printf("\nCódigo: %d\nDescrição: %sEstoque: %d\nPreço unitário: %.2f\n", p->listaProduto.codigo, p->listaProduto.desc, p->listaProduto.quantidadeestoque, p->listaProduto.precounitario);
    p = p->proximo;
  }
  printf("\n");
}

//--------------------------------------------------------------------------
void lista_venda(noptr *inicioV, noptr *inicioC, noptr *inicioP){

  if(inicioP==NULL || inicioC==NULL){
    printf("\n\tNenhum produto ou cliente cadastrado!\n");
    return;
  }

  noptr *p;
  p = inicioV;  
  printf("\n|Todas as vendas|\n");
  while(p){
    printf("\nCódigo: %d\nCliente: %ld\nProduto: %d\nQuantidade: %d\n", p->listaVenda.codigodavenda, p->listaVenda.cpfcliente.cpf, p->listaVenda.codigoproduto.codigo, p->listaVenda.quantidadecomprada);
    p=p->proximo;  
  }
  printf("\n");
}

//--------------------------------------------------------------------
void numero_clienteE(noptr *inicioV, int valorE){
  
  int cont = 0;
  noptr *aux;
  aux = inicioV;
  
  while(aux != NULL){
    if(aux->listaVenda.quantidadecomprada > valorE){
      cont++;
    }
    aux = aux->proximo;
  }

  printf("\n%d clientes compraram acima de %d volumes.\n", cont, valorE);
}

//------------------------------------------------------------------
void estoque_abaixo(noptr *iniciofunc, int abaixo){

  if(iniciofunc==NULL){
    printf("\n\tNenhum produto cadastrado!\n");
    return;
  }

  noptr *p;
  p = iniciofunc;

  while(p!=NULL){
    if(p->listaProduto.quantidadeestoque < abaixo){
      printf("\n\n|Produto|\nCódigo: %d\nDescrição: %sEstoque: %d\nPreço unitário: %.2f\n", p->listaProduto.codigo, p->listaProduto.desc, p->listaProduto.quantidadeestoque, p->listaProduto.precounitario);
      return;
    }
    p=p->proximo;
  }
  
  printf("\n\tNenhum produto com o estoque abaixo de: %d\n", abaixo);
}