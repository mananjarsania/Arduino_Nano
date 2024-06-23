#include <Arduino_FreeRTOS.h>

// Define LED pin
const int ledPin = 13;  // Onboard LED pin on Arduino Nano

// Function prototypes
void TaskBlink(void *pvParameters);

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Create the Blink task
  xTaskCreate(
    TaskBlink,       // Task function
    "Blink",         // Name of the task
    128,             // Stack size (bytes)
    NULL,            // Parameter to pass
    1,               // Task priority
    NULL             // Task handle
  );

  // Start the scheduler
  vTaskStartScheduler();
}

void loop() {
  // Empty. Tasks are running in FreeRTOS.
}

void TaskBlink(void *pvParameters) {
  (void) pvParameters;

  // Task loop
  for (;;) {
    digitalWrite(ledPin, HIGH);  // Turn the LED on
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Wait for 1000 ms (1 second)
    digitalWrite(ledPin, LOW);   // Turn the LED off
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Wait for 1000 ms (1 second)
  }
}
