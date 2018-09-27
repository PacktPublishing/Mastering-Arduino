
#include <rtttl.h>

#define PIEZOPIN 7
#define SPEAKERPIN 8

int soundPin = PIEZOPIN;
char *song = "r2d2:d=4,o=3,b=250:17a8,480p,17g#8,480p,17g8,480p,17f#8,480p,17f8,480p,17e8,480p,2d#8,480p,17b6,480p,17d7,480p,17d#6,480p,17f#8,480p,17c#7,480p,17g#7,480p,17f6,480p,17a#7,480p,17e7,480p,17g#8,480p,17e8,480p,17g#6,480p,17g7,480p,17c#7,480p,17g7,480p,17f#8,480p,17c#7,480p,17f#6,480p,17f8,480p,17g#7,480p,17g6,480p,17a8,480p,17c#8,480p,17g6,480p,17f#8,480p,17g7,480p,17f8,480p,17a#6,480p,17f#8,480p,17d8,480p,17g7,480p,17g8,480p,17c8,480p,17g#6,480p,17a8";

void setup() {
  // put your setup code here, to run once:
  Rtttl player;
  player.begin(soundPin);
  player.play(song, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
