ISR:
An ISR is a special function that runs automatically when an interrupt occurs.
Use Case
Normal code: You keep doing your work step by step.
Interrupt: Something important happens (button press, timer expires, UART receives data).
ISR: CPU pauses the current work, quickly handles the event, then goes back to what it was doing.

Polling
void loop() {
    if (digitalRead(BUTTON_PIN) == HIGH) {
        Serial.println("Button Pressed");
    }
}

The CPU keeps checking the button millions of times.

Interrupt + ISR
void IRAM_ATTR buttonISR() {
    Serial.println("Button Pressed");
}

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(
        digitalPinToInterrupt(BUTTON_PIN),
        buttonISR,
        FALLING
    );
}

Now the CPU does other work. Only when the button is pressed does buttonISR() automatically run.
//code
const int buttonPin = 4;
volatile bool buttonPressed = false;

void IRAM_ATTR buttonISR() {
    buttonPressed = true;
}

void setup() {
    Serial.begin(115200);
    pinMode(buttonPin, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(buttonPin),
        buttonISR,
        FALLING
    );
}

void loop() {
    if (buttonPressed) {
        Serial.println("Button was pressed!");
        buttonPressed = false;
    }
}
How it works
Program starts.
loop() keeps running.
User presses button.
ESP32 hardware generates an interrupt.
CPU jumps to buttonISR().
ISR sets buttonPressed = true.
ISR exits.
CPU returns to loop().
loop() notices the flag and prints the message.

IRAM:
IRAM_ATTR tells the compiler to place the function in Instruction RAM (IRAM), so it can run even if flash memory is temporarily unavailable.

Volatile:
volatile tells the compiler:

"This variable can change unexpectedly outside the normal program flow."

Without volatile, the compiler might optimize the code and never notice that the ISR changed the variable.