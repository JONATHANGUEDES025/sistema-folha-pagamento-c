# Sistema de Folha de Pagamento em C

Aplicação de console que calcula o salário semanal de funcionários, separando horas normais e horas extras. O programa considera uma jornada regular de **40 horas por semana** e paga as horas excedentes com **adicional de 50%**.

## Funcionalidades

- Cadastro do nome do funcionário
- Leitura das horas trabalhadas e do valor por hora
- Validação de valores numéricos e não negativos
- Cálculo das horas normais e extras
- Detalhamento do salário semanal
- Opção para calcular vários funcionários na mesma execução

## Tecnologias

- Linguagem C
- Biblioteca padrão do C
- Compatível com compiladores que suportam C11

## Como executar

Crie a pasta de saída e compile o programa.

### Windows com MinGW

```powershell
New-Item -ItemType Directory -Force build
gcc -std=c11 -Wall -Wextra -Wpedantic src/main.c -o build/folha-pagamento.exe
.\build\folha-pagamento.exe
```

### Linux ou macOS

```bash
mkdir -p build
gcc -std=c11 -Wall -Wextra -Wpedantic src/main.c -o build/folha-pagamento
./build/folha-pagamento
```

## Regra de cálculo

- Até 40 horas: `horas trabalhadas × valor da hora`
- Acima de 40 horas: as horas excedentes recebem o valor da hora acrescido de 50%

Exemplo: para 45 horas trabalhadas a R$ 20,00 por hora, o resultado é R$ 800,00 pelas horas normais mais R$ 150,00 pelas horas extras, totalizando **R$ 950,00**.

## Estrutura do projeto

```text
sistema-folha-pagamento-c/
├── src/
│   └── main.c
├── .gitignore
└── README.md
```

Projeto desenvolvido para praticar funções, ponteiros, laços de repetição, validação de entrada e cálculos em C.
