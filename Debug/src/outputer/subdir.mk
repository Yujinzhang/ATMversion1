################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/outputer/Outputer.cpp 

OBJS += \
./src/outputer/Outputer.o 

CPP_DEPS += \
./src/outputer/Outputer.d 


# Each subdirectory must supply rules for building sources it contributes
src/outputer/%.o: ../src/outputer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\cygwin\usr\local\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


