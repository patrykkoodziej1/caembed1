#include "mbed.h"

DigitalIn button(PA_0);
Serial pc(USBTX, USBRX);

bool buttonFlag = false;

void buttonPressed() {
    buttonFlag = true; // Set the flag to indicate button press
}

int main() {
    button.rise(&buttonPressed);
    
    while (1) {
        if (buttonFlag) {
            pc.printf("Button pressed\n");
            buttonFlag = false; // Reset the flag
        }