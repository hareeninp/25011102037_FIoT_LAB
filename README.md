# Foundations of IoT Laboratory

**Repository Name:** 25011102037_FIoT_LAB

**Register Number:** 25011102037

**Subject:** Foundations of IoT Laboratory

## Repository Overview

This repository contains the laboratory experiments, continuous assessment tasks, and final IoT project performed as part of the Foundations of IoT Laboratory.

The experiments are organized into two main sections:

- **8051 Microcontroller:** Embedded C programming, GPIO interfacing, peripheral control, and hardware experiments using Keil µVision.
- **STM32 Microcontroller:** Embedded system development, sensor interfacing, UART and I²C communication, Wi-Fi connectivity, MQTT communication, and IoT data analytics using STM32CubeMX, Keil µVision, ESP8266, and Node-RED.

## Repository Structure

```text
25011102037_FIoT_LAB/
├── README.md
├── 8051/
│   ├── CAT 2/
│   ├── CAT 3/
│   ├── CAT 4/
│   ├── CAT 5/
│   │   ├── Task 2A (led fading pwm)/
│   │   └── Task 2B (waveforms)/
│   ├── CAT 6/
│   │   ├── Task A(transmit)/
│   │   └── Task B(echo interrupt)/
│   └── CAT 7/
│       ├── Task 7A/
│       ├── Task 7b/
│       └── Task 7C/
└── STM32/
    ├── CAT8/
    │   ├── Task8A/
    │   ├── Task8B/
    │   └── Task8C/
    ├── CAT9/
    │   ├── Task9A/
    │   └── Task9B/
    ├── CAT10/
    │   ├── Task9A/
    │   └── Task9B/
    ├── CAT11/
    │   ├── Task10C/
    │   ├── Task10D/
    │   └── Task10E/
    ├── CAT12/
    │   ├── Task1/
    │   ├── Task2/
    │   └── Task3/
    ├── CAT13/
    ├── CAT14/
    └── CAT15/
        └── Project - IoT Weather Station with Indoor vs Outdoor Analysis/
```

## Development Tools

**8051 Microcontroller**

- AT89S52 / 8051 Microcontroller
- Keil µVision
- Embedded C
- 8051 Assembly Startup Files

**STM32 Microcontroller**

- STM32F4 Microcontroller
- STM32CubeMX
- Keil µVision
- Embedded C
- STM32 HAL Drivers
- Bosch BME280 Sensor API
- ESP8266 Wi-Fi Module
- MQTT Protocol
- MQTTX
- Node-RED
- Node-RED Dashboard 2.0
- Weather API

## Experiment Documentation

Each experiment or task is documented using a `README.md` file where available.

The experiment documentation follows this format:

1. Experiment Details
2. Circuit Diagram
3. Core Logic / Pseudocode / Code Base
4. Inference

## Project Files

**8051 Tasks**

- Keil project file (`.uvproj` or `.uvprojx`)
- Embedded C source file (`.c`)
- Startup assembly file (`STARTUP.A51`)
- `Objects/` directory containing the generated `.hex` file
- Experiment `README.md`

**STM32 Tasks**

- STM32CubeMX configuration file (`.ioc`)
- `.mxproject` file
- `Core/` directory
- `Drivers/` directory
- `MDK-ARM/` directory containing the Keil project and startup assembly file
- Experiment `README.md`

## CAT15 – IoT Weather Station with Indoor vs Outdoor Analysis

**Project Title:** IoT Weather Station with Indoor vs Outdoor Analysis

**Objective:**

To develop an IoT-based weather monitoring system that measures indoor temperature, atmospheric pressure, and humidity using a BME280 sensor interfaced with an STM32 microcontroller.

The sensor readings are transmitted through an ESP8266 Wi-Fi module to an MQTT broker and displayed using Node-RED Dashboard 2.0.

Outdoor weather data is obtained from an online weather API and compared with the indoor sensor readings to generate recommendations such as AC ON, FAN ON, ventilation, or humidity control.

**System Architecture:**

```text
BME280 Sensor
     |
     | I2C
     v
STM32 Microcontroller
     |
     | UART
     v
ESP8266 Wi-Fi Module
     |
     | MQTT over Wi-Fi
     v
MQTT Broker (broker.emqx.io)
     |
     | MQTT Subscribe
     v
Node-RED <----- HTTP ----- Weather API
     |
     v
Indoor vs Outdoor Comparison
     |
     v
Decision Logic
     |
     v
Node-RED Dashboard 2.0
```

**Hardware Components:**

- STM32F4 Microcontroller
- BME280 Temperature, Pressure, and Humidity Sensor
- ESP8266 Wi-Fi Module
- Wi-Fi Router

**Software Components:**

- STM32CubeMX
- Keil µVision
- STM32 HAL Libraries
- Bosch BME280 Sensor API
- MQTT Broker (`broker.emqx.io`)
- MQTTX
- Node-RED
- Node-RED Dashboard 2.0
- Online Weather API

**MQTT Topics:**

```text
stm32/jayashri/temperature
stm32/jayashri/pressure
stm32/jayashri/humidity
```

**Working Principle:**

1. The BME280 sensor measures indoor temperature, pressure, and humidity.
2. The STM32 microcontroller acquires the readings through I²C communication.
3. The ESP8266 module connects the STM32 system to Wi-Fi.
4. Sensor readings are published to the MQTT broker.
5. Node-RED subscribes to the MQTT topics and receives the indoor sensor data.
6. Outdoor temperature and humidity are retrieved from a weather API.
7. A Node-RED function compares indoor and outdoor conditions.
8. The system generates recommendations for cooling, ventilation, and humidity control.
9. The readings and recommendations are displayed on Node-RED Dashboard 2.0.

**Decision Outputs:**

- AC ON
- FAN ON
- AC / FAN OFF
- Ventilate
- Dehumidifier ON
- Humidifier ON
- NO ACTION

These are dashboard recommendations and do not directly control physical appliances.

## Objective

To understand microcontroller architecture, embedded programming, GPIO control, peripheral interfacing, sensor integration, wireless communication, MQTT-based data transmission, and IoT analytics through practical experiments using 8051 and STM32 microcontrollers.

The laboratory also aims to demonstrate end-to-end IoT system development by integrating embedded hardware, cloud communication, external weather data, and real-time dashboard visualization.