  /* 02-21-22
  Daniellle Adan's C Robot Simulator Self-Made Map, Mission.
  Feel free to use the map as your basic color-sorting map!
  Also feel free to use my code as your reference!*/
  
    int pa0,pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,LineColorValue; // analog channels, sensors
    int countCrosslines, //Crossline Interaction's Counter
        ballSortedCounter; //Sorted Ball Counter
    int errorTypeIdentifier; //Expected Error Identifier -> Error Codes
    string whichBallIdentifier; //Identify how many ball or which ball was already executed with keep_up()
void setup()  
{ 
  //Null
}
void loop(){
  //loopimg it all
   robotMotorActivity(); //Main Activity
   crossLineCounterActivity(); //2nd Main Activity
   keepObject(); //Supporting Activity or a void for a specific task
}

void robotMotorActivity(){
  // Main Activity : powers the robot's motors and identify which motor to use
    pa0=analog(0);    pa1=analog(1);    pa2=analog(2);
    pa3=analog(3);    pa4=analog(4);    pa5=analog(5);
    pa6=analog(6);    pa7=analog(7);    //declaring the 7 main sensors
    LineColorValue = 512;  //The value of the line that'll be traced
  
 if (pa0 > LineColorValue) //If the left sensor detects the line's value
  {sl(100);} // - slide left
  else if (pa4 > LineColorValue) //If the right sensor detects the line's value
  {sr(100);} // - slide right
  else
  {fd(1000);} // catch : just move forward
  
}

void crossLineCounterActivity(){
  //2nd Main Activity
    //declaring the 8 main sensors
    pa0=analog(0);    pa1=analog(1);    pa2=analog(2);
    pa3=analog(3);    pa4=analog(4);    pa5=analog(5);
    pa6=analog(6);    pa7=analog(7);    pa8=analog(8);
   LineColorValue = 512; //The value of the line that'll be traced
if(pa0 > LineColorValue && pa4 > LineColorValue){
  //If both sensors detects the line's value
    countCrosslines++; //crossline counter will add 1
    //displays infos on the LCD
    lcd("ball_sorted:%d,crosslines:%d",ballSortedCounter,countCrosslines); 
switch(countCrosslines){ 
  //crossline's interactions and functions to those interactions
    case 2:
    fd(1000);
    countCrosslines = 2;
    sleep(2300);
break;

    case 3:
     tl(100);
     sleep(890);
break;

  case 4:
   fd(100);
   sleep(370);
   sr(100);
   sleep(710);
break;

 case 5:
   tl(100);
   sleep(890);
break;

  case 6:
  fd(100);
  sleep(340);
  sr(100);
  sleep(720);
break;

  case 7: //First ball has sorted
  if(pa8>10){
  fd(100);
  sleep(50);
  keep_down();
  ballSortedCounter = 1;
  beep();
  sl(100);
  sleep(1430);
  fd(100);
  }else{
    errorDetectorActivity(2);
  }
break;

  case 8:
  tl(100);
  sleep(750);
break;

   case 9:
   fd(100);
   sleep(370);
   sl(100);
   sleep(850);
break;

   case 10:
   fd(100);
   sleep(120);
break;

  case 11:
  fd(100);
  sleep(430);
  sl(100);
  sleep(690);
  break;

  case 12:
   fd(100);
   sleep(170);
break;
   
  case 13: //Second Ball has sorted
   fd(100);
   sleep(50);
   keep_down();
   ballSortedCounter = 2;
   beep();
   sl(100);
   sleep(1470);
   fd(100);
break;

  case 14:
   fd(100);
   sleep(170);
break;
    
  case 15:
  fd(100);
  sleep(1110);
break;
  
  case 16:
  sl(100);
  sleep(1420);
  fd(100);
break;

  case 17:
  fd(100);
  sleep(170);
break;
  
  case 18:
  fd(100);
  sleep(430);
  sl(100);
  sleep(790);
break;
  
  case 19: //Third Ball has sorted
   fd(100);
   sleep(50);
   keep_down();
   ballSortedCounter = 3;
   beep();
   sl(100);
   sleep(1410);
   fd(100);
break;
   
   case 20:
   fd(100);
   sleep(430);
   sr(100);
   sleep(690);
break;

   case 21:
   fd(100);
   sleep(420);
   sr(100);
   sleep(790);
break;
   
   case 22:
   fd(100);
   sleep(420);
   sl(100);
   sleep(720);
break;
   
   case 23:
      tl(100);
     sleep(890); 
break;

   case 24: //Last activity
   lcd("Mission Completed!");
   fd(100);
   sleep(900);
   tl(1000);
   sleep(1480);
   bk(170);
   sleep(140);
   system_stop(); //stop the whole robot and its main functions
   beep();
break;

  default: //catch : just forward
   fd(100);
   sleep(170); 
break;
   }
}
}

void keepObject(){
    pa8 = analog(8);

    if(pa8 > 10){
        keep_up();
        fd(30);
        }
}
void errorDetectorActivity(int errorTypeIdentifier){
      //It detects/catches some expected errors & logical errors
      //Some issues have not yet been experienced nor discovered so please let me know!
       lcd("Error Code:00%d",errorTypeIdentifier);
       system_stop();
       beep();
}