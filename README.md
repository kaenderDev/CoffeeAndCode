# Sistema de Gerenciamento de Cafeteria

Este sistema foi desenvolvido em **C** para automatizar o fluxo operacional de uma cafeteria, integrando a manutenção do cardápio, o controle de pedidos em fila e o faturamento das vendas.

## Como Executar

Você pode utilizar o executável pré-compilado ou compilar manualmente via terminal.

### Opção 1: Execução Direta
1. Navegue até a pasta `output`.
2. Execute o arquivo `main.exe`.

### Opção 2: Compilação via Terminal (GCC)
Caso deseje compilar o código fonte manualmente, utilize o seguinte comando na raiz do projeto:
```bash
gcc main.c -o sistema_cafeteria
./sistema_cafeteria

## Estruturas de Dados

O projeto utiliza diferentes estruturas de dados para organizar as informações de forma eficiente, garantindo que cada operação siga uma lógica computacional apropriada.

---

### Lista Encadeada (Cardápio)

O cardápio é gerenciado por uma lista encadeada simples, onde cada nó representa um produto disponível.

* **Campos**: Armazena ID único, nome do item e preço.
* **Inserção**: Novos itens são adicionados ao início da lista para otimização, com verificação de ID duplicado.
* **Busca e Remoção**: O sistema percorre a lista para encontrar IDs específicos para realizar edições ou a exclusão do nó.



#### Complexidade

| Operação          | Complexidade |
| :---------------- | :----------- |
| Adicionar Item    | **O(1)** |
| Listar Cardápio   | **O(n)** |
| Editar/Remover    | **O(n)** |

---

### Fila (Pedidos)

A fila segue o modelo **FIFO (First-In, First-Out)**, garantindo que os clientes sejam atendidos na ordem exata em que realizaram o pedido.

* **Itens do Pedido**: Utiliza um **array dinâmico** (`int *itens_id`) dentro de cada pedido para armazenar múltiplos produtos via `realloc`.
* **Gestão**: Mantém ponteiros para o `inicio` e o `fim` da fila, permitindo inserções e remoções rápidas.



#### Complexidade

| Operação                  | Complexidade |
| :------------------------ | :----------- |
| Enfileirar (Novo Pedido)  | **O(1)** |
| Desenfileirar (Finalizar) | **O(1)** |
| Calcular Total Pedido     | **O(k * n)** |

> *Nota: No cálculo do total, **k** é a quantidade de itens no pedido e **n** o tamanho do cardápio.*

---

### Pilha (Cancelamentos)

A pilha gerencia os pedidos cancelados seguindo o modelo **LIFO (Last-In, First-Out)**.

* **Uso**: Quando um pedido é retirado da fila (cancelado), ele é empilhado no topo da estrutura.
* **Desfazer**: A operação permite desempilhar o último pedido cancelado e reinseri-lo na fila de produção.



#### Complexidade

| Operação                | Complexidade |
| :---------------------- | :----------- |
| Empilhar (Cancelar)     | **O(1)** |
| Desempilhar (Restaurar) | **O(1)** |
| Limpar Pilha            | **O(n)** |

---

### Gerenciamento de Memória e Financeiro

* **Faturamento**: Utiliza um array para armazenar as últimas 10 vendas, calculando o total arrecadado e a média por venda.
* **Memória**: O sistema faz uso de `malloc`, `realloc` e `free` para garantir que pedidos finalizados e listas de cancelamento sejam limpas, evitando vazamentos de memória.