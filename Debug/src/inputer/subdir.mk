################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/inputer/ChtInputer.cpp 

OBJS += \
./src/inputer/ChtInputer.o 

CPP_DEPS += \
./src/inputer/ChtInputer.d 


# Each subdirectory must supply rules for building sources it contributes
src/inputer/%.o: ../src/inputer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\cygwin\usr\local\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


