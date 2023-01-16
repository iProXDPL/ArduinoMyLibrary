//Math

//Array Taylor
float My_sqrt(float x){
  float eps=1e-6;
  float ds=1;
  float s=1;
  for(int i=1;i<50;i++){
    ds=-ds*((2*i)*(2*i-1)*x)/(i*i*4);
    s+=ds/(1-(2*i));
    if(abs(ds/s)<eps){
      break;
    }
  }
  return s;
}

float My_exp(float x){
  float eps = 1e-10;
  float ds = 1;
  float s = 1;
  for(int i=1; i<50; i++){
    ds = ds *(x/i);
    s = s + ds;
    if(abs(ds)<eps){
      break;
    }
  }
  return s;
}

float My_sin(float x){
  float eps=1e-4;
  float ds=x;
  float s=x;
  for(int i=2;i<50;i++){
    ds = -ds * x * x / ((2*i-1)*(2*i-2));
    s += ds;
    if(abs(ds/s)<eps){
      break;
    }
  }
  return s;
}

float My_cos(float x){
  float eps=1e-4;
  float ds=1;
  float s=1;
  for(int i=1;i<50;i++){
    ds = -ds *( x * x )/((2*i)*(2*i-1));
    s += ds;
    if(abs(ds/s)<eps){
      break;
    }
  }
  return s;
}

float My_ln(float x){
  float eps=1e-6;
  float ds = x;
  float s = x;
  for(int i = 2; i < 50; i++){
    ds = -ds * x;
    s += ds / i;
    if(abs(ds/s)<eps){
      break;
    }
  }
  return s;
}

//Method Newton-Rawson
float MySqrt(float liczba) {
  float x = liczba / 2;
  int i=0;
  while (abs(x - liczba / x) > 0.000001) {
    x = (x + liczba / x) / 2;
    if (x * x == liczba) {
      break;
    }
    i++;
  }
  return x;
}
float MyLn(float y){
  float x = y,x1;
  int i=0;
  for(;i<50;i++) {
    x1 = x - 1 + (y/exp(x));
    if(abs(x1-x)<1e-6)break;
    x=x1;
  }
  return x;
}

float arcsin(float y){
  float x = y,x1;
  int i=0;
  for(;i<50;i++) {
    x1 = x - (sin(x)/cos(x))+(y/cos(x));
    if(abs(x1-x)<1e-6)break;
    x=x1;
  }
  return x;
}

float arccos(float y){
  float x = y,x1;
  int i=0;
  for(;i<50;i++) {
    x1 = x + (cos(x)/sin(x))-(y/sin(x));
    if(abs(x1-x)<1e-6)break;
    x=x1;
  }
  return x;
}

float arcsinh(float y){
  float x = y,x1;
  int i=0;
  for(;i<50;i++) {
    float l = (exp(x)-exp(-x))/2;
    float m = (exp(x)+exp(-x))/2;
    x1 = x-l/m+y/m;
    if(abs(x1-x)<1e-6)break;
    x=x1;
  }
  return x;
}

float arccosh(float y){
  float x = y,x1;
  int i=0;
  for(;i<50;i++) {
    float l = (exp(x)+exp(-x))/2;
    float m = (exp(x)-exp(-x))/2;
    x1 = x-l/m+y/m;
    if(abs(x1-x)<1e-6)break;
    x=x1;
  }
  return x;
}

//Golden ratio

//Our function
float nfun(float x){
  return x*x-(500*x); 
}

float GoldenMin(int be){
  int i=0;
  const float fi = (sqrt(5)-1.0)/2.0;
  float a=0,b=be;
  float h=b-a;
  float u=b-h*fi;
  float v=a+h*fi;
  float fa=nfun(a);
  float fb=nfun(b);
  float fu=nfun(u);
  float fv=nfun(v);
  float delta = 1e-4;
  for(;i<100;i++){
    if(abs(h)<delta){
    break;
    }
    if(fu>fv){  
    a=u;
    fa=fu;
    u=v;      
    fu=fv;
    h=b-a;
    v=a+h*fi;
    fv=nfun(v);    
    }
    else
    {
      b=v;
      fb=fv;
      v=u;
      fv=fu;
      h=b-a;
      u=b-h*fi;
      fu=nfun(u);
    }
  }
  return (fu<fv)? u:v; 
}

