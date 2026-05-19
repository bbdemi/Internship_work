# Urban Monkey Robot — RPS Testing & Board Component Study

Testing individual components of the Urban Monkey robot using a **Regulated Power Supply (RPS)**, verifying current and voltage for each device, and studying all components present on the control board.
 
---

## Table of Contents

- [Project Overview](#project-overview)
- [RPS Testing — Voltage & Current Verification](#rps-testing--voltage--current-verification)
- [Complete Component List](#complete-component-list)
- [Component Functions In Detail](#component-functions-in-detail)
- [Observations & Notes](#observations--notes)
- [Status](#status)
---

## Project Overview

This session involved two main activities:

1. **RPS Testing** — Using a Regulated Power Supply to supply controlled voltage and current to each device individually, and checking whether the readings fall within the expected safe operating range.
2. **Board Component Study** — Identifying and understanding every component present on the Urban Monkey control board, which is built on a perfboard and interfaces with an ESP32.
---

## RPS Testing — Voltage & Current Verification

A **Regulated Power Supply (RPS)** was used to power each component or module individually. The purpose was to confirm that each device draws the expected current at its rated voltage — ensuring nothing is shorted, damaged, or out of spec before integrating into the full system.

### Testing Approach

- Set the RPS to the component's rated voltage before connecting
- Enable current limiting on the RPS as a safety measure
- Connect the component and observe the voltage and current readings
- Compare readings against the expected datasheet values
- Mark the component as pass or fail based on whether readings are within range
### General Voltage Reference

| Component | Typical Operating Voltage |
|-----------|--------------------------|
| ESP32 | 3.3V (logic) / 5V (USB input) |
| Relay Module | 5V coil |
| MOSFETs (gate signal) | 3.3V – 5V |
| LEDs | 2V – 3.5V (with series resistor) |
| Solenoid / High-power load | 12V / 24V (via relay or MOSFET) |

> All readings were verified against component datasheets and expected operating ranges during the RPS session.
 
---

## Complete Component List

### 1. 🔵 Relay (Blue Box)
**Type:** Electromechanical Switch

- Physically switches high-power circuits ON and OFF using a low-power control signal
- Used to control solenoids, lights, and other high-current loads
- Operates via an internal coil that pulls a mechanical contact when energized
---

### 2. ⚫ Power Transistors / MOSFETs (Black with Silver Top)
**Type:** Electronic Switch — 3-pin (Gate, Drain, Source)

- Used as electronic switches controlled by the ESP32's GPIO signals
- Allow the ESP32 (which outputs small currents) to switch much higher current loads
- The metal tab on top acts as a heat sink for thermal dissipation
---

### 3. 🔵 Resistors (Blue Cylindrical with Color Bands)
**Type:** Passive — Current Limiting

Used in multiple places across the board:
- In series with transistor/MOSFET gate pins to limit drive current
- In LED circuits to prevent overcurrent through the LED
- As pull-up or pull-down resistors on signal lines to define a default logic state
---

### 4. 🔴 Ceramic Capacitors (Small Red, Marked "101")
**Type:** Passive — Noise Filtering

- Marking "101" = 100pF capacitance
- Placed across power supply pins to filter high-frequency noise
- Smooth out sudden voltage spikes and dips caused by switching loads
- Stabilize the circuit during rapid switching of relays or MOSFETs
---

### 5. 🔴 Diodes (Red Cylindrical with Band)
**Type:** Rectifier / Protection Diode

- Allow current to flow in one direction only (band = cathode = negative end)
- **Flyback diodes** — placed across relay coils and solenoids to absorb the voltage spike generated when an inductive load is suddenly switched off (very important for protecting MOSFETs and ESP32)
- Also used for reverse polarity protection to prevent damage from incorrect wiring
---

### 6. 💡 LED Indicators
**Type:** Visual Status Indicator

- Provide real-time visual feedback about the circuit's state
- Common uses on this board:
    - Power ON indicator
    - Relay energized indicator
    - GPIO signal active indicator
- Always used with a series resistor to limit current
---

### 7. 🔌 Screw Terminals
**Type:** Electrical Connector — External Interface

- Provide secure, tool-tightened connection points for external wiring
- Used to connect:
    - Main power input to the board
    - Solenoid output wires
    - Light/load output wires
    - Ground lines
- More reliable than header pins for high-current connections
---

### 8. 🔗 Header Pins
**Type:** Signal Connector — ESP32 Interface

- Connect the ESP32 module to the perfboard circuit
- Carry GPIO control signals from the ESP32 to transistors and relays
- Also carry 5V and GND from the ESP32 to power the board's logic components
- Allow the ESP32 to be plugged and unplugged without soldering
---

### 9. 🧵 Jumper Wires / Solder Tracks
**Type:** Interconnect — Prototype Wiring

- Run across the perfboard to connect component legs together
- Serve the same role as copper traces on a manufactured PCB
- In prototyping, these are either short wire links soldered in place or solder bridges between adjacent holes
---

### 10. 🟤 Perfboard (Base Board)
**Type:** Substrate — General Purpose PCB

- A board pre-drilled with a regular grid of holes, each with a copper pad
- Components are inserted through the holes and soldered on the underside
- Used to build custom circuits without designing a dedicated PCB
- All the above components are mounted and interconnected on this perfboard
---

## Component Functions In Detail

### Why Flyback Diodes Are Critical
When a relay coil or solenoid is de-energized, the collapsing magnetic field generates a large reverse voltage spike (sometimes 10× the supply voltage). Without a flyback diode across the coil, this spike travels back into the MOSFET or ESP32 pin and can instantly destroy them. The diode clamps this spike by giving the induced current a safe path to dissipate.

### Why MOSFETs Instead of Direct ESP32 Control
The ESP32 GPIO pins can only source or sink about 12mA safely. Relays, solenoids, and motors require far more current. MOSFETs act as the interface — the ESP32 sends a small signal to the gate, and the MOSFET switches the full load current through its drain-source channel without stressing the ESP32.

### Why Capacitors Near Power Pins
Every time a relay clicks or a MOSFET switches, it draws a sudden burst of current from the supply. This creates a brief voltage dip on the power rail. Ceramic capacitors placed close to the supply pins of ICs act as a local charge reservoir, instantly supplying this burst and keeping the voltage stable.
 
---

## Observations & Notes

- Voltage and current readings from the RPS confirmed that all tested components were drawing within their expected operating ranges.
- Flyback diodes across relay coils and solenoids are essential — missing or reversed diodes are a common failure point in relay driver boards.
- The "101" marking on ceramic capacitors is a standard 3-digit code: first two digits are significant figures, third is the multiplier (number of zeros in pF), so 101 = 10 × 10¹ = 100pF.
- Resistor color bands on blue cylindrical resistors follow the standard 4-band or 5-band color code for reading resistance values.
- Screw terminals are preferred over header pins for any connection carrying more than a few hundred milliamps.
- The perfboard construction is suitable for prototyping but for a production robot, migrating to a custom PCB would improve reliability and reduce the chance of loose solder joints.
---

## Status

| Task | Status |
|------|--------|
| RPS voltage & current testing for all devices | ✅ Completed |
| Component identification on board | ✅ Completed |
| Component function study | ✅ Completed |
| Full system integration testing | ⏳ Pending |
 
---

## References

- ESP32 GPIO electrical specifications
- Relay module datasheet (coil voltage & current ratings)
- Standard resistor color code chart
- Ceramic capacitor 3-digit marking code reference
- Flyback diode selection guidelines for inductive loads
