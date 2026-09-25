#include <iostream>
#include <vector>
#include <string>

// A class to represent a Patient
class Patient
{
public:
    // Constructor to initialize a Patient object
    Patient(int id, std::string name, int age)
        : patientId(id), patientName(name), patientAge(age) {}

    // Getter methods for patient details
    int getId() const { return patientId; }
    std::string getName() const { return patientName; }
    int getAge() const { return patientAge; }

    // Friend function to allow easy printing of Patient objects
    friend std::ostream &operator<<(std::ostream &os, const Patient &p)
    {
        os << "Patient ID: " << p.patientId
           << ", Name: " << p.patientName
           << ", Age: " << p.patientAge;
        return os;
    }

private:
    int patientId;
    std::string patientName;
    int patientAge;
};

// A class to represent a Doctor
class Doctor
{
public:
    // Constructor to initialize a Doctor object
    Doctor(int id, std::string name, std::string specialization)
        : doctorId(id), doctorName(name), doctorSpecialization(specialization) {}

    // Getter methods for doctor details
    int getId() const { return doctorId; }
    std::string getName() const { return doctorName; }
    std::string getSpecialization() const { return doctorSpecialization; }

    // Friend function to allow easy printing of Doctor objects
    friend std::ostream &operator<<(std::ostream &os, const Doctor &d)
    {
        os << "Doctor ID: " << d.doctorId
           << ", Name: " << d.doctorName
           << ", Specialization: " << d.doctorSpecialization;
        return os;
    }

private:
    int doctorId;
    std::string doctorName;
    std::string doctorSpecialization;
};

// A class to represent an Appointment
class Appointment
{
public:
    // Constructor to initialize an Appointment object
    Appointment(int apptId, int pId, int dId, std::string apptDate, std::string apptTime)
        : appointmentId(apptId), patientId(pId), doctorId(dId),
          appointmentDate(apptDate), appointmentTime(apptTime) {}

    // Getter methods for appointment details
    int getAppointmentId() const { return appointmentId; }
    int getPatientId() const { return patientId; }
    int getDoctorId() const { return doctorId; }
    std::string getAppointmentDate() const { return appointmentDate; }
    std::string getAppointmentTime() const { return appointmentTime; }

    // Friend function to allow easy printing of Appointment objects
    friend std::ostream &operator<<(std::ostream &os, const Appointment &a)
    {
        os << "Appointment ID: " << a.appointmentId
           << ", Patient ID: " << a.patientId
           << ", Doctor ID: " << a.doctorId
           << ", Date: " << a.appointmentDate
           << ", Time: " << a.appointmentTime;
        return os;
    }

private:
    int appointmentId;
    int patientId;
    int doctorId;
    std::string appointmentDate;
    std::string appointmentTime;
};

// A class to manage the entire system
class HospitalManagementSystem
{
public:
    // Method to add a new patient to the system
    void addPatient(int id, const std::string &name, int age)
    {
        // Check if a patient with the same ID already exists
        for (const auto &patient : patients)
        {
            if (patient.getId() == id)
            {
                std::cout << "Error: Patient with ID " << id << " already exists." << std::endl;
                return;
            }
        }
        patients.emplace_back(id, name, age);
        std::cout << "Patient added successfully!" << std::endl;
    }

    // Method to add a new doctor to the system
    void addDoctor(int id, const std::string &name, const std::string &specialization)
    {
        // Check if a doctor with the same ID already exists
        for (const auto &doctor : doctors)
        {
            if (doctor.getId() == id)
            {
                std::cout << "Error: Doctor with ID " << id << " already exists." << std::endl;
                return;
            }
        }
        doctors.emplace_back(id, name, specialization);
        std::cout << "Doctor added successfully!" << std::endl;
    }

    // Method to schedule a new appointment
    void scheduleAppointment(int apptId, int pId, int dId, const std::string &date, const std::string &time)
    {
        bool patientExists = false;
        for (const auto &p : patients)
        {
            if (p.getId() == pId)
            {
                patientExists = true;
                break;
            }
        }
        if (!patientExists)
        {
            std::cout << "Error: Patient with ID " << pId << " not found." << std::endl;
            return;
        }

        bool doctorExists = false;
        for (const auto &d : doctors)
        {
            if (d.getId() == dId)
            {
                doctorExists = true;
                break;
            }
        }
        if (!doctorExists)
        {
            std::cout << "Error: Doctor with ID " << dId << " not found." << std::endl;
            return;
        }

        // Check for existing appointment with the same ID
        for (const auto &appt : appointments)
        {
            if (appt.getAppointmentId() == apptId)
            {
                std::cout << "Error: Appointment with ID " << apptId << " already exists." << std::endl;
                return;
            }
        }

        appointments.emplace_back(apptId, pId, dId, date, time);
        std::cout << "Appointment scheduled successfully!" << std::endl;
    }

