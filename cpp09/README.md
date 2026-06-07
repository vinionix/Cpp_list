# C++ Module 09 — STL

Implementação dos três exercícios do módulo 09 de C++ da 42 Rio. O módulo aplica containers da STL a problemas de processamento de dados, avaliação de expressões e ordenação, mantendo compatibilidade com **C++98**.

## Objetivo

Praticar a escolha e o uso de containers adequados para cada problema. Cada exercício utiliza uma estrutura principal diferente e possui validações próprias para entradas inválidas.

## Exercícios e containers

| Exercício | Programa | Container principal | Propósito |
| --- | --- | --- | --- |
| [`ex00`](ex00/) | `btc` | `std::map<std::string, double>` | consultar taxas históricas e calcular valores de bitcoin |
| [`ex01`](ex01/) | `RPN` | `std::stack<int, std::list<int> >` | avaliar expressões em notação polonesa reversa |
| [`ex02`](ex02/) | `PmergeMe` | `std::vector<int>` e `std::deque<int>` | ordenar inteiros positivos com merge-insert sort |

Nenhum desses containers é reutilizado fora do exercício indicado.

## Como compilar

Cada exercício possui um `Makefile` independente:

```sh
cd ex00 # ou ex01 / ex02
make
```

Também estão disponíveis os alvos `clean`, `fclean` e `re`.

## ex00 — Bitcoin Exchange

`BitcoinExchange` lê uma base CSV de datas e taxas, valida o arquivo de entrada e calcula o valor informado com a taxa correspondente. A implementação valida o cabeçalho, as linhas do CSV, datas reais — incluindo anos bissextos — e valores numéricos.

A busca usa `lower_bound`: uma data exata utiliza sua própria taxa; quando não há correspondência exata, é usada somente a taxa da data anterior mais próxima.

O `data.csv` incluído é uma base compacta para testes locais. Antes de uma avaliação baseada no subject da 42, ele deve ser substituído pelo arquivo completo fornecido com o exercício, sem alteração do código.

Teste manual:

```sh
cd ex00 && make
cat > /tmp/input.txt <<'INPUT'
date | value
2011-01-03 | 3
2011-01-04 | 2
2012-01-11 | -1
2001-42-42
2012-01-11 | 2147483648
INPUT
./btc /tmp/input.txt
```

## ex01 — Reverse Polish Notation

O programa avalia uma expressão em notação polonesa reversa. Cada token deve ser um único dígito ou um dos quatro operadores aritméticos. Um operador remove primeiro o operando da direita e depois o da esquerda; a expressão só é válida quando resta exatamente um resultado.

A implementação também trata divisão por zero e overflow em resultados intermediários.

Testes manuais:

```sh
cd ex01 && make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "4 0 /"
./RPN "1 2"
```

## ex02 — PmergeMe

O programa ordena uma sequência de inteiros positivos com versões separadas do merge-insert sort para `std::vector` e `std::deque`. A implementação aceita e preserva valores duplicados.

Cada versão forma pares, separa os valores menores e maiores, ordena recursivamente a cadeia dos maiores e insere os elementos pendentes por busca binária. A ordem de inserção utiliza limites derivados da sequência de Jacobsthal. Manter as duas implementações separadas deixa explícitas as diferenças entre os containers.

O tempo medido para cada container inclui a cópia dos dados originais e a ordenação. Ao final, o programa verifica internamente se ambos produziram a mesma sequência.

Testes manuais:

```sh
cd ex02 && make
./PmergeMe 3 5 9 7 4
./PmergeMe 3 1 3 2 2
./PmergeMe 1
seq 3000 -1 1 | xargs ./PmergeMe
```

## Status atual

Os três exercícios possuem implementação, `Makefile` e cenários de teste manual. Não há suíte automatizada de testes neste módulo. A base CSV incluída no `ex00` é reduzida e destinada a validações locais.

## Evolução do módulo

- implementação dos três exercícios e separação por container;
- inclusão das validações de entrada e tratamento de erros;
- documentação da arquitetura e dos testes manuais;
- **estado atual:** módulo implementado e disponível para validação manual; manutenção voltada a testes e documentação.

## Aprendizados principais

- selecionar containers da STL conforme os padrões de acesso necessários;
- validar e processar arquivos e argumentos de linha de comando;
- usar busca ordenada com `std::map::lower_bound`;
- aplicar uma pilha à avaliação de expressões RPN;
- comparar implementações de ordenação com `std::vector` e `std::deque`.

## Autor

Desenvolvido por [vinionix](https://github.com/vinionix) como parte dos módulos de C++ da 42 Rio.
