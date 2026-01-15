#include "database.hpp"
#include <iostream>

void init_database(pqxx::connection& c) {
    pqxx::work tx(c);

    tx.exec(R"(
        CREATE TABLE IF NOT EXISTS students(
            id SERIAL PRIMARY KEY,
            student_id VARCHAR(20) UNIQUE NOT NULL,
            name VARCHAR(50) NOT NULL,
            surname VARCHAR(50) NOT NULL,
            department VARCHAR(80),
            email VARCHAR(120)
        )
    )");

    tx.commit();
}

void insert_sample_student(pqxx::connection& c) {
    pqxx::work tx(c);

    tx.exec_params(
        "INSERT INTO students(student_id, name, surname, department, email) "
        "VALUES ($1,$2,$3,$4,$5) ON CONFLICT (student_id) DO NOTHING",
        "220304017", "Emirhan", "Tekin", "Computer Engineering", "emirhan@example.com"
    );

    tx.commit();
}
// =======================
// READ – Öğrencileri Listele
// =======================
void list_students(pqxx::connection& c) {
    pqxx::work tx(c);

    pqxx::result r = tx.exec(
        "SELECT student_id, name, surname, department, email FROM students ORDER BY id"
    );

    tx.commit();

    std::cout << "\n--- STUDENT LIST ---\n";

    if (r.empty()) {
        std::cout << "No records found.\n";
        return;
    }

    for (const auto& row : r) {
        std::cout
            << "Student ID: " << row["student_id"].c_str()
            << " | Name: " << row["name"].c_str()
            << " " << row["surname"].c_str()
            << " | Department: "
            << (row["department"].is_null() ? "-" : row["department"].c_str())
            << " | Email: "
            << (row["email"].is_null() ? "-" : row["email"].c_str())
            << "\n";
    }
}

// =======================
// UPDATE – Email Güncelle
// =======================
bool update_student_email(
    pqxx::connection& c,
    const std::string& student_id,
    const std::string& new_email
) {
    pqxx::work tx(c);

    pqxx::result r = tx.exec_params(
        "UPDATE students SET email = $1 WHERE student_id = $2",
        new_email,
        student_id
    );

    tx.commit();

    if (r.affected_rows() == 0) {
        std::cout << "Update failed: student not found.\n";
        return false;
    }

    std::cout << "Email updated successfully.\n";
    return true;
}

// =======================
// DELETE – Öğrenci Sil
// =======================
bool delete_student(
    pqxx::connection& c,
    const std::string& student_id
) {
    pqxx::work tx(c);

    pqxx::result r = tx.exec_params(
        "DELETE FROM students WHERE student_id = $1",
        student_id
    );

    tx.commit();

    if (r.affected_rows() == 0) {
        std::cout << "Delete failed: student not found.\n";
        return false;
    }

    std::cout << "Student deleted successfully.\n";
    return true;
}

