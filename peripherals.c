// Required LPC header files (Specific to Keil/LPC1769 setup)
#include "LPC17xx.h"  // General header for LPC1769 registers
#include "ADC.h"    // Header for Analog-to-Digital Converter functions
#include "LCD.h"    // Header for 16x2 LCD control functions
#include <stdio.h>  // For using sprintf

// --- Pin Definitions ---
// Assuming Sensor Analog Output (A0) is connected to ADC Channel 0 (P0.23 on LPC1769)
#define MOISTURE_ADC_CHANNEL 0

// Motor Control: Assuming the Relay is driven by GPIO Pin P2.0
#define MOTOR_PIN (1 << 0) // Pin P2.0
#define MOTOR_PORT LPC_GPIO2

// --- Critical Threshold ---
// If the reading is *above* this threshold, the soil is considered DRY.
// This value must be calibrated based on the YL-69 sensor output.
#define DRYNESS_THRESHOLD 1500

// --- Function Prototypes ---
void init_peripherals(void);
void delay_ms(uint32_t ms);

/**
 * @brief Initializes GPIO, ADC, and LCD peripherals.
 */
void init_peripherals(void) {
    // 1. Initialize GPIO for Motor Control
    MOTOR_PORT->FIODIR |= MOTOR_PIN; // Set Motor Pin (P2.0) as output
    MOTOR_PORT->FIOCLR |= MOTOR_PIN; // Motor is initially OFF
    
    // 2. Initialize ADC (for reading analog sensor data)
    ADC_Init(12); // Initialize 12-bit ADC
    
    // 3. Initialize LCD (to display status)
    LCD_Init();
    LCD_DisplayString(1, "Soil Monitor Ready");
}
