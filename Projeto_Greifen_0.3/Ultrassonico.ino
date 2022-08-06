void ultrassonico() {
  
       distancia = sonar.ping_cm(); 
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Approximation:");
       lcd.setCursor(5,1);
       lcd.print(distancia);

       delay(250);
}

void impacto() {
  
       distancia = sonar.ping_cm(); 
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Approximation:");
       lcd.setCursor(5,1);
       lcd.print(distancia);


     if(distancia>20){
       SFrente();
      }

     else if(distancia<10){
      SRe();
     }

     else if(distancia<=20 && distancia >=10){
       SDireita();
     }
   
    delay(100);
}
