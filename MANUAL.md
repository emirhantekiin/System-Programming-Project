# User Manual

This document explains how to use the Student Information System application.

---

## Overview

The Student Information System is a command-line based C++ application that allows users to manage student records stored in a PostgreSQL database.  
The application runs inside a Docker container and communicates with the database container using Docker Compose.

---

## Starting the System

To start the system, run the following command in the project root directory:

```bash
docker compose up
---

## Application Usage

When the application starts, a menu is displayed that allows the user to:

- Add a new student record
- List all students
- Update an existing student
- Delete a student record
- Exit the application
---

## Data Persistence

All student records are stored in a PostgreSQL database using Docker volumes.
Data remains persistent after stopping or restarting the containers.
