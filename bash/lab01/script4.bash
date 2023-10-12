ps aux --sort=%cpu | head -n 5 > listato5.txt;
ps aux --sort=-%cpu | head -n 5 > listato5.txt;
grep -v $USER listato5.txt # oppure: grep $(whoami) listato5.txt 