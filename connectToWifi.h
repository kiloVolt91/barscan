/*FUNCTION CONNESSIONE WIFI TO INTERNET */

//#include <WiFi.h>


void connectToWifi() {                                                 
  WiFi.begin(ssid, password);  // Avvio del WiFi
  //Serial.println();                 
  //Serial.println();                 
  //Serial.print("Connecting to ");

      lcd.clear();
      lcd.print("Conn. in Corso ");
      delay(1000);

  Serial.println(ssid);
 
  while (WiFi.status() != WL_CONNECTED) {      // ... Connessione in corso ...
   // Serial.print(".");
    lcd.print(".");
    delay(250);                                // AGGIUNGERE AVVISO DI MANCATA CONNESSIONE
  }
  //Serial.println("");
  //Serial.println("WiFi connected");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WiFi connected");  
  delay(1000);
  //Serial.println("IP address: ");  
  //Serial.println(WiFi.localIP());
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP()); 
  delay(1000);
  //Serial.print ("Tempo Impiegato");
  //Serial.println(millis());
  //Serial.print("MAC: ");
  //Serial.println(WiFi.macAddress());
  //delay(1500);
  lcd.clear();
}
