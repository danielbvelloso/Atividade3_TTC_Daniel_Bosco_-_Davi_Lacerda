//Código do dispositivo B
#include <SPI.h>
#include <LoRa.h>

const int ss = 5;
const int rst = 14;
const int dio0 = 2;

int contador = 0;
unsigned long tempoT = 0;

void setup() {
  Serial.begin(115200);
  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Erro LoRa ESP32");
    while (1);
  }
  
  LoRa.setTxPower(17);
  LoRa.setSpreadingFactor(7);
  Serial.println("ESP32 OK: Enviando #0 a #4");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String rx = "";
    while (LoRa.available()) rx += (char)LoRa.read();
    Serial.println("RECEBIDO: " + rx);
  }

  if (millis() - tempoT > 4000) {
    Serial.println("ENVIANDO: #" + String(contador));
    LoRa.beginPacket();
    LoRa.print("#" + String(contador));
    LoRa.endPacket();
    
    contador++;
    if (contador > 4) contador = 0; 
    tempoT = millis();
  }
}
