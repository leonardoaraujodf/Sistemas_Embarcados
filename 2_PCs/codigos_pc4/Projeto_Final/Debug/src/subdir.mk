################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Botao.cpp \
../src/Display.cpp \
../src/ProjetoFinal.cpp \
../src/main.cpp 

OBJS += \
./src/Botao.o \
./src/Display.o \
./src/ProjetoFinal.o \
./src/main.o 

CPP_DEPS += \
./src/Botao.d \
./src/Display.d \
./src/ProjetoFinal.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


