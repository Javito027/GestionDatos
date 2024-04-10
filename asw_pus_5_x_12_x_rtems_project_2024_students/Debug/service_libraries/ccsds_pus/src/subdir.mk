################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../service_libraries/ccsds_pus/src/ccsds_pus_format.c 

C_DEPS += \
./service_libraries/ccsds_pus/src/ccsds_pus_format.d 

OBJS += \
./service_libraries/ccsds_pus/src/ccsds_pus_format.o 


# Each subdirectory must supply rules for building sources it contributes
service_libraries/ccsds_pus/src/%.o: ../service_libraries/ccsds_pus/src/%.c service_libraries/ccsds_pus/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	sparc-rtems-gcc -std=c99 -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/asw/edroom_glue/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/service_libraries/crc/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/asw/dataclasses/CDTMHandler/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/llsw/emu_gss/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/service_libraries/ccsds_pus/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/llsw/tmtc_dyn_mem/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/service_libraries/serialize/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/llsw/config/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/llsw/emu_sc_channel_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/llsw/sc_channel_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_5_x_12_x_rtems_project_2024_resuelto/llsw/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-service_libraries-2f-ccsds_pus-2f-src

clean-service_libraries-2f-ccsds_pus-2f-src:
	-$(RM) ./service_libraries/ccsds_pus/src/ccsds_pus_format.d ./service_libraries/ccsds_pus/src/ccsds_pus_format.o

.PHONY: clean-service_libraries-2f-ccsds_pus-2f-src

