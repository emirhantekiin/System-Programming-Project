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

# Week 2 – Docker Setup and Containerization Report

## Objective
The objective of Week 2 was to introduce Docker technology into the project and prepare the system for container-based development. The focus was on creating the Docker environment, configuring Dockerfiles, and understanding container behavior.

---

## Work Completed
During Week 2, the following tasks were completed:

- Docker was installed and configured on the development environment.
- A Dockerfile was created for the C++ application.
- The base operating system image (Ubuntu) was selected.
- Required build tools were installed inside the container:
  - g++
  - make
  - cmake
- The C++ application was successfully compiled inside the Docker container.
- Basic container lifecycle commands were tested (`build`, `run`, `stop`).

---

## Dockerfile Configuration
A Dockerfile was prepared to containerize the C++ application.  
The Dockerfile defines:

- The base image
- Required build dependencies
- Build steps for the C++ project
- The default command executed when the container starts

This ensured that the application could be built and run consistently across different environments.

---

## Container Execution Test
The Docker image was built and executed successfully using the following commands:

```bash
docker build -t sis-app .
docker run sis-app

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
## Week 4 – Application and Database Integration Report

### Objective
The objective of Week 4 was to complete the full integration between the C++ application and the PostgreSQL database and to verify that the system works correctly as a complete containerized application.

---

### System Architecture
The system consists of two Docker containers managed using Docker Compose:

- **PostgreSQL Database Container**  
  Responsible for storing student information and initializing the database using an `init.sql` script.

- **C++ Application Container**  
  A command-line application that connects to the PostgreSQL database using the `libpqxx` library and executes SQL queries.

The containers communicate over Docker’s internal network using the service name `db`.

---

### Database Initialization
The PostgreSQL database is automatically initialized during the first startup of the container.  
The `init.sql` script performs the following operations:

- Creates the `students` table
- Inserts sample student data

This ensures that the database schema and initial records are available without any manual setup.

---

### Application–Database Connection
The C++ application establishes a connection to the PostgreSQL database using the following configuration:

- Host: `db`
- Port: `5432`
- Database name: `sis_user`
- User: `sis_user`

The successful connection is confirmed by log messages printed to the console from the application container.

---

### Data Retrieval Test
After establishing the connection, the application executes the following SQL query:

```sql
SELECT * FROM students;
```
## CRUD Operations Demonstration
In addition to data retrieval, basic CRUD-related operations were demonstrated to validate database interaction capabilities.

- **Insert Operation:**  
  A new test student record was inserted into the PostgreSQL database using an SQL `INSERT` command executed from the C++ application.

- **Delete Operation:**  
  The inserted test record was removed from the database using an SQL `DELETE` command.

These operations confirm that the application can both read from and write to the database.

---

## Error Handling and Validation
Basic error handling mechanisms were implemented in the C++ application using exception handling provided by the **libpqxx** library.

- Database connection errors are captured and printed to the console.
- SQL execution errors are handled gracefully.
- Connection status is verified before executing database operations.

This improves the robustness and stability of the system.

---

## Logging and Verification
System behavior was verified using Docker container logs and status checks.

Application logs were inspected using:
```bash
docker logs sis-app-v2
```

## Results
- PostgreSQL container started successfully and passed the health check.
- Database tables and sample data were created using the `init.sql` script.
- The C++ application connected to the PostgreSQL database without errors.
- Student records were successfully retrieved from the database.
- Basic insert and delete operations were executed and verified.

---

## Version Control and Collaboration
All Week 4 developments were carried out using a branch-based Git workflow.

- Feature branches were used during development.
- Pull Requests were created to merge changes into the `main` branch.
- Clear and descriptive commit messages were used.
- Code changes were reviewed before merging.

This workflow ensured traceability, collaboration, and code quality throughout the project.

---

## Conclusion
Week 4 successfully demonstrates a fully working containerized Student Information System.  
The integration between Docker, PostgreSQL, and the C++ application was completed, and database operations were verified through real-time application output.  
The system meets all Week 4 requirements and provides a solid foundation for further development.











