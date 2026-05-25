#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <string>

// EXCEPCIONES PERSONALIZADAS
class DivisionByZeroException : public std::runtime_error {
public:
	DivisionByZeroException()
		: std::runtime_error("Error: División entre cero.") {}
};

class NegativeValueException : public std::runtime_error {
public:
	NegativeValueException()
		: std::runtime_error("Error: Valor negativo detectado.") {}
};

class InvalidInputException : public std::runtime_error {
public:
	InvalidInputException()
		: std::runtime_error("Error: Entrada no numérica.") {}
};

// LOGGER
class Logger {
private:
	std::ofstream logfile;

public:
	Logger(const std::string& filename) {
		logfile.open(filename, std::ios::app);
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
		// Elimina el salto de línea de ctime()
		fecha.pop_back();
		logfile << "[" << fecha << "] "
		        << message << std::endl;
	}
};

// FUNCIÓN DIVIDIR
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

// FUNCIÓN PARA VALIDAR TEXTO
void validarEntrada(const std::string& texto) {
	bool esNumero = true;
	for (char c : texto) {
		if (!isdigit(c) && c != '.') {
			esNumero = false;
			break;
		}
	}
	if (!esNumero) {
		throw InvalidInputException();
	}
}

int main() {

	Logger logger("system.log");

	// PRUEBA 1
	try {
		std::cout << "Prueba 1 -> 10 / 2"
		          << std::endl;
		double resultado = dividir(10, 2);
		std::cout << "Resultado: "
		          << resultado
		          << std::endl;
		logger.log("10 / 2 ejecutado correctamente.");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		logger.log(ex.what());
	}
	std::cout << std::endl;

	// PRUEBA 2
	try {

		std::cout << "Prueba 2 -> 10 / 0"
		          << std::endl;
		double resultado = dividir(10, 0);
		std::cout << "Resultado: "
		          << resultado
		          << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		logger.log(ex.what());
	}
	std::cout << std::endl;

	// PRUEBA 3
	try {
		std::cout << "Prueba 3 -> -8 / 2"
		          << std::endl;
		double resultado = dividir(-8, 2);
		std::cout << "Resultado: "
		          << resultado
		          << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		logger.log(ex.what());
	}
	std::cout << std::endl;

	// PRUEBA 4
	try {
		std::cout << "Prueba 4 -> 20 / 5"
		          << std::endl;
		double resultado = dividir(20, 5);
		std::cout << "Resultado: "
		          << resultado
		          << std::endl;
		logger.log("20 / 5 ejecutado correctamente.");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		logger.log(ex.what());
	}
	std::cout << std::endl;
	logger.log("Programa finalizado.");

	return 0;
}
