/*Function CREAZIONE STRINGA URL */
String createURL(String url){
        String res = 
        String ("http://")         + 
        String(__SERVER_HOST__)    + 
        String(":")                +
        String(__SERVER_PORT__)    +
        String(__SERVER_URL__)     +
        url;
        return res;
   
}