float GoldenMax(int be){
  int i=0;
  const float fi = (sqrt(5)-1.0)/2.0;
  float a=0,b=be;
  float h=b-a;
  float u=b-h*fi;
  float v=a+h*fi;
  float fa=nfun(a);
  float fb=nfun(b);
  float fu=nfun(u);
  float fv=nfun(v);
  float delta = 1e-4;
  for(;i<100;i++){
    if(abs(h)<delta){
    break;
    }
    if(fu<fv){  
    a=u;
    fa=fu;
    u=v;      
    fu=fv;
    h=b-a;
    v=a+h*fi;
    fv=nfun(v);    
    }
    else
    {
      b=v;
      fb=fv;
      v=u;
      fv=fu;
      h=b-a;
      u=b-h*fi;
      fu=nfun(u);
    }
  }
  return (fu<fv)? u:v; 
}

//Finding zeros method
//Our function
float fun(float x, float y) {
  return (x * x - y);
}
//Derivative function
float pfun(float x, float y) {
  return 2 * x;
}

//Root-finding methods
float Bisection(float y) {
  float a = 0, b = 32, c;
  float fa = fun(a, y), fb = fun(b, y), fc;
  float delta = 1e-8, ep;

  if (fa == 0) {
    c = a;
  } else if (fb == 0) {
    c = b;
  } else {
    for (int i = 0; i < 50; i++) {
      c = 0.5 * (a + b);
      //Serial.println("c w forze");
      // Serial.println(c);
      fc = fun(c, y);
      ep = abs(b - a);
      if (ep < delta) {
        Serial.print("Bisekcja iteracje ");
        Serial.println(i);
        break;
      }
      if (fb * fc < 0) {
        a = c;
        fa = fc;
      } else {
        b = c;
        fb = fc;
      }
    }
  }
  return c;
}

float Falsi(float y) {
  float a = 0, b = 32, c;
  float fa = fun(a, y), fb = fun(b, y), fc;
  float delta = 1e-8, ep;
  if (fa == 0) {
    c = a;
  } else if (fb == 0) {
    c = b;
  } else {
    for (int i = 0; i < 50; i++) {
      c = b - (b - a) * fb / (fb - fa);
      //Serial.println("c w forze");
      // Serial.println(c);
      fc = fun(c, y);
      ep = min(abs(a - c), abs(b - c));
      if (ep < delta) {
        Serial.print("Falsi iteracje ");
        Serial.println(i);
        break;
      }
      if (fb * fc < 0) {
        a = c, fa = fc;
      } else {
        b = c, fb = fc;
      }
    }
  }
  return c;
}

float Newton(float y) {
  float x = 128, x1, f, pf;
  float delta = 1e-8, ep, ksi;

  for (int i = 0; i < 40; i++) {
    f = fun(x, y);
    pf = pfun(x, y);
    x1 = x - f / pf;
    ep = abs(x1 - x);
    ksi = ep / abs(x1);
    if (ep < delta || ksi < delta) {
      Serial.print("Newton iteracje ");
      Serial.println(i);
      break;
    }
    x = x1;
  }
  return x1;
}

float Secants(float y) {
  if (y == 0) {
    return 0;
  } 
  else {
    float x = 128, x1, f, pf;
    float delta = 1e-9, ep, ksi;
    float x0;
    float f0 = fun(x0, f);

    for (int i = 0; i < 50; i++) {
      f = fun(x, y);
      pf = (f - f0) / (x - x0);
      x1 = x - f / pf;
      ep = abs(x1 - x);
      ksi = x0 + delta;
      if (ep < delta || ksi < delta) {
        Serial.print("Siecznych iteracje ");
        Serial.println(i);
        break;
      }
      x0 = x;
      f0 = f;
      x = x1;
    }
    return x;
  }
}
