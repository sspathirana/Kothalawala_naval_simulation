String readString;
char Data[10];


char command[10];
void readSerial(){
  if(Serial.available())
  {
   // delay(3);
    readString = Serial.readStringUntil('\n');
  }
  if (readString.length() > 0) 
  {
    readString.toCharArray(Data,10);
    
    if(Data[0] == 'D' && Data[1] == 'G' && Data[2] == 'E' && Data[3] == 'N'){
        Data[0] ='e';
        display_UP[4] = 0.1; AL_en[4] = 4;
        delay(1000);
    }
    else if(Data[0] == 'D' && Data[1] == 'G' && Data[2] == 'O' && Data[3] == 'F'){
        Data[0] ='e';
        display_UP[4] = 0; AL_en[4] = 0;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'C' && Data[2] == '1' && Data[3] == 'N'){
        Data[0] ='e';
        display_UP[5] = 0.1; AL_en[5] = 4;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'C' && Data[2] == '1' && Data[3] == 'O' && Data[4] == 'F'){
        Data[0] ='e';
        display_UP[5] = 0; AL_en[5] = 0;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'C' && Data[2] == '2' && Data[3] == 'N'){
        Data[0] ='e';
        display_UP[6] = 0.1; AL_en[6] = 4;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'C' && Data[2] == '2' && Data[3] == 'O' && Data[4] == 'F'){
        Data[0] ='e';
        display_UP[6] = 0; AL_en[6] = 0;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'B' && Data[2] == 'S' && Data[3] == 'V'){
        displayABSV();
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'B' && Data[2] == 'O' && Data[3] == 'F'){
        Data[0] ='e';
        display_UP[3] = 0; AL_en[3] = 0;
        delay(1000);
    }
  }
  readString = "";

}