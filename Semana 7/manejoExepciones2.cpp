#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <string>

class DivisionByZeroException : public std::runtime_error {
public:
    DivisionByZeroException()
        : std::runtime_error(
            "Error: División entre cero."
        ) {}
};

class NegativeValueException : public std::runtime_error {
public:
    NegativeValueException()
        : std::runtime_error(
            "Error: Valor negativo detectado."
        ) {}
};

class Logger {
private:
    std::ofstream logfile;

public:
    Logger(const std::string& filename) {
        logfile.open(
            filename,
            std::ios::app
        );
        if (!logfile.is_open()) {
            throw std::runtime_error(
                "No se pudo abrir el archivo log."
            );
        }
    }
    ~Logger() {
        if (logfile.is_open()) {
            logfile.close();
        }
    }
    void log(const std::string& message) {
        time_t now = time(0);
        std::string fecha = ctime(&now);
        // Elimina el salto de línea
        fecha.pop_back();
        logfile << "[" << fecha << "] "
                << message
                << std::endl;
    }
};

double dividir(double a, double b) {
    // División entre cero
    if (b == 0) {
        throw DivisionByZeroException();
    }
    // Valores negativos
    if (a < 0 || b < 0) {
        throw NegativeValueException();
    }
    return a / b;
}

int main() {

    Logger logger("system.log");

    // Lista de divisiones
    double numeradores[] = {10, 20, -5, 30, 100};
    double denominadores[] = {2, 0, 5, -3, 4};
    int total = 5;
    
    std::cout << "===== MONITOREO EN TIEMPO REAL ====="
              << std::endl << std::endl;

    // Ciclo de monitoreo
    for (int i = 0; i < total; i++) {
        try {
            std::cout << "Operacion "
                      << (i + 1)
                      << " -> "
                      << numeradores[i]
                      << " / "
                      << denominadores[i]
                      << std::endl;

            double resultado = dividir(
                numeradores[i],
                denominadores[i]
            );
            std::cout << "Resultado: "
                      << resultado
                      << std::endl;
            logger.log(
                "Operacion correcta: " +
                std::to_string(numeradores[i]) +
                " / " +
                std::to_string(denominadores[i]) +
                " = " +
                std::to_string(resultado)
            );
        }

        // División entre cero
        catch (const DivisionByZeroException& ex) {
            std::cerr << ex.what()
                      << std::endl;
            logger.log(
                std::string("ERROR -> ") +
                ex.what()
            );
        }

        // Valores negativos
        catch (const NegativeValueException& ex) {
            std::cerr << ex.what()
                      << std::endl;
            logger.log(
                std::string("ERROR -> ") +
                ex.what()
            );
        }

        // Cualquier otra excepción
        catch (const std::exception& ex) {
            std::cerr << "Excepcion general: "
                      << ex.what()
                      << std::endl;
            logger.log(
                std::string("Excepcion general: ") +
                ex.what()
            );
        }
        std::cout << "-----------------------------"
                  << std::endl;
    }
    logger.log("Monitoreo finalizado.");
    std::cout << std::endl
              << "Revisa el archivo system.log"
              << " para los registros."
              << std::endl;

    return 0;
}
