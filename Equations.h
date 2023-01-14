//Convert a value from one range into a proportional value of another range.
//MyMap(Variable Changing,from min,from max,to min,to max)
//Equation of a straight line passing through two points
float EquationFor2Points(float x,float x1,float x2,float y1,float y2){
  //The same function is map in Arduino IDE
  float y = (((y2-y1)*x)/(x2-x1))-(((y1*x2)-(y2*x1))/(x2-x1));
  return y;
}

//The same for 3 Points
float EquationFor2Points(float x,float x1,float y1,float x2,float y2,float x3,float y3){
  float L1=((x-x2)*(x-x3))/((x1-x2)*(x1-x3));
  float L2=((x-x1)*(x-x3))/((x2-x1)*(x2-x3));
  float L3=((x-x1)*(x-x2))/((x3-x1)*(x3-x2));
  float y = (L1*y1)+(L2*y2)+(L3*y3);
  y=constrain(y,0,255);
  return y;
}
float EquationFor4Points(float x,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){
  float L1=((x-x2)*(x-x3)*(x-x4))/((x1-x2)*(x1-x3)*(x1-x4));
  float L2=((x-x1)*(x-x3)*(x-x4))/((x2-x1)*(x2-x3)*(x2-x4));
  float L3=((x-x1)*(x-x2)*(x-x4))/((x3-x1)*(x3-x2)*(x3-x4));
  float L4=((x-x1)*(x-x2)*(x-x3))/((x4-x1)*(x4-x2)*(x4-x3));
  float y=(L1*y1)+(L2*y2)+(L3*y3)+(L4*y4);
  y=constrain(y,0,255);
  return y;
}
float EquationFor5Points(float x,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float x5,float y5){
  float L1=((x-x2)*(x-x3)*(x-x4)*(x-x5))/((x1-x2)*(x1-x3)*(x1-x4)*(x1-x5));
  float L2=((x-x1)*(x-x3)*(x-x4)*(x-x5))/((x2-x1)*(x2-x3)*(x2-x4)*(x2-x5));
  float L3=((x-x1)*(x-x2)*(x-x4)*(x-x5))/((x3-x1)*(x3-x2)*(x3-x4)*(x3-x5));
  float L4=((x-x1)*(x-x2)*(x-x3)*(x-x5))/((x4-x1)*(x4-x2)*(x4-x3)*(x4-x5));
  float L5=((x-x1)*(x-x2)*(x-x3)*(x-x4))/((x5-x1)*(x5-x2)*(x5-x3)*(x5-x4));
  float y=(L1*y1)+(L2*y2)+(L3*y3)+(L4*y4)+(L5*y5);
  y=constrain(y,0,255);
  return y;
}
