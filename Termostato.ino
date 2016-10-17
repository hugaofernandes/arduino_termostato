//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Termostato
// 
// Made by hugo medeiros fernandes
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/2147316-termostato

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

int rele = 2;
int sensor = 0;
int count = 0;
float graus = 28.0;
float temperatura = 0.0;
float voltage = 0.0;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  voltage = (float(analogRead(sensor)) * 5.0) / 1024.0;
  temperatura += (voltage - 0.5) * 100.0;
  count++;
  if (count == 10){
    temperatura /= count;    
    Serial.println(temperatura);
    if (temperatura >= graus){
    	digitalWrite(rele, HIGH);
    }
    else {
    	digitalWrite(rele, LOW);
    }
  	count = 0;
	temperatura = 0.0;
  }
}

