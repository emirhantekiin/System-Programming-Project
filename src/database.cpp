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
