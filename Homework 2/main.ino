#define pressbutton 2

const int led1 = 8;
char number;
int result;
int keepgoin = 1;
void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(30000);
  pinMode(pressbutton, INPUT);
  pinMode(led1, OUTPUT);
}

void loop()
{

  while (Serial.available() == 1)
  {
    char userin = (char)Serial.read(); // receiving the data from the serial port

    switch (userin)
    {

    case '5':
      int pressnum;
      pressnum = 1;
      while (keepgoin == 1)
      {
        int buttonstate = digitalRead(pressbutton);
        if (buttonstate == 1)
        {

          Serial.print("pressed:");
          Serial.println(pressnum); // counting how many times button is pressed
          pressnum++;
        }
        delay(200);

        char again = (char)Serial.read();

        if (again == '2')
          keepgoin = 0;
      }
      break;  // checking the options
    case '1': // led on
      digitalWrite(led1, HIGH);
      break;

    case '2': // led of5

      digitalWrite(led1, LOW);
      break;

    case '3': // flash 3 times
      for (int i = 0; i < 3; i++)
      {
        digitalWrite(led1, HIGH);
        delay(300);
        digitalWrite(led1, LOW);
        delay(300);
      }
      break;

    case '4': // square of number
      int go = 1, number1 = 0;
      while (go == 1)
      {

        delay(200);

        number = (char)Serial.read();
        number1 = number - '0';
        // Serial.println(number);
        // Serial.println(number1);

        if (number1 > 0)
        {
          go = 0;
          int square = (number1 * number1);
          Serial.println(square);
          delay(100);
        }
      }
      Serial.println(" ");

      break;
    }
  }
}
