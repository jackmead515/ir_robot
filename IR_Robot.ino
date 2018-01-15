#include <IRremote.h>
#include <Servo.h>

int RECV_PIN = 5;
Servo ServoL;
Servo ServoR;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  delay(100);
  irrecv.enableIRIn();
  delay(100);

}
void loop() {
  if(irrecv.decode(&results)){
    //if(results.value > 80000 && results.value < 4000000000){ // black remote
    if(results.value < 600000000 && results.value < 4000000000 && results.value > 500000000){ // silver remote
      if(results.value == 551494365){
          //Stop
          ServoL.detach(); ServoR.detach();
          delay(10);
      }else if(results.value == 551485695){
          //Forward
          ServoL.attach(8); ServoR.attach(9);
          ServoL.write(180); ServoR.write(0);
          delay(10);
      }else if(results.value == 551518335){
          //Backwards
          ServoL.attach(8); ServoR.attach(9); 
          ServoL.write(0); ServoR.write(180);
          delay(10);    
      }else if(results.value == 551534655){
          //Left
          ServoL.attach(8); ServoR.attach(9);
          ServoL.write(0); ServoR.write(0);
          delay(10); 
      }else if(results.value == 551502015){
          //Right
          ServoL.attach(8); ServoR.attach(9);
          ServoL.write(180); ServoR.write(180);
          delay(10); 
      }
    }
      irrecv.resume();
  }
  delay(10);
}

