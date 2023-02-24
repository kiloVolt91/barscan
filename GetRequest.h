/*Function GET REQUEST */ 
/*
 * Trasmette stringa di valori al server per ricevere risposta
 */

#include <ESP8266HTTPClient.h>  // Richiesta GET http
#include <ArduinoJson.h> // Conversione json to string

String getHTTPrequest(String url) {

   /* 
    *  SE LA CONNESSIONE DEL CLIENT NON VA A BUON FINE -> RIAVVIA IL LOOP 
   */
   if (!client.connect(__SERVER_HOST__,__SERVER_PORT__)) 
   {    
      //Serial.println("connection failed");
      lcd.clear();
      lcd.print("Conn. Failed");
      delay (1000);

      
      String res = "connection failed";
      return res;
   }
   else 
   {
      /*  
       * SE LA CONNESSIONE DEL CLIENT E' ANDATA A BUON FINE 
       */
       //Serial.println("Connected");  
      lcd.clear();
      lcd.print("Connected");
      delay (1000);
   }
 
   //Serial.print("Requestin URL: ");
   //Serial.println (url);
      lcd.clear();
      lcd.print("Richiesta URL");
      lcd.setCursor(0,1);
      lcd.print(url);
      delay (1000);
      
   HTTPClient http;   // CREAZIONE DI UNA VARIABILE DI CLASSE HTTP DI NOME "http"
   //Serial.print("[HTTP] begin...\n");
      lcd.clear();
      lcd.print("Richiesta HTTP");
      delay (1000);
   if ( http.begin(client,url) ) 
   {  
      /* INIZIALIZZAZIONE DELLA COMUNICAZIONE HTTP  */
      //Serial.print("[HTTP] GET...\n");
      lcd.clear();
      lcd.print("GET HTTP");
      delay (1000);
   
      /* INVIO DI UNA "GET REQUEST" (HTTP header) ALL'INDIRIZZO INDICATO DURANTE L'INIZIALIZZAZIONE */
      int httpCode = http.GET();              
      
      if ( httpCode > 0 ) 
      {                                 
         /* IN CASO DI ERRORE "httpCode" sarà NEGATIVO, IN CASO DI RISPOSTA ALLA RICHIESTA GET, IL SERVER RISPONDERA' AFFERMATIVAMENTE (200) */
         //Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      lcd.clear();
      lcd.print("httpCode >0");
      delay (1000);

         /* COMUNICAZIONE DEL DATO OTTENUTO IN RISPOSTA ALLA RICHIESTA */
         if ( httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY ) 
         {
            /* PAYLOAD è IL DATO OTTENUTO */
            String payload = http.getString();  
            //Serial.println("*** RISPOSTA DEL SERVER ***");
            //Serial.println(payload);
      lcd.clear();
      lcd.print("Risposta");
      lcd.setCursor(0,1);
      lcd.print(payload);
      delay (1000);
                 
            /* CONVERSIONE ED ESTRAZIONE DEL DATO */
            DynamicJsonDocument doc(1024); // DIMENSIONE DEL DATO JSON
            String input = payload;
            deserializeJson(doc, input);
            JsonObject obj = doc.as<JsonObject>();

            /* You can use a String to get an element of a JsonObject. No duplication is done. */
            int ans_status = obj[String("status")];
            String ans_message = obj[String("message")];
            //Serial.println("*** status da json ***");
            //Serial.println(ans_status);
            //Serial.println(ans_message);
      lcd.clear();
      lcd.print("Json ");    
      lcd.print(ans_message);
      lcd.setCursor(0,1);
      lcd.print(ans_message);
      delay (1000);
            String res = ans_message;
            return res;     
          }
      } 
      else 
      {
         //Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      
      lcd.clear();
      lcd.print("GET Failed");
      delay(1000);

         
         String res = "[HTTP] GET... failed, error";
         return res;
      }
      http.end();
   }
   else
   {
      //Serial.printf("[HTTP} Unable to connect\n");
      lcd.clear();
      lcd.print("Conn. Failed");
      delay(1000);
      String res = "[HTTP} Unable to connect";
      return res;
   }
}
