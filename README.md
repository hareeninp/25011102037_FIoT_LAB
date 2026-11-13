# Foundations of IoT Laboratory

**Repository Name:** 25011102037_FIoT_LAB

**Register Number:** 25011102037

**Subject:** Foundations of IoT Laboratory

## Repository Overview

This repository contains the laboratory experiments and continuous assessment tasks performed as part of the Foundations of IoT Laboratory.

The experiments are organized into two main sections:

- **8051 Microcontroller:** Embedded C programming, GPIO interfacing, peripheral control, and hardware experiments using Keil µVision.
- **STM32 Microcontroller:** Embedded system development, peripheral interfacing, and microcontroller programming using STM32CubeMX and Keil µVision.

## Repository Structure

```text
25011102037_FIoT_LAB/
├── README.md
├── 8051/
│   ├── CAT2/
│   │   └── TASK2B/
│   ├── CAT3/
│   │   └── TASK3A/
│   ├── CAT4/
│   │   └── TASK4A/
│   ├── CAT5/
│   │   ├── TASK5A/
│   │   ├── TASK5B/
│   │   │   ├── TASK5B.1/
│   │   │   ├── TASK5B.2/
│   │   │   └── TASK5B.3/
│   │   └── TASK5C/
│   ├── CAT6/
│   │   ├── TASK6A/
│   │   └── TASK6B/
│   └── CAT7/
│       ├── TASK7A/
│       ├── TASK7B/
│       └── TASK7C/
└── STM32/
    ├── CAT8/
    │   ├── TASK8A/
    │   ├── TASK8B/
    │   └── TASK8C/
    ├── CAT9/
    │   ├── TASK9A/
    │   └── TASK9B/
    ├── CAT10/
    │   ├── TASK10A/
    │   ├── TASK10B/
    │   └── TASK10C/
    ├── CAT11/
    │   ├── TASK11A/
    │   └── TASK11B/
    ├── CAT12/
    │   ├── TASK12A/
    │   ├── TASK12B/
    │   └── TASK12C/
    ├── CAT13/
    │   └── TASK13/
    └── CAT14/
        └── TASK14/
```

## Development Tools

**8051 Microcontroller**
- AT89S52 / 8051 Microcontroller
- Keil µVision
- Embedded C
- 8051 Assembly Startup Files

**STM32 Microcontroller**
- STM32 Microcontroller
- STM32CubeMX
- Keil µVision
- Embedded C
- STM32 HAL Drivers

## Experiment Documentation

Each task folder contains the relevant project files and a `README.md` documenting the experiment.

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
- Task `README.md`

**STM32 Tasks**

- STM32CubeMX configuration file (`.ioc`)
- `.mxproject` file
- `Core/` directory
- `Drivers/` directory
- `MDK-ARM/` directory containing the Keil project and startup assembly file
- Task `README.md`

## Objective

To understand microcontroller architecture, embedded programming, GPIO control, peripheral interfacing, and hardware-software integration through practical experiments using 8051 and STM32 microcontrollers.