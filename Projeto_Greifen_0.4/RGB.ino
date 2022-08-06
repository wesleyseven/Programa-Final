void RGB (){    
         
         if(++mode > 4) mode = 0; 
            switch(mode) {
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);   // Desligado
          break;
        case 1:
          colorWipe(strip.Color(255,   0,   0), 50);    // Vermelho
          break;
        case 2:
          colorWipe(strip.Color(0, 255,   0), 50);    // Verde
          break;
        case 3:
          colorWipe(strip.Color(0,   0, 255), 50);    // Azul
          break;
        case 4:
          colorWipe(strip.Color(100,   49, 206), 50);    // Roxo
          break;  
   }
}      

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);        
    strip.show();                         
    delay(wait);                          
  }
}
