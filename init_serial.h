/*Inizializzazione Comunicazione Seriale con PC e sensori */
void init_serial()
{
   Serial.begin(9600); // AVVIO DELLA COMUNICAZIONE SERIALE con il computer // DA RIMUOVERE
   //Serial2.begin(4800); // AVVIO DELLA COMUNICAZIONE SERIALE CON IL BARCODE - BAUDRATE SETTABILE DA SENSORE
   lcd.print("Serial Ready");
   delay(1000);
   lcd.clear();
   //Serial.print("Communication Ready");
   delay(100);
}
