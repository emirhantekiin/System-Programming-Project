INSTALLATION GUIDE

This document explains how to install and run the Student Information System (C++ + PostgreSQL) using Docker and Docker Compose.

REQUIREMENTS

You need the following tools installed:

Docker
Docker Compose
Git
Linux / Windows / macOS

INSTALLATION STEPS

Clone the repository

git clone https://github.com/emirhantekin/System-Programming-Project.git

cd System-Programming-Project

Build and run with Docker Compose

docker compose up --build

What this does:

Builds the C++ application inside a Docker container
Starts the PostgreSQL database container
Runs the application automatically

Verify output

If everything is working, you should see something similar to:
SIS Docker Week 2 OK
Connecting to PostgreSQL...
DB connection OK

This confirms:

Docker environment works
C++ application runs
PostgreSQL connection is established

STOPPING THE APPLICATION

To stop containers:

Press CTRL + C in the terminal where it is running

Then remove containers:
docker compose down

NOTES

PostgreSQL runs in a separate container.
Database data is persisted using Docker volumes.
You do not need to install PostgreSQL on your own computer.

TROUBLESHOOTING

If you get errors:

Make sure Docker Desktop / Docker service is running.

Try rebuilding without cache:
docker compose build --no-cache
docker compose up

If the app starts before DB is ready, restart:
docker compose down
docker compose up

AUTHOR

System Programming Course Project – Student Information System
