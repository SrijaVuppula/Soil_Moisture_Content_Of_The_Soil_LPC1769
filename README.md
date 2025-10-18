# Sensing Moisture Content of the Soil 

This repository contains the C source code, hardware logic, and project report for an automated system designed to sense soil moisture levels and control irrigation to prevent water wastage in agriculture.

---

## Project Objective

The primary goal of this system is to improve irrigation efficiency and conserve water by ensuring that water is supplied to plants **only when there is not enough moisture in the soil**.

* **Key Function:** Detect soil dryness to decide when the water pump should be turned ON/OFF.
* **Target Audience:** Farmers and individuals with gardens, aiming to reduce labor and cost.

---

## System Components (Hardware & Software)

This project is built around an embedded system architecture using a Keil MicroVision environment.

### Hardware

| Component | Role in the System | Key Specification |
| :--- | :--- | :--- |
| **Microcontroller (MCU)** | Central control unit; processes sensor data and controls the pump motor. | **LPC 1769** (ARM Cortex-M3) |
| **Moisture Sensor** | Senses the resistance/water content in the soil. | **YL-69 Sensor** |
| **Comparator** | Compares the sensor's analog voltage to a set reference threshold. | **YL 38 Comparator Module** (LM393 IC) |
| **Actuator** | Provides water supply. | **12V Pump Motor (M1)** controlled by a Relay (K1) |

### Software

| Tool | Purpose |
| :--- | :--- |
| **IDE/Compiler** | Used for writing, compiling (to hex files), and debugging the C source code. | **Keil MicroVision 4** |
| **Programming Language** | Used to program the LPC-1769 Microcontroller. | **C / Embedded C** |
| **Interface** | Used to upload code and monitor sensor readings (serial output). | **Flash Magic Tool** (for upload) and **Windows System** (for control/monitoring) |

---

## Repository Contents

| File Name | Description |
| :--- | :--- |
| **`main.c`** | Contains the **core control loop logic** (`while(1)`) for reading the sensor, checking the threshold, and making the ON/OFF decision. |
| **`peripherals.c`** | **Contains the hardware initialization functions** (`init_peripherals`), setting up the GPIO pins, ADC, and LCD before the main loop starts. |

---

##  Future Scope

The architecture is modular and designed to be expandable. Potential future scope includes:

* Developing a **mobile application** to allow farmers to control the system remotely.
* Integrating additional sensors (e.g., DHT11 for temperature/humidity) to predict weather patterns or plant disease.
* Adding LCD screens to display the current moisture content levels and water utilization statistics.
---

