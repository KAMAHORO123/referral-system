# Ruhengeri Referral Hospital Healthcare System

## Overview
This project is a C++ program designed to manage patient appointments at Ruhengeri Referral Hospital using linked lists. The system allows users to register patients, doctors, and appointments while ensuring data integrity through input validation and unique ID enforcement.

## Features
- Register patients with ID, name, date of birth, and gender.
- Register doctors with ID, name, and specialization.
- Create appointments ensuring valid patient and doctor IDs.
- Display registered patients, doctors, and appointments.
- Menu-based navigation for easy interaction.
- Input validation to prevent incorrect entries.

## Menu Options
1. Register patient
2. Register doctor
3. Register appointment
4. Display patients
5. Display doctors
6. Display appointments
7. Exit

## Installation and Usage
1. Compile the C++ code using a compiler (e.g., g++):
   ```bash
   g++ hospital_system.cpp -o hospital_system
   ```
2. Run the executable:
   ```bash
   ./hospital_system
   ```
3. Follow the menu prompts to interact with the system.

## Requirements
- C++ Compiler (g++, clang, or MSVC)
- Basic understanding of C++ and linked lists

## Input Validation
- Ensures patient_id, doctor_id, and appointment_id are unique.
- Prevents non-numeric input for integer fields.
- Verifies that referenced patient and doctor exist before creating an appointment.

## Contributing
Feel free to enhance the system by adding new features or optimizing existing functionalities. Submit pull requests with clear documentation.

## License
This project is licensed under the MIT License.

