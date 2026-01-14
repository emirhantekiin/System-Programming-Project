FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install build tools + PostgreSQL deps
RUN apt-get update && apt-get install -y --no-install-recommends \
    g++ \
    cmake \
    make \
    libpqxx-dev \
    libpq-dev \
    postgresql-client \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy project files
COPY . .

# Configure + build
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build -j

# Run the application
CMD ["./build/sis_app"]
