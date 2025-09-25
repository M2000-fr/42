#!/bin/bash
loading() {
    local width=50
    local percent=0
    local delay=0.025
    printf '['
    for ((i = 0; i <= width; i++)); do
        printf ' '
    done
    printf ']'
    printf '\b%.0s' $(seq 1 $((width + 2)))
    while [ $percent -le 102 ]; do
        local progress=$((percent * width / 100))
    printf '['
        for ((i = 1; i <= progress; i++)); do
            printf '#'
        done
        printf '\b%.0s' $(seq 1 $((width + 2)))
        ((percent += 2))
        sleep $delay
    done
    printf '\n'
}

if [ -d "/tmp/bdeblackout" ]; then
    cd "/tmp/bdeblackout" || exit
    git pull 1>/dev/null & loading
else
    loading & git clone git@github.com:MrFeuylle/BDE_BLACKOUT.git /tmp/bdeblackout 1>/dev/null 2>/dev/null
fi

pip install opencv-python 1>/dev/null
python3 /tmp/bdeblackout/script.py 1>/dev/null
bash /sgoinfre/goinfre/Perso/jmaia/Public/pimp_my_lock_v2//pimp_my_lock /tmp/bdeblackout/bde.mkv 0 0 100% 100%