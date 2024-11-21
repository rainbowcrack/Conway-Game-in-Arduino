// c++
// Incluir biblioteca que permite a manipulação do LCD por funções
#include <LiquidCrystal.h>

// Dimensões do tabuleiro e do LCD
#define TABULEIRO_LIN 8
#define TABULEIRO_COL 8
#define DISPLAY_LIN 2
#define DISPLAY_COL 16

// Tabuleiro maior para simular
int tabuleiro[TABULEIRO_LIN][TABULEIRO_COL];

// Posição do glider inicial
int glider[5][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

// LCD com os pinos do Arduino, correspondem: RS, E, D4, D5, D6 e D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Contador de populações
int populationCount = 0;

void setup() {
    lcd.begin(DISPLAY_COL, DISPLAY_LIN);

    // Nome do jogo no LCD na tela
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Jogo da Vida");
    delay(2000);

    // Inicializa o tabuleiro com células mortas
    for (int i = 0; i < TABULEIRO_LIN; i++) {
        for (int j = 0; j < TABULEIRO_COL; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Glider na matriz inicial
    for (int i = 0; i < 5; i++) {
        int x = glider[i][0];
        int y = glider[i][1];
        tabuleiro[x][y] = 1;  // Células vivas
    }

    displayTabuleiro();
    delay(1000);
}

// Tabuleiro no LCD (16x2)
void displayTabuleiro() {
    lcd.clear();
    for (int i = 0; i < DISPLAY_LIN; i++) {
        lcd.setCursor(0, i);
        for (int j = 0; j < DISPLAY_COL; j++) {
            // Calcula a célula correspondente no tabuleiro maior
            int x = i; // Cria variáveis temporárias para comparações
            int y = j;

            // " " para morto e "." para vivo
            // Condição ? valor_se_verdadeiro : valor_se_falso;
            lcd.print(tabuleiro[x][y] == 1 ? "." : " ");
        }
    }
}

// Atualiza o tabuleiro com as regras do Jogo da Vida
void updateTabuleiro() {
    int newTabuleiro[TABULEIRO_LIN][TABULEIRO_COL];
    int vivosCount = 0;  // Contador de células vivas

    // Aplica as regras de Conway a cada célula
    for (int i = 0; i < TABULEIRO_LIN; i++) {
        for (int j = 0; j < TABULEIRO_COL; j++) {
            int vizinhosVivos = countVizinhosVivos(i, j);

            // Regras do Jogo da Vida
            if (tabuleiro[i][j] == 1) {  // Célula viva
                newTabuleiro[i][j] = (vizinhosVivos == 2 || vizinhosVivos == 3) ? 1 : 0;
            } else {  // Célula morta
                newTabuleiro[i][j] = (vizinhosVivos == 3) ? 1 : 0;
            }

            // Atualiza contador de células vivas
            if (newTabuleiro[i][j] == 1) {
                vivosCount++;
            }
        }
    }

    // Atualiza o tabuleiro
    for (int i = 0; i < TABULEIRO_LIN; i++) {
        for (int j = 0; j < TABULEIRO_COL; j++) {
            tabuleiro[i][j] = newTabuleiro[i][j];
        }
    }

    // Incrementa o contador caso células vivas
    if (vivosCount > 0) {
        populationCount++;
    }
}

// Conta os vizinhos vivos de uma célula, passando por parâmetro as variáveis temporárias de comparação
int countVizinhosVivos(int x, int y) {
    int vivosCount = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // Avança

            int nx = (x + i + TABULEIRO_LIN) % TABULEIRO_LIN;
            int ny = (y + j + TABULEIRO_COL) % TABULEIRO_COL;

            vivosCount += tabuleiro[nx][ny]; 
        }
    }

    return vivosCount;  
}

void loop() {
    updateTabuleiro();    // Atualiza o estado do tabuleiro
    displayTabuleiro();   // Exibe o LCD
    delay(1000);  

    // Ao final, mostre o número total de populações
    // Exemplo de 20 gerações
    if (populationCount > 20) {  
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Populacoes:");
        lcd.setCursor(0, 1);
        lcd.print(populationCount);
        while (true);  // Pausa o programa
    }
}
