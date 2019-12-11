#include "Talkie.h"m   
 #include "Vocab_Special.h"

Talkie voice;

void setup() {
 }
 void loop() {
     voice.say(spPAUSE2);
     voice.say(sp2_DANGER);
     voice.say(sp2_DANGER);
     voice.say(sp3_STORM);
     voice.say(sp3_IN);
     voice.say(sp3_THE);
     voice.say(sp3_NORTH);
 }
