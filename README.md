# Task 3.1P: Sensor-Based Trigger and Notification System

## Project Objective
[cite_start]The goal of this task is to monitor light intensity levels in a terrarium and generate automated notifications based on sunlight exposure[cite: 11, 14, 15]. [cite_start]The system ensures that the environment meets the required conditions for plant health[cite: 13].

## System Architecture
[cite_start]The system follows a modular design for data acquisition and event-driven communication[cite: 18].

### Block Diagram


## Implementation Details

### 1. Hardware Setup
- [cite_start]**Controller:** Arduino Nano 33 IoT[cite: 8].
- [cite_start]**Sensor:** BH1750 Light Sensor (connected via I2C)[cite: 8, 19].
- [cite_start]**Trigger Mechanism:** The system monitors the light level; a threshold is defined in the code to distinguish between "sunlight exposure" and "darkness"[cite: 15, 24].

### 2. Notification Mechanism
[cite_start]The system utilizes [IFTTT / Node-RED] to push notifications[cite: 18].
- [cite_start]**Trigger Logic:** When the light level crosses the defined threshold, a signal is sent to the web service[cite: 24].
- [cite_start]**Notification:** An [email/mobile notification] is generated upon the trigger event[cite: 17].

## Demonstration
A video recording showcasing the system's response to changing light intensity:
[رابط الفيديو الخاص بك هنا]

## Testing Methodology
[cite_start]To verify the system, I performed the following tests[cite: 24]:
1. [cite_start]**Sensor Calibration:** Verified raw data collection using the `BH1750test` example code to ensure accuracy[cite: 20].
2. **Trigger Validation:** Simulated sunlight conditions to confirm the threshold-based trigger fires correctly.
3. [cite_start]**Notification Verification:** Monitored the target platform (email/app) to confirm delivery of alerts when the threshold is crossed[cite: 22].
