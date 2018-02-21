#include <BlockDriver.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SysCall.h>

#include <SFEMP3Shield.h>
#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shieldmainpage.h>
#include <LiquidCrystal.h>


//Simple example of using Sparkfun's MP3 Shield. You need to install the SdFat and SFEMP3Shield libraries first.

//Select include SdFat library from Sketch menu 


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


int trackNumber = 1;

SdFat sd; // Create SDFat object. 

SFEMP3Shield MP3player; // Create SFEMP3Shield object

//Settings for MP3 player
const uint8_t volume = 0; // MP3 Player volume 0=max, 255=lowest (off)
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max


//In void setup you need to functions which are define below
void setup(){
  lcd.begin(16, 2);
  initSD();  // Initialize the SD card
  initMP3Player(); // Initialize the MP3 Shield
}

void loop()
{

if (trackNumber == 0) {
      MP3player.playTrack(0); //plays track 1 (track000.mp3)
//lcd.print("ddworman presents: soundclout project uno");
  

 }

 else if (trackNumber == 1) {
   MP3player.playTrack(1); //plays track 2 (track001.mp3)
   //lcd.print("ddworman presents: poles 1469");

 }

else if (trackNumber == 2) {
   MP3player.playTrack(2); //plays track 2 (track002.mp3)
   //lcd.print("ddworman presents: narkotik kal");
 
}
//function to intialize SD card. Leave it alone unless you know what you're doing.

void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}


//function to intialize MP3 player. Leave it alone unless you know what you're doing

void initMP3Player()
{
  uint8_t result = MP3player.begin(); // init the mp3 player shield
  if(result != 0) // check result, see readme for error codes.
  {
    // Error checking can go here!
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}



