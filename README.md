# Digital-System-Design---Final-Project

- An implementation of an embedded system on an Altera Cyclone IV FPGA using a NIOS II processor.

## Instructions on cloning the project, building hardware and software, and flashing the Altera board.

1. Clone the git repo (in the desired directory):
   ```shell
      git clone https://github.com/Gonzaga-2024-CPEN-Projects/NIOSII_Project_CPEN_430.git
   ```
2. Navigate to the repo: `NIOSII_Project_CPEN_430`.
3. Right click `chip.qpf` and "open with" Quartus.

### To build and flash the hardware:

5. You should not have to run a .tcl script In Quartus, the pin assignments are saved in the .qsf file, but if you get errors for some reason: Select `tools>Tcl Scripts`, then select `chip.tcl` and click `run`.
6. Compile the hardware project in Quartus.
7. Once the build is complete, select `tools>programmer`. After selecting the correct hardware, select `output_files/chip.sof` and flash the hardware.

### To build and flash the software:
1. Select `tools>Nios II Software Build Tools For Eclipse`.
2. Choose `{path to project}/NIOSII_Project_CPEN_430\software` as the software workspace.
3. In the project explorer you should see `blinky-sw` and `blinky-sw_bsp`. Right click `blinky-sw_bsp`. Select `Nios II>Generate BSP`.
4. Once that has finished, right click `blinky-sw_bsp` again, and select `Build Project`.
5. Right click `blinky-sw` and click `Build Project`.
6. Right click `blinky-sw` and click `Run As>Run Configurations`. Double click `blinky-sw Nios II Hardware configuration` under `Nios II Hardware` in the navigation pane on the left.
7. This should flash the software, and you are now able to play the game.

Note:
- If you open Eclipse and there doesn't appear to be any project, right click in the project explorer and select Import>General>Existing Projects into Workspace.
