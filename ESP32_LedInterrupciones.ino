/*     
* Encender un led con interrupciones, mejor funcionamiento que los otros
* que no usan interrupciones. Por que ?
*/
    
const int ledPin = 32;
const int switchPin = 23;

volatile bool ledState = LOW; // Estado inicial del LED
volatile bool switchPressed = false; // Estado inicial del interruptor

void IRAM_ATTR switchInterrupt() {
  // Cambiar el estado del interruptor
  switchPressed = !switchPressed;  // invierto el valor

  // Cambiar el estado del LED basado en el estado del interruptor
  if (switchPressed) {
    ledState = !ledState;         // invierto el valor
    digitalWrite(ledPin, ledState);
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP); // Habilitar la resistencia pull-up interna
  
  // Configurar la interrupción en el flanco de bajada (cuando el interruptor se presiona)
  attachInterrupt(digitalPinToInterrupt(switchPin), switchInterrupt, FALLING);
        /*
         * LOW para activar la interrupción cuando el pin está bajo;
         * CHANGE para activar la interrupción cada vez que el pin cambia de valor;
         * RISING para disparar cuando el pin va de bajo a alto;
         * FALLING para cuando el pin pasa de alto a bajo.
        */
}

void loop() {
  // codigo principal (opcional)
}
