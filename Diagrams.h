//Convert a value from one range into a proportional value of another range.
//EquationFor*(Variable Changing,from min,from max,to min,to max)
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
//Working like Derivative
//Derivative*(Variable Changing)
float Derivative1Degree(float yi){
  float h = 1.0;
  float a;
  static float yi1 = 0;
  a = (yi-yi1)*h;
  yi1 = yi;
  a=abs(a);
  return a;
}

float Derivative2Degree(float yi){
  float h = 1;
  float a;
  static float yi1 = 0;
  static float yi2 = 0;
  a = (3*yi - 4*yi1 + yi2) / (2.0 * h);
  yi2 = yi1;
  yi1 = yi;
  a=abs(a);
  return a;
}
 
float Derivative3Degree(float yi){
  float h = 1;
  float a;
  static float yi1 = 0;
  static float yi2 = 0;
  static float yi3 = 0;
  a = (((11*yi)-(18*yi1)+(9*yi2)-(2*yi3))/6*h);
  yi3 = yi2;
  yi2 = yi1;
  yi1 = yi;
  a=abs(a);
  return a;
}

float Derivative1Degree2Row(float yi){
  float h = 1.0;
  float a;
  static float yi1 = 0;
  static float yi2 = 0;
  a = (yi - 2*yi1  + yi2) / sq(h);
  yi2 = yi1;
  yi1 = yi;
  a=abs(a);
  return a;
}

float Derivative2Degree2Row(float yi){
  float h = 1;
  float a;
  static float yi1 = 0;
  static float yi2 = 0;
  static float yi3 = 0;
  a = (2*yi - 5*yi1 + 4*yi2 -yi3) / sq(h);
  yi3 = yi2;
  yi2 = yi1;
  yi1 = yi;
  a=abs(a);
  return a;
}
//Working like Integral
//Integral*(Variable Changing)
float Integral1Degree(float yi){
  float h = 0.01;
  static float s;
  static float yi1 = 0;
  s += (yi+yi1) * h / 2.0;
  yi1 = yi;
  return s;
}

float Integral2Degree(float yi){
  float h = 0.01;
  static float s;
  static float yi1 = 0;
  static float yi2 = 0;
  s += ((5*yi + 8*yi1 - yi2)*h) / 12.0;
  yi2 = yi1;
  yi1 = yi;
  return s;
}

float Integral3Degree(float yi){
  float h = 0.01;
  static float s;
  static float yi1 = 0;
  static float yi2 = 0;
  static float yi3 = 0;
  s += ((9*yi + 19*yi1 - 5*yi2 + yi3)*h) / 24.0;
  yi3 = yi2;
  yi2 = yi1;
  yi1 = yi;
  return s;
}
