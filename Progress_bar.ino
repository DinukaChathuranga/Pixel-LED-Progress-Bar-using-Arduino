#include <FastLED.h>


#define NUM_LEDS 51
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

// Define the colors for the loading animation
CRGB loadingColor = CRGB::Green;
CRGB backgroundColor = CRGB::Black;
CRGB breathingColor = CRGB::Red;

int segmentWidth = 3;

int animationSpeed = 500;

int brightnessLevel = 220; 

void updateLoadingAnimation(int progress) {
 
  fill_solid(leds, NUM_LEDS, backgroundColor);

  int numSegments = progress / segmentWidth;

  for (int i = 0; i < numSegments; i++) {
    int startIndex = i * segmentWidth;
    int endIndex = startIndex + segmentWidth;
    fill_solid(leds + startIndex, endIndex - startIndex, loadingColor);
  }

  FastLED.show();
}




void setup() {

  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(brightnessLevel); 
}

void loop() {
 int num_leds = 48;
  for (int progress = 0; progress <= num_leds; progress += segmentWidth) {
    updateLoadingAnimation(progress);
    delay(animationSpeed);
  }

  fill_solid(leds, NUM_LEDS, breathingColor);
  FastLED.show();
  delay(2500); 

  // Perform heart breathing effect
 
}
