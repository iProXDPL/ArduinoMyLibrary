
bool Buffor(int x,int treshold1){
  const int treshold=treshold1;
  static bool state = LOW;
  state = (x<treshold)? LOW:HIGH;
  return state;
}
bool Bufferschmitt(int x,int tresholdD,int tresholdU){
  const int tresholdDown=tresholdD;
  const int tresholdUP=tresholdU;
  static bool state = LOW;
  if(state == LOW){
   state = (x<tresholdUP)? LOW:HIGH;
  }
  else{
    state = (x<tresholdDown)? LOW:HIGH;
  }
  return state;
}
