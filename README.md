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
* Potênciometro
* Display LCD (16x2)
* Cabos
### veja
| Pino do Display LCD (16x2) | Conectar no Pino do Arduino UNO R3 | O que significa? |
|----------|----------|----------|
| VSS  | GND (ao Potênciometro)   | A   |
| VDD  | 5V   | Dado 4   |
| V0  | ao Potênciometro   | Dado 6   |
| RS  | 12 pino  | Dado 8   |
| RW  | GND   | Dado 10  |
| E  | 11 pino  | Dado 12  |
| D4-D7  | 5 a 2 Pino  | Dado 14  |
| A      |  resistor | dado |
| K    | GND   | dado |


