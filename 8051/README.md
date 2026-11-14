# 8051 – FOUNDATIONS OF IoT LABORATORY

**Repository Name:** 25011102037_FIoT_LAB

**Register Number:** 25011102037

**Subject:** Foundations of IoT Laboratory

**Microcontroller:** 8051

---

## Overview

This directory contains the 8051 microcontroller laboratory experiments performed as part of the Foundations of IoT Laboratory.

The experiments focus on embedded C programming, GPIO operations, digital input/output interfacing, LED control, switch interfacing, peripheral control, and hardware-software integration.

The programs are developed using Keil µVision and Embedded C for the 8051 microcontroller architecture.

---

## Repository Structure

```text
8051/
├── README.md
├── CAT2/
│   └── TASK2B/
├── CAT3/
│   └── TASK3A/
├── CAT4/
│   └── TASK4A/
├── CAT5/
│   ├── TASK5A/
│   ├── TASK5B/
│   │   ├── TASK5B.1/
│   │   ├── TASK5B.2/
│   │   └── TASK5B.3/
│   └── TASK5C/
├── CAT6/
│   ├── TASK6A/
│   └── TASK6B/
└── CAT7/
    ├── TASK7A/
    ├── TASK7B/
    └── TASK7C/
```

Each CAT directory contains the corresponding experiment files and task documentation.

---

## Development Tools

**Hardware:**
- AT89S52 / 8051 Microcontroller
- LEDs
- Push Buttons and Switches
- Interfacing Components
- 8051 Development Board

**Software:**
- Keil µVision
- Embedded C
- 8051 Assembly Startup Files
- Keil C51 Compiler

---

## Experiment Documentation

Each task is documented using the following format:

1. Experiment Details
2. Circuit Diagram
3. Core Logic / Pseudocode / Code Base
4. Inference

---

## Project Files

A typical 8051 task folder contains:

```text
TASK/
├── Objects/
│   └── project.hex
├── STARTUP.A51
├── main.c
├── project.uvproj
├── README.md
└── circuit.png
```

**File Description:**

| File / Folder | Description |
|---|---|
| `Objects/` | Compiled output files |
| `.hex` | Generated hexadecimal program for the microcontroller |
| `STARTUP.A51` | 8051 startup assembly file |
| `.c` | Embedded C source code |
| `.uvproj` / `.uvprojx` | Keil µVision project file |
| `README.md` | Experiment documentation |
| `circuit.png` | Circuit diagram |

---

## Objective

To understand the architecture and programming of the 8051 microcontroller through practical laboratory experiments.

The experiments provide hands-on experience in embedded C programming, digital input/output operations, peripheral interfacing, and hardware-software integration using the 8051 microcontroller.

The laboratory work helps develop fundamental embedded systems programming skills and provides a foundation for advanced microcontroller and IoT applications.