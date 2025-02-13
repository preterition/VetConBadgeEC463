#include <Arduino.h>
#include <stdlib.h>
#include <string.h>
#include <Button.h>
#include <HardwareSerial.h>
#include <LiquidCrystal.h>
#define NAMESET 1
#define NAMELEN 128

/*

TX: 2.5
RX: 2.6

PUSH BUTTONS: 2.3, 2.7

LIQUID CRYSTAL: 10,  9,   7,   6,   5,   17
                1.2, 1.3, 2.4, 1.7, 1.6, 3.2

*/

// Define LiquidCrystal Object
LiquidCrystal lcd = LiquidCrystal(10, 9, 7, 6, 5, 17);

// Define PushButtons using Button.h
Button push2(PUSH2); // HARD RESET

// Define Flags to place in FRAM
int startFlag PLACE_IN_FRAM;
int secretFlag PLACE_IN_FRAM;
int nameToggle PLACE_IN_FRAM;
int secretFlag2 PLACE_IN_FRAM;
int secretFlag3 PLACE_IN_FRAM;
int secretFlag4 PLACE_IN_FRAM;
int wrongFlag PLACE_IN_FRAM;

char name[NAMELEN] PLACE_IN_FRAM;
char secret_word[NAMELEN] PLACE_IN_FRAM;

// Custom GLYPHS for 16x2 LCD go HERE:

byte Skull[8] = {
    0b00000,
    0b01110,
    0b10101,
    0b11011,
    0b01110,
    0b01110,
    0b00000,
    0b00000};

// Function Prototypes

void clearStr();

void setName();

void mainMenu();

void setStr();

void displayName();

void secret();

void resetBadge();

void secretCode2();

void secretCode();

void secretCode3();

void wipeBoard();

void bluetooth();

void bleName();

void blePassword();

void ledMenu();

void ledWave();

void ledBlink();

void ledAlt();

void interrupt();

void writeString(String s);

void clearStr(char *str);

void setStr(String x, char *str);

void lcdCheck();

void setup()
{
  // put your setup code here, to run once:

  // Set Up Push Buttons and LCD
  push2.begin();

  lcd.begin(16, 2);

  // Set Up Serial Parameters, BT Serial, and timeouts
  Serial.begin(9600);
  Serial1.begin(9600);
  //Serial1.begin(38400);
  Serial.setTimeout(2000);

  // Set Up Pins for LEDs 1, 2 & 3 (in-order)
  pinMode(P3_1, OUTPUT);
  pinMode(P2_1, OUTPUT);
  pinMode(P2_0, OUTPUT);

  // Set Up Custom Characters
  lcd.createChar(0, Skull);
}

// String Set/Clear/Write functions for BT Serial/Serial Comms

void clearStr(char *str)
{
  for (int i = 0; i < NAMELEN; i++)
    str[i] = '\0';
}

void setStr(String x, char *str)
{
  char new_name[NAMELEN];
  x.toCharArray(new_name, NAMELEN);
  for (int i = 0; i < NAMELEN; i++)
    str[i] = new_name[i];
}

void writeString(String stringData)
{ // Used to serially push out a String with Serial.write()

  for (int i = 0; i < 15; i++)
  {
    Serial1.write(stringData[i]); // Push each char 1 by 1 on each loop pass
  }
}

// Function to check if enabled secret prompts LED on/off

void ledCheck()
{
  if (secretFlag2 == 1)
  {
    digitalWrite(P3_1, secretFlag2);
  }
  else if (secretFlag2 == 0)
  {
    digitalWrite(P3_1, secretFlag2);
  }
  if (secretFlag3 == 1)
  {
    digitalWrite(P2_1, secretFlag3);
  }
  else if (secretFlag3 == 0)
  {
    digitalWrite(P2_1, secretFlag3);
  }
  if (secretFlag4 == 1)
  {
    digitalWrite(P2_0, secretFlag4);
  }
  else if (secretFlag4 == 0)
  {
    digitalWrite(P2_0, secretFlag4);
  }
}

// Check and 'rebase' the lcd

void lcdCheck()
{
  lcd.clear();
  if (nameToggle == NAMESET)
  {
    lcd.setCursor(2, 0);
    lcd.write(byte(0));
    lcd.print("VETCON  30");
    lcd.write(byte(0));
    lcd.setCursor(0, 1);
    lcd.print(name);
  }
  else
  {
    lcd.setCursor(2, 0);
    lcd.write(byte(0));
    lcd.print("WELCOME TO");
    lcd.write(byte(0));
    lcd.setCursor(2, 1);
    lcd.write(byte(0));
    lcd.print("VETCON  30");
    lcd.write(byte(0));
  }
}

// Main Menu selection function

void mainMenu()
{

statement:
  Serial.print("************************\n");
  Serial.print("*|        MENU        |*\n");
  Serial.print("*|                    |*\n");
  Serial.print("*| 1: Set Name Tag    |*\n");
  Serial.print("*| 2: Display Name Tag|*\n");
  Serial.print("*| 3: Game Link       |*\n");

  Serial.print("*| 4: Game Link 2     |*\n");
  if (secretFlag == 1)
  {
    Serial.print("*| 5: Secret Token    |*\n");
  }
  if (secretFlag == 1 && secretFlag2 == 1)
  {
    Serial.print("*| 6: Secret Token 2  |*\n");
  }
  if (secretFlag == 1 && secretFlag2 == 1 && secretFlag3 == 1)
  {
    Serial.print("*| 7: Secret Token 3  |*\n");
  }
  Serial.print("*| 8: Start Bluetooth |*\n");
  if (secretFlag == 1 && secretFlag2 == 1 && secretFlag3 == 1 && secretFlag4 == 1)
  {
    Serial.print("*| 9: LED CNTRL Menu  |*\n");
  }
  Serial.print("*| 0: Reset Badge     |*\n");
  Serial.print("*|                    |*\n");
  Serial.print("************************\n");

  Serial.print("Please enter input\n");

  while (Serial.available() == 0)
  {
    // THIS BLOCK STAYS EMPTY!
  }
  char inputData = (char)Serial.read();
  Serial.print("Input: ");
  Serial.print(inputData);
  Serial.print("\n\n");
  Serial.flush();

  for (;;)
  {
    switch (inputData)
    {
    case '1':
      sleepSeconds(1);
      Serial.print("You Chose to Set your Device Name!\n"); // DeviceID Input
      sleepSeconds(1);
      if (nameToggle == 0)
      {
        Serial.print("Jumping to setName...\n");
        sleepSeconds(1);
        setName();
      }
      else if (nameToggle == NAMESET)
      {
        Serial.print("YOU ALREADY SET YOUR NAME\n");
        Serial.print("Name: ");
        Serial.print(name);
        Serial.print("\n");
        Serial.print("Would you like to change your name?\n");
        sleepSeconds(1);
        Serial.print("PLEASE PRESS '1' FOR YES, '2' FOR NO\n");

        while (Serial.available() == 0)
        {
          // THIS BLOCK STAYS EMPTY!
        }
        char inputData = (char)Serial.read();
        Serial.print("Input: ");
        Serial.print(inputData);
        Serial.print("\n\n");
        if (inputData == '1')
        {
          Serial.print("Jumping to setName...\n");
          sleepSeconds(1);
          setName();
        }
        sleepSeconds(1);
      }
      sleepSeconds(1);
      goto statement;
    case '2':
      sleepSeconds(1);
      Serial.print("You Chose to Display your Device Name!\n"); // DeviceID Input
      sleepSeconds(1);
      Serial.print("Displaying Device Name on Badge\n");
      sleepSeconds(1);
      Serial.print(name);
      Serial.print("\n");
      displayName();
      goto statement;
    case '3':
      sleepSeconds(1);
      Serial.print("You Chose to Play Game 1!\n"); // Game Link
      sleepSeconds(1);
      Serial.print("URL:\n");
      Serial.print("shorturl.at/advFT\n");
      sleepSeconds(1);
      goto statement;
    case '5':
      sleepSeconds(1);
      if (secretFlag == 0)
      {
        Serial.print("Access Denied\n");
        goto statement;
      }
      else
      {
        if (secretFlag2 == 1)
        {
          Serial.print("Secret already unlocked\n");
          goto statement;
        }
        secretCode();
        goto statement;
      }
    case '4':
      sleepSeconds(1);
      Serial.print("You Chose to Play the Game 2!\n"); // Game Link
      sleepSeconds(1);
      Serial.print("URL:\n");
      Serial.print("shorturl.at/lxIL6\n");
      sleepSeconds(1);
      goto statement;
    case '6':
      sleepSeconds(1);
      if (secretFlag == 0 || secretFlag2 == 0)
      {
        Serial.print("Access Denied\n");
        goto statement;
      }
      else
      {
        if (secretFlag3 == 1)
        {
          Serial.print("Secret already unlocked\n");
          goto statement;
        }
        secretCode2();
        goto statement;
      }

    case '7':
      sleepSeconds(1);
      if (secretFlag == 0 || secretFlag2 == 0 || secretFlag3 == 0)
      {
        Serial.print("Access Denied\n");
        goto statement;
      }
      else
      {
        if (secretFlag4 == 1)
        {
          Serial.print("Secret already unlocked\n");
          goto statement;
        }
        secretCode3();
        goto statement;
      }

    case '8':
      sleepSeconds(1);
      Serial.print("Bluetooth Entered\n");
      Serial.print("Exit Bluetooth Menu to Return\n\n\n");
      bluetooth();
      goto statement;
    case '9':
      sleepSeconds(1);
      if (secretFlag == 1 && secretFlag2 == 1 && secretFlag3 == 1 && secretFlag4 == 1)
      {
        Serial.print("Entering the LED Control Menu!\n\n");
        ledMenu();
        sleepSeconds(1);
      }
      else if (secretFlag == 1)
      {
        Serial.print("Secret 1 Already Unlocked\n\n");
        sleepSeconds(1);
      }
      else
      {
        secret();
        sleepSeconds(1);
      }
      goto statement;

    case '0':
      // Set Up Push Buttons

      sleepSeconds(1);
      resetBadge();
      if (startFlag == 1)
      {
        goto statement;
      }
      else
      {
        return;
      }

    default:
      Serial.print("Invalid Statement\n");
      goto statement;
    }
  }
}

