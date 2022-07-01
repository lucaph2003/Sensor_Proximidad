#include <Wire.h>      // libreria de comunicacion por I2C
#include <LCD.h>      // libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7
const int Echo = 9;
const int Trigger = 8;
int x;
int cont;
const int ledPIN2 = 7;
const int ledPIN = 6;
const int buz=10;
float sinVal;
int toneVal;

void setup()
{
    lcd.setBacklightPin(3,POSITIVE);  // puerto P3 de PCF8574 como positivo
    lcd.setBacklight(HIGH);   // habilita iluminacion posterior de LCD
    lcd.begin(16, 2);     // 16 columnas por 2 lineas para LCD 1602A
    lcd.clear(); // limpia pantalla
     Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
   pinMode(ledPIN , OUTPUT);  //definir pin como salida
  pinMode(ledPIN2 , OUTPUT);
  pinMode(buz, OUTPUT);
 
}

void loop()
{
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  


  if (d < 20){
   digitalWrite(ledPIN , LOW);
   lcd.setCursor(0, 0);    // ubica cursor en columna 0 y linea 1
   tone(buz,100);
   delay(100);
   noTone(buz);
   lcd.print("   CUIDADO!!!");
   lcd.setCursor(0, 1);
   lcd.print("Objeto a: ");
   lcd.print(d);
   lcd.print("cm");
   digitalWrite(ledPIN2 , HIGH);   // poner el Pin en HIGH
   delay(100);                   // esperar un segundo
   digitalWrite(ledPIN2 , LOW);    // poner el Pin en LOW
   delay(1000);
   lcd.clear();
   
     
           if (d < 10){
            
                digitalWrite(ledPIN , LOW);
                 lcd.setCursor(0, 0);    // ubica cursor en columna 0 y linea 1
                 lcd.print("   CUIDADO!!!");
                  lcd.setCursor(0, 1);
                lcd.print("Objeto a: ");
                  lcd.print(d);
              lcd.print("cm");
             
               
                digitalWrite(ledPIN2 , HIGH);   // poner el Pin en HIGH
                delay(50);                   // esperar un segundo
               digitalWrite(ledPIN2 , LOW);    // poner el Pin en LOW
               delay(100);
               lcd.clear();
              tone(buz, 261.63, 200);
              delay(200);
               noTone(buz);
                 
              
               
           
            
}
  
  }else{
   digitalWrite(ledPIN , HIGH);   // poner el Pin en HIGH
   delay(1000);                   // esperar un segundo
   
  }

    
      
   

}
