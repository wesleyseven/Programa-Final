void seguidor_de_linha() {

  bool ESensorD = digitalRead(SensorD);
  bool ESensorE = digitalRead(SensorE);

  if (ESensorD==LOW && ESensorE==LOW) {
  SFrente();
  } 
  
  else if (ESensorD) {
  SDireita();
  }

  else if (ESensorE) {
   SEsquerda();
  }

  delay(100);
}


void SFrente (){
  
  digitalWrite(MT1, HIGH);
  digitalWrite(MT3, HIGH);

}

void SDireita () {
    
  digitalWrite(MT1, LOW);
  digitalWrite(MT3, HIGH);
  
}

void SEsquerda () {
    
  digitalWrite(MT1, HIGH);
  digitalWrite(MT3, LOW);
  
}