// Wireless/BT COMM function

void bluetooth()
{

statement:
  Serial.print("Welcome to Bluetooth\n");
  Serial.print("Type 1 to Start Communication: \n");
  Serial.print("Type 2 to Change to Parent/Child\n");
  Serial.print("Type 0 to Exit: \n");
  while (Serial.available() == 0)
  {
    // THIS BLOCK STAYS EMPTY!
  }
  char inputData = (char)Serial.read();
  Serial.print("You entered ");
  Serial.print(inputData);
  Serial.flush();
  Serial.print("\n\n");
  // char badgePassowrd[] = "AT+PSWD=";
  // strcat(badgePassowrd,inputData.c_str());

  for (;;)
  {
    switch (inputData)
    {
    case '1':
    {
      sleep(100);
      Serial.print("Type to send to other badge\n");
      Serial.print("Type 'exitnowpls' to quit!\n");
      while (Serial.available() == 0)
      {
        // THIS BLOCK STAYS EMPTY!
      }
      String toSend = Serial.readString();
      if (toSend == "exitnowpls")
      {
        Serial.print("Exiting now!\n");
        sleepSeconds(1);
        return;
      }

      // Serial.print("got inside case 1\n");
      Serial.print("Sending Data via Bluetooth...\n");
      writeString(toSend);
      Serial.flush();

      if (Serial1.available())
      {
        // Serial.print("got inside Serial1\n");
        // String incomingData = Serial1.readString();
        String dataIn = Serial1.readString();

        // Serial.print(incomingData);
        Serial.print("Data Received: ");
        Serial.print(dataIn);
        Serial.print("\n");
      }
      break;
    }
    case '2':
    {
      
      delay(100);
      Serial.print("COMMANDS:\n");
      Serial.print("Type: AT+ROLE=0 for child\n");
      Serial.print("Type: AT+ROLE=1 for parent\n\n");
      Serial.print("Type 'exitnowpls' to quit!\n");
      while (Serial.available() == 0)
      {
        // THIS BLOCK STAYS EMPTY!
      }
      String toSend = Serial.readString();
      if (toSend == "exitnowpls")
      {
        Serial.print("Exiting now!\n");
        return;
      }

      Serial.print("Sending Command...\n");
      writeString(toSend);

      if (Serial1.available())
      {
        Serial.print("got inside Serial1\n");
        // String incomingData = Serial1.readString();
        String dataIn = Serial1.readString();

        // Serial.print(incomingData);
        Serial.print("Data Received: ");
        Serial.print(dataIn);
        Serial.print("\n");
      }
      break;
    }
    case '0':
      sleepSeconds(1);
      return;
    default:
      Serial.print("Invalid Menu Item\n");
      goto statement;
    }
  }
}

