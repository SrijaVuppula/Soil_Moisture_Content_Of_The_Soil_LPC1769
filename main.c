int main(void) {
    uint32_t soil_value;
    char lcd_buffer[17]; // Buffer for LCD display line 2

    // System startup
    init_peripherals();

    // Main control loop - works in real time
    while (1) {
        // --- 1. Read Sensor Value ---
        soil_value = ADC_Read(MOISTURE_ADC_CHANNEL);
        
        // --- 2. Decision Logic (DRY/WET Check) ---
        if (soil_value > DRYNESS_THRESHOLD) {
            // Soil is dry (value indicates higher resistance/lower moisture)
            
            // Turn Pump ON [cite: 232]
            MOTOR_PORT->FIOSET |= MOTOR_PIN;
            
            // Update LCD Display
            LCD_DisplayString(1, "Soil is DRY!");
            sprintf(lcd_buffer, "PUMP: ON (Val:%lu)", soil_value);
            LCD_DisplayString(2, lcd_buffer);
            // The pump should be turned ON when moisture is below the set limit[cite: 232].

        } else {
            // Soil is wet (moisture is sufficient)
            
            // Turn Pump OFF [cite: 233]
            MOTOR_PORT->FIOCLR |= MOTOR_PIN;
            
            // Update LCD Display
            LCD_DisplayString(1, "Moisture OK.");
            sprintf(lcd_buffer, "PUMP: OFF (Val:%lu)", soil_value);
            LCD_DisplayString(2, lcd_buffer);
            // The pump should be turned OFF when moisture is above the set limit[cite: 233].
        }
        
        // --- 3. Optional: Send Status to Windows Terminal (Flash Magic Terminal) ---
        // char terminal_buffer[50];
        // sprintf(terminal_buffer, "Soil moisture: %lu\r\n", soil_value);
        // UART_SendString(terminal_buffer); // Assuming a UART transmit function

        delay_ms(5000); // Wait 5 seconds before taking the next reading
    }
}

// Simple blocking delay function
void delay_ms(uint32_t ms) {
    // This is a placeholder; a proper delay function would be implemented using a timer peripheral.
    for (uint32_t i = 0; i < ms; i++) {
        for (uint32_t j = 0; j < 10000; j++);
    }
}
