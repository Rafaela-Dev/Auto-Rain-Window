// Autora: Rafaela B

#include <Servo.h>  // Biblioteca para controlar o servo motor

// Pinos
const int sensorChuva = A0;     // Sensor de chuva conectado ao pino analógico A0
const int valorLimite = 600;    // Valor limite para detectar chuva (ajustável)

Servo janela;                   // Objeto do servo motor

void setup() {
  Serial.begin(9600);           // Inicializa a comunicação serial
  janela.attach(9);             // Servo motor conectado ao pino digital 9
  janela.write(0);              // Janela começa aberta (posição 0 graus)
  delay(500);
  Serial.println("Sistema iniciado: janela aberta.");
}

void loop() {
  int leituraChuva = analogRead(sensorChuva);  // Lê o valor do sensor
  Serial.print("Valor do sensor: ");
  Serial.println(leituraChuva);

  if (leituraChuva < valorLimite) {
    // Chuva detectada
    janela.write(90);           // Fecha a janela (posição 90 graus)
    Serial.println("Chuva detectada! Janela fechando...");
  } else {
    // Tempo seco
    janela.write(3);            // Abre a janela (posição 0 graus)
    Serial.println("Tempo seco. Janela aberta.");
  }

  delay(3000);  // Aguarda 3 segundos antes de nova leitura
}