// Badge Reset, CLEAR FRAM and LCD

void resetBadge()
{
  Serial.print("Reset Badge:\n");
  sleepSeconds(1);
  Serial.print("ARE YOU SURE YOU WANT TO RESET?\n");
  Serial.print("ALL SECRET PROGRESS WILL BE LOST\n\n");
  Serial.print("Please Press & Hold Button 1 for reset\n");
  Serial.print("Otherwise, wait 5 seconds! (after this message)\n");

  sleep(200);
  while (true)
  {
    sleepSeconds(5);
    if (push2.pressed())
    {
      Serial.print("RESETTING.....\n");
      sleepSeconds(3);
      wipeBoard();
      Serial.print("BADGE RESET\n");
      break;
    }
    else
    {
      Serial.print("Badge Reset Aborted...\n");
      break;
    }
  }
}

// Badge Secret Functions

void secret()
{
  Serial.print("Secret Unlocked\n");
  SYSCFG0 = FRWPPW | DFWP;
  secretFlag = 1;
  SYSCFG0 = FRWPPW | PFWP | DFWP;
  return;
}

void secretCode()
{

  char answer[] = "1016";
  Serial.print("Please Enter The Secret Code:\n");
  while (Serial.available() == 0)
  {
    // THIS BLOCK STAYS EMPTY!
  }
  String inputData = Serial.readStringUntil('\n');
  if (inputData == answer)
  {
    Serial.print("CONGRATS! SECRET 1 SOLVED\n");

    SYSCFG0 = FRWPPW | DFWP;
    secretFlag2 = 1;
    SYSCFG0 = FRWPPW | PFWP | DFWP;
    digitalWrite(P3_1, secretFlag2);
  }
  else
  {
    Serial.print("INCORRECT CODE\n");
  }
  return;
}

void secretCode2()
{
  char answer[] = "semperdisco";
  char wrong[] = "3411323115333443242344234424521532244442453454141544431152543131111542453454";
  Serial.print("Please Enter The Secret Code:\n");
  while (Serial.available() == 0)
  {
    // THIS BLOCK STAYS EMPTY!
  }
  String inputData = Serial.readStringUntil('\n');
  if (inputData == answer)
  {
    Serial.print("CONGRATS! SECRET 2 SOLVED\n");

    SYSCFG0 = FRWPPW | DFWP;
    secretFlag3 = 1;
    SYSCFG0 = FRWPPW | PFWP | DFWP;
    digitalWrite(P2_1, secretFlag3);
  }
  else if (inputData == wrong)
  {
    for (int i = 0; i < 50; i++)
    {
      Serial.print("THIS IS NOT A GAME\n");
    }
    SYSCFG0 = FRWPPW | DFWP;
    clearStr(secret_word);
    // setStr(x, secret_word);
    wrongFlag = 1;
    SYSCFG0 = FRWPPW | PFWP | DFWP;
    wipeBoard();
  }
  else
  {
    Serial.print("INCORRECT CODE\n");
  }
  return;
}

void secretCode3()
{
  char answer[] = "ilovevetcon";
  Serial.print("Please Enter the Secret Code:\n");

  while (Serial.available() == 0)
  {
    // THIS BLOCK STAYS EMPTY!
  }
  String inputData = Serial.readStringUntil('\n');
  if (inputData == answer)
  {
    Serial.print("CONGRATS! SECRET 3 SOLVED\n");

    SYSCFG0 = FRWPPW | DFWP;
    secretFlag4 = 1;
    SYSCFG0 = FRWPPW | PFWP | DFWP;
    digitalWrite(P2_0, secretFlag4);
  }
  else
  {
    Serial.print("INCORRECT CODE\n");
  }
  return;
}

// LED Functions

void ledWave()
{
  for (;;)
  {
    lcd.scrollDisplayLeft();
    digitalWrite(P3_1, HIGH); // Turn LED 1 on
    sleep(600);               // wait half a second
    lcd.scrollDisplayLeft();
    digitalWrite(P3_1, LOW);  // Turn LED 1 off
    digitalWrite(P2_1, HIGH); // and repeat for LED 2 to 5
    sleep(600);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_1, LOW);
    digitalWrite(P2_0, HIGH); // and repeat for LED 2 to 5
    sleep(600);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_0, LOW);
    sleep(200);
    if (push2.pressed())
    {
      break;
    }
  }
  return;
}

