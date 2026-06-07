# C++ Module 09

Implementação em C++98 dos três exercícios de containers da STL.

## Containers por exercício

- `ex00`: `std::map<std::string, double>` armazena datas e taxas de bitcoin.
- `ex01`: `std::stack<int, std::list<int> >` avalia expressões RPN.
- `ex02`: `std::vector<int>` e `std::deque<int>` executam versões separadas do merge-insert sort.

Nenhum desses containers é reutilizado fora do exercício indicado.

## ex00 — Bitcoin Exchange

`BitcoinExchange` valida o cabeçalho e as linhas do banco CSV, datas reais (incluindo anos bissextos), números e o arquivo de entrada. A busca usa `lower_bound`: uma data exata usa sua própria taxa; caso contrário, o iterador volta uma posição e usa somente a data anterior mais próxima.

O `data.csv` incluído é uma base compacta para testes locais. Antes da avaliação, ele deve ser substituído pelo `data.csv` completo fornecido junto ao subject da 42, sem alterar o código.

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

Cada token precisa ser um dígito único ou um dos quatro operadores. Um operador remove primeiro o operando da direita e depois o da esquerda. A expressão só é válida quando resta exatamente um resultado. Divisão por zero e overflow intermediário são erros.

Teste manual:

```sh
cd ex01 && make
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "4 0 /"
./RPN "1 2"
```

## ex02 — PmergeMe

A implementação aceita duplicatas: elas são valores positivos válidos e são preservadas. Cada versão forma pares, separa menores e maiores, ordena recursivamente a cadeia dos maiores e insere os pendentes por busca binária. A ordem dos pendentes usa limites derivados da sequência de Jacobsthal. As implementações de `vector` e `deque` são mantidas separadas para tornar suas diferenças defensáveis na avaliação.

O tempo de cada container inclui a cópia dos dados originais e a ordenação. Ao final, o programa também verifica internamente que ambos produziram a mesma sequência.

Testes manuais:

```sh
cd ex02 && make
./PmergeMe 3 5 9 7 4
./PmergeMe 3 1 3 2 2
./PmergeMe 1
seq 3000 -1 1 | xargs ./PmergeMe
```
