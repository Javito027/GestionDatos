################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../service_libraries/edroomsl/edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.cpp 

CPP_DEPS += \
./service_libraries/edroomsl/edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.d 

OBJS += \
./service_libraries/edroomsl/edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.o 


# Each subdirectory must supply rules for building sources it contributes
service_libraries/edroomsl/edroombp/src/rtemsapi_4_6/rtems_4_6/%.o: ../service_libraries/edroomsl/edroombp/src/rtemsapi_4_6/rtems_4_6/%.cpp service_libraries/edroomsl/edroombp/src/rtemsapi_4_6/rtems_4_6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/llsw/config/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/llsw/emu_hw_timecode_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/service_libraries/crc/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/dataclasses/CDTMHandler/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/llsw/emu_gss/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/service_libraries/ccsds_pus/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/llsw/tmtc_dyn_mem/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/service_libraries/serialize/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/components/cchk_fdirmng/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/components/ccbkgtcexec/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/components/ccepdmanager/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/components/cctm_channelctrl/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/components/icuasw/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/edroom_glue/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/service_libraries/edroomsl/edroombp/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/service_libraries/edroomsl/edroomsl/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/service_libraries/edroomsl/edroomsl_types/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/llsw/rtems_osswr/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/dataclasses/CDEventList/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/dataclasses/CDEvAction/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/dataclasses/CDTCHandler/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/asw/dataclasses/CDTMList/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/service_libraries/icuasw_pus_services/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/llsw/sc_channel_drv/include" -I"/home/opolo70/OBDH-workspace/asw_pus_19_x_rtems_project_2024_resuelto/llsw/emu_sc_channel_drv/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-service_libraries-2f-edroomsl-2f-edroombp-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6

clean-service_libraries-2f-edroomsl-2f-edroombp-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6:
	-$(RM) ./service_libraries/edroomsl/edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.d ./service_libraries/edroomsl/edroombp/src/rtemsapi_4_6/rtems_4_6/edroombp.o

.PHONY: clean-service_libraries-2f-edroomsl-2f-edroombp-2f-src-2f-rtemsapi_4_6-2f-rtems_4_6