void ledBlink()
{
  for (;;)
  {
    lcd.scrollDisplayLeft();
    digitalWrite(P3_1, HIGH);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_1, HIGH);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_0, HIGH);
    lcd.scrollDisplayLeft();
    sleep(600);
    lcd.scrollDisplayLeft();
    digitalWrite(P3_1, LOW);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_1, LOW);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_0, LOW);
    lcd.scrollDisplayLeft();
    sleep(400);
    if (push2.pressed())
    {
      break;
    }
  }
  return;
}

void ledAlt()
{
  for (;;)
  {
    lcd.scrollDisplayLeft();
    digitalWrite(P3_1, HIGH);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_1, LOW);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_0, HIGH);
    lcd.scrollDisplayLeft();
    sleep(1500);
    lcd.scrollDisplayLeft();
    digitalWrite(P3_1, LOW);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_1, HIGH);
    lcd.scrollDisplayLeft();
    digitalWrite(P2_0, LOW);
    lcd.scrollDisplayLeft();
    sleep(500);
    if (push2.pressed())
    {
      break;
    }
  }
  return;
}

// LED Menu

// TODO: MAKE SURE WE CAN INTERRUPT AND MAINTAIN LED FUNCTIONALITY AT SAME TIME
//  LOOK INTO INTERRUPT + GO TO COMBINATION FOR INTERRUPT STARTUP ROUTINE

void ledMenu()
{
  for (int i; i < 10; i++)
  {
    Serial.print("\r");
  }

  Serial.print("Welcome to the LED Control Menu! \n\n");
ledprompt:

  lcdCheck();
  ledCheck();

  Serial.print("Option 5 will return you to the Main Menu \n\n");
  Serial.print("Otherwise, press & hold Button 1 \n\n");

  Serial.print("************************\n");
  Serial.print("*|        MENU        |*\n");
  Serial.print("*|                    |*\n");
  Serial.print("*| 1: Turn LEDs OFF   |*\n");
  Serial.print("*| 2: LED 'WAVE'      |*\n");
  Serial.print("*| 3: LED 'BLINK'     |*\n");
  Serial.print("*| 4: LED 'ALTERNATE' |*\n");
  Serial.print("*| 5: Back 2 Main Menu|*\n");
  Serial.print("*|                    |*\n");
  Serial.print("************************\n");

  Serial.print("Please enter input\n");

  while (Serial.available() == 0)
  {
    // THIS BLOCK STAYS EMPTY!
  }
  char inputData = (char)Serial.read();
  Serial.print("Input: ");
  Serial.print(inputData);
  Serial.print("\n\n");
  Serial.flush();

  switch (inputData)
  {
  case '1':
    Serial.print("Entering deep sleep, press the Reset button to wake!\n\n");
    digitalWrite(P3_1, 0);
    digitalWrite(P2_1, 0);
    digitalWrite(P2_0, 0);
    suspend();
    goto ledprompt;
  case '2':
    lcd.setCursor(2, 0);
    ledWave();
    goto ledprompt;
  case '3':
    lcd.setCursor(2, 0);
    ledBlink();
    goto ledprompt;
  case '4':
    lcd.setCursor(2, 0);
    ledAlt();
    goto ledprompt;
  case '5':
    return;
  default:
    goto ledprompt;
  }
  return;
}

// LCD Name Display

void displayName()
{
  lcd.clear();

  lcd.setCursor(2, 0);
  lcd.write(byte(0));
  lcd.print("VETCON  30");
  lcd.write(byte(0));

  lcd.setCursor(0, 1);
  if (nameToggle == NAMESET)
  {

    lcd.print(name);
  }
  else
  {
    Serial.print("ERROR: NAME NOT SET\n");
  }

  return;
}

