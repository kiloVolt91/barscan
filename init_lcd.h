/*Inizializzazione LCD*/

void init_lcd(){
    lcd.begin(16, 2);
    lcd.print("Ready");
    delay(1000);
}