    // Method to display all patients in the system
    void viewAllPatients() const
    {
        std::cout << "\n--- All Patients ---" << std::endl;
        if (patients.empty())
        {
            std::cout << "No patients registered." << std::endl;
        }
        else
        {
            for (const auto &patient : patients)
            {
                std::cout << patient << std::endl;
            }
        }
        std::cout << "--------------------" << std::endl;
    }

    // Method to display all doctors in the system
    void viewAllDoctors() const
    {
        std::cout << "\n--- All Doctors ---" << std::endl;
        if (doctors.empty())
        {
            std::cout << "No doctors registered." << std::endl;
        }
        else
        {
            for (const auto &doctor : doctors)
            {
                std::cout << doctor << std::endl;
            }
        }
        std::cout << "-------------------" << std::endl;
    }

    // Method to view appointments for a specific doctor
    void viewDoctorAppointments(int doctorId) const
    {
        std::cout << "\n--- Appointments for Doctor ID " << doctorId << " ---" << std::endl;
        bool found = false;
        for (const auto &appt : appointments)
        {
            if (appt.getDoctorId() == doctorId)
            {
                std::cout << appt << std::endl;
                found = true;
            }
        }
        if (!found)
        {
            std::cout << "No appointments found for this doctor." << std::endl;
        }
        std::cout << "-----------------------------------------------" << std::endl;
    }

private:
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Appointment> appointments;
};

// Main function to run the application
int main()
{
    HospitalManagementSystem hms;
    int choice;

    // Sample data to start with
    hms.addDoctor(101, "Dr. Smith", "Cardiology");
    hms.addDoctor(102, "Dr. Jones", "Neurology");
    hms.addPatient(1, "Alice Johnson", 35);
    hms.addPatient(2, "Bob Williams", 50);

    // Main menu loop
    do
    {
        std::cout << "\n--- Hospital Management System Menu ---" << std::endl;
        std::cout << "1. Add a new Patient" << std::endl;
        std::cout << "2. Add a new Doctor" << std::endl;
        std::cout << "3. Schedule an Appointment" << std::endl;
        std::cout << "4. View All Patients" << std::endl;
        std::cout << "5. View All Doctors" << std::endl;
        std::cout << "6. View Doctor's Appointments" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id, age;
            std::string name;
            std::cout << "Enter Patient ID: ";
            std::cin >> id;
            std::cin.ignore(); // Clear newline from buffer
            std::cout << "Enter Patient Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Patient Age: ";
            std::cin >> age;
            hms.addPatient(id, name, age);
            break;
        }
        case 2:
        {
            int id;
            std::string name, specialization;
            std::cout << "Enter Doctor ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter Doctor Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Specialization: ";
            std::getline(std::cin, specialization);
            hms.addDoctor(id, name, specialization);
            break;
        }
        case 3:
        {
            int apptId, pId, dId;
            std::string date, time;
            std::cout << "Enter Appointment ID: ";
            std::cin >> apptId;
            std::cout << "Enter Patient ID: ";
            std::cin >> pId;
            std::cout << "Enter Doctor ID: ";
            std::cin >> dId;
            std::cin.ignore();
            std::cout << "Enter Appointment Date (e.g., YYYY-MM-DD): ";
            std::getline(std::cin, date);
            std::cout << "Enter Appointment Time (e.g., HH:MM): ";
            std::getline(std::cin, time);
            hms.scheduleAppointment(apptId, pId, dId, date, time);
            break;
        }
        case 4:
            hms.viewAllPatients();
            break;
        case 5:
            hms.viewAllDoctors();
            break;
        case 6:
        {
            int doctorId;
            std::cout << "Enter Doctor ID to view appointments: ";
            std::cin >> doctorId;
            hms.viewDoctorAppointments(doctorId);
            break;
        }
        case 7:
            std::cout << "Exiting system. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 7);

    return 0;
}
