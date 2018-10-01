#!/bin/bash

# location of OpenOCD Board .cfg files
OPENOCD_BOARD_DIR=$HOME/Embedded/share/openocd/scripts/board

# start xterm with opencd in the background
xterm -e openocd -f $OPENOCD_BOARD_DIR/ek-lm4f120xl.cfg &

# save he PID of the background process
XTERM_PID=$!

# wait a bit to be sure the hardware is ready
sleep 2

# execute some initialisation commands via gdb
arm-none-eabi-gdb --batch --command=init.gdb build/a.out

# start the gdb gui
nemiver --remote=localhost:3333 --gdb-binary="$(which arm-none-eabi-gdb)" build/a.out

# clone xterm when the user has exited nemiver
kill $XTERM_PID

