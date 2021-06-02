/*
 예제 9.1
 피에조 부저를 이용한 소리 출력
*/

int buzzerPin = 9;
int songLength = 16;



// 노래의 빠르기를 설정한다.
int tempo = 200;

const int inputPin1 = 2;
const int inputPin2 = 3;
const int inputPin3 = 4;

void setup() 
{
  // 부저핀을 출력으로 설정한다
  pinMode(buzzerPin, OUTPUT);

  pinMode(inputPin1,INPUT_PULLUP);
  pinMode(inputPin2,INPUT_PULLUP);
  pinMode(inputPin3,INPUT_PULLUP);
}


void loop() 
{
  int swinput1 = digitalRead(inputPin1);
  int swinput2 = digitalRead(inputPin2);
  int swinput3 = digitalRead(inputPin3);
  
  
  // 부저 출력 시간에 사용할 변수 설정
  int duration;
  
  // 노래 길이 데이터 갯수만큼 반복한다
 

    if(swinput1 == LOW){
      tone(buzzerPin,262,100);
    }
    
    else if(swinput2 == LOW){
      tone(buzzerPin,330,100);
    }
    
    if(swinput3 == LOW){
      tone(buzzerPin,392,100);
    }

  }
  

int frequency(char note){
  // 노래 데이터를 주파수 값으로 변경하기 위한 함수

  int i;
  // 음계의 갯수 설정
  int notes = 8;

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  // 노래 데이터를 주파수 값으로 변경하기 위해 반복하여 비교한다  
  for (i = 0; i < notes; i++){
    if (names[i] == note){
      // 맞는 값을 찾았을 경우 이 값을 회신한다
      return(frequencies[i]);
    };
  };
  // 앞의 for문에서 맞는 값을 못찾았을 경우 0을 회신한다
  return(0);
}
