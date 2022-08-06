void seguidor_de_linha() {

  bool ESensorD = digitalRead(SensorD);
  bool ESensorE = digitalRead(SensorE);

  if (ESensorD==LOW && ESensorE==LOW) {
  SFrente();   
  }

  else if (ESensorD==HIGH && ESensorE==HIGH) {
  SParar();   
  }
  
  else if (ESensorD) {
  SDireita();
  }

  else if (ESensorE) {
  SEsquerda();
  }

  delay(100);
}
