FROM ubuntu:22.04

# Install build tools and PostgreSQL dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    libpqxx-dev \
    postgresql-client \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

# Build the C++ application
RUN cmake -S . -B build && cmake --build build

CMD ["./build/sis_app"]
