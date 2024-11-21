#include <LiquidCrystal.h>

// Dimensões do tabuleiro e do LCD
#define BOARD_ROWS 8
#define BOARD_COLS 8
#define DISPLAY_ROWS 2
#define DISPLAY_COLS 16

// Tabuleiro maior para simulação
int board[BOARD_ROWS][BOARD_COLS];
int glider[5][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

// LCD conectado aos pinos do Arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Contador de populações
int populationCount = 0;

void setup() {
    lcd.begin(DISPLAY_COLS, DISPLAY_ROWS);

    // Exibe o nome do jogo no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jogo da Vida");
    delay(2000);

    // Inicializa o tabuleiro com células mortas
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Posiciona o Glider na matriz inicial
    for (int i = 0; i < 5; i++) {
        int x = glider[i][0];
        int y = glider[i][1];
        board[x][y] = 1;  // Define células vivas
    }

    displayBoard();
    delay(1000);
}

// Exibe uma janela do tabuleiro no LCD (16x2)
void displayBoard() {
    lcd.clear();
    for (int i = 0; i < DISPLAY_ROWS; i++) {
        lcd.setCursor(0, i);
        for (int j = 0; j < DISPLAY_COLS; j++) {
            // Calcula a célula correspondente no tabuleiro maior
            int x = i;
            int y = j;

            // Imprime " " para morto e "." para vivo
            lcd.print(board[x][y] == 1 ? "." : " ");
        }
    }
}

// Atualiza o tabuleiro com as regras do Jogo da Vida
void updateBoard() {
    int newBoard[BOARD_ROWS][BOARD_COLS];
    int aliveCount = 0;  // Contador de células vivas nesta geração

    // Aplica as regras de Conway a cada célula
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            int aliveNeighbors = countAliveNeighbors(i, j);

            // Regras do Jogo da Vida
            if (board[i][j] == 1) {  // Célula viva
                newBoard[i][j] = (aliveNeighbors == 2 || aliveNeighbors == 3) ? 1 : 0;
            } else {  // Célula morta
                newBoard[i][j] = (aliveNeighbors == 3) ? 1 : 0;
            }

            // Atualiza contador de células vivas
            if (newBoard[i][j] == 1) {
                aliveCount++;
            }
        }
    }

    // Atualiza o tabuleiro
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }

    // Incrementa o contador de populações se houver células vivas
    if (aliveCount > 0) {
        populationCount++;
    }
}

// Conta os vizinhos vivos de uma célula (tabuleiro em forma de toroide)
int countAliveNeighbors(int x, int y) {
    int aliveCount = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // Ignora a célula atual

            int nx = (x + i + BOARD_ROWS) % BOARD_ROWS;
            int ny = (y + j + BOARD_COLS) % BOARD_COLS;

            aliveCount += board[nx][ny];
        }
    }

    return aliveCount;
}

void loop() {
    updateBoard();    // Atualiza o estado do tabuleiro
    displayBoard();   // Exibe a janela no LCD
    delay(1000);      // Espera 1 segundo

    // Ao final da simulação, exibe o número total de populações
    if (populationCount > 20) {  // Por exemplo, parar após 20 ciclos
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Populacoes:");
        lcd.setCursor(0, 1);
        lcd.print(populationCount);
        while (true);  // Pausa o programa
    }
}
