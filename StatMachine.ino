void state_machine(int state, float temp){
  switch(state){
    case heiz_60:
      
      ausgabe(heiz_60,temp);
      digitalWrite(RELAY, ON);
      brennerstat = 1;
      
      if (temp < ERSTETEMP){
        newstate = heiz_60; 
          if (digitalRead(TASTER)){
            newstate = einmeisch;
            ausgabe(einmeisch,temp);
            while(digitalRead(TASTER)){}
          }
      }
      else{
        newstate = einmeisch;
      }
      break;
      
    case (einmeisch):
    
      ausgabe(einmeisch,temp);  
      digitalWrite(RELAY, OFF);
      brennerstat = 0;
      
      
      if(digitalRead(TASTER)==HIGH){
        newstate = heiz_63;
        ausgabe(heiz_63,temp);
        while(digitalRead(TASTER)){}
      }
      else{
        newstate = einmeisch;
      }
      break;

    case heiz_63:

      ausgabe(heiz_63,temp);
      digitalWrite(RELAY, ON); 
      brennerstat = 1;
      
      if (temp < ZWEITETEMP){
        newstate = heiz_63;
        if (digitalRead(TASTER)){
            newstate = rast_45;
            ausgabe(rast_45,temp);
            while(digitalRead(TASTER)){};
          }
      }
      else{
        newstate = rast_45;
      }
      break;

    case(rast_45):

      ausgabe(rast_45,temp);
      digitalWrite(RELAY, OFF);
      brennerstat = 0;
      
      if( timeold == 0){
        timeold = millis();
        timenew = millis();
        newstate = rast_45;
      }
      else if ( (timenew - timeold) < ERSTERAST){
        newstate = rast_45;
        if (digitalRead(TASTER)){
            newstate = heiz_66;
            ausgabe(heiz_66,temp);
            while(digitalRead(TASTER)){}
            timeold = 0;
            timenew = 0;
          }
        timenew = millis();  
      }
      else{
        newstate= heiz_66;
        timeold = 0;
        timenew = 0;
      }
      break;

   case heiz_66:

      ausgabe(heiz_66,temp);
      digitalWrite(RELAY, ON);
      brennerstat = 1;
    
      if (temp < DRITTETEMP){
        newstate = heiz_66;
        if (digitalRead(TASTER)){
            newstate = rast_10;
            ausgabe(rast_10,temp);
            while(digitalRead(TASTER)){}
          }
      }
      else{
        newstate = rast_10;  
      }
      break;

   case(rast_10):

      ausgabe(rast_10,temp);
      digitalWrite(RELAY, OFF);
      brennerstat = 0;
      
      if( timeold == 0){
        timeold = millis();
        timenew = millis();
        newstate = rast_10;
      }
      else if ( (timenew - timeold) < ZWEITERAST){
        newstate = rast_10;
        if (digitalRead(TASTER)){
            newstate = heiz_72;
            ausgabe(heiz_72,temp);
            while(digitalRead(TASTER)){};
            timeold = 0;
            timenew = 0;
          }
        timenew = millis();  
      }
      else{
        newstate= heiz_72;
        timeold = 0;
        timenew = 0;
      }
      break;

   case heiz_72:
   
      ausgabe(heiz_72,temp);
      digitalWrite(RELAY, ON);
      brennerstat = 1;
      
      if (temp < VIERTETEMP){
        newstate = heiz_72;
        if (digitalRead(TASTER)){
            newstate = rast_15;
            ausgabe(rast_15,temp);
            while(digitalRead(TASTER)){}
            timeold = 0;
            timenew = 0;
          }
      }
      else{
        newstate = rast_15;
      }
      break;
   case(rast_15):

      ausgabe(rast_15,temp);
      digitalWrite(RELAY, OFF);
      brennerstat = 0;
      
      if( timeold == 0){
        timeold = millis();
        timenew = millis();
        newstate = rast_15;
      }
      else if ( (timenew - timeold) < DRITTERAST){
        newstate = rast_15;
        if (digitalRead(TASTER)){
            newstate = heiz_76;
            ausgabe(heiz_76,temp);
            while(digitalRead(TASTER)){}
          }
        timenew = millis();  
      }
      else{
        newstate= heiz_76;
        timeold = 0;
        timenew = 0;
      }
      break;

   case heiz_76:

      ausgabe(heiz_76,temp);
      digitalWrite(RELAY, ON);
      brennerstat = 1;
      
      if (temp < FUNFTETEMP){
        newstate = heiz_76;
        if (digitalRead(TASTER)){
            newstate = ende;
            ausgabe(ende,temp);
            while(digitalRead(TASTER)){}
          }
      }
      else{
        newstate = ende;
      }
      break;
      
   case ende:

      ausgabe(ende,temp);
      digitalWrite(RELAY, OFF);
      brennerstat = 0;

     if (digitalRead(TASTER)){
            newstate = heiz_60;
            ausgabe(heiz_60,temp);
            while(digitalRead(TASTER)){}
          }
        
  }
  
}