// Name Set
void setName()
{
  Serial.print("Please Enter A Name:\n");
  while (Serial.available() == 0)
  {
    // THIS BLOCK STAYS EMPTY!
  }

  String inputData = Serial.readStringUntil('\n');

  char secretString2[] = "Senior Design";
  char secretAnswer2[] = "\n   _____            _               ____            _           \n  / ___/___  ____  (_)___  _____   / __ \\___  _____(_)___ _____ \n  \\__ \\/ _ \\/ __ \\/ / __ \\/ ___/  / / / / _ \\/ ___/ / __ `/ __ \\ \n ___/ /  __/ / / / / /_/ / /     / /_/ /  __(__  ) / /_/ / / / /\n/____/\\___/_/ /_/_/\\____/_/     /_____/\\___/____/_/\\__, /_/ /_/ \n                                                  /____/        \n";

  if (inputData == secretString2)
  {
    Serial.print(secretAnswer2);
  }

  Serial.print("You entered ");
  Serial.print(inputData);
  SYSCFG0 = FRWPPW | DFWP;
  setStr(inputData, name);
  nameToggle = NAMESET;
  SYSCFG0 = FRWPPW | PFWP | DFWP;
  Serial.print("\n");
  Serial.flush();
  sleepSeconds(1);
  return;
}

// Board Wipe function specifically for 'red herring' key

void wipeBoard()
{
  SYSCFG0 = FRWPPW | DFWP;
  startFlag = 0;
  secretFlag = 0;
  nameToggle = 0;
  secretFlag2 = 0;
  secretFlag3 = 0;
  secretFlag4 = 0;
  wrongFlag = 0;
  lcd.clear();
  clearStr(name);
  SYSCFG0 = FRWPPW | PFWP | DFWP;

  return;
}

// Main function "loop"
void loop()
{
  // put your main code here, to run repeatedly:
  lcdCheck();
  ledCheck();
  sleepSeconds(2);
  const char *welcome[] = {
      "*****************BEWARE*******************",
      "*****************THERE********************",
      "******************IS**********************",
      "***************NO*ESCAPE******************",
      "╭╮╭╮╭┳━━━┳╮╱╱╭━━━┳━━━┳━╮╭━┳━━━╮╭━━━━┳━━━╮",
      "┃┃┃┃┃┃╭━━┫┃╱╱┃╭━╮┃╭━╮┃┃╰╯┃┃╭━━╯┃╭╮╭╮┃╭━╮┃",
      "┃┃┃┃┃┃╰━━┫┃╱╱┃┃╱╰┫┃╱┃┃╭╮╭╮┃╰━━╮╰╯┃┃╰┫┃╱┃┃",
      "┃╰╯╰╯┃╭━━┫┃╱╭┫┃╱╭┫┃╱┃┃┃┃┃┃┃╭━━╯╱╱┃┃╱┃┃╱┃┃",
      "╰╮╭╮╭┫╰━━┫╰━╯┃╰━╯┃╰━╯┃┃┃┃┃┃╰━━╮╱╱┃┃╱┃╰━╯┃",
      "╱╰╯╰╯╰━━━┻━━━┻━━━┻━━━┻╯╰╯╰┻━━━╯╱╱╰╯╱╰━━━╯",
      "╭╮╱╱╭┳━━━┳━━━━┳━━━┳━━━┳━╮╱╭╮",
      "┃╰╮╭╯┃╭━━┫╭╮╭╮┃╭━╮┃╭━╮┃┃╰╮┃┃",
      "╰╮┃┃╭┫╰━━╋╯┃┃╰┫┃╱╰┫┃╱┃┃╭╮╰╯┃",
      "╱┃╰╯┃┃╭━━╯╱┃┃╱┃┃╱╭┫┃╱┃┃┃╰╮┃┃",
      "╱╰╮╭╯┃╰━━╮╱┃┃╱┃╰━╯┃╰━╯┃┃╱┃┃┃",
      "╱╱╰╯╱╰━━━╯╱╰╯╱╰━━━┻━━━┻╯╱╰━╯",
      "******************************************",
      "******************************************",
      "******************************************",
      "******************************************",
  };

  if (startFlag == 0)
  { // On display welcome on startup, never again.
    for (int idx = 0; idx < sizeof(welcome) / sizeof(char); idx++)
    {
      Serial.print(welcome[idx]);
      Serial.print("\n");
    }
    SYSCFG0 = FRWPPW | DFWP;
    startFlag = 1;
    SYSCFG0 = FRWPPW | PFWP | DFWP;
  }

  mainMenu();
}