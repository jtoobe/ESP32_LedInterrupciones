/*     
* Encender un led con interrupciones, mejor funcionamiento que los otros
* que no usan interrupciones. Por que ?
*/
    
    int led  = 32;  // Pin donde está conectado el LED
    int boton = 23; // Pin donde está conectado el pulsador
    boolean estado=true;
    
    void setup() {                
      pinMode(led, OUTPUT);
      pinMode(boton, INPUT_PULLUP);
       
        /*
         * LOW para activar la interrupción cuando el pin está bajo;
         * CHANGE para activar la interrupción cada vez que el pin cambia de valor;
         * RISING para disparar cuando el pin va de bajo a alto;
         * FALLING para cuando el pin pasa de alto a bajo.
        */
      attachInterrupt(digitalPinToInterrupt(boton), controlar, CHANGE); 
      Serial.begin(115200);     
    }
    
    void loop() {
      /* Aquí no hay nada que hacer
       * para este script, pero podriamos
       * estar controlando un sensor por ejemplo
       */
    }

    // Funcion que se ejecuta con la interrupcion
  
    void controlar() {
      if (estado) // Si el botón está pulsado
      {
        digitalWrite(led,LOW); // encendemos el LED
        estado=false;
        Serial.println(estado);
      }
      else // Sino..
      {
        digitalWrite(led, HIGH); // apagamos el LED
        estado=true;
        Serial.println(estado);
      }
      
    }
