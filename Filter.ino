float filterfuckingtemp(float intemp){
  float rueck = 0;
  //Serial.println(intemp);

  if((intemp != DEVICE_DISCONNECTED_C) && (intemp != 85.00)){
    speicher[speicherplatz] = intemp;
    speicherplatz++;
  }
  if(speicherplatz > 19){
    speicherplatz = 0;
  }
  if((intemp == DEVICE_DISCONNECTED_C) || (intemp == 85.00)){
    stoerung ++;
  }
  else{
    stoerung = 0;
  }

  if(stoerung < 100){
      for(int i = 0; i<20; i++){

    rueck+=speicher[i];
   }
   rueck = ((rueck*100)/20)/100;
  }

  else{
    rueck = FEHLER;   
  }

  

  return rueck;
}

void speicherfuellen(void){
  for (speicherplatz; speicherplatz<20; speicherplatz++){

    float temp = sensors.getTempCByIndex(0);

     
    if((temp != DEVICE_DISCONNECTED_C) && (temp != 85.00)){
      speicher[speicherplatz] = temp;   
    }
    else{
      speicher[speicherplatz] = 0;
    }

    
     
  }
}
