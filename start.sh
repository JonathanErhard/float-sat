title1="Compile and flash"
title2="connect to rfcomm"
title3="setup the router"

RED='\033[0;31m'
PURPLE='\033[0;35m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

cur_path=$(pwd)

ARG1=${1: flash}
ARG2=${2: flash}

#'echo "$ARG1"'

set +e
cd "$(dirname "$0")" || exit 128

cmd1="set +e
/bin/bash generate.sh
cd build-discovery/generated/nodes/main-node
make main-node
cd ../../../..
/bin/bash quickflash.sh"
'cd build-corfu-host-tools/ground-tools/ground
./corfu-ground'

cmd15="cd build-corfu-host-tools/ground-tools/ground
./corfu-ground"

cmd2="set +e
rfkill -o DEVICE
sudo rfcomm connect /dev/rfcomm0 00:0E:EA:CF:7C:1D"

cmd3="
sudo chmod a+rw /dev/rfcomm0
cd build-corfu-host-tools/ground-tools/router
./router -L_IN UART -L_OUT UDP -IN_UART 2 -OUT_UDP_DOWN 8671 -OUT_UDP_UP 8672"

'cmd4="cd a_floatsat/float-sat/build-corfu-host-tools/ground-tools/ground
./corfu-ground"'
if [ "$1" != "-f" ];
then
    echo -e " ${PURPLE} compiling and flashing... ${NC} "
    gnome-terminal --tab --title="$title1" --command="bash -c '$cmd1; $SHELL'"
else
    echo -e "${GREEN} not flashing ${NC} "
fi
if [ "$1" != "-b" ];
then
    gnome-terminal --tab --title="$title1" --command="bash -c '$cmd15; $SHELL'"
    echo -e "${PURPLE} connecting to rfcomm ${NC} "
    echo -e "${RED} pls give your password ${NC} "
    gnome-terminal --tab --title="$title2" --command="bash -c '$cmd2; $SHELL'"
    echo -e "${PURPLE} connecting the router ${NC} "
    echo -e "${PURPLE} if there is an error during this you need to change the file path in start.sh in the specified location ${NC} "
    echo -e "${RED} pls give your password ${NC}"
    gnome-terminal --tab --title="$title3" --command="bash -c '$cmd3; $SHELL'"
else
    echo -e "${GREEN} not compiling ${NC} "
fi





#./corfu/scripts/build-corfu-from-project.sh 

#324  mkdir build-discovery
#325  cd build-discovery/
#326  cmake -DCMAKE_TOOLCHAIN_FILE=../corfu/extern/rodos/cmake/port/discovery.cmake ..               