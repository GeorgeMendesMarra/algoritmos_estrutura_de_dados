# Calculadora de Simulação de Investimento com Rendimento Simples

Programa em linguagem C, com interface interativa de console (menu em modo texto), que simula a evolução de um investimento submetido a **juros simples** ao longo do tempo.

## Sobre o projeto

O usuário informa o capital inicial, a taxa de juros mensal e o período de investimento (em meses). O programa calcula os juros gerados a cada mês — sempre sobre o capital inicial, sem reinvestimento — e exibe a evolução mês a mês em forma de tabela, seguida de um resumo com o total de juros, o montante final e a rentabilidade percentual.

Fórmula utilizada:

```
J = C x i x t
M = C + J
```

Onde `C` é o capital inicial, `i` é a taxa de juros mensal (decimal), `t` é o número de meses, `J` é o total de juros acumulado e `M` é o montante final.

## Funcionalidades

- Menu interativo em modo texto (Nova simulação / Sair)
- Entrada de capital inicial, taxa de juros mensal e prazo do investimento
- Cálculo de rendimento pelo regime de juros simples
- Exibição da evolução do investimento mês a mês em tabela formatada
- Resumo final com total de juros, montante e rentabilidade total
- Validação das entradas (rejeita valores negativos, nulos ou não numéricos)
- Permite realizar múltiplas simulações na mesma execução, sem precisar reabrir o programa

## Como compilar e executar

Requer um compilador C compatível com o padrão C99 (ex.: GCC).

**Windows:**
```bash
gcc -Wall -o calculadora_investimento.exe calculadora_investimento.c
calculadora_investimento.exe
```

**Linux/macOS:**
```bash
gcc -Wall -o calculadora_investimento calculadora_investimento.c
./calculadora_investimento
```

## Exemplo de uso

Capital de R$ 1.000,00, taxa de 2% ao mês, por 6 meses:

| Mês | Juros do mês | Total de juros | Saldo total |
|-----|--------------|-----------------|-------------|
| 1   | R$ 20,00     | R$ 20,00        | R$ 1.020,00 |
| 2   | R$ 20,00     | R$ 40,00        | R$ 1.040,00 |
| 3   | R$ 20,00     | R$ 60,00        | R$ 1.060,00 |
| 4   | R$ 20,00     | R$ 80,00        | R$ 1.080,00 |
| 5   | R$ 20,00     | R$ 100,00       | R$ 1.100,00 |
| 6   | R$ 20,00     | R$ 120,00       | R$ 1.120,00 |

Montante final: **R$ 1.120,00** — rentabilidade total de **12%**.

## Arquivos do projeto

- [`calculadora_investimento.c`](calculadora_investimento.c) — código-fonte do programa
- [`documentacao_projeto.docx`](documentacao_projeto.docx) — documentação técnica completa do projeto (objetivos, fundamentação teórica, metodologia, testes e conclusão)
