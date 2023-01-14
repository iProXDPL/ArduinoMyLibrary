//Buttons
//digitalWrite(PIN,Function(Button PIN));
bool onHold(int pin){
  return digitalRead(pin);
}

bool onClick(int pin){
  bool button;
  static bool state = LOW;
  static bool btnPre=!digitalRead(pin);
  button=digitalRead(pin);
  if(btnPre==LOW&&button==HIGH){
    state=!state;
  }
  btnPre=button;
  return state;
}

bool onDoubleClick(int pin){
  bool button;
  static bool state = LOW;
  static bool oneClick = false;
  static int counter = 0;
  static int counterMax = 10;
  static bool btnPre=digitalRead(pin);
  button=digitalRead(pin);
  if(btnPre==LOW&&button==HIGH){
    if(!oneClick){
    oneClick=true;
    }
    else
    {
    state=!state;
    oneClick=false;
    counter=0;
    }
  }
  if(oneClick)counter++;
  if(counter>counterMax){
    oneClick=false;
    counter=0;
  }
  btnPre=button;
  return state;
}

bool onLongHold(int pin){
  bool button;
  static bool state = LOW;
  static bool LongHold = false;
  static int counter = 0;
  static int counterMax = 6;
  button=digitalRead(pin);
  if(button==LOW){
    counter=0;
    LongHold=0;
  }
  else
  {
    if(LongHold==false)counter++;
    if(counter>counterMax){
      state=!state;
      LongHold=false;
      counter=0;
    }
  }
  return state;
}

//analogWrite(PIN,Function(Button PIN));
int onPressHold(int pin){
  bool button;
  static int state = 0;
  static bool dir = LOW;
  static bool btnPre=digitalRead(pin);
  button=digitalRead(pin);
  if(btnPre==LOW&&button==HIGH)dir=!dir;
  if(button){
    if(dir){
      state++;
    }
    else
    {
      state--;
    }
  }
  state=constrain(state,0,255);
  btnPre=button;
  return state;
}
int TripleClick(int pin){
  bool button;
  static int state = 0;
  static bool oneClick = false;
  static bool ddClick = false;
  static bool tripClick = false;
  static int counter = 0;
  static int counterMax = 10;
  static bool btnPre = !digitalRead(pin);
  static bool btnPrePre = btnPre;
  
  button=!digitalRead(pin);
  
  if(button==HIGH){
    if(btnPre==LOW && btnPrePre==LOW && !oneClick){
      if(tripClick == false){
          Serial.println("One Click");
          oneClick = true;
          state=1;
        } else if(tripClick == true){
          state=0;
          tripClick=false;
       }
    }
    else if(btnPre=HIGH&&btnPrePre==LOW&&!ddClick){
      Serial.println("DDClick");
      ddClick=true;
      state=2;
    }
    else if(oneClick==true&&ddClick==true&&tripClick==false)
    {
      Serial.println("TripleClick");
      state=3;
      tripClick=true;
    }
  }
  btnPre=button;
  btnPrePre=btnPre;
  if(oneClick||ddClick)counter++;
  if(counter>counterMax){
    Serial.println("Clear");
    oneClick=false;
    ddClick=false;
    counter=0;
    if(state==1||state==2){
      state=0;
    }
  }
  return state;
}
int LongLongHold(int pin,int time){
  bool button;
  static int state = 0;
  static int counter = 0;
  static int counterMax = time;
  static bool LongHold = false;
  static bool LongLongHold = false;
  button=!digitalRead(pin);
  if(button==LOW){
    counter=0;
    state = 0;
    LongHold = false;
    LongLongHold = false;
  }
  else
  {
    counter++;
    Serial.println(counter);
    if(counter>=counterMax&&counter<=counterMax*2&&counter<=counterMax*3){
      state = 1;
    }
    else if(counter>=counterMax*2&&counter<=counterMax*3){
      state = 2;
    }
    else if(counter>=counterMax*3){
      state = 3;
    }
  }
  return state;
}
