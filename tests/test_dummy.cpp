#include <iostream>
#include <cstdlib>      // getenv
#include <pqxx/pqxx>

static std::string getEnvOrDefault(const char* key, const std::string& defVal) {
    const char* v = std::getenv(key);
    return (v && *v) ? std::string(v) : defVal;
}

int main() {
    try {
        // Docker compose içinden bağlanıyorsan host genelde servis adı olur: db veya postgres
        // Projende hangisi kullanılıyorsa ona göre default verdim.
        std::string host = getEnvOrDefault("DB_HOST", "db");
        std::string port = getEnvOrDefault("DB_PORT", "5432");
        std::string dbname = getEnvOrDefault("DB_NAME", "sis");
        std::string user = getEnvOrDefault("DB_USER", "sis_user");
        std::string pass = getEnvOrDefault("DB_PASSWORD", "sis_pass");

        std::cout << "[TEST] Connecting to PostgreSQL...\n";
        std::cout << "[TEST] host=" << host << " port=" << port
                  << " dbname=" << dbname << " user=" << user << "\n";

        std::string connStr =
            "host=" + host + " " +
            "port=" + port + " " +
            "dbname=" + dbname + " " +
            "user=" + user + " " +
            "password=" + pass;

        pqxx::connection conn(connStr);

        if (!conn.is_open()) {
            std::cerr << "[TEST] FAIL: DB connection could not be opened.\n";
            return 1;
        }

        std::cout << "[TEST] PASS: DB connection OK. Connected to: " << conn.dbname() << "\n";

        // Basit sağlık kontrolü
        pqxx::work txn(conn);

        // 1) DB cevap veriyor mu?
        pqxx::result r1 = txn.exec("SELECT 1;");
        if (r1.empty() || r1[0][0].as<int>() != 1) {
            std::cerr << "[TEST] FAIL: SELECT 1 did not return expected result.\n";
            return 2;
        }
        std::cout << "[TEST] PASS: SELECT 1 OK.\n";

        // 2) students tablosu var mı? (yoksa test FAIL yapmayalım, WARN diyelim)
        // Çünkü bazı haftalarda init.sql daha eklenmemiş olabilir.
        pqxx::result r2 = txn.exec(
            "SELECT EXISTS ("
            "  SELECT 1 FROM information_schema.tables "
            "  WHERE table_schema='public' AND table_name='students'"
            ");"
        );

        bool hasStudents = (!r2.empty() && r2[0][0].as<bool>() == true);
        if (!hasStudents) {
            std::cout << "[TEST] WARN: 'students' table not found. (init.sql ekli değilse normal)\n";
            txn.commit();
            conn.disconnect();
            std::cout << "[TEST] DONE.\n";
            return 0; // sadece bağlantı testi geçmiş olsun
        }

        std::cout << "[TEST] PASS: 'students' table exists.\n";

        // 3) students tablosunda kaç kayıt var?
        pqxx::result r3 = txn.exec("SELECT COUNT(*) FROM students;");
        long long count = r3[0][0].as<long long>();
        std::cout << "[TEST] INFO: students row count = " << count << "\n";

        txn.commit();
        conn.disconnect();

        std::cout << "[TEST] ALL PASSED.\n";
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "[TEST] FAIL: Exception: " << e.what() << "\n";
        return 99;
    }
}
