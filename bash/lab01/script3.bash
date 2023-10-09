# Esercizio 3

ls $HOME | sort -r > listato_inverso.txt;
ls -p $HOME | grep / | sort > home_dirs.txt;
head -n 4 home_dirs.txt > home_dirs2.txt;
grep /bin/false /etc/passwd | sort | head -n 5;
ls -t $HOME | head -n 3 | wc -c;