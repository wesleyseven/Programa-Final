void ultrassonico() {
  
       distancia = sonar.ping_cm(); 
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Approximation:");
       lcd.setCursor(5,1);
       lcd.print(distancia);

       delay(250);
}
