void SFrente (){
  
  digitalWrite(MT1, HIGH);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, HIGH);
  digitalWrite(MT4, LOW);

}

void SRe() {
  
  digitalWrite(MT1, LOW);
  digitalWrite(MT2, HIGH);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, HIGH);
  
}
void SDireita () {
    
  digitalWrite(MT1, HIGH);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, HIGH);
  
}

void SEsquerda () {
    
  digitalWrite(MT1, LOW);
  digitalWrite(MT2, HIGH);
  digitalWrite(MT3, HIGH);
  digitalWrite(MT4, LOW);
  
}

void SParar () {
    
  digitalWrite(MT1, LOW);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, LOW);
  
}
