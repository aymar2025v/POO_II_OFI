class Time:
    def __init__(self, hour=0, minute=0, second=0):
        self._hour = hour
        self._minute = minute
        self._second = second
        self._validate()

    def _validate(self):
        """Asegura que los valores estén en rango."""
        if not (0 <= self._hour < 24):
            self._hour = 0
        if not (0 <= self._minute < 60):
            self._minute = 0
        if not (0 <= self._second < 60):
            self._second = 0

    # Propiedades de solo lectura (getters)
    @property
    def hour(self):
        return self._hour

    @property
    def minute(self):
        return self._minute

    @property
    def second(self):
        return self._second

    # Setters (opcionales, para objetos modificables)
    @hour.setter
    def hour(self, value):
        self._hour = value
        self._validate()

    @minute.setter
    def minute(self, value):
        self._minute = value
        self._validate()

    @second.setter
    def second(self, value):
        self._second = value
        self._validate()

    def set_time(self, h, m, s):
        self.hour = h
        self.minute = m
        self.second = s

    def print_military(self):
        print(f"{self.hour:02d}:{self.minute:02d}:{self.second:02d}")

    def print_standard(self):
        h = self.hour % 12
        if h == 0:
            h = 12
        ampm = "AM" if self.hour < 12 else "PM"
        print(f"{h}:{self.minute:02d}:{self.second:02d} {ampm}")

# --- Objeto modificable (normal) ---
t1 = Time(10, 30, 45)
t1.print_military()          # 10:30:45
t1.hour = 14                 # Usa el setter
t1.print_military()          # 14:30:45

# --- Simulación de objeto constante (sin setters) ---
class ConstTime:
    """Versión de solo lectura: no se definen setters."""
    def __init__(self, hour, minute, second):
        self._hour = hour
        self._minute = minute
        self._second = second
        # No hay validación automática; podríamos hacerla en __init__

    @property
    def hour(self):
        return self._hour

    @property
    def minute(self):
        return self._minute

    @property
    def second(self):
        return self._second

    def print_military(self):
        print(f"{self.hour:02d}:{self.minute:02d}:{self.second:02d}")

    def print_standard(self):
        h = self.hour % 12
        if h == 0:
            h = 12
        ampm = "AM" if self.hour < 12 else "PM"
        print(f"{h}:{self.minute:02d}:{self.second:02d} {ampm}")

# --- Prueba del objeto constante simulado ---
t2 = ConstTime(23, 59, 58)
print(f"t2 hour (propiedad): {t2.hour}")   # 23
t2.print_military()                         # 23:59:58

# Intentar modificar genera un AttributeError porque no hay setter
try:
    t2.hour = 22
except AttributeError as e:
    print(f"Error (esperado): {e}")   # can't set attribute

# Nota: Aún se podría accerder a t2._hour directamente (convención de privacidad),
# pero el lenguaje no lo impide. La simulación es solo por convención.
