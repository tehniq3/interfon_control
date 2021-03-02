/*
 * sistem comanda electromagnet la interfon Electra
 * realizare fizica: George DACIN
 * program: Nicu FLORICA (niq_ro)
 */

#define apel 2
#define raspuns 3
#define yala 4

byte starebuton;             // the current reading from the input pin
byte citirestarebuton;   // 
byte ultimastarebuton = HIGH;   // the previous reading from the input pin

unsigned long ultimtpdebounce = 0;  // the last time the output pin was toggled
unsigned long tpdebounce = 50;    // the debounce time; increase if the output flickers
unsigned long tpcomanda = 1000;  // activate relay time in ms

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

citirestarebuton = digitalRead(apel);  // read the state of the switch into a local variable: 
  if (citirestarebuton != ultimastarebuton) // If the switch changed, due to noise or pressing:
  {
    ultimtpdebounce = millis();  // reset the debouncing timer
  }
  if ((millis() - ultimtpdebounce) > tpdebounce) 
  {
    if (citirestarebuton != starebuton) // if the button state has changed
    {
      starebuton = citirestarebuton;         
      if (starebuton == LOW) // only toggle the LED if the new button state is LOW
      {
  digitalWrite(raspuns, HIGH);
  delay(tpcomanda);
  digitalWrite(yala, HIGH);
  delay(tpcomanda);
  digitalWrite(raspuns, LOW);
  digitalWrite(yala, LOW);
      }
    }
  }
ultimastarebuton = citirestarebuton;
} // sfarsit program
