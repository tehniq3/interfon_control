/*
 * sistem comanda electromagnet la interfon Electra
 * realizare fizica: George DACIN
 * program: Nicu FLORICA (niq_ro)
 */

#define apel 2
#define raspuns 3
#define yala 4

byte suna = 1;  

void setup() {
pinMode(apel, INPUT);
digitalWrite(apel, HIGH);
pinMode(raspuns, OUTPUT);
pinMode(yala, OUTPUT);
digitalWrite(raspuns, LOW);
digitalWrite(yala, LOW);
}

void loop() {

suna = digitalRead(apel);

if (suna == 0)
{
  digitalWrite(raspuns, HIGH);
  delay(1000);
  digitalWrite(yala, HIGH);
  delay(1000);
  suna = 1;
  digitalWrite(raspuns, LOW);
  digitalWrite(yala, LOW);
}

} // sfarsit program
