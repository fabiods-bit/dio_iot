const int pinoVentilador = 7;
const int pinoLed = 8;
const int pinoBuzina = 9;
const int pinoSensor = A0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoVentilador, OUTPUT);
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoBuzina, OUTPUT);
}

void loop() {
  int leitura = analogRead(pinoSensor);
  float temperatura = (leitura * 5.0 / 1023.0) * 100;

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  if (temperatura >= 30 && temperatura < 50) {
    digitalWrite(pinoVentilador, HIGH);
    digitalWrite(pinoLed, LOW);
    digitalWrite(pinoBuzina, LOW);
  } else if (temperatura >= 50) {
    digitalWrite(pinoVentilador, HIGH);
    digitalWrite(pinoLed, HIGH);
    tone(pinoBuzina, 1000);
  } else {
    digitalWrite(pinoVentilador, LOW);
    digitalWrite(pinoLed, LOW);
    noTone(pinoBuzina);
  }

  delay(1000);
}
