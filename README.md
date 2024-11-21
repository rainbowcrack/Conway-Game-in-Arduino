# Conway-Game-in-Arduino
## Jogo da Vida
<p>O Jogo da Vida de Conway é uma variante simples do Autômato Celular de Von Neumann, do qual simula uma população de vizinhos a partir de sua população inicial e interações, sejam morte ou nascimento com uma regra matemática.

* Uma célula morta com exatamente três vizinhos vivos se torna uma célula viva;
* Uma célula viva com menos de dois vizinhos vivos morre de solidão; 
* Uma célula viva com mais de três vizinhos vivos morre de superpopulação;
* Uma célula viva com dois ou três vizinhos vivos continua no mesmo estado para a próxima geração;</p>

<div style="display: flex; justify-content: center;">
  <img src="https://github.com/user-attachments/assets/73403d68-9326-42b2-9826-7f9fb753157e" width="500" />
</div>

  Surge daí a iniciativa de adaptar esse sistema para o trabalho final de Arduino da disciplina "Laboratório de Iniciação à Computação".

  ### Projeto desenvolvido por 
  [Izabel Chaves](https://github.com/rainbowcrack/) (Aluna do 1º período de Ciência da Computação - PUC MINAS) @ 2024

## Componentes
* Placa de ensaio
* Arduino UNO R3
* Resistor 10kΩ
* Potênciometro
* Display LCD (16x2)
* Cabos
  
### Informações Detalhadas do Display LCD e do Arduino
| Pino do Display LCD (16x2) | Conectar no Pino do Arduino UNO R3 | O que significa? |
|----------|----------|----------|
| VSS  | GND (do Potênciometro) | Fio Terra |
| VDD  | 5V | Alimentação |
| V0  | Entrada Analógica (do Potênciometro) | Controle de voltagem no LCD |
| RS  | Pino 12 | Registro de Seleção |
| RW  | GND | Leitura e Escrita |
| E  | Pino 11 | Habilita Transferência de Dados  |
| D4-D7 | Pino 5 ao 2 | Entrada de Dados |
| A | Resistor | Controle de itensidade do LED do LCD |
| K | GND | Fecha o circuito do LED do LCD |

<p>
  O Potênciometro é responsável por controlar a itensidade do brilho da tela, enquanto os demais pinos do Display LCD são fornecidos para a entrada de dados com exeção do "A" e "K" restritos a tratar os bits como leds acesos ou não e o "E" para a Matriz 16x2. 
</p>

## Exemplos de código
A biblioteca LiquidCrystal simplifica a integração do display LCD com o código passado ao Arduino, por meio de funções (ver as especificações da biblioteca). Assim, os números do LCD correspondem à: RS, E, D4, D5, D6 e D7 respectivamente, enquanto o Begin inicializa a Matriz 16x2.

```cpp
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
```

No entanto, o Begin não será usado porque o espaço amostral para ocorrer as evoluções deverá ser maior que 32 bits, assim pegar os microbits de cada bit tornando uma Matriz 8x8.

```cpp
// Dimensões do tabuleiro e do LCD
#define TABULEIRO_LIN 8
#define TABULEIRO_COL 8
#define DISPLAY_LIN 2
#define DISPLAY_COL 16
```
Haverá um contador de populações definido pelo programador que será incrementado a cada interação.

```cpp
// Contador de populações
int populacaonCount = 0;

// Atualiza contador de células vivas
if (newTabuleiro[i][j] == 1) {
  vizinhosVivos++;
}

// Ao final da simulação, exibe o número total de populações
    if (populacaoCount > 20) {  // Por exemplo, parar após 20 ciclos
```
Para caso a função em C++ seja " _condição ? valor_se_verdadeiro : valor_se_falso;_ " as **Regras do Jogo da Vida** são definidas por:

```cpp
if (tabuleiro[i][j] == 1) {  // Célula viva
    newTabuleiro[i][j] = (vizinhosVivos == 2 || vizinhosVivos == 3) ? 1 : 0;
} else {  // Célula morta
    newTabuleiro[i][j] = (vizinhosVivos == 3) ? 1 : 0;
}
```

E atualizar o valor da Matriz será dado em:

```cpp
// Atualiza o tabuleiro
    for (int i = 0; i < TABULEIRO_LINS; i++) {
        for (int j = 0; j < TABULEIRO_COL; j++) {
            tabuleiro[i][j] = newTabuleiro[i][j];
        }
    }
```

## Tópicos que foram trabalhados
* Importações de Biblioteca
* Programação em Arduino e em C++
* Matrizes
* Simulação de Eventos
* Condicionais e Contadores
* Manipulação de bits
* Memória de Buffer e Tempo de Evolução de Sistemas Dinâmicos
* Funções Atômicas/Modularização
* Autômatos Celulares
* Algoritmos Genéticos
* Problema para a Máquina de Turing-Completa
  
## Explorado Futuramente
A expansão da simulação para melhor visualizar em uma Matriz de LEDS ou um Display LCD com mais Bits, pois houve um conflito que requeriu adaptação "Como fazer uma Matriz para 8x8 bits se comportar no Display com capacidade de apenas 16x2?" Olhando os microbits! Que em um cenário futuro pode ser interpretado com a manipulação direta dessa memória para além das facilidades que a biblioteca LiquidCrystal propõe fugindo da análise da tabela ASCII olhando cada caractere (problema a ver em **Arquitetura de Computadores**).

Ao invés de analisar a evolução de um Glider e a quantidade fixas de gerações, deixar o usuário informar os valores e as posições.

Em um contexto mais avançado, no quesito de Pesquisa Científica, prever a construção de uma **Máquina de Turing-Completa** a partir da premissa que a evolução de Autômatos Celulares em um sistema simples como em um Arduino simula uma posterior contrução de um computador complexo, com suas entradas lógicas.

Analisar contextos de disseminação de vírus ou evolução de populações por índices estatísticos similares ao IDH, papel da **Geografia Estatística, Avanços na Computação, Medicina e Estratégia Política.**

## Créditos
[Izabel Chaves](https://github.com/rainbowcrack/) (Aluna do 1º período de Ciência da Computação - PUC MINAS) @ 2024
