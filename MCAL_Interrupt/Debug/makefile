################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
INTRR_MCAL.lss \

FLASH_IMAGE += \
INTRR_MCAL.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: INTRR_MCAL.elf secondary-outputs

# Tool invocations
INTRR_MCAL.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,INTRR_MCAL.map -mmcu=atmega32 -o "INTRR_MCAL.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

INTRR_MCAL.lss: INTRR_MCAL.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S INTRR_MCAL.elf  >"INTRR_MCAL.lss"
	@echo 'Finished building: $@'
	@echo ' '

INTRR_MCAL.hex: INTRR_MCAL.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex INTRR_MCAL.elf  "INTRR_MCAL.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: INTRR_MCAL.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 INTRR_MCAL.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) INTRR_MCAL.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
