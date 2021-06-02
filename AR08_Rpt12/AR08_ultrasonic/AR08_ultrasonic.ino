const char trigPin = 13;
const char echoPin = 12;
const int ledA   =  2;
const int ledB   =  3;
const int ledC   =  4;

// 펄스 폭과 거리 변수 설정  

int pulseWidth;
int distance;
int distanceOld;

  

void setup() {

  // 시리얼 통신 설정

  Serial.begin (9600);

 

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(trigPin,LOW);
  pinMode(ledA , OUTPUT);
  pinMode(ledB , OUTPUT);
  pinMode(ledC , OUTPUT);

}

 

void loop(){

  // 10us의 트리거 신호를 HC-SR04로 내보낸다.

  digitalWrite(trigPin,HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

 

  // Echo 펄스 폭을 측정하여 pulseWidth 변수에 저장한다.  

 pulseWidth = pulseIn(echoPin, HIGH);
distance = pulseWidth / 58; 

 

 if(distance <= 200 || distance >= 2){  
 if(distance<=30){

       digitalWrite(ledA, HIGH);
       digitalWrite(ledB, LOW);
       digitalWrite(ledC, LOW);   

    }

    if(distance>30 || distance<=60){

       digitalWrite(ledA, LOW);
       digitalWrite(ledB, HIGH);
       digitalWrite(ledC, LOW);

    }

    if(distance>60){

       digitalWrite(ledA, LOW);
       digitalWrite(ledB, LOW);
       digitalWrite(ledC, HIGH);

    }

    if(distance !=distanceOld){

      Serial.print(distance);
      Serial.println(" cm");

    }

  };

  distanceOld = distance;
  delay(100);

}
