#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Patient Linked List Structure
struct Patient {
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient* next;
};

// Doctor Linked List Structure
struct Doctor {
    int doctor_id;
    string name;
    string specialization;
    Doctor* next;
};

// Appointment Linked List Structure
struct Appointment {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment* next;
};

Patient* patientHead = nullptr;
Doctor* doctorHead = nullptr;
Appointment* appointmentHead = nullptr;

// Function to validate integer input
int getValidatedInt(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer.\n";
        } else {
            return value;
        }
    }
}

// Function to validate string input
string getValidatedString(string prompt) {
    string value;
    cout << prompt;
    cin.ignore();
    getline(cin, value);
    while (value.empty()) {
        cout << "Input cannot be empty. Try again: ";
        getline(cin, value);
    }
    return value;
}

// Function to check if a patient exists
bool patientExists(int id) {
    Patient* temp = patientHead;
    while (temp) {
        if (temp->patient_id == id) return true;
        temp = temp->next;
    }
    return false;
}

// Function to check if a doctor exists
bool doctorExists(int id) {
    Doctor* temp = doctorHead;
    while (temp) {
        if (temp->doctor_id == id) return true;
        temp = temp->next;
    }
    return false;
}

// Function to check if an appointment exists
bool appointmentExists(int id) {
    Appointment* temp = appointmentHead;
    while (temp) {
        if (temp->appointment_id == id) return true;
        temp = temp->next;
    }
    return false;
}

// Function to register a patient
void registerPatient() {
    int id = getValidatedInt("Enter Patient ID: ");
    if (patientExists(id)) {
        cout << "Patient ID already exists!\n";
        return;
    }
    string name = getValidatedString("Enter Name: ");
    string dob = getValidatedString("Enter DOB: ");
    string gender = getValidatedString("Enter Gender: ");
    
    Patient* newPatient = new Patient{id, name, dob, gender, patientHead};
    patientHead = newPatient;
    cout << "Patient registered successfully!\n";
}

// Function to register a doctor
void registerDoctor() {
    int id = getValidatedInt("Enter Doctor ID: ");
    if (doctorExists(id)) {
        cout << "Doctor ID already exists!\n";
        return;
    }
    string name = getValidatedString("Enter Name: ");
    string specialization = getValidatedString("Enter Specialization: ");
    
    Doctor* newDoctor = new Doctor{id, name, specialization, doctorHead};
    doctorHead = newDoctor;
    cout << "Doctor registered successfully!\n";
}

// Function to register an appointment
void registerAppointment() {
    int id = getValidatedInt("Enter Appointment ID: ");
    if (appointmentExists(id)) {
        cout << "Appointment ID already exists!\n";
        return;
    }
    int patient_id = getValidatedInt("Enter Patient ID: ");
    int doctor_id = getValidatedInt("Enter Doctor ID: ");
    if (!patientExists(patient_id) || !doctorExists(doctor_id)) {
        cout << "Patient ID or Doctor ID does not exist!\n";
        return;
    }
    string date = getValidatedString("Enter Appointment Date: ");
    
    Appointment* newAppointment = new Appointment{id, patient_id, doctor_id, date, appointmentHead};
    appointmentHead = newAppointment;
    cout << "Appointment registered successfully!\n";
}

// Function to display all patients
void displayPatients() {
    Patient* temp = patientHead;
    if (!temp) {
        cout << "No patients registered.\n";
        return;
    }
    while (temp) {
        cout << "ID: " << temp->patient_id << " | Name: " << temp->name << " | DOB: " << temp->dob << " | Gender: " << temp->gender << "\n";
        temp = temp->next;
    }
}

// Function to display all doctors
void displayDoctors() {
    Doctor* temp = doctorHead;
    if (!temp) {
        cout << "No doctors registered.\n";
        return;
    }
    while (temp) {
        cout << "ID: " << temp->doctor_id << " | Name: " << temp->name << " | Specialization: " << temp->specialization << "\n";
        temp = temp->next;
    }
}

// Function to display all appointments
void displayAppointments() {
    Appointment* temp = appointmentHead;
    if (!temp) {
        cout << "No appointments registered.\n";
        return;
    }
    while (temp) {
        cout << "Appointment ID: " << temp->appointment_id << " | Patient ID: " << temp->patient_id << " | Doctor ID: " << temp->doctor_id << " | Date: " << temp->appointment_date << "\n";
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Register Patient\n";
        cout << "2. Register Doctor\n";
        cout << "3. Register Appointment\n";
        cout << "4. Display Patients\n";
        cout << "5. Display Doctors\n";
        cout << "6. Display Appointments\n";
        cout << "7. Exit\n";
        choice = getValidatedInt("Enter your choice: ");

        switch (choice) {
            case 1: registerPatient(); break;
            case 2: registerDoctor(); break;
            case 3: registerAppointment(); break;
            case 4: displayPatients(); break;
            case 5: displayDoctors(); break;
            case 6: displayAppointments(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}
