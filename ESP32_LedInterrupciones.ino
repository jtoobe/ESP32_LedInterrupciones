/*     
 Encender un led con interrupciones
*/
    
    int led  = 5;  // Pin donde está conectado el LED
    int boton = 18; // Pin donde está conectado el pulsador
    boolean estado=true;
    
    void setup() {                
      pinMode(led, OUTPUT);
      pinMode(boton, INPUT);
      attachInterrupt(digitalPinToInterrupt(boton), controlar, CHANGE); 
      Serial.begin(115200);     
    }
    
    void loop() {
      /* Aquí no hay nada que hacer
       * para este script, pero podriamos
       * estar controlando un sensor por ejemplo
       */
       delay(1000);
       Serial.println(estado);
    }

    // Funcion que se ejecuta con la interrupcion
  
    void controlar() {
      if (estado) // Si el botón está pulsado
      {
        digitalWrite(led,LOW); // encendemos el LED
        estado=false;
      }
      else // Sino..
      {
        digitalWrite(led, HIGH); // apagamos el LED
        estado=true;
      }
      
    }
