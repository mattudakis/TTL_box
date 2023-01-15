//--------------------------------Created by Matt Udakis -------------------------------//
//                                                                                      //
// Load this script onto an arduino connected to 2 solenoid valves                      //
// The corresponding matlab script is called reward_delivery.m                          //
// matlab script will enable GUI for connection to arduino                              //
// delivery of reward and also manual open and closing of solenoid valves for set up    //
// Additonal TTL ports are added for integration with Matlab code to trigger experiment //
// contingencies                                                                        //
//--------------------------------------------------------------------------------------//

int solenoid1       = 12;
int solenoid2       = 10;
int TTL_1           = 2;
int TTL_2           = 3;
int TTL_3           = 4;
int TTL_4           = 5;

// TTL_1 output to the inscopix DAQ to signify when optogenetics is delivered.


int openTime1 = 25;
int openTime2 = 25;

String serialReceived;
char State;

bool BreakStatus = false;
boolean receiverState;

void setup() {

  pinMode(solenoid1, OUTPUT);
  pinMode(solenoid2, OUTPUT);
  
  pinMode(TTL_1, OUTPUT);
  pinMode(TTL_2, OUTPUT);
  pinMode(TTL_3, OUTPUT);
  pinMode(TTL_4, OUTPUT);


  Serial.begin(500000); //open serial port and set rate to 9600 baud

}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {

    serialReceived = Serial.readStringUntil('\n');
    //    serialReceived = Serial.parseInt();
    State = serialReceived.charAt(0);
    switch (State) {
      case '1':
        digitalWrite(solenoid1, HIGH);
        delay(openTime1);
        digitalWrite(solenoid1, LOW);
        break;
        
      case '2':
        digitalWrite(solenoid2, HIGH);
        delay(openTime2);
        digitalWrite(solenoid2, LOW);
        break;
        
      case '3':
        digitalWrite(solenoid1, HIGH);
        break;
        
      case '4':
        digitalWrite(solenoid1, LOW);
        break;

      case '5':
        digitalWrite(solenoid2, HIGH);
        break;
        
      case '6':
        digitalWrite(solenoid2, LOW);
        break;


      case '7':
        digitalWrite(TTL_1, HIGH);
        break;
        
      case '8':
        digitalWrite(TTL_1, LOW);
        break;
            
    }
  }
}
