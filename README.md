# C++ Modules — 42 Rio

Repositório de estudos e implementações dos módulos de C++ da formação da [42 Rio](https://42.rio/). Os exercícios percorrem os fundamentos da linguagem, orientação a objetos, templates, containers da STL e algoritmos, sempre com compilação em **C++98**.

O repositório reúne os módulos `cpp00` a `cpp09`. Cada exercício é independente, possui seu próprio `Makefile` e inclui um programa de demonstração ou teste manual em `main.cpp` — com exceção do primeiro exercício, implementado diretamente em `Megaphone.cpp`.

## Objetivo

Praticar C++ de forma progressiva, partindo da sintaxe básica e chegando ao uso de templates, containers e algoritmos da biblioteca padrão. As implementações também exercitam gerenciamento de memória, cópia de objetos, polimorfismo, tratamento de exceções e organização de classes.

## Tecnologias e conceitos

- C++98
- Make
- orientação a objetos e forma canônica ortodoxa
- alocação dinâmica e gerenciamento de recursos
- herança, classes abstratas e polimorfismo
- exceções, conversões e serialização
- templates de funções e classes
- STL: iteradores, algoritmos e containers

## Organização dos módulos

| Módulo | Exercícios | Foco principal |
| --- | ---: | --- |
| [`cpp00`](cpp00/) | 2 | sintaxe inicial, streams, classes e encapsulamento |
| [`cpp01`](cpp01/) | 6 | memória, ponteiros, referências, composição e ponteiros para métodos |
| [`cpp02`](cpp02/) | 3 | forma canônica ortodoxa, sobrecarga de operadores e números de ponto fixo |
| [`cpp03`](cpp03/) | 3 | herança e especialização de classes |
| [`cpp04`](cpp04/) | 3 | polimorfismo, cópia profunda, classes abstratas e interfaces |
| [`cpp05`](cpp05/) | 4 | exceções, classes abstratas e criação de objetos por fábrica |
| [`cpp06`](cpp06/) | 3 | conversões de tipos, serialização e identificação dinâmica de tipos |
| [`cpp07`](cpp07/) | 3 | templates de funções e classes |
| [`cpp08`](cpp08/) | 3 | containers, iteradores e algoritmos da STL |
| [`cpp09`](cpp09/) | 3 | processamento de dados, RPN e merge-insert sort com containers da STL |

O [`cpp09/README.md`](cpp09/README.md) detalha a arquitetura, as regras de validação e os testes manuais do módulo final.

## Como compilar e executar

### Pré-requisitos

- compilador C++ com suporte a C++98 (`c++` ou `g++`)
- `make`
- ambiente compatível com comandos POSIX para os exemplos de terminal

Não existe um alvo de compilação único na raiz. Entre no diretório do exercício desejado e execute o `Makefile` local:

```sh
cd cpp00/ex00
make
./megaphone "hello world"
```

Os alvos disponíveis nos exercícios são:

```sh
make       # compila o programa
make clean # remove os arquivos objeto
make fclean
make re    # recompila do zero
```

O nome do executável varia por exercício e está definido na variável `NAME` ou `NAME_PROG` de cada `Makefile`. Os arquivos `main.cpp` mostram os cenários usados para exercitar as implementações. O módulo 09 também documenta comandos de teste específicos.

## Status atual

Os dez módulos, do `cpp00` ao `cpp09`, estão presentes no repositório, totalizando **33 exercícios com `Makefile` próprio**. Em uma compilação local do conjunto, 32 exercícios foram compilados; o `cpp06/ex02` atualmente falha porque captura `std::exception` por valor, comportamento tratado como erro pelas flags do projeto. O histórico registra a progressão até o módulo 09, mas o repositório não informa resultados de avaliações da 42 e não possui uma suíte automatizada de testes na raiz.

## Evolução do projeto

A linha do tempo abaixo usa apenas marcos identificáveis no histórico do repositório:

- **Outubro de 2025:** conclusão registrada do `cpp00`.
- **Novembro de 2025 a janeiro de 2026:** inclusão do `cpp01` e avanço pelos módulos `cpp02` e `cpp03`.
- **Fevereiro a maio de 2026:** implementação dos módulos `cpp04` a `cpp08`.
- **Junho de 2026:** inclusão e documentação do `cpp09`.
- **Estado atual:** coleção organizada do `cpp00` ao `cpp09`; manutenção concentrada em documentação e validação manual dos exercícios.

## Aprendizados principais

- estruturar classes com responsabilidades bem definidas e estado encapsulado;
- compreender cópia, atribuição, destruição e propriedade de recursos;
- aplicar herança e polimorfismo sem perder controle sobre o ciclo de vida dos objetos;
- usar exceções e conversões de tipos de forma explícita;
- escrever abstrações genéricas com templates;
- escolher e aplicar containers e algoritmos da STL conforme o problema.

## Autor

Desenvolvido por [vinionix](https://github.com/vinionix) durante a formação na 42 Rio.
