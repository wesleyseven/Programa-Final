void Frente (){

  if(CPS.Button(PSB_L2)) {
  
  digitalWrite(MT1, HIGH);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, HIGH);
  digitalWrite(MT4, LOW);
  }
  else {Parar ();}
}

void Re (){

  if(CPS.Button(PSB_R2)) {
    
  digitalWrite(MT1, LOW);
  digitalWrite(MT2, HIGH);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, HIGH);
   }
}

void Direita () {

  if(CPS.Button(PSB_PAD_RIGHT)) {
    
  digitalWrite(MT1, HIGH);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, HIGH);
  }
}

void Esquerda () {

  if(CPS.Button(PSB_PAD_LEFT)){
    
  digitalWrite(MT1, LOW);
  digitalWrite(MT2, HIGH);
  digitalWrite(MT3, HIGH);
  digitalWrite(MT4, LOW);
  }
}

void Parar () {
  digitalWrite(MT1, LOW);
  digitalWrite(MT2, LOW);
  digitalWrite(MT3, LOW);
  digitalWrite(MT4, LOW);
}
