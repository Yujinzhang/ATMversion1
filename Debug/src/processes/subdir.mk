################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/processes/ChtProp.cpp \
../src/processes/Dlist.cpp \
../src/processes/IOdata.cpp \
../src/processes/Predisposition.cpp \
../src/processes/ProcCht.cpp \
../src/processes/Runner.cpp \
../src/processes/Thermokarst.cpp 

OBJS += \
./src/processes/ChtProp.o \
./src/processes/Dlist.o \
./src/processes/IOdata.o \
./src/processes/Predisposition.o \
./src/processes/ProcCht.o \
./src/processes/Runner.o \
./src/processes/Thermokarst.o 

CPP_DEPS += \
./src/processes/ChtProp.d \
./src/processes/Dlist.d \
./src/processes/IOdata.d \
./src/processes/Predisposition.d \
./src/processes/ProcCht.d \
./src/processes/Runner.d \
./src/processes/Thermokarst.d 


# Each subdirectory must supply rules for building sources it contributes
src/processes/%.o: ../src/processes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\cygwin\usr\local\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


