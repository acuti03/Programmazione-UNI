# Esercizio 2

cd ~/prova_dir;
rm *;
who > users.txt;
wc -l users.txt;
ps aux > process.txt;
grep $USER process.txt;
ps aux | grep root | wc -l;