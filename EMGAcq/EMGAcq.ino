// it might be as simple as:

// Arduino pin numbers
const int EMG1 = 0; // analog pin connected to EMG1 output
const int EMG2 = 1; // analog pin connected to EMG2 output

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("EMG1: ");
  Serial.print(analogRead(EMG1));
  Serial.print("\n");
  Serial.print("EMG2: ");
  Serial.println(analogRead(EMG2));
  Serial.print("\n\n");
  delay(1000);
}

/* if not, try something more like this:
const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

unsigned long time;
float frequency;

void setup()
{
   Serial.begin(9600);
   Serial.println("Collect data from EMG 1 and EMG 2, separated with a comma and a newline");  
   Serial.println("Ex. 5,4.8\n");
}

void loop()
{
   recvWithEndMarker();
   if (newData == true)
   {
      parseData() ;
      showParsedData();
   }
}

void recvWithEndMarker()
{
   static byte ndx = 0;
   char endMarker = '\n';
   char rc;

   while (Serial.available() > 0 && newData == false)
   {
      rc = Serial.read();

      if (rc != endMarker)
      {
         receivedChars[ndx] = rc;
         ndx++;
         if (ndx >= numChars)
         {
            ndx = numChars - 1;
         }
      }
      else
      {
         receivedChars[ndx] = '\0'; // terminate the string
         ndx = 0;
         newData = true;
      }
   }
}

void parseData()        // split the data into its parts
{

   char * strtokIndx; // this is used by strtok() as an index

   strtokIndx = strtok(receivedChars, ",");     // get the first part - the string
   time = atoi(strtokIndx); // copy it to messageFromPC

   strtokIndx = strtok(NULL, ",");
   frequency = atof(strtokIndx);     // convert this part to a float
}

//============

void showParsedData()
{
   Serial.print("Time ");
   Serial.print(time);
   Serial.print("   Frequency ");
   Serial.println(frequency);
   newData = false;
}
*/
