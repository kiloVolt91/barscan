    int barcode_length = 8; //numero di cifre che compongono il barcode
    byte message[] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x02, 0x01, 0xAB, 0xCD};
    const int button = D4;
    byte ind = 0;
    byte variable [14] = {0};
    byte answer [7] = {0};
    byte qcode [8] = {0};
    long int t1 =0; // ATTENZIONARE TEMPO MASSIMO DI ACCENSIONE DEL COMPONENTE - MILLIS() - PREVEDERE RESET
    String QCODE = "";
    String ANSWER = "";
    int prova;
