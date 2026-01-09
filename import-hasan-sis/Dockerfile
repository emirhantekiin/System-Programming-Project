FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    g++ cmake make libpqxx-dev

WORKDIR /app
COPY . .

RUN cmake -S . -B build && cmake --build build
CMD ["./build/sis_app"]
