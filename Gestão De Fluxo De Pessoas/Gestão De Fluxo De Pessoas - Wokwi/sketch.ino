#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define o LCD com o endereço I2C (0x27) e tamanho 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define BOTAO_ENTRADA 6 // Pino do botão de entrada
#define BOTAO_SAIDA 7   // Pino do botão de saída

int pessoasDentro = 0; // Contador de pessoas dentro

void setup() {
  // Configura os pinos SDA e SCL para o LCD
  Wire.setSDA(16); // GP16
  Wire.setSCL(17); // GP17
  Wire.begin();

  // Inicializa o LCD
  lcd.init();
  lcd.backlight(); // Liga a luz de fundo do LCD
  lcd.begin(16, 2); // Configura o LCD para 16 colunas e 2 linhas
  lcd.print("Sistema de Fluxo");
  lcd.setCursor(0, 1);
  lcd.print("de Pessoas");

  // Configura os pinos de entrada dos botões
  pinMode(BOTAO_ENTRADA, INPUT_PULLUP);  // Botão de entrada
  pinMode(BOTAO_SAIDA, INPUT_PULLUP);    // Botão de saída
}

void loop() {
  // Lê os botões
  bool botaoEntrada = digitalRead(BOTAO_ENTRADA) == LOW;  // Botão de entrada
  bool botaoSaida = digitalRead(BOTAO_SAIDA) == LOW;      // Botão de saída

  // Se o botão de entrada for pressionado, aumenta o contador
  if (botaoEntrada) {
    pessoasDentro++;
    delay(300); // Anti-rebote
  }

  // Se o botão de saída for pressionado, diminui o contador
  if (botaoSaida && pessoasDentro > 0) {
    pessoasDentro--;
    delay(300); // Anti-rebote
  }

  // Exibe o número de pessoas no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pessoas: ");
  lcd.print(pessoasDentro);
  delay(500);  // Atualiza a cada meio segundo
}
