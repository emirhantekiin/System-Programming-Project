#include <iostream>
#include <pqxx/pqxx>

int main() {
    // =========================
    // WEEK 2 - Docker Test
    // =========================
    std::cout << "SIS Docker Week 2 OK" << std::endl;

    // =========================
    // WEEK 3 - PostgreSQL Integration
    // =========================
    try {
        std::cout << "Connecting to PostgreSQL..." << std::endl;

        // Docker Compose içinden bağlanırken
        // host = servis adı (db)
        pqxx::connection conn(
            "host=db "
            "port=5432 "
            "dbname=sis_user "
            "user=sis_user "
            "password=sis_pass"
        );

        if (conn.is_open()) {
            std::cout << "DB connection OK" << std::endl;
            std::cout << "Connected to database: "
                      << conn.dbname() << std::endl;
        } else {
            std::cerr << "DB connection failed" << std::endl;
            return 1;
        }

        // Basit SELECT testi
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT * FROM students;");

        std::cout << "\nStudents table content:\n";
        for (const auto &row : r) {
            std::cout
                << "ID: " << row["id"].as<int>() << ", "
                << "Student No: " << row["student_no"].c_str() << ", "
                << "Name: " << row["name"].c_str() << ", "
                << "Surname: " << row["surname"].c_str() << ", "
                << "Department: " << row["department"].c_str() << ", "
                << "Email: " << row["email"].c_str()
                << std::endl;
        }

        txn.commit();
        conn.disconnect();
    }
    catch (const std::exception &e) {
        std::cerr << "PostgreSQL error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
