# Trabalho 1 - Sistemas Operacionais

Este repositório contém o Trabalho 1 da disciplina de Sistemas Operacionais, referente à questão 2.

## Descrição

O trabalho consiste em um programa escrito em linguagem C que lida com dados relacionados a medicamentos. O código fonte está organizado de acordo com a estrutura de um Makefile, permitindo a compilação fácil através do comando `make`.

## Compilação

Para compilar o programa, utilize o seguinte comando:

```bash
make
```
Isso gerará o executável do programa.

## Utilização

O programa espera arquivos de texto no formato específico para teste. Os arquivos de entrada (`terminal1.txt`, `terminal2.txt`, `terminal3.txt`, `terminal4.txt`) devem seguir o padrão:

{nome_do_paciente} {id_do_medicamento} {quantidade}

- nome_do_paciente: Nome do paciente que recebe o medicamento.
- id_do_medicamento: Identificação única do medicamento.
- quantidade: Quantidade do medicamento a ser administrada.

Os arquivos já contém exemplos de entrada.

## Execução

Após a compilação, execute o programa com:

```bash
./trabalho1
```

## Contribuição

Sinta-se à vontade para contribuir com melhorias, correções de bugs ou novos recursos. Abra uma *issue* ou envie um *pull request* e ficaremos felizes em revisar.

## Licença

Este trabalho é distribuído sob a licença [MIT](LICENSE).
