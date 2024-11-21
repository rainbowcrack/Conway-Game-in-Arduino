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

<p>
  Surge daí a iniciativa de adaptar esse sistema para o trabalho final de Arduino da disciplina "Laboratório de Iniciação à Computação", em Ciência da Computação. 
</p>

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


