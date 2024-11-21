import ctypes
from ctypes import c_void_p, c_float, c_uint8, c_bool

# Load the shared library
lib = ctypes.CDLL('./libms5837.so')

# Define function argument and return types

# Constructor and Destructor
lib.MS5837_new.restype = c_void_p
lib.MS5837_delete.argtypes = [c_void_p]
lib.MS5837_delete.restype = None

# init
lib.MS5837_init.argtypes = [c_void_p]
lib.MS5837_init.restype = c_bool

# begin
lib.MS5837_begin.argtypes = [c_void_p]
lib.MS5837_begin.restype = c_bool

# setModel
lib.MS5837_setModel.argtypes = [c_void_p, c_uint8]
lib.MS5837_setModel.restype = None

# getModel
lib.MS5837_getModel.argtypes = [c_void_p]
lib.MS5837_getModel.restype = c_uint8

# setFluidDensity
lib.MS5837_setFluidDensity.argtypes = [c_void_p, c_float]
lib.MS5837_setFluidDensity.restype = None

# read
lib.MS5837_read.argtypes = [c_void_p]
lib.MS5837_read.restype = None

# pressure
lib.MS5837_pressure.argtypes = [c_void_p, c_float]
lib.MS5837_pressure.restype = c_float

# temperature
lib.MS5837_temperature.argtypes = [c_void_p]
lib.MS5837_temperature.restype = c_float

# depth
lib.MS5837_depth.argtypes = [c_void_p]
lib.MS5837_depth.restype = c_float

# altitude
lib.MS5837_altitude.argtypes = [c_void_p]
lib.MS5837_altitude.restype = c_float

# Access static constants
lib.MS5837_get_Pa.restype = c_float
lib.MS5837_get_bar.restype = c_float
lib.MS5837_get_mbar.restype = c_float
lib.MS5837_get_MS5837_30BA.restype = c_uint8
lib.MS5837_get_MS5837_02BA.restype = c_uint8
lib.MS5837_get_MS5837_UNRECOGNISED.restype = c_uint8

# Create an instance of MS5837
sensor = lib.MS5837_new()

# Initialize the sensor
if not lib.MS5837_init(sensor):
    print("Sensor initialization failed!")
else:
    print("Sensor initialized successfully!")

# Set the model (e.g., MS5837_30BA)
model_30BA = lib.MS5837_get_MS5837_30BA() # may explode, accessing constant
lib.MS5837_setModel(sensor, model_30BA)

# Set fluid density (e.g., for freshwater)
lib.MS5837_setFluidDensity(sensor, 997.0) 

# Read sensor data
lib.MS5837_read(sensor)

# Get pressure and temperature
pressure = lib.MS5837_pressure(sensor, 1.0)  # Conversion factor of 1.0
temperature = lib.MS5837_temperature(sensor)

print(f"Pressure: {pressure} mbar")
print(f"Temperature: {temperature} °C")

# Get depth and altitude
depth = lib.MS5837_depth(sensor)
altitude = lib.MS5837_altitude(sensor)

print(f"Depth: {depth} meters")
print(f"Altitude: {altitude} meters")

# Clean up
lib.MS5837_delete(sensor)
