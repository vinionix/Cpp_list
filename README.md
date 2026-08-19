# C++ Modules — 42 Rio

Repositório de estudos e implementações dos módulos de C++ da formação da 42 Rio, cobrindo do `cpp00` ao `cpp09`.

A coleção mostra uma progressão completa pelos fundamentos de C++98: sintaxe e classes, gerenciamento de memória, forma canônica ortodoxa, herança, polimorfismo, exceções, casts, templates, STL e algoritmos.

## Objetivo

Usar exercícios pequenos e independentes para construir uma base sólida em C++ e entender não apenas a sintaxe, mas as decisões de projeto por trás de objetos, ownership de recursos, abstrações e estruturas de dados.

## Progressão técnica

```text
cpp00  classes, streams, encapsulamento
  ↓
cpp01  memória, ponteiros, referências
  ↓
cpp02  forma canônica, operadores
  ↓
cpp03  herança
  ↓
cpp04  polimorfismo e abstrações
  ↓
cpp05  exceções e fábricas
  ↓
cpp06  casts e serialização
  ↓
cpp07  templates
  ↓
cpp08  containers, iteradores, algoritmos
  ↓
cpp09  processamento de dados e algoritmos
```

## Tecnologias e conceitos

- C++98
- Make
- orientação a objetos
- forma canônica ortodoxa
- alocação dinâmica e gerenciamento de recursos
- deep copy e ownership
- herança e polimorfismo
- classes abstratas e interfaces
- exceções
- casts e serialização
- templates de funções e classes
- STL
- iteradores
- containers
- algoritmos

## Organização dos módulos

| Módulo | Exercícios | Foco principal |
| --- | ---: | --- |
| [`cpp00`](cpp00/) | 2 | sintaxe inicial, streams, classes e encapsulamento |
| [`cpp01`](cpp01/) | 6 | memória, ponteiros, referências, composição e ponteiros para métodos |
| [`cpp02`](cpp02/) | 3 | forma canônica ortodoxa, operadores e ponto fixo |
| [`cpp03`](cpp03/) | 3 | herança e especialização |
| [`cpp04`](cpp04/) | 3 | polimorfismo, cópia profunda, classes abstratas e interfaces |
| [`cpp05`](cpp05/) | 4 | exceções, abstrações e fábrica de objetos |
| [`cpp06`](cpp06/) | 3 | conversões de tipos, serialização e identificação dinâmica |
| [`cpp07`](cpp07/) | 3 | templates |
| [`cpp08`](cpp08/) | 3 | containers, iteradores e algoritmos da STL |
| [`cpp09`](cpp09/) | 3 | processamento de dados, RPN e merge-insert sort |

O [`cpp09/README.md`](cpp09/README.md) contém documentação adicional do módulo final.

## Como compilar

Não existe build único na raiz. Cada exercício possui seu próprio `Makefile`.

Exemplo:

```bash
cd cpp00/ex00
make
./megaphone "hello world"
```

Alvos comuns:

```bash
make
make clean
make fclean
make re
```

O nome do executável varia conforme o exercício e pode ser conferido no `Makefile` local.

## Como revisar este repositório

Para entender a evolução sem abrir todos os 33 exercícios, uma boa sequência é:

1. observar encapsulamento e classes no `cpp00`;
2. comparar ponteiros/referências e ownership no `cpp01`;
3. analisar copy constructor/assignment no `cpp02`;
4. acompanhar herança e polimorfismo nos módulos 03/04;
5. verificar tratamento de exceções no 05;
6. revisar casts no 06;
7. observar a mudança para abstrações genéricas no 07;
8. comparar escolhas de containers no 08/09.

## Status

Os dez módulos, do `cpp00` ao `cpp09`, estão presentes no repositório, totalizando **33 exercícios com `Makefile` próprio**.

Em uma validação local registrada anteriormente, 32 exercícios compilaram e `cpp06/ex02` apresentou falha relacionada à captura de `std::exception` por valor sob as flags do projeto. Essa observação é mantida para não confundir “arquivo presente” com “build validado”.

O repositório não afirma resultados de avaliações da 42 nem uma suíte automatizada global.

## Evolução registrada

- **Outubro de 2025:** `cpp00`.
- **Novembro de 2025 a janeiro de 2026:** `cpp01`, `cpp02` e `cpp03`.
- **Fevereiro a maio de 2026:** `cpp04` a `cpp08`.
- **Junho de 2026:** `cpp09`.
- **Estado atual:** coleção completa do `cpp00` ao `cpp09`, com foco em organização, revisão e documentação.

## O que este projeto demonstra

- evolução consistente em C++;
- modelagem orientada a objetos;
- entendimento de ownership e ciclo de vida;
- herança e polimorfismo;
- tratamento de erros com exceções;
- templates e programação genérica;
- seleção de containers e algoritmos;
- capacidade de trabalhar sob restrições de padrão C++98.

## Documentação

- [Technical Overview](docs/TECHNICAL_OVERVIEW.md) — visão da progressão, temas de design, estratégia de validação e valor técnico da coleção.

## Autor

Desenvolvido por [Vinícius Fidelis](https://github.com/vinionix) durante a formação na 42 Rio.
