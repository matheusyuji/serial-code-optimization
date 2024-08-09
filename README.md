# Otimização de Código Serial

## Como executar

Para compilar o programa:

```bash
make
```

Para executar o script e gerar os dados:

```bash
bash ./gendata.sh 
```

Para plotar os gráficos:

```bash
./plot.gp Resultados/ 
``` 

## Funcionamento
* Os dados gerados foram com valores de N iguais a 64, 100, 128, 200, 256, 512, 600, 900, 1024 e 2000.

* O fator de bloqueio, BK, divide a matriz em blocos menores de 8x8 para melhorar a localização dos dados em cache. Em vez de operar em toda a matriz de uma só vez, a multiplicação de matrizes é feita por blocos, o que aumenta a eficiência de cache. 

* O fator de desenrolamento, UR, desenrola o loop interno de multiplicação, executando 4 operações de multiplicação-acumulação consecutivas em uma única iteração do loop. 

* Quando o tamanho da matriz ou vetor não é um múltiplo de 8 (para BK) ou 4 (para UR), o código deve incluir lógica para processar os elementos "restantes" que não se encaixam perfeitamente nos blocos ou na quantidade de elementos desenrolados.

* Ambas as otimizações focam em maximizar a eficiência do cache e reduzir o tempo de acesso à memória, que são os principais gargalos em operações de multiplicação de matrizes e vetores.

## Especificações do programa
O script para gerar os dados deve ser executado na zara e o programa também deve ser compilado na zara.