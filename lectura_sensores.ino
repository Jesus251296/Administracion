/*Sensor de Temperatura, Humedad y Humo con snmpd*/
/*HOLA Mundo*/

#include <FileIO.h> //incluye la libreria de archivos
#include <LiquidCrystal.h> //incluye libreira LCD
LiquidCrystal lcd(8,9,10,11,12,13); // (rs, enable, pines)
#include <DHT.h>
//#define DHTPIN7 7 //sensor DHT 11
#define DHTPIN6 6
#define DHTPIN5 5 
#define DHTTYPE DHT11 
//DHT dht7(DHTPIN7, DHTTYPE);
DHT dht6(DHTPIN6, DHTTYPE);
DHT dht5(DHTPIN5, DHTTYPE);
void setup() {
 lcd.begin(16,2); //inicializamos el lcd
 Bridge.begin(); //iniciamos la comunicacion AVR - LININO
 Serial.begin(9600); //iniciamos la comunicacion serial a 9600 baudios
 FileSystem.begin(); //iniciamos la libreria de archivos
// dht7.begin();
 dht6.begin();
 dht5.begin();
}
void loop() { 
//int temp7 = dht7.readTemperature();//Lectura de temperatura rack centro
//int hume7 = dht7.readHumidity(); //Lectura de humedad rack centro
int temp6 = dht6.readTemperature();//Lectura de temperatura rack izquierda
int hume6 = dht6.readHumidity(); //Lectura de humedad rack izquierda
int temp5 = dht5.readTemperature();//Lectura de temperatura rack derecha
int hume5 = dht5.readHumidity(); //Lectura de humedad rack derecha
lcd.setCursor(0,0); lcd.print("Temp"); //imprime en la posicion
lcd.setCursor(5,0); lcd.print(temp6);
//lcd.setCursor(8,0); lcd.print(temp7);
lcd.setCursor(11,0); lcd.print(temp5);
lcd.setCursor(14,0); lcd.print((char)223);
lcd.setCursor(15,0); lcd.print("C");
lcd.setCursor(0,1); lcd.print("Hume");
lcd.setCursor(5,1); lcd.print(hume6);
//lcd.setCursor(8,1); lcd.print(hume7);
lcd.setCursor(11,1); lcd.print(hume5);
lcd.setCursor(14,1); lcd.print("%R");
 /*File script = FileSystem.open("/etc/snmp/temp7.sh",FILE_WRITE);
 script.print("#!/bin/sh\n");
 script.print("echo ");
 script.print(temp7);
 script.close(); */
 File script1 = FileSystem.open("/etc/snmp/temp6.sh",FILE_WRITE);
 script1.print("#!/bin/sh\n");
 script1.print("echo ");
 script1.print(temp6);
 script1.close(); 
 File script2 = FileSystem.open("/etc/snmp/temp5.sh",FILE_WRITE);
 script2.print("#!/bin/sh\n");
 script2.print("echo ");
 script2.print(temp5);
 script2.close(); 
 /*File script3 = FileSystem.open("/etc/snmp/hume7.sh",FILE_WRITE);
 script3.print("#!/bin/sh\n");
 script3.print("echo ");
 script3.print(hume7);
 script3.close(); */
 File script4 = FileSystem.open("/etc/snmp/hume6.sh",FILE_WRITE);
 script4.print("#!/bin/sh\n");
 script4.print("echo ");
 script4.print(hume6);
 script4.close();
 File script5 = FileSystem.open("/etc/snmp/hume5.sh",FILE_WRITE);
 script5.print("#!/bin/sh\n");
 script5.print("echo ");
 script5.print(hume5);
 script5.close();
// int adc_MQ0 = analogRead(A0); //Leemos la salida analógica del MQ
// float voltaje0 = adc_MQ0 * (5.0 / 1023.0); 
// int x = adc_MQ0-100;
// Serial.print("adc0: ");
// Serial.print(x);
 /*Serial.print(adc_MQ0);*/
 int adc_MQ1 = analogRead(A1); //Leemos la salida analógica del MQ
 float voltaje1 = adc_MQ1 * (5.0 / 1023.0); 
 Serial.print(" adc1: ");
 Serial.print(adc_MQ1);
 int adc_MQ2 = analogRead(A2); //Leemos la salida analógica del MQ
 float voltaje2 = adc_MQ2 * (5.0 / 1023.0); 
 Serial.print(" adc2: ");
 Serial.println(adc_MQ2);
 
// File script6 = FileSystem.open("/etc/snmp/smok0.sh",FILE_WRITE);
// script6.print("#!/bin/sh\n");
// script6.print("echo ");
// script6.print(x);
 /*script6.print(adc_MQ0);*/
// script6.close();
 File script7 = FileSystem.open("/etc/snmp/smok1.sh",FILE_WRITE);
 script7.print("#!/bin/sh\n");
 script7.print("echo ");
 script7.print(adc_MQ1);
 script7.close();
 File script8 = FileSystem.open("/etc/snmp/smok2.sh",FILE_WRITE);
 script8.print("#!/bin/sh\n");
 script8.print("echo ");
 script8.print(adc_MQ2);
 script8.close();
 delay(1000);
}
