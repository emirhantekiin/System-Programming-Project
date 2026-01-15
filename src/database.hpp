#pragma once
#include <pqxx/pqxx>

void init_database(pqxx::connection& c);
void insert_sample_student(pqxx::connection& c);
