
#include "parametri_rete.h"
#include "parametri_lcd.h"
#include "parametri_barcode.h"
#include "createURL.h"
#include "GetRequest.h"
#include "connectToWifi.h"
#include "init_lcd.h"
#include "init_serial.h"
// Se nel codce c'è la stringa "NO", accesso non consentito, altrimenti si

  String readString; // Variabile di lettura del Barcode da seriale
  int  n = 0; // contatore loop
  

/* AVVIO SETUP*/ 
void setup() {
  
    init_lcd();           // AVVIO LCD
    init_serial();        //AVVIO COMUNICAZIONE SERIALE
    connectToWifi();     // AVVIO DELLA CONNESSIONE WIFI
    pinMode(button, INPUT);
    delay(1000);
    Serial.swap();
    lcd.clear();
    lcd.print("Setup Completo");
    delay(1000);
    }


void loop() {
      
    char phrase[14] = {'R', 'e', 'a', 'd', 'y', ' ', 't', 'o', ' ','s', 'c', 'a', 'n', ' '};      // Durante il Loop scrivi il messaggio "Pronto a Scansionare"
    
    lcd.print(phrase[n]);
    n++;
    if (n==15){
      n=0;
      lcd.clear();
    }
    delay(250);
      if (digitalRead(button)==LOW)
     {
       delay(500);
       Serial.write(message, sizeof(message)); 
   
//       Serial.println("Messaggio Trasmesso");
//       delay(10);

    lcd.clear();
    lcd.print("MESSAGGIO TRASMESSO");
    delay(250);
    
    
       t1=millis();
       while (millis()-t1<5000)
          {
//           while (Serial.available())
//                 {      
//                  byte ans;
//                  byte b = Serial.read();
//                  variable[ind]=b;
//                  if (ind <= 6) // Memorizzare nome indice
//                     {
//                      answer[ind] = b;
//                      ANSWER += (String)(char)answer[ind];
//                     }
//                  else if(ind <= 14) // Memorizzare nome indice Sottraendo al barcode length l'indice della riga sopra
//                     {
//                      qcode[ind] = b;
//                      QCODE += (String)(char)qcode[ind];
//                     }
//                  ind++;     
//                  }

                                         while (Serial.available())
                                                                   {      
                                                                    byte ans;
                                                                    byte b = Serial.read();
                                                                    variable[ind]=b;
                                                                    
                                                                    if (ind <= 6) // Memorizzare nome indice

                                                                                 {
                                                                                  lcd.clear();
                                                                                  answer[ind] = b;
                                                                                  ANSWER += (String)(char)answer[ind];

                                                                                  /**/
                                                                                  lcd.setCursor(0,0);
                                                                                  lcd.print("answer");
                                                                                  lcd.setCursor(0,1);
                                                                                  lcd.print(answer[ind]);
                                                                                  delay(1000);
                                                                                  /**/
                                                                                 }
                                                                                                                                                    
                                                                    else if(ind <= 14) // Memorizzare nome indice Sottraendo al barcode length l'indice della riga sopra
                                                                                 
                                                                                 {
                                                                                  lcd.clear();
                                                                                  qcode[ind] = b;
                                                                                  QCODE += (String)(char)qcode[ind];
                                                                                  
                                                                                  /**/                                                                                  
                                                                                  lcd.setCursor(0,0);
                                                                                  lcd.print("qcode");
                                                                                  lcd.setCursor(0,1);
                                                                                  lcd.print(qcode[ind]);
                                                                                  delay(1000);
                                                                                  /**/
                                                                                 }
                                                                    ind++;     
                                                                   }








          }
//       Serial.print("variable 0: "); Serial.println(variable[0], HEX);
//       Serial.print("variable 1: "); Serial.println(variable[1], HEX);
//       Serial.print("variable 2: "); Serial.println(variable[2], HEX);
//       Serial.print("variable 3: "); Serial.println(variable[3], HEX);
//       Serial.print("variable 4: "); Serial.println(variable[4], HEX);
//       Serial.print("variable 5: "); Serial.println(variable[5], HEX);
//       Serial.print("variable 6: "); Serial.println(variable[6], HEX);
//       Serial.print("variable 7: "); Serial.println(variable[7], HEX);
//       Serial.print("variable 8: "); Serial.println(variable[8], HEX);
//       Serial.print("variable 9: "); Serial.println(variable[9], HEX);
//       Serial.print("variable 10: "); Serial.println(variable[10], HEX);
//       Serial.print("variable 11: "); Serial.println(variable[11], HEX);
//       Serial.print("variable 12: "); Serial.println(variable[12], HEX);
//       Serial.print("variable 13: "); Serial.println(variable[13], HEX);
//       Serial.print("variable 14: "); Serial.println(variable[14], HEX);
//       Serial.print( "Il Qcode è: "); Serial.println(QCODE);
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(QCODE);
      lcd.setCursor(0,1);
      delay (1000);

      String __URL_STRING__ = createURL(QCODE);
//      Serial.println(__URL_STRING__);



      
      QCODE = "";    
      
      String RESPONSE = getHTTPrequest (__URL_STRING__);
      lcd.print(RESPONSE);
      delay(1000);
      
       ind = 0;
       
       for (int k=1;k<15;k++) 
           {
            variable[k] = 0;
           }
       delay(1000);
       lcd.clear();
    }
}
     
  
     
//     while (Serial2.available()) {
//      delay(1);
//      char q_code = Serial2.read();
//      readString += q_code;
//     }
//
//     if (readString.length()>= barcode_length) {
//      Serial.print(readString);
//      lcd.clear();
//      lcd.setCursor(0,0);
//      lcd.print(readString);
//      lcd.setCursor(0,1);
//      delay (10);
//      
//      String __URL_STRING__ = createURL(readString);
//      Serial.println(__URL_STRING__);
//      readString = "";
//    
//      String RESPONSE = getHTTPrequest (__URL_STRING__);
//      lcd.print(RESPONSE);
// 
//delay(5000);
//lcd.clear();
//}
//}
