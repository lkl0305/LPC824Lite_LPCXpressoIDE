################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../delay/delay.c 

OBJS += \
./delay/delay.o 

C_DEPS += \
./delay/delay.d 


# Each subdirectory must supply rules for building sources it contributes
delay/%.o: ../delay/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__USE_LPCOPEN -D__LPC82X__ -D__REDLIB__ -I"D:\Board\LPC824Lite\workspace\lpc_board_ucdrogon_lpc824lite\inc" -I"D:\Board\LPC824Lite\workspace\usart0_test" -I"D:\Board\LPC824Lite\workspace\lpc_chip_82x\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


