#include <math.h>
#include <LiquidCrystal.h>
 
double const A= -1.96300569740801; 
double const B= 9.08743780492067;
int const SENSOR_PIN= A0;
int reglux;
int fadeAmount;
float const pente= 0.450; 
int led9;
int led10;
int led11;
const int rs = 13, en = 12, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


double resistance;
double luxSol;

double res_lux(double a, double b, double res);
double dig_res();


void setup() {
  Serial.begin(9600);
  for (int a =9; a <= 11; a++) {
     pinMode (a, OUTPUT);  
  }
  pinMode(9, OUTPUT);
  lcd.begin(16, 2);
  
}

void loop() {
    resistance = dig_res();
    luxSol = res_lux(A,B,resistance);

    if (luxSol < 500)
    {
      reglux=500-luxSol;        //reg etant la valeur a ajuster en lux
      fadeAmount=pente*reglux+0.537;   //calcule le nombre de volt a envoyer en fonction du nombre de lux
    }
    else 
    { 
       fadeAmount=0;
       reglux = 0;
    }
        for (int b=9; b <= 11; b++) 
        {
           analogWrite(b, fadeAmount);
        }
    
    Serial.print("Luminosité = ");
    Serial.println(luxSol);
    Serial.print("fadeAmount =");
    Serial.println(fadeAmount);

    lcd.clear();
    lcd.print("Lux = ");
    lcd.print(luxSol);
    lcd.setCursor(0,2);
    lcd.print("Led = ");
    lcd.print(fadeAmount);
    
    delay(10);
  
}
                                             
double dig_res() //a expliquer 
{
    double rawData = analogRead(SENSOR_PIN);
    double resVolt = rawData / 1023 * 5;
    double ldrVolt = 5 - resVolt;
    double ldrRes = ldrVolt/resVolt * 100000;
    return ldrRes;
}

double res_lux(double a, double b, double res)
{
    double membre1 = pow(res, a);
    double membre2 = pow(10, b);
    double luxP = membre1 * membre2;
    double luxS= luxP*0.206+44; //Mouais 
    return luxS;
}
