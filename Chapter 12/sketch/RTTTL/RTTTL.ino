#include <rtttl.h>

#define PIEZOPIN 7
#define SPEAKERPIN 8

int soundPin = PIEZOPIN;
char *song = "Star Wars:d=8,o=5,b=180:f5,f5,f5,2a#5.,2f.,d#,d,c,2a#.,4f.,d#,d,c,2a#.,4f.,d#,d,d#,2c,4p,f5,f5,f5,2a#5.,2f.,d#,d,c,2a#.,4f.,d#,d,c,2a#.,4f.,d#,d,d#,2c";

void setup() {
  // put your setup code here, to run once:
  Rtttl player;
  player.begin(soundPin);
  player.play(song, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
