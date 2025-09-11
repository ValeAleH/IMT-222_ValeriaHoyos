#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <EEPROM.h>


#define BTN_VOL_UP    2
#define BTN_VOL_DOWN  3
#define BTN_CH_UP     4
#define BTN_CH_DOWN   5
#define BAUDRATE 115200

#define EEPROM_VOL_ADDR  0
#define EEPROM_CH_ADDR   1

extern uint8_t vol;
extern uint8_t canal;
extern unsigned long ultimaActividad;
extern bool datosModificados;
extern uint16_t contadorEscrituras;


void conf(void);
void iniciarEEPROM(void);
void manejarEEPROM(void);
void guardarEEPROM(void);
void leerBotones(void);
void incrementarVolumen(void);
void decrementarVolumen(void);
void incrementarCanal(void);
void decrementarCanal(void);
void mostrarEstado(void);

#endif
