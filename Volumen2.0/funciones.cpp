#include "funciones.h"


uint8_t vol = 0;
uint8_t canal = 1;
unsigned long ultimaActividad = 0;
bool datosModificados = false;
uint16_t contadorEscrituras = 0;

const uint8_t VOL_MAX = 100;
const uint8_t VOL_MIN = 0;
const uint8_t CANAL_MAX = 9;
const uint8_t CANAL_MIN = 1;

void conf(void) {
  Serial.begin(BAUDRATE);
  pinMode(BTN_VOL_UP, INPUT_PULLUP);
  pinMode(BTN_VOL_DOWN, INPUT_PULLUP);
  pinMode(BTN_CH_UP, INPUT_PULLUP);
  pinMode(BTN_CH_DOWN, INPUT_PULLUP);
}


void iniciarEEPROM(void) {
  vol = EEPROM.read(EEPROM_VOL_ADDR);
  canal = EEPROM.read(EEPROM_CH_ADDR);

  
  if (vol > VOL_MAX) vol = 50;
  if (canal < CANAL_MIN || canal > CANAL_MAX) canal = 1;

  guardarEEPROM();
}


void manejarEEPROM(void) {
  if (datosModificados && millis() - ultimaActividad > 2000) {
    guardarEEPROM();
    datosModificados = false;
  }
}


void guardarEEPROM(void) {
  EEPROM.update(EEPROM_VOL_ADDR, vol);
  EEPROM.update(EEPROM_CH_ADDR, canal);
  contadorEscrituras++;
}


void leerBotones(void) {
  if (digitalRead(BTN_VOL_UP) == LOW) {
    incrementarVolumen();
    delay(200);
  }
  if (digitalRead(BTN_VOL_DOWN) == LOW) {
    decrementarVolumen();
    delay(200);
  }
  if (digitalRead(BTN_CH_UP) == LOW) {
    incrementarCanal();
    delay(200);
  }
  if (digitalRead(BTN_CH_DOWN) == LOW) {
    decrementarCanal();
    delay(200);
  }
}


void incrementarVolumen(void) {
  if (vol < VOL_MAX) {
    vol++;
    ultimaActividad = millis();
    datosModificados = true;
  }
}

void decrementarVolumen(void) {
  if (vol > VOL_MIN) {
    vol--;
    ultimaActividad = millis();
    datosModificados = true;
  }
}


void incrementarCanal(void) {
  canal++;
  if (canal > CANAL_MAX) canal = CANAL_MIN; 
  ultimaActividad = millis();
  datosModificados = true;
}

void decrementarCanal(void) {
  if (canal == CANAL_MIN) canal = CANAL_MAX; 
  else canal--;
  ultimaActividad = millis();
  datosModificados = true;
}

void mostrarEstado(void) {
  static uint8_t ultimoVol = 255;
  static uint8_t ultimoCanal = 255;

  if (vol != ultimoVol || canal != ultimoCanal) {
    Serial.print("Volumen: ");
    Serial.print(vol);
    Serial.print(" | Canal: ");
    Serial.print(canal);
    Serial.print(" | Escrituras EEPROM: ");
    Serial.println(contadorEscrituras);

    ultimoVol = vol;
    ultimoCanal = canal;
  }
}
