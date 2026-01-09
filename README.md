# System Programming Project

## Overview
This project is developed as part of the System Programming course.
It is a simple Student Information System implemented using Docker technology.

The system runs as two separate containers: a C++ application container
and a PostgreSQL database container.

## Technologies Used
- C++
- PostgreSQL
- Docker
- Docker Compose
- GitHub

## System Structure
- PostgreSQL container is used to store student data.
- C++ command-line application connects to the database and performs operations.

## Functions
- Add student information
- List student records
- Update student data
- Delete student data

## Development Process
- Branch-based development strategy is used.
- All changes are made via Pull Requests.
- Code reviews are required before merging.

## Project Status
Initial setup phase.

---

## Week 3 – PostgreSQL Integration Report

### Objective
Integrate PostgreSQL into the Student Information System project using Docker Compose and prepare the C++ application environment for database connectivity.

### Work Completed
- PostgreSQL service was added using Docker Compose.
- Database credentials (DB name, user, password) were defined via environment variables.
- Persistent volume was configured for PostgreSQL data.
- Healthcheck was implemented using `pg_isready`.
- Application service was configured to wait for the database using `depends_on` with `service_healthy`.
- Dockerfile was updated to include:
  - g++
  - cmake
  - make
  - libpqxx-dev
  - postgresql-client
- A dummy PostgreSQL connection message was implemented in the C++ application.

### Dummy PostgreSQL Connection (C++)
The application simulates a PostgreSQL connection to verify Docker and dependency setup.

```cpp
std::cout << "Dummy PostgreSQL connection successful (Week 3)" << std::endl;
```















