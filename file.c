const int temp_trans_pin = A0;
const int Heater_pin = 13;
const int FAN_Pin = 6;

// Set the range of the desire temperature

float MinTemp=20, MaxTemp=25; // Room temp [20-25]

#include<LiquidCrystal.h> // library name included

LiquidCrystal LCD (12, 11, 5, 4, 3, 2);

void setup(){
  LCD.begin(16,2);
  pinMode(Heater_pin,OUTPUT);
  pinMode(FAN_Pin,OUTPUT);
  
  LCD.print("Room Temp(C): ");
  LCD.setCursor(2,1);
  LCD.print(MinTemp);
  LCD.print("-");
  LCD.print(MaxTemp);
  
  delay(2000);
  
}

void loop() {
  
  float Eqv_volt, SensorTemp;
  
  Eqv_volt=analogRead(temp_trans_pin)*5.0/1023;
  SensorTemp = 100.0*Eqv_volt-50.0;
  
  LCD.clear();
  LCD.print("Sensor Reading: ");
  LCD.setCursor(2, 1);
  LCD.print(SensorTemp);
  LCD.print(" C");
    
  delay(2000);
  
  if (SensorTemp>MaxTemp){
    LCD.clear();
    LCD.print("Temp is HIGHER!");
    LCD.setCursor(0,1);
    LCD.print("Turn on FAN!");
    
    for(int i=0; i<=255; i++){
      analogWrite(FAN_Pin, i);
      }
    
    delay(2000);
    
    LCD.clear();
    LCD.print("Now temp is OK!");
    LCD.setCursor(0,1);
    LCD.print("Turn off FAN!");
    
    for(int i=255; i>0; i--){
      analogWrite(FAN_Pin, i);
      }
    
    delay(2000);
    
    }
  
  else if(SensorTemp<MinTemp){
    LCD.clear();
    LCD.print("Temp is LOWER!");
    LCD.setCursor(0,1);
    LCD.print("Turn on HEATER!"); 
  
 digitalWrite(Heater_pin, HIGH);
    
    delay(3000);
    
    LCD.clear();
    LCD.print("Now temp is OK!");
    LCD.setCursor(0,1);
    LCD.print("Turn off HEATER!");
    
    delay(1000);
    
    digitalWrite(Heater_pin, LOW);
    LCD.clear();
  }
  
  else if(SensorTemp>MinTemp && SensorTemp<MaxTemp){
    
    LCD.clear();
    LCD.print("Temp is normal!");
    LCD.setCursor(2,1);
    LCD.print("Turn off all");
    
    delay(1000);
    
    LCD.clear();    
  }
    
  else{
    
    LCD.clear();
    LCD.print("Something went wrong");
    LCD.setCursor(2,1);
    LCD.print("wrong in the circuit");
    
    delay(1000);
    LCD.clear();
    
  }
  
  delay(1000); 
  } 
